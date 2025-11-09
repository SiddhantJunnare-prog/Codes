// Header Files

#include<iostream>
#include<queue>
#include<vector>
#include<string>
using namespace std;

struct Node
{
    char data;
    int freq;
    Node* left, *right;

    Node(char data, int freq)
    {
        this->data = data;
        this->freq = freq;
        left = right = nullptr;
    }
};

struct Compare
{
    bool operator()(Node* l, Node* r)
    {
        return l-> freq > r->freq;
    }
};

void printCodes(Node* root, string code)
{
    if(!root)
        return;
    if(root -> data != '$')
        cout << root -> data  << " : " << code << endl;

    printCodes(root -> left, code + "0");
    printCodes(root -> right, code + "1");
    
}

void HuffmanEncoding(char data[], int freq[], int n)
{
    priority_queue<Node*, vector<Node*>, Compare> pq;

    //Step1 : Create leaf nodes and add them in the priority queue
    for(int i = 0 ; i < n ; i++)
        pq.push(new Node(data[i], freq[i]));
    
    //step2 : Build Huffman Tree
    while(pq.size() > 1)
    {
        Node* left = pq.top(); 
        pq.pop();
        Node* right = pq.top();
        pq.pop();

        Node* top = new Node('$', left -> freq + right -> freq);
        top -> left = left;
        top -> right = right;

        pq.push(top);
    }

    //step3 : Print codes
    printCodes(pq.top(), "");
}

int main()
{
    char data[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    int freq[] = {5, 9, 12, 13, 16, 45};

    int n = sizeof(data)/sizeof(data[0]);

    HuffmanEncoding(data, freq, n);
}