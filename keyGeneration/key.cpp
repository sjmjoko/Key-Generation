#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include<bitset>
#include<vector>
#include<array>
#include<algorithm>
#include"keyHeader.h"
//PC-1 Table
int pc_1_Table[] = { 57, 49, 41, 33, 25, 17, 9, 1, 58, 50, 42, 34, 26, 18, 10, 2, 59, 51, 43, 35, 27, 19, 11, 3, 60, 52, 44,
36, 63, 55, 47, 39, 31, 23, 15, 7, 62, 54, 46, 38, 30, 22, 14, 6, 61, 53, 45, 37, 29, 21, 13, 5, 28, 20, 12, 4 };
//PC-2 Table
int pc_2_Table[] = { 14, 17, 11, 24, 1, 5, 3, 28, 15, 6, 21, 10, 23, 19, 12, 4, 26, 8, 16, 7, 27, 20, 13, 2, 41, 52, 32, 37, 47, 55, 30,
40, 51, 45, 33, 48, 44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32 };
//IP-1 Table
int IP_1[] = { 58, 50, 42, 34, 26, 18, 10, 2, 60, 52, 44, 36, 28, 20, 12, 4, 62, 54, 46, 38, 30, 22, 14, 6, 64, 56, 48, 40, 32, 24, 16, 8,
57, 49, 41, 33, 25, 17, 9, 1, 9, 51, 43, 35, 27, 19, 11, 3, 61, 53, 45, 37, 29, 21, 13, 5, 63, 55, 47, 39, 31, 23, 15, 7 };
//IP-2 Table
int IP_2[] = { 40, 8, 48, 16, 56, 24, 64, 32, 39, 7, 47, 15, 55, 23, 63, 31, 38, 6, 46, 14, 54, 22, 62, 30, 37, 5, 45, 13, 53, 21, 61, 29, 36,
4, 44, 12, 52, 20, 60, 28, 35, 3, 43, 11, 51, 19, 59, 27, 34, 2, 42, 10, 50, 18, 58, 26, 33, 1, 41, 9, 49, 17, 57, 25 };
//Expansion Table
int expansion[] = { 32, 1, 2, 3, 4, 5, 4, 5, 6, 7, 8, 9, 8, 9, 10, 11, 12, 13, 12, 13, 14, 15, 16, 17,
16, 17, 18, 19, 20, 21, 20, 21, 22, 23, 24, 25, 24, 25, 26, 27, 28, 29, 28, 29, 30, 31, 32, 1 };
using namespace std;
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
vector<int> toASCII(vector<int> &v, vector<char> &key)
{
	int ascii;
	for (int i = 0; i <key.size(); i++)
	{
		ascii = int(key[i]);
		v.push_back(ascii);
	}
	return v;
}
int* toBINARY(vector<int> &ascii, int temp[])
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
	return temp;
}
template<class Y>
vector<vector<int> > Resize(vector<vector<Y> > &v, int rows, int columns)
{
	v.resize(rows);
	for (int i = 0; i < rows; ++i)
	{
		v[i].resize(columns);   //allocate space for columns
	}
	return v;
}
vector<int> pc1(int kt[],vector<int> &pk)
{
	for (int i = 0; i < 56; i++)
	{
		pk.push_back(kt[pc_1_Table[i] - 1]);
	}
	return pk;
}
vector<vector<int> > rotationSchedule(vector<vector<int> > &tk, vector<int> &pc, vector<int> x)
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
	return tk;
}
vector<vector<int> > pc2(vector<vector<int> > &v, vector<vector<int> > &k, int a[])
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < PC_2_COLS; j++)
		{
			k[i][j] = v[i][a[j] - 1];
		}
	}
	return k;
}
int main()
{
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
	pc1(kTemp, PC_1_key);
	//key rotation schedule
	rotationSchedule(tempKey, PC_1_key, x);
	////conversion to PC-2 table
	pc2(tempKey, encryptionKey, pc_2_Table);
	print2D(encryptionKey);
	system("pause");
	return 0;
}