#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <cstdio>
using namespace std;
#define gc getchar

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
    
    map<int, int> studentTeam;
    vector<queue<int>> teams(n);

    for (int i = 0; i < n; i++) {
        int m;
        Get(m);
        for (int j = 0; j < m; j++) {
            int student;
            Get(student);
            studentTeam[student] = i; 
        }
    }
    
    queue<int> mainQueue;

    char ch[20];
    while (scanf("%s", ch) != EOF) {
        if (ch[0] == 'E') {
            int student;
            Get(student);
            int team = studentTeam[student];
            teams[team].push(student);
            if (teams[team].size() == 1) {
                mainQueue.push(team);
            }
        } else if (ch[0] == 'D') {
            int currentTeam = mainQueue.front();
            cout << teams[currentTeam].front() << endl;
            teams[currentTeam].pop();
            if (teams[currentTeam].empty()) {
                mainQueue.pop();
            }
        }
    }
    
    return 0;
}
