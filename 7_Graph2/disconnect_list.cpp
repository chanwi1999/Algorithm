/* backjoon problem 11400 */

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int dfs(int cur, int prev) {
    visit[cur] = ++num;
    int ret = visit[cur];

    for (int next : adjList[cur]) {
        if (next == prev) continue;
        if (visit[next]) {
            ret = min(ret, visit[next]);
            continue;
        }
        int minimum = dfs(next, cur);
        if (minimum > visit[cur]) list.push_back(cur, next);
        ret = min(ret, minimum);
    }

    return ret;
}

int main() {
	return 0;
}
