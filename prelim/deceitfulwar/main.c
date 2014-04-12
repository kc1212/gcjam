#include <stdio.h>
#include <stdlib.h>

int choose_block(double* w, int n, double b);
int war(double* w1, double* w2, int n);

int main(void)
{
	int i, j = 0;
	int T;
	scanf("%d", &T);

	for (i = 0; i < T; i++)
	{
		int N;
		scanf("%d", &N);

		double* w1 = (double*)malloc(N*sizeof(double));
		double* w2 = (double*)malloc(N*sizeof(double));

		for (j = 0; j < N; j++)
		{
			scanf("%lf", w1+j);
		}

		for (j = 0; j < N; j++)
		{
			scanf("%lf", w2+j);
		}

		int score = war(w1, w2, N);
		printf("%d\n", score);

		free(w1);
		free(w2);

	}
	return 0;
}


int war(double* w1, double* w2, int n)
{
	int i, score = 0;
	for (i = 0; i < n; i++)
	{
		int j = choose_block(w2, n, w1[i]);
		score += w1[i] > w2[j] ? 1 : 0;
		w1[i] = -1; w2[j] = -1;
	}
	return score;
}

int choose_block(double* w, int n, double b)
{
	// returns index of the choosen block
	// block should have the greatest difference
	double diff = -1.0;
	int ctr = -1;
	int i;
	for (i = 0; i < n, w[i] > 0.0; i++)
	{
		double tmp = w[i] - b;
		if (diff > tmp)
		{
			diff = tmp;
			ctr = i;
		}
	}
	return ctr;
}


