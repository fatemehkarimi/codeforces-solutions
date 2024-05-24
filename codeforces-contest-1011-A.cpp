//http://codeforces.com/contest/1011/problem/A

#include <iostream>
#include <string>
#include <set>

using namespace std;

int main(void)
{
  int n, k;
  cin >> n >> k;
  getchar();
  string input;
  getline(cin, input);

  set <char> stage;

  for (int i = 0; i < input.size(); ++i)
    if (input[i] >= 'a' && input[i] <= 'z')
      stage.insert(input[i]);


  int finalWeight = 0;

  int last = -1;

  int counter = 0;
  for (auto a = stage.begin(); a != stage.end() && counter < k; ++a)
    if (last + 1 != (int)(*a)){
      finalWeight += (*a - 'a' + 1);
      last = *a;
      ++counter;
    }

  if (counter < k)
    cout << -1 << endl;
  else
    cout << finalWeight << endl;



  return 0;
}
