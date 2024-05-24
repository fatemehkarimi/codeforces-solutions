//http://codeforces.com/contest/982/problem/C

#include <iostream>
#include <vector>

using namespace std;

pair <int, bool> DFS(vector < vector <int> > & Tree, vector <bool> & visited, int start);

int main(void)
{
  int n = 0;
  cin >> n;

  vector < vector <int> > Tree(n);

  for (int i = 0; i < n - 1; ++i){
    int t1, t2;
    cin >> t1 >> t2;
    --t1;
    --t2;

    Tree[t1].push_back(t2);
    Tree[t2].push_back(t1);
  }

  vector <bool> visited(n, false);
  pair <int, bool> result = DFS(Tree, visited, 0);

  if (!result.second)
    cout << result.first - 1 << endl;
  else
    cout << "-1" << endl;

  return 0;
}


pair <int, bool> DFS(vector < vector <int> > & Tree, vector <bool> & visited, int start)
{
  visited[start] = 1;

  bool com_size = 1;
  int total_comp = 0;

  for (auto a : Tree[start])
    if (!visited[a]){
       pair <int, bool> tmp = DFS(Tree, visited, a);


        total_comp += tmp.first;

        if (tmp.second)
          com_size = !com_size;
     }


  if (!com_size)
    ++total_comp;

    return make_pair(total_comp, com_size);

}
