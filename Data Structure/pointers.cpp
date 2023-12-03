#include <iostream>
using namespace std;

struct node {
	int roll;
	node* next;
};
node* root = NULL;

void append(int roll) {
	if (root== NULL) {
		root = new node();
		root->roll = roll;
		root->next = NULL;
	}
	else {
		node* current_node = root;
		while (current_node->next != NULL) {
			current_node = current_node->next;
		}
		node *newnode = new node();
		newnode->roll = roll;
		newnode->next = NULL;

		current_node->next = newnode;
	}
	cout << "Your value " << roll << " entered " << endl;
}

void print() {
	node* current_node = root;
	cout << "Your data: " << endl;
	while (current_node != NULL) {
		cout << current_node->roll << endl;
		current_node = current_node->next;
	}
}

void delete_node(int roll) {
	node* current_node = root;
	node* previous_node = NULL;
	while (current_node->roll != roll) {
		previous_node = current_node;
		current_node = current_node->next;
	}
	if (current_node == root) {
		node* temp = root;
		root = root->next;
		delete(temp);
	}
	else {
		previous_node->next = current_node->next;
		delete(current_node);
	}
	cout << "Your value "<<roll<<" deleted " << endl;
}

struct biNode {
	int roll;
	biNode* next, * prev;
};
biNode* biRoot, * biTail;

void biAppend(int roll) {
	if (biRoot == NULL) {
		biRoot = new biNode();
		biRoot->roll = roll;
		biRoot->next = NULL;
		biTail = biRoot;
	}
	else {
		biNode* newNode = new biNode();
		newNode->roll = roll;
		newNode->next = NULL;
		biTail->next = newNode;
		biTail = biTail->next;
	}
	cout << "Your value "<<roll<< " added " << endl;
}
void biPrint() {
	biNode* current_node = biRoot;
	cout << "Your bidirectional data: " << endl;
	while (current_node != NULL) {
		cout << current_node->roll << endl;
		current_node = current_node->next;
	}
}

struct BST {
	int roll;
	BST* left, * right;
	BST() {
		left = NULL;
		right = NULL;
	}
};
BST* BSTRoot;

void insert(int roll){
	if (BSTRoot == NULL) {
		BSTRoot = new BST();
		BSTRoot->roll = roll;
	}
	else {
		BST* current = BSTRoot, * parent;
		while (current != NULL) {
			if (roll < current->roll) {
				parent = current;
				current = current->left;
			}
			else {
				parent = current;
				current = current->right;
			}
		}
		BST* newNode = new BST();
		newNode->roll = roll;
		if (newNode->roll < parent->roll)
			parent->left = newNode;
		else
			parent->right = newNode;
	}
}

void print_preorder(BST *current) {
	if (current == NULL) return;
	cout << current->roll << endl;
	print_preorder(current->left);
	print_preorder(current->right);
}

int main() {
	append(1);
	append(2);
	append(3);
	print();
	delete_node(2);
	print();
	biAppend(3);
	biAppend(2);
	biAppend(1);
	biPrint();
	cout << "BST" << endl;
	insert(1);
	insert(5);
	insert(9);
	print_preorder(BSTRoot);
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
