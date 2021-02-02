/* backjoon problem 1854 */
/* - wrong */

#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
#include <stack>

using namespace std;
int n, m, k;
stack<int> kth[1005];
vector<vector<pair<int, int>>> adjList;

void func() { // the value input in kth stack array
	
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, 1));

	while (1) {
		int cur = pq.top().second;
		int cost = pq.top().first;
		pq.pop();

		// if k is not input in stack[cur], then you not founded the kth shortest path not yet
		if (kth[cur].size() < k) kth[cur].push(cost);
		else continue; // already found the kth shortest path

		for (auto i:adjList[cur]) {
			int next = i.first;
			int next_cost = cost + i.second;
			if(kth[next].size() < k) {
				pq.push(make_pair(next_cost, next));
			}
		}
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	adjList.resize(n + 5);
	for (int i=0; i<m; i++) {
		int from, to, cost;
		scanf("%d %d %d", &from, &to, &cost);
		adjList[from].push_back({to, cost});
	}

	for (int i=1; i<=n; i++) {
		if (kth[i].size() < k) printf("-1\n");
		else printf("%d\n", kth[i].top());
		// printf("%d\n", kth[i][k-1]);
	}

	return 0;
}
