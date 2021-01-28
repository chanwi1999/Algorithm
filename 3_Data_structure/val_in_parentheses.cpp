/* backjoon problem 2504 */
/* stack */

#include <cstdio>
#include <stack>

using namespace std;

int main(){
	char ins[1000];
	stack<int> stk;
	int i = -1;
	bool flag = true;

	scanf("%s", ins);

	while(ins[++i] != '\0') {
		if (ins[i] == '(') stk.push(-2);
		else if (ins[i] == '[') stk.push(-3);
		else if (ins[i] == ')') {
			int t = 0;
			while (!stk.empty() && stk.top() > 0) t += stk.top(), stk.pop();
			if (t == 0) t = 1;
			if (!stk.empty() && stk.top() == -2) stk.pop(), stk.push(t *= 2);
			else {
				flag = false;
				break;	
			}
		}
		else {
			int t = 0;
            while (!stk.empty() && stk.top() > 0) t += stk.top(), stk.pop();
            if (t == 0) t = 1;
            if (!stk.empty() && stk.top() == -3) stk.pop(), stk.push(t *= 3);
            else {
                flag = false;
                break;
            }
		}
	}

	int t = 0;
	if (flag) {
		while (!stk.empty()) {
			if (stk.top() > 0) {
				t += stk.top(), stk.pop();
			} else {
				flag = false;
				t = 0;
				break;
			}
		}
	}

	printf("%d\n", t);
}
