#include <iostream>

using namespace std;

int paint_target(const long long _r, const long long _t);

int main(void)
{

	int T = 0;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		long long r; // radius
		long long t; // milli-L of paint
		cin >> r >> t;

		cout << "Case #" << i+1 << ": ";
		cout << paint_target(r, t) << endl;
	}

	return 0;
}

int paint_target(const long long _r, const long long _t)
{
	int ctr = 0;
	long long r = _r + 1;
	long long rem = _t; // remaining paint

	do
	{
		ctr++;
		rem = rem - ( r*r - (r-1)*(r-1) );
		r+=2;
	}
	while (rem >= 0);

	return ctr-1;
}

// use binary search on equation n(2n + 2r -1)
// int paint_target2(const long long _r, const long long _t)
// {
// }



