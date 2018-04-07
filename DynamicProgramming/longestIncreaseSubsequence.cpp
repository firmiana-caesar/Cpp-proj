//
//  longestIncreaseSubsequence.cpp
//  DynamicProgramming
//
//  Created by 郭杰 on 2018/4/7.
//  Copyright © 2018年 郭杰. All rights reserved.
//
//最长上升子序列的定义为该序列中的最长的满足i < j时ai < aj的子序列
//input:
//n = 5, a = (4, 2, 3, 1, 5)
//output:
//3(2, 3, 5)
//limit:
//1 <= n <= 1000
//0 <= ai <= 1000000

#include <iostream>
using namespace std;
#define MAX_N 1000

int n = 0;
int dp[MAX_N];
int a[MAX_N];

void solve(){
    int res = 0;
    for (int i = 0 ; i < n; i++){
        dp[i] = 1;
        
        for (int j = 0 ; j < i; j++)
            if(a[j] < a[i])
                dp[i] = max(dp[i], dp[j] + 1);
        
        res = max(res, dp[i]);
    }
    
    cout << res;
}

int main(){
    cin >> n;
    for (int i = 0 ; i < n; i++){
        cin >> a[i];
    }
    
    solve();
    
    return 0;
}
