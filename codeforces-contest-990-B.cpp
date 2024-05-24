//http://codeforces.com/contest/990/problem/B

#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main(void)
{
    int n, k;
    while (cin >> n >> k) {
        map <int, int> bacSize;

        for (int i = 0; i < n; ++i){
            int tmp;
            cin >> tmp;

            auto a = bacSize.find(tmp);

            if (a == bacSize.end())
                bacSize[tmp] = 1;
            else
                ++(a->second);
        }

        int count = 0;

        for (auto a = bacSize.begin(); a != bacSize.end(); ){
            int i = a->first;
            auto j = ++a;

                if (j != bacSize.end() && j->first > i){
                    if (j->first <= i + k)
                        bacSize[i] = 0;                
                }
        }

        for (auto a : bacSize)
            count += a.second;

        cout << count << endl;

    }

    return 0;
}
