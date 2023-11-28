#include <iostream>

using namespace std;
int result[1000001] = {0,};

int make_one(int X)
{
    if (X == 1)
        return 0;
    if ( result[X] != 0)
        return result[X];

    int rs;    
    if (X % 3 == 0 && X % 2 == 0)
        rs =  1 + min(min(make_one(X / 3), make_one(X / 2)), make_one(X - 1));
    else if (X % 3 == 0)
        rs =  1 + min(make_one(X / 3), make_one(X - 1));
    else if (X % 2 == 0)
        rs =  1 + min(make_one(X / 2), make_one(X - 1));
    else
        rs = 1 + make_one(X - 1);
    
    result[X] = rs;

    return rs;
}

int main()
{
    int X;
    cin >> X;

    cout << make_one(X);
}
