#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pi;
typedef vector<pi> vii;

template <class InpIter, class T>
InpIter binary_s(InpIter start, InpIter end, T val) {
    InpIter temp = end;
    end--;
    InpIter mid;
    while (start <= end) {
        mid = start + (end - start) / 2;
        if (*mid == val) return mid;
        if (*mid > val) end = mid - 1;
        if (*mid < val) start = mid + 1;
    }
    return temp;
}

template <class InpIter>
void print(InpIter start, InpIter end) {
    while (start != end) {
        cout << *start << " ";
        start++;
    }
    cout << "\n";
}

template <class InpIter>
void scan(InpIter start, InpIter end) {
    while (start != end) {
        cin >> (*start);
        start++;
    }
}

bool check_palindrome(string str) {
    for (int i = 0; i < str.size() / 2; i++)
        if (str[i] != str[str.size() - 1 - i]) return false;
    return true;
}

int main() {
    char tstr[1000];
    while (true) {
        cin.getline(tstr, 1000);
        string str(tstr);
        if (str == "") return 0;
        if (str.size() == 0) return 0;
        vs temp;
        set<string> som;
        for (int i = 0; i < str.size(); i++)
            for (int j = i; j < str.size(); j++)
                temp.push_back(str.substr(i, j - i + 1));
        for (int i = 0; i < temp.size(); i++) {
            if (check_palindrome(temp[i])) som.insert(temp[i]);
        }
        cout << "The string '" << str << "' contains " << som.size()
             << " palindromes.\n";
    }
    return 0;
}