//http://codeforces.com/contest/1011/problem/C

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main(void)
{
    int n = 0, m;
    cin >> n >> m;

    vector <int> take_off(n);
    vector <int> land(n);

    for (int i = 0; i < n; ++i)
        cin >> take_off[i];

    for (int i = 0; i < n; ++i)
        cin >> land[i];

    bool possible = 1;

    double mass = m;
    if (land[0] - 1 > 0)
        mass += (double)m / (land[0] - 1);

    for (int i = n - 1; i >= 1 && possible; --i){
        if (land[i] - 1 > 0 && take_off[i] - 1 > 0){
            mass += ((double)mass / (land[i] - 1));
            mass += ((double)mass / (take_off[i] - 1));

        }
        else
            possible = 0;

        if (mass - m > 1000000000)
            possible = 0;

    }



    if (take_off[0] - 1 > 0 && possible)
        mass += (mass /(take_off[0] - 1));
    else
        possible = 0;

    if (possible)
        cout << fixed << setprecision(10) << mass - m << endl;
    else
        cout << "-1" << endl;

    return 0;
}
