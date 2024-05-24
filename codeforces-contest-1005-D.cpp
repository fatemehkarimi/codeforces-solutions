//http://codeforces.com/contest/1005/problem/D
//Polycarp and Div 3

#include <iostream>
#include <vector>
#include <string>
#include <climits>


using namespace std;

int max(int a, int b);
bool div3(string & str, int i, int j);

int main(void)
{
	string str;
	cin >> str;

	vector <int> arr(str.size() + 1);

	int lastdiv3_index = -1;

	for (int i = 0; i < str.size(); ++i)
		if (str[i] % 3 == 0){
			arr[i + 1] = arr[i] + 1;
			lastdiv3_index = i;
		}
		else if (i - 1 > lastdiv3_index && (str[i] + str[i - 1]) % 3 == 0){
			arr[i + 1] = arr[i - 1] + 1;
			lastdiv3_index = i;
		}
		else if (i - 2 > lastdiv3_index && (str[i] + str[i - 1] + str[i - 2]) % 3 == 0){
			arr[i + 1] = arr[i - 2] + 1;
			lastdiv3_index = i;
		}
		else
			arr[i + 1] = arr[i];

	cout << arr[str.size()] << endl;

	return 0;
}


bool div3(string & str, int i, int j)
{
	int sum = 0;

	for (int x = i; x <= j; ++x)
		sum += (str[x] - '0');

	if (sum % 3 == 0)
		return true;

	return false;
}

int max(int a, int b)
{
	return a > b ? a : b;
}
