// https://codeforces.com/contest/1337/problem/C
// C. Linova and Kingdom

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

#define lld long long int

using namespace std;

int get_levels(vector <vector <int> > & Graph, vector <pair <int, int> > & order,
                int root, int parent, int level)
{
    int count_below = 0;
    for(auto a : Graph[root])
        if(a != parent){
            count_below += get_levels(Graph, order, a, root, level + 1);
        }
    order.push_back(make_pair(count_below - level, root));
    return count_below + 1;
}

lld get_score(vector <vector <int> > & Graph, vector <bool> & visited,
                set <int> & industry, int root, lld score_above)
{
    lld score = 0;
    if(industry.find(root) != industry.end())
        score = score_above;

    visited[root] = true;

    for(auto a : Graph[root])
        if(!visited[a]){
            if(industry.find(root) == industry.end())
                score += get_score(Graph, visited, industry, a, score_above + 1);
            else
                score += get_score(Graph, visited, industry, a, score_above);
        }
    return score;
}

int main(void)
{
    int n, k;
    cin >> n >> k;

    vector <vector <int> > Graph(n);
    for(int i = 1; i < n; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }

    vector <pair <int, int> > order;
    get_levels(Graph, order, 0, -1, 0);
    sort(order.begin(), order.end());

    set <int> industry;
    for(int i = 0; i < k; ++i)
        industry.insert(order[i].second);

    vector <bool> visited(n, false);
    cout << get_score(Graph, visited, industry, 0, 0) << endl;
    return 0;
}
