//https://codeforces.com/problemset/problem/1076/C
//C. Meme Problem

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(void)
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        double B = sqrt(n * n - 4 * n);
        double root1 = (n + B) / 2;
        double root2 = (n - B) / 2;

        bool result_found = 0;
        if(root1 >= 0){
            double a = root1;
            double b = n - a;

            if(b >= 0){
                result_found = 1;
                cout << "Y " << fixed << setprecision(10) << a << ' ' << fixed << setprecision(10) << b << endl; 
            }
        }
        if(root2 >= 0 && !result_found){
            double a = root2;
            double b = n - a;

            if(b >= 0){
                result_found = 1;
                cout << "Y " << fixed << setprecision(10) << a << ' ' << fixed << setprecision(10) << b << endl; 
            }   
        }

        if(!result_found)
            cout << "N" << endl;
    }   
    return 0;
}


