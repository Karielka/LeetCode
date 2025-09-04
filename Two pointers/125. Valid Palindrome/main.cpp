#include <string>

std::string normalize_ascii_fast(const std::string& s) {
    std::string out;
    out.reserve(s.size());
    for (unsigned char c : s) {
        if (c >= '0' && c <= '9')         out.push_back((char)c);
        else if (c >= 'A' && c <= 'Z')    out.push_back((char)(c + 32)); // tolower
        else if (c >= 'a' && c <= 'z')    out.push_back((char)c);
        // всё остальное — пропускаем
    }
    return out;
}


class Solution {
public:
    bool isPalindrome(std::string s) {
        std::string str = normalize_ascii_fast(s);
        //std::cout << normalize_ascii_fast(s);
        for (int i = 0; i < str.length() / 2; i++) {
            if (str[i] != str[str.length() - i - 1])
                return false;
        }
        return true;
    }
};