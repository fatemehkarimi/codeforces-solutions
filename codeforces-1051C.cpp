//https://codeforces.com/problemset/problem/1051/C
//C. Vasya and Multisets

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    map <int, vector <int> > nums;

    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;
        nums[x].push_back(i);
    }

    bool turn_a = false;
    int count_a = 0, count_b = 0;

    string result(n, 'A');
    for(auto a : nums)
        if(a.second.size() == 1){
            if(turn_a){
                result[a.second[0]] = 'A';
                ++count_a;
            }
            else{
                result[a.second[0]] = 'B';
                ++count_b;
            }
            turn_a = !turn_a;
        }

    if(count_a == count_b){
        cout << "YES" << endl << result << endl;
        return 0;
    }

    bool fixed = 0;
    for(auto a : nums)
        if(a.second.size() > 2){
            fixed = 1;
            if(turn_a){
                result[a.second[0]] = 'A';
                for(int i = 1; i < (int)a.second.size(); ++i)
                    result[a.second[i]] = 'B';
            }
            else{
                result[a.second[0]] = 'B';
                for(int i = 1; i < (int)a.second.size(); ++i)
                    result[a.second[i]] = 'A';
            }
            break;
        }
    if(fixed)
        cout << "YES" << endl << result << endl;
    else
        cout << "NO" << endl;
    return 0;
}
