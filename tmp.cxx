/*
 * Siddhartha Tiwari
 * Date: 22-08-2020
 */

#include <bits/stdc++.h>
using namespace std;
#define MYCOMP 1
#ifdef MYCOMP
class pscr {
   public:
    pscr() { cerr << "\n"; }
    template <class T,
              typename enable_if<is_fundamental<T>::value, T>::type* = nullptr>
    pscr operator<<(T var) {
        cerr << var;
        return *this;
    }
    template <class T, typename enable_if<!is_fundamental<T>::value &&
                                              !is_pointer<T>::value,
                                          T>::type* = nullptr>
    pscr operator<<(T& var) {
		typedef typename T::value_type temp_type;
		vector<temp_type> temp;
		temp.insert(temp.begin(), var.begin(), var.end());
		auto it = temp.begin();
        for (; it != (--temp.end()); it++)
            *this << *it << string(", ");
		*this << *it;
        return *this;
    }
    template <class T,
              typename enable_if<is_pointer<T>::value, T>::type* = nullptr>
    pscr operator<<(T var) {
        cerr << "Can't print an array. Try something different.\n";
        return *this;
    }
    template <class T1, class T2>
    pscr operator<<(pair<T1, T2> var) {
        *this << "(" << var.first << ", " << var.second
              << ")";
        return *this;
    }
    pscr operator<<(const char str[]) {
		string tstr(str);
		cerr << tstr;
		return *this;
	}
    pscr operator<<(string var) {
        cerr << var;
        return *this;
    }
};
#endif
#define debug(...) "[[" << #__VA_ARGS__ << ": " << __VA_ARGS__ << "]]\t\t"

int main() {
    
    return 0;
}
