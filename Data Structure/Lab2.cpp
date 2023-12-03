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
	void addBegin(int dat)
	{
		Node* newPtr = new Node(dat);
		if (head == NULL)
		{
			head = newPtr;
		}
		else
		{
			Node* temp = head;
			newPtr->next = temp;
			head = newPtr;
		}
	}
	void addAnyPos(int pos, int dat)
	{
		if (pos < 0) {
			cout << "Invalid position" << endl;
			return;
		}
		Node* newPtr = new Node(dat);
		if (head == NULL)
		{
			head = newPtr;
		}
		else
		{
			if (pos == 0)
			{
				newPtr->next = head;
				head = newPtr;
			}
			else
			{
				Node* temp = head, * temp1 = NULL;
				for (int i = 0; i < pos; i++)
				{
					temp1 = temp;
					temp = temp->next;
				}
				temp1->next = newPtr;
				newPtr->next = temp;
			}
		}
	}

	bool contains(int item)
	{
		Node* temp = head;
		while (temp->next != NULL)
		{
			if (temp->data == item)
			{
				cout << "value found" << endl;
				return true;
			}
			else
				temp = temp->next;
		}
	}
	int size()
	{
		int size = 0;
		Node* temp = head;
		while (temp != NULL)
		{
			size++;
			temp = temp->next;
		}
		return size;
	}
	bool isEmpty()
	{
		if (head != NULL)
			return false;
		else
			return true;
	}
	int get(int pos)
	{
		Node* temp = head;
		while (temp->next != NULL)
		{
			if (pos < 0 || pos >= size())
				cout << "Wrong position" << endl;
			else
			{
				for (int i = 0; i < pos; i++)
				{
					temp = temp->next;
				}
				return temp->data;
			}

		}
	}
	int indexOf(int item)
	{
		Node* temp = head;
		int index = 0;
		while (temp->next != NULL)
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
		delete temp;
	}
	void removeLast() {
		Node* temp = head, * temp1=NULL;
		while (temp->next != NULL) {
			temp1 = temp;
			temp = temp->next;
		}
		delete temp;
		temp1->next=NULL;
	}
	void remove(int pos) {
		if (head == NULL) {
			cout << "List is empty" << endl;
			return;
		}
		else if (pos < 0 || pos >= size()) {
			cout << "Invalid position" << endl;
			return;
		}
		else {
			Node* temp = head, * temp1 = NULL;
			if (pos == 0) {
				head = head->next;
				delete temp;
				return;
			}
			for (int i = 0; i < pos; i++) {
				temp1 = temp;
				temp = temp->next;
			}
			temp1->next = temp->next;
			delete temp;
		}
	}

	void reverse()
	{
		Node* rem = head;
		Node* temp = NULL, * reversed = NULL;

		while (rem != NULL) {
			temp = rem->next;
			rem->next = reversed;
			reversed = rem;
			rem = temp;
		}
		head = reversed;
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
	

	void display()
	{
		Node* temp = head;
		cout << "Printing all values" << endl;
		while (temp != NULL)
		{
			cout << temp->data << endl;
			temp = temp->next;
		}
	}

};

int main()
{
	int input;
	SLL* s = new SLL();
	while (1)
	{
		cout << "Press 1 to add at last" << endl;
		cout << "Press 2 to add at begin" << endl;
		cout << "Press 3 to add at any position" << endl;
		cout << "Press 4 to the item contains in the list" << endl;
		cout << "Press 5 to show size" << endl;
		cout << "Press 6 to check is the SLL is  empty" << endl;
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
			s->addAnyPos(pos, data);
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
			cout << "value at " << pos << " " << s->get(pos) << endl;
			s->display();
		}
		else if (input == 8)
		{
			int item;
			cout << "Enter item" << endl;
			cin >> item;
			cout <<"The item " << item <<" is at index " << s->indexOf(item) << endl;
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
