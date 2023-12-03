//Binary Search Tree ADT with diffreent implementations
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* left, * right;
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

int nodeCount(Node* n) {
    if (n == NULL) return 0;
    else {
        int leftTotal=nodeCount(n->left);
        int rightTotal = nodeCount(n->right);
        return 1 + leftTotal + rightTotal;
    }
}
int leafCount(Node* n) {
    if (n == NULL)
        return 0;
    else if (n->left == NULL && n->right == NULL)
        return 1;
    else {
        int leftTotal = leafCount(n->left);
        int rightTotal = leafCount(n->right);
        return leftTotal + rightTotal;
    }
}

Node* leafDelete(Node* n) {
    if (n == NULL) return NULL;
    if (n->left == NULL && n->right == NULL) {
        cout << n->data << " deleting..." << "\n";
        delete n;
        cout << "deleted" << "\n";
        return NULL;
    }
    n->left = leafDelete(n->left);
    n->right = leafDelete(n->right);
    return n;
}
int countHeight(Node* n) {
    if (n == NULL || (n->left == NULL && n->right == NULL)) {
        return 0;
    }
    else {
        int l = countHeight(n->left);
        int r = countHeight(n->right);
        if (l > r)
            return l + 1;
        else
            return r + 1;
    }
}
int main()
{
    BST* s = new BST();
    int r;
    cout << "Enter how many numbers:" << "\n";
    cin >> r;
    while (r--) {
        int i;
        cin >> i;
        s->root = s->insert(s->root, i);
    }
    while (1)
    {
        cout << "Press 1 to count total node number" << endl;
        cout << "Press 2 to count total leaf number" << endl;
        cout << "Press 3 to delete leaf" << endl;
        cout << "Press 4 to find height of the BST" << endl;
        cout << "Press 5 to exit" << endl;
        cout << "Press your option" << endl;
        int i;
        cin >> i;
        if (i == 1) {
            cout << "Total nodes created" << "\n";
            cout << nodeCount(s->root) << "\n";
        }
        else if (i == 2) {
            cout << "Total leaf nodes created" << "\n";
            cout << leafCount(s->root) << "\n";
        }
        else if (i == 3) {
            cout << "PreOrder traversal" << "\n";
            s->preOrder(s->root);
            s->root = leafDelete(s->root);
            cout << "Total nodes created" << "\n";
            cout << nodeCount(s->root) << "\n";
            cout << "Total leaf nodes created" << "\n";
            cout << leafCount(s->root) << "\n";
            cout << "PreOrder traversal" << "\n";
            s->preOrder(s->root);
        }
        else if (i == 4) {
            cout << "Height" << "\n";
            cout << countHeight(s->root) << "\n";
        }
        else if (i == 5) {
            break;
        }
        else {
            cout << "Wrong option" << "\n";
        }
    }
}
