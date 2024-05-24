//http://codeforces.com/contest/982/my
//contest 484
//problem solved in practice
//failed to solve at contest time

#include <iostream>
#include <string>

using namespace std;

int main(void)
{
  int n = 0;
  while (cin >> n) {
    string str;

    cin >> str;
    str = '0' + str + '0';

    if(str.find("000") != string::npos  || str.find("11") != string::npos)
      cout << "No" << endl;
    else
      cout << "Yes" << endl;
  }
  return 0;
}
