#include<iostream>
using namespace std;

int iterativeFibo(int n)
{
    if (n <= 1)
        return n;

    int a = 0, b = 1, c;
    
    for(int i = 2 ; i <= n ; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int recursiveFibo(int n)
{
    if(n <= 1)
        return n;
    
    return recursiveFibo(n - 1) + recursiveFibo(n - 2);
}

int recursiveFiboDP(int n, int arr[])
{
    if(n <= 1)
        return n;
    if(arr[n] != -1)
        return arr[n];
    
    return recursiveFiboDP(n - 1, arr) + recursiveFiboDP(n - 2, arr);
}

int main()
{
    int n;
    cin >> n;

    int arr[n + 1];
    for(int i = 0 ; i <= n ; i++)
        arr[i] = -1;

    cout << "Iterative Fibo : " <<  iterativeFibo(n) << endl;
    cout << "Recursive Fibo : " <<  recursiveFibo(n) << endl;
    cout << "Recursive Fibo with DP: " <<  recursiveFiboDP(n, arr) << endl;
    
    return 0;
}