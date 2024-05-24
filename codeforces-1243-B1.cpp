//https://codeforces.com/contest/1243/problem/B1
//B1. Character Swap (Easy Version)

#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    int k;
    cin >> k;
    while(k--){
        int n;
        cin >> n;

        string str1, str2;
        cin >> str1 >> str2;


        bool operation_performed = false;
        bool possible = true;

        for(int i = 0; i < n; ++i)
            if(str1[i] != str2[i]){
                if(operation_performed)
                    possible = false;

                for(int j = i + 1; j < n; ++j)
                    if(str2[j] == str2[i] && str1[j] == str1[i]){
                        str2[j] = str1[i];
                        str1[i] = str1[j];
                        operation_performed = true;
                        break;
                    }

                if(!operation_performed)
                    possible = false;
            }

        if(operation_performed && possible)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
