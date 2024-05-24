//DP-CODEFORCES
//https://codeforces.com/problemset/problem/416/C
//C. Booking System

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    set < pair < pair <int, int>, int> > requests;
    for(int i = 0; i < n; ++i){
        int size, pay;
        cin >> size >> pay;
        requests.insert(make_pair(make_pair(size, pay), i));
    }

    int m;
    cin >> m;

    vector <pair <int, int> > tables(m);
    for(int i = 0; i < m; ++i){
        int t_size;
        cin >> t_size;
        tables[i] = make_pair(t_size, i);
    }
    sort(tables.begin(), tables.end());

    map <int, int> result;
    int n_sitted = 0, total_paid = 0;
    for(auto table : tables){
        int capacity = table.first;
        int t_idx = table.second;

        pair < pair <int, int>, int> best_fit = make_pair(make_pair(0, 0), -1);
        for(auto request : requests)
            if(request.first.first <= capacity && request.first.second > best_fit.first.second)
                best_fit = request;

        if(best_fit.second != -1){
            result[t_idx] = best_fit.second;
            ++n_sitted;
            total_paid += best_fit.first.second;
            requests.erase(best_fit);
        }
    }

    cout << n_sitted << ' ' << total_paid << endl;
    for(auto a : result)
        cout << a.second + 1 << ' ' << a.first + 1 << endl;
    return 0;
}
