#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

char next(char ch) {
    if (ch == 'N') return 'E';
    if (ch == 'E') return 'S';
    if (ch == 'S') return 'W';
    if (ch == 'W') return 'N';
}

int main() {
    char ch;
    std::cin >> ch;
    map<char, char> ass = {{'C', '1'}, {'D', '2'}, {'S', '3'}, {'H', '4'}};
    map<char, string> ass2 = {
        {'T', "10"}, {'J', "11"}, {'Q', "12"}, {'K', "13"}, {'A', "14"}};
    while (ch != '#') {
        vector<string> arr[4];
        string str1, str2;
        std::cin >> str1;
        std::cin >> str2;
        str1 += str2;
        for (int i = 0; i < 52; i++) {
            string temp = str1.substr(2 * i, 2);
            string construct;
            construct = ass[temp.at(0)];
            if (temp.at(1) >= '2' && temp.at(1) <= '9')
                construct += (atoi(temp.substr(1, 1).c_str()) - 2 + 'A');
            else
                construct += ('A' + (atoi(ass2[temp.at(1)].c_str()) - 2));
            arr[i % 4].push_back(construct);
        }
        for (int i = 0; i < 4; i++) sort(arr[i].begin(), arr[i].end());
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < arr[i].size(); j++) {
                string temp = arr[i][j];
                string construct = temp[0] == '1'
                                       ? "C"
                                       : temp[0] == '2'
                                             ? "D"
                                             : temp[0] == '3'
                                                   ? "S"
                                                   : temp[0] == '4' ? "H" : "1";
                int ch = int(temp[1] - 'A') + 2;
                if (ch >= 2 && ch <= 9)
                    construct += to_string(ch);
                else
                    construct +=
                        ch == 10
                            ? "T"
                            : ch == 11
                                  ? "J"
                                  : ch == 12
                                        ? "Q"
                                        : ch == 13 ? "K" : ch == 14 ? "A" : "1";
                arr[i][j] = construct;
            }
        }
        map<char, vector<string>> ans;
        for (int i = 0; i < 4; i++) {
            ch = next(ch);
            ans[ch] = arr[i];
        }
        std::cout << "S: ";
        for (int i = 0; i < 13; i++) {
            std::cout << ans['S'][i];
            if (i != 12) cout << " ";
        }
        std::cout << "\nW: ";
        for (int i = 0; i < 13; i++) {
            std::cout << ans['W'][i];
            if (i != 12) cout << " ";
        }
        std::cout << "\nN: ";
        for (int i = 0; i < 13; i++) {
            std::cout << ans['N'][i];
            if (i != 12) cout << " ";
        }
        std::cout << "\nE: ";
        for (int i = 0; i < 13; i++) {
            std::cout << ans['E'][i];
            if (i != 12) cout << " ";
        }
        std::cout << "\n";
        std::cin >> ch;
    }
    return 0;
}