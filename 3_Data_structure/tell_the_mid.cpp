/* backjoon problem 1655 */
/* priority queue, min heap, max heap */

#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

priority_queue <int, vector<int>, less<int>> maxh;
priority_queue <int, vector<int>, greater<int>> minh;

int main() {
	int N, cur,tmp1, tmp2;

	scanf("%d", &N);
	scanf("%d", &cur);
	printf("%d\n", cur);
	N--;

	while (N--) {
		int input;
		scanf("%d", &input);

		if (cur <= input) minh.push(input);
		else maxh.push(input);

		tmp1 = maxh.size() - minh.size();
		tmp2 = minh.size() - maxh.size();
		if (tmp1 > 0) {
			if (tmp1 == 2 || (tmp1 == 1 && maxh.top() < cur)) {
				minh.push(cur);
				cur = maxh.top();
				maxh.pop();
			}
		} else if (tmp2 > 0) {
			if (tmp2 == 2 || (tmp2 == 1 && minh.top() < cur)) {
				maxh.push(cur);
				cur = minh.top();
				minh.pop();
			}
		}
		printf("%d\n", cur);
	
	}
	return 0;
}
