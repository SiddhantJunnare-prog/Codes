#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    if(n == 2) 
        return true;
    if(n == 0 || n == 1 || !(n % 2)) 
        return false;

    int limit = n/2;
    for(int i = 2 ; i <= limit ; i++)
    {
        if(!(n % 2)) 
            return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    if(isPrime(n))
        cout << "Yes";
    else 
        cout << "No";
}