#include "lab4prep.h"
#include <iostream>

using namespace std;

int main(){
	//cout << STRING_ARRAY[0] << endl;
	ifstream inputFile1("lab4TestData.txt");
	if (!inputFile1) {
    	cout << "File could not be opened." << endl;
        return 1;
   	}
	Lab4IoPrep ioObject;
	ioObject.readInputFile(inputFile1);
	//file not found case
	//else, read input file
	
		
	return 1;
}