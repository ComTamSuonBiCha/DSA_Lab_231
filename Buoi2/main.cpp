#include<iostream>
#include<string>
#include<sstream>
using namespace std;
template <class T>
class DLinkedList {
public:
    class Node; // Forward declaration
protected:
    Node* head;
    Node* tail;
    int count;
public:
    DLinkedList(){};
    ~DLinkedList(){};
    void    add(const T &e);
    void    add(int index, const T &e);
    int     size();
    bool    empty();
    T       get(int index);
    void    set(int index, const T &e);
    int     indexOf(const T &item);
    bool    contains(const T &item);
    T       removeAt(int index);
    bool    removeItem(const T &item);
    void    clear();
public:
    class Node
    {
    private:
        T data;
        Node *next;
        Node *previous;
        friend class DLinkedList<T>;

    public:
        Node()
        {
            this->previous = NULL;
            this->next = NULL;
        }

        Node(const T &data)
        {
            this->data = data;
            this->previous = NULL;
            this->next = NULL;
        }
    };

};


template <class T>
void DLinkedList<T>::add(const T& e) {
    /* Insert an element into the end of the list. */
    if (count == 0)
    {
        Node* newNode = new Node(e);
        head = newNode;
        tail = newNode;
        tail->next=NULL;
        ++(this->count);
        return;
    }
    Node* newNode = new Node(e);
    tail->next=newNode;
    newNode->previous = tail;
    newNode->next=nullptr;
    tail = newNode;
    ++(this->count);
    return;
}

template<class T>
void DLinkedList<T>::add(int index, const T& e) {
    /* Insert an element into the list at given index. */ 
    if (count == 0) {add(e);return;}
    if (index == 0)
    {
        Node* newNode = new Node(e);
        newNode->next = head;
        head->previous = newNode;
        head = newNode;
        ++(this->count);
        return; 
    }
    if (index == this->count) {add(e); return;}
    int idx = 0;
    Node* front = head;
    Node* back = NULL;
    for (;front != NULL; back = front, front = front->next, ++idx)
    {
        if (idx == index)
        {
            Node* newNode = new Node (e);
            ++(this->count);
            back->next = newNode;
            newNode->next = front;
            front->previous = newNode;
            return;
        }
    }
}

template<class T>
int DLinkedList<T>::size() {
    /* Return the length (size) of list */ 
    return this->count;
}


template<class T>
T DLinkedList<T>::get(int index) {
    /* Give the data of the element at given index in the list. */
    if (count == 0) return -1;
    if (index == this->count - 1) return tail->data;
    if (index == 0) return head->data;
    int idx = 0;
    for (Node* h = head; h != NULL; h = h->next, ++idx)
    {
        if (idx == index) return h->data;
    }
    return -1;
}

template <class T>
void DLinkedList<T>::set(int index, const T& e) {
    /* Assign new value for element at given index in the list */
    if (count == 0) return;
    if (index == 0)
    {
        head->data = e;
        return;
    }
    if (index == this->count - 1)
    {
        tail->data = e;
        return;
    }
    int idx = 0;
    for (Node* h = head; h != NULL; h = h->next, ++idx)
    {
        if (idx == index)
        {
            h->data = e;
            return;
        }
    }
}

template<class T>
bool DLinkedList<T>::empty() {
    /* Check if the list is empty or not. */
    if (this->count == 0) return true;
    else return false;
}

template<class T>
int DLinkedList<T>::indexOf(const T& item) {
    /* Return the first index wheter item appears in list, otherwise return -1 */
    if (count == 0) return -1;
    int idx=0;
    for (Node* h = head; h!= NULL; h = h->next, ++idx)
    {
        if (h->data == item)
        {
            return idx;
        }
    }
    return -1;
}

template<class T>
bool DLinkedList<T>::contains(const T& item) {
    /* Check if item appears in the list */
    if (count == 0) return -1;
    for (Node* h = head; h!= NULL; h=h->next)
    {
        if (h->data == item)
        {
            return true;
        }
    }
    return false;
}

template<class T>
T DLinkedList<T>::removeAt(int index)
{
    T luu;
    if (index == 0)
    {
        Node* temp = head;
        luu = head->data;
        head = head->next;
        head->previous = NULL;
        delete temp;
        --(this->count);
        return luu;
    }
    else if (index == count - 1)
    {
        Node* temp = tail;
        luu = tail->data;
        tail = tail->previous;
        if (tail)
            tail->next = nullptr;
        delete temp;
        --count;
        return luu;
    }
    else
    {
        int currentIndex = 0;
        Node* current = head;
        
        while (currentIndex < index && current)
        {
            current = current->next;
            currentIndex++;
        }
        
        if (current)
        {
            Node* temp = current;
            luu = current->data;
            current->previous->next = current->next;
            current->next->previous = current->previous;
            delete temp;
            --count;
            return luu;
        }
    }
    return luu;
}
template<class T>
bool DLinkedList<T>::removeItem(const T &item)
{
    Node* curr = head;
    while (curr != nullptr)
    {
        if (curr->data == item)
        {
            if (curr->previous)
            {
                curr->previous->next = curr->next;
            }
            if (curr->next)
            {
                curr->next->previous = curr->previous;
            }
            if (curr == head)
            {
                head = curr->next;
            }
            if (curr == tail)
            {
                tail = curr->previous;
            }
            delete curr;
            count--;
            return true;
        }
        curr = curr->next;
    }
    return false;
}
template<class T>
void DLinkedList<T>::clear()
{
    while (head != nullptr)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
    count = 0;
}
int main()
{
    DLinkedList<int> list;
    int values[] = {10, 15, 2, 6, 4, 7, 40, 8};
    int index[] = {0, 1, 5, 3, 2, 1, 1, 0};

    for (int idx = 0; idx < 8; idx++)
    list.add(values[idx]);

    for(int idx=0; idx < 8; idx++){
    int idxRemoved = index[idx];
    int rs = list.removeAt(idxRemoved);
    }
    cout << list.empty();   
    return 0;
}