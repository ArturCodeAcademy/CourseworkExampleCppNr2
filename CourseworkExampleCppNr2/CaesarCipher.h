#pragma once

#include <string>

#include "EncoderDecoderBase.h"

using namespace std;

namespace ED
{
	class CaesarCipher : public EncoderDecoderBase
	{
	public:
		CaesarCipher(int key) : EncoderDecoderBase(key % ('Z' - 'A' + 1)) { }
		string Encode(string text) override;
		string Decode(string text) override;

	private:
		char EncodeLetter(char letter, char begin, char end);
		char DecodeLetter(char letter, char begin, char end);
	};	
}