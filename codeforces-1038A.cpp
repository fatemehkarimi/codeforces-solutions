//http://codeforces.com/problemset/problem/1038/A
//Equality

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;

    vector <int> count(k, 0);

    for(int i = 0; i < n; ++i)
        ++count[str[i] - 'A'];

    cout << (*min_element(count.begin(), count.end())) * k << endl;

    return 0;
}
