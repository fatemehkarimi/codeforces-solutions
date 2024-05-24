//https://codeforces.com/problemset/problem/1221/C
//C. Perfect Team

#include <iostream>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    while(n--){
        int c, m, x;
        cin >> c >> m >> x;
        cout << min(min(c, m), (c + m + x) / 3) << endl;
    }
    return 0;
}
