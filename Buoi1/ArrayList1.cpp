template <class T>
class ArrayList {
protected:
    T* data;        // dynamic array to store the list's items
    int capacity;   // size of the dynamic array
    int count;      // number of items stored in the array
public:
    ArrayList(){capacity = 5; count = 0; data = new T[5];}
   ~ArrayList(){ delete[] data; }    
    void    add(T e);
    void    add(int index, T e);
    int     size();
    bool    empty();
    void    clear();
    T       get(int index);
    void    set(int index, T e);
    int     indexOf(T item);
    bool    contains(T item);
    T       removeAt(int index);
    bool    removeItem(T item);
    void    ensureCapacity(int index);

};
template<class T>
void ArrayList<T>::ensureCapacity(int cap){
    /* 
        if cap == capacity: 
            new_capacity = capacity * 1.5;
            create new array with new_capacity
        else: do nothing
    */
    if (cap == capacity)
    {
        int newCapacity = (capacity * 3) / 2; // You can adjust the growth factor as needed

        // Create a new array with the new capacity
        T* newData = new T[newCapacity];

        // Copy the elements from the old array to the new array
        for (int i = 0; i < count; i++) {
            newData[i] = data[i];
        }

        // Deallocate the old array
        delete[] data;

        // Update the data pointer and capacity
        data = newData;
        capacity = newCapacity;
    }
    return ;
}

template <class T>
void ArrayList<T>::add(T e) {
     //Insert an element into the end of the array. 
    int newCapacity = capacity + 1;
    T* newData = new T[newCapacity];
        // Copy the elements from the old array to the new array
    for (int i = 0; i < count; i++) {
        newData[i] = data[i];
    }
    newData[count] = e;
    // Deallocate the old array
    delete[] data;
    // Update the data pointer and capacity
    data = newData;
    capacity = newCapacity;
    count ++;
}


template<class T>
void ArrayList<T>::add(int index, T e) {
     
        //Insert an element into the array at given index.
        //if index is invalid:
        //    throw std::out_of_range("the input index is out of range!");
   if (index < 0 || index > count) {
        throw std::out_of_range("The input index is out of range!");
    } 
   int newCapacity = capacity + 1;
   T* newData = new T[newCapacity];
   for (int i=0;i < index;i++ )
   {
    newData[i] = data[i];
   }
   newData[index] = e;
   for(int i=index;i<count;i++) 
   {
    newData[i+1] = data[i];
   }
   delete[] data;
   capacity = newCapacity;
   count++;
   data = newData;
}
template<class T>
void ArrayList<T>::add(int index, T e) {
    ensureCapacity(capacity);
    if (index < 0 || index > count) {
        throw std::out_of_range("The input index is out of range!");
    } 
    int movecount = this->count - index;
    if (movecount > 0){
        memmove(this->data + index + 1,this-> data + index, movecount *sizeof(int));
    }
    this->data[index] = element;
    this->count++;
}

template<class T>
int ArrayList<T>::size() {
    /* Return the length (size) of the array */ 
    return count;
}

template<class T>
T ArrayList<T>::removeAt(int index){
    /*
    Remove element at index and return removed value 
    if index is invalid:
        throw std::out_of_range("index is out of range");
    */
    if (index < 0 || index > count) {
        throw std::out_of_range("The input index is out of range!");
    }
    T removedItem = data[index]; // Store the removed item

    // Shift elements to the left to fill the gap
    for (int i = index; i < count - 1; i++) {
        data[i] = data[i + 1];
    }

    count--; // Decrease the count to reflect the removed item

    return removedItem;
}   

template<class T>
bool ArrayList<T>::removeItem(T item){
     /* Remove the first apperance of item in array and return true, otherwise return false */
     for ( int index = 0; index < this -> count ; index ++)
    {
        if ( this -> data[index] == element ) {
        this -> removeAt ( index );
        return true ;
        }
    }
    return false ;
}

template<class T>
void ArrayList<T>::clear(){
    /* 
        Delete array if array is not NULL
        Create new array with: size = 0, capacity = 5
    */
   delete this->data[];
   this->capacity = 5;
   this->data = new int [this->capacity];
   this->count=0;
}
