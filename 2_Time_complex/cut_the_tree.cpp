/* backjoon problem 2805 */
/* binary search */

#include <cstdio>

using namespace std;

long long tree[1000001];

int main(void) {

	int N, M;
	int high = 0, low = 0;
	long long ans = 0;

	scanf("%d", &N);
	scanf("%d", &M);

	for (int i = 0; i < N; i++) {
		scanf("%lli", &tree[i]);

		if (high < tree[i]) high = tree[i];
	}

	while (low <= high) {
		long long mid = (low+high)/2;
		long long sum = 0;

		for (int i = 0; i < N; i++) {
			if (mid < tree[i]) sum += tree[i] - mid;
		}

		if (sum >= M) {
			if (ans < mid) ans = mid;
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}

	printf("%lli\n", ans);

	return 0;
}
