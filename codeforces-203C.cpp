//https://codeforces.com/problemset/problem/203/C
//C. Photographer

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    int n, d, a, b;
    cin >> n >> d >> a >> b;
    vector < pair <int, int> > customers(n);
    for(int i = 1; i <= n; ++i){
        int x, y;
        cin >> x >> y;
        customers[i - 1] = make_pair(x * a + y * b, i);
    }
    sort(customers.begin(), customers.end());
    vector <int> result;
    for(auto a : customers)
        if(d - a.first >= 0){
            result.push_back(a.second);
            d -= a.first;
        }

    cout << result.size() << endl;
    for(auto a : result)
        cout << a << ' ';
    cout << endl;
    return 0;
}
