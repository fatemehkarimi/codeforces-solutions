//https://codeforces.com/contest/1215/problem/A
//A. Yellow Cards

#include <iostream>

using namespace std;

int main(void)
{
    int a1, a2, k1, k2, n;
    cin >> a1 >> a2 >> k1 >> k2 >> n;

    int min_possible = min(max(0, n - ((k1 - 1) * a1 + (k2 - 1) * a2)), a1 + a2);
    int max_possible = 0;

    if(k1 < k2){
        max_possible = min(n / k1, a1);
        n -= (max_possible * k1);
        max_possible += min(n / k2, a2);
    }
    else{
        max_possible = min(n / k2, a2);
        n -= (max_possible * k2);
        max_possible += min(n / k1, a1);
    }

    cout << min_possible << ' ' << max_possible << endl;
    return 0;
}
