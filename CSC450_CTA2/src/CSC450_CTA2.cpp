//============================================================================
// Name        : CSC430_CTA2.cpp
// Author      : Andy
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

int main() {

	//initialize variables string1, string2, and results
	std::string str1, str2, result;

	//loop that executes the program 3x
	for (int i = 0; i < 3; ++i) {
		//print out user prompt and store input in variable
		cout << "Enter first string: ";
		getline(cin, str1);

		cout << "Enter second string: ";
		getline(cin, str2);

		//concatenate two strings together and print results
		result = str1 + str2;
		cout << "Concatenated string: " << result << endl << endl;
	}
}
