//https://codeforces.com/problemset/problem/915/C
//C. Permute Digits

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>

using namespace std;

int main(void)
{
    long long int n, m;
    cin >> n >> m;

    multiset <int> num1;
    vector <int> num2;

    while(n != 0){
        num1.insert(n % 10);
        n /= 10;
    }

    while(m != 0){
        num2.push_back(m % 10);
        m /= 10;
    }

    std::reverse(num2.begin(), num2.end());
    stack <int> result_num;

    if(num1.size() < num2.size()){
        for(auto digit = num1.rbegin(); digit != num1.rend(); ++digit)
            cout << *digit;
        return cout << endl, 0;
    }

    bool is_smaller = 0;
    for(int i = 0; i < (int)num2.size() && !is_smaller; ++i){
        int value = -1;
        for(auto digit = num1.rbegin(); digit != num1.rend(); ++digit)
            if(*digit <= num2[i]){
                value = *digit;
                break;
            }

        if(value == -1){
            for(int k = i - 1; k >= 0; --k){
                num1.insert(result_num.top());
                result_num.pop();
                for(auto digit = num1.rbegin(); digit != num1.rend(); ++digit)
                    if(*digit < num2[k]){
                        value = *digit;
                        break;
                    }

                if(value != -1){
                    result_num.push(value);
                    auto a = num1.find(value);
                    num1.erase(a);
                    is_smaller = true;
                    break;
                }
            }
        }
        else{
            result_num.push(value);
            auto a = num1.find(value);
            num1.erase(a);

            if(value < num2[i])
                is_smaller = true;
        }
    }

    vector <int> num;
    while(!result_num.empty()){
        num.push_back(result_num.top());
        result_num.pop();
    }
    std::reverse(num.begin(), num.end());
    for(auto a : num)
        cout << a;
    for(auto digit = num1.rbegin(); digit != num1.rend(); ++digit)
        cout << *digit;
    cout << endl;
    return 0;
}
