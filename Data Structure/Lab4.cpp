#include <iostream>
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
class SLL
{
public:
    Node* head = NULL;
    void add(int item)
    {
        Node* newPtr = new Node(item);
        if (head == NULL)
        {
            head = newPtr;
        }
        else
        {
            Node* temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newPtr;

        }
    }
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
    
};
Node* d(Node* n,int pos) {
    if (pos < 1) return n;
    if (n == NULL) return NULL;
    if (pos == 1) {
        Node* t = n->next;
        cout << n->data << " is deleting" << "\n";
        delete n;
        return t;
    }
    n->next = d(n->next, pos - 1);
    return n;
}
Node* sort(Node* n) {
    if (n == NULL || n->next == NULL)
        return n;
    Node* m = n;
    Node* c = n->next;
    while (c != NULL) {
        if (c->data < m->data)
            m = c;
        c = c->next;
    }
    int temp = n->data;
    n->data = m->data;
    m->data = temp;
    n->next = sort(n->next);
    return n;
}

int gcd(int a, int b) {
    if (b == 0)return a;
    else return gcd(b, a % b);
}

int p(int n) {
    if (n == 0)
        return 1;
    else {
        cout << n << "\n";
        return p(n - 1);
    }
}
int pr(int n) {
    if (n == 0)
        return 1;
    else {
        pr(n - 1);
        cout << n << "\n";
    }
}
int Fibo(int n) {
    if (n <=1) return n;
    else return Fibo(n - 2) + Fibo(n - 1);
}
int sumFibo(int n) {
    int sum = 0;
    for (int i = 0; i < n-1; i++) {
        sum += Fibo(i);
    }
    return sum;
}
int main()
{
    while (1)
    {
        cout << "Press 1 to find GCD" << "\n";
        cout << "Press 2 to print n descending numbers" << "\n";
        cout << "Press 3 to print n ascending numbers" << "\n";
        cout << "Press 4 to print sum of n numbers of Fibonacci series" << "\n";
        cout << "Press 5 to delete nth node" << "\n";
        cout << "Press 6 to sort linked list" << "\n";
        cout << "Press 7 to exit" << "\n";
        cout << "Press your option" << "\n";
        int input;
        cin >> input;
        if (input == 1)
        {
            cout << "Enter two number" << "\n";
            int a, b;
            cin >> a >> b;
            cout << "GCD is" << "\n";
            cout << gcd(a, b)<< "\n";
        }
        else if (input == 2)
        {
            cout << "Enter number" << "\n";
            int n;
            cin >> n;
            cout << "Printing number: " << "\n";
            p(n);
        }
        else if (input == 3)
        {
            cout << "Enter number" << "\n";
            int n;
            cin >> n;
            cout << "Printing number: " << "\n";
            pr(n);
        }
        else if (input == 4)
        {
            cout << "Enter number" << "\n";
            int n;
            cin >> n;
            cout << "Printing sum of fibonacci: " << "\n";
            cout << sumFibo(n)<<"\n";
        }
        else if (input == 5)
        {
            SLL* s = new SLL();
            cout << "Enter how many numbers want to input" << "\n";
            int e;
            cin >> e;
            while (e--) {
                int x;
                cin >> x;
                s->add(x);
            }
            cout << "Entered Numbers" << "\n";
            s->display();
            cout << "Enter position" << "\n";
            int n;
            cin >> n;
            s->head=d(s->head, n);
            cout << "After deleting" << "\n";
            s->display();
        }
        else if (input == 6)
        {
            SLL* s = new SLL();
            cout << "Enter how many numbers want to input" << "\n";
            int n;
            cin >> n;
            while (n--) {
                int x;
                cin >> x;
                s->add(x);
            }
            cout << "Entered Numbers" << "\n";
            s->display();
            cout << "Sorted Numbers" << "\n";
            s->head = sort(s->head);
            s->display();
        }
        else if (input == 7)
        {
            break;
        }
        else {
            cout << "Wrong option entered " << "\n";
        }
    }
}
