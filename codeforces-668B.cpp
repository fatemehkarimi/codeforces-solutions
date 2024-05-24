//https://codeforces.com/problemset/problem/688/B
//B. Lovely Palindromes

#include  <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(void)
{
    string num;
    cin >> num;
    string rev_num = num;
    std::reverse(rev_num.begin(), rev_num.end());
    num = num + rev_num;
    cout << num << endl;
    return 0;
}
