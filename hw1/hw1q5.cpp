#include <iostream>
#include <sstream>
#include <cstring> 
#include <string>
#include <fstream>
using namespace std;

int main (int argc, char * argv[])
{
	ifstream myFile;
	
	if(argc<2)
	{
		cout<<"No file name entered";
		return 1;
	}

	myFile.open(argv[1]);
	int numWords;
	myFile>>numWords;
	//cout<<numWords;
	string* words=new string[numWords];
	int n=0;
	string buffer;
	while(n<numWords)
	{
		myFile>>buffer;
		words[n]=buffer;
		n++;
	}
	//cout<<"n: "<<n;
	for(int x=numWords-1;x>=0;x--)
	{
		cout<<endl;
		cout<<words[x];
	}
	myFile.close();
	delete[] words;







}