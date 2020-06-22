#include <iostream>
#include <cstring>

using namespace std;

class String {
    long long int len,n,m;
    char *str;

public:
    String();
    String(const String&);
    String(char *str);
    ~String();
    String& operator=(String &);
    void show(){
    cout << str << endl;
    }
    void sqr(int n,int m) {
    for(int i = 0; i < n; ++i) {
        str = strcpy(str);
    }
    for( long int j = 0; j < m; ++j) {
        cout << str << endl;
    }
    }

    friend istream &operator >> (istream &, String &);
    friend ostream &operator << (ostream &, String &);
};

String::String() {
 str = new char [1];
 str[0] = '\0';
 len = 0;
}

String::String(char *_str){
   len = strlen(_str);
   str = new char[len + 1];
   strncpy(str, _str, len);
   str[len] = '\0';
}
String::~String() {
delete [] str;
}
String::String(const String& s){
   len = s.len;
   str = new char[len + 1];
   strcpy(str,s.str);
}
String& String::operator=(String & s)
{
    len = s.len;
    delete [] str;
    str = new char [len + 1];
    strcpy(str,s.str);
}


istream &operator >> (istream &is, String &s) {
 char buf[10001];
 is.getline(buf,10001);
 if(s.len != 0) {
    delete [] s.str;
 }
 s.len = strlen(buf);
 s.str = new char[s.len+1];
 strncpy(s.str,buf,s.len);
 s.str[s.len] = '\0';
 return is;
}


int main() {
 String s1;
 int n,m;
 cin >> n >> m;
 s1.sqr(n,m);
 return 0;
}
