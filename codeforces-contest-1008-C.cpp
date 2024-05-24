//http://codeforces.com/contest/1008/problem/C
//Reorder the Array

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main(void)
{
    int n = 0;
    cin >> n;

    vector <int> num(n);

    for (int i = 0; i < n; ++i){
        int t;
        cin >> t;

        num[i] = t;
    }

    sort(num.begin(), num.end());

    int countResult = 0;

    int i = 0, j = 0;
    for (; i < n && j < n; ++i){
        while (j < n)
            if (num[i] >= num[j])
                ++j;
            else{
                ++countResult;
                ++j;
                break;
            }
    }

    cout << countResult << endl;

    return 0;
}
