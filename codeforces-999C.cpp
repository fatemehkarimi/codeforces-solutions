//https://codeforces.com/problemset/problem/999/C
//Alphabetic Removals

#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main(void)
{
	int n, k;
	cin >> n >> k;

	set <pair <char, int> > alphabet;
	string result(n, ' ');

	for(int i = 0; i < n; ++i){
		char tmp;
		cin >> tmp;
		alphabet.insert(make_pair(tmp, i));
	}

	auto a = alphabet.begin();
	for(int i = 0; i < k; ++i)
		++a;

	for(; a != alphabet.end(); ++a)
		result[a->second] = a->first;

	for(auto a : result)
		if(a != ' ')
			cout << a;

	cout << endl;

	return 0;
}
