// Name: Daniel Calderon
// Date: December 17, 2015
// Elf Program2
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

const int R = 30;
const int C = 50;
 
void fillArray(ifstream& fin, string S[][C]);

int main()
{
	ifstream fin;
	ofstream fout;
	fin.open("northpole.txt");
	fout.open("status.txt");
	if(fin.fail())
	{
		cout << "Error on input file"<<endl;
		exit(1);
	}
	if(fout.fail())
	{
		cout << "Eroor on output file"<<endl;
		exit(1);
	}
	string S[R][C];
	fillArray(fin,S);
	fout << "Daniel Calderon" <<endl;
	for(int i=0;i <R;i++)
	{
		for(int j=0; j< C;j++)
		{
			if((i != 0 && i != 30-1 && j != 0 && j != 50-1))//checks for borders 30 is the row so subtract one and 50 is the column subtract one
			{
				if( (S[i][j] == "@") && (S[i-1][j] == "!" && S[i][j+1] =="!" && S[i+1][j]=="!"&& S[i][j-1]=="!"))//Checks for all four adjacent sides
				{
				fout << "elf" << "[" << i << "]" <<"[" << j << "]" << ":" << "Munch!" << endl; 
				}
				if((S[i][j] == "@") && ( (S[i-1][j] == "!" && S[i][j+1] =="!" && S[i+1][j]=="!") || (S[i-1][j] == "!" && S[i+1][j]=="!"&& S[i][j-1]=="!") || (S[i-1][j] == "!" && S[i][j+1] =="!" && S[i][j-1]=="!")||(S[i][j+1] =="!" && S[i+1][j]=="!"&& S[i][j-1]=="!") ))//checks for three adjacent sides
				{
					fout << "elf" << "[" << i << "]" <<"[" << j << "]" << ":" << "Run!" << endl;
				}

			}
		}
	}
	fin.close();
	fout.close();
	return 0;
}

// ********************************
void fillArray(ifstream& fin, string S[][C])
{
	string word;
	for(int i=0; i < R; i++)
	{
		for( int j=0;j < C; j++)
		{
			fin >>word;
			S[i][j] = word;
		}
	}
}//end fillArray




 
