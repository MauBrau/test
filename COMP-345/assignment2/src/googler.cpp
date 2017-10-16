//============================================================================
// Name        : assignment2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Document.h"

using namespace std;

int main() {
	cout << "Testing!" << endl; // prints !!!Hello World!!!

	Document test("test.txt", "stopwordstest.txt");

	cout << "file name: " + test.getFileName() << endl;
	cout << "contents: " << endl;

	string testing;
	for(vector<string>::const_iterator i = test.getContents().begin(); i !=  test.getContents().end(); ++i){
		testing = *i;
		cout << testing << endl;
	}
	return 0;
}
