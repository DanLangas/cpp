#include <iostream>
using namespace std;


struct Node
{
    int data;
    struct Node* left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

// parcurgerea arborelui postordine
void postOrdine(struct Node* node)
{
    if (node == NULL)
        return;

    postOrdine(node->left);

    postOrdine(node->right);

    cout << node->data << " ";
}

//parcurgerea arborelui inordine
void inOrdine(struct Node* node)
{
    if (node == NULL)
        return;

    inOrdine(node->left);

    cout << node->data << " ";

    inOrdine(node->right);
}

//parcurgerea arborelui in preordine
void preOrdine(struct Node* node)
{
    if (node == NULL)
        return;

    cout << node->data << " ";

    preOrdine(node->left);

    preOrdine(node->right);
}


int main()
{
    struct Node *root = new Node(10);
    root->left             = new Node(4);
    root->right         = new Node(1);
    root->left->left     = new Node(9);
    root->left->right = new Node(21);

    cout << "\nAfisare prin Preordine \n";
    preOrdine(root);

    cout << "\nAfisare cu Inordine \n";
    inOrdine(root);

    cout << "\nAfisare cu Postordine \n";
    postOrdine(root);

    return 0;
}
