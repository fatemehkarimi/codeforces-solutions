//https://codeforces.com/problemset/problem/1033/C
//C. Permutation Game

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    vector <int> nums(n);
    map <int, int> num_loc;
    for(int i = 0; i < n; ++i){
        cin >> nums[i];
        num_loc[nums[i]] = i;
    }

    string result(n, 'B');

    for(int i = n - 1; i >= 1; --i){
        bool A_wins = false;
        for(int j = num_loc[i]; j < n && !A_wins; j += i)
            if(i < nums[j] && result[j] == 'B')
                A_wins = true;

        for(int j = num_loc[i]; j >= 0 && !A_wins; j -= i)
            if(i < nums[j] && result[j] == 'B')
                A_wins = true;

        if(A_wins)
            result[num_loc[i]] = 'A';
    }
    cout << result << endl;
    return 0;
}
