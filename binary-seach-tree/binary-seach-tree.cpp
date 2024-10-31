#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* create_node(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* insert_node(Node* root, int value) {
    if (root == nullptr) {
        return create_node(value);
    }
    if (value < root->data) {
        root->left = insert_node(root->left, value);
    }
    else {
        root->right = insert_node(root->right, value);
    }
    return root;
}

void traversal_tree(Node* root) {
    if (root == nullptr) {
        return;
    }
    traversal_tree(root->left);
    cout << root->data << " ";
    traversal_tree(root->right);
}

void traversal_BFS(Node* root) {
    if (root == nullptr) {
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        cout << current->data << " ";

        if (current->left != nullptr) {
            q.push(current->left);
        }
        if (current->right != nullptr) {
            q.push(current->right);
        }
    }
}

void traversal_DFS(Node* root) {
    if (root == nullptr) {
        return;
    }
    stack<Node*> stack;
    stack.push(root);

    while (!stack.empty()) {
        Node* current = stack.top();
        stack.pop();

        cout << current->data << " ";

        if (current->right != nullptr) {
            stack.push(current->right);
        }
        if (current->left != nullptr) {
            stack.push(current->left);
        }
    }
}

int main() {
    Node* root = nullptr;
    root = insert_node(root, 50);
    root = insert_node(root, 30);
    root = insert_node(root, 20);
    root = insert_node(root, 40);
    root = insert_node(root, 70);
    root = insert_node(root, 60);
    root = insert_node(root, 80);

    cout << "Inorder traversal of the BST: ";
    traversal_tree(root);
    cout << endl;

    cout << "BFS traversal of the BST: ";
    traversal_BFS(root);
    cout << endl;

    cout << "DFS traversal of the BST: ";
    traversal_DFS(root);
    cout << endl;

    return 0;
}
