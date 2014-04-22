#include <iostream>
#include <cmath>

using namespace std;

const double pi = 3.1415926535897932;
const double pi_inv = 0.3183098861837907;

int paint_target(const double _r, const double _t);

int main(void)
{

	int T = 0;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		double r; // radius
		double t; // milli-L of paint
		cin >> r >> t;

		cout << "Case #" << i+1 << ": ";
		cout << paint_target(r, t) << endl;
	}

	return 0;
}

int paint_target(const double _r, const double _t)
{
	int ctr = 0;
	double r = _r + 1;
	double rem = _t; // remaining paint

	do
	{
		ctr++;
		rem = rem - ( pow(r,2) - pow(r-1,2) );
		r+=2;
	}
	while (rem >= 0);

	return ctr-1;
}


