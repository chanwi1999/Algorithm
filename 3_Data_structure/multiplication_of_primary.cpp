/* backjoon problem 2014 */
/* priority queue */

#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

priority_queue<ll> pq;
vector<int> primes;

int main() {
	pq.push(-1);

	while(!pq.empty()) {
		ll cur = pq.top();
		pq.pop();

		for (int i = 0; i < primes.size(); ++i) pq.push(cur * primes[i]);
	}

	return 0;
}
