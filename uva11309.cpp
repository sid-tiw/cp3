#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string temp;
        cin >> temp;
        int hrs = stoi(temp.substr(0, 2)), mins = stoi(temp.substr(3, 2));
        int thrs = hrs, tmins = mins;
        do {
            if (tmins == 59) {
                if (thrs == 23)
                    thrs = 0;
                else
                    thrs++;
                tmins = 0;
            } else
                tmins++;
            int val = thrs * 100 + tmins;
            string mn = to_string(val);
            string rev = mn;
            reverse(rev.begin(), rev.end());
            if (mn == rev) {
                if (thrs < 10) cout << "0";
                cout << thrs << ":";
                if (tmins < 10) cout << "0";
                cout << tmins << "\n";
				break;
            }
        } while (thrs != hrs || tmins != mins);
    }
}