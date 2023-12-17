#include <stdio.h>
#include <stack>
using namespace std;

int main()
{
	int n;
	stack <int> st;
	scanf("%d", &n);
	int array[n];
	for(int i = 0; i < n; i++){
		scanf("%d", &array[i]);
	}
	int m = sizeof(array) / sizeof(array[0]);
	
	int ans = 0;
	
	for(int i = 0; i < m; i++){
		while(!st.empty() && (array[st.top()] < array[i])){
			
			int tinggiatas = array[st.top()];
			st.pop();
			
			if (st.empty()) break;
                
            int jarakantara = i - st.top() - 1;
            
            int tinggi = min(array[st.top()], array[i]) - tinggiatas;
            
            ans += tinggi * jarakantara;
		}
		st.push(i);
	}
	
	printf("%d", ans);
	
	return 0;
}

