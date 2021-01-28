/* backjoon problem 1572 */
/* indexed tree find K-th */

#include <cstdio>

#define MAX_N		1000000
#define SZ_TR		262144

int OFFSET, tree[SZ_TR];
int nos[MAX_N + 1];

int min(int a, int b) { return (a < b) ? a : b; }

/*
void init(int N) {
	for (int i=1; i <=1; i++)
}
*/

int query(int idx) { // interval update
	int res = 0;

	while (idx > 0) {
		res += tree[idx];
		idx -= idx & (-idx);
	}

	return res;
}

int findKth(int kth) { // top-down
	int idx = 1, left, right;

	while (idx < OFFSET) {
		left = idx * 2, right = left + 1;
		if (tree[left] >= kth) idx = left;
		else kth -= tree[left], idx = right;
	}

	return idx - OFFSET;
}

void update(int idx, int add) { // one node update
	idx += OFFSET;

	idx /= 2;
	while (idx > 0) {
		tree[idx] += add;
		idx += idx & (-idx);
	}
}

int main(void) {
	int i, N, K, kth;
	int ans = 0;

	scanf("%d %d", &N, &K);

	kth = (N+1) / 2;
	for (i=0; i<K; i++) {
		scanf("%d", nos + i);
		update(nos[i], 1);
	}

	ans = findKth(kth);

	for (i=K; i<N; i++) {
		scanf("%d", nos + i);
		update(nos[i], 1);
		update(nos[i-K], -1);
		ans += findKth(kth);
	}

	printf("%d\n", ans);

	return 0;
}
