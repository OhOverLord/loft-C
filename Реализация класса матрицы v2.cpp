#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

class Matrix
{
protected:
    int b = 3;
public:
    int a[3][3];
    int input(){
        for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            this->a[i][j] = rand()%100 - 10;
        }
        }
    }
    void output(){
        for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << this->a[i][j] << " ";
        }
            cout << endl;
        }
    }
    void transposition(){
        for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << this->a[j][i] << " ";
        }
            cout << endl;
        }
    }
    void g(){
        cout << this->b;
    }
};

int main()
{
    Matrix m;
    m.input();
    cout << "Initial matrix" << endl;
    m.output();
    cout << "transposed matrix" << endl;
    m.transposition();
    m.g();
    cout <<endl;
    system("pause");
}
