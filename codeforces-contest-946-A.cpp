//http://codeforces.com/contest/946/problem/A

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n = 0;
    while (cin >> n) {
        int sum1 = 0;
        int sum2 = 0;

        for (int i = 0; i < n; ++i){
            int tmp;
            cin >> tmp;

            if (tmp < 0)
                sum2 += tmp;
            else
                sum1 += tmp;
        }

        cout << sum1 - sum2 << endl;
    }
    return 0;
}
