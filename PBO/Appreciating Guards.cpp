#include <stdio.h>
#include <queue>
#include <functional>
#include <math.h>
using namespace std;
#define gc getchar_unlocked

template <typename T> void getNum(T &val){
	char ch; bool bo=0; val=0;
	for(ch=gc(); ch<'0'||'9'<ch;ch=gc()) if(ch=='-') bo =1;
	for(;'0'<=ch && ch<='9'; val=(val<<3)+(val<<1)+ch-48, ch=gc());
	if(bo) val=-val;
}

int main() {
    int testcase, n, res;

    getNum<int>(testcase);

    for (int i = 0; i < testcase; i++) {
        getNum<int>(n);
        int temp[n];
        int total = 0, average, x, y ,z;
        priority_queue<int> pq1;
		priority_queue<int, vector<int>, greater<int> > pq2;
        for(int j = 0; j < n; j++){
			int number;
			getNum<int>(number);
			total += number;
			temp[j] = number;
		}
		
		if (total % n == 0){
			average = total/n;
		} else {
			printf("-1\n");
			continue;
		}
		
		for(int j = 0; j < n; j++){
			if (temp[j] < average){
				pq2.push(temp[j]);
			} else if (temp[j] > average){
				pq1.push(temp[j]);
			}
		}
		
		int itr = 0;
		while (!pq1.empty() && !pq2.empty()){
		x = pq1.top();
		pq1.pop();
		y = pq2.top();
		pq2.pop();
		z = ceil((x - y) / 2);
		x -= z;
		if (x < average) pq2.push(x);
		else if (x > average) pq1.push(x);
		y += z;
		if (y < average) pq2.push(y);
		else if (y > average) pq1.push(y);
		itr++;
		}
		printf("%d\n", itr);
    }
    return 0;
}

