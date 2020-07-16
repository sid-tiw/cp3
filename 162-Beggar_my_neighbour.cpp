#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

template <class T>
void print(T arr) {
    for (auto it : arr) cout << it << " ";
    cout << "\n";
}

bool isNotFace(string str) {
    char ch = str.at(1);
    if (ch == 'K' || ch == 'Q' || ch == 'J' || ch == 'A') return false;
    return true;
}

int face_number(string str) {
    char ch = str.at(1);
    int val = (ch == 'J')
                  ? 1
                  : (ch == 'Q') ? 2 : (ch == 'K') ? 3 : (ch == 'A') ? 4 : -1;
    return val;
}

int main() {
    while (true) {  // a single deck of a card in one loop
        vector<string> current_stack;
        list<string> players[2];
        string temp;
        cin >> temp;
        if (temp == "#") break;
        players[0].push_back(temp);
        for (int i = 0; i < 51; i++) {
            cin >> temp;
            if (i % 2 == 0)
                players[1].push_back(temp);
            else
                players[0].push_back(temp);
        }
        int turn = 0, last_face = -1, won;
        while (true) {
            if (last_face == -1) {
                if (players[turn].size() == 0) {
                    won = !turn;
                    break;
                }
                string t_card = players[turn].back();
                bool val = !isNotFace(t_card);
                current_stack.push_back(t_card);
                players[turn].erase(--players[turn].end());
                if (val) last_face = turn;
            } else {
                string t_card = current_stack[current_stack.size() - 1];
                int l_m = face_number(t_card), i;
                bool flag = false;
                for (i = 0; i < l_m; i++) {
                    if (!players[turn].size()) {
                        won = !turn;
                        flag = true;
                        break;
                    }
                    string t_c_in = players[turn].back();
                    bool val = !isNotFace(t_c_in);
                    current_stack.push_back(t_c_in);
                    players[turn].erase(--players[turn].end());
                    if (val) {
                        last_face = turn;
                        break;
                    }
                }
                if (flag) break;
                if (i == l_m) {
                    reverse(current_stack.begin(), current_stack.end());
                    players[last_face].insert(players[last_face].begin(),
                                              current_stack.begin(),
                                              current_stack.end());
                    current_stack.clear();
                    current_stack.push_back(players[last_face].back());
                    turn = last_face;
                    if (!isNotFace(players[last_face].back()))
                        last_face = turn;
                    else
                        last_face = -1;
                    players[turn].erase(--players[turn].end());
                }
            }
            turn = turn ^ 1;
        }
        if (won)
            cout << 1;
        else
            cout << 2;
        cout << setw(3) << players[won].size() << "\n";
    }
    return 0;
}