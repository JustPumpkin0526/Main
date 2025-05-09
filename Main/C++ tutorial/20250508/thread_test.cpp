#include "thread_test.h"

queue<int> jobs;
condition_variable cv;
mutex mtx;
int counter = 0;
atomic_flag lk = ATOMIC_FLAG_INIT;
bool done = false;
bool ready = false;

void function_1() {
	cout << "Function 1 has been called" << endl;
}

void function_2() {
	cout << "Function 2 has been called" << endl;
}

void hello() {
	cout << "Hello, World!" << endl;
}

void complexCalculation(int a, int b) {
	cout << a + b << endl;

}

void print_block(int n, char c) {
	mtx.lock();
	for (int i = 0; i < n; ++i) {
		cout << c;
	}
	cout << "\n";
	mtx.unlock();
}

void print_id(int id) {
	unique_lock<mutex> lck(mtx);
	while (!ready) cv.wait(lck);
	cout << "thread " << id << endl;
}

void go() {
	unique_lock<mutex> lck(mtx);
	ready = true;
	cv.notify_all();
}

void printThreadID(int id) {
	mtx.lock();
	cout << "Thread ID: " << id << endl;
	mtx.unlock();
}

void increment(int num) {
	for (int i = 0; i < num; i++) {
		lock_guard<mutex> guard(mtx);  //동기화를 보장
		++counter;
		cout << this_thread::get_id() << ": " << counter << endl;
	}
}

void threadFunction() {
	cout << "Thread ID: " << this_thread::get_id() << " started.\n";
	this_thread::sleep_for(chrono::seconds(3));
	cout << "Thread ID: " << this_thread::get_id() << " ended.\n";
}

void lock_func() {
	while (lk.test_and_set(memory_order_acquire));
}

void unlock_func() {
	lk.clear(memory_order_release);
}

void worker_thread1() {
	this_thread::sleep_for(chrono::seconds(1));

	unique_lock<mutex> lk(mtx);
	counter = 1;
	done = true;
	lk.unlock();
	cv.notify_one();
}

void worker_thread2(int id) {
	while (true) {
		unique_lock<mutex> lock(mtx);
		cv.wait(lock, [] {return !jobs.empty() || done;});
		if (done && jobs.empty()) return;
		int job = jobs.front();
		jobs.pop();
		lock.unlock();
		cout << "Thread " << id << " processed job " << job << endl;
	}
}

void do_the_work(promise<int>& p) {
	p.set_value(42);
}

class ThreadPool {
private:
	queue<function<void()>> tasks;
	vector<thread> workers;
	mutex queue_mutex;
	condition_variable condition;
	bool stop;

public:
	ThreadPool(size_t threads) : stop(false) {
		for (size_t i = 0; i < threads; ++i)
			workers.emplace_back([this] {
			for (;;) {
				function<void()> task;
				{
					unique_lock<mutex> lock(this->queue_mutex);
					this->condition.wait(lock,
						[this] {return this->stop || !this->tasks.empty();});
					if (this->stop && this->tasks.empty())
						return;
					task = move(this->tasks.front());
					this->tasks.pop();
				}
				task();
			}
				});
	}

	~ThreadPool() {
		{
			unique_lock<mutex> lock(queue_mutex);
			stop = true;
		}
		condition.notify_all();
		for (thread& worker : workers)
			worker.join();
	}

	template<class F>
	void enqueue(F&& f) {
		if (!stop) {
			unique_lock<mutex> lock(queue_mutex);
			tasks.emplace(forward<F>(f));
		}
		condition.notify_one();
	}
};

void thread_test() {
	//스레드 기초 개념 확인
	/*thread thread_1(function_1);
	thread thread_2(function_2);

	thread_1.join();
	thread_2.join();*/

	//스레드의 생성부터 종료의 과정
	//thread t(hello); //스레드가 생성됨
	//t.join();		 //해당 스레드가 종료될 때까지 기다림

	//뮤텍스 테스트
	/*thread th1(print_block, 50, '*');
	thread th2(print_block, 50, '$');

	th1.join();
	th2.join();*/

	//스레드의 필요성
	/*thread t1(complexCalculation, 10, 20);
	thread t2(complexCalculation, 30, 40);

	t1.join();
	t2.join();*/

	//멀티 스레드
	/*thread tid1(printThreadID, 1);
	thread tid2(printThreadID, 2);
	thread tid3(printThreadID, 3);
	thread tid4(printThreadID, 4);

	tid1.join();
	tid2.join();
	tid3.join();
	tid4.join();*/

	//멀티 스레드 동기화
	/*thread tc1(increment, 5000);
	thread tc2(increment, 5000);

	tc1.join();
	tc2.join();

	cout << "Final couter: " << counter << endl;*/

	//스레드의 상태 변화
	//thread ts(threadFunction);	// 새로운 스레드 생성 (생성 상태)
	//ts.detach();					//스레드를 백그라운드에서 실행하게 함 (실행 상태)
									//스레드 ts는 독립적으로 실행되는 중, thread_test함수 즉 메인 스레드는 ts와 별개로 계속 진행
									//이때 스레드 ts는 실행 상태, 실행 대기 상태, 중지 상태를 오가게 됨
									//스레드가 작업이 끝나면 종료 상태가 됨
	//this_thread::sleep_for(chrono::seconds(5));

	//조건변수
	/*thread tt(worker_thread1);
	unique_lock<mutex> lk(mtx);
	cv.wait(lk, [] {return done;});

	cout << "Worker thread is done, value: " << counter << endl;
 	
	tt.join();*/
	//조건변수 2
	/*thread threads[10];
	for (int i = 0;i < 10;++i) {
		threads[i] = thread(print_id, i);
	}
	cout << "10 threads ready to race...\n";
	go();
	for (auto& th : threads) th.join();*/

	

	//스레드 폴
	/*vector<thread> workers;
	for (int i = 0; i < 4; ++i) {
		workers.push_back(thread(worker_thread2, i));
	}
	for (int i = 0; i < 100; ++i) {
		unique_lock<mutex> lock(mtx);
		jobs.push(i);
		cv.notify_one();
	}
	for (auto &t : workers)
		t.join();*/

	//시스템에서 지원하는 동시 스레드의 최대 수 출력
	/*unsigned int n = thread::hardware_concurrency();
	cout << n << " concurrent threads are supported.\n";*/

	//future & promise
	promise<int> p;
	future<int> f = p.get_future();

	thread t(do_the_work, ref(p));
	t.join();

	cout << "The answer is " << f.get() << endl;


}