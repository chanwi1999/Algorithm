/* backjoon problem 5719 */
/* Dijkstra algorithm, BFS - wrong */

#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
#include <queue>

using namespace std;

int n, m, u, v, p, start, dest;
int adjMat[505][505];
int D[505];

void getShortestPath() {
	memset(D, -1, sizeof(D));
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start));

	while (!pq.empty()) {
		auto temp = pq.top(); pq.pop();
		int cur = temp.second;
		int weight = temp.first;

		if (D[cur] != 1) continue;
		D[cur] = weight;
		for (int i=0; i<n; i++) { // i means next
			if (adjMat[cur][i] == -1) continue;
			if (D[cur] != -1) continue;
			pq.push(make_pair(weight+adjMat[cur][i], i));
		}
	}
}

void removeShortestPath() {	
	queue<int> q;
	q.push(dest);

	while (q.size()) {
		int tmp = q.front(); q.pop();

		for (int i=0; i<n; i++) { // i means prev
			if (adjMat[i][tmp] == -1) continue;
			if (D[tmp] == D[i]+adjMat[i][tmp]) { // shortestpath
				adjMat[i][tmp] = -1;
				q.push(i);
			}
		}
	}
}

int main() {
	
	int ans[100001];
	int cnt = 0;

	while (1) {
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0) break;

		memset(adjMat, -1, sizeof(adjMat)); // init -1; no way

		scanf("%d %d", &start, &dest);
		
		for (int i=0; i<m; i++) {
			scanf("%d %d %d", &u, &v, &p);
			adjMat[u][v] = p;
		}

		getShortestPath();
		removeShortestPath();
		getShortestPath();

		ans[cnt++] = D[dest];
	}

	for (int i=0; i<cnt; i++) printf("%d\n", ans[i]);

	return 0;
}
