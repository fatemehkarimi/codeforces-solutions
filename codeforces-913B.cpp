//https://codeforces.com/problemset/problem/913/B
//Christmas Spruce

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    vector < vector <int> > Graph(n);

    for(int i = 0; i < n - 1; ++i){
        int tmp;
        cin >> tmp;

        Graph[tmp - 1].push_back(i + 1);
    }

    bool spurce = true;
    for(int i = 0; i < n; ++i)
        if(Graph[i].size() != 0){//case node is not a leaf
            int leaf = 0;
            for(int j = 0; j < Graph[i].size(); ++j)
                if(Graph[Graph[i][j]].size() == 0)
                    ++leaf;

            if(leaf < 3){
                spurce = false;
                break;
            }
        }

    if(spurce)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
