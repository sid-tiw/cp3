#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <class T, class POW>
T binary_exp_rec(T a, POW b) {
    T ans, ml = 1;
    if (!b) return 1;
    if (b % 2 == 0) ans = binary_exp_rec(a, b / 2);
    if (b % 2 != 0) {
        ans = binary_exp_rec(a, (b - 1) / 2);
        ml = a;
    }
    return ans * ans * ml;
}

template <class T, class POW>
T binary_exp_iter(T a, POW b) {
    T res = 1;
    while (b > 0) {
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

template <class T>
class Matrix {
    vector<vector<T>> obj;

   public:
    Matrix(int rows, int cols) { obj = vector<vector<T>>(rows, vector<T>(cols)); }
    Matrix(int rows, int cols, T val) {
        obj = vector<vector<T>>(rows, vector<T>(cols, val));
    }
    vector<T> operator[](int val) {
        return obj[val];
    }
};

int main() {
	Matrix<int> A(4, 5, -1);
    cout << binary_exp_iter(3, 5);
    return 0;
}