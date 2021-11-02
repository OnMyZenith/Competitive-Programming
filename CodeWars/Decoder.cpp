#include <bits/stdc++.h>

using namespace std;
struct Decoder
{
    static std::string decode(const std::string &p_what)
    {
        std::string res = p_what;
        std::map<char, char> decodeOneChar;
        std::string in = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz ?.,0123456789!@#$%^&*()_+-";
        for (const auto &w : in)
        {
            decodeOneChar[Encoder::encode(std::string("") + w)[0]] = w;
        }
        // "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz ?.,0123456789!@#$%^&*()_+-"  = "13579, acegikmoqsuwyACEGIKbdfhjlnprtvxzBDFHJLNPRTVXZ?.68MOQSUWY024!@#$%^&*()_+-"
        map<char, char> decodeOnce;
        for (int i = 0; i < res.length(); i++)
        {
            int n = i;
            do
            {
                res[i] = decodeOneChar[res[i]];
            } while (n--);
        }

        return res;
    }
};