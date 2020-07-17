#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void change_c(string temp, int suits[][5], map<char, int> assoc) {
    char ch_f = temp.at(0);
    char ch_s = temp.at(1);
    int second = assoc[ch_f] - 1, first;
    if (second == -1) second = 4;
    first = assoc[ch_s] - 1;
    suits[first][second]++;
}

int total(int arr[5]) {
    int total = 0;
    for (int i = 0; i < 5; i++) total += arr[i];
    return total;
}

int main() {
    string temp;
    map<char, int> assoc;
    assoc['J'] = 1;
    assoc['Q'] = 2;
    assoc['K'] = 3;
    assoc['A'] = 4;
    assoc['S'] = 1;
    assoc['D'] = 2;
    assoc['H'] = 3;
    assoc['C'] = 4;
    string prev_out = "-1";
    char l_str[3];
    int l_count = 0;
    vector<string> inp_str;
    while (scanf("%s", l_str) != -1) {
        l_count++;
        inp_str.push_back(l_str);
    }
    l_count /= 13;
    for (int kk = 0; kk < l_count; kk++) {
        vector<string> str;
        int pnt = 0, pnt_no_tr = 0;
        int suits[4][5];
        bool su_stop[4];
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 5; j++) suits[i][j] = 0;
        for (int i = 0; i < 13; i++) {
            temp = inp_str[kk * 13 + i];
            str.push_back(temp);
            change_c(temp, suits, assoc);
        }
        for (int it = 0; it < str.size(); it++) pnt += assoc[str.at(it).at(0)];
        for (int i = 0; i < 4; i++) {
            int t_to = total(suits[i]);
            if (suits[i][2] > 0 && t_to == 1) pnt--;
            if (suits[i][1] > 0 && t_to <= 2) pnt--;
            if (suits[i][0] > 0 && t_to <= 3) pnt--;
        }
        pnt_no_tr = pnt;
        for (int i = 0; i < 4; i++) {
            int t_to = total(suits[i]);
            if (t_to == 2) pnt++;
            if (t_to == 1) pnt += 2;
            if (t_to == 0) pnt += 2;
        }
        int flag = 1;
        string t_ar[4];
        for (int i = 0; i < 4; i++) {
            int t_to = total(suits[i]);
            char t_num[5];
            itoa(t_to, t_num, 10);
            t_ar[i] = t_num;
            string ch =
                i == 0 ? "S" : i == 1 ? "D" : i == 2 ? "H" : i == 3 ? "C" : "";
            t_ar[i] += ch;
            if (suits[i][3] > 0)
                su_stop[i] = true;
            else if (suits[i][2] > 0 && t_to > 1)
                su_stop[i] = true;
            else if (suits[i][1] > 0 && t_to > 2)
                su_stop[i] = true;
            else
                su_stop[i] = false;
            flag *= su_stop[i];
        }
        sort(t_ar, t_ar + 4);
        prev_out = "";
        if (pnt < 14) {
            prev_out = "PASS\n";
        } else if (pnt_no_tr >= 16 && flag == 1) {
            prev_out = "BID NO-TRUMP\n";
        } else if (pnt >= 14) {
            prev_out = "BID ";
            prev_out += t_ar[3].at(1);
            prev_out += "\n";
        }
        cout << prev_out;
    }
    return 0;
}