#pragma once

#include <string>

using namespace std;

namespace ED
{
	class EncoderDecoderBase
	{
	protected:
		int key;

	public:

		EncoderDecoderBase(int key)
		{
			this->key = key;
		}

		virtual string Encode(string text) = 0;
		virtual string Decode(string text) = 0;

		inline string operator >> (string text)
		{
			return Encode(text);
		}

		inline string operator << (string text)
		{
			return Decode(text);
		}
	};
}