//https://codeforces.com/problemset/problem/5/C

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <map>

using namespace std;

int main(void)
{
    string input;
    cin >> input;

    int size = input.size();
    vector <int> arr(size, -1);
    stack <int> Stack;

    for(int i = 0; i < size; ++i)
        if(input[i] == '(')
            Stack.push(i);
        else{
            if(!Stack.empty()){
                int top = Stack.top();
                arr[i] = top;
                Stack.pop();

                if(top > 0 && arr[top - 1] != -1)
                    arr[i] = arr[top - 1];
            }
        }

    map <int, int> lengths;

    for(int i = 0; i < size; ++i)
        if(arr[i] != -1)
            lengths[i - arr[i] + 1]++;

    if(lengths.empty()){
        cout << 0 << ' ' << 1 << endl;
        return 0;
    }
    
    auto result = lengths.rbegin();
    cout << result->first << ' ' << result->second << endl;

    return 0;
}
