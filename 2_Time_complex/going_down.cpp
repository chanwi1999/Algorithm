/* backjoon problem 2096 */
/* dynamic programing : if every input save, then memory lack! */

#include <cstdio>

using namespace std;

#define MAX_N 100000

int main(void) {
	int N;
	int input[3], maxdp[3], mindp[3];
	
	scanf("%d", &N);
	scanf("%d %d %d", maxdp, maxdp+1, maxdp+2);
	maxdp[0] = mindp[0];
	maxdp[1] = mindp[1];
	maxdp[2] = mindp[2];

	for (int i = 0; i < N; ++i) {
		scanf("%d %d %d", input, input+1, input+2);
	}

	return 0;
}
