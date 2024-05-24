// https://codeforces.com/contest/1333/problem/B
// B. Kind Anton

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		vector <int> arrA(n);
		vector <int> arrB(n);

		for(int i = 0; i < n; ++i)
			cin >> arrA[i];

		for(int i = 0; i < n; ++i)
			cin >> arrB[i];

		bool possible = true;

		for(int i = n - 1; i >= 0; --i)
			if(arrA[i] == arrB[i])
				continue;
			else if(arrA[i] < arrB[i]){
				bool found = false;
				for(int j = i - 1; j >= 0; --j)
					if(arrA[j] == 1){
						found = true;
						break;
					}

				if(!found){
					possible = false;
					break;
				}
			}
			else{
				bool found = false;
				for(int j = i - 1; j >= 0; --j)
					if(arrA[j] == -1){
						found = true;
						break;
					}

				if(!found){
					possible = false;
					break;
				}
			}

		if(possible)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
