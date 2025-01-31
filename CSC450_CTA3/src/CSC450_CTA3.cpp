
#include <iostream>
using namespace std;

//error handling for invalid user inputs
int safeInput(){
	int value;
	string input;
	cin >> input;
	try {
		value = stoi(input);
	} catch(const exception& e) {
		cerr << "Invalid input: Not an integer.Please enter valid integer:";
		value = safeInput();
	}
	return value;
}

int main() {
	//declare variables
	int input1, input2, input3;

	//Prompt user to enter 3 integers and store into the variables
	cout<< "Please enter integer 1:";
	input1 = safeInput();
	cout << "Please enter a integer 2:";
	input2 = safeInput();
	cout << "Please enter a integer 3:";
	input3 =  safeInput();

	//Declaration of points, allocation of memory for pointers using new keyword
	int *ptr1 = new int(input1);
	int *ptr2 = new int(input2);
	int *ptr3 = new int(input3);

	//Print onto console the 3 integers by dereferencing pointers
	cout<< "Values printed using variables:"<< endl;
	cout<< "Value 1: "<< input1 << endl;
	cout<< "Value 2: "<< input2 << endl;
	cout<< "Value 3: "<< input3 << endl;

	//Print onto console the 3 integers by dereferencing pointers
	cout<< "Values printed using pointers:"<< endl;
	cout<< "Value 1: "<< *ptr1 << endl;
	cout<< "Value 2: "<< *ptr2 << endl;
	cout<< "Value 3: "<< *ptr3 << endl;

	//Deallocation of memory for pointers using delete keyword
	delete ptr1;
	delete ptr2;
	delete ptr3;

	return 0;

}
