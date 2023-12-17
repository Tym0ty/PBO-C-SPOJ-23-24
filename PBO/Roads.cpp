#include <cstdio>
#include <vector>
using namespace std;
#define rep(i,n) for(int (i)=0; (i)<(int)(n); ++(i))
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef long long ll;
template <typename T, typename U> static void MIN (T &x, U y) {if (y < x) x = y; }

class UnionFind {
	vector<int> data;
	public :
	void init (int n){data.assign(n, -1); }
	bool unionSet(int x, int y){
		x = root(x); y = root(y);
		if (x != y){
			if (data[y] < data[x]) swap(x,y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool findset(int x, int y) {return root(x) == root(y); }
	int root(int x){ return data[x] < 0 ? x : data[x] = root(data[x]); }
	int size(int x){ return -data[root(x)]; }
};

void Get ( int &ret ){
	ret = 0; 
	char inp = getchar_unlocked();
	while (inp<'0' || inp>'9') inp = getchar_unlocked();
	while('0'<=inp && inp <= '9'){
		ret = (ret<<3) + (ret<<1) + (int)(inp-'0'); 
		inp = getchar();
	}
}

int main(){
	int T;
	Get(T);
	for (int ii = 0; ii < T; ++ii){
		int n; int m; int clib; int croad;
		Get(n); Get(m); Get(clib); Get(croad);
		UnionFind DSU; DSU.init(n);
		rep (i, m){
			int u; int v;
			Get(u); Get(v);
			--u; --v;
			DSU.unionSet(u, v);
		}
		int ccs = 0;
		rep (i, n)
			ccs += DSU.root(i) == i;
		ll ans = INFL;
		for (int i = ccs; i <=n; ++i)
			MIN(ans, (ll)clib * i + (ll)croad * (n - i));
		printf("%lld\n", ans);
	}
	return 0;
}