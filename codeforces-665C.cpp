//https://codeforces.com/problemset/problem/665/C
//Simple Strings

#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string str;
    cin >> str;

    for(int i = 0; i < str.size() - 1; ++i)
        if(str[i] == str[i + 1])
            for(int j = 0; j < 26; ++j){
                if(i + 2 < str.size() && str[i] != 'a' + j && str[i + 2] != 'a' + j){
                    str[i + 1] = 'a' + j;
                    break;
                }
                else if(i + 2 >= str.size() && str[i] != 'a' + j){
                    str[i + 1] = 'a' + j;
                    break;
                }
            }

    cout << str << endl;

    return 0;
}
