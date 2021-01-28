/* backjoon problem 2042 */
/* indexed tree */

#include <cstdio>

#define MAX_N		1000000
#define SZ_TR		262144
#define INF			1000000001

int OFFSET, tree[SZ_TR];
int nos[MAX_N + 1];

int min(int a, int b) { return (a < b) ? a : b; }

void init(int N) {
	int i;

	for (OFFSET = 1; OFFSET <= N; OFFSET *= 2);
	for (i = 1; i <= N; ++i)
		tree[OFFSET + i] = nos[i];
	
	tree[OFFSET] = INF;
	
	for (i = N + 1; i < OFFSET; ++i)
		tree[OFFSET + i] = INF;
	for (i = OFFSET - 1; i > 0; --i)
		tree[i] = min(tree[i * 2], tree[i * 2 + 1]);
}

int query(int from, int to) { // interval update
	int res = INF;
	from += OFFSET, to += OFFSET;

	while (from <= to) {
		if (from % 2 == 1)
			res += min(res, tree[from++]);
		if (to % 2 == 0)
			res += min(res, tree[to--]);

		from /= 2, to /= 2;
	}

	return res;
}

void update(int idx, int val) { // one node update
	idx += OFFSET;
	tree[idx] = val;

	idx /= 2;

	while (idx > 0) {
		tree[idx] = min(tree[idx * 2], tree[idx * 2 + 1]);
		idx /= 2;
	}
}

int main(void) {
	int N, M, K, i;

	scanf("%d %d %d", &N, &M, &K);
	for (i = 1; i <= N; ++i) scanf("%d", nos + i);
	init(1, 1, N);
}
