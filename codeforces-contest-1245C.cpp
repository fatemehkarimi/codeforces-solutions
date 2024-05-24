//https://codeforces.com/contest/1245/problem/C
//C. Constanze's Machine

#include <iostream>
#include <string>
#include <vector>

#define lld long long int
#define MODULO 1000000007

using namespace std;

int main(void)
{
    vector <lld> fibo(100000);
    fibo[0] = 1;
    fibo[1] = 2;

    for(int i = 2; i < (int)fibo.size(); ++i){
        fibo[i] = fibo[i - 1] + fibo[i - 2];
        fibo[i] %= MODULO;
    }

    string input;
    cin >> input;

    lld result = 1;
    for(lld i = 0; i < (lld)input.size(); ++i){
        if(input[i] == 'u'){
            lld j = i;
            while(input[j] == 'u')
                ++j;

            result = (result * fibo[j - i - 1]) % MODULO;
            i = j - 1;
        }
        else if(input[i] == 'n'){
            lld j = i;
            while(input[j] == 'n')
                ++j;

            result = (result * fibo[j - i - 1]) % MODULO;
            i = j - 1;
        }
        else if(input[i] == 'w' || input[i] == 'm')
            result = 0;
    }

    cout << result << endl;
    return 0;
}
