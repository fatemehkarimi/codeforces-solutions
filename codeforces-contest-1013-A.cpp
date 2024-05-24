//http://codeforces.com/contest/1013/problem/A

#include <iostream>


using namespace std;

int main(void)
{
    int n = 0;
    cin >> n;

    int sum1 = 0, sum2 = 0;

    for (int i = 0; i < n; ++i){
        int t;
        cin >> t;

        sum1 += t;
    }
    for (int i = 0; i < n; ++i){
        int t;
        cin >> t;

        sum2 += t;
    }


    if (sum2 <= sum1)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
