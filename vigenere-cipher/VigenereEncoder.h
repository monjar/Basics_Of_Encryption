#include <iostream>
#include <string>
#ifndef VIGENERE_CIPHER_VIGENERE_ENCODER_H
#define VIGENERE_CIPHER_VIGENERE_ENCODER_H

class VigenereEncoder {

private:

    std::string key;

    std::string mapEncoding(const std::string &text, char (charEncodeFunc)(char, char));

public:

    explicit VigenereEncoder(const std::string &key);

    std::string encrypt(const std::string &text);

    std::string decrypt(const std::string &text);

};

#endif
