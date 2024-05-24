//https://codeforces.com/problemset/problem/870/C
//C. Maximum splitting

#include <iostream>

using namespace std;

int main(void)
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        if(n % 4 == 0)
            cout << n / 4 << endl;
        else if(n % 4 == 1 && n >= 9)
            cout << (n - 9) / 4 + 1 << endl;
        else if(n % 4 == 2 && n >= 6)
            cout << (n - 6) / 4 + 1 << endl;
        else if(n % 4 == 3 && n >= 15)
            cout << (n - 15) / 4 + 2 << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}

