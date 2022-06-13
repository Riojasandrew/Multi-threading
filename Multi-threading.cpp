// Clearly use true multithreading.
// Create the main space baseand start launching 10 Rockets at the Rocket Pad remotely.
// There should be 3 seconds between each launch.
// Then transfer launch control from Main Base to the Rocket Pad Space Cadet after the first rocket launch.
// Your code must be over commented.

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <thread>
#include <mutex>
#include <chrono>
#include <stdio.h>

using namespace std;
using namespace std::this_thread;
mutex m;

void searchLaunch(int* ary, int start, int search_length) {
	int type_ii = 0;
	for (int type_i = start; type_i < start + search_length; type_i++) {
		if (ary[type_i] == 500) {
			printf("\n Main thread ID: %d", type_ii);
		}
		++type_ii;
	}
}

void searchID(int* ary, int start, int search_length) {
	int ii = 0;
	for (int i = start; i < start + search_length; i++) {
		if (ary[i] == 400) {
			printf("\n found on %d insertions", ii);

		}
		++ii;
	}
}

void launchRocket(int type_i) {
	int z = 100;
	srand(time(0));
	int* ary = new int[z];

	for (int type_i = 0; type_i < z; type_i++) {
		ary[type_i] = rand() % 999;
	}
	thread t1(searchLaunch, ary, 0, 19);
	thread t2(searchLaunch, ary, 2, 29);
	thread t3(searchLaunch, ary, 4, 39);
	thread t4(searchLaunch, ary, 6, 49);
	thread t5(searchLaunch, ary, 8, 59);

	t1.join();
	if (t2.joinable()) {
		t2.join();
	}
	t3.join();
	t4.join();
	if (t5.joinable()) {
		t5.join();
	}
	if (type_i == 1) { // Launch Main
		m.lock();
		printf("launching rocket from main on thread id: %d", this_thread::get_id());
		m.unlock();
		this_thread::sleep_for(chrono::seconds(3)); // time delayed
	}
	else { // launch from launch pad
		m.lock();
		printf("launching rocket from launch on thread id: %d", this_thread::get_id());
		m.unlock();
	}
	
	
}

void loopLaunch() {
	int n = 100;
	srand(time(0));
	int* ary = new int[n];
	
	for (int i = 0; i < n; i++) {
		ary[i] = rand() % 999;
	}
	thread t1(searchID, ary, 0, 19);
	thread t2(searchID, ary, 20, 39);
	thread t3(searchID, ary, 40, 59);
	thread t4(searchID, ary, 60, 79);
	thread t5(searchID, ary, 80, 99);

	t1.join();
	if (t2.joinable()) {
		t2.join();
	}
	t3.join();
	t4.join();
	if (t5.joinable()) {
		t5.join();
	}

}


int main()
{


	cout << "\n\n\t\t\t\t\tThe Space Race\n\n" << endl;
	
		for (int i = 0; i < 1000; i++) {
			loopLaunch();
			printf("\n\nPress Enter to start launching rockets locally from Space base using main thread!");
			cin.get();
	}
	


}
//cin.get();