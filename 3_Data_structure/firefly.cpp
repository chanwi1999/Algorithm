/* backjoon problem */

#include <cstdio>

#define MAX_N		100000
#define SZ_TR		1048576
int OFFSET, tree[SZ_TR];

void init(int N) {
	for (OFFSET=1; OFFSET<=N; OFFSET*=2);
}

void update(int from, int to) {
	from += OFFSET, to += OFFSET;

	while (from <= to) {
		if (from%2 == 1) ++tree[from++];
		if (to%2 == 0) ++tree[to--];

		from /= 2, to /= 2;
	}
}

int query(int idx) {
	int ret = 0;
	idx += OFFSET;

	while (idx > 0) {
		ret += tree[idx];
		idx /= 2;
	}

	return ret;
}

int main() {

	int N, M, i, h, sum = 0;
	int ans, cnt;

	scanf("%d %d", &N, &M);

	init(M);

	for (i=0; i<N; i++) {
		scanf("%d", &h);
		if (i%2 == 1) ++tree[M-h+1];
		else ++tree[1], --tree[h+1];
	}

	ans = N+1, cnt = 0;

	for (h=1; h<=M; ++h) {
		sum += tree[h];
		if (sum < ans) {
			ans = sum;
			cnt = 1;
		}
		else if (sum == ans) ++cnt;
	}

	printf("%d %d\n", ans, cnt);

	return 0;
}
