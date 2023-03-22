#include "RandomInsertionCipher.h"

ED::RandomInsertionChipher::RandomInsertionChipher(int key)
	: EncoderDecoderBase(abs(key)) { }

string ED::RandomInsertionChipher::Encode(string text)
{
	string res = "";
	for (char ch : text)
	{
		res += ch;
		for (int i = 0; i < key; i++)
		{
			res += GetRandomLetterOrNumber();
		}
	}
	return res;
}

string ED::RandomInsertionChipher::Decode(string text)
{
	string res = "";
	for (int i = 0; i < text.size(); i += key + 1)
	{
		res += text[i];
	}
	return res;
}

char ED::RandomInsertionChipher::GetRandomLetterOrNumber()
{
	switch (rand() % 3)
	{
	case 0:
		return (char)((rand() % ('Z' - 'A')) + 'A');
	case 1:
		return (char)((rand() % ('z' - 'a')) + 'a');
	default:
		return (char)((rand() % ('0' - '9')) + '0');
	}
}

char ED::RandomInsertionChipher::GetRandomSymbol()
{
	return (char)rand();
}