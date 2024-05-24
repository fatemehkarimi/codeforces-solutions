//http://codeforces.com/contest/946/problem/B

#include <iostream>

using namespace std;

int main(void)
{
    long long int a, b;
    while (cin >> a >> b) {
        
        /*long long int newA = a % (2 * b);
        long long int newB = b % (2 * a);*/

        long long int newA = a;
        long long int newB = b;

        while (1) {
            if (newA == 0 || newB == 0)
                break;
            else if (newA >= 2 * newB)
                newA = newA % (2 * newB);
            else if (newB >= 2 * newA)
                newB = newB % (2 * newA);
            else
                break;
        }
        cout << newA << ' ' << newB << endl;
    }
    return 0;
}
