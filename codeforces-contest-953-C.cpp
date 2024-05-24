//codeforces
//contest 953 probelm C
//http://codeforces.com/contest/953/problem/C

#include <iostream>
#include <map>

using namespace std;

int main(void)
{
    int n;
    while (cin >> n) {
        bool * arr = new bool[n];

        for (int i = 0; i < n; ++i)
            cin >> arr[i];

        map <bool, int> counts;

        bool isZebra = 1;

        for (int i = 0; i < n; ){
            int counter = 0;
            bool curr_value = arr[i];
            while(i < n && arr[i] == curr_value){
                ++i;
                ++counter;
            }

            auto a = counts.find(curr_value);
            if (a == counts.end())
                counts.insert(make_pair(curr_value, counter));
            else if (a->second != counter){
                    isZebra = 0;
                    break;
            }

        }

        int count = counts.begin()->second;
        for (auto a : counts)
            if (a.second != count){
                isZebra = 0;
                break;
            }


        if (isZebra)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        
        delete[] arr;
        arr = nullptr;
    }
    return 0;
}
