#include <iostream>
#include <cmath>
using namespace std;

class Binary
{
private:
    int sch;
    bool data[32];
public:
    Binary(){
        data[0] = 0;
        sch = 1;
    }
    Binary(int value){
        sch = 0;
        if (value == 0)
        {
            data[0] = 0;
            sch = 1;
        }
            while(value != 0)
            {
                int new_Value = value % 2;
                data[sch] = new_Value;
                value = value / 2;
                sch++;
            }
        }
        long long b_i(){
            int res = 0;
            for(int i = 0; i < sch; i++) {
            if (data[i] > 0){
            res=data[i]%10+res*10;
            data[i]/=10;
            data[i] = res;
}
            }
        int a = sch;
        long long value = 0;
        for(int i = 0; i < sch; i++,a--) {
            if(data[i] != 0) {
                value += pow(2,a-1);
            }
        }
        cout << value;
        }



    void show(){
        for (int i = sch - 1; i >= 0; i--)
        {
            cout << data[i];
        }
    }
};

int main()
{
    int a = 0;
    cin >> a;
    Binary b = a;
    b.b_i();
}
