//https://codeforces.com/contest/1216/problem/C
//C. White Sheet

#include <iostream>

using namespace std;

typedef struct dot{
	int x;
	int y;
	dot(int xx, int yy){
		x = xx;
		y = yy;
	}
	dot(){}
}dot;

bool is_inner(dot A1, dot A2, dot B1, dot B2)
{
	if(!(A1.x >= B1.x && A1.x <= B2.x && A1.y >= B1.y && A1.y <= B2.y))
		return false;
	if(!(A2.x >= B1.x && A2.x <= B2.x && A2.y >= B1.y && A2.y <= B2.y))
		return false;
	return true;
}

bool fully_covers(dot W1, dot W2, dot B11, dot B12, dot B21, dot B22)
{
	bool result = false;
	bool not_covered = true;
	if(B11.x - W1.x > 0 && W2.y - W1.y > 0 && is_inner(W1, dot(B11.x, W2.y), W1, W2))
		result = result || !is_inner(W1, dot(B11.x, W2.y), B21, B22), not_covered = false;

	if(W2.x - W1.x > 0 && W2.y - B12.y > 0 && is_inner(dot(W1.x, B12.y), W2, W1, W2))
		result = result || !is_inner(dot(W1.x, B12.y), W2, B21, B22), not_covered = false;

	if(W2.x - B12.x > 0 && W2.y - W1.y > 0 && is_inner(dot(B12.x, W1.y), W2, W1, W2))
		result = result || !is_inner(dot(B12.x, W1.y), W2, B21, B22), not_covered = false;

	if(W2.x - W1.x > 0 && B11.y - W1.y > 0 && is_inner(W1, dot(W2.x, B11.y), W1, W2))
		result = result || !is_inner(W1, dot(W2.x, B11.y), B21, B22), not_covered = false;

	if(not_covered)
		return true;
	return result;
}

int main(void)
{
	dot W1, W2, B11, B12, B21, B22;
	cin >> W1.x >> W1.y >> W2.x >> W2.y >> B11.x >> B11.y >> B12.x >> B12.y >> B21.x >> B21.y >> B22.x >> B22.y;

	if(is_inner(W1, W2, B11, B12) || is_inner(W1, W2, B21, B22))
		return cout << "NO" << endl, 0;

	bool result = fully_covers(W1, W2, B11, B12, B21, B22) || fully_covers(W1, W2, B21, B22, B11, B12);
	if(result)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
