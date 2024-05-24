//https://codeforces.com/problemset/problem/492/C
//C. Vanya and Exams

#include <iostream>
#include <set>
#define lld long long int

using namespace std;

int main(void)
{
	lld n, r, avg;
	cin >> n >> r >> avg;
	multiset <pair <lld, lld> > exams;

	lld sum = 0;
	for(int i = 0; i < n; ++i){
		lld a, b;
		cin >> a >> b;
		exams.insert(make_pair(b, a));
		sum += a;
	}

	lld assay = 0;
	while(sum < avg * n){
		auto x = exams.begin();
		if(x->second >= r){
			exams.erase(x);
			continue;
		}
		lld must_add = min(avg * n - sum, r - x->second);
		assay += (x->first * must_add);
		sum += must_add;
		exams.erase(x);
	}
	cout << assay << endl;
	return 0;
}
