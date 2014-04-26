#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

void print_v(vector<string> v);
bool check(vector<string> &v_init, vector<string> &v_dev);
int naive(const int L, const int N, vector<string> &v_init, const vector<string> &v_dev);
void naive_comb(string head, string tail, vector<string> &v);

int main(void)
{
	int T;
	cin >> T;

	for (int i = 1; i <= T; i++)
	{
		int N, L;
		cin >> N >> L;

		vector<string> v_init, v_dev;

		for (int j = 0; j < N; j++)
		{
			string bits;
			cin >> bits;
			v_init.push_back(bits);
		}

		for (int j = 0; j < N; j++)
		{
			string bits;
			cin >> bits;
			v_dev.push_back(bits);
		}
		check(v_init, v_dev);
		naive(L, N, v_init, v_dev);

		
	}
	return 0;
}


void print_v(vector<string> v)
{
	for (vector<string>::iterator i = v.begin(); i != v.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;
}


int naive(const int L, const int N, vector<string> &v_init, const vector<string> &v_dev)
{
	vector<string> v;
	string s("");
	for (int i = 0; i < L; i++)
	{
		s += 48+i;
	}
	cout << s << endl;
	naive_comb("", s, v);

	// TODO need sorting function..
	// sort(v.begin(), v.end());

	// TODO i give up...
	// for (int i = 0; i < v.size(); i++)
	// {
	// 	vector<string> tmp = v_init;
	// 	for (int j = 0; j < tmp.size(); j++)
	// 	{
	// 		tmp[j][v[i]-48] = tmp[j][v[i]] == '1' ? '0' : '1';
	// 	}
	// }

	print_v(v);
}

void naive_comb(string head, string tail, vector<string> &v)
{
	if (tail.size() == 0)
	{
		v.push_back(head);
	}
	else
	{
		naive_comb(head, tail.substr(1), v);
		naive_comb(head + tail[0], tail.substr(1), v);
	}
}


bool check(vector<string> &v_init, vector<string> &v_dev)
{
	vector<string> tmp = v_init;
	unsigned int ctr = 0;

	sort(v_init.begin(), v_init.end());
	sort(v_dev.begin(), v_dev.end());

	vector<string>::iterator ii = v_init.begin();
	vector<string>::iterator i = v_dev.begin();
	for ( ; i != v_dev.end() && ii != v_init.end(); i++, ii++)
	{
		if (*i != *ii)
		{
			return false;
		}
	}
	// cout << "ok " << endl;
	return true;

	// for (vector<string>::const_iterator i = v_dev.begin(); i != v_dev.end(); i++)
	// {
	// 	for (vector<string>::iterator j = tmp.begin(); j != tmp.end(); j++)
	// 	{
	// 		if (*j == *i)
	// 		{
	// 			ctr++;
	// 			tmp.erase(j);
	// 			break;
	// 		}
	// 	}
	// }
	// cout << ctr << endl;
	// return ctr == v_init.size() ? true : false;
}




