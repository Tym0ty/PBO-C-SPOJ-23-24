#include <set>
#include <cstdio>
using namespace std;
#define gc getchar_unlocked
set<int> set_int;

void Get ( int &ret ){
	ret = 0; char inp=gc(); int kl=1;
	while (inp<'0' || inp>'9'){
		if(inp=='-') kl=-1; inp=gc();}
	while('0'<=inp && inp <= '9')
		ret = (ret<<3) + (ret<<1) + (int)(inp-'0'), inp = gc();
		if (kl < 1) ret =-ret;
}

int main() {
    int tmp, tests;
    Get(tests);

    while(tests--) {
        Get(tmp);

        if (set_int.count(tmp) == 0) {
        	printf("No ");
            set_int.insert(tmp);
            printf("%d\n", set_int.size());
        } else {
            printf("Yes ");
            printf("%d\n", set_int.size());
        }
    }

    return 0;
}
