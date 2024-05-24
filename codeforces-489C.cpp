//http://codeforces.com/problemset/problem/489/C
//C. Given Length and Sum of Digits...

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string numWithSum(int len, int sum, bool maximum);

int main(void)
{
    int len, sum;
    cin >> len >> sum;

    string smallest = numWithSum(len, sum, 0);
    string biggest = numWithSum(len, sum, 1);

    cout << smallest << ' ' << biggest << endl;

    return 0;
}

string numWithSum(int len, int sum, bool maximum)
{
    vector < vector <int> > arr(len, vector <int> (sum + 1, -1));

    for (int i = 0; i <= min(9, sum); ++i)
        arr[0][i] = i;

    for (int i = 1; i < len; ++i)
        for (int j = 0; j < sum + 1; ++j)
            for (int k = 0; k <= 9; ++k){

                if (i == len - 1 && k == 0)
                    continue;//avoid leading zero

                if (j - k >= 0 && arr[i - 1][j - k] >= 0){
                    if (maximum)
                        arr[i][j] = max(arr[i][j], k);
                    else{
                        if (arr[i][j] == -1)
                            arr[i][j] = k;
                        else
                            arr[i][j] = min(arr[i][j], k);
                    }
                }
            }

    if (arr[len - 1][sum] == -1)
        return "-1";

    string result;
    --len;
    while (len >= 0){
        result = result + (char)(arr[len][sum] + '0');
        sum -= arr[len][sum];
        --len;
    }

    return result;
}
