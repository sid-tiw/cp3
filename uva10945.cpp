#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
    char str[1000];
    while (true) {
        cin.getline(str, 1000);
        string tstr(str);
        if (tstr == "DONE") break;
        string nstr = "";
        for (int i = 0; i < tstr.size(); i++) {
            if ((tstr[i] >= 'a' && tstr[i] <= 'z') ||
                (tstr[i] >= 'A' && tstr[i] <= 'Z'))
                nstr += (char)tolower(tstr[i]);
        }
        string temp = nstr;
        reverse(temp.begin(), temp.end());
        if (temp == nstr)
            cout << "You won't be eaten!\n";
        else
            cout << "Uh oh..\n";
    }
}