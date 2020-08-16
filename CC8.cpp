// Author: Siddhartha Tiwari
// IIIT Vadodara
// penny_khurana

#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <vector>

using namespace std;
typedef long long ll;

int parent(vector<int> &arr, int m) {
    int prev = m, temp;
    while (arr[m] != m) m = arr[m];
    while (arr[prev] != prev) {
        temp = prev;
        prev = arr[prev];
        arr[temp] = m;
    }
    return m;
}

void join_un(int a, int b, vector<int> &arr, vector<int> &rank,
             vector<list<int>> &mp_list) {
    int p1 = parent(arr, a), p2 = parent(arr, b);
    if (p1 == p2) return;
    list<int> temp;
    temp.splice(temp.end(), mp_list[p1]);
    temp.splice(temp.end(), mp_list[p2]);
    if (rank[p1] < rank[p2]) swap(p1, p2);
    arr[p1] = p2;
    mp_list[p2].splice(mp_list[p2].end(), temp);
    if (rank[p1] == rank[p2]) rank[p1]++;
}

void make_set(vector<int> &arr, vector<int> &rank, vector<list<int>> &mp_list,
              int n) {
    arr[n] = n;
    rank[n] = 0;
    mp_list[n] = *(new list<int>(1, n));
}

int main() {
    // ifstream cin("in.txt");
    // ofstream cout("out.txt");
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr(n);
        vector<int> perm(n), dsu(n, -1), rank(n), main_ind;
        vector<ll> popu(n), init(n);
        list<int> empty_list;
        vector<list<int>> mp_list(n, empty_list);
        vector<bool> flag(n, false);
        vector<int> size_m(n), orig(n);
        vector<ll> diff_marr(n, -1);
        vector<pair<int, vector<int>>> diff_arr(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            arr[a - 1].push_back(b - 1);
            arr[b - 1].push_back(a - 1);
        }
        for (int i = 0; i < n; i++) cin >> perm[i];
        for (int i = 0; i < n; i++) cin >> popu[i];
        for (int i = 0; i < n; i++) cin >> init[i];
        for (auto rev = perm.rbegin(); rev != perm.rend(); rev++) {
            int ind_cur = (*rev) - 1;
            auto vec = arr[ind_cur];
            make_set(dsu, rank, mp_list, ind_cur);
            for (auto it : vec) {
                if (dsu[it] == -1) continue;
                join_un(ind_cur, it, dsu, rank, mp_list);
            }
            int v_temp = parent(dsu, ind_cur);
            size_m[ind_cur] = mp_list[v_temp].size();
        }
        for (int i = 0; i < n; i++) {
            int ind = parent(dsu, perm[i] - 1);
            if (!flag[ind]) {
                flag[ind] = true;
                empty_list.splice(empty_list.end(), mp_list[ind]);
            }
        }
        for (auto it : empty_list) main_ind.push_back(it);
        for (int i = 0; i < main_ind.size(); i++) orig[main_ind[i]] = i;
        for (int i = 0; i < n; i++) {
            auto it = perm[i] - 1;
            int ps_or = orig[it], sz_or = size_m[it];
            diff_arr[ps_or].first = i;
            diff_arr[ps_or + sz_or].second.push_back(it);
        }
        vector<pair<ll, int>> temp_v;
        for (int i = 0; i < n; i++) {
            temp_v.erase(temp_v.end() - diff_arr[i].second.size(),
                         temp_v.end());
            ll val = 0;
            if (temp_v.size() != 0) val = temp_v[temp_v.size() - 1].first;
            int tt_in = diff_arr[i].first;
            temp_v.push_back(
                make_pair(val + popu[perm[tt_in] - 1], tt_in));
            auto t_it = lower_bound(temp_v.begin(), temp_v.end(), make_pair(init[main_ind[i]], -1));
            if (t_it == temp_v.end()) {
                diff_marr[main_ind[i]] = -1;
                continue;
            }
            diff_marr[main_ind[i]] = (*t_it).second + 1;
        }
        for (int i = 0; i < n; i++) cout << diff_marr[i] << " ";
        cout << "\n";
    }
    return 0;
}