//https://codeforces.com/problemset/problem/1100/C
//C. NN and the Optical Illusion

#include <iostream>
#include <iomanip>
#include <cmath>

#define PI 3.14159265358979323846
using namespace std;

int main(void)
{
    int n, r;
    cin >> n >> r;

    double cosAngle = cos((n - 2) * PI / (2 * (double)n));
    double R = cosAngle * r / (1 - cosAngle);
    cout << fixed << setprecision(10) << R << endl;
    return 0;
}
