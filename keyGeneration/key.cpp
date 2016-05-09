#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include<bitset>
#include<vector>
#include<array>
#include<algorithm>
using namespace std;
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
vector<int> toASCII(vector<int> &v,vector<char> &key)
{
	int ascii;
	for (int i = 0; i <key.size(); i++)
	{
		ascii = int(key[i]);
		v.push_back(ascii);
	}
	return v;
}
void toBINARY(vector<int> &ascii,int temp[])
{
	int k = 7, z = 0;
	for (int i = 0; i < SIZE_1; i++)
	{
		bitset<8> p(ascii[i]);
		
		for (int j = 0; j < SIZE_1; j++)
		{
			temp[z + j] = p[k];
			k--;
		}
		z += 8;
		k = 7;
	}
}
template<class Y>
void Resize(vector<vector<Y> > &v, int rows, int columns)
{
	v.resize(rows);
	for (int i = 0; i < rows; ++i)
	{
		v[i].resize(columns);   //allocate space for columns
	}
}
void pc1(int kt[], vector<int> &pk,int a[])
{
	for (int i = 0; i < 56; i++)
	{
		pk.push_back( kt[a[i]-1]);
	}
}
void rotationSchedule(vector<vector<int> > &tk, vector<int> &pc, vector<int> x)
{
	int  roundBit[] = { 1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1 };
	vector<int> L(pc.begin(), pc.begin() + pc.size() / 2);
	vector<int> R(pc.begin() + pc.size() / 2, pc.end());
	x.reserve(L.size() + R.size());
	for (int i = 0; i < 16; i++)
	{
		rotate(L.begin(), L.begin() + roundBit[i], L.end());
		rotate(R.begin(), R.begin() + roundBit[i], R.end());
		x.insert(x.end(), L.begin(), L.end());
		x.insert(x.end(), R.begin(), R.end());
		for (int j = 0; j < 56; j++)
		{
			tk[i][j] = x[j];
		}
		x.clear();  
	}
}
void pc2(vector<vector<int> > &v, vector<vector<int> > &k, int a[])
{
	for (int i = 0; i < ROWS; i++)
	{
	    for (int j = 0; j < PC_2_COLS; j++)
		{
	        k[i][j] = v[i][a[j]-1];
	    }
	}
}
int main()
{	
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
	int ascii,q=0;
	string  originalKey; 
	cout << "Enter the key: ";
	getline(cin, originalKey);
	//transfer key to vector
	for (int i = 0; i < originalKey.length(); i++)
	{
		key.push_back(originalKey[i]);
	}
	cout << endl;
	//convert key to ASCII CODE
	toASCII(asciiKey, key);
	//populate the bits of the key to an integer array 
	toBINARY(asciiKey, kTemp);
	//resize any 2D-arrays to be used
	Resize(tempKey, ROWS, COLUMNS);
	Resize(encryptionKey, ROWS, PC_2_COLS);
	//perform PC-1 permutation
	pc1(kTemp, PC_1_key, pc_1_Table);
	//key rotation schedule
	rotationSchedule(tempKey, PC_1_key, x);
	////conversion to PC-2 table
	pc2(tempKey, encryptionKey, pc_2_Table);
	print2D(encryptionKey);
	system("pause");
	return 0;
}