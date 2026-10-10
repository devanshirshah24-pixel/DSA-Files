#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    char data;
    Node* left;
    Node* right;

    Node(char value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// Inorder: Left -> Root -> Right
void inorder(Node* root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Preorder: Root -> Left -> Right
void preorder(Node* root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder: Left -> Right -> Root
void postorder(Node* root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// Level Order: Level by level
void levelOrder(Node* root)
{
    if (root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        Node* current = q.front();
        q.pop();

        cout << current->data << " ";

        if (current->left != NULL)
            q.push(current->left);

        if (current->right != NULL)
            q.push(current->right);
    }
}

int main()
{
    // Creating the binary tree

    Node* root = new Node('A');

    root->left = new Node('B');
    root->right = new Node('C');

    root->left->left = new Node('D');
    root->left->right = new Node('E');

    root->right->left = new Node('F');
    root->right->right = new Node('G');

    cout << "Inorder Traversal: ";
    inorder(root);

    cout << endl;

    cout << "Preorder Traversal: ";
    preorder(root);

    cout << endl;

    cout << "Postorder Traversal: ";
    postorder(root);

    cout << endl;

    cout << "Level Order Traversal: ";
    levelOrder(root);

    cout << endl;

    return 0;
}