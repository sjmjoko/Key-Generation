#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include<bitset>
#include<vector>
#include<array>
using namespace std;
#define SIZE_1 8  //rows and columns
#define SIZE_2 7 //rows of PC-1 table
template < class T >
void print(vector<T> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}
template< class X >
void print2D(vector< vector<X>> x)
{
	for (int i = 0; i < x.size(); i++)
	{
		for (int j = 0; j < x[0].size(); j++)
		{
			cout << x[i][j] << " ";
		}
		cout << endl;
	}

}
int main()
{
	vector< vector<int> > keyTable;    //2D  encryption key
	vector<char> key;
	vector<int> asciiKey;
	vector<bitset<2> >  bitKey;
	int kTemp[64];
	int pc_1_Table[] = {57,49,41,33,25,17,9,1,58,50,42,34,26,18,10,2,59,51,43,35,27,19,11,3,60,52,44,
		                36,63,55,47,39,31,23,15,7,62,54,46,38,30,22,14,6,61,53,45,37,29,21,13,5,28,20,12,4};

	int ascii,k=7,z=0;
	string  originalKey; 
		cout << "Enter the key: ";
	getline(cin, originalKey);
	for (int i = 0; i < originalKey.length(); i++)
	{
		key.push_back(originalKey[i]);
	}
	cout << endl;
	//convert key to ASCII CODE
	for (int i = 0; i <key.size(); i++)
	{
		ascii = int(key[i]);
		asciiKey.push_back(ascii);
	}
	
	//populate the bits of the key to an integer array 
	for (int i = 0; i < SIZE_1; i++)
	{
		bitset<8> p(asciiKey[i]);
		
		for (int j = 0; j < SIZE_1; j++)
		{
			kTemp[z + j] = p[k];
			k--;
		}
		z += 8;
		k = 7;
	}
	k = 0;
	
	//2x2 64-bit key 
	keyTable.resize(SIZE_1);    //allocate space for rows
	for (int i = 0; i < SIZE_1; ++i)
	{
		keyTable[i].resize(SIZE_1);   //allocate space for columns
	}

	//transfer the integer key to a 2x2 matrix 
	for (int i = 0; i < SIZE_1; i++)
	{
		for (int j = 0; j< SIZE_1; j++)
		{
			keyTable[i][j] = kTemp[j + k];
		}
		k += 8;
	}
    print2D(keyTable);
	
	system("pause");
	return 0;
}