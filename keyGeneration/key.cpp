#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include<bitset>
#include<vector>
#include<array>
#include<algorithm>
using namespace std;
struct rotation{
	int roundNum;
	int roundBit;
};
vector<rotation> LSI;
#define ROWS 16
#define COLUMNS 56
#define PC_2_COLS 48
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
	//rotation schedule
	LSI.push_back(rotation());
	int roundNum[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
	int  roundBit[] = { 1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1 };
	for (int i = 0; i < 16; i++)
	{
		LSI.push_back({ roundNum[i], roundBit[i] });
	}

	vector< vector<int> > encryptionKey,tempKey;    //2D  encryption key
	vector<char> key;
	vector<int> asciiKey, PC_1_key,x;
	int kTemp[64];
	//PC-1 standard table
	int pc_1_Table[] = {57,49,41,33,25,17,9,1,58,50,42,34,26,18,10,2,59,51,43,35,27,19,11,3,60,52,44,
		                36,63,55,47,39,31,23,15,7,62,54,46,38,30,22,14,6,61,53,45,37,29,21,13,5,28,20,12,4};
	//PC-2 standard table
	int pc_2_Table[] = {14,17,11,24,1,5,3,28,15,6,21,10,23,19,12,4,26,8,16,7,27,20,13,2,41,52,32,37,47,55,30,
		                40,51,45,33,48,44,49,39,56,34,53,46,42,50,36,29,32};
	
	int ascii,k=7,z=0,q=0;
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
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << kTemp[j + q] << " ";
		}
		q += 8;
		cout << endl;
	}
	cout << endl;
	//temporary key to hold
	tempKey.resize(ROWS);    //allocate space for rows
	for (int i = 0; i < ROWS; ++i)
	{
		tempKey[i].resize(COLUMNS);   //allocate space for columns
	}
	encryptionKey.resize(ROWS);
	for (int i = 0; i < ROWS; ++i)
	{
		encryptionKey[i].resize(PC_2_COLS);   //allocate space for columns
	}
	//PC-1 generation into a vector
	for (int i = 0; i < 56; i++)
	{
		PC_1_key.push_back( kTemp[pc_1_Table[i]-1]);
	}
	//split the PC-1
	vector<int> L(PC_1_key.begin(), PC_1_key.begin() + PC_1_key.size() / 2);
	vector<int> R(PC_1_key.begin() + PC_1_key.size() / 2, PC_1_key.end());
	x.reserve(L.size() + R.size());
	for (int i = 0; i < 16; i++)
	{
		rotate(L.begin(), L.begin() + roundBit[i], L.end());
		rotate(R.begin(), R.begin() + roundBit[i], R.end());
		x.insert(x.end(), L.begin(), L.end());
		x.insert(x.end(), R.begin(), R.end());
		for (int j = 0; j < 56; j++)
		{
			tempKey[i][j] = x[j];
		}
		x.clear();
	}
	for (int i = 0; i < ROWS; i++)
	{
	for (int j = 0; j < PC_2_COLS; j++)
	{
	encryptionKey[i][j] = tempKey[i][pc_2_Table[j]-1];
	}
	}
	
	system("pause");
	return 0;
}