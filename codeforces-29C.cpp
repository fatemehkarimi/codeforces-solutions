//https://codeforces.com/problemset/problem/29/C
//C. Mail Stamps

#include <iostream>
#include <vector>
#include <map>

using namespace std;

void dfs(map <int, vector <int> > & Graph, vector <int> & path, map <int, bool> & visited, int source)
{
    visited[source] = true;
    path.push_back(source);

    for(auto a : Graph[source])
        if(!visited[a])
            dfs(Graph, path, visited, a);
    return;
}

int main(void)
{
    int n;
    cin >> n;
    map <int, vector <int> > Graph;
    map <int, bool> visited;

    for(int i = 0; i < n; ++i){
        int u, v;
        cin >> u >> v;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
        visited[u] = visited[v] = false;
    }

    int start;
    for(auto a : Graph)
        if(a.second.size() == 1)
            start = a.first;

    vector <int> path;
    dfs(Graph, path, visited, start);

    for(auto a : path)
        cout << a << ' ';
    cout << endl;
    return 0;
}
