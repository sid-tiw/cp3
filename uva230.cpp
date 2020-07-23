/*
 * Siddhartha Tiwari
 * Date: 22-08-2020
 */

#include <bits/stdc++.h>
using namespace std;
// #define MYCOMP 1
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
	fstream fin("inp.txt", fstream::in);
	ofstream fout("out.txt");
	char tstr[100000];
	set<pair<string, string>> titles, borrowed, returned;
	map<string, string> ass;
	while(true) {
		cin.getline(tstr, 100000);
		string str(tstr);
		if(str == "END")
			break;
		str.erase(0, 1);
		size_t fnd = str.find("\"");
		string s1 = str.substr(0, fnd);
		string s2 = str.substr(fnd+5);
		ass[s1] = s2;
		titles.insert(make_pair(s2, s1));
	}
	while(true) {
		cin.getline(tstr, 10000);
		string str(tstr);
		if(str == "END")
			break;
		size_t fnd = str.find(" ");
		if(fnd != string::npos) {
			string frst = str.substr(0, fnd), scnd = str.substr(fnd+1);
			scnd.erase(0, 1);
			scnd.erase(scnd.size()-1, 1);
			if(frst == "BORROW") {
				titles.erase(titles.find(make_pair(ass[scnd], scnd)));
				borrowed.insert(make_pair(scnd, ass[scnd]));
			}
			else
				returned.insert(make_pair(ass[scnd], scnd));
		}
		else {
			for(auto it : returned) {
				titles.insert(it);
				auto tt = titles.find(it);
				if(tt == titles.begin())
					cout << "Put \"" << it.second << "\" first\n";
				else
					cout << "Put \"" << it.second << "\" after \"" << (*(--tt)).second << "\"\n";
			}
			cout << "END\n";
			returned.clear();
		}
	}
	return 0;
}
