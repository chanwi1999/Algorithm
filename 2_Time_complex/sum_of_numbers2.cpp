/* backjoon problem 2003 */
/* two pointer algorithm */

#include <cstdio>

using namespace std;

int arr[10000];

int main(void) {

	int N, M, high, low, sum;
	int cnt = 0;

	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; ++i) scanf("%d", arr+i);
	
	sum = arr[0];
	high = low = 0;

	while(low <= high && high < N) {
        if (sum < M) sum += arr[++high];
        else if (sum == M) {
            cnt++;
            sum += arr[++high];
        }else {
            sum -= arr[low++];
            if (low > high && low < N) {
                high = low;
                sum = arr[low];
            }
        }
    }

	printf("%d\n", cnt);

	return 0;
}
