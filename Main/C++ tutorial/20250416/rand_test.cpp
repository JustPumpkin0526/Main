#include "rand_test.h"

void rand_test() {
	random_device rd;

	mt19937 gen(rd());

	uniform_int_distribution<int> dis(0, 99);

	for (int i = 0;i < 5; i++) {
		cout << "³­¼ö : " << dis(gen) << endl;
	}
}