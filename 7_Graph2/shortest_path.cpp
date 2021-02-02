/* backjoon problem 1753 */
/* Dijkstra algorithm - timeover! */

#include <cstdio>
#include <vector>

using namespace std;

#define INF 1e9
int v, e, k;
bool visited[100001];
int D[100001];
vector<pair<int, int>> graph[100001];

int getSmallestNode() {
	int min = INF;
	int idx = 0;

	for (int i=0; i<=v; i++) {
		if (D[i] < min && !visited[i]) {
			min = D[i];
			idx = i;
		}
	}

	return idx;
}

void dijkstra(int start) {
	D[start] = 0;
	visited[start] = true;

	for (int i=0; i<graph[start].size(); i++) {
		int idx = graph[start][i].first;
		D[idx] = graph[start][i].second;
	}

	for (int i=0; i<v-1; i++) {
		int cur = getSmallestNode();
		visited[cur] = true;

		for (int j=0; j<graph[cur].size(); j++) {
			int weight = D[cur] + graph[cur][j].second;
			if (weight < D[graph[cur][j].first]) D[graph[cur][j].first] = weight;
		}
	}
}

int main() {
	
	scanf("%d %d", &v, &e);
	scanf("%d", &k);

	for (int i=0; i<e; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		graph[u].push_back({v, w});
	}

	fill_n(D, 100001, INF);

	dijkstra(k);

	for (int i=1; i<=v; i++) {
		if (i == k) printf("0\n");
		else if (D[i] == INF) printf("INF\n");
		else printf("%d\n", D[i]);
	}

	return 0;
}
