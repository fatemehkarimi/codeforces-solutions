//https://codeforces.com/contest/1215/problem/B
//B. The Number of Products

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    vector <long long int> positive(n + 1, 0);
    vector <long long int> negative(n + 1, 0);

    long long int sum_pos = 0, sum_neg = 0;
    for(int i = 1; i <= n; ++i){
        int num;
        cin >> num;

        if(num < 0){
            negative[i] = 1 + positive[i - 1];
            positive[i] = negative[i - 1];
        }
        else{
            negative[i] = negative[i - 1];
            positive[i] = 1 + positive[i - 1];
        }
        sum_neg += negative[i];
        sum_pos += positive[i];
    }
    cout << sum_neg << ' ' << sum_pos << endl;
    return 0;
}
