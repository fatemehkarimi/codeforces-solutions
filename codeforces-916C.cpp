//https://codeforces.com/problemset/problem/916/C
//C. Jamie and Interesting Graph

#include <iostream>
#include <vector>
#include <cmath>
#include <map>

#define lld long long int

using namespace std;

bool is_prime(lld num)
{
	lld limit = sqrt(num) + 1;
	if(num == 2)
		return true;
	if(num % 2 == 0)
		return false;
	for(lld i = 3; i <= limit; i += 2)
		if(num % i == 0)
			return false;
	return true;
}

lld find_next_prime_number(lld limit)
{
	for(lld i = limit;; ++i)
		if(is_prime(i))
			return i;
}

int main(void)
{
	int n, m;
	cin >> n >> m;
	vector < map <int, int> > Graph(n);
	Graph[0][n - 1] = 2;
	Graph[n - 1][0] = 2;
	lld mst_weight = 2;
	--m;
	for(int i = 1; i < n - 2; ++i){
		Graph[0][i] = 2;
		Graph[i][0] = 2;
		mst_weight += 2;
		--m;
	}

	if(n > 2){
		lld weight = find_next_prime_number(mst_weight + 2);
		Graph[0][n - 2] = (weight - mst_weight);
		Graph[n - 2][0] = (weight - mst_weight);
		mst_weight = weight;
		--m;
	}

	for(int i = 1; i < n && m > 0; ++i)
		for(int j = i + 1; j < n && m > 0; ++j){
			Graph[i][j] = 100000;
			Graph[j][i] = 100000;
			--m;
		}

	cout << 2 << ' ' << mst_weight << endl;
	for(int i = 0; i < n; ++i)
		for(auto a : Graph[i])
			if(i < a.first)
				cout << i + 1 << " " << a.first + 1 << ' ' << a.second << endl;
	return 0;
}
