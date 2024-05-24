// https://codeforces.com/contest/1332/problem/D
// D. Walk on Matrix

#include <iostream>

using namespace std;

unsigned int find_min_power(unsigned int k)
{
    unsigned int x = 1;
    while(x <= k)
        x *= 2;
    return x;
}

int main(void)
{
    unsigned int k;
    cin >> k;
    if(k == 0){
        cout << 1 << ' ' << 1 << endl;
        cout << k << endl;
        return 0;
    }

    unsigned int p = find_min_power(k);
    unsigned int greatest = (1 << 18) - 1;
    unsigned int result[3][2] = {{greatest, p}, {k, greatest}, {0, k}};

    cout << 3 << ' ' << 2 << endl;
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 2; ++j)
            cout << result[i][j] << ' ';
        cout << endl;
    }
    return 0;
}
