#include <stack>
#include <vector>
#include <set>
#include <cstdio>
using namespace std;
#define gc getchar_unlocked

#define MAX 100001

set<int> s;
set<int>::iterator it;

int sequence[MAX], res[MAX];

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
    
    for (int i = 0; i < n; i++) {
        Get(sequence[i]);
    }

    for (int i = n - 1; i >= 0; i--) {
        s.insert(sequence[i]);
        it = s.find(sequence[i]);
        s.erase(s.begin(), it);
        it++;
        if (it == s.end())
            res[i] = 0;
        else
            res[i] = *it;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", res[i]);
    }
    
    return 0;
}
