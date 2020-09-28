#include <iostream>
#include <string>
#include "VigenereEncoder.h"

#define uint unsigned int
using namespace std;

char isAlphabet(char c) {
    return c >= 'A' && c <= 'Z';
}

char encryptCharacterByKey(char textChar, char keyChar) {
    return (textChar + keyChar - (2 * 'A')) % 26 + 'A';
}

char decryptCharacterByKey(char textChar, char keyChar) {
    return (textChar - keyChar + 26) % 26 + 'A';
}

string VigenereEncoder::mapEncoding(const string &text, char (charEncodeFunc)(char, char)) {
    string out;
    for (uint i = 0, j = 0; i < text.length(); i++) {
        char c = toupper(text[i]);
        if (!isAlphabet(c)) {
            out += c;
            continue;
        }
        out += charEncodeFunc(c, key[j]);
        j = (j + 1) % key.length();
    }
    return out;
}

VigenereEncoder::VigenereEncoder(const string &key) {
    for (char strChar : key)
        this->key += toupper(strChar);
}

string VigenereEncoder::encrypt(const string &text) {
    return mapEncoding(text, encryptCharacterByKey);
}

string VigenereEncoder::decrypt(const string &text) {
    return mapEncoding(text, decryptCharacterByKey);
}


