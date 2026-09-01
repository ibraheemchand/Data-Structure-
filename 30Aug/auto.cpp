#include <iostream>
using namespace std;

void hello(int a ){
    cout << "hellow world , the value is " << a << endl;
}
int main(){

    void(*f)(int)= hello;
    
    f(3);


    auto fx = hello;
    fx(8);

    return 0;
}