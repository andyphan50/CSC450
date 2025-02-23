
#include <iostream>
#include <thread>				//provides support for multithreading
#include <mutex>				//provides support for mutexes
#include <condition_variable>  	//provides support for conditional variables used to block one or more threads until notified
#include <stdexcept>			//provides support for exception handling
#include <limits>				//provides support for int boundary checking
using namespace std;

mutex mtx;					//used to protect shared resources and ensure only one thread can acess the shared resource at a time
condition_variable cv;		//condition variable used for thread synchronization
bool ready = false;			//flag indicating whether the thread has finished counting
int sharedCounter =0;		//shared counter used by both threads


//function for performing boundary checking throws err if out of bounds
void boundaryCheck(int val) {
	int minInt = numeric_limits<int>::min();
	int maxInt = numeric_limits<int>::max();

	if (val < minInt || val > maxInt) {
		cerr << "Integer out of bound for int!" << endl;
	} else{
		return;
	}

}

// Functions to be executed by a thread
void countUp(){
	try{
		unique_lock<mutex> lock(mtx);    		//Lock the mutex
		for(int i=1; i <=20; ++i) {
			++sharedCounter;
			boundaryCheck(sharedCounter);		//checks buffer boundary for sharedCounter
			cout << "Counting up: " << sharedCounter << endl;
		}
		ready = true;
		cv.notify_one();				// notifies one waiting thread that the ready flag is set
	} catch (const exception &e) {
		cerr << "Exception in countUp:" << e.what() << endl;
	}
}

void countDown(){
	try{
		unique_lock<mutex> lock(mtx);    		//Acquires the mutex to protect the shared resource
		cv.wait(lock, []{return ready;});		// waits until the ready flag is set to true before executing
		for(int i=20; i >=1; --i) {
			--sharedCounter;
			boundaryCheck(sharedCounter);		//checks buffer boundary for sharedCounter
			cout << "Counting down: " << sharedCounter << endl;
		}
	} catch (const exception &e) {
		cerr << "Exception in countDown:" << e.what() << endl;
	}
}



int main() {
	try{
		// Create threads and runs them
		std::thread t1(countUp);
		std::thread t2(countDown);
		t1.join();
		t2.join();
	} catch (const exception &e) {
		cerr << "Exception in main: "<< e.what() << endl;
	}
    return 0;
}
