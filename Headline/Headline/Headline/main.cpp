/*
1.在n个元素的数组中，找到差值为k的数字对去重后的个数
#include <iostream>
using namespace std;

#define MAX_NUM 1000000
#define MAX 100000000
#define MIN -1

int main()
{
    long number[MAX_NUM];
    
    int n, k;//n个数，k差值
    
    int counter = 0;
    cin >> n >> k;
    for (int i = 0 ;  i < n; i++)
        cin >> number[i];
    
    for (int i = 0 ; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if(abs(number[i] - number[j]) == k)
            {
                counter++;
                number[i] = -1;
                number[j] = -1;
            }
        }
    }
    
    cout << counter;
    
    return 0;
}
*/






/*
2.定义两个字符串变量s，m，再定义两种操作
 操作1:m = s，s = s + s；
 操作2:s = s + m；
 假设初始化s = “a”， m = s，
 求最小的操作步骤，可以将s拼接到长度等于n
#include <iostream>
using namespace std;

string new_str = "";
string test_str = "";
int counter;

int main(){
    string s = "a";
    string m = s;
    int num = 0;
    
    string do_first(string str_one, string str_two);
    string do_second(string str_one, string str_two);
    int pingcuo(string s, string m);
    
    cin >> num;
    for (int i = 0; i < num; i++)
        new_str = new_str.append(s);
    
    int count = pingcuo(s, m);
    cout << count;
    
    return 0;
}


string do_first(string s, string m)
{
    string m_new = s;
    string s_new = s.append(s);
    return s_new;
}

string do_second(string s, string m)
{
    string s_new = s.append(m);
    return s_new;
}

int pingcuo(string s, string m)
{
    if(new_str.length() != test_str.length())
    {
        string s_new = do_first(s, m);
        string m_new = do_second(s, m);
        pingcuo(s, m);
        counter++;
    }
    
    return counter++;
}
*/







/*
 3.程序需要读取一个表达式，并且输出用字符“6”拼凑出来的计算结果
 第一行n，表示有多少行表达式
 接下来n行为相应的计算表达式
 */









/*
 4.给一个包含n个整数元素的集合a，一个包含m个整数元素的集合b
 定义magic操作，从一个集合中取出一个元素，放到另一个集合里，且操作过后每个集合的平均值都大于操作前
 注意以下两点：不可以把集合的元素去空，这样就没有平均值了；
 值为x的元素从集合b取出放入集合a，但集合a中已经有值为x的元素，则a的平均值不变，b的平均值可能会改变
 问最多能进行多少次magic操作
 输入描述：
    第一行为两个整数n，m，第二行n个整数，表示集合a中的元素，第三行m个整数，表示集合b中的元素
 输出描述：
    表示最多可以进行的操作次数
#include <iostream>
using namespace std;
#define MAX 100000

float ave_fir;
float ave_sec;
float ave_temp;
int counter;

int main(){
    int n = 0, m = 0;
    cin >> n >> m;
    int num1[MAX], num2[MAX];
    for (int i = 0; i < n; i++)
        cin >> num1[i];
    for (int j = 0; j < m; j++)
        cin >> num2[j];
    
    void move_cal(int num1[], int num2[], int n, int m);
    move_cal(num1, num2, n, m);
    
    cout << counter;
    
    return 0;
}

float cal_ave(int num[], int count)
{
    int total = 0;
    for(int i = 0; i < count; i++)
        total += num[i];
    return total / count;
}

void move_cal(int num1[], int num2[], int n, int m)
{
    ave_fir = cal_ave(num1, n);
    ave_sec = cal_ave(num2, m);
    
    for(int i = 0; i < n; i++)
    {
        num1[n+1] = num2[i];
        n++; m--;
        ave_temp = cal_ave(num1, n);
        if(ave_temp > ave_fir)
        {
            ave_fir = ave_temp;
            num2[i] = -1;
            counter++;
        }
        else
            num1[n] = 0;
    }
    move_cal(num2, num1, m, n);
}
*/







/*
 已知空中有n个高度互不相同的跳板，小T刚开始在高度为0的地方，每次跳跃可以选择与自己当前高度绝对值小于等于H的跳板，
 跳跃过后到达以跳板为轴的镜像位置，在最多跳k次的情况下最高能跳多高
 输入描述：
    第一行三个整数n，k，h，以下n行，每行一个整数ti，表示第i个跳板距离地面的高度
 输出描述：
    表示能够跳到的最高高度
 
#include <iostream>
using namespace std;
#define MAX 100000

int height_counter;
int count_num;
int abs_dis;
int height[MAX];

int main(){
    int n;
    cin >> n >> count_num >> abs_dis;
    
    
    for (int i = 0; i < n; i++)
        cin >> height[i];
    
    int height_cal(int old_height, int board_height);
    int cal_height();
    
    int final_height = cal_height();
    cout << final_height;
    
    return 0;
}

int height_cal(int old_height, int board_height)
{
    return old_height + (old_height - board_height) * 2;
}

int cal_height(){
    for(int i = 0; i < count_num; i++)
        if(abs(height_counter - height[i]) < abs_dis)
            height_cal(height_counter, height[i]);
        else
            return height_counter;
    
    return height_counter;
}*/







