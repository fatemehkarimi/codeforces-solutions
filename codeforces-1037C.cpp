//https://codeforces.com/problemset/problem/1037/C
//C. Equalize

#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;

	int min_count = 0;
	for(int i = 0; i < n; ++i)
		if(i + 1 < n && a[i] != b[i] && a[i + 1] != b[i + 1] && a[i] == b[i + 1] && a[i + 1] == b[i]){
			min_count++;
			i++;
		}
		else if(a[i] != b[i])
			++min_count;

	cout << min_count << endl;
	return 0;
}
