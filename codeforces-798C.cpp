//https://codeforces.com/problemset/problem/798/C
//C. Mike and gcd problem

#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
    while(b != 0){
        int tmp = a;
        a = b;
        b = tmp % b;
    }
    return a;
}

int main(void)
{
    int n;
    cin >> n;
    vector <int> nums(n);
    for(int i = 0; i < n; ++i)
        cin >> nums[i];

    int _gcd = nums[0];
    for(int i = 1; i < n; ++i)
        _gcd = gcd(_gcd, nums[i]);

    if(_gcd != 1){
        cout << "YES" << endl << 0 << endl;
        return 0;
    }

    int count = 0;
    for(int i = 0; i < n; ++i)
        if(nums[i] % 2){
            if(i + 1 < n && nums[i + 1] % 2){
                ++count;
                int a = nums[i];
                int b = nums[i + 1];
                nums[i] = a - b;
                nums[i + 1] = a + b;
            }
            else if(i - 1 >= 0 && nums[i - 1] % 2 == 0){
                ++count;
                int a = nums[i - 1];
                int b = nums[i];
                nums[i - 1] = a - b;
                nums[i] = a + b;
                ++count;
                a = nums[i - 1];
                b = nums[i];
                nums[i - 1] = a - b;
                nums[i] = a + b;
            }
            else if(i + 1 < n && nums[i + 1] % 2 == 0){
                ++count;
                int a = nums[i];
                int b = nums[i + 1];
                nums[i] = a - b;
                nums[i + 1] = a + b;
                ++count;
                a = nums[i];
                b = nums[i + 1];
                nums[i] = a - b;
                nums[i + 1] = a + b;
            }
        }
    cout << "YES" << endl;
    cout << count << endl;
    return 0;
}
