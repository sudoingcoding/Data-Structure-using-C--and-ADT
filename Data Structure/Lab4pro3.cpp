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
void reverse(Queue* queueSrc, int k) {
    if (k == 0) return;
    int e = queueSrc->dequeue();
    reverse(queueSrc, k - 1);
    queueSrc->enqueue(e);
    int s = queueSrc->size() - k;
}

Queue* reverseFirstK(Queue* queueSrc, int k) {
    if (k < 0 || k >= queueSrc->size()) {
        cout << "Input is invalid." << endl;
        return queueSrc;
    }
    reverse(queueSrc, k);
    int s = queueSrc->size()-k;
    while (s-- > 0) {
        queueSrc->enqueue(queueSrc->dequeue());
    }
    return queueSrc;
}


int main()
{
    Queue* q = new Queue();
    q->enqueue(10);
    q->enqueue(20);
    q->enqueue(30);
    q->enqueue(40);
    q->enqueue(50);
    q->enqueue(60);
    q->enqueue(70);
    q->enqueue(80);
    q->enqueue(90);
    q->enqueue(100);
    q->display();


    Queue* qr = new Queue();
    qr = reverseFirstK(q,5);
    qr->display();
    
}
