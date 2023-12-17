#include<iostream>
using namespace std;

int solve(int N,int M){
		unsigned long long K = 0;
    while (true) {
        if ((N ^ K) > M) {
            break;
        }
        K++;
       
}
 cout << K << endl;
}

int main (){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int itr;
	cin >> itr;
	
	for(int i = 0; i < itr; i++){
		unsigned long long N, M;
		cin >> N >> M; 
		solve(N, M);   
	}
	
}
