#include <iostream>
#include <string>

using namespace std;

#ifndef VIGENERE_CIPHER_VIGENERE_ENCODER_H
#define VIGENERE_CIPHER_VIGENERE_ENCODER_H

class VigenereEncoder {

private:

    string key;

    string mapEncoding(const string &text, char (charEncodeFunc)(char, char));

public:

    explicit VigenereEncoder(const string &key);

    string encrypt(const string &text);

    string decrypt(const string &text);

};

#endif
