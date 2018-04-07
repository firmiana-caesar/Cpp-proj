//
//  LCS.cpp
//  DynamicProgramming
//
//  Created by 郭杰 on 2018/4/7.
//  Copyright © 2018年 郭杰. All rights reserved.
//
/*
 最长公共子序列问题，给定两个字符串求最长的公共子序列的长度，只要序号递增即可，无需字符互相靠近
 */
//经典LCS问题：
//limit:1 <= n, m <= 1000
//input：
//n = 4, m = 4
//s = "abcd", t = "becd"
//output:3("bcd")
//use time 283
//dp[i][j] -> 选到si和tj时的lcs长度
//dp[i + 1][j + 1] = max(dp[i][j]+1) [while s[i] == t[j]] or max(dp[i+1][j] dp[i][j+1]) [while s[i] != t[j]]
/*
#include <iostream>
using namespace std;
#define MAX_L 1000
int n = 0;
int m = 0;
char s[MAX_L];
char t[MAX_L];
int dp[MAX_L][MAX_L];

int lcs(){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(s[i] == t[j]){
                dp[i + 1][j + 1] = dp[i][j] + 1;
            }else{
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }
    return dp[n][m];
}

void solve(){
    cout << lcs() << endl;
}

int main(){
    clock_t start_time;
    clock_t end_time;
    start_time = clock();
    
    cin >> n >> m;
    for (int i = 0 ; i < n; i++)
        cin >> s[i];
    for (int j =  0; j < m; j++)
        cin >> t[j];
    solve();
    
    end_time = clock();
    cout << end_time - start_time << endl;
    
    return 0;
}
*/
