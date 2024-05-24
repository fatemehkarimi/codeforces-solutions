//https://codeforces.com/problemset/problem/1154/C
//C. Gourmet Cat

#include <iostream>

using namespace std;

int main(void)
{
    int f, r, c;
    cin >> f >> r >> c;
    int days = 0;
    days = min(f / 3, min(r / 2, c / 2));
    f = (days < f / 3) ? 3 : f % 3;
    r = (days < r / 2) ? 2 : r % 2;
    c = (days < c / 2) ? 2 : c % 2;
    days *= 7;

    int plan[7] = {0, 1, 2, 0, 2, 1, 0};//0: fish 1: rabit 2: chicken
    int max_day = 0;
    for(int i = 0; i < 7; ++i){
        int tmp_day = 0;
        int tmp_f = f, tmp_r = r, tmp_c = c;
        for(int j = i;; j = (j + 1) % 7){
            if(plan[j] == 0){
                if(f != 0)
                    --f;
                else
                    break;
            }
            if(plan[j] == 1){
                if(r != 0)
                    --r;
                else
                    break;
            }
            if(plan[j] == 2){
                if(c != 0)
                    --c;
                else
                    break;
            }
            ++tmp_day;
        }
        f = tmp_f, r = tmp_r, c = tmp_c;
        max_day = max(max_day, tmp_day);
    }
    cout << days + max_day << endl;
    return 0;
}
