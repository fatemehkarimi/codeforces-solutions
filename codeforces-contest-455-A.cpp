//http://codeforces.com/contest/455/problem/A
//A. Boredom

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(void)
{
	int n = 0;
	cin >> n;
	map <long long int, long long int> num;

	for(int i = 0; i < n; ++i){
		int tmp;
		cin >> tmp;

		++num[tmp];
	}

	vector <long long int> maxPoint(num.size(), 0);
	auto a = num.begin();
	maxPoint[0] = a->first * a->second;
	long long int prev = a->first;
	++a;

	int index = 1;
	for (; a != num.end(); ++a){
		maxPoint[index] = a->first * a->second;

		if (prev + 1 == a->first && index >= 2)
			maxPoint[index] += maxPoint[index - 2];
		else if (a->first - prev > 1)
			maxPoint[index] += maxPoint[index - 1];

		maxPoint[index] = max(maxPoint[index], maxPoint[index - 1]);

		++index;
		prev = a->first;
	}

	cout << maxPoint[index - 1] << endl;
 	return 0;
}
