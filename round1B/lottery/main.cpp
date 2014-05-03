#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <cmath>
using namespace std;

int main(void)
{
	int T;
	cin >> T;
	for (int z = 0; z < T; z++)
	{
		unsigned a, b, k, ctr;
		cin >> a >> b >> k;

		//vector<unsigned > v;
		ctr = 0;
		for (unsigned i = 0; i < a; i++)
		{
			for (unsigned j = 0; j < b; j++)
			{
				unsigned res = i&j;
				if (res < k)
					ctr++;
			}
		}

		cout << "Case #" << z+1 << ": " << ctr << endl;
	}
	return 0;
}


