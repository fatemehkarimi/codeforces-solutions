//https://codeforces.com/problemset/problem/858/C

#include <iostream>
#include <string>

using namespace std;

bool isvowel(char a);

int main(void)
{
	string input;
	cin >> input;

	int i = 0;
	for(; i < (int)input.size() - 2; ++i)
		if(isvowel(input[i]))
			cout << input[i];
		else if (!isvowel(input[i]) && !isvowel(input[i + 1]) && !isvowel(input[i + 2])){
			if(input[i] == input[i + 1] && input[i] == input[i + 2]){
				int j = i;
				while(j < input.size() && input[i] == input[j])
					cout << input[j++];

				if(!isvowel(input[j]))
					cout << ' ';
				
				i = j - 1;
			}
			else{
				cout << input[i] << input[i + 1] << ' ';
				i += 1;
			}
		}
		else
			cout << input[i];

	while(i < input.size())
		cout << input[i++];

	cout << endl;
	return 0;
}

bool isvowel(char a)
{
	if(a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
		return true;
	return false;
}
