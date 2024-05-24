//http://codeforces.com/problemset/problem/899/A
//A. Splitting in Teams

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n = 0;
    cin >> n; 

    int one = 0, two = 0;
    for (int i = 0; i < n; ++i){
        int t;
        cin >> t;

        if (t == 1)
            ++one;
        else
            ++two;
    }

    int groups = min(one, two);
    one -= groups;

    if (one > 0)
        groups += (one / 3);

    cout << groups << endl;

    return 0;
}
