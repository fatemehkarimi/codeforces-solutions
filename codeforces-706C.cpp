//https://codeforces.com/problemset/problem/706/C
//C. Hard problem

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

int main(void)
{
    int n = 0;
    cin >> n;

    vector <long long int> values(n);
    vector <string> words(n);

    for(int i = 0; i < n; ++i)
        cin >> values[i];

    for(int i = 0; i < n; ++i)
        cin >> words[i];

    vector <long long int> word_reversed(n, LLONG_MAX);
    vector <long long int> word_not_reversed(n, LLONG_MAX);

    word_reversed[0] = values[0];
    word_not_reversed[0] = 0;

    for(int i = 1; i < n; ++i){
        string reversed1 = words[i];
        reverse(reversed1.begin(), reversed1.end());
        string reversed2 = words[i - 1];
        reverse(reversed2.begin(), reversed2.end());

        if(words[i - 1] <= words[i])
            word_not_reversed[i] = word_not_reversed[i - 1];
        if(reversed2 <= words[i])
            word_not_reversed[i] = min(word_not_reversed[i], word_reversed[i - 1]);

        if(word_not_reversed[i - 1] != LLONG_MAX && words[i - 1] <= reversed1)
            word_reversed[i] = word_not_reversed[i - 1] + values[i];
        if(word_reversed[i - 1] != LLONG_MAX && reversed2 <= reversed1)
            word_reversed[i] = min(word_reversed[i], word_reversed[i - 1] + values[i]);
    }

    long long int result = min(word_reversed[n - 1], word_not_reversed[n - 1]);

    if(result == LLONG_MAX)
        cout << "-1" << endl;
    else
        cout << result << endl;

    return 0;
}
