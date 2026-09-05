#include <iostream>
using namespace std;

int factorial(int n, int result = 1) {
    if (n == 0)
        return result;

    return factorial(n - 1, n * result);
}


int main(){

cout << "the factorial is " << factorial(5) << endl;
    return 0;
}