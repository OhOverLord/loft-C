#include <iostream>

using namespace std;
int sum (int x) {
  if (x > 0)
    return (x % 10) + sum(x/10);
    return 0;

}
int main(int argc, char *argv[])
{
    int a;
    cin >> a;
    cout << sum(a);
    return 0;
}
