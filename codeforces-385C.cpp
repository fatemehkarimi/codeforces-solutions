//https://codeforces.com/problemset/problem/385/C
//C. Bear and Prime Numbers

#include <cstdio>
#include <iostream>

using namespace std;

#define SIZE 10000002

int count_num[SIZE] = {};
int f_values[SIZE] = {};
bool is_prime[SIZE];

int main(void)
{
    for(int i = 0; i < SIZE; ++i)
        is_prime[i] = true;
    is_prime[1] = false;

    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        int x;
        scanf("%d", &x);
        ++count_num[x];
    }

    for(int i = 2; i < SIZE; ++i)
        if(is_prime[i]){
            f_values[i] += count_num[i];
            f_values[i] += f_values[i - 1];

            for(int j = 2 * i; j < SIZE; j += i){
                is_prime[j] = false;
                f_values[i] += count_num[j];
            }
        }
        else
            f_values[i] = f_values[i - 1];

    int Q;
    scanf("%d", &Q);
    while(Q--){
        int left, right;
        scanf("%d %d", &left, &right);
        left = min(left - 1, SIZE - 1);
        right = min(right, SIZE - 1);
        printf("%d\n", f_values[right] - f_values[left]);
    }
    return 0;
}
