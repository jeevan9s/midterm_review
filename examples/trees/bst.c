#include <stdio.h>
#include <stdlib.h>
// @practice -> binary-search-tree implementation in C

typedef int Key;
typedef struct _node *pNode;

typedef struct _node
{
    Key key;
    void *value;
    Node *leftChild;
    Node *rightChild;
} Node;

typedef struct _tree
{
    Node *root;
} Tree;

Node *createNode(Key k, void *v)
{
    Node *new = malloc(sizeof(Node));

    if (new)
    {
        new->key = k;
        new->value = v;
        new->leftChild = NULL;
        new->rightChild = NULL;
    }

    return new;
}

int insert(Key k, void *v, Node *root)
{
    int result = 0; // 0 = fail, 1 = success
    if (root->key == k)
        result = 0;

    else if (k < root->key)
    {
        if (root->leftChild)
        {
            result = insert(k, v, root->leftChild);
        }

        else
        {
            Node *new = createNode(k, v);
            root->leftChild = new;
            result = 1;
        }
    }

    else if (k > root->key)
    {
        if (root->rightChild)
        {
            result = insert(k, v, root->rightChild);
        }

        else
        {
            Node *new = createNode(k, v);
            root->rightChild = new;
            result = 1;
        }
    }

    return result;
}

Node* find(Key k, Node *root) {
    if ((!root) || (root->key == k)) return root; // termination conditions

    if (k > root->key) {
        return find(k, root->rightChild);
    } 

    else {
        return find(k, root->leftChild);
    }
}


Node* deleteNode(Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->value)
        root->leftChild = deleteNode(root->leftChild, key);
    else if (key > root->value)
        root->rightChild = deleteNode(root->rightChild, key);
    
    else {
        // case 1 & 2: leaf node or node with only one child
        if (root->leftChild == NULL) {
            Node* temp = root->rightChild;
            free(root);
            return temp;
        } else if (root->rightChild == NULL) {
            Node* temp = root->leftChild;
            free(root);
            return temp;
        }

        // get the proxy
        Node* temp = findMax(root->leftChild);

        root->value = temp->value;
        root->leftChild = deleteNode(root->leftChild, temp->value);
    }
    return root;
}

// largest value is located at the rightmost node
int findMax(Node* r) {
    if (!r) return -1;
    Node* current = r;
    while (current->rightChild) {
        current = current->rightChild;
    }
    return current->value;
}

int findMin(Node *r) {
    if (!r) return -1; 
    Node *current = r; 
    while (current->leftChild) {
        current = current->leftChild; 
    }
    return current->value;
}

