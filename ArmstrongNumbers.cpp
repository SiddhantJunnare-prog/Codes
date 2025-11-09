#include<bits/stdc++.h>
using namespace std;

int cube(int n)
{
    return n * n * n;
}

int isArmstrong(int n)
{
    int sum = 0;

    for(int copy = n ; copy ; copy /= 10)
    {
        int digit = copy % 10;
        sum += cube(digit);
    }

    return sum == n;
}

int main()
{
    int n;
    cin >> n;

    if(isArmstrong(n))
        cout << "Armstrong number";
    else
        cout << "Not an Armstrong number";
}