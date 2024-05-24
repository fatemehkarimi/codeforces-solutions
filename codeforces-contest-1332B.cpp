// https://codeforces.com/contest/1332/problem/B
// B. Composite Coloring

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(void)
{
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		vector <int> numbers(n);
		vector <int> colors(n, 0);

		for(int i = 0; i < n; ++i)
			cin >> numbers[i];

		int m = 0;
		for(int i = 2; i < sqrt(1000) + 1; ++i){
			int curr_color = -1;
			for(int j = 0; j < n; ++j)
				if(colors[j] == 0 && numbers[j] % i == 0){
					if(curr_color == -1)
						curr_color = ++m;
					colors[j] = curr_color;
				}
		}

		//primes left
		for(auto & a : colors)
			if(a == 0)
				a = ++m;
			
		cout << m << endl;
		for(auto a : colors)
			cout << a << ' ';
		cout << endl;
	}
	return 0;
}
