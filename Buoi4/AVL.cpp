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
Node* BalanceTree(Node* root, const T& val) {
    int balancing = this->getBalance(root);
    if (balancing > 1 && (val < root->pLeft->data)) { // Left of Left
        return rotateRight(root);
    } else if (balancing > 1 && (val >= root->pLeft->data)) { //Right of Left
        root->pLeft = rotateLeft(root->pLeft);
        return rotateRight(root);
    } else if (balancing < -1 && (val >= root->pRight->data)) { //Right of Right
        return rotateLeft(root);
    } else if (balancing < -1 && (val < root->pRight->data)) {
        root->pRight = rotateRight(root->pRight);
        return rotateLeft(root);
    }
    return root;
}

Node* insertion(Node* root, const T& val) {
    if (!root)
        return new Node(val);
    if (val < root->data) {
        root -> pLeft = insertion(root->pLeft, val);
    } else if (val > root-> data) {
        root -> pRight = insertion(root->pRight, val); 
    }
    return BalanceTree(root, val);
}
Node* BalanceTree2(Node* root) {
    int balancing = this->getBalance(root);
    if (balancing > 1 && (root->pLeft->pLeft)) { // Left of Left
        return rotateRight(root);
    } else if (balancing > 1 && (!root->pLeft->pLeft)) { //Right of Left
        root->pLeft = rotateLeft(root->pLeft);
        return rotateRight(root);
    } else if (balancing < -1 && (root->pRight->pRight)) { //Right of Right
        return rotateLeft(root);
    } else if (balancing < -1 && (!root->pRight->pRight)) {
        root->pRight = rotateRight(root->pRight);
        return rotateLeft(root);
    }
    return root;
}
Node* delele(Node* root, const T& value) {
    if (!root)
        return root;
    if (val < root->data) {
        root->pLeft = delete(root->pLeft, value);
        return BalanceTree2(root);
    }
    else if (val > root->data) {
        root->pRight = delete(root->pRight, value);
        return BalanceTree2(root);
    }
    if (!root->pLeft) {
        Node* temp = root->pRight;
        root->pRight = nullptr;
        delete root;
        return BalanceTree2(temp);
    } else if (!root->pRight) {
        Node* temp = root->pLeft;
        root->pLeft = nullptr;
        delete root;
        return BalanceTree2(temp);
    } else { //delete node 0 phai la la
        Node* temp1 = root;
        Node* temp2 = root->pLeft;
        while(temp2->pRight) {
            temp1 = temp2;
            temp2 = temp2->pRight;
        }
        if (temp1 != root) {
            temp1 -> pRight = temp2->pLeft;
        } else {
            temp1 -> pLeft = temp2->pRight;
        }
        root->data = temp2->data;
        temp2->pRight = temp2->pLeft = nullptr;
        delete temp2;
    }
    if (!root) {
        return root;
    }
    root -> pLeft = BalanceTree2(root->pLeft);
    root -> pRight = BalanceTree2(root->pRight);
    return BalanceTree2(root);
}
void remove(const T& value) {
    this->root = this->delelte(root, value);
}
void insert(const T& value) {
    this->root = this->insertion(root, value);
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

template<class T>
static void sortSegment(T* start, T* end, int segment_idx, int cur_segment_total) {
    // useful function
}

template<class T>
static void ShellSort(T* start, T* end, int* num_segment_list, int num_phases) 
{
    int size = end - start;
    
    for (int i = num_phases - 1; i >= 0; i--)
    {
        int incr = num_segment_list[i];
        
        for (int j = 0; j < size - incr; j++)
            for (int k = 0; k < size - incr; k++)
                for (int m = k; m < size - incr && start[m] > start[m + incr]; m++)
                    swap (start[m], start[m + incr]);
    
        cout << incr << " segments: ";
        printArray(start, end);
    }
}