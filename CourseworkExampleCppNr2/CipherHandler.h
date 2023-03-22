#pragma once
#include <vector>

#include "EncoderDecoderBase.h"

#define r_iterator vector<EncoderDecoderBase*>::reverse_iterator

namespace ED
{
	class CipherHandler
	{
	private:
		vector<EncoderDecoderBase*> ciphers;

	public:
		CipherHandler(vector<EncoderDecoderBase*>ciphers) : ciphers(ciphers) { }
		string Encode(string text);
		string Decode(string text);
	};
}