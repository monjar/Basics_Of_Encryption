#include <string>
#include "VigenereAttacker.h"
#include "VigenereEncoder.h"
const int MAX_KEY_LENGTH = 5;

std::string backTrack(std::string key, const std::string &encryptedText, const std::string& actualText){
    VigenereEncoder encoder(key);
    std::string decryptedText = encoder.decrypt(encryptedText);
    if(decryptedText == actualText)
        return key;
    else if(key.length() >= MAX_KEY_LENGTH)
        return "";
    for (int letter = 0; letter < 26; ++letter) {
        std::string nextCharAns = backTrack(key + (char)('A' + letter), encryptedText, actualText);
        if (!nextCharAns.empty())
            return nextCharAns;
    }
    return "";
}

std::string VigenereAttacker::findKey(const std::string &encryptedText, const std::string &actualText) {
    std::string upperText;
    for (char strChar : actualText)
        upperText += toupper(strChar);
    return backTrack("" , encryptedText, upperText);
}
