//CODEFORCES-MATH
//https://codeforces.com/problemset/problem/515/C
//C. Drazil and Factorial

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
	vector <string> concat(10);
	concat[2] = "2";
	concat[3] = "3";
	concat[4] = "322";
	concat[5] = "5";
	concat[6] = "53";
	concat[7] = "7";
	concat[8] = "7222";
	concat[9] = "7332";

	int n;
	cin >> n;
	string result;
	for(int i = 0; i < n; ++i){
		char c;
		cin >> c;

		if(c != '0' && c != '1')
			result = result + concat[c - '0'];
	}

	sort(result.begin(), result.end(), std::greater <char>());
	cout << result << endl;
	return 0;
}
