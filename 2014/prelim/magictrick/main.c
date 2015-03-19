#include <stdio.h>
#include <stdlib.h>

#define BAD_MAGICIAN -1
#define BAD_VOLUNTEER -2

void print_table(int table[][4]);
int get_game_result(int t1[], int t2[]);

int main(void)
{
	int i, j, k = 0;
	int T, row1, row2;
	int table1[4][4] = {};
	int table2[4][4] = {};
	int result;

	scanf("%d", &T);

	for (i = 0; i < T; i++)
	{
		scanf("%d", &row1);

		// load table1
		for (j = 0; j < 4; j++)
		{
			for (k = 0; k < 4; k++)
			{
				scanf("%d", &table1[j][k]);
			}
		}

		scanf("%d", &row2);

		// load table2
		for (j = 0; j < 4; j++)
		{
			for (k = 0; k < 4; k++)
			{
				scanf("%d", &table2[j][k]);
			}
		}

		result = get_game_result(table1[row1-1], table2[row2-1]);
		switch(result)
		{
			case BAD_MAGICIAN:
				printf("Case #%d: Bad magician!\n", i+1);
				break;
			case BAD_VOLUNTEER:
				printf("Case #%d: Volunteer cheated!\n", i+1);
				break;
			default:
				printf("Case #%d: %d\n", i+1, result);
				break;
		}
	}

	return 0;
}


int get_game_result(int t1[], int t2[])
{
	int i, j = 0;
	int matched_counter = 0;
	int matched_number = 0;

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (t1[i] == t2[j])
			{
				matched_counter++;
				matched_number = t1[i];
			}
		}
	}

	if (matched_counter > 1)
		return BAD_MAGICIAN;

	if (matched_counter == 0)
		return BAD_VOLUNTEER;

	return matched_number;
}


