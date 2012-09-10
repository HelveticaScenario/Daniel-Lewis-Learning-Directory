/*
 * writeFile.cpp
 *
 *  Created on: Aug 13, 2012
 *      Author: contrarian
 */

#include <iostream>
#include <fstream>
using namespace std;

int main(){
	ofstream outFile;
	char outFileName[256];
	char outFileData[256];
	cout << "Set output file name: "; cin.getline(outFileName, 256);
	cout << "Text to write to file: "; cin.getline(outFileData, 256);

	outFile.open(outFileName);
	outFile << outFileData;
	outFile.close();
	return 0;

}


