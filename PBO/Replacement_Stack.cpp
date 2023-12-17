#include <stack>
#include <vector>
#include <set>
#include <cstdio>
using namespace std;
#define gc getchar_unlocked

void Get ( int &ret ){
	ret = 0; char inp=gc(); int kl=1;
	while (inp<'0' || inp>'9'){
		if(inp=='-') kl=-1; inp=gc();}
	while('0'<=inp && inp <= '9')
		ret = (ret<<3) + (ret<<1) + (int)(inp-'0'), inp = gc();
		if (kl < 1) ret =-ret;
}

int main() {
    int n;
    Get(n);
    
    vector<int> sequence(n);
    vector<int> res(n, 0);
    stack<int> s;

    for (int i = 0; i < n; i++) {
        Get(sequence[i]);
    }

    for (int i = 0; i < n; i++) {
        while (!s.empty() && sequence[i] > sequence[s.top()]) {
            res[s.top()] = sequence[i];
            s.pop();
        }
        s.push(i);
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", res[i]);
    }
    
    return 0;
}
