#include "thread_test.h"

void function_1() {
	cout << "Function 1 has been called" << endl;
}

void function_2() {
	cout << "Function 2 has been called" << endl;
}
mutex mtx;
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

void thread_test() {
	//스레드 기초 개념 확인
	thread thread_1(function_1);
	thread thread_2(function_2);

	thread_1.join();
	thread_2.join();

	//뮤텍스 테스트
	thread th1(print_block, 50, '*');
	thread th2(print_block, 50, '$');

	th1.join();
	th2.join();

	//스레드의 필요성
	thread t1(complexCalculation, 10, 20);
	thread t2(complexCalculation, 30, 40);

	t1.join();
	t2.join();
}