#include <bits/stdc++.h>
using namespace std;
std::string decodeMorse(std::string morseCode) {
    std::string decoded;
    int n = morseCode.size() - 1;
    int i = 0;
    while (morseCode[i] == ' ')
        i++;
    while (morseCode[n] == ' ')
        n--;
    for (; i <= n; i++) {
        string letter;
        if (i <= n - 2 && morseCode[i] == ' ' && morseCode[i + 1] == ' ')
            decoded += " ";
        while (i <= n && morseCode[i] != ' ') {
            letter += morseCode[i];
            i++;
        }
        decoded = decoded + MORSE_CODE[letter];
    }
    return decoded;
}