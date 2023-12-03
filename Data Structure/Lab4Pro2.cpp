#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Queue
{
public:
    Node* front, * rear;
    Queue()
    {
        front = NULL;
        rear = NULL;
    }
    void enqueue(int data)
    {
        Node* ptrN = new Node(data);
        if (front == NULL)
        {
            front = rear = ptrN;
        }
        else
        {
            rear->next = ptrN;
            rear = ptrN;
        }
    }
    int dequeue()
    {
        Node* t = front;
        front = front->next;
        int data = t->data;
        delete t;
        return data;
    }
    bool isEmpty()
    {
        bool isempty;
        if (front)
            isempty = false;
        else
            isempty = true;
        return isempty;
    }
    int size()
    {
        Node* t = front;
        int s = 0;
        while (t != NULL)
        {
            s++;
            t = t->next;
        }
        return s;
    }
    void display()
    {
        Node* temp = front;
        cout << "Displaying numbers" << "\n";
        while (temp != NULL)
        {
            cout << temp->data << "\n";
            temp = temp->next;
        }
    }
    void destroy()
    {
        Node* t = front;
        if (t != NULL)
        {
            t = t->next;
            delete t;
        }
        front = NULL;
        rear = NULL;

    }
    int Front()
    {
        return front->data;
    }
    int Rear()
    {
        return rear->data;
    }
};

Queue* negQueue(Queue* queueSrc) {
    Queue* q = new Queue();
    Queue* qt = new Queue();
    while (!queueSrc->isEmpty()) {
        int a = queueSrc->Front();
        if (a < 0)
            q->enqueue(queueSrc->dequeue());
        else
            qt->enqueue(queueSrc->dequeue());
    }
    while (!qt->isEmpty()) {
        queueSrc->enqueue(qt->dequeue());
    }
    return q;
}
int main()
{
    Queue* q = new Queue();
    q->enqueue(1);
    q->enqueue(2);
    q->enqueue(-3);
    q->enqueue(4);
    q->enqueue(-5);
    q->display();


    Queue* qr = new Queue();
    qr = negQueue(q);
    cout << "Negative numbers" << "\n";
    qr->display();
    cout << "Positive numbers" << "\n";
    q->display();
}
