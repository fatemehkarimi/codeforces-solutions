//DP-CODEFORCES
//https://codeforces.com/problemset/problem/174/B
//B. File List

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
    string input;
    cin >> input;

    vector <string> result;

    bool possible = true;
    int pre = 0;
    bool before_dot = true;
    string file_name;
    for(int i = 0; i < (int)input.size();)
        if(input[i] != '.'){
            ++pre;
            ++i;
        }
        else if(input[i] == '.' && before_dot){
            if(pre > 8 || pre < 1){
                possible = false;
                break;
            }
            file_name = input.substr(i - pre, pre);
            file_name += '.';
            pre = 0;
            before_dot = false;
            ++i;
        }
        else if(input[i] == '.' && !before_dot){
            if(pre <= 1){
                possible = 0;
                break;
            }
            int ext_len = 0;
            if(pre > 3)
                ext_len = 3;
            else if(pre == 3)
                ext_len = 2;
            else if(pre == 2)
                ext_len = 1;
            file_name = file_name + input.substr(i - pre, ext_len);
            result.push_back(file_name);
            pre -= ext_len;
            before_dot = true;
        }

    if(!before_dot){
        if(pre > 3 || pre < 1)
            possible = false;
        else{
            file_name += input.substr((int)input.size() - pre, pre);
            result.push_back(file_name);
            pre = 0;
        }
    }

    if(possible && pre == 0){
        cout << "YES" << endl;
        for(auto a : result)
            cout << a << endl;
    }
    else
        cout << "NO" << endl;
    return 0;
}
