#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char* argv[])
{
  if(argc < 3){
    cerr << "Please provide an input and output file." << endl;
    return 1;
  }
  ifstream input(argv[1]);
  ofstream output(argv[2]);

  int floors;
  int *floorsizes;
  int **possessionCounts;
  string ***trojans;
  string curr;
  string filler;
  input >> floors;
  getline(input,filler);
  trojans = new string**[floors];

  //you will need to keep track of how many people are on each floor.
  floorsizes = new int[floors];//got it
  possessionCounts=new int*[floors];
  for (int i = 0; i < floors; i++) {
	  floorsizes[i] = 0;
	  possessionCounts[i]=NULL;
	  trojans[i] = NULL;
  }
  while(getline(input, curr)) {
	  stringstream ss;
	  ss << curr;
	  ss >> curr;
	  if (curr == "MOVEIN") {
	  	//cout<<"1"<<endl;
		  int i,k;
		  ss >> i;
		  ss >> k;
		  if (ss.fail()) {
			  output << "Error - incorrect command" << endl;
		  }
		  else if(i>=floors)
		  {
		  	output<<"Error: floor "<<i<<" does not exist"<<endl;
		  }
		  else if(floorsizes[i]!=0){
		  	output<<"Error: floor "<<i<<" is not empty"<<endl;
		  }
		  
		  else
		  {
		  	floorsizes[i]=k;
		  	possessionCounts[i]=new int[k];
		  	trojans[i]=new string*[k];
		  	//new:
		  	for(int y=0;y<k;y++)
		  	{
		  		possessionCounts[i][y]=0;
		  		trojans[i][y]=NULL;
		  	}
		  }
	  }
	  else if (curr == "MOVEOUT") {
	  	//cout<<"2"<<endl;
	  	int i;
	  	ss>>i;
	  	if (ss.fail()) {
			  output << "Error - incorrect command" << endl;
		  }
		  else if(i>=floors)
		  {
		  	output<<"Error: floor "<<i<<" does not exist"<<endl;
		  }
		  else if(floorsizes[i]==0){
		  	output<<"Error: floor "<<i<<" is empty"<<endl;
		  }
		  
		  else
		  {
		  	floorsizes[i]=0;
		  	for(int x=0;x<floorsizes[i];x++)
		  	{

		  		delete[] trojans [i][x];
		  	}
		  	delete[] possessionCounts[i];
		  	delete[] trojans[i];
		  }

	  }
	  else if (curr == "OBTAIN") {
	  	//cout<<"3"<<endl;
		int i,j,k;
	  	ss>>i;
	  	ss>>j;
	  	ss>>k;

	  	if (ss.fail()) {
			  output << "Error - incorrect command" << endl;
		  }
		  else if(i>=floors)
		  {
		  	output<<"Error: floor "<<i<<" does not exist"<<endl;
		  }
		  else if(floorsizes[i]==0){
		  	output<<"Error: floor "<<i<<" is empty"<<endl;
		  }
		  
		  else if(j>=floorsizes[i])
		  	output<<"Error: There is no student "<<j<<" on floor "<<i<<endl;
		  else
		  {
		  	trojans[i][j]=new string[k];
		  	for(int x=0;x<k;x++)
		  	{
		  		ss>>trojans[i][j][x];
		  	}
		  	possessionCounts[i][j]=k;
		  }

	  }
	  else if (curr == "OUTPUT") {
	  	//cout<<"4"<<endl;
	  	int i,j;
	  	ss>>i;
	  	ss>>j;
	  	if (ss.fail()) {
			  output << "Error - incorrect command" << endl;
		  }
		  else if(i>=floors)
		  {
		  	output<<"Error: floor "<<i<<" does not exist"<<endl;
		  }
		  else if(floorsizes[i]==0){
		  	output<<"Error: floor "<<i<<" is empty"<<endl;
		  }
		  
		  else if(j>=floorsizes[i])
		  	output<<"Error: There is no student "<<j<<" on floor "<<i<<endl;
		  else if(possessionCounts[i][j]<=0)
		  	output<<"Error: Student "<<j<<" has no possessions"<<endl;
		  else
		  {
		  	for(int x=0;x<possessionCounts[i][j];x++)
		  	{
		  		output<<trojans[i][j][x];
		  		if(x<possessionCounts[i][j]-1)
		  			output<<", ";
		  	}
		  	output<<endl;

		  }
	  }
	  else {

	  	output<<"Invalid command"<<endl;
	  	

	  }
	  
	  	
  }
  for(int x=0;x<floors;x++)
	  	{
	  		
	  			for(int y=0;y<floorsizes[x];y++)
	  			{
	  				delete[]trojans[x][y];//HERE
	  			}
	  		
	  		delete[]possessionCounts[x];
	  		delete[]trojans[x];
	  	}
	  	delete[] possessionCounts;
	  	delete[] trojans;
	  	delete[] floorsizes;
	  	input.close();
	  	output.close();
  return 0;
}
