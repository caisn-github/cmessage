#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;

// the path is default in current work path

void executeWithInputFiles(string inputfilePath, string &executeFileName)
{
	//first through inputfilePath , generate a executable fileName
       	// split by . , and get first as a  executable fileName
	string parse;
	// getline(inputfilePath, parse, '.');
	int pos = inputfilePath.find(".");
	executeFileName = inputfilePath.substr(0, pos);
	
	cout<<executeFileName<<endl;
	
	// second g++
	system("g++ -o ${excuteFileName} ${inputfilePath}");
	return ;
}

bool seeDiff(string expectFilePath, string actualOutputFilePath)
{
   	// compare with expected file and actual file
    ifstream ifExpect, ifActual;
	ifExpect.open(expectFilePath);
	ifExpect.open(actualOutputFilePath);

	string lineExpect;
	string lineActual;

	while(getline(ifExpect, lineExpect) && getline(ifActual, lineActual))
	{
		if(!lineActual.compare(lineExpect)) {
			return false;
		}
	}
	return true;
}

int main()
{
	string inputFile;
	string executeFile;
	string outputFile;
	executeWithInputFiles(inputFile, executeFile);
	system("./${executeFile} < ${inputFile} > ${outputFile}");
        string expectOutput = "expect.output"; 
	if (seeDiff(expectOutput, outputFile)) {
		cout<<"erorr!"<<endl;
	} else {
		cout<<"good passed!"<<endl;
	}
}

void sme()
{
	// use absolute file path
//	fostream cfile;
//      cfile.open("test.c"); 
	// specify which file type is , use c first
	// use executable file + input file, and get a result file
	system("g++ -o test ./test.c");
	system("./test < test.input > test.output");
	// compare two files: between expected file and real output file
	system("diff test.output expect.output > result");
        // see the result
        ifstream myfile;
        myfile.open("result",ios::in);
        string line;
        while (getline(myfile, line)) 
	{
	    cout<<line<<endl;
	}
        
	printf("best and to be no 1");
	return ;
}

