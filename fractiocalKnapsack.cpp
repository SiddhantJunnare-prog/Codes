#include<iostream>
#include<algorithm>
using namespace std;

struct Item
{
    int weight, value;
    double ratio;
};

bool compare(Item a, Item b)
{
    return a.ratio > b.ratio;
}

double fractionalKnapsack(Item arr[], int n, int capacity)
{
    sort(arr, arr + n, compare);

    double totalValue = 0.0;
    int currentWeight = 0;

    for(int i = 0 ; i < n ; i++)
    {
        if(arr[i].weight + currentWeight <= capacity)
        {
            currentWeight += arr[i].weight;
            totalValue += arr[i].value;
        }
        else
        {
            int remain = capacity - currentWeight;
            totalValue += arr[i].value * ((double)remain/arr[i].weight);
            break; 
        }
    }
    return totalValue;
}

int main()
{
    int n, capacity;
    cout << "Enter number of items : ";
    cin >> n;


    Item arr[n];
    cout << "Enter weight and value of each item\n";

    for(int i = 0 ; i < n ; i++)
    {
        cout << "Enter weight : ";
        cin >> arr[i].weight;
        cout << "Enter value : ";
        cin >> arr[i].value;

        arr[i].ratio = (double)arr[i].value/arr[i].weight;
    }

    cout << "Enter the capacity of Knapsack : ";
    cin >> capacity;

    double maxProfit = fractionalKnapsack(arr, n, capacity);
    cout << "Maximum profit : " << maxProfit << endl;

    return 0;
}