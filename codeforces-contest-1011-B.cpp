//http://codeforces.com/contest/1011/problem/B

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n = 0, m = 0;
    cin >> n >> m;

    vector <int> package(100, 0);
    int max_possible = m / n;


    for (int i = 0; i < m; ++i){
        int t;
        cin >> t;

        --t;
        ++package[t];
    }

    if (max_possible == 0){
        cout << 0 << endl;
        return 0;
    }

    int day = 0;


    for (int i = 1; i <= max_possible; ++i){
        int people = 0;
        for (int j = 0; j < 100; ++j){
            people += (package[j] / i);
        }

        if (people >= n)
            day = i;

    }


    cout << day << endl;

    return 0;
}
