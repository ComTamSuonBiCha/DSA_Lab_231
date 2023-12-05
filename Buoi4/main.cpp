//Helping functions
#include <iostream>
#include <math.h>
#include <queue>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"

enum BalanceValue
{
    LH = -1,
    EH = 0,
    RH = 1
};

void printNSpace(int n)
{
    for (int i = 0; i < n - 1; i++)
        cout << " ";
}

void printInteger(int &n)
{
    cout << n << " ";
}

template<class T>
class AVLTree
{
public:
    class Node;
private:
    Node *root;
protected:
    int getHeightRec(Node *node)
    {
        if (node == NULL)
            return 0;
        int lh = this->getHeightRec(node->pLeft);
        int rh = this->getHeightRec(node->pRight);
        return (lh > rh ? lh : rh) + 1;
    }
public:
    AVLTree() : root(nullptr) {}
    ~AVLTree(){}
    int getHeight()
    {
        return this->getHeightRec(this->root);
    }
    void printTreeStructure()
    {
        int height = this->getHeight();
        if (this->root == NULL)
        {
            cout << "NULL\n";
            return;
        }
        queue<Node *> q;
        q.push(root);
        Node *temp;
        int count = 0;
        int maxNode = 1;
        int level = 0;
        int space = pow(2, height);
        printNSpace(space / 2);
        while (!q.empty())
        {
            temp = q.front();
            q.pop();
            if (temp == NULL)
            {
                cout << " ";
                q.push(NULL);
                q.push(NULL);
            }
            else
            {
                cout << temp->data;
                q.push(temp->pLeft);
                q.push(temp->pRight);
            }
            printNSpace(space);
            count++;
            if (count == maxNode)
            {
                cout << endl;
                count = 0;
                maxNode *= 2;
                level++;
                space /= 2;
                printNSpace(space / 2);
            }
            if (level == height)
                return;
        }
    }

    void insert(const T &value);
int getBalance(Node*subroot){
    if(!subroot) return 0;
    return getHeightRec(subroot->pLeft)- getHeightRec(subroot->pRight);
}
Node* rotateLeft(Node* subroot)
{
    Node* temp = subroot->pRight;
    subroot->pRight = temp->pLeft;
    temp->pLeft = subroot;
    return temp;
    //TODO: Rotate and return new root after rotate
};
Node* rotateRight(Node* subroot)
{
    Node* temp = subroot->pLeft;
    subroot->pLeft = temp->pRight;
    temp->pRight = subroot;
    return temp;
    //TODO: Rotate and return new root after rotate
};

Node* Insert(const T &value, Node* node){
    if(!node) return new Node(value);
    if(value<node->data){
        node->pLeft = Insert(value, node->pLeft);
    }
    else if(value>=node->data){
        node->pRight = Insert(value,node->pRight); 
    }
    
    int balance = getBalance(node);
    if(balance > 1 && value < node->pLeft->data)
        return rotateRight(node);
    if(balance < -1 && value >= node->pRight->data)
        return rotateLeft(node);
    if(balance > 1 && value >= node->pLeft->data){
        node->pLeft = rotateLeft(node->pLeft);
        return rotateRight(node);
    }
    if(balance < -1 && value < node->pRight->data){
        node->pRight = rotateRight(node->pRight);
        return rotateLeft(node);
    }
    return node;
}

void insert(const T &value){
    //TODO
    this->root = Insert(value, this->root);
}

Node* rightRotate(Node* y)
    {
        Node* x = y->pLeft;
        y->pLeft = x->pRight;
        x->pRight = y;
        return x;
    }
    Node* leftRotate(Node* x)
    {
        Node* y = x->pRight;
        x->pRight = y->pLeft;
        y->pLeft = x;
        return y;
    }
    int getBalance(Node* N)
    {
        if (N == NULL)
            return 0;
        return getHeightRec(N->pLeft) - getHeightRec(N->pRight);
    }
    Node* maxValueNode(Node* node)
    {
        Node* current = node;

        /* loop down to find the leftmost leaf */
        while (current->pRight != NULL)
            current = current->pRight;

        return current;
    }

    Node* deleteNode(Node* root, int key)
    {
        // STEP 1: PERFORM STANDARD BST DELETE  
        if (root == NULL)
            return root;
        // If the key to be deleted is smaller  
        // than the root's key, then it lies 
        // in left subtree  
        if (key < root->data)
            root->pLeft = deleteNode(root->pLeft, key);
        // If the key to be deleted is greater  
        // than the root's key, then it lies  
        // in right subtree  
        else if (key > root->data)
            root->pRight = deleteNode(root->pRight, key);

        // if key is same as root's key, then  
        // This is the node to be deleted  
        else
        {
            // node with only one child or no child  
            if ((root->pLeft == NULL) ||
                (root->pRight == NULL))
            {
                Node* temp = root->pLeft ?
                    root->pLeft :
                    root->pRight;

                // No child case  
                if (temp == NULL)
                {
                    temp = root;
                    root = NULL;
                }
                else // One child case  
                    *root = *temp; // Copy the contents of  
                                   // the non-empty child  
                free(temp);
            }
            else
            {
                Node* temp = maxValueNode(root->pLeft);
                root->data = temp->data;
                root->pLeft = deleteNode(root->pLeft,
                    temp->data);
            }
        }
        if (root == NULL)
            return root;
        // STEP 3: GET THE BALANCE FACTOR OF  
        // THIS NODE (to check whether this  
        // node became unbalanced)  
        int balance = getBalance(root);

        // If this node becomes unbalanced,  
        // then there are 4 cases  

        // Left Left Case  
        if (balance > 1 && getBalance(root->pLeft) >= 0)
            return rightRotate(root);
        // Left Right Case  
        if (balance > 1 && getBalance(root->pLeft) < 0)
        {
            root->pLeft = leftRotate(root->pLeft);
            return rightRotate(root);
        }

        // Right Right Case  
        if (balance < -1 &&  getBalance(root->pRight) <= 0)
            return leftRotate(root);

        // Right Left Case  
        if (balance < -1 && getBalance(root->pRight) > 0)
        {
            root->pRight = rightRotate(root->pRight);
            return leftRotate(root);
        }

        return root;
    }
    void remove(const T& value)
    {
        // TODO
        this->root = deleteNode(root, value);
    }
    class Node
    {
    private:
        T data;
        Node *pLeft, *pRight;
        BalanceValue balance;
        friend class AVLTree<T>;

    public:
        Node(T value) : data(value), pLeft(NULL), pRight(NULL), balance(EH) {}
        ~Node() {}
    };
};
