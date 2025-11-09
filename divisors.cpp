#include<bits/stdc++.h>
using namespace std;

void divisors(int n)
{
    int limit = n/2;

    for(int i = 1 ; i <= limit ; i++)
    {
        if(!(n % i))
            cout << i << ",";
    }
    cout << n ;
}

int main()
{
    int n;
    cin >> n;
    divisors(n);
}