// https://codeforces.com/problemset/problem/1081/D
// D. Maximum Distance

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct Edge
{
	int u;
	int v;
	int c;

	bool operator < (const Edge & p)const{
		return c < p.c;
	}
	
}Edge;

bool specials[100100];
int unions[100100];
Edge Edges[100100];

int get_parent(int a)
{
	if(a == unions[a])
		return a;
	return unions[a] = get_parent(unions[a]);
}

bool union_groups(int a, int b)
{
	a = get_parent(a);
	b = get_parent(b);
	if(a != b){
		if(specials[a])
			unions[b] = a;
		else
			unions[a] = b;
	if(specials[a] && specials[b])
		return true;
	}
	return false;
}

int main(void)
{
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);

	for(int i = 0; i < k; ++i){
		int x;
		scanf("%d", &x);
		--x;
		specials[x] = true;
	}

	for(int i = 0; i < m; ++i){
		int u, v, c;
		scanf("%d %d %d", &u, &v, &c);
		--u, --v;
		Edges[i].u = u;
		Edges[i].v = v;
		Edges[i].c = c;
	}

	for(int i = 0; i < n; ++i)
		unions[i] = i;

	sort(Edges, Edges + m);
	int counter = 0;
	int result = 0;
	for(int i = 0; i < m; ++i){
		int u = Edges[i].u;
		int v = Edges[i].v;

		counter += union_groups(u, v);
		if(counter == k - 1){
			result = Edges[i].c;
			break;
		}
	}

	for(int i = 0; i < k; ++i)
		printf("%d ", result);
	printf("\n");
	return 0;
}
