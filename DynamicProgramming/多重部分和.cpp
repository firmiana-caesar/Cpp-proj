//
//  多重部分和.cpp
//  DynamicProgramming
//
//  Created by 郭杰 on 2018/4/7.
//  Copyright © 2018年 郭杰. All rights reserved.
//
//多重部分和问题为有n个数字a，每个数字有m中，求能否使用其中的几个数字使得他们的和正好为k
//input:
//n = 3,a = (3, 5, 8), m = (3, 2, 2), k = 17
//limit:
//1 <= n <= 100
//1 <= a, m <= 1000000
//1 <= k <= 1000000
/*
#include <iostream>
using namespace std;
#define MAX_N 100
#define MAX_K 1000000
int n = 0;
int K = 0;
int a[MAX_N];
int m[MAX_N];
bool dp[MAX_N][MAX_K];

void solve(){
    dp[0][0] = true;
    
    for (int i = 0 ; i < n; i++){
        for (int j = 0; j <= K; j++){
            for (int k = 0 ; k <= m[i] && k * a[i] <= j; k++){
                dp[i + 1][j] |= dp[i][j - k * a[i]];
            }
        }
    }
    
    if(dp[n][K])
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int main(){
    cin >> n;
    for (int i = 0 ; i < n; i++)
        cin >> a[i];
    for (int i = 0 ; i < n; i++)
        cin >>m[i];
    
    solve();
    
    return 0;
}
*/
