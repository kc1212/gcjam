#include <iostream>
#include <vector>

using namespace std;

void print_board(vector< vector<char> > board);
bool find_soln(int r, int c, int m, vector< vector<char> >& board);

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

		cout << "Case #" << i+1 << ":\n";
		// cout << "r:" << R << " c:" << C << " m:" << M << endl;
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

	// more mines than cells
	if (m >= r*c)
		return false;

	// case for a single row or column
	else if (r == 1 || c == 1)
	{
		vector<int>::size_type len;
		len = board[0].size();
		for (int i = 0; i < r*c-m; i++)
		{
			if (r == 1)
				board[0][i] = '.';
			else
				board[i][0] = '.';
		}
	}

	// one non-mine, do nothing
	else if (n == 1) {}

	// n less than 4
	else if (n<4)
		return false;

	// n is odd and has either two rows or two columns
	else if (n%2!=0 && (r==2 || c==2)) // odd
		return false;

	// TODO almost there.. check case 52
	// n is odd and can't be filled in two rows
	// else if (n/c < 2 && n%2!=0)
		// return false;

	// one mine
	else if (m == 1)
	{
		vector<char> tmp(c, '.');
		fill(board.begin(), board.end(), tmp);
		board[r-1][c-1] = '*';
	}
	// if we can't fill two rows...
	else if (n/c < 2 && n%2==0) // even
	{
		fill_n(board[0].begin(), n/2, '.');
		fill_n(board[1].begin(), n/2, '.');
	}
	// else if ((n-3)/r < 2 && n%2!=0) // odd
	else if ((n-3)/c < 2 && n%2!=0) // odd
	{
		fill_n(board[0].begin(), (n-3)/2, '.');
		fill_n(board[1].begin(), (n-3)/2, '.');
		fill_n(board[2].begin(), 3, '.');
	}
	// we have fill more than two rows of non-mines
	else if (n/c >= 2)
	{
		int i;
		for (i = 0; i < n/c; i++)
		{
			fill(board[i].begin(), board[i].end(), '.');
		}
		// if there is one extra non-mine cell
		if (n%c == 1)
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
	else
	{
		cout << "ERROR!!" << endl;
	}
	
	board[0][0] = 'c';
	return true;
}





