#include <iostream>
#include <cstring>
using namespace std;
int split(char *s,char words[][255]) {
    if(s==NULL)
        return -1;
    int count = 0,len = strlen(s),i=0;
    do {
        while(i<len && isspace(s[i]))
            ++i;
        int start = i;
        while(i<len && !isspace(s[i]))
            ++i;
            if(i!=len) {
                strcpy(words[count],s+start,i-start);
                ++count;
                ++i;

        }
    }while(i<len);
    return count;
}

int main()
{
    char str[101] = {};
    char words[101][255];
    cin.getline(str,101);
    int k = split(str,words);
    for(int i =0;i<k;++i) {
        cout << words[i];
    }
    return 0;
}
