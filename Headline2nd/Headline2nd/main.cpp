/*
#include <iostream>
using namespace std;
#define MAX_N 10
#define MAX 10000
int N,n;
int a[MAX][100000];

void solve(){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < )
    }
}

int main(){
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> n;
        for (int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    solve();
    return 0;
}
*/
/*
#include <iostream>
using namespace std;
#define MAX_N1 100
#define MAX_N2 100
int n1, n2, m;
int a[MAX_N1];
int b[MAX_N2];
int dp[MAX_N1][MAX_N2];

void solve(){
    for (int i = 0; i < n1; i++){
        int rest = 0;
        for (int j = 0; j < n2; j++){
            
            if(i == 0 || j == 0)
                break;
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j - 1] + 1);
            rest = m - a[i] - b[j];
        }
    }
    
    cout << dp[n1][n2];
}

int main(){
    cin >> n1 >> n2 >> m;
    for (int i = 0; i < n1; i++)
        cin >> a[i];
    for (int i = 0; i < n2; i++)
        cin >> b[i];
    
    solve();
    return 0;
}
*/
