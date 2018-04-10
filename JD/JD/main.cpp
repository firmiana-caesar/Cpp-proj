/*
 对于一个字符串，可以移除相应的字符串使其变成回文字符串，输出移除相应的字符之后能够形成回文字符串的方法
 input:
 string s,length(s) <= 50
 output:
 移除的方案数
 */
/*
#include <iostream>
#include <stack>
using namespace std;
#define MAX 50
string s;
int length = 0;
int dp[MAX];

bool check(string s){
    int new_length = sizeof(s) / 8;
    //cout << new_length;
    stack<char> check;
    bool is_true = false;
    for (int i = 0 ; i < (new_length / 2); i++){
        check.push(s[i]);
    }
    
    for (int i = (new_length / 2); i < new_length; i++){
        char c = check.top();
        if (c != s[i]){
            return false;
        }
        else
            is_true = true;
    }
        
    return is_true;
}

int double_check(){
    int res;
    string new_s;
    if(length == 1)
        return 0;
    
    dp[0] = 0;
    
    for (int i  = 1 ; i < length; i++){
        new_s = new_s + s[i];
        for (int j = i; j < length; j++){
            if(check(new_s + s[j]))
                dp[j]++;
        }
    }
    
    res = dp[length - 1];
    return res;
}

void solve(){
    int res;
    res = double_check();
    cout << res << endl;

}

int main(){
    cin >> s;
    length = sizeof(s) / 8;
    solve();
    
    return 0;
}
*/


#include <iostream>
using namespace std;
#define MAX 1000
int check[MAX];
int counter = 0;

void checker(int number, int countdown){
    if (number % 2 != 0){
        if (countdown != counter)
            cout << "No" << endl;
        else
            cout << "No";
        
        return;
    }
    
    int jishu = 0;//jishu
    int oushu = 0;//oushu
    
    for (int i = 2; i <= number / 2; i+=2){
        int new_jishu = number / i;
        if (new_jishu % 2 == 0)
            continue;
        if(new_jishu < jishu)
            break;
        else
            jishu = new_jishu;
    }
    
    if(jishu != 0)
        oushu = number / jishu;
    
    if(countdown != counter)
        cout << jishu << " " << oushu << endl;
    else
        cout << jishu << " " << oushu;
}

void solve(){
    for (int i = 0 ; i < counter; i++)
        checker(check[i], i);
}

int main(){
    cin >> counter;
    for (int i = 0 ; i < counter; i++)
        cin >> check[i];
    
    solve();
    
    return 0;
}
