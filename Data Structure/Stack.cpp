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

class Stack
{
public:
    Node* top;
    Stack()
    {
        top = NULL;
    }
    void Push(int data)
    {
        Node* n = new Node(data);
        if (top == NULL)
            top = n;
        else
        {
            n->next = top;
            top = n;
        }
    }
    int Pop()
    {
        int p = 0;
        if (top == NULL)
            cout << "Empty" << "\n";
        else
        {
            Node* n = top;
            top = n->next;
            p = n->data;
            delete n;
        }
        return p;
    }
    int Size()
    {
        Node* t = top;
        int s = 0;
        while (t != NULL)
        {
            s++;
            t = t->next;
        }
        return s;
    }
    bool isEmpty()
    {
        if (top == NULL)
            return true;
        else
            return false;
    }
    void destroy()
    {
        Node* t = top;
        if (t != NULL)
        {
            t = t->next;
            delete t;
        }
        top = NULL;
        delete top;
        cout << "Stack is destroyed "<< "\n";
    }
    int Top()
    {
        return top->data;
    }
    void display()
    {
        Node* temp = top;
        cout << "Displaying numbers" << "\n";
        while (temp != NULL)
        {
            cout << temp->data << "\n";
            temp = temp->next;
        }
    }
};

Stack* copyStack(Stack* stackSrc)
{
    Stack* t = new Stack();
    Stack* s = new Stack();
    while (!stackSrc->isEmpty())
    {
        int a = stackSrc->Pop();
        t->Push(a);
    }
    while (!t->isEmpty())
    {
        int a = t->Pop();
        s->Push(a);
    }
    return s;
}
void binConv() {
    Stack* s = new Stack();
    int n;
    cout << "Enter the number: " << "\n";
    cin >> n;
    while (n != 0) {
        int i = n % 2;
        n /= 2;
        s->Push(i);
    }
    cout << "Binary Number is: " << "\n";
    while (!s->isEmpty()) {
        int i = s->Pop();
        cout << i;
    }
    cout << "\n";
}
void reverse(Stack* stackSrc)
{
    Stack* s = new Stack();
    while (!stackSrc->isEmpty())
    {
        int e = stackSrc->Pop();
        s->Push(e);
    }
    stackSrc->top = s->top;
}
void parsing()
{
    string s;
    cout << "Enter your equation: " << "\n";
    cin >> s;
    Stack* sr = new Stack();
    for (auto& x : s)
    {
        if (sr->isEmpty()&& ((x == ')') ||(x=='(')))
            sr->Push(x);
        else if (x == '(')
        {
            sr->Push(x);
        }
        else if (x == ')')
            sr->Pop();
        else {
            sr->Push(x);
        }
    }
    if (sr->isEmpty())
    {
        cout << "Complete" << "\n";
    }
    else cout << "Incomplete" << "\n";
}

int main()
{
    while (1)
    {
        cout << "Press 1 to use stack adt" << endl;
        cout << "Press 2 to copy stack" << endl;
        cout << "Press 3 to find a binary number" << endl;
        cout << "Press 4 to reverse a stack" << endl;
        cout << "Press 5 to check parse parenthesis" << endl;
        cout << "Press 6 to exit" << endl;
        cout << "Press your option" << endl;
        int input;
        cin >> input;
        if (input == 1)
        {
            Stack* s = new Stack();
            cout<<"Size now: " << s->Size() << "\n";
            if (s->isEmpty()) cout << "Empty" << "\n";
            else cout << "Not Empty" << "\n";
            s->Push(1);
            s->Push(2);
            s->Push(3);
            s->Push(4);
            s->Push(5);
            s->display();
            cout << "Size now: " << s->Size() << "\n";
            cout << "Top number: " << s->Top() << "\n";
            if (s->isEmpty()) cout << "Empty" << "\n";
            else cout << "Not Empty" << "\n"; 
            s->Pop();
            cout << "First number is poped" << "\n";
            s->display();
            cout << "Top number: " << s->Top() << "\n";
            s->destroy();
        }
        else if (input == 2)
        {
            Stack* s = new Stack();
            s->Push(1);
            s->Push(2);
            s->Push(3);
            s->Push(4);
            s->Push(5);
            cout << "Source stack" << "\n";
            s->display();
            Stack* st = new Stack();
            st=copyStack(s);
            cout << "Copied stack" << "\n";
            st->display();
        }
        else if (input == 3)
        {
            binConv();
        }
        else if (input == 4)
        {
            Stack* s = new Stack();
            s->Push(1);
            s->Push(2);
            s->Push(3);
            s->Push(4);
            s->Push(5);
            cout << "Main stack" << "\n";
            s->display();
            reverse(s);
            cout << "Reversed stack" << "\n";
            s->display();
        }
        else if (input == 5)
        {
            parsing();
        }
        else if (input == 6)
        {
            break;
        }
        else {
            cout << "Wrong Option" << "\n";
        }
    }
}
