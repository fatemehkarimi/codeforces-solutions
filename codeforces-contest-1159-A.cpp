//https://codeforces.com/contest/1159/problem/A
//A. A pile of stones

#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	string input;
	cin >> input;

	int min_count = 0;
	for(int i = 0; i < n; ++i){
		if(input[i] == '-')
			--min_count;
		else
			++min_count;
		if(min_count < 0)
			min_count = 0;
	}

	cout << min_count << endl;
	return 0;
}
