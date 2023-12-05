#include<iostream>
using namespace std;
template <class T>
class SLinkedList {
public:
    class Node; // Forward declaration
protected:
    Node* head;
    Node* tail;
    int count;
public:
    SLinkedList();
    ~SLinkedList();
    void    add(const T &e);
    void    add(int index,const T &e);
    int     size();
    bool    empty();
    int     size();
    void    clear();
    T       get(int index);
    void    set(int index,const T &e);
    int     indexOf(const T &item);
    bool    contains(const T &item);
    T       removeAt(int index);
    bool    removeItem(const T &item);
public:
    class Node {
    private:
        T data;
        Node* next;
        friend class SLinkedList<T>;
    public:
        Node() {
            next = 0;
        }
        Node(Node* next) {
            this->next = next;
        }
        Node(T data, Node* next = NULL) {
            this->data = data;
            this->next = next;
        }
    };
};

template <class T>
void SLinkedList<T>::add(const T& e) {
    /* Insert an element into the end of the list. */
    Node* pNew = new Node(e,nullptr);
    if (head=nullptr)
    {
        head = pNew;
        tail = pNew;
    }
    else {
        tail->next = pNew;
        tail = pNew;
    }
    count ++;
}

template<class T>
void SLinkedList<T>::add(int index, const T& e) {
    /* Insert an element into the list at given index. */ 
    if (index < 0 || index > count) {
        throw std::out_of_range("Index out of bounds");
    }
    if (index == count) {
        // If the index is equal to the count, add to the end of the list.
        add(e);
    } else {
        Node* newNode = new Node(e);
        if (index == 0) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
        count++;
    }
}

template<class T>
int SLinkedList<T>::size() {
    /* Return the length (size) of list */ 
    return count;
}
template <class T>
T SLinkedList<T>::removeAt(int index)
{
    T luu;
    /* Remove element at index and return removed value */
    if(index == 0){
        Node* tmp = head;
        luu = head->data;
        head = head->next;
        delete tmp;
        count--;
        return luu;
    }
    else{
        Node* tmp = head;
        for(int i = 0; i < index - 1; i++){
            tmp = tmp->next;
        }
        luu = tmp->next->data;
        Node* tmp1 = tmp->next;
        tmp->next = tmp->next->next;
        delete tmp1;
        count--;
    }
    Node* tmp3 = head;
    while(tmp3->next != nullptr){
        tmp3 = tmp3->next;
    }
    tail = tmp3;
    tmp3 = nullptr;
    delete tmp3;
    return luu;
}

template <class T>
bool SLinkedList<T>::removeItem(const T& item)
{
    
    /* Remove the first apperance of item in list and return true, otherwise return false */
    if(head->data == item){
        removeAt(0);
        return true;
    }
    Node* tmp = head;
    Node* tmp1 = head->next;
    bool check = false;
    while(tmp1){
        if(tmp1->data ==item){
            tmp->next = tmp1->next;
            delete tmp1;
            count--;
            check = true;
            break;
        }
        tmp = tmp->next;
        tmp1 = tmp1->next;
    }
    Node* tmp3 = head;
    while(tmp3->next != nullptr){
        tmp3 = tmp3->next;
    }
    tail = tmp3;
    tmp3 = nullptr;
    delete tmp3;
    
    return check;

}

template<class T>
void SLinkedList<T>::clear(){
    /* Remove all elements in list */
    Node* tmp = head;
    int count = 0;
    while(tmp){
        count++;
        tmp = tmp->next;
    }
    for(int i = 0; i < count; i++){
        removeAt(0);
    }
    head = tail = nullptr;
    count = 0;
}

template <class T>
T SLinkedList<T>::get(int index) {
    /* Give the data of the element at the given index in the list. */
    if (index < 0 || index >= count) {
        throw std::out_of_range("Index out of bounds");
    }

    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

template <class T>
void SLinkedList<T>::set(int index, const T& e) {
    /* Assign a new value for the element at the given index in the list */
    if (index < 0 || index >= count) {
        throw std::out_of_range("Index out of bounds");
    }

    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    current->data = e;
}

template <class T>
bool SLinkedList<T>::empty() {
    /* Check if the list is empty or not. */
    return count == 0;
}

template <class T>
int SLinkedList<T>::indexOf(const T& item) {
    /* Return the first index where item appears in the list, otherwise return -1 */
    int index = 0;
    Node* current = head;
    while (current != nullptr) {
        if (current->data == item) {
            return index;
        }
        current = current->next;
        index++;
    }
    return -1; // Item not found
}

template <class T>
bool SLinkedList<T>::contains(const T& item) {
    /* Check if item appears in the list */
    Node* current = head;
    while (current != nullptr) {
        if (current->data == item) {
            return true;
        }
        current = current->next;
    }
    return false; // Item not found
}
class LLNode {
public:
    int val;
    LLNode* next;
    LLNode(); // Constructor: val = 0, next = nullptr
    LLNode(int val, LLNode* next); // Constructor with customized data
};
LLNode* reverseLinkedList(LLNode* head) {
    LLNode* prev = nullptr;
    LLNode* current = head;
    LLNode* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev; // 'prev' now points to the new head of the reversed list
}
LLNode* addLinkedList(LLNode* l0, LLNode* l1) {
    int carry = 0;
    LLNode* resultHead = nullptr;
    LLNode* current = nullptr;

    while (l0 || l1 || carry) {
        int sum = (l0 ? l0->val : 0) + (l1 ? l1->val : 0) + carry;
        carry = sum / 10; // Calculate the carry for the next iteration
        int digit = sum % 10;

        // Create a new node with the calculated digit
        LLNode* newNode = new LLNode(digit, nullptr);

        if (!resultHead) {
            resultHead = newNode;
            current = newNode;
        } else {
            current->next = newNode;
            current = newNode;
        }

        // Move to the next digits in both input lists if available
        if (l0) l0 = l0->next;
        if (l1) l1 = l1->next;
    }
    return resultHead;
}