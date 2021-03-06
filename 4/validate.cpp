#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <array>

using namespace std;

//if98

class Node
{
    public:
        int data;
        Node *right;
        Node *left;
        Node(int data)
        {
            this->data = data;
        }
        Node()
        {
        }
};   

bool validate(Node *head)
{
    int hval = head->data;
    if(head->right == nullptr && head->left != nullptr)
    {
        int lval = head->left->data;
        if(lval > hval)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    else if(head->left == nullptr && head->right != nullptr)
    {
        int rval = head->right->data;
        if(rval <= hval)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    else if(head->left != nullptr && head->left != nullptr)
    {
        int lval = head->left->data;
        int rval = head->right->data;
        if(rval <= hval || lval > hval)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        return true;
    }
    
    bool v1, v2 = validate(head->right), validate(head->left);

    if(v1 == false || v2 == false)
    {
        return false;
    }
}
int main(void)
{
    Node *a = new Node(5);
    a->right = new Node(7);
    a->left = new Node(3);
    a->right->right = new Node(8);
    a->right->left = new Node(6);
    a->left->right = new Node(4);
   a->left->left = new Node(2);
    
}

