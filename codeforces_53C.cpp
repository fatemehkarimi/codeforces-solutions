//https://codeforces.com/problemset/problem/53/C
//Little Frog

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    vector <bool> used(n + 1, false);
    vector <int> order;

    order.push_back(1);
    used[1] = true;

    for(int i = n - 1; i > 0; --i){
        int num = order.back();
        if(num - i >= 1 && !used[num - i]){
            used[num - i] = true;
            order.push_back(num - i);
        }
        else if(num + i <= n && !used[num + i]){
            used[num + i] = true;
            order.push_back(num + i);
        }
    }

    for(auto a : order)
        cout << a << ' ';
    cout << endl;
    return 0;
}
