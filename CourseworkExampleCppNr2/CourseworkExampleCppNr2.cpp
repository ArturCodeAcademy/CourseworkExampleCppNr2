#include "UI.h"

using namespace std;

void test()
{
    vector<ED::EncoderDecoderBase*> ciphers =
    {
        new ED::CaesarCipher(5),
        new ED::DictionaryCipher(6),
        new ED::RandomInsertionChipher(1),
        new ED::RandomInsertionChipher(5),
        new ED::CaesarCipher(2),
        new ED::DictionaryCipher(1)
    };
    ED::CipherHandler ch(ciphers);
    string text = "Hello<-=->\nworld<-+->";
    string encoded = ch.Encode(text);
    string decoded = ch.Decode(encoded);

    cout << encoded << endl;
    cout << decoded << endl;
}

int main()
{
    //test();

    UI ui;

    auto handler = ui.SelectCiphers();
    string text = ui.GetText();
    do
    {
        string res = ui.ApplyModifiers(handler, text);
        ui.PrintResult(res);

        cout << "Close program (1) or continue (2)?" << endl;
        int choice;
        cin >> choice;
        if (choice == 1)
            break;
    } while (true);
}
