#include <iostream>
#include <string>
#include <thread>
#include <mutex>

using namespace std;

string GlobalString;
const int ThreadNum = 10;
thread ThreadArray[ThreadNum];
mutex M;

void threadfunction(int id) {
	M.lock();
	GlobalString.append("Thread #" + to_string(id) + "\n");
	M.unlock();
}

void main() {

	for (int i = 0; i < ThreadNum; i++) {
		ThreadArray[i] = thread(threadfunction, i);
	}

	for (int i = 0; i < ThreadNum; i++) {
		ThreadArray[i].join();
	}
	cout << GlobalString;
	system("pause");
}