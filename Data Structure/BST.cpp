//Binary Search Tree ADT
#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* left,*right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

class BST {
public:
    Node* root;
    BST() {
        root = NULL;
    }
    Node* insert(Node* n, int d) {
        if (n == NULL) {
            Node* temp = new Node(d);
            n = temp;
        }
        else if (d >= n->data) {
            n->right = insert(n->right, d);
            
        }
        else {
            n->left = insert(n->left, d);
        }
        return n;
    }
    bool search(Node* n, int d) {
        if (n == NULL) {
            return false;
        }
        if (n->data == d) {
            return true;
        }
        else if (d < n->data) {
            return search(n->left, d);
        }
        else if (d > n->data) {
            return search(n->right, d);
        }
    }
    void preOrder(Node* n) {
        if (n != NULL) {
            cout << n->data << "\n";
            preOrder(n->left);
            preOrder(n->right);
        }
    }
    void inOrder(Node* n) {
        if (n != NULL) {
            inOrder(n->left);
            cout << n->data << "\n";
            inOrder(n->right);
        }
    }
    void postOrder(Node* n) {
        if (n != NULL) {
            postOrder(n->left);
            postOrder(n->right);
            cout << n->data << "\n";
        }
    }
    Node* Delete(Node* n, int d) {
        if (n != NULL) {
            if (n->data > d) {
                n->left = Delete(n->left, d);
            }
            else if (n->data < d)
                n->right = Delete(n->right, d);
            else {
                if (n->right == NULL && n->left == NULL) {
                    Node* temp = n;
                    delete temp;
                    cout << "Deleted." << endl;
                    return NULL;
                }
                else if (n->left == NULL) {
                    Node* temp = n->right;
                    delete n;
                    cout << "Deleted." << endl;
                    return temp;
                }
                else if (n->right == NULL) {
                    Node* temp = n->left;
                    delete n;
                    cout << "Deleted." << endl;
                    return temp;
                }
                else {
                    Node* temp = findMin(n->right);
                    n->data = temp->data;
                    n->right = Delete(n->right, temp->data);

                }
            }
            return n;
        }
    }
    Node* findMin(Node* n) {
        if (n->left != NULL) return findMin(n->left);
        return n;     
    }
    Node* findMax(Node* n) {
        if (n->right != NULL) return findMax(n->right);
        return n;
    }
};

int main() {
    BST* s = new BST();
    while (1)
    {
        cout << "Press 1 to insert data" << endl;
        cout << "Press 2 to search data" << endl;
        cout << "Press 3 to traverse data" << endl;
        cout << "Press 4 to delete data" << endl;
        cout << "Press 5 to find smallest and largest data" << endl;
        cout << "Press 6 to exit" << endl;
        cout << "Press your option" << endl;
        int i;
        cin >> i;
        if (i == 1) {
            int r;
            cout << "Enter how many numbers:" << "\n";
            cin >> r;
            while (r--) {
                int i;
                cin >> i;
                s->root = s->insert(s->root, i);
            }
        }
        else if (i == 2) {
            cout << "Enter number to search:" << "\n";
            int b;
            cin >> b;
            if (s->search(s->root, b)) cout << "Number " << b << " is present" << "\n";
            else cout << "Number " << b << " is not found" << "\n";
        }
        else if (i == 3) {
            cout << "Preorder print:" << "\n";
            s->preOrder(s->root);
            cout << "Inorder print:" << "\n";
            s->inOrder(s->root);
            cout << "Postorder print:" << "\n";
            s->postOrder(s->root);
        }
        else if (i == 4) {
            cout << "Enter number to delete" << "\n";
            int k;
            cin >> k;
            s->root = s->Delete(s->root, k);
        }
        else if (i == 5) {
            cout << "Minimum number" << "\n";
            cout << s->findMin(s->root)->data << "\n";
            cout << "Maximum number" << "\n";
            cout << s->findMax(s->root)->data << "\n";
        }
        else if (i == 6) {
            break;
        }
        else {
            cout << "Wrong option" << "\n";
        }
    }
}