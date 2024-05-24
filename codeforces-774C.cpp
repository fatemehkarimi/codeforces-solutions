//https://codeforces.com/problemset/problem/774/C
//C. Maximum Number

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    string max_num(n / 2, '1');
    if(n % 2)
        max_num[0] = '7';

    cout << max_num << endl;
    return 0;
}
