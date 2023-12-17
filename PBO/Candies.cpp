#include <stdio.h>
#include <queue>
#include <functional>
using namespace std;
#define gc getchar_unlocked
#define ll long long

template <typename T> void getNum(T &val){
	char ch; bool bo=0; val=0;
	for(ch=gc(); ch<'0'||'9'<ch;ch=gc()) if(ch=='-') bo =1;
	for(;'0'<=ch && ch<='9'; val=(val<<3)+(val<<1)+ch-48, ch=gc());
	if(bo) val=-val;
}

int main(){
	int t, n, k;
	
	getNum<int>(t);
	int y = 0;
	for(int i = 0; i < t; i++){
		getNum<int>(n);
		getNum<int>(k);
		deque <int> dq;
		int arr[n];
		
		for (int j = 0; j < n; j++){
			int x;
			getNum<int>(x);	
			arr[j] = x;	
		}
		
		for (int l = 0; l < n; l++)
        {
            while (!dq.empty() && dq.front() < l - k + 1)
                dq.pop_front();

            while (!dq.empty() && arr[dq.back()] < arr[l])
                dq.pop_back();

            dq.push_back(l);

            if (l >= k - 1)
                printf("%d ", arr[dq.front()]);
        }
        printf("\n");
	}
}
