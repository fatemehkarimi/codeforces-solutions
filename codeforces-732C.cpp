//https://codeforces.com/problemset/problem/732/C
//C. Sanatorium

#include <iostream>
#include <vector>
#include <algorithm>

#define lld long long int

using namespace std;

int main(void)
{
    vector <lld> meals(3);
    cin >> meals[0] >> meals[1] >> meals[2];

    sort(meals.begin(), meals.end());
    lld missed = 0;
    //full meals
    meals[2] -= meals[0], meals[1] -= meals[0];

    if(meals[1] == meals[2] && meals[1] != 0)
        missed += (meals[2] - 1);
    else if(meals[2] > meals[1]){
        --meals[2];//first meal on entrance
        missed += meals[1];
        meals[2] -= meals[1];
        missed += (2 * meals[2]);
    }
    cout << missed << endl;
    return 0;
}
