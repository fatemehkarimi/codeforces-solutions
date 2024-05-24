//https://codeforces.com/contest/1208/problem/B
//B. Uniqueness

#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    vector <int> nums(n);
    for(int i = 0; i < n; ++i)
        cin >> nums[i];
    set <int> prefix;

    int min_length = n - 1;

    for(int i = 0; i < n; ++i){
        bool valid = true;
        map <int, int> freq;

        for(int j = 0; j < i; ++j)
            if(++freq[nums[j]] == 2){
                valid = false;
                break;
            }

        int min_idx_suffix = n;
        for(int j = n - 1; j >= i; --j)
            if(++freq[nums[j]] == 2)
                break;
            else
                min_idx_suffix = j;

        if(valid)
            min_length = min(min_length, min_idx_suffix - i);
    }
    cout << min_length << endl;
    return 0;
}

