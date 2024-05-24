//https://codeforces.com/problemset/problem/1023/C
//C. Bracket Subsequence

#include <iostream>
#include <climits>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int main(void)
{
	int n, k;
	cin >> n >> k;

	string input;
	cin >> input;

	stack <int> Stack;
	vector <int> pairs(input.size(), INT_MAX);
	vector <bool> to_be(input.size(), false);

	for(int i = 0; i < input.size(); ++i){
		if(input[i] == '(')
			Stack.push(i);
		else if(input[i] == ')' && !Stack.empty()){
			int top = Stack.top();
			Stack.pop();
			pairs[top] = top;
			pairs[i] = top;
		}
	}
	
	for(int i = 0; i < input.size(); ++i)
		if(k / 2 > 0 && pairs[i] != INT_MAX && input[i] == '('){
			to_be[i] = true;
			k -= 2;
		}
		else if(pairs[i] != INT_MAX && input[i] == ')' && to_be[pairs[i]])
			to_be[i] = true;


	for(int i = 0; i < input.size(); ++i)
		if(to_be[i])
			cout << input[i];

	cout << endl;

	return 0;
}
