/* backjoon problem 2748 */
/* dynamic programming: if you use recursive call, then time over! */

#include <cstdio>

using namespace std;

long long dp[90]; // memorization

long long fibonacci(int n) {
	
	if (n == 0) return 0;
	else if (n == 1) return 1;
	else if (dp[n] != 0) return dp[n]; // check the memorization
	else dp[n] = fibonacci(n-1) + fibonacci(n-2);
	
	return dp[n];
}

int main(void) {
	
	int n;

	scanf("%d", &n);
	printf("%lld\n", fibonacci(n));

	return 0;
}
