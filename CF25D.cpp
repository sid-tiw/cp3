#include <algorithm>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <vector>

using namespace std;

int find_set(map<int, int> &arr, int a) {
    vector<int> temp;
    while (arr[a] != -1) {
        temp.push_back(a);
        a = arr[a];
    }
    for (auto it : temp) arr[it] = a;
    return a;
}

void union_sets(map<int, int> &arr, map<int, int> &rank, int a, int b,
                vector<pair<int, int>> &rep) {
    int x = a, y = b;
    a = find_set(arr, a);
    b = find_set(arr, b);
    if (a != b) {
        if (rank[a] < rank[b]) swap(a, b);
        arr[b] = a;
        if (rank[a] == rank[b]) rank[a]++;
    } else
        rep.push_back(make_pair(x, y));
}

void make_set(map<int, int> &arr, map<int, int> &rank, int a) {
    arr[a] = -1;
    rank[a] = 0;
}

int main() {
    ofstream out("out.txt");
    ifstream inp("inp.txt");
    int n;
    cin >> n;
    map<int, int> arr, rank;
    vector<pair<int, int>> rep;
    vector<int> anot;
    for (int i = 1; i <= n; i++) make_set(arr, rank, i);
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        union_sets(arr, rank, a, b, rep);
    }
    for (int i = 1; i <= n; i++)
        if (arr[i] == -1) anot.push_back(i);
    cout << rep.size() << "\n";
    for (int i = 0; i < rep.size(); i++)
        cout << rep[i].first << " " << rep[i].second << " " << anot[i] << " "
             << anot[i + 1] << "\n";
    return 0;
}