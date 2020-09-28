#include <iostream>
#include "VigenereEncoder.h"
#include "VigenereAttacker.h"


using namespace std;

int main() {
    VigenereEncoder cipher("AKEYQ");
//    string text = "A slumber did my spirit seal;\nI had no human fears:\nShe seemed a thing that could not feel\nThe touch of earthly years.\nNo motion has she now, no force;";
    string text = "A slumber did my spirit seal; I had no human fears";
    string encrypted = cipher.encrypt(text);
    string decrypted = cipher.decrypt(encrypted);
    cout << text << endl;
    cout << "Encrypted:\n" << encrypted << endl;
    cout << "Decrypted:\n" << decrypted << endl;


    VigenereAttacker attacker;
    cout<<"ANSWER:" + attacker.findKey(encrypted,text);

}