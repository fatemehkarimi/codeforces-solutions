#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n = 0;
	while (cin >> n) {
		long long int x = 0, y = 0, z = 0;

		for (int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			x += tmp;
		}

		for (int j = 0; j < n - 1; ++j) {
			int tmp;
			cin >> tmp;
			y += tmp;
		}

		for (int j = 0; j < n - 2; ++j) {
			int tmp;
			cin >> tmp;
			z += tmp;
		}


		cout << x - y << endl;
		cout << y - z << endl;


	}
	return 0;
}
