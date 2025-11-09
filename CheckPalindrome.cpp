#include<iostream>
using namespace std;

int main()
{
    int num;
    cin >> num;
    int copy;
    int rem = 0, digit = 0, reverse = 0;

    for(copy = num ; num > 0 ; num /= 10)
    {
        int digit = num % 10;
        reverse = reverse * 10 + digit;
    }

    copy == reverse ? cout << "Palindrome number" : cout << "Not a Palindrome number";
    
}