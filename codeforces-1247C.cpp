//https://codeforces.com/contest/1247/problem/C
//C. p-binary

#include <iostream>
#include <climits>
#define lld long long int

using namespace std;

int count_one(lld num)
{
    int count = 0;
    while(num != 0){
        if(num % 2)
            ++count;
        num = num >> 1;
    }
    return count;
}

int main(void)
{
    lld n, p;
    cin >> n >> p;

    if(n <= p){
        cout << -1 << endl;
        return 0;
    }

    lld factor = 1;
    while(true){
        lld num = n - factor * p;
        if(num <= 0)
            break;
        if(count_one(num) <= factor && num >= factor){
            cout << factor << endl;
            return 0;
        }
        ++factor;
    }
    cout << -1 << endl;
    return 0;
}
