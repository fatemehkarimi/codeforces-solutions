//https://codeforces.com/problemset/problem/868/C
//C. Qualification Rounds

#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main(void)
{
    int n, k;
    cin >> n >> k;

    vector <set <int> > problem_status(n);
    vector <set <int> > team_status(k);

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < k; ++j){
            int status;
            cin >> status;
            if(status == 1){
                team_status[j].insert(i);
                problem_status[i].insert(j);
            }
        }

    for(auto team : team_status)
        if((int)team.size() == n){
            cout << "NO" << endl;
            return 0;
        }

    for(auto problem : problem_status)
        if((int)problem.size() == 0){
            cout << "YES" << endl;
            return 0;
        }

    for(auto team : problem_status)
        if((int)team.size() == 1){
            int only_team = *team.begin();
            if((int)team_status[only_team].size() >= 1 && (int)team_status[only_team].size() < n)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
            return 0;
        }

    if(k == 3){
        cout << "NO" << endl;
        return 0;
    }

    //[0-1], [0, 2], [0, 3], [2, 3], [1, 3], [1, 2]
    bool all_valid_combination[] = {0, 0, 0, 0, 0, 0};
    for(auto a : problem_status)
        if(a.size() == 2){
            if(a.find(0) != a.end() && a.find(1) != a.end())
                all_valid_combination[0] = true;
            else if(a.find(0) != a.end() && a.find(2) != a.end())
                all_valid_combination[1] = true;
            else if(a.find(0) != a.end() && a.find(3) != a.end())
                all_valid_combination[2] = true;
            else if(a.find(2) != a.end() && a.find(3) != a.end())
                all_valid_combination[3] = true;
            else if(a.find(1) != a.end() && a.find(3) != a.end())
                all_valid_combination[4] = true;
            else if(a.find(1) != a.end() && a.find(2) != a.end())
                all_valid_combination[5] = true;
        }

    for(int i = 0; i < 3; ++i)
        if(all_valid_combination[i] == 1 && all_valid_combination[i + 3] == 1){
            cout << "YES" << endl;
            return 0;
        }
    cout << "NO" << endl;
    return 0;
}

