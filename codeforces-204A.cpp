//https://codeforces.com/problemset/problem/204/A

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int numberOfDigits(long long int num);
long long int countBetween(long long int a, int digit);

int main(void)
{
    vector <long long int> digits_count(20, 0);

    digits_count[0] = 0;
    digits_count[1] = 9;
    digits_count[2] = 9;

    for(int i = 3; i < 20; ++i)
        digits_count[i] = digits_count[i - 1] * 10;

    long long int left, right;
    cin >> left >> right;

    int n_digits_left = numberOfDigits(left);
    int n_digits_right = numberOfDigits(right);

    long long int result = 0;
    for(int i = 1; i < n_digits_right; ++i)
        result += digits_count[i];

    for(int i = 1; i < n_digits_left; ++i)
        result -= digits_count[i];

    if(left < 10)
        result -= (left - 1);
    else
        result -= countBetween(left - 1, n_digits_left);

    if(right < 10)
        result += (right);
    else
        result += countBetween(right, n_digits_right);

    cout << result << endl;

    return 0;
}

int numberOfDigits(long long int num)
{
    int count = 0;
    while(num != 0){
        ++count;
        num /= 10;
    }

    return count;
}

long long int countBetween(long long int a, int digit)
{
    long long int power10 = pow(10, digit - 1);
    int leftmostDigit = a / power10;
    int rightmostDigit = a % 10;

    long long int numBetween = a % power10;
    numBetween /= 10;

    ++numBetween;//0 to numBetween

    long long int count = 0;

    count = (leftmostDigit - 1) * pow(10, digit - 2);
    count += numBetween;

    if(rightmostDigit < leftmostDigit)
        --count;

    return count;
}
