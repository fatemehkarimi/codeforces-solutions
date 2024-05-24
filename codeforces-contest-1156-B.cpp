//https://codeforces.com/contest/1156/problem/B
//B. Ugly Pairs

#include <iostream>
#include <algorithm>
#include <string>
#include <list>

using namespace std;

int main(void)
{
	int T = 0;
	cin >> T;
	while(T--){
		string input;
		cin >> input;
		sort(input.begin(), input.end());
		string result;
		result = result + input[0];
		input[0] = ' ';
		bool no_result = 0;

		while(result.size() != input.size()){
			bool no_answer = 1;
			for(int i = 0; i < (int)input.size(); ++i)
				if(input[i] != ' '){
					if(abs(input[i] - result[0]) != 1){
						result = input[i] + result;
						input[i] = ' ';
						no_answer = 0;
						continue;
					}

					if(abs(input[i] - result[result.size() - 1]) != 1){
						result = result + input[i];
						input[i] = ' ';
						no_answer = 0;
						continue;
					}

					for(int j = 1; j < (int)result.size() - 1; ++j)
						if(abs(result[j] - input[i]) != 1 && abs(result[j + 1] - input[i]) != 1){
							string tmp_result;
							for(int k = 0; k <= j; ++k)
								tmp_result = tmp_result + result[k];
							tmp_result = tmp_result + input[i];
							for(int k = j + 1; k < (int)result.size(); ++k)
								tmp_result = tmp_result + result[k];

							result = tmp_result;
							input[i] = ' ';
							no_answer = 0;
							break;
						}
				}
			if(no_answer){
				no_result = 1;
				break;
			}
		}

		if(no_result)
			cout << "No answer" << endl;
		else
			cout << result << endl;
	}
	return 0;
}
