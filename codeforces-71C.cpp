//https://codeforces.com/problemset/problem/71/C
//C. Round Table Knights

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    vector <int> nums(n);
    for(int i = 0; i < n; ++i)
        cin >> nums[i];

    int polygan = 0;
    int offset = 0;
    for(int x = 3; x <= n; ++x){
        if(n % x == 0){
            polygan = n;
            offset = n / x;
                
            for(int i = 0; i < n; ++i)
                if(nums[i]){
                    bool valid_polygan = true;
                    for(int j = i, k = polygan; k > 0; j = (j + offset) % n, --k){
                        if(!nums[j]){
                            valid_polygan = false;
                            break;
                        }
                    }
                    if(valid_polygan){
                        cout << "YES" << endl;
                        return 0;
                    }
                }
        }
    }
    cout << "NO" << endl;
    return 0;
}
