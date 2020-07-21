#include <iostream>
#include <set>
#include <string>
#include <map>
#include <fstream>
#include <iomanip>

using namespace std;

void print_pair(set<pair<string, string>> som, ostream& fout) {
	for(auto it : som)
		fout << it.first << " " << it.second << "\n";
	fout << "\n";
	return;
}

int main() {
	fstream fin("inp.txt", fstream::in);
	ofstream fout("out.txt");
	char tstr[100000];
	set<pair<string, string>> titles, borrowed, returned;
	map<string, string> ass;
	while(true) {
		fin.getline(tstr, 100000);
		string str(tstr);
		if(str == "END")
			break;
		str.erase(0, 1);
		cout << str << "\n";
		size_t fnd = str.find("\"");
		string s1 = str.substr(0, fnd);
		string s2 = str.substr(fnd+5);
		ass[s1] = s2;
		titles.insert(make_pair(s2, s1));
		print_pair(titles, fout);
	}
	fout << "Here\n";
	fout.close();
	while(true) {
		fin.getline(tstr, 10000);
		string str(tstr);
		if(str == "END")
			break;
		size_t fnd = str.find(" ");
		if(fnd != string::npos) {
			string frst = str.substr(0, fnd), scnd = str.substr(fnd+1);
			scnd.erase(0, 1);
			scnd.erase(scnd.size()-1, 1);
			if(frst == "BORROW") {
				titles.erase(titles.find(make_pair(scnd, ass[scnd])));
				borrowed.insert(make_pair(scnd, ass[scnd]));
			}
			else
				returned.insert(make_pair(scnd, ass[scnd]));
		}
		else {
			for(auto it : returned) {
				titles.insert(it);
				auto tt = titles.find(it);
				if(tt == titles.begin())
					fout << "Put \"" << it.first << "\" first\n";
				else
					fout << "Put \"" << it.first << "\" after \"" << (*(--tt)).first << "\"\n";
			}
		}
	}
	return 0;
}
