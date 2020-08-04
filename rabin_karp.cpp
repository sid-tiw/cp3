#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;

ll lucas_19 = 32361122672259149LL;

vector<int> rabin_karp(string s, string t, ll prime) {
    vector<ll> constants(t.size()), hashes(s.size() - t.size() + 1, 0);
    ll to_search_hash = 0;
    constants[0] = 13;
    for (int i = 1; i < t.size(); i++) {
        constants[i] = constants[i - 1] * constants[0];
        constants[i] %= prime;
    }
    for (int i = 0; i < t.size(); i++) {
        hashes[0] += (constants[t.size() - i - 1] * s[i]);
        to_search_hash += (constants[t.size() - i - 1] * t[i]);
        hashes[0] %= prime;
        to_search_hash %= prime;
    }
    for (int i = 1; i < hashes.size(); i++) {
        hashes[i] =
            constants[0] *
                (hashes[i - 1] - constants[constants.size() - 1] * s[i - 1]) +
            s[i + t.size() - 1] * constants[0];
        hashes[i] %= prime;
    }
    vector<int> indices_search;
    for (int i = 0; i < hashes.size(); i++)
        if (hashes[i] == to_search_hash) indices_search.push_back(i);
    return indices_search;
}

int main() {
    string s, t;
    cin >> s >> t;
    if (t.size() > s.size()) {
        // Not possible to search for the given substring.
        cout << "You are a failure!!!\n";
        return 0;
    }
    vector<int> indices_search = rabin_karp(s, t, lucas_19);
    if (!indices_search.size()) {
        cout << "Naat found!!\n";
        return 0;
    }
    cout << "Found at these indices: ";
    for (auto it : indices_search) cout << it << " ";
    cout << "\n";
    return 0;
}