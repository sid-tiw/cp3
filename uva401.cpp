#include <algorithm>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    char tstr[1000];
    map<char, char> ass = {{'E', '3'}, {'3', 'E'}, {'J', 'L'}, {'L', 'J'},
                           {'S', '2'}, {'2', 'S'}, {'Z', '5'}, {'5', 'Z'}};
    while (true) {
        cin.getline(tstr, 1000);
        string str(tstr);
        if (str == "") return 0;
        string temp1 = str;
        string temp2 = str;
        reverse(temp1.begin(), temp1.end());
        for (int i = 0; i < temp2.size(); i++) {
            char ch = temp2[i];
            if (ch == 'B' || ch == 'C' || ch == 'D' || ch == 'F' || ch == 'G' ||
                ch == 'K' || ch == 'N' || ch == 'P' || ch == 'Q' || ch == 'R' ||
                ch == '4' || ch == '6' || ch == '9' || ch == '7' || ch == '0' ||
                ch == 'o') {
                temp2 = "";
                break;
            }
            ch = ass[ch];
            if (ch == 0) ch = temp2[i];
            temp2.at(i) = ch;
        }
        reverse(temp2.begin(), temp2.end());
        if (temp1 == str && temp2 == str)
            cout << str << " -- is a mirrored palindrome.\n";
        else if (temp1 == str)
            cout << str << " -- is a regular palindrome.\n";
        else if (temp2 == str)
            cout << str << " -- is a mirrored string.\n";
        else
            cout << str << " -- is not a palindrome.\n";
        cout << "\n";
    }
    return 0;
}