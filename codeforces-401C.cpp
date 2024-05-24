//https://codeforces.com/problemset/problem/401/C
//C. Team

#include <iostream>
#include <list>

using namespace std;

int main(void)
{
	int zeros, ones;
	cin >> zeros >> ones;
	list <bool> result;

	while(zeros > 0 && ones > 0){
		for(int i = 0; i < 2 && ones > 0; ++i){
			result.push_back(1);
			--ones;
		}
		result.push_back(0);
		--zeros;
	}

	for(int i = 0; i < 2 && ones > 0; ++i){
		result.push_back(1);
		--ones;
	}

	if(ones != 0)
		return cout << -1 << endl, 0;

	if(zeros > 0){
		result.push_front(0);
		--zeros;
	}

	auto a = result.begin();
	while(zeros > 0){
		while(a != result.end())
			if(*a == 1){
				++a;
				if(a != result.end() && *a == 1)
					break;
			}
			else
				++a;

		if(a == result.end())
			break;

		result.insert(a, 0);
		--zeros;
	}

	if(zeros != 0)
		return cout << -1 << endl, 0;

	for(auto a : result)
		cout << a;
	cout << endl;
	return 0;
}
