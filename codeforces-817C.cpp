//https://codeforces.com/problemset/problem/817/C
//C. Really Big Numbers

#include <iostream>
#define lld long long int

using namespace std;

lld calc(lld num){
    lld tmp = num;
    lld sum = 0;
    while(tmp != 0){
        sum += (tmp % 10);
        tmp /= 10;
    }
    return num - sum;
}

lld binary_search(lld first, lld last, lld s)
{
    if(first >= last)
        return -1;

    lld middle = first + (last - first) / 2;
    lld val_middle = calc(middle);
    if(val_middle == s)
        return middle;
    if(s < val_middle)
        return binary_search(first, middle, s);
    else
        return binary_search(middle + 1, last, s);
}

int main(void)
{
    lld n, s;
    cin >> n >> s;

    if(s == 0){
        cout << n << endl;
        return 0;
    }
    lld first_num = -1;
    s = (s % 9 == 0 ? s : (s / 9 + 1) * 9);

    while(first_num == -1){
        first_num = binary_search(0, 10e18, s);
        s += 9;
    }
    first_num -= (first_num % 10);
    cout << max((lld)0, n - first_num + 1) << endl;
    return 0;
}
