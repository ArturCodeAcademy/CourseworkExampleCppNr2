#include "CaesarCipher.h"

string ED::CaesarCipher::Encode(string text)
{
	for (int i = 0; i < text.size(); i++)
	{
		text[i] = EncodeLetter(text[i], 'A', 'Z');
		text[i] = EncodeLetter(text[i], 'a', 'z');
		text[i] = EncodeLetter(text[i], '0', '9');
	}
	return text;
}

string ED::CaesarCipher::Decode(string text)
{
	for (int i = 0; i < text.size(); i++)
	{
		text[i] = DecodeLetter(text[i], 'A', 'Z');
		text[i] = DecodeLetter(text[i], 'a', 'z');
		text[i] = DecodeLetter(text[i], '0', '9');
	}
	return text;
}
char ED::CaesarCipher::EncodeLetter(char letter, char begin, char end)
{
	if (begin <= letter && letter <= end)
	{
		return (letter - begin + key) % (end - begin + 1) + begin;
	}
	return letter;
}

char ED::CaesarCipher::DecodeLetter(char letter, char begin, char end)
{
	if (begin <= letter && letter <= end)
		return (letter - begin - key + end - begin + 1) % (end - begin + 1) + begin;
	return letter;
}