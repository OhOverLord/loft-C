#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstdlib>

using namespace std;

class Matrix {
private:
    int size_of_vec;
    vector<vector<int> > vec;
    vector<int> vec_row;

public:

    Matrix(int _size){

//        �����������

        size_of_vec = _size;
    }

    void input_vec(){

//        ���������� ������� ���������� �������

        for(int i = 0; i < size_of_vec; ++i){
            for(int j = 0; j < size_of_vec; ++j){
                vec_row.push_back(rand()%100 + 10);
            }
            vec.push_back(vec_row);
            vec_row.clear();
        }
    }

    void sort_vec(){

//        ���������� �������, �� ������� ���������
//        �� �������� (������ � ��������� �������
//        ���������), � ����� �� �����������

        sort(vec[0].begin() + 1, vec[0].end());
        for(int i = 1; i < vec.size() - 1; i++){
            for(int j = 1; j < vec.size(); j++){
                sort(vec[i].begin() + j, vec[i].end());
                sort(vec[i].begin(), vec[i].end() - j, greater<int>());
            }
        }
        sort(vec[vec.size() - 1].begin(), vec[vec.size() - 1].end(), greater<int>());
    }

    void output_vec(){

//        ����� ������� �� �����

        for(int i = 0; i < vec.size(); i++){
            for(int j = 0; j < vec.size(); ++j){
                cout << vec[i][j] << "\t";
        }
            cout << endl;
        }
    }
    ~Matrix(){

//    ����������

        vec.clear();
        vec_row.clear();
    }
};

int main() {

//        ���������� �������, �� ������� ���������
//        �� �������� (������ � ��������� �������
//        ���������), � ����� �� �����������


    int _size;
    cout << "Input size:" << endl;
    cin >> _size;
    Matrix m(_size);
    m.input_vec();
    m.output_vec();
    cout << "��������������� ������" << endl;
    m.sort_vec();
    m.output_vec();
}
