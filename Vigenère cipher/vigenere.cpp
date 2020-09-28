#include <iostream>
#include <string>

#define uint unsigned int
using namespace std;

char isAlphabet(char c) {
    return c >= 'A' && c <= 'Z';
}

class VigenereEncoder {

private:

    string key;

    string mapEncoding(const string &text, char (charEncodeFunc)(char, char)) {
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

public:

    VigenereEncoder(const string &key) {
        for (char strChar : key)
            this->key += toupper(strChar);
    }

    string encrypt(const string &text) {
        return mapEncoding(text, encryptCharacterByKey);
    }

    string decrypt(string text) {
        return mapEncoding(text, decryptCharacterByKey);
    }

    static char encryptCharacterByKey(char textChar, char keyChar) {
        return (textChar + keyChar - (2 * 'A')) % 26 + 'A';
    }

    static char decryptCharacterByKey(char textChar, char keyChar) {
        return (textChar - keyChar + 26) % 26 + 'A';
    }

};

int main() {
    VigenereEncoder cipher("MYKEY");
    string text = "A slumber did my spirit seal;\nI had no human fears:\nShe seemed a thing that could not feel\nThe touch of earthly years.\nNo motion has she now, no force;";
    string encrypted = cipher.encrypt(text);
    string decrypted = cipher.decrypt(encrypted);
    cout << text << endl;
    cout << "Encrypted:\n" << encrypted << endl;
    cout << "Decrypted:\n" << decrypted << endl;
}