//https://codeforces.com/problemset/problem/962/C
//C. Make a Square

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

#define _INFINITY 20

bool is_square(int n)
{
    int sq = sqrt(n);
    if(sq * sq == n)
        return true;
    return false;
}

int check_num(vector <int> & num)
{
    int n = 0;
    int remove = 0;
    for(auto a : num)
        if(a != -1)
            n = n * 10 + a;
        else
            ++remove;
    if(is_square(n))
        return remove;
    else
        return _INFINITY;
}

void brute_force(vector <int> num, int idx, int & min_remove)
{
    if(idx >= (int)num.size()){
        int i = 0;
        while(i < (int)num.size() && num[i] == -1)
            ++i;

        if(i < (int)num.size() && num[i] == 0)//if number contains leading zeros
            return;

        min_remove = min(min_remove, check_num(num));
        return;
    }

    brute_force(num, idx + 1, min_remove);
    num[idx] = -1;
    brute_force(num, idx + 1, min_remove);
}

int main(void)
{
    int n;
    cin >> n;

    vector <int> num;
    while(n != 0){
        num.push_back(n % 10);
        n /= 10;
    }
    std::reverse(num.begin(), num.end());

    int result = 20;
    brute_force(num, 0, result);
    cout << (result >= (int)num.size() ? -1 : result) << endl;
    return 0;
}
