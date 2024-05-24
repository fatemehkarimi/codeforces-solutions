//DP-CODEFORCES
//https://codeforces.com/problemset/problem/1088/C
//C. Ehab and a 2-operation task

#include <iostream>
#include <vector>

using namespace std;

int find_must_add(int a, int x, int r)
{
    for(int i = 0; i < x; ++i)
        if((a + i) % x == r)
            return i;
}

int main(void)
{
    int n;
    cin >> n;
    vector <int> nums(n);
    for(int i = 0; i < n; ++i)
        cin >> nums[i];

    vector < pair <int, pair <int, int> > > operations;
    for(int i = n - 1; i >= 0; --i){
        int must_add = find_must_add(nums[i], n, i);
        if(must_add == 0)
            continue;
        operations.push_back(make_pair(1, make_pair(i, must_add)));
        for(int j = 0; j <= i; ++j)
            nums[j] += must_add;
    }

    operations.push_back(make_pair(2, make_pair(n - 1, n)));
    cout << operations.size() << endl;
    for(auto a : operations)
        cout << a.first << ' ' << a.second.first + 1 << ' ' << a.second.second << endl;
    return 0;
}
