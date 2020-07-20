#include <math.h>

#include <iostream>
#include <string>

using namespace std;

int main() {
    char str[100000];
    int t;
    cin >> t;
    cin.ignore();
    int tt = t;
    while (t--) {
        cin.getline(str, 100000);
        string tstr(str), temp = "";
        for (int i = 0; i < tstr.size(); i++)
            if (tstr[i] >= 'a' && tstr[i] <= 'z') temp += tstr[i];
        const int k = sqrt(temp.size());
        if (k * k != temp.size()) {
            cout << "Case #" << (tt - t) << ":\n"
                 << "No magic :(\n";
            continue;
        }
        string te[3] = {"", "", ""};
        char grid[k][k];
        for (int i = 0; i < k; i++)
            for (int j = 0; j < k; j++) grid[i][j] = temp[i * k + j];
        for (int i = 0; i < k; i++)
            for (int j = 0; j < k; j++) {
                te[0] += grid[j][i];
                te[1] += grid[k - i - 1][k - j - 1];
                te[2] += grid[k - j - 1][k - i - 1];
            }
        if (!te[0].compare(te[1]) && !te[1].compare(te[2]) &&
            !te[2].compare(temp))
            cout << "Case #" << (tt - t) << ":\n" << k << "\n";
        else
            cout << "Case #" << (tt - t) << ":\n"
                 << "No magic :(\n";
    }
}