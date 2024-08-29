#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
	// use absolute file path
//	fostream cfile;
//      cfile.open("test.c"); 
	// specify which file type is , use c first
	// use executable file + input file, and get a result file
	system("g++ -o test test.c");
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
	return 0;
   
}
