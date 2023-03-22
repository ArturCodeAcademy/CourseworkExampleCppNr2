#pragma once

#include <map>
#include <vector>
#include <algorithm>

#include "EncoderDecoderBase.h"

namespace ED
{
	class DictionaryCipher : public EncoderDecoderBase
	{
	private:
		map<char, char> encodeDictionary, decodeDictionary;

	public:
		DictionaryCipher(int key);
		string Encode(string text) override;
		string Decode(string text) override;

	private:
		string Code(string text, const map<char, char>* const dictionary);
		void InitDictionary();
	};
}