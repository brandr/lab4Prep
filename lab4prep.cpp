#include "lab4prep.h"
#include <iostream>

using namespace std;

int main(){
	ifstream inputFile1("lab4TestData.txt");
	if (!inputFile1) {
    	cout << "File could not be opened." << endl;
        return 1;
   	}
	Lab4IoPrep ioObject;
	ioObject.readInputFile(inputFile1);
	return 1;
}