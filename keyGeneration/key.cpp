#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include<bitset>
#include<vector>
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

int main()
{
	vector<char> key;
	vector<int> asciiKey;
	vector<bitset<8> > bitKey;
	int ascii;
	string  originalKey;
	getline(cin, originalKey);
	for (int i = 0; i < originalKey.length(); i++)
	{
		key.push_back(originalKey[i]);
	}
	print(key);
	//convert key to ASCII CODE
	for (int i = 0; i <key.size(); i++)
	{
		ascii = int(key[i]);
		asciiKey.push_back(ascii);
	}
	print(asciiKey);
	cout << endl;
	//convert key to bits
	for (int i = 0; i < asciiKey.size(); i++)
	{
			bitset<8> p(asciiKey[i]);    
			bitKey.push_back(p);
	}
	print(bitKey);
	system("pause");
	return 0;
}
