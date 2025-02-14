#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

//this function is responsible for reversing the content of the original file and
//outputting it to another txt file. it takes references of the inputFileName
//and the outputFileName
void reverseFileContent(const string& inputFileName, const string& outputFileName) {
	//open input and output file
	std::ifstream inputFile(inputFileName);
	std::ofstream outputFile(outputFileName);

	//check to see if input and output file were opened successfully
	if(inputFile && outputFile) {
		//create buffer stringstream object
		stringstream buffer;
		//feed inputfile data into buffer
		buffer << inputFile.rdbuf();
		//store data in buffer into content
		string content = buffer.str();
		//using reverse() from the algorithm library to reverse the characters
		reverse(content.begin(), content.end());
		//feed the data in content into the output file
		outputFile << content;
		//close inputFile and output file
		outputFile.close();
		inputFile.close();
	}  else {
		cerr << "Error: Unable to open files" << endl;
	}


}

int main() {
	string inputFileName = "CSC450_CT5_mod5.txt";
	string outputFileName = "CSC450-mod5-reverse.txt";
	//declare an ofstream object with the name fileOut
	ofstream fileOut;

	//open() file using fileName, and ios_base::app (append mode)
	fileOut.open(inputFileName, ios_base::app);

	//check to see if file was opened successfully
	if(fileOut) {
		string userInput;
		cout << "Enter text to append to file: " << endl;
		getline(cin, userInput);

		//append user input into file
		fileOut << userInput << endl;
		//close file
		fileOut.close();

		reverseFileContent(inputFileName, outputFileName);

		cout<< "Content successfully appended" << endl;
	} else {
		cerr<< "Error: could not open file for writing" << endl;
	}

	return 0;
}
