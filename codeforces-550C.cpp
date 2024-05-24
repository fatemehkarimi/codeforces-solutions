//https://codeforces.com/problemset/problem/550/C
//C. Divisibility by Eight


#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
    string num;
    cin >> num;

    vector <string> divisible_by_8;

    for(int i = 0; i < 1000; ++i)
        if(i % 8 == 0)
            divisible_by_8.push_back(to_string(i));

    string result;

    for(int i = 0; i < divisible_by_8.size(); ++i){
        int index = 0;
        for(int j = 0; j < num.size(); ++j)
            if(num[j] == divisible_by_8[i][index])
                ++index;

        if(index == divisible_by_8[i].size()){
            result = divisible_by_8[i];
            break;
        }
    }

    if(result.empty())
        cout << "NO" << endl;
    else{
        cout << "YES" << endl;
        cout << result << endl;
    }
    return 0;
}
