#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

bool is_pal(long long num) {
    string temp = to_string(num);
    string rev = temp;
    reverse(rev.begin(), rev.end());
    return rev == temp;
}

long long rev(long long num) {
    string temp = to_string(num);
    reverse(temp.begin(), temp.end());
    string::size_type sz = 0;
    return stoll(temp, &sz, 10);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long num;
        cin >> num;
        int count = 0;
        do {
            num = num + rev(num);
            count++;
        } while (!is_pal(num));
        cout << count << " " << num << "\n";
    }
}