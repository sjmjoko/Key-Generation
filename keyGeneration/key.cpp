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
//S-BOX ARRAYS
int S1[][16] = { { 14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7 },
{ 0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8 },
{ 4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0 },
{ 15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13 } };int S2[][16] = { { 15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10 },
{ 3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5 },
{ 0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15 },
{ 13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9 } };int S3[][16] = { { 10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8 },
{ 13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1 },
{ 13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7 },
{ 1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12 } };int S4[][16] = { { 7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15 },
{ 13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9 },
{ 10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4 },
{ 3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14 } };int S5[][16] = { { 2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9 },
{ 14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6 },
{ 4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14 },
{ 11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3 } };int S6[][16] = { { 2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9 },
{ 14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6 },
{ 4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14 },
{ 11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3 } };

int S7[][16] = { { 4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1 },
{ 13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6 },
{ 1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2 },
{ 6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12 } };int S8[][16] = { { 13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7 },
{ 1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2 },
{ 7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8 },
{ 2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11 } };

using namespace std;
//KEY GENERATION FUNCTION
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
void Resize(vector<vector<Y> > &v, int rows, int columns)
{
	v.resize(rows);
	for (int i = 0; i < rows; ++i)
	{
		v[i].resize(columns);   //allocate space for columns
	}
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

//MESSAGE GENERATION FUNCTIONS
vector<vector<int> > ip1_permutation(vector<vector<int>> &a, int c[]) //vector confused,vector non confused, ip table
{
	for (int i = 0; i< a.size(); i++)
		for (int j = 0; j < a[0].size(); j++)
		{
			a[i][j] = a[i][c[j] - 1];
		}
	return a;
}
vector<char> deleteSpaces(vector<char> & v)
{
	for (int k = 0; k < v.size(); k++)
	{
		if (v[k] == ' ')
		{
			v.erase(v.begin() + k);
		}
	}
	return v;
}
vector<char> addFillers(vector<char> & v)
{
	while (v.size() % 8 != 0)
	{
		v.insert(v.end(), 'x');
	}
	return v;
}
vector<vector < int> > toAscii(vector<vector <char> > &c, vector<vector < int> > &v, int rownum)
{
	int ascii;
	for (int i = 0; i <rownum; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			ascii = int(c[i][j]);
			v[i][j] = ascii;
		}
	}
	return v;
}
vector<int> expansionTable(vector<int> &right, vector<int> &temp)
{
	for (int i = 0; i < 48; i++)
	{
		right.push_back(temp[expansion[i] - 1]);
	}
	return right;
}
vector<int> XOR(vector<vector<int> > &k, vector<int> &t, vector<int> &c, int rowkey) //pass the row of the key being used
{
	int a, b;
	for (int i = 0; i < k[rowkey].size(); i++)
	{
		a = k[rowkey][i];
		b = t[i];
		c.push_back(a^b);
	}
	return c;
}
vector<vector<int> > toBinary(vector<vector<int> > &ascii, vector<vector<int> > &bin, vector<int> &mes, int rows) //mes is a emp vector
{
	int b = 0, c = 7, e = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < ascii[0].size(); j++)
		{
			bitset<8> p(ascii[i][j]);
			for (int a = 0; a < ascii[0].size(); a++)
			{
				mes.push_back(p[c]);
				c--;
			}
			for (int d = 0; d < ascii[0].size(); d++)
			{
				bin[e][d + b] = mes[d];
			}
			b += 8;
			if (b == 64)
			{
				b -= 8;
			}
			c = 7;
			mes.clear();
		}
		b = 0;
		e++;
	}
	return bin;
}

//ENCRYPTION FUNCTIONS
vector<vector<int> > to2D(vector<vector<int> > &v, vector<int> a)
{
	int t=0;
	Resize(v, 8, 6);
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			v[i][j] = a[j+t];
		}
		t += 6;
	}
	return v;
}
int row(int a, int b)
{
	int c = 2 * a + b;
	return c;
}
int column(int a, int b, int c, int d)
{
	int e = 8 * a + 4 * b + c * 2 + d;
	return e;
}
void sBox(vector<vector<int> > &v, vector<int> &x)
{
	int d;
	d = S1[row(v[0][0], v[0][5])][column(v[0][1], v[0][2], v[0][3], v[0][4])];
	bitset<4> a(d);
	for (int j = 3; j >= 0; j--)
	{
		x.push_back(a[j]);
	}

	d = S2[row(v[1][0], v[1][5])][column(v[1][1], v[1][2], v[1][3], v[1][4])];
	bitset<4> b(d);
	for (int j = 3; j >= 0; j--)
	{
		x.push_back(b[j]);
	}

	d = S3[row(v[2][0], v[2][5])][column(v[2][1], v[2][2], v[2][3], v[2][4])];
	bitset<4> c(d);
	for (int j = 3; j >= 0; j--)
	{
		x.push_back(c[j]);
	}

	d = S4[row(v[3][0], v[3][5])][column(v[3][1], v[3][2], v[3][3], v[3][4])];
	bitset<4> e(d);
	for (int j = 3; j >= 0; j--)
	{
		x.push_back(e[j]);
	}

	d = S5[row(v[4][0], v[4][5])][column(v[4][1], v[4][2], v[4][3], v[4][4])];
	bitset<4> f(d);
	for (int j = 3; j >= 0; j--)
	{
		x.push_back(f[j]);
	}

	d = S6[row(v[5][0], v[5][5])][column(v[5][1], v[5][2], v[5][3], v[5][4])];
	bitset<4> g(d);
	for (int j = 3; j >= 0; j--)
	{
		x.push_back(g[j]);
	}
	d = S7[row(v[6][0], v[6][5])][column(v[6][1], v[6][2], v[6][3], v[6][4])];
	bitset<4> h(d);
	for (int j = 3; j >= 0; j--)
	{
		x.push_back(h[j]);
	}
	d = S1[row(v[7][0], v[7][5])][column(v[7][1], v[7][2], v[7][3], v[7][4])];
	bitset<4> p(d);
	for (int j = 3; j >= 0; j--)
	{
		x.push_back(p[j]);
	}
}
vector<int> pBox(vector<int> a, vector<int> &b)
{
	for (int i = 0; i < a.size(); i++)
	{
		b.push_back(a[IP_2[i] - 1]);
	}
	return b;
}
//void encryption(vector<vector<int> > &text, vector<vector<int> > &key, vector<int> cipher, int textRows)  //study this function
//{
//	int cycle = 0; //determines the number of rows to be encrypted
//	while (cycle < textRows)
//	{
//		int keyIterator = 0;
//		vector<int> Left, Right, temp, tempL; //temp is usd to store things temporarily
//		//separate the text into 32 bits, left and right
//		for (int i = 0; i < 32; i++)  //select the row of the text
//		{
//			Left.push_back(text[cycle][i]);
//			Right.push_back(text[cycle][i + 32]);  //push the right text as a temporary text 32 bit
//		}
//		tempL.insert(tempL.end(), Right.begin(), Right.end()); //R(i)=L(i+1)
//		//this part should be repeated 16 times
//		expansionTable(temp, Right); //temp is the temporary expanded right text
//		Right.clear();//clear the right variable to store the new Right text
//		XOR(key, temp, Right, cycle);
//	}
//}
int main()
{
	int k = 7, z = 0, l = 0;
	char t;
	string  originalKey;
	cout << "Enter the key: ";
	getline(cin, originalKey);
	cout << "Enter the message: ";
	getline(cin, message);
	//transfer key to vector
	for (int i = 0; i < originalKey.length(); i++)
	{
		key.push_back(originalKey[i]);
	}
	//transfer string message to string message
	for (int i = 0; i < message.length(); i++)
	{
		msg.push_back(message[i]);
	}
	//delete spaces in the message
	deleteSpaces(msg);
	//add filler character if message is not in blocks of 8
	addFillers(msg);
	int rows = msg.size() / 8;
	cout << endl;
	//convert key to ASCII CODE
	//GENERATION OF THE ENCRYPTION
	toASCII(asciiKey, key);
	//populate the bits of the key to an integer array 
	toBINARY(asciiKey, kTemp);
	//resize any 2D-arrays to be used
	Resize(tempKey, ROWS, COLUMNS);
	Resize(encryptionKey, ROWS, PC_2_COLS);
	Resize(textChar, rows, 8);
	Resize(textAscii, rows, 8);
	Resize(textBin, rows, 64);
	//perform PC-1 permutation
	pc1(kTemp, PC_1_key);
	//key rotation schedule
	rotationSchedule(tempKey, PC_1_key, x);
	////conversion to PC-2 table
	pc2(tempKey, encryptionKey, pc_2_Table);
	/*print2D(encryptionKey);*/
	//GENERATION OF THE PLAIN TEXT
	/*cout << rows << endl;*/
	//transfer the message to a 2D character vector
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			t = msg[j + l];
			textChar[i][j] = t;
		}
		l += 8;
	}
	//convert the chars to ascii code for each block
	//convert each char into 8 bits
	toAscii(textChar, textAscii, rows);
	//convert the ascii message into binary
	toBinary(textAscii, textBin, msgTemp, rows);
	//IP-1 permutation
	ip1_permutation(textBin, IP_1);
	/*print2D(textBin);*/
	cout << endl;
	//generate the text to be encrypted
	//THE ENCRYPTING STARTS HERE
	//THE ENCRYPTING STARTS HERE
	//THE ENCRYPTING STARTS HERE
	for (int i = 32; i < textBin[0].size(); i++)
	{
		tempTextRight.push_back(textBin[0][i]);
	}
	expansionTable(rightText, tempTextRight);
	tempTextRight.clear();
	XOR(encryptionKey, rightText, cipherText, 0);
	to2D(temp, cipherText);
	cipherText.clear();
	sBox(temp, tempTextRight);
	pBox(tempTextRight, cipherText);
	system("pause");
	return 0;
}