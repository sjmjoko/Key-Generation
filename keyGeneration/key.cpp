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
int pc_2_Table[] = { 14, 17, 11, 24, 1, 5, 3, 28, 15, 6, 21, 10, 23, 19, 12, 4, 26, 8, 16, 7, 27, 20, 13, 2, 41, 52, 31, 37, 47, 55, 30,
40, 51, 45, 33, 48, 44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32 };
//IP-1 Table
int IP_1[] = { 58, 50, 42, 34, 26, 18, 10, 2, 60, 52, 44, 36, 28, 20, 12, 4, 62, 54, 46, 38, 30, 22, 14, 6, 64, 56, 48, 40, 32, 24, 16, 8,
57, 49, 41, 33, 25, 17, 9, 1, 59, 51, 43, 35, 27, 19, 11, 3, 61, 53, 45, 37, 29, 21, 13, 5, 63, 55, 47, 39, 31, 23, 15, 7 };
//IP-2 Table
int IP_2[] = { 16 ,7 ,20, 21, 29, 12, 28, 17, 1 ,15, 23, 26, 5 ,18, 31, 10, 2, 8, 24, 14, 32, 27, 3 ,9, 19, 13, 30, 6 ,22 ,11, 4,
25 };
//Expansion Table
int expansion[] = { 32, 1, 2, 3, 4, 5, 4, 5, 6, 7, 8, 9, 8, 9, 10, 11, 12, 13, 12, 13, 14, 15, 16, 17,
16, 17, 18, 19, 20, 21, 20, 21, 22, 23, 24, 25, 24, 25, 26, 27, 28, 29, 28, 29, 30, 31, 32, 1 };
//S-BOX ARRAYS
//S1 s-box table
int S1[][16] = { { 14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7 },
                 { 0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8 },
                 { 4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0 },
                 { 15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13 } };
//S2 s-box table
int S2[][16] = { { 15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10 },
                 { 3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5 },
                 { 0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15 },
                {13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9 } };
//S3 s-box table
int S3[][16] = { { 10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8 },
                 { 13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1 },
                 { 13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7 },
               { 1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12 } };
//S4 s-box table
int S4[][16] = { { 7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15 },
                 { 13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9 },
               { 10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4 },
{ 3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14 } };
//S5 s-box table
int S5[][16] = { { 2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9 },
                 { 14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6 },
                 { 4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14 },
               { 11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3 } };
//S6 s-box table
int S6[][16] = { { 12, 1 ,10, 15, 9, 2 ,6 ,8 ,0 ,13, 3, 4, 14, 7 ,5 ,11 },
                 { 10 ,15, 4, 2, 7, 12, 9, 5 ,6 ,1 ,13, 14, 0, 11, 3, 8 },
{ 9 ,14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6 },
{ 4 ,3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7 ,6 ,0 ,8 ,13 } };
//S7 s-box table
int S7[][16] = { { 4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1 },
{ 13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6 },
{ 1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2 },
{ 6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12 } };
//S8 s-box table
int S8[][16] = { { 13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7 },
{ 1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2 },
{ 7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8 },
{ 2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11 } };

using namespace std;
//KEY GENERATION FUNCTION
template < class T >  //This function prints a 1D vector of any data type
void print(vector<T> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}
template< class X >   //This function prints a 2D vector of any data type
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
//convert the character to ascii codes 
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
//convert the ascii codes to 8 bits
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
template<class Y>  //resize any 2D vector to chosen number of rows and columns
void Resize(vector<vector<Y> > &v, int rows, int columns)
{
	v.resize(rows);
	for (int i = 0; i < rows; ++i)
	{
		v[i].resize(columns);   //allocate space for columns
	}
}
//perform PC-1 permutation to the key
vector<int> pc1(int kt[],vector<int> &pk)
{
	for (int i = 0; i < 56; i++)
	{
		pk.push_back(kt[pc_1_Table[i] - 1]);
	}
	return pk;
}
//rotate the key according to the number of shifts
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
//perform PC-2 permutation to the key
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
//perform IP-1 permutation on the plain text
vector<vector<int> > ip1_permutation(vector<vector<int>> &a, int c[]) //vector confused,vector non confused, ip table
{
	vector < vector<int> > d;
	Resize(d, a.size(), a[0].size());
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < a[0].size(); j++)
		{
			d[i][j] = a[i][j];
		}
	}
	for (int i = 0; i< a.size(); i++)
		for (int j = 0; j < a[0].size(); j++)
		{
			a[i][j] = d[i][c[j] - 1];
		}
	return a;
}
//deletes spaces in the plain text
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
//adds filler characters in the plain text
vector<char> addFillers(vector<char> & v)
{
	while (v.size() % 8 != 0)
	{
		v.insert(v.end(), 'x');
	}
	return v;
}
//converts each char to ASCII codes
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
//expand the 32 bit text to 48-bits
vector<int> expansionTable(vector<int> &right, vector<int> &temp)
{
	for (int i = 0; i < 48; i++)
	{
		right.push_back(temp[expansion[i] - 1]);
	}
	return right;
}
//perform XOR of the key and the plain text
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
//converts each char to 8-bits
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
void printSide(vector<int> a, int x, int b)
{
	for (int i = x; i < b; i++)
	{
		cout << a[i];
	}
	cout << endl;
}
//ENCRYPTION FUNCTIONS
//convert the 1D 48 bit text to 2D (8x6)
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
vector<vector<int> > dimen(vector<vector<int> > &v, vector<int> a, int r)
{
	int t = 0;
	Resize(v, r, 64);
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < 64; j++)
		{
			v[i][j] = a[j + t];
		}
		t += 64;
	}
	return v;
}
//get rows for the Sboxes
int row(int a, int b)
{
	int c = 2 * a + b;
	return c;
}
//get columns for the Sboxes
int column(int a, int b, int c, int d)
{
	int e = 8 * a + 4 * b + c * 2 + d;
	return e;
}
//perform the reduction of 48 bits to 32 bits
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
	d = S8[row(v[7][0], v[7][5])][column(v[7][1], v[7][2], v[7][3], v[7][4])];
	bitset<4> p(d);
	for (int j = 3; j >= 0; j--)
	{
		x.push_back(p[j]);
	}
}
//perform permutation to the output of the Sbox
vector<int> pBox(vector<int> a, vector<int> &b)
{
	for (int i = 0; i < a.size(); i++)
	{
		b.push_back(a[IP_2[i] - 1]);
	}
	return b;
}
//transfer contents of one vect to another
vector<int> passover(vector<int> &x, vector<int> y)
{
	for (int i = 0; i < y.size(); i++)
	{
		x.push_back(y[i]);
	}
	return x;
}
//perform XOR to R(i+1) and Li
vector<int> xor(vector<int> &a, vector<int> &b, vector<int> &c)
{
	int x ,y;
	for (int i = 0; i <32; i++)
	{
		x = b[i];
		y = c[i];
		a.push_back(x^y);
	}
	return a;
}
//convert binary to ASCII
vector<int> bin2ASCCI(vector<int> &x, vector<int> y)
{
	int arr[8], t = 0, q = 0, decimal = 0;
	while (t < y.size() / 8)
	{
		for (int i = 0; i < 8; i++)
		{
			arr[i] = y[i + q];
		}
		for (int j = 0; j < 8; j++)
		{
			decimal = decimal << 1 | arr[j];
		}
		x.push_back(decimal);
		decimal = 0;
		t++;
	}
	return x;
}
int main()
{
	int k = 7, z = 0, l = 0;
	char t;
	string  originalKey;
	cout << "Enter the key: ";  //prompt the user to enter the key
	getline(cin, originalKey);
	cout << "Enter the message: ";   //prompt the user to enter the plain text
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
	/*GENERATION OF THE ENCRYPTION*/
	toASCII(asciiKey, key);
	/*populate the bits of the key to an integer array */
	toBINARY(asciiKey, kTemp);
	
	/*resize any 2D-arrays to be used*/
	Resize(tempKey, ROWS, COLUMNS);
	Resize(encryptionKey, ROWS, PC_2_COLS);
	Resize(textChar, rows, 8);
	Resize(textAscii, rows, 8);
	Resize(textBin, rows, 64);
	//perform PC-1 permutation
	pc1(kTemp, PC_1_key);
	/*printSide(PC_1_key, 0, 28);
	printSide(PC_1_key, 28, 56);*/
	//key rotation schedule
	rotationSchedule(tempKey, PC_1_key, x);
	print2D(tempKey);
	////conversion to PC-2 table
	pc2(tempKey, encryptionKey, pc_2_Table);
	//print2D(encryptionKey);
	
	//GENERATION OF THE PLAIN TEXT
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
	/*print2D(textBin);*/
	//IP-1 permutation
	ip1_permutation(textBin, IP_1);
	/*print2D(textBin);*/
	
	cout << endl;
	//generate the text to be encrypted
	//THE ENCRYPTING STARTS HERE
	while (cycle < rows)
	{
		for (int i = 0; i < 32; i++) tempTextLeft.push_back(textBin[cycle][i]);  //transfer the left half of the text in a specific row of 64 bits
		for (int i = 32; i < textBin[cycle].size(); i++) tempTextRight.push_back(textBin[cycle][i]);  //transfer the right half of the text in a specific row of 64 bits
		
		for (int q = 0; q < 16; q++)                       //perform the encryption schedule 16 times
		{
			dummy1 = tempTextRight;                        //temp L(i+1) = Ri
			expansionTable(rightText, tempTextRight);      //retrieve the text and perform the expansion from 32 bits to 48 bits
			XOR(encryptionKey, rightText, cipherText, q);  //perform XOR of the 48 bit text and key at each round q
			tempTextRight.clear();                         //vectors are cleared to be re-used
			rightText.clear();
			to2D(temp, cipherText);                        //convert the temporary cipher text to 2D
			cipherText.clear();
			sBox(temp, tempTextRight);                     //reduce the cipher text from 48 bits to 32 bits using S-boxes
			pBox(tempTextRight, rightText);                //perform permutation to the output of the S-Box
			tempTextRight.clear();
			xor(cipherText,tempTextLeft,rightText);        //peform XOR to Li and R(i+1)
			rightText.clear();
			tempTextLeft = dummy1;                         //L(i+1) = Ri
			passover(tempTextRight, cipherText);           //Ri is to be encrypted 16 times
			cipherText.clear();
		}
		for (int i = 0; i < tempTextLeft.size(); i++){ CIPHER.push_back(tempTextLeft[i]); }     //push L16 to the cipher text
		for (int i = 0; i < tempTextRight.size(); i++){ CIPHER.push_back(tempTextRight[i]); }   //push R16 to the cipher text
		tempTextRight.clear();   //clear this vector as it will be used in until the entire text is encrypted
		tempTextLeft.clear();
		cycle++;                //increment to another row of text
	}
	int length = CIPHER.size() / 8,decimal=0,tr=0;
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			decimal = decimal << 1 | CIPHER[j + tr];
		}
		numbers.push_back(decimal);
		decimal = 0;
		tr += 8;
	}
	print(numbers);
	/*print(CIPHER);*/
	/*dimen(dum, CIPHER,rows);
	print2D(dum);*/
	system("pause");
	return 0;
} 