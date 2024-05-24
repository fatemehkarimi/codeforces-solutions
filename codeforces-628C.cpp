//https://codeforces.com/problemset/problem/628/C
//C. Bear and String Distance

#include <cstdio>
#include <iostream>
using namespace std;

int main(void)
{
	int n, k;
	scanf("%d %d", &n, &k);

	char str[100000];
	scanf("%s", str);

	char result[100000];

	for(int i = 0; i < n; ++i){
		int d1 = abs('a' - str[i]);
		int d2 = abs('z' - str[i]);
		char c;

		if(d1 > d2)
			c = 'a';
		else
			c = 'z';

		if(k >= max(d1, d2)){
			result[i] = c;
			k -= max(d1, d2);
		}
		else{
			if(str[i] + k <= 'z')
				result[i] = str[i] + k;
			else
				result[i] = str[i] - k;
			k = 0;
		}
	}

	if(k > 0)
		return printf("-1\n"), 0;

	for(int i = 0; i < n; ++i)
		printf("%c", result[i]);
	printf("\n");
	return 0;
}
