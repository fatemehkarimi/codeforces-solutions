//https://codeforces.com/problemset/problem/279/C
//C. Ladder

#include <iostream>
#include <vector>

using namespace std;

int find_up_point(vector <int> & up, int left, int right, int left_idx, int right_idx)
{
    if(left >= right)
        return -1;

    int middle = left + (right - left) / 2;
    if(up[middle] >= left_idx && up[middle] < right_idx){
        int result = find_up_point(up, middle + 1, right, left_idx, right_idx);
        return result == -1 ? middle : result;
    }
    else if(up[middle] < left_idx)
        return find_up_point(up, middle + 1, right, left_idx, right_idx);
    else
        return find_up_point(up, left, middle, left_idx, right_idx);
}

int find_down_point(vector <int> & down, int left, int right, int left_idx, int right_idx)
{
    if(left >= right)
        return -1;

    int middle = left + (right - left) / 2;
    if(down[middle] >= left_idx && down[middle] < right_idx){
        int result = find_down_point(down, left, middle, left_idx, right_idx);
        return result == -1 ? middle : result;
    }
    else if(down[middle] < left_idx)
        return find_down_point(down, middle + 1, right, left_idx, right_idx);
    else
        return find_down_point(down, left, middle, left_idx, right_idx);
}

int main(void)
{
    int n, m;
    cin >> n >> m;
    vector <int> arr(n);
    for(int i = 0; i < n; ++i)
        cin >> arr[i];

    vector <int> up;
    vector <int> down;

    for(int i = 0; i < n - 1; ++i)
        if(arr[i] > arr[i + 1])
            down.push_back(i);
        else if(arr[i] < arr[i + 1])
            up.push_back(i);

    while(m--){
        int left, right;
        cin >> left >> right;
        --left, --right;

        int up_idx = find_up_point(up, 0, up.size(), left, right);
        int down_idx = find_down_point(down, 0, down.size(), left, right);

        if(up_idx == -1 || down_idx == -1)
            cout << "Yes" << endl;
        else if(up[up_idx] < down[down_idx])
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}
