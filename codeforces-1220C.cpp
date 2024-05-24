//https://codeforces.com/problemset/problem/1220/C
//C. Substring Game in the Lesson

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
    string input;
    cin >> input;
    vector <bool> extendable(input.size(), false);
    char min_char = input[0];
    for(int i = 1; i < (int)input.size(); ++i){
        if(min_char < input[i])
            extendable[i] = true;

        min_char = min(min_char, input[i]);
    }

    for(auto a : extendable)
        if(a)
            cout << "Ann" << endl;
        else
            cout << "Mike" << endl;
    return 0;
}
