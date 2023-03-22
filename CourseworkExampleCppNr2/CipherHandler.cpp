#include "CipherHandler.h"

string ED::CipherHandler::Encode(string text)
{
	string res = text;
	for (EncoderDecoderBase* ed : ciphers)
		res = *ed >> res;
	return res;
}

string ED::CipherHandler::Decode(string text)
{
	string res = text;
	for (r_iterator it = ciphers.rbegin(); it != ciphers.rend(); it++)
		res = **it << res;
	return res;
}