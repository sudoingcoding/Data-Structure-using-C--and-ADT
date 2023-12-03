//Doubly Linked List ADT
#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};
class DLL {
    Node* head;
    Node* tail;
public:
    DLL() {
        head = NULL;
        tail = NULL;
    }
    void add(int data) {
       
        Node* block = new Node(data);
        if (head == NULL) {
            head = tail = block;
        }
        else {
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = block;
            block->prev = current;
            tail = block;
        }
        
    }
    void addBegin(int data) {
        Node* current = head;
        Node* block = new Node(data);
        head = block;
        block->next = current;
        current->prev = block;

    }
    void insertAtEnd(int data) {
        Node* block = new Node(data);
        tail->next = block;
        block->prev = tail;
        tail = block;
    }
    void addAnyPos(int data, int pos) {
        Node* block = new Node(data);
        Node* current = head;

        if (head == NULL) {
            head = tail = block;
        }
        else if (pos == 1) {
            head = block;
            block->next = current;
            current->prev = block;
        }
        else {
            int i = 2;
            while (current->next != NULL) {
                if (i == pos) {
                    break;
                }
                current = current->next;
                i++;
            }
            block->next = current->next;
            if (current->next != NULL) {
                current->next->prev = block;
            }
            current->next = block;
            block->prev = current;
        }
        if (block->next == NULL) {
            tail = block;
        }
    }

    bool contains(int item) {
        Node* current = head;
        while (current->next != NULL) {
            if (current->data == item)
                return true;
            else
                current = current->next;
        }
    }
    int size() {
        int size = 0;
        Node* temp = head;
        while (temp != NULL)
        {
            size++;
            temp = temp->next;
        }
        return size;
    }
    bool isEmpty(){
        if( (head != NULL)&& (tail != NULL))
            return false;
        else
            return true;
    }
    int get(int pos){
        Node* temp = head;
        while (temp->next != NULL)
        {
            if (pos < 0 || pos > size())
                cout << "Wrong position" << endl;
            else
            {
                for (int i = 1; i < pos; i++)
                {
                    temp = temp->next;
                }
                return temp->data;
            }

        }
    }
    int indexOf(int item){
        Node* temp = head;
        int index = 1;
        while (temp != NULL)
        {
            if (item == temp->data)
            {
                return index;
            }
            temp = temp->next;
            index++;
        }

    }
    void removeFirst() {
        Node* temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
    }
    void removeLast() {
        Node* temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete temp;
    }
    void remove(int pos) {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        Node* current = head;
        int count = 1;

        while (current != NULL && count < pos) {
            current = current->next;
            count++;
        }

        if (current == NULL) {
            cout << "Position exceeds the size of the list" << endl;
            return;
        }

        if (current == head) {
            head = current->next;
        }
        if (current->next != NULL) {
            current->next->prev = current->prev;
        }
        if (current->prev != NULL) {
            current->prev->next = current->next;
        }

        delete current;

        cout << "Node at position " << pos << " removed successfully" << endl;
    }

    void reverse()
    {
        Node* temp = head;
        Node* t = NULL;

        while (temp != NULL) {
            t = temp->prev;
            temp->prev = temp->next;
            temp->next = t;
            temp = temp->prev;
        }

        if (t != NULL) {
            head = t->prev;
        }
        tail = head;

        while (tail->next != NULL) {
            tail = tail->next;
        }

        cout << "DLL reversed successfully" << endl;
    }

    void display() {
        Node* current = head;
        cout << "Printing data" << "\n";
        while (current != NULL) {
            cout << current->data << "\n";
            current = current->next;
        }
    }
    void sort() {
        Node* i, * j;
        int temp;
        for (i = head; i->next != NULL; i = i->next) {
            for (j = i->next; j != NULL; j = j->next) {
                if (i->data > j->data) {
                    temp = i->data;
                    i->data = j->data;
                    j->data = temp;
                }
            }
        }
    }

};
int main(){
    int input;
    DLL* s = new DLL();
    while (1)
    {
        cout << "Press 1 to add at last" << endl;
        cout << "Press 2 to add at begin" << endl;
        cout << "Press 3 to add at any position" << endl;
        cout << "Press 4 to the item contains in the list" << endl;
        cout << "Press 5 to show size" << endl;
        cout << "Press 6 to check is the SLL is empty" << endl;
        cout << "Press 7 to get item at a index" << endl;
        cout << "Press 8 to get item position" << endl;
        cout << "Press 9 to remove first element" << endl;
        cout << "Press 10 to remove last element" << endl;
        cout << "Press 11 to remove any element" << endl;
        cout << "Press 12 to reverse element" << endl;
        cout << "Press 13 to sort element" << endl;
        cout << "Press 14 to display element" << endl;
        cout << "Press 15 to exit" << endl;
        cout << "Press your option" << endl;
        cin >> input;
        if (input == 1)
        {
            int data;
            cout << "Enter data" << endl;
            cin >> data;
            s->add(data);
            s->display();
        }
        else if (input == 2)
        {
            int data;
            cout << "Enter data" << endl;
            cin >> data;
            s->addBegin(data);
            s->display();
        }
        else if (input == 3)
        {
            int data, pos;
            cout << "Enter data" << endl;
            cin >> data;
            cout << "Enter position" << endl;
            cin >> pos;
            s->addAnyPos(data, pos);
            s->display();
        }
        else if (input == 4)
        {
            int item;
            cout << "Enter item" << endl;
            cin >> item;
            s->contains(item);
            s->display();
        }
        else if (input == 5)
        {
            cout << "size " << s->size() << endl;
            s->display();
        }
        else if (input == 6)
        {
            if (s->isEmpty() == true)
                cout << "Empty" << endl;
            else
                cout << "Not Empty" << endl;
            s->display();
        }
        else if (input == 7)
        {
            int pos;
            cout << "Enter position" << endl;
            cin >> pos;
            cout << "value at " << pos << " is " << s->get(pos) << endl;
            s->display();
        }
        else if (input == 8)
        {
            int item;
            cout << "Enter item" << endl;
            cin >> item;
            cout << "The item " << item << " is at index " << s->indexOf(item) << endl;
            s->display();
        }
        else if (input == 9)
        {
            s->removeFirst();
            s->display();
        }
        else if (input == 10)
        {
            s->removeLast();
            s->display();
        }
        else if (input == 11)
        {
            int pos;
            cout << "Enter the position" << endl;
            cin >> pos;
            s->remove(pos);
            s->display();
        }
        else if (input == 12)
        {
            s->reverse();
            cout << "reversed list" << endl;
            s->display();
        }
        else if (input == 13)
        {
            s->sort();
            cout << "sorted list" << endl;
            s->display();
        }
        else if (input == 14)
        {
            s->display();
        }
        else if (input == 15)
        {
            break;
        }
    }
    delete s;
    return 0;
}
