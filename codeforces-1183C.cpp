//https://codeforces.com/problemset/problem/1183/C
//C. Computer Game

#include <iostream>
#include <cmath>
#define lld long long int
using namespace std;

void binary_search(lld k, lld n, lld n_l, lld n_r, lld a, lld b, lld & curr_result)
{
    if(n_l >= n_r)
        return;

    lld middle = n_l + (n_r - n_l) / 2;
    lld value = middle * a + b * (n - middle);

    if(value < k){
        if(value > curr_result)
            curr_result = middle;
        binary_search(k, n, middle + 1, n_r, a, b, curr_result);
    }
    else
        binary_search(k, n, n_l, middle, a, b, curr_result);
}

int main(void)
{
    int T = 0;
    cin >> T;
    while(T--){
        lld k, n, a, b;
        cin >> k >> n >> a >> b;
        lld answer = -1;
        binary_search(k, n, 0, n + 1, a, b, answer);
        cout << answer << endl;
    }
    return 0;
}

