#include <iostream>

using namespace std;
class Fraction
{
    long int x,y;
    char z;
public:
    Fraction(): x(0), y(1) {}
    Fraction(int n, int m):x(n),y(m) {}
void show()
 {
     cout << x << "/" << y << endl;
 }
void read()
 {
     cin >> this->x >> this->z >> this->y;
 }

 Fraction operator + (Fraction &right_v){
        int new_x = (x * right_v.y) + (right_v.x * y);
        int new_y = y * right_v.y;
        if(y == right_v.y) {
        int new_x = x  + right_v.x;
     }
        Fraction new_vector = Fraction(new_x, new_y);
        return new_vector;
    }
};



int main()
{
    Fraction v;
    Fraction v1;
    v.read();
    v1.read();
    Fraction sum;
    sum = v + v1;
    sum.show();
    return 0;
}
