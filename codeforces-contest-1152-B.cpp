//https://codeforces.com/contest/1152/problem/B
//B. Neko Performs Cat Furrier Transform

#include <iostream>
#include <vector>
using namespace std;

bool check_valid(int num);
pair <int, int> find_mask(int num);

int main(void)
{
	int num;
	cin >> num;

	int step = 0;
	vector <int> result;
	if(num % 2 == 0){//step 1: num ^ 0,
		result.push_back(0);
		++step;
	}

	while(step <= 40){
		if(check_valid(num))
			break;

		if(step % 2)
			++num;
		else{
			pair <int, int> mask = find_mask(num);
			num = num ^ mask.first;
			result.push_back(mask.second);
		}
		++step;
	}

	cout << step << endl;
	for(auto a : result)
		cout << a << ' ';
	cout << endl;

	return 0;
}

bool check_valid(int num)
{
	int mask = 1;
	while(mask <= num){
		if(mask == num)
			return true;
		mask <<= 1;
		++mask;
	}
	return false;
}

pair <int, int> find_mask(int num)
{
	unsigned int value = 1 << 31;
	bool first_zero = false;
	while(true){
		if(value & num)
			first_zero = true;
		else if(first_zero && !(value & num)) {
			int final_result = 0;
			int _pow = 0;
			while(value != 0){
				++_pow;
				final_result += value;
				value >>= 1;
			}
			return make_pair(final_result, _pow);
		}
		value >>= 1;
	}
	return make_pair(-1, -1);//returning this value indicates error
}
