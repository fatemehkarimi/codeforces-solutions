//https://codeforces.com/contest/1215/problem/D
//D. Ticket Game

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    vector <int> nums(n);
    deque <int> indices;

    int sum1 = 0, sum2 = 0;
    for(int i = 0; i < n; ++i){
        char c;
        cin >> c;
        if(c == '?')
            indices.push_back(i);
        else{
            nums[i] = c - '0';
            if(i < n / 2)
                sum1 += nums[i];
            else
                sum2 += nums[i];
        }
    }

    bool turn_m = true;
    while(!indices.empty()){
        if(turn_m){
            if(sum2 < sum1){
                if(indices.front() < n / 2){
                    sum1 += 9;
                    indices.pop_front();
                }
                else if(indices.back() >= n / 2)
                    indices.pop_back();
            }
            else{
                if(indices.back() >= n / 2){
                    sum2 += 9;
                    indices.pop_back();
                }
                else if(indices.front() < n / 2)
                    indices.pop_front();
            }
        }
        else{
            if(sum2 < sum1){
                if(indices.back() >= n / 2){
                    sum2 += 9;
                    indices.pop_back();
                }
                else if(indices.front() < n / 2)
                    indices.pop_front();
            }
            else{
                if(indices.front() < n / 2){
                    sum1 += 9;
                    indices.pop_front();
                }
                else if(indices.back() >= n / 2)
                    indices.pop_back();
            }
        }
        turn_m = !turn_m;
    }

    if(sum1 == sum2)
        cout << "Bicarp" << endl;
    else
        cout << "Monocarp" << endl;
    return 0;
}
