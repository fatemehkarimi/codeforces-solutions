//https://codeforces.com/problemset/problem/676/C
//C. Vasya and String

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
    int n, k;
    cin >> n >> k;
    string input;
    cin >> input;

    vector <int> end_with_a(n, 0);
    vector <int> end_with_b(n, 0);
    vector <int> a_loc, b_loc;

    for(int i = 0; i < n; ++i){
        if(input[i] == 'a'){
            if(i - 1 >= 0)
                end_with_a[i] = end_with_a[i - 1] + 1;
            else
                end_with_a[i] = 1;
            if(k == 0){
                end_with_b[i] = 0;
                continue;
            }
            int size = (int)a_loc.size();
            end_with_b[i] = size - k >= 0 ? i - a_loc[size - k]: i + 1;
            a_loc.push_back(i);
        }
        else{
            if(i - 1 >= 0)
                end_with_b[i] = end_with_b[i - 1] + 1;
            else
                end_with_b[i] = 1;

            if(k == 0){
                end_with_a[i] = 0;
                continue;
            }

            int size = (int)b_loc.size();
            end_with_a[i] = size - k >= 0 ? i - b_loc[size - k]: i + 1;
            b_loc.push_back(i);
        }
    }
    auto max_a = std::max_element(end_with_a.begin(), end_with_a.end());
    auto max_b = std::max_element(end_with_b.begin(), end_with_b.end());
    int result = max(*max_a, *max_b);
    cout << result << endl;
    return 0;
}
