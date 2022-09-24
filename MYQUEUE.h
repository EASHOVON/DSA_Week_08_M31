#include <bits/stdc++.h>
using namespace std;

template <typename N>
class Node
{
public:
    N value;
    Node *Next;
    Node(N val)
    {
        this->value = val;
        this->Next = NULL;
    }
};

template <typename Q>
class Queue
{
    Node<Q> *front;
    Node<Q> *back;

public:
    Queue()
    {
        front = NULL;
        back = NULL;
    }

    // Enqueue --> Push
    void Push(Q val)
    {
        Node<Q> *newNode = new Node<Q>(val);
        if (front == NULL)
        {
            front = newNode;
            back = newNode;
            return;
        }

        back->Next = newNode;
        back = back->Next;
    }

    // Dequeue --> Pop
    Q Pop()
    {
        Q chk;
        if (back == NULL)
        {
            cout << "Queue Underflow | There is no element in the queue" << endl;
            return chk;
        }
        Node<Q> *delNode;
        delNode = front;
        front = front->Next;
        if (front == NULL)
        {
            back == NULL;
        }
        chk = delNode->value;
        delete delNode;
        return chk;
    }

    // Peek
    Q Front()
    {
        Q chk;
        chk = front->value;
        return chk;
    }

    Q Back()
    {
        Q chk;
        chk = back->value;
        return chk;
    }

    // Empty

    bool Empty()
    {
        if (front == NULL && back == NULL)
            return true;
        else
            false;
    }
};