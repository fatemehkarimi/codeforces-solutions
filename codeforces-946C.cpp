//https://codeforces.com/problemset/problem/946/C
//C. String Transformation

#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string input;
    cin >> input;
    if(input.size() < 26){
        cout << -1 << endl;
        return 0;
    }

    int idx = 0;
    for(int i = 0; i < input.size(); ++i)
        if(idx < 26 && input[i] - 'a' <= idx)
            input[i] = 'a' + idx++;

    if(idx < 26)
        cout << -1 << endl;
    else
        cout << input << endl;
    return 0;
}
