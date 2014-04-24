#include <iostream>

using namespace std;

int paint_target(const unsigned long long r, const unsigned long long t);;
bool check(const unsigned long long mid, const unsigned long long r, const unsigned long long t);

int main(void)
{

	int T = 0;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		unsigned long long r; // radius
		unsigned long long t; // milli-L of paint
		cin >> r >> t;

		cout << "Case #" << i+1 << ": ";
		cout << paint_target(r, t) << endl;
	}

	return 0;
}

// use binary search on equation n(2n + 2r -1)
// arithmetic series (http://en.wikipedia.org/wiki/Arithmetic_series)
int paint_target(const unsigned long long r, const unsigned long long t)
{
	unsigned long long low = 1;
	unsigned long long high = 2;

	while (check(high,r,t))
	{
		low = high;
		high *= 2;
	}

	while ( low < high )
	{
		unsigned long long mid = (low + high + 1)/2;
		// cout << mid << " | " << mid*(2*r + 2*mid-1) << " | " << t;
		if ( check(mid, r, t) )
			low = mid;
		else
			high = mid - 1;
	}
	return low;
}

bool check(const unsigned long long mid, const unsigned long long r, const unsigned long long t)
{
	return mid*(2*r + 2*mid-1) <= t;
}


