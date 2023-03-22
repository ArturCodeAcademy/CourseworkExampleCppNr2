#include "DictionaryCipher.h"

ED::DictionaryCipher::DictionaryCipher(int key) : EncoderDecoderBase(key)
{
	InitDictionary();
}

string ED::DictionaryCipher::Encode(string text)
{
	return Code(text, &encodeDictionary);
}

string ED::DictionaryCipher::Decode(string text)
{
	return Code(text, &decodeDictionary);
}

string ED::DictionaryCipher::Code(string text, const map<char, char>* const dictionary)
{
	for (int i = 0; i < text.size(); i++)
	{
		map<char, char>::const_iterator it = dictionary->find(text[i]);
		if (it != dictionary->end())
			text[i] = it->second;
	}
	return text;
}

void ED::DictionaryCipher::InitDictionary()
{
	encodeDictionary.clear();
	srand(key);
	vector<char> keys, values;
	for (char i = 'A'; i <= 'Z'; i++)
		keys.push_back(i);
	for (char i = 'a'; i <= 'z'; i++)
		keys.push_back(i);
	for (char i = '0'; i <= '9'; i++)
		keys.push_back(i);
	keys.push_back(' ');
	values = keys;
	random_shuffle(values.begin(), values.end());

	for (int i = 0; i < keys.size(); i++)
	{
		encodeDictionary[keys[i]] = values[i];
		decodeDictionary[values[i]] = keys[i];
	}
}