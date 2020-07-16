#include <iostream>
#include <stdio.h>

using namespace std;
long max_ind = 1000000;

template<class T>
void print(T arr[], int n){
	for(int i=0;i<n;i++)
		cout << arr[i] << " ";
	cout << "\n";
}

template<class T>
void print(T arr){
	for(auto it=arr.begin();it!=arr.end();it++)
		cout << (*it) << " ";
	cout << "\n";
}

long find_max(long a, long b, long arr[]){
	long max_m = arr[a];
	for(long i = a+1;i<=b;i++)
		max_m = max(max_m, arr[i]);
	return max_m;
}

int main() {
	long arr[max_ind+1];
	arr[0] = -1;
	arr[1] = 1;
	for(int i=2;i<=max_ind;i++){
		long temp = i;
		long count = 1;
		while(temp >= i){
			if(temp % 2 == 0)
				temp /=2;
			else
				temp = 3*temp + 1;
			count++;
		}
		count += (arr[temp] - 1);
		arr[i] = count;
	}
	long a, b;
	int n;
	while(scanf("%ld %ld", &a, &b) != -1){
		cout << a << " " << b << " " << find_max(min(a, b), max(a, b), arr) << "\n";
	}
	return 0;
}