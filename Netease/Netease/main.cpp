/*
 input:
 输入的第一行为一个正整数T（T<=10），表示测试数据组数。
 接下来有T组数据。每组数据的第一行为两个正整数N，M（1<=N<20, N<=M<200），表示花砖的边长和小云家墙的边长。保证N和M都是奇数。接下来N行，每行N个字符，表示花砖的图案，且字符只会包含大小写字母和数字。相同的字符代表一个完美对称的图案。
 每组测试数据后包含一个空行。
 
 output:
 对于每一组数据，输出M行，每行包含M个字符，表示花砖平铺满墙后的图案。
 每组数据后输出一个空行。
 error:堆栈爆
#include <iostream>
using namespace std;
#define MAX 200
static int TurnOfTest;
int N;
int M;
char texture[MAX][MAX];
char finaltexture[MAX][MAX];

int main(){
    cin >> TurnOfTest;
    void make(int positionX, int positionY);
    for (int i  = 0; i < TurnOfTest; i++){
        cin >> N >> M;
        for (int j = 0; j < N; j++){
            for (int k = 0; k < M; k++){
                cin >> texture[N][M];
                make(int(M / 2), int(M / 2));
            }
        }
    }
    
    return 0;
}

void make(int positionX, int positionY){
    if (positionX + int(N / 2) < M){
        for(int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                finaltexture[positionX - int(N / 2) + i][positionY - int(N / 2) + j] = texture[i][j];
                make(positionX - N, positionY - N);
                make(positionX + N, positionY + N);
                make(positionX + N, positionY - N);
                make(positionX - N, positionY + N);
                make(positionX, positionY + N);
                make(positionX, positionY - N);
                make(positionX - N, positionY);
                make(positionX + N, positionY);
            }
        }
    }
    else{
        //if((positionX >= int(M / 2)) || (positionY >= int(M / 2))){
            int extraX = M - positionX + int(N / 2);
            int extraY = M - positionY + int(N / 2);
            for(int i = 0; i < extraX; i++){
                for (int j = 0; j < extraY; j++){
                    finaltexture[i][j] = texture[int(N / 2) + i][int(N / 2) + j];
                }
            }
        //}
    }
    
    for(int i = 0 ; i < M; i++){
        for (int j = 0 ; j < M; j++){
            cout << finaltexture[i][j];
        finaltexture[i][j] = NULL;
        }
    }
}
*/


/*
 世界杯临近，C国要组建一支最强的足球队，教练小Q想先组建一支具备实力的候选队伍，然后正式队伍再从里面挑选。
 小Q已经确定了后卫和门将两个位置的人选，剩下的前锋和中场人选需要从N个候选人里面确定。其中前锋需要X人，中场需要Y人。每个候选人可能只能打前锋和中场的某个位置，也可能可以同时胜任前锋和中场两个位置，并且候选人打不同位置时候具有不同的能力值。当一个候选人被选定为某个位置后就不能更改，候选人在该位置的能力值就是候选人的能力值。
 小Q希望最后入选的所有人选中，能力值最低的候选人的能力值也尽可能地高，这样才能组成最强的战队，小Q求助于你，希望你能告诉他这个值是多少。
 input:
 输入的第一行为一个正整数T（T<=10），表示测试数据组数。
 接下来有T组数据。每组数据第1行包含了三个整数N（0<N<=50000），X，Y(0 <=
 X, Y <= 10000)，X, Y不会同时为0。然后下面N行，每行有2个整数S0，S1(0 <=
 S0, S1 <= 10000)，分别表示这个候选人在前锋和中场的能力值，如果能力值为0，则表示该候选不能胜任该位置。
 数据保证X+Y<=N。如果没有满足的方案，则输出0。
 数据说明：
 有10%的测试数据，满足每组数据的N <= 100
 有30%的测试数据，满足每组数据的N <= 2000
 有100%的测试数据，满足每组数据的N <= 50000
 output:
 对于每一组数据，输出一行，包含一个整数，为最优方案下，能力值最低的候选人所具备的能力值。
 
#include <iostream>
using namespace std;
#define MAX 10000
int table[2][MAX];
int T = 0;//多少组数据
int N = 0;//当前组多少行数据
int X = 0;//前锋人数要求
int Y = 0;//中场人数要求
int tab[MAX];

int main(){
    cin >> T;
    int Done(int X, int Y);
    for (int i = 0; i < T; i++){
        cin >> N >> X >> Y;
        for (int i = 0; i < 2; i++)
            for (int j = 0 ; j < N; j++)
                cin >> table[i][j];
        tab[i] = Done(X, Y);
    }
    
    for (int i = 0 ; i < T; i++)
        cout << tab[i];
    
    return 0;
}

int Done(int X, int Y){
    int maxS0 = 0;
    int maxS1 = 0;
    int pickout[X + Y];
    
        for(int j = 0; j < N; j++){
            if(table[0][j] > maxS0){
                maxS0 = table[0][j];
                pickout[j] = j;
            }
        }
    
    
    for (int i = 0; i < N; i++){
        if(i != pickout[i] || table[1][i] > maxS1){
            maxS1 = table[1][i];
        }
    }
    
    return max(maxS0, maxS1);
}*/



/*
 input:
 输入的第一行为一个正整数T，表示测试数据组数。
 接下来有T组数据。每组数据有3行。每一行为一个长度为3的字符串，字符串中只包含字符'.'和'X'，表示当前要测试的点阵，'.'表示该点可以被选择，'X'表示该点不可以被选择。
 数据保证至少有两个点可以选择。
 数据范围：
 对于所有数据，都满足1<=T<=10。
 output:
 对于每一组数据，输出一行，包含一个整数，为在给定的点阵中可以绘制的不同的图形数量。
 
#include <iostream>
using namespace std;
char fine[3][3];
int T;

int main(){
    cin >> T;
    int maxCount();
    int count[10] = {0};
    for (int i = 0 ; i < T; i++)
    {
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
                cin >> fine[j][k];
        count[i] = maxCount();
    }
    
    for (int i = 0 ; i < T; i++)
        cout << count[i];
    
    return 0;
}

int maxCount(){
    int count = 0;
    
    int can[9];
    int cancount = 0;
    int cannot[9];
    int cannotcount = 0;
    
    for (int i = 0 ; i < 3; i++){
        for (int j = 0 ; j < 3; j++){
            if(fine[i][j] == '.'){
                can[i * 3 + j] = 1;
                cancount++;
                cout << cancount << endl;
            }
            else{
                cannot[i * 3 + j] = 0;
                cannotcount++;
                cout << cannotcount << endl;
            }
        }
    }
    
    
    for(int i = 1 ; i <= cancount; i++)
        count *= i;
    
    return count;
}
*/
