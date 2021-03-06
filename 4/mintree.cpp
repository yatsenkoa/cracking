#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <array>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    Node () : left(nullptr), right(nullptr) {};
    Node (int value) : data(value), left(nullptr), right(nullptr) {};
    ~Node() {delete left, delete right;};
};
//root node is middle, left and right are smaller binary searches

void branch(Node *root, vector<int> list)
{
    if(list.size() == 1)
    {
        root->data = list[0];
        return;
    }
    else if(list.size() == 2)
    {
        root->data = list[1];
        Node*left = new Node(list[0]);
        root->left = left;
        return;
    }

    root->data = list[list.size() / 2];
    Node *left = new Node();
    Node *right = new Node();

    root->left = left;
    root->right = right;

    vector<int> l (list.begin(), list.begin() + list.size()/2);
    vector<int> r (list.begin() + list.size() / 2 + 1, end(list));

    branch(left, l);
    branch(right, r);
}


int main(void)
{
    vector<int> li = {0,1,2,3,4,5,6,7,8,9,10};
    Node *root = new Node();

    branch(root, li);
}

