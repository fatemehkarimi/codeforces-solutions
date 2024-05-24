//https://codeforces.com/problemset/problem/1107/C
//C. Brutality

#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main(void)
{
	int n, k;
	cin >> n >> k;
	vector <long long int> values(n);

	for(int i = 0; i < n; ++i)
		cin >> values[i];

	string input;
	cin >> input;

	long long int damage = 0;
	for(int i = 0; i < n; ++i){
		multiset <int> consecutive;
		int j = i;
		while(j < n && input[i] == input[j])
			consecutive.insert(values[j++]);

		int kk = k;
		for(auto a = consecutive.rbegin(); a != consecutive.rend() && kk > 0; ++a, --kk)
			damage += *a;
		i = j - 1;
	}
	cout << damage << endl;
	return 0;
}
