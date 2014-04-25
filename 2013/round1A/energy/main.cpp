#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

void naive_max_gain(const int &E, const int e, const int &R, const int g,
		vector<int> &res, const vector<int> v, const unsigned int k);

int main(void)
{
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		int e, r, n;
		cin >> e >> r >> n;

		vector<int> v;
		vector<int> results;
		for (int j = 0; j < n; j++)
		{
			int tmp; cin >> tmp;
			v.push_back(tmp);
		}
		naive_max_gain(e, e, r, 0, results, v, 0);
		cout << "Case #" << i << ": " << *max_element(results.begin(), results.end()) << endl;
	}

	return 0;
}

void naive_max_gain(const int &E, const int e, const int &R, const int g,
		vector<int> &res, const vector<int> v, const unsigned int k)
{
	assert(k < v.size());

	if (v.size()-1 == k)
	{
		for (int i = 0; i <= e; i++)
		{
			// printf("\t[%d, %d, %d, %d, %d]\n", -1, i, k, v[k], v[k]*i);
			res.push_back(g+v[k]*i);
		}
	}
	else
	{
		// for all the possible energy which can be used
		for (int i = 0; i <= e; i++)
		{
			int energy = min(E, e-i+R); // energy after activity
			// printf("[%d, %d, %d, %d, %d]\n", energy, i, k, v[k], v[k]*i);
			naive_max_gain(E, energy, R, g+v[k]*i, res, v, k+1);
		}
	}
}




