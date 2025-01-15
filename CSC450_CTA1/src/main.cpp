#include <iostream>
using namespace std;


int main() {
	string first_name = "Andy";
	string last_name = "Phan";
	string address = "3401 Lotus Dr.";
	string city = "Arlington";
	int zip_code = 76014;

	cout << "First Name:" + first_name +"\n";
	cout << "Last Name:" + last_name +"\n";
	cout << "Address:" + address+  "\n";
	cout << "City:" + city + "\n";
	cout << "Zip Code:" + to_string(zip_code);
	return 0;
}


