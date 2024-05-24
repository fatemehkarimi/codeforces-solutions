//https://codeforces.com/problemset/problem/581/C
//C. Developing Skills

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int find_upper(int x)
{
    int ten = x / 10 + 1;
    return ten * 10;
}

int main(void)
{
    int n, k;
    cin >> n >> k;

    vector < map <int, int> > nums(10);
    for(int i = 0; i < 100; ++i)
        nums[i % 10][i] = 0;

    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;
        nums[x % 10][x]++;
    }

    for(int i = 9; i >= 0; --i)
        for(auto & num : nums[i]){
            if(num.first == 100)
                continue;

            int upper = find_upper(num.first);
            int diff = upper - num.first;
            int count = min(num.second, k / diff);
            k -= (diff * count);
            num.second -= count;
            nums[upper % 10][upper] += count;
        }

    int result = 0;
    for(auto num : nums)
        for(auto a : num)
            result += ((a.first / 10) * a.second);
    cout << result << endl;
    return 0;
}
