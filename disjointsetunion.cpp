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

void union_sets(map<int, int> &arr, map<int, int> &rank, int a, int b) {
    a = find_set(arr, a);
    b = find_set(arr, b);
    if (a != b) {
        if (rank[a] < rank[b]) swap(a, b);
        arr[b] = a;
        if (rank[a] == rank[b]) rank[a]++;
    }
}

void make_set(map<int, int> &arr, map<int, int> &rank, int a) {
    arr[a] = -1;
    rank[a] = 0;
}

int main() {
    ofstream out("out.txt");
    ifstream inp("inp.txt");
    int n;
    inp >> n;
    map<int, int> arr, rank;
    for (int i = 0; i < n; i++) {
        int a;
        inp >> a;
        make_set(arr, rank, a);
    }
    return 0;
}