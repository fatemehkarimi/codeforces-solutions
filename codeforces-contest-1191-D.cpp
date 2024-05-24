//https://codeforces.com/contest/1191/problem/D
//D. Tokitsukaze, CSL and Stone Game

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    vector <int> nums(n);
    for(int i = 0; i < n; ++i)
        cin >> nums[i];

    sort(nums.begin(), nums.end());
    bool starter = 0;//0 for sjf, 1 for csl
    for(int i = 0; i < n - 1; ++i)
        if(nums[i] > 0 && nums[i] == nums[i + 1]){
            --nums[i];
            starter = 1;
            break;
        }
    sort(nums.begin(), nums.end());
    for(int i = 0; i < n - 1; ++i)
        if(nums[i] == nums[i + 1]){
            cout << "cslnb" << endl;
            return 0;
        }

    for(int i = 0; i < n; ++i)
        if(nums[i] - i >= 0){
            nums[i] -= i;
            if(nums[i] % 2)
                starter = !starter;
        }
        else
            break;

    if(starter)
        cout << "sjfnb" << endl;
    else
        cout << "cslnb" << endl;
    return 0;
}
