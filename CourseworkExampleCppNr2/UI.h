#pragma once

#include <iostream>
#include <fstream>

#include "CipherHandler.h"
#include "CaesarCipher.h"
#include "DictionaryCipher.h"
#include "RandomInsertionCipher.h"

class UI
{
public:

	ED::CipherHandler SelectCiphers()
	{
		int count, index = 0;
		vector<ED::EncoderDecoderBase*> ciphers;
		cout << "Select count of ciphers: ";
		cin >> count;
		
		while (index < count)
		{
			cout << "Select " << ++index << " of " << count << endl;
			ciphers.push_back(SelectCipher());
		}
		return ED::CipherHandler(ciphers);
	}

	string GetText()
	{
		string text = "";
		string line;
		cout << "Write text to file 'info.txt'" << endl;
		system("pause");

		ifstream file("info.txt");
		
		while (file >> line)
			text += "\n" + line;
		file.close();
		return text;
	}

	string ApplyModifiers(ED::CipherHandler& handler, string text)
	{
		int choice;
		do
		{
			cout << "Decode (1) or Encode (2) text?" << endl;
			cin >> choice;
		} while (choice < 1 || choice > 2);

		if (choice == 1)
			return handler.Encode(text);
		return handler.Decode(text);
	}

	void PrintResult(string res)
	{
		int choice;
		do
		{
			cout << "Print result to console (1) or to file 'result.txt' (2)?" << endl;
			cin >> choice;
		} while (choice < 1 || choice > 2);

		if (choice == 1)
		{
			cout << res << endl;
			return;
		}

		ofstream file("result.txt");
		file << res << endl;
		file.close();
	}

private:

	ED::EncoderDecoderBase* SelectCipher()
	{
		int selection;
		do
		{
			cout << "1) Caesar cipher" << endl;
			cout << "2) Dictionary cipher" << endl;
			cout << "3) Random insertion cipher" << endl;
			cin >> selection;
		} while (selection < 1 || selection > 3);

		int key;
		cout << "Select key: ";
		cin >> key;
		
		switch (selection)
		{
		case 1:
			return new ED::CaesarCipher(key);
		case 2:
			return new ED::DictionaryCipher(key);
		case 3:
			return new ED::RandomInsertionChipher(key);
		default:
			return nullptr;
		}
	}
};