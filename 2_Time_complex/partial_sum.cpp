/* backjoon problem 1806 */
/* partial sum */

#include <cstdio>

using namespace std;

#define INF 1000000000
int arr[10000];

int main(void) {
	int N, S;
	int sum = 0, ans = INF;
	int s = -1, e = -1;

	scanf("%d %d", &N, &S);
	for (int i = 0; i < N; ++i) scanf("%d", arr + i);

	while (e < N) {
		if (sum < S) {
			++e;
			sum += arr[e];
		} else {
			if (e - s + 1 < ans) ans = e - s + 1;
			sum -= arr[s];
			++s;
		}
	}

	if (ans == INF) ans = 0;
	printf("%d\n", ans);

	return 0;
}
