#include <iostream>
#include <string>
using namespace std;
#define u -1
#define d 1
#define l -1
#define r 1
#define MAX 1000
string s = NULL;
int Q;
int N, M, X, Y;
int result[MAX];

void solve(int i){
    int count = 0;
    for (int j = 0; j < s.length(); j++){
        count++;
        if(s[j] == 'u')Y = Y + u;
        if(s[j] == 'd')Y = Y + d;
        if(s[j] == 'l')X = X + l;
        if(s[j] == 'r')X = X + r;
        if (X > N || X < 0 || Y > M || Y < 0){
            result[i] = count;
            return;
        }
    }
    result[i] = count;
}

int main(){
    cin >> s;
    cin >> Q;
    for (int i = 0; i < Q; i++){
        cin >> N >> M >> X >> Y;
        solve(i);
    }
    for (int i = 0 ; i < Q; i++)
        cout << result[i] << endl;
    return 0;
}


