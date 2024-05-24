//https://codeforces.com/problemset/problem/1165/C
//C. Good String

#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	string input;
	cin >> input;
	string result;
	int idx = 0;
	int must_removed = 0;
	for(int i = 0; i < n; ++i)
		if(idx % 2 == 0){
			while(i + 1 < n && input[i] == input[i + 1]){
				input[i] = ' ';
				++must_removed, ++i;
			}
			if(i + 1 == n){
				++must_removed;
				input[n - 1] = ' ';
			}
			++i;
			idx += 2;
		}

	cout << must_removed << endl;
	for(auto a : input)
		if(a != ' ')
			cout << a;
	cout << endl;
	return 0;
}
