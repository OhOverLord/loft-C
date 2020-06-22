#include <fstream>
#include <iostream>
#include <cstring>
#include <locale>
#include <algorithm>
#include <vector>
#include "class_passenger_train.h"
#include "other_functions.h"

using namespace std;

int main() {
    setlocale(0,"");
    vector<PassengerTrain> trains;
    read_file(trains);
    while(1)
    {
        menu(trains);
    }
    return 0;
}
