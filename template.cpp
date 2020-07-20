#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pi;
typedef vector<pi> vii;

template <class InpIter, class T>
InpIter binary_s(InpIter start, InpIter end, T val) {
    InpIter temp = end;
    end--;
    InpIter mid;
    while (start <= end) {
        mid = start + (end - start) / 2;
        if (*mid == val) return mid;
        if (*mid > val) end = mid - 1;
        if (*mid < val) start = mid + 1;
    }
    return temp;
}

template <class InpIter>
void print(InpIter start, InpIter end) {
    while (start != end) {
        cout << *start << " ";
        start++;
    }
    cout << "\n";
}

template <class InpIter>
void scan(InpIter start, InpIter end) {
    while (start != end) {
        cin >> (*start);
        start++;
    }
}

int main() {
	return 0;
}