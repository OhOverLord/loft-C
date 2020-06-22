#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class Student {

private:
char name[51];
char surname[51];
int hp;
int energy;
int iq;
void change_field(int &field, int delta);

public:
void start_game();
bool is_alive();
void show();
void eat();
void wait();
void study();
};

void Student::start_game(){
cin >> name;
cin >> surname;
hp = 100;
energy = 100;
iq = 20;
}

bool Student::is_alive(){
return hp > 0;
}

void Student::show(){
cout << name << " " << surname << ": HP = ";
if (hp < 100)cout << 0;
if (hp < 10) cout << 0;
cout << hp << ", ";

cout << "Energy = ";
if (energy < 100)cout << 0;
if (energy < 10) cout << 0;
cout << energy << ", ";

cout << "IQ = ";
if(iq < 100)cout << 0;
if(iq<10)cout << 0;
cout << iq << ".";
}

void Student::change_field(int &field,int delta){
field += delta;
   if(field > 100) {
    field = 100;
   }
   if(field < 0) {
    field = 0;
   }
}

void Student::eat(){
if (is_alive()){
change_field(hp,1);
change_field(energy,7);
change_field(iq,-1);
}
}

void Student::wait(){
if (is_alive()){
change_field(hp,1);
change_field(energy,-3);
change_field(iq,0);
}
}
void Student::study(){
if (is_alive()){
change_field(hp,-2);
change_field(energy,-4);
change_field(iq,5);
}
}


int main()
{
Student s;
s.start_game();

int turns;
cin >> turns;

for (int i = 0; i < turns ; i++){
char action[51];
cin >> action;
if(action[0] == 'W') {
            s.wait();
        }
        else if(action[0] == 'E') {
            s.eat();
        }

        else if(action[0] == 'S') {
            s.study();
        }
s.show();
if (!s.is_alive())
cout << " Game over.";
cout << endl;
}
return 0;
}
