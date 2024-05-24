//https://codeforces.com/problemset/problem/417/C

#include <cstdio>

int main(void)
{
	int n, k;
	scanf("%d %d", &n, &k);
	if(n < 2 * k + 1){
		printf("-1\n");
		return 0;
	}
	printf("%d\n", n * k);
	for(int i = 0; i < n; ++i)
		for(int j = 1; j <= k; ++j)
			printf("%d %d\n", i + 1, (i + j) % n + 1);

	return 0;
}
