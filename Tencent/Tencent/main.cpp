/*
 画板N*M，斜率为1画蓝色，斜率为-1画黄色，两种颜色都有就画绿色，空白为X
 input：
 第一行包括正整数N，M，表示画板长宽，接下来N行数据每行包括M个数据表示画的内容。1 <= N, 50 <= M
 output：
 输出正整数，计算最少几次操作能够完成
 
#include <iostream>
using namespace std;
#define MAX 50
int N;
int M;
char board[MAX][MAX];
int counter;
int counterG;

int main(){
    cin >> N >> M;
    for (int i = 0 ; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];
    
    for (int i = 0 ; i < N; i++)
        for (int j = 0; j < M; j++)
            if(board[i][j] == 'G')
                counterG++;
    
    void Find(int x, int y);
    Find(0, 0);
    
    cout << counter - counterG;
    
    return 0;
}


void Find(int x, int y){
    char start = board[x][y];
    
    if(start == board[x + 1][y + 1] && (x + 1) < M && (y + 1) < N){
        board[x][y] = 'X';
        Find(x + 1, y + 1);
    }
    else if (start == board[x - 1][y + 1] && (x - 1) > 0 && (y + 1) < N){
        board[x][y] = 'X';
        Find(x - 1, y + 1);
    }
    counter++;
}
*/

/*
 经过N天，留下M块巧克力，每天吃的巧克力不少于前一天的一半，但某一天不能不吃，求第一天吃多少块
 input：
 N表示天数，M表示巧克力数量, N <= 50000, M <= 100000
 output：
 第一天最多能吃的巧克力数量
 
#include <iostream>
using namespace std;
#define MAX 100000
int N;//day
int M;//chocalate
int dayCount = 0;
int record[MAX];

int main(){
    cin >> N >> M;
    int eat(int FirstCho, int dayCount);
    
    for (int i = 0; i < N; i++)
        record[i] = eat(int(M / 2), N);
    
    for (int i = 0; i < N; i++)
        cout << record[i];
    
    return 0;
}

int eat(int FirstCho, int dayCount){
    int newFirst = FirstCho;
    for (int i = 0; i < dayCount; i++)
            FirstCho = FirstCho / 2;
    
    
    if(FirstCho == 0)
        return newFirst;
    
    return 0;
}
*/

/*
 input:
 第一行为纸牌数量，第二行为纸牌的数字
 output：
 抽完后先抽的人比后抽的人多多少点数
 */
#include <iostream>
using namespace std;
#define MAX 100000
int N;
int card[MAX];
int counter = 0;

int main(){
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> card[i];
    
    void cardSort();
    cardSort();
    
    void Count();
    Count();
    
    
    cout << counter;
    return 0;
}

void cardSort(){
    for (int i = 0; i < N; i++)
        for (int j = 0 ; j < N - 1; j++){
            if(card[i] > card[j]){
                int temp = 0;
                temp = card[i];
                card[i] = card[j];
                card[j] = temp;
            }
        }
}

void Count(){
    int count1 = 0;
    int count2 = 0;
    
    for (int i = 0 ; i < N; i+=2){
        if(i < N){
            count1 += card[i];
            count2 += card[i + 1];
        }
    }
    
    counter = count1 - count2;
}




