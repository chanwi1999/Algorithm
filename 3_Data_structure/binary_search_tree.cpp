/* backjoon problem 5639 */
/* binary search tree */

#include <cstdio>
#include <stack>

using namespace std;

int nos[1000], ans[1000];

void search(int srchF, int srchT, int ansF, int ansT) {
	ans[ansT] = nos[srchF];
	int i = srchF + 1;
	
	while (i <= srchT && nos[i] < nos[srchF]) ++i;
	--i;

	if (i > srchF) search(srchF + 1, i, ansF, ansF + i - srchF -1);
	if (i < srchT) search(i + 1, srchT, ansF + i - srchF, ansT -1);
}

int main(){ // time over
	char ins[1000];
	stack<int> stk;
	int i = -1;
	bool flag = true;

	int N = 0, n;
	while (~scanf("%d", &n)) nos[N++] = n;

	search(0, N - 1, 0, N - 1);

	while (ans[++i] > 0) printf("%d", ans[++i]);
}
