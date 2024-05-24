//https://codeforces.com/problemset/problem/331/C1
//The Great Julya Calendar

#include <iostream>

using namespace std;

int main(void)
{
    long long int n = 0;
    cin >> n;

    long long int steps = 0;
    while(n != 0){
        long long int tmp = n;
        long long int max_digit = tmp % 10;
        while(tmp != 0){
            max_digit = max(max_digit, tmp % 10);
            tmp /= 10;
        }

        n -= max_digit;
        ++steps;
    }

    cout << steps << endl;
    return 0;
}
