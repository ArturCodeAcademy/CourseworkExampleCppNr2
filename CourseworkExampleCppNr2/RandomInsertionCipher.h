#pragma once

#include "EncoderDecoderBase.h"

namespace ED
{
	class RandomInsertionChipher : public EncoderDecoderBase
	{
	public:
		RandomInsertionChipher(int key);
		string Encode(string text) override;
		string Decode(string text) override;

	private:
		char GetRandomLetterOrNumber();
		char GetRandomSymbol();
	};
}