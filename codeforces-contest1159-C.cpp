//https://codeforces.com/contest/1159/problem/C
//C. The Party and Sweets

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;

	vector <int> boys(n);
	vector <int> girls(m);

	for(int i = 0; i < n; ++i)
		cin >> boys[i];
	for(int i = 0; i < m; ++i)
		cin >> girls[i];

	sort(boys.begin(), boys.end());
	sort(girls.begin(), girls.end());

	if(boys[n - 1] > girls[0]){
		cout << -1 << endl;
		return 0;
	}

	bool first_person_ok = false;
	long long int minCandy = 0;
	minCandy += boys[n - 1];//give it to first person
	if(boys[n - 1] == girls[0])
		first_person_ok = 1;

	for(int j = 1; j < m; ++j)
		minCandy += girls[j];

	for(int i = n - 2; i >= 0; --i)
		if(boys[i] <= girls[0] && !first_person_ok){
			minCandy += (girls[0] + (m - 1) * boys[i]);
			first_person_ok = true;
		}
		else if(first_person_ok)
			minCandy += (m * boys[i]);


	if(first_person_ok)
		cout << minCandy << endl;
	else
		cout << -1 << endl;

	return 0;
}
