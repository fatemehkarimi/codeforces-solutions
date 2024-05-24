//https://codeforces.com/problemset/problem/552/C
//C. Vanya and Scales

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int w, m;
    cin >> w >> m;

    vector <int> num_base_w(40, 0);
    int idx = 0;
    while(m != 0){
        num_base_w[idx++] = m % w;
        m /= w;
    }

    for(int i = 0; i <= idx; ++i)
        if(num_base_w[i] == w || num_base_w[i] == w - 1){
            num_base_w[i + 1]++;
        }
        else if (num_base_w[i] > 1)
            return cout << "NO" << endl, 0;
    cout << "YES" << endl;
    return 0;
}
