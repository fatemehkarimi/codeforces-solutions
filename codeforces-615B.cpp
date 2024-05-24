//https://codeforces.com/problemset/problem/615/B

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main(void)
{
    int n, m;
    cin >> n >> m;

    vector < vector <int> > Graph(n);

    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;

        --u, --v;

        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }

    vector <int> longest_tail(n, 1);

    for(int i = 1; i < n; ++i)
        for(auto a : Graph[i])
            if(a < i)
                longest_tail[i] = max(longest_tail[i], longest_tail[a] + 1);


    long long int result = LONG_MIN;
    for(int i = 0; i < n; ++i)
        result = max(result, (long long int)longest_tail[i] * (long long int)Graph[i].size());

    cout << result << endl;

    return 0;
}
