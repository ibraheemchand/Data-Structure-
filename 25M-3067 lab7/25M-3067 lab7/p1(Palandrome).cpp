#include <iostream>
#include <deque>
#include <string>
using namespace std;

bool CheckPalendrome(deque<char> d){
int size = (d.size()/2)+1;
for (int i = 0; i < size; i++)
{
    if (d.front()!=d.back())
    {
        return false;
    }
    else {
        d.pop_back();
        d.pop_front();
    }
}

    return true;
}

int main(){
deque<char> d;

d.push_back('d');
d.push_back('i');
d.push_back('c');

if (CheckPalendrome(d))
{
    cout << " is a Palandrome " << endl;
}
else{
    cout << "Not a palandrome " << endl;
}






return 0;
}
