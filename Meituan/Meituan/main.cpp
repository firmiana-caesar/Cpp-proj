/*#include <iostream>
using namespace std;

int main(){
    string s;
    string t;
    cin >> s;
    cin >> t;
    
    int count = t.length();
    
    int max = 0;
    int counter = 0;
    int test_num = s.length() - t.length() + 1;
    
    for (int i = 0; i < test_num; i++)
    {
        for(int j = 0; j < count; j++)
        {
            if(s[i+j] != t[j])
                counter++;
        }
        max = max + counter;
        counter = 0;
    }
    
    cout << max;
    return 0;
}

*/

#include <iostream>
using namespace std;

int main(){
    string s;
    cin >> s;
    int count = sizeof(s);
    
    int counter0,counter1, counter2,counter3,counter4,counter5,counter6, counter7, counter8,counter9;
    for (int i = 0; i < count; i++)
    {
        switch(s[i])
        {
            case '0':
                counter0++;
                break;
            case '1':
                counter1++;
                break;
            case '2':
                counter2++;
                break;
            case '3':
                counter3++;
                break;
            case '4':
                counter4++;
                break;
            case '5':
                counter5++;
                break;
            case '6':
                counter6++;
                break;
            case '7':
                counter7++;
                break;
            case '8':
                counter8++;
                break;
            case '9':
                counter9++;
                break;
            default:
                break;
        }
    }
    
    cout << counter0 << counter1 << counter2 >> counter3 >> counter4 >> counter5 >> counter6 >> counter7 >> counter8 >> counter9 >> endl;
    
    if(counter1 = 0)
        count >> 1;
    
    return 0;
}
