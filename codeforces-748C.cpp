//https://codeforces.com/problemset/problem/748/C
//C. Santa Claus and Robot

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    string input;
    cin >> input;

    pair <int, int> start_point = make_pair(0, 0);
    int idx_start = 0;
    pair <int, int> curr_loc = make_pair(0, 0);

    vector <pair <int, int> > points;
    points.push_back(start_point);
    for(int i = 0; i < n; ++i){
        pair <int, int> pre_loc = curr_loc;

        if(input[i] == 'L')
            curr_loc.first -= 1;
        else if(input[i] == 'U')
            curr_loc.second += 1;
        else if(input[i] == 'R')
            curr_loc.first += 1;
        else
            curr_loc.second -= 1;

        if(abs(curr_loc.first - start_point.first) + abs(curr_loc.second - start_point.second) < i - idx_start){
            if(points.empty() || points.back() != start_point)
                points.push_back(start_point);
            points.push_back(pre_loc);
            start_point = pre_loc;
            idx_start = i;
        }
    }

    cout << points.size() << endl;
    return 0;
}
