#include<bits/stdc++.h>
using namespace std;

int findGCD(int n1, int n2)
{
    for(int i = min(n1,n2) ; i > 0 ; i--)
    {
        if(!(n1 % i) && !(n2 % i))
            return i;
    }
    return 1;
}

//optimal approach
int GCD(int n1, int n2)
{
    while(n1 > 0 && n2 > 0)
    {
        if(n1 > n2)
            n1 %= n2;
        else
            n2 %= n1;
    }

    if(!n1)
        return n2;
    return n1;
}


int main()
{
    int n1, n2;
    cin >> n1 >> n2;

    cout << "GCD is " << findGCD(n1,n2) << endl;
}