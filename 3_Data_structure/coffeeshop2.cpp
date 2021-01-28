/* indexed tree */

#include <cstdio>

#define MAX_N		1000000
#define SZ_TR		262144

int OFFSET, tree[SZ_TR];
int nos[MAX_N + 1];

int min(int a, int b) { return (a < b) ? a : b; }

void init(int N) {
	int i;

	for (OFFSET = 1; OFFSET <= N; OFFSET *= 2);
	for (i = 1; i <= N; ++i) tree[OFFSET + i] = nos[i];
	tree[OFFSET] = 0;
	for (i = N + 1; i < OFFSET; ++i) tree[OFFSET + i] = 0;
	for (i = OFFSET - 1; i > 0; --i) tree[i] = min(tree[i * 2], tree[i * 2 + 1]);
}

int query(int from, int to) { // interval update
	int res = 0;
	from += OFFSET, to += OFFSET;

	while (from <= to) {
		if (from % 2 == 1) res += tree[from++];
		if (to % 2 == 0) res += tree[to--];
		from /= 2, to /= 2;
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

void update(int idx, int val) { // one node update
	idx += OFFSET;
	tree[idx] = val;

	idx /= 2;
	while (idx > 0) {
		tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
		idx /= 2;
	}
}

int main(void) {
	int N, M, K, i;

	scanf("%d %d %d", &N, &M, &K);
	for (i = 1; i <= N; ++i) scanf("%d", nos + i);
	init(1, 1, N);
}
