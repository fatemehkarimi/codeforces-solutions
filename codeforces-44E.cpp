//https://codeforces.com/problemset/problem/44/E
//E. Anfisa the Monkey

#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main(void)
{
    int k, a, b;
    string input;
    cin >> k >> a >> b >> input;

    vector < vector <int> > array(k, vector <int> (input.size() + 1, -1));

    b = min(b, (int)input.size() - 1);
    for(int i = a; i <= b; ++i)
        array[0][i] = i;

    for(int i = 1; i < k; ++i)
        for(int j = 0; j <= (int)input.size(); ++j)
            for(int bound = a; bound <= b; ++bound)
                if(j - bound >= 0 && array[i - 1][j - bound] != -1){
                    array[i][j] = bound;
                    break;
                }

    if(array[k - 1][input.size()] == -1)
        cout << "No solution" << endl;
    else{
        stack <int> Stack;
        int i = k - 1;
        int j = input.size();

        while(i >= 0 && array[i][j] != -1){
            Stack.push(array[i][j]);
            j -= array[i][j];
            --i;
        }
        i = 0;
        while(!Stack.empty()){
            j = i;
            i += Stack.top();
            Stack.pop();
            for(; j < i; ++j)
                cout << input[j];
            cout << endl;
        }
    }
    return 0;
}
