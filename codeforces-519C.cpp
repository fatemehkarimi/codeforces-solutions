//https://codeforces.com/problemset/problem/519/C
//C. A and B and Team Training

#include <iostream>

using namespace std;

int main(void)
{
    int n, m;
    cin >> n >> m;

    int half_complete = min(n, m);
    n -= half_complete;
    m -= half_complete;

    int full_complete = 0;
    int left = max(n, m);
    full_complete = min(half_complete, left);

    half_complete = (left > half_complete ? 0 : half_complete - left);

    while(half_complete > 0){
        --half_complete;

        if(half_complete == 0)
            break;

        int new_group = min(2, half_complete);
        full_complete += new_group;
        half_complete -= new_group;
    }

    cout << full_complete << endl;
    return 0;
}
