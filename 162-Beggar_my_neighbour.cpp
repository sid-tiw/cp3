#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isNotFace(string str) {
  char ch = str.at(1);
  if (ch == 'K' || ch == 'Q' || ch == 'J' || ch == 'A') return false;
  return true;
}

int main() {
  while (true) {  // a single deck of a card in one loop
    vector<string> players[2], current_stack;
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
    int turn = 0, last_face = -1;
    while (true) {
      int len = current_stack.size();
      int p_len = current_stack.size();
      if (p_len == 0) break;
      if (last_face == -1) {
        if (current_stack.size() == 0 || isNotFace(current_stack[len - 1])) {
          current_stack.push_back(players[turn][p_len - 1]);
          last_face = isNotFace(players[turn][p_len - 1]) ? -1 : turn;
          players[turn].erase(players[turn].end() - 1);
        }
      }
      turn = turn ^ 1;
    }
  }
  return 0;
}