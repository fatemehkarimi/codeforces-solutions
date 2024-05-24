//http://codeforces.com/problemset/problem/569/B
//B. Inventory

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int n = 0;
    cin >> n;

    vector <pair <int, int> > item;
    vector <bool> used(n, false);
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        --t;
        item.push_back(make_pair(t, i));
    }

    for (int i = 0; i < n; ++i)
        if (item[i].first < n)
            used[item[i].first] = true;

    int pointer = 0;

    for (int i = 0; i < n; ++i)
        if (item[i].first >= n)
            for (; pointer < n; ++pointer)
                if (!used[pointer]){
                    item[i].first = pointer;
                    used[pointer] = true;
                    break;
                }

    sort(item.begin(), item.end());

    for (int i = 0; i < n;){
        int j = i + 1;
        while (j < n && item[j].first == item[i].first){
            while (pointer < n && used[pointer] == true)
                ++pointer;

            item[j].first = pointer;
            used[pointer] = true;
            ++j;
        }

        i = j;
    }

    vector <int> final(n);
    for (auto a : item)
        final[a.second] = a.first;

    for (auto a : final)
        cout << a + 1 << ' ';
    cout << endl;

    return 0;
}
