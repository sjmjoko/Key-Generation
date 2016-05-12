#ifndef KEYHEADER_H
#define KEYHEADER_H
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include<bitset>
#include<vector>
#include<array>
#include<algorithm>
#define ROWS 16
#define COLUMNS 56
#define PC_2_COLS 48
#define SIZE_1 8  //rows and columns
#define SIZE_2 7 //rows of PC-1 table

using namespace std;
vector< vector<int> > encryptionKey, tempKey, textBin, textAscii, textMsg;    //2D  encryption key,binary text message
vector<char> key, msg;         //char key and message
vector<int> asciiKey, PC_1_key, x, asciiMsg, msgTemp, ipMsg;
int kTemp[64];
vector<vector<char> > textChar;

int k = 7, z = 0, l = 0;  //iteration variables
char t;
int ascii, q = 0;
string  originalKey,message;  //key and message strings
//printing functions 
template < class T >
void print(vector<T> v);
template< class X >
void print2D(vector< vector<X>> x);
//key generation functions
vector<int> toASCII(vector<int> &v, vector<char> &key);
int* toBINARY(vector<int> &ascii, int temp[]);
template<class Y>
vector<vector<int> > Resize(vector<vector<Y> > &v, int rows, int columns);
vector<int> pc1(int kt[], vector<int> &pk);
vector<vector<int> > rotationSchedule(vector<vector<int> > &tk, vector<int> &pc, vector<int> x);
vector<vector<int> > pc2(vector<vector<int> > &v, vector<vector<int> > &k, int a[]);
//message generation functions
void ip1_permutation(vector<vector<int>> &a, int c[]);
vector<char> deleteSpaces(vector<char> & v);
vector<char> addFillers(vector<char> & v);
void toAscii(vector<vector <char> > &c, vector<vector < int> > &v, int rownum);
void expansionTable(vector<int> &right, vector<int> temp);
int XOR(vector<vector<int> > &k, vector<int> &t, vector<int> &c, int rowkey);
void toBinary(vector<vector<int> > &ascii, vector<vector<int> > &bin, vector<int> &mes, int rows);

#endif