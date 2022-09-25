#include <bits/stdc++.h>
#include <queue>
using namespace std;

class treeNode
{
public:
    int data;
    treeNode *leftChild, *rightChild;

    treeNode(int val)
    {
        this->data = val;
        this->leftChild = this->rightChild = NULL;
    }
};

void inOrderTrav(treeNode *root, string &chk)
{
    if (root == NULL)
    {
        return;
    }
    inOrderTrav(root->leftChild, chk);
    chk += to_string(root->data);
    inOrderTrav(root->rightChild, chk);
}
void preOrderTrav(treeNode *root, string &chk)
{
    if (root == NULL)
    {
        return;
    }
    chk += to_string(root->data);
    inOrderTrav(root->leftChild, chk);
    inOrderTrav(root->rightChild, chk);
}
void postOrderTrav(treeNode *root, string &chk)
{
    if (root == NULL)
    {
        return;
    }
    inOrderTrav(root->leftChild, chk);
    inOrderTrav(root->rightChild, chk);
    chk += to_string(root->data);
}

void levelOrderTrav(treeNode *root)
{
    if (root == NULL)
        return;
    queue<treeNode *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        treeNode *node = q.front();
        q.pop();
        if (node != NULL)
        {
            cout << node->data << " ";
            if (node->leftChild)
                q.push(node->leftChild);
            if (node->rightChild)
                q.push(node->rightChild);
        }
        else if (!q.empty())
        {
            q.push(NULL);
        }
    }
    /* while (!Q.Empty())
    {
        treeNode *current = Q.Front();
        cout << current->data << " ";
        if (current->leftChild != NULL)
            Q.Push(current->leftChild);
        if (current->rightChild != NULL)
            Q.Push(current->rightChild);
        Q.Pop();
    } */
}

int findMaxInLevelOrd(treeNode *root, int k)
{
    if (root == NULL)
    {
        return -1;
    }
    queue<treeNode *> q;
    q.push(root);
    q.push(NULL);
    int level = 0;
    int max = INT_MIN;
    while (!q.empty())
    {
        treeNode *node = q.front();
        q.pop();
        if (node != NULL)
        {
            if (k == level)
            {
                if (node->data > max)
                {
                    max = node->data;
                }
            }
            if (node->leftChild)
                q.push(node->leftChild);
            if (node->rightChild)
                q.push(node->rightChild);
        }
        else
        {
            if (!q.empty())
            {
                q.push(NULL);
                level++;
            }
        }
    }
    return max;
}

int main()
{
    int n;
    cin >> n;
    treeNode *allNodes[n + 1];
    for (int i = 0; i < n; i++)
    {
        allNodes[i] = new treeNode(-1);
    }

    for (int i = 0; i < n; i++)
    {
        int value, left, right;
        cin >> value >> left >> right;
        allNodes[i]->data = value;
        if (left > n - 1 || right > n - 1)
        {
            cout << "Invalid Index" << endl;
            break;
        }
        if (left != -1)
        {
            allNodes[i]->leftChild = allNodes[left];
        }

        if (right != -1)
        {
            allNodes[i]->rightChild = allNodes[right];
        }
    }

    // levelOrderTrav(allNodes[0]);
    /* string preOrdertext = "";
    string inOrdertext = "";
    string postOrdertext = "";

    preOrderTrav(allNodes[0], preOrdertext);
    inOrderTrav(allNodes[0], inOrdertext);
    postOrderTrav(allNodes[0], postOrdertext);
    cout << "Pre-Order: " << preOrdertext << endl;
    cout << "In-Order: " << inOrdertext << endl;
    cout << "Post-Order: " << postOrdertext << endl; */
    int k = 2;
    cout << "Maximum Number in " << k << "th level is: " << findMaxInLevelOrd(allNodes[0], k) << endl;
    return 0;
}

/*
9
0 1 2
1 3 4
2 5 6
3 -1 -1
4 -1 -1
5 7 8
6 -1 -1
7 -1 -1
8 -1 -1
*/