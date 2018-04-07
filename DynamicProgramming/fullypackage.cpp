//
//  fullypackage.cpp
//  DynamicProgramming
//
//  Created by 郭杰 on 2018/4/7.
//  Copyright © 2018年 郭杰. All rights reserved.
//
//完全背包问题，相对于之前的背包问题，区别在于每个物品的数量是没有限制的
//input:
//n = 3, (w, v) = (3,4), (4,5), (2,3)
//W = 7
//output:10
//limit: 1 <= n <= 100, 1 <= W < 10000
//use time:135
/*
#include <iostream>
using namespace std;
#define MAX_N 100
#define MAX_W 10000
int n, W;
int dp[MAX_N + 1][MAX_W + 1];
int w[MAX_N];
int v[MAX_N];

void solve(){
    /*solution 1st
    for (int i = 0 ; i < n; i++){
        for (int j = 0; j <= W; j++){
            for (int k = 0; k * w[i] <= j; k++){
                dp[i+1][j] = max(dp[i + 1][j], dp[i][j - k * w[j]] + k * v[i]);
            }
        }
    }*/
    
    /*solution 2nd*/
/*
    for (int i = 0 ; i < n; i++){
        for (int j = 0 ; j <= W; j++){
            if(j < w[i]){
                dp[i + 1][j] = dp[i][j];
            }else{
                dp[i + 1][j] = max(dp[i][j], dp[i + 1][j - w[i]] + v[i]);
            }
        }
    }
     
    cout << dp[n][W] << endl;
}

int main(){
    clock_t start_time, end_time;
    start_time = clock();
    
    cin >> n >> W;
    for (int i = 0; i < n; i++)
        cin >> w[i] >> v[i];
    solve();
    
    end_time = clock();
    cout << end_time - start_time << endl;
    
    return 0;
}
*/
