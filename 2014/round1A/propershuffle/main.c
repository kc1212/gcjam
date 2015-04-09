#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

void algo(int a[], const int N, const int good);
int score(int a[], const int N);
void swap(int* a, int* b);

void algo(int a[], const int N, const int good)
{
	for (int k = 0; k < N; k++)
		a[k] = k;

	for (int k = 0; k < N; k++) {
		int p = good ? rand() % (N-k) + k : rand() % N;
		swap(&a[k], &a[p]);
	}

}

int score(int a[], const int N)
{
	int score = 0;
	for (int k = 0; k < N; k++) {
		if (a[k] >= k)
			score++;
	}
	return score;
}

void swap(int* a, int* b)
{
	int tmp = *b;
	*b = *a;
	*a = tmp;
}

int main(void)
{
	int cutoff = 0, T = 0, N = 1000, Tries = 1000;
	int a[N];
	srand(time(NULL));
	scanf("%d", &T);
	assert(T == 120);

	int tot_score = 0;
	for (int i = 0; i < Tries; i++) {
		algo(a, N, 0); // bad algorithm
		tot_score += score(a,N);
	}
	cutoff = (double)tot_score / Tries;
	assert(cutoff == 528);

	for (int i = 0; i < T; i++) {
		int tmp;
		scanf("%d", &tmp);
		assert(tmp == N);

		for (int j = 0; j < N; j++)
			scanf("%d", a+i);

		printf("Case #%d: ", i+1);
		// algo(a, N, 1);
		// printf("%f - %f\n", (double)score(a,N), (cutoff + 500) / 2.0);
		if (score(a,N) > (cutoff + 500) / 2.0 )
			printf("BAD\n");
		else
			printf("GOOD\n");
	}

	return 0;
}



