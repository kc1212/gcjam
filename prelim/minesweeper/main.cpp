/*
growing the non-mine region
always add two cells when growing from the edge
add one cell when not growing from the edge
example:

. .
c .

. . .
c . .

. .
. . .
c . .

. . .
. . .
c . .

. . .
. . . .
c . . .

. .
. . .
. . . .
c . . .

. . .
. . .
. . . .
c . . .

. . .
. . . .
. . . .
c . . .

*/
#include <iostream>
#include <vector>

using namespace std;

void print_board(vector< vector<char> > board);
bool find_soln(int r, int c, int m, vector< vector<char> >& board);

enum { VERTICAL, HORIZONTAL };

int main(void)
{
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int R, C, M;
		cin >> R >> C >> M;
		vector<char> row(C, '*');
		vector< vector<char> > board(R, row);

		cout << "Case " << i+1 << ":\n";
		if ( find_soln(R, C, M, board) )
		{
			print_board(board);
		}
		else
		{
			cout << "Impossible" << endl;
		}



	}
	return 0;

}

// C++11
void print_board(vector< vector<char> > board)
{
	for (auto v : board)
	{
		for (auto e : v)
		{
			cout << e;
		}
		cout << endl;
	
	}
}


bool find_soln(int r, int c, int m, vector< vector<char> >& board)
{
	// assume there are always mines
	if (m >= r*c)
	{
		return false;
	}

	// case for a single row or column
	if (r == 1 || c == 1)
	{
		std::vector<int>::size_type len;
		len = board[0].size();
		for (int i = 0; i < r*c-m; i++)
		{
			if (r == 1)
				board[0][i] = '.';
			else if (c == 1)
				board[i][0] = '.';
		}

		board[0][0] = 'c';
		return true;
	}

	// more rows than col then direction = true, else false
	const unsigned direction = r > c ? VERTICAL : HORIZONTAL;

	return true;
}







