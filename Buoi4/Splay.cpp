#include<iostream>
using namespace std;

class SplayTree {
    struct Node {
        int val;
        Node* pLeft;
        Node* pRight;
        Node* pParent;
        Node(int val = 0, Node* l = nullptr, Node* r = nullptr, Node* par = nullptr) : val(val), pLeft(l), pRight(r), pParent(par) { }
    };
    Node* root;

    // print the tree structure for local testing
    void printBinaryTree(string prefix, const Node* root, bool isLeft, bool hasRightSibling) {
        if (!root && isLeft && hasRightSibling) {
            cout << prefix << "├──\n";
        }
        if (!root) return;
        cout << prefix;
        if (isLeft && hasRightSibling) 
            cout << "├──";
        else 
            cout << "└──";
        cout << root->val << '\n';
        printBinaryTree(prefix + (isLeft && hasRightSibling ? "|  " : "   "), root->pLeft, true, root->pRight);
        printBinaryTree(prefix + (isLeft && hasRightSibling ? "|  " : "   "), root->pRight, false, root->pRight);
    }

    void printPreorder(Node* p) {
        if (!p) {
            return;
        }
        cout << p->val << ' ';
        printPreorder(p->pLeft);
        printPreorder(p->pRight);
    }
public:
    SplayTree() {
        root = nullptr;
    }
    ~SplayTree() {
        // Ignore deleting all nodes in the tree
    }

    void printBinaryTree() {
        printBinaryTree("", root, false, false);
    }

    void printPreorder() {
        printPreorder(root);
        cout << "\n";
    }

    void splay(Node* p) {
        // To Do
    }

    void insert(int val) {
        // To Do
    }
    // write your helper functions here
    void rotateLeft(Node* p) {
        Node* q = p->pRight;
        if (q) {
            p->pRight = q->pLeft;
            if (q->pLeft) q->pLeft->pParent = p;
            q->pParent = p->pParent;
        }
        if (!p->pParent) {
            root = q;
        } else if (p == p->pParent->pLeft) {
            p->pParent->pLeft = q;
        } else {
            p->pParent->pRight = q;
        }
        if (q) {
            q->pLeft = p;
        }
        p->pParent = q;
    }

    void rotateRight(Node* p) {
        Node* q = p->pLeft;
        if (q) {
            p->pLeft = q->pRight;
            if (q->pRight) q->pRight->pParent = p;
            q->pParent = p->pParent;
        }
        if (!p->pParent) {
            root = q;
        } else if (p == p->pParent->pRight) {
            p->pParent->pRight = q;
        } else {
            p->pParent->pLeft = q;
        }
        if (q) {
            q->pRight = p;
        }
        p->pParent = q;
    }
    void splay(Node* p) {
        while (p->pParent) {
            if (!p->pParent->pParent) {
                if (p->pParent->pLeft == p) {
                    
                    rotateRight(p->pParent);
                } else {
                    
                    rotateLeft(p->pParent);
                }
            } else if (p->pParent->pLeft == p && p->pParent->pParent->pLeft == p->pParent) {
                rotateRight(p->pParent->pParent);
                rotateRight(p->pParent);
            } else if (p->pParent->pRight == p && p->pParent->pParent->pRight == p->pParent) {
                rotateLeft(p->pParent->pParent);
                rotateLeft(p->pParent);
            } else if (p->pParent->pLeft == p && p->pParent->pParent->pRight == p->pParent) {
                
                rotateRight(p->pParent);
                rotateLeft(p->pParent);
            } else {
                rotateLeft(p->pParent);
                rotateRight(p->pParent);
            }
        }
    }

    void insert(int val) {
        Node* p = root;
        Node* q = nullptr;
        while (p) {
            q = p;
            if (p->val <= val) {
                p = p->pRight;
            } else {
                p = p->pLeft;
            }
        }

        p = new Node(val);
        if (!q) {
            root = p;
        } else if (q->val <= val) {
            q->pRight = p;
        } else {
            q->pLeft = p;
        }
        p->pParent = q;
        splay(p);
    }
    bool search(int val){
    //TODO
        Node* current = root;
        Node* parent = nullptr;
        while(current) {
            if (val == current->val) {
                splay(current);
                return true;
            } else if (val < current->val) {
                parent = current;
                current = current->pLeft;
            } else if (val > current->val) {
                parent = current;
                current = current->pRight;
            }
        }
        if (parent)
            splay(parent);
        return false;
    } 
    Node* remove(int val) {
        if (!root) {
            return nullptr;
        }

        if (search(val)) {
            if (root->val != val) {
                return nullptr;
            }
        } else {
            return nullptr;
        }

        Node* removedNode = root;

        Node* tree1 = root->pLeft;
        Node* tree2 = root->pRight;

        if (!tree1) {
            root = tree2;
            if (tree2) {
                tree2->pParent = nullptr;
            }
        } else {
            tree1->pParent = nullptr;
            Node* p = tree1;
            while (p->pRight) {
                p = p->pRight;
            }
            splay(p);

            root = tree1;
            root->pRight = tree2;
            if (tree2) {
                tree2->pParent = root;
            }
        }

        if (root) {
            root->pParent = nullptr;
        }

        return removedNode;
    }
};
