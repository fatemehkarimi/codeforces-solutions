//https://codeforces.com/problemset/problem/612/C
//C. Replace To Make Regular Bracket Sequence

#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool open_char(char c)
{
	if(c == '{' || c == '[' || c == '<' || c == '(')
		return true;
	return false;
}

int main(void)
{
	string input;
	cin >> input;

	stack <char> Stack;
	int count_convert = 0;
	bool impossible = false;

	for(int i = 0; i < (int)input.size(); ++i)
		if(open_char(input[i]))
			Stack.push(input[i]);
		else{
			if(Stack.empty()){
				impossible = true;
				break;
			}

			if(input[i] == '>' && Stack.top() != '<')
				++count_convert;
			else if(input[i] == ')' && Stack.top() != '(')
				++count_convert;
			else if(input[i] == '}' && Stack.top() != '{')
				++count_convert;
			else if(input[i] == ']' && Stack.top() != '[')
				++count_convert;
			Stack.pop();
		}

	if(!Stack.empty())
		impossible = true;

	if(impossible)
		cout << "Impossible" << endl;
	else
		cout << count_convert << endl;
	return 0;
}
