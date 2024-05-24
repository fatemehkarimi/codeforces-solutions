//http://codeforces.com/contest/1059/problem/C

#include <iostream>
#include <vector>

using namespace std;

vector <int> sequenceTransform(int n);

int main(void)
{
    int n;
    cin >> n;

    vector <int> result = sequenceTransform(n);
    for(auto a : result)
        cout << a << ' ';
    cout << endl;

    return 0;
}

vector <int> sequenceTransform(int n)
{
    vector <int> result;
    if (n == 1){
        result.push_back(1);
        return result;
    }
    else if (n == 2){
        result.push_back(1);
        result.push_back(2);
        return result;
    }
    else if (n == 3){
        result.push_back(1);
        result.push_back(1);
        result.push_back(3);
        return result;
    }

    int limit = (n % 2 == 0 ? n / 2 : n / 2 + 1);
    for(int i = 0; i < limit; ++i)
        result.push_back(1);

    vector <int> half_result = sequenceTransform(n / 2);

    for(auto a : half_result)
        result.push_back(2 * a);

    return result;
}
