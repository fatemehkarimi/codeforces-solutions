//https://codeforces.com/problemset/problem/1038/C
//C. Gambling

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector <long long int> A(n);
	vector <long long int> B(n);

	for(int i = 0; i < n; ++i)
		cin >> A[i];
	for(int i = 0; i < n; ++i)
		cin >> B[i];

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	long long int score_a = 0, score_b = 0;
	int idx_a = n - 1, idx_b = n - 1;
	bool turn_a = true;

	while(idx_a >= 0 || idx_b >= 0){
		if(turn_a){
			if(idx_a >= 0 && idx_b >= 0){
				if(B[idx_b] > A[idx_a])
					--idx_b;
				else
					score_a += A[idx_a], --idx_a;
			}
			else if(idx_a >= 0)
				score_a += A[idx_a], --idx_a;
			else
				--idx_b;
		}
		else{
			if(idx_a >= 0 && idx_b >= 0){
				if(A[idx_a] > B[idx_b])
					--idx_a;
				else
					score_b += B[idx_b], --idx_b;
			}
			else if(idx_b >= 0)
				score_b += B[idx_b], --idx_b;
			else
				--idx_a;
		}
		turn_a = !turn_a;
	}
	cout << score_a - score_b << endl;
	return 0;
}
