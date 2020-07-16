#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
	int m, n;
	cin >> m >> n;
	int case_no = 1;
	while(m != 0 && n != 0){
    if(case_no != 1)
      cout << "\n";
		char pos[m][n];
		int pos_val[m][n];
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++){
				cin >> pos[i][j];
				pos_val[i][j] = 0;
			}
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++){
				if(pos[i][j] != '*')
					continue;
				for(int p=0;p<3;p++)
					for(int q=0;q<3;q++){
						if(p+i < 1 || p+i > m || q+j < 1 || q+j > n)
							continue;
						pos_val[p+i-1][q+j-1]++;
					}
			}
		cout << "Field #" << case_no << ":\n";
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(pos[i][j] == '*')
					cout << "*";
				else
					cout << pos_val[i][j];
			}
			cout <<"\n";
		}
		cin >> m >> n;
		case_no++;
	}
}