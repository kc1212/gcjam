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
	for( vector< vector<char> >::iterator i = board.begin(); i != board.end(); ++i)
	{
		for( vector<char>::iterator j = i->begin(); j != i->end(); ++j)
		{
			cout << *j;
		}
		cout << endl;
	}
}


bool find_soln(const int r, const int c, const int m, vector< vector<char> >& board)
{
	// assume there are always mines
	const int n = r*c - m;
	// cout << n << ", " << r << ", " << c << endl;

	// more mines than cells
	if (m >= r*c)
		return false;

	// case for a single row or column
	if (r == 1 || c == 1)
	{
		std::vector<int>::size_type len;
		len = board[0].size();
		for (int i = 0; i < r*c-m; i++)
		{
			if (r == 1)
				board[0][i] = '.';
			else
				board[i][0] = '.';
		}
		board[0][0] = 'c';
		return true;
	}

	// n less than 4
	if (n%2==0 && n < 4)
		return false;

	// n is odd and less than 9
	if (n%2!=0 && n<9 && r<=3 && c<=3) // odd
		return false;

	// if we can't fill two rows...
	if (n/r < 2 && n%2==0) // even
	{
		fill_n(board[0].begin(), n/2, '.');
		fill_n(board[1].begin(), n/2, '.');
	}
	else if ((n-3)/r < 2 && n%2!=0) // odd
	{
		fill_n(board[0].begin(), n/2, '.');
		fill_n(board[0].begin(), (n-3)/2, '.');
		fill_n(board[1].begin(), (n-3)/2, '.');
		fill_n(board[2].begin(), 3, '.');
	}
	// otherwise...
	else
	{
		int i;
		for (i = 0; i < n/c; i++)
		{
			fill(board[i].begin(), board[i].end(), '.');
		}
		// if there is one extra non-mine cell
		if ( n%c == 1 )
		{
			board[i][0] = '.';
			board[i][1] = '.';
			board[i-1][c-1] = '*';
		}
		else
		{
			fill_n(board[i].begin(), n%c, '.');
		}
	}
	
	board[0][0] = 'c';
	return true;
}





