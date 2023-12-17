#include <iostream>
using namespace std;
const long long int MOD = 1000000007;

long long fast_pow(long long base, long long n, long long M) {
    if(n==0)
        return 1;
    if(n==1)
    return base;
    long long halfn=fast_pow(base,n/2,M);
    if(n%2==0)
        return ( halfn * halfn ) % M;
    else
        return ( ( ( halfn * halfn ) % M ) * base ) % M;
}

long long findMMI_fermat(long long n,long long M) {
    return fast_pow(n,M-2,M);
}

long long factorial[1000009];

int main(int argc, char const *argv[]) {
	factorial[0] = 1;
    for (long long i=1; i<1000009; i++) {
        factorial[i] = (factorial[i-1] * i) % MOD;
    }
	
    int itr;
    scanf("%d", &itr);

    while (itr--) {
        int m, n;
    	scanf("%d %d", &m, &n);

        int l = m - n;
        
        if (l+1 < n) {
            printf("0\n");
            continue;
        }

        long long x = factorial[l];

        long long y = findMMI_fermat(factorial[l + 1 - n], MOD);
        y = (factorial[l + 1] * y) % MOD;
		
		long long hasil = x * y % MOD;
		
        printf("%lld\n", hasil);
}
    return 0;
}

