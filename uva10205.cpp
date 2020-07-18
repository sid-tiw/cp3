#include <string.h>

#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

string next_f(string str) {
    if (strcmp(str.c_str(), "2") >= 0 && strcmp(str.c_str(), "9") <= 0)
        return to_string(atoi(str.c_str()) + 1);
    if (!str.compare("10")) return "Jack";
    if (!str.compare("Jack")) return "Queen";
    if (!str.compare("Queen")) return "King";
    if (!str.compare("King")) return "Ace";
    if (!str.compare("Ace")) return "-1";
}

string next_s(string str) {
    if (!str.compare("Clubs")) return "Diamonds";
    if (!str.compare("Diamonds")) return "Hearts";
    if (!str.compare("Hearts")) return "Spades";
    if (!str.compare("Spades")) return "Clubs";
}

string next(string str) {
    int t = str.find(' ');
    string temp1 = next_f(str.substr(0, t));
    string temp2 = str.substr(t + 4);
    if (!temp1.compare("-1")) {
        temp2 = next_s(temp2);
        temp1 = "2";
    }
    string ans = temp1;
    ans += string(" of ");
    ans += temp2;
    return ans;
}

int main() {
    int t;
    cin >> t;
    vector<string> som, temp;
    som.push_back("2 of Clubs");
    for (int i = 0; i < 51; i++) som.push_back(next(som.back()));
    while (t--) {
        temp.clear();
        temp = som;
        // for (auto it : temp) cout << it << "\n";
        int n;
        cin >> n;
        vector<int> arr[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 52; j++) {
                int tem_e;
                cin >> tem_e;
                arr[i].push_back(tem_e);
            }
        }
        char shuffle[4];
        cin.getline(shuffle, 4);
        vector<int> shuffs;
        while (!cin.eof()) {
            cin.getline(shuffle, 4);
            if (strcmp(shuffle, "") == 0) break;
            shuffs.push_back(atoi(shuffle));
        }
        for (auto it : shuffs) {
            vector<string> state;
            for (auto jt : arr[it - 1]) state.push_back(temp[jt - 1]);
            temp = state;
        }
        for (auto it : temp) cout << it << "\n";
        if(t != 0)
            cout << "\n";
    }
}