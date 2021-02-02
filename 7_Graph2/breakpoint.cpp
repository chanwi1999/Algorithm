/* backjoon problem 11266 */
/* Graphs breakpoint algorithm */

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int v, e;
vector<int> adjList[10005];
int visit[10005];
bool isCut[10005];
int num = 0;

int dfs(int cur, bool isRoot) {
	
	visit[cur] = ++num;
	int ret = visit[cur];
	int child_cnt = 0;

	for (int i=0; i<adjList[cur].size(); i++) {
		int next = adjList[cur][i];

		if (visit[next]) {
			ret = min(ret, visit[next]);
			continue;
		}
		child_cnt++;

		int minimum = dfs(next, false);
		if (!isRoot && minimum >= visit[cur]) {
			isCut[cur] = true;
		}
		ret = min(ret, minimum);
	}
	if (isRoot) isCut[cur] = child_cnt > 1;
	

	return ret;
}

int main() {

	scanf("%d %d", &v, &e);

	for (int i=0; i<e; i++) {
		int from, to;

		scanf("%d %d", &from, &to);
		adjList[from].push_back(to);
		adjList[to].push_back(from);
	}

	for (int i=1; i<=v; i++) { 
		if (visit[i]) continue;
		dfs(i, true);
	}

	int cnt = 0;
	for (int i=1; i<=v; i++) {
		if (isCut[i]) cnt++;
	}
	printf("%d\n", cnt);
	for (int i=1; i<=v; i++) {
		if (isCut[i]) printf("%d ", i);
	}
	printf("\n");

	return 0;
}
