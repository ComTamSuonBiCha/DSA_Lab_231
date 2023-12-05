1.
static T* Partition(T* start, T* end) 
{
    const T pivot = *start;
    T* j = end;
    T* i = start;
    do {
        do i++; while(*i < pivot);
        do j--; while(*j > pivot);
        const T temp = *i;
        *i = *j;
        *j = temp;
    }while(i < j);
    T temp = *i;
    *i = *j;
    *j = temp;
    temp = *start;
    *start = *j;
    *j = temp;
    return j;
}


static void QuickSort(T* start, T* end) 
{
    if (start == end) return;
    T* pivotPos = Partition(start,end);
    cout << (pivotPos - start) << " ";
    QuickSort(start,pivotPos);
    QuickSort(pivotPos + 1,end);
}
2.
// You must use the nodes in the original list and must not modify ListNode's val attribute. 
// Hint: You should complete the function mergeLists first and validate it using our first testcase example

// Merge two sorted lists
ListNode* mergeLists(ListNode* a, ListNode* b) {
    ListNode// You must use the nodes in the original list and must not modify ListNode's val attribute. 
// Hint: You should complete the function mergeLists first and validate it using our first testcase example

// Merge two sorted lists
ListNode* mergeLists(ListNode* l1, ListNode* l2) 
{
    ListNode dummy (0);
    ListNode *tail = &dummy;

    while (l1 != nullptr && l2 != nullptr) 
    {
        if (l1->val < l2->val) 
        {
            tail->next = l1;
            l1 = l1->next;
        } 
        else 
        {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    tail->next = (l1 != nullptr) ? l1 : l2;
    return dummy.next;
}

// Sort and unsorted list given its head pointer
ListNode* mergeSortList(ListNode* head) 
{
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = nullptr;

    while (fast != nullptr && fast->next != nullptr) 
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    prev->next = nullptr; 

    ListNode* left = mergeSortList(head);
    ListNode* right = mergeSortList(slow);

    return mergeLists(left, right);
} dummy(0);
    ListNode* current=&dummy;
    while(a!=nullptr&&b!=nullptr) {
        if (a->val < b->val){
            current->next=a;
            a=a->next;
        } else {
            current->next=b;
            b=b->next;
        }
        current=current->next;
    }
    if (a!=nullptr){
        current->next=a;
    }else{
        current->next=b;
    }
    return dummy.next;
}

ListNode* findMiddle(ListNode* head) {
    ListNode* slow=head;
    ListNode* fast=head;
    ListNode* prev=nullptr;
    while(fast!=nullptr&& fast->next!=nullptr) {
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    if (prev) {
        prev->next=nullptr; // Split the list into two halves
    }
    return slow;
}

// Sort and unsorted list given its head pointer
ListNode* mergeSortList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode* middle = findMiddle(head);
    ListNode* firstHalf = mergeSortList(head);
    ListNode* secondHalf = mergeSortList(middle);
    return mergeLists(firstHalf, secondHalf);
}
3.
static void merge(T* start, T* middle, T* end) {
    // TODO
    int size1 = middle - start + 1;
    int size2 = end - middle;
    int i1 = 0, i2 = 0, k = 0;
    int* l = new int[size1];
    int* r = new int[size2];
    for(int i = 0; i < size1; i++){
        l[i] = start[i];
    }
    for(int j = 0; j <size2; j++){
        r[j] = middle[j+1];
    }
    while(i1<size1 && i2 < size2){
        if(l[i1] <= r[i2]){
            start[k++] = l[i1++];
        }
        else{
            start[k++] = r[i2++];
        }
    }
    while(i1<size1){
        start[k++] = l[i1++];
    }
    while(i1<size2){
        start[k++] = r[i2++];
    }
}

static void InsertionSort(T* start, T* end) {
    // TODO
    int n = end - start;
    for(int i = 1; i<n;i++){
        for(int j = i; j>0 && start[j] < start[j-1]; j--){
            swap(start[j],start[j-1]);
        }
    }
}

static void TimSort(T* start, T* end, int min_size) {
    // TODO
    // You must print out the array after using insertion sort and everytime calling method merge.
    int n = end - start;
    T*s = start, *e=end;
    for(int i = 0; i < n; i+=min_size){
        if(i+min_size<=n){
            InsertionSort(s,s+min_size);
            s += min_size;
        }
        else InsertionSort(s,e);
    }
    cout << "Insertion Sort: ";
    printArray(start,end);
    int count = 0;
    for (int gap = min_size; gap < n; gap*=2){
		s = start;
		for (int j = 0; j < n; j+=2*gap){
			T* mid = s + gap - 1;
			if (j + gap - 1 >= n) mid = end - 1;
			if (j + 2 * gap - 1 < n)
				e = s + 2 * gap - 1;
			else e = end - 1;
			merge(s, mid, e);
			cout << "Merge " << ++count << ": ";
			printArray(start,end);
			s += 2 * gap;
		}
	}
}
4.
string minDiffPairs(int* arr, int n) 
{
    sort (arr, arr + n);
    int minDiff = INT32_MAX;
    
    for (int i = 1; i < n; ++i) 
    {
        int diff = arr[i] - arr[i - 1];
        minDiff = min (minDiff, diff);
    }

    bool found = false;
    for (int i = 1; i < n; ++i) 
    {
        int diff = arr[i] - arr[i - 1];
        if (diff == minDiff) 
        {
            if (found) cout << ", ";
            cout << "(" << arr[i - 1] << ", " << arr[i] << ")";
            found = true;
        }
    }
    
    cout << endl;

    return "";
}
5.
#include <vector>

struct Element {
    int value;  
    int frequency;
    int index;  
};

bool compareFrequency(const Element& a, const Element& b) {
    if (a.frequency == b.frequency) {
        return a.index < b.index;  
    }
    return a.frequency > b.frequency;  
}

void sortByFrequency(int* arr, int n) {
    std::vector<Element> elements;
    for (int i = 0; i < n; ++i) {
        bool found = false;
        for (auto& element : elements) {
            if (element.value == arr[i]) {
                element.frequency++;
                found = true;
                break;
            }
        }
        if (!found) {
            elements.push_back({arr[i], 1, i});  
        }
    }

    std::sort(elements.begin(), elements.end(), compareFrequency);

    int index = 0;
    for (const auto& element : elements) {
        for (int i = 0; i < element.frequency; ++i) {
            arr[index++] = element.value;
        }
    }
}
6.
void closestKPoints(Point points[], int n, Point &des_point, int k){
    //TODO
    int i, j;
    int max = 0;
    Point tmp;
    for (i = 1; i < n; i++) {
        max = pow(points[i].x - des_point.x, 2) + pow(points[i].y - des_point.y, 2);
        tmp = points[i];
        j = i - 1;
        while (j >= 0 && pow(points[j].x - des_point.x, 2) + pow(points[j].y - des_point.y, 2) > max) {
            points[j + 1] = points[j];
            j = j - 1;
        }
        points[j + 1] = tmp;
    }
    if(k > n) k = n;
    for (int i = 0; i < k; i++) {
        points[i].display();
            cout << endl;
    }
}
7.
// STUDENT ANSWER BEGIN
// You can define other functions here to help you.

void BFS()
{
    if (!root){  
    return; 
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* current=q.front();
        q.pop();
        cout<<current->value<<" "; 
        if (current->pLeft){
            q.push(current->pLeft);
        }
        if (current->pRight){
            q.push(current->pRight);
        }
    }
}
// STUDENT ANSWER END
8.
int longestPathSumUtil(BTNode* root, int& maxPathSum, int& maxPathLength, int currentPathSum, int currentPathLength) {
    if (root == nullptr) {
        return 0;
    }
    currentPathSum += root->val;
    currentPathLength++;
    if (root->left == nullptr && root->right == nullptr) {
        if (currentPathLength > maxPathLength || (currentPathLength == maxPathLength && currentPathSum > maxPathSum)) {
            maxPathLength = currentPathLength;
            maxPathSum = currentPathSum;
        }
    }
    longestPathSumUtil(root->left, maxPathSum, maxPathLength, currentPathSum, currentPathLength);
    longestPathSumUtil(root->right, maxPathSum, maxPathLength, currentPathSum, currentPathLength);

    return maxPathSum;
}

int longestPathSum(BTNode* root) {
    int maxPathSum = 0;
    int maxPathLength = 0;
    longestPathSumUtil(root, maxPathSum, maxPathLength, 0, 0);
    return maxPathSum;
}
9.
int lowestAncestor(BTNode* root, int a, int b) {
    if (root == nullptr) {
        return -1;
    }
    if (root->val == a || root->val == b) {
        return root->val;
    }
    int leftAncestor = lowestAncestor(root->left, a, b);
    int rightAncestor = lowestAncestor(root->right, a, b);
    if (leftAncestor != -1 && rightAncestor != -1) {
        return root->val;
    }
    return (leftAncestor != -1) ? leftAncestor : rightAncestor;
}
10.
const int MOD=27022001;
int sumDigitPathUtil(BTNode* root, int currentPathNumber) {
    if (root == nullptr) {
        return 0;
    }
    currentPathNumber = (currentPathNumber * 10 + root->val) % MOD;
    if (root->left == nullptr && root->right == nullptr) {
        return currentPathNumber;
    }

    int leftSum = sumDigitPathUtil(root->left, currentPathNumber) % MOD;
    int rightSum = sumDigitPathUtil(root->right, currentPathNumber) % MOD;
    return (leftSum + rightSum) % MOD;
}

int sumDigitPath(BTNode* root) {
    if (root == nullptr) {
        return 0;
    }
    int result = sumDigitPathUtil(root, 0);
    return result;
}
11.
int getHeight() {
        return getHeightHelper(root);
    }
int getHeightHelper(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        int leftHeight = getHeightHelper(node->pLeft);
        int rightHeight = getHeightHelper(node->pRight);
        return 1 + max(leftHeight, rightHeight);
    }
string preOrder() {
        stringstream ss;
        preOrderHelper(root, ss);
        return ss.str();
}
void preOrderHelper(Node* node, stringstream& ss) {
        if (node) {
            ss << node->value << " ";
            preOrderHelper(node->pLeft, ss);
            preOrderHelper(node->pRight, ss);
        }
}
string inOrder() {
        stringstream ss;
        inOrderHelper(root, ss);
        return ss.str();
}
void inOrderHelper(Node* node, stringstream& ss) {
        if (node) {
            inOrderHelper(node->pLeft, ss);
            ss << node->value << " ";
            inOrderHelper(node->pRight, ss);
        }
}
string postOrder() {
        stringstream ss;
        postOrderHelper(root, ss);
        return ss.str();
}
void postOrderHelper(Node* node, stringstream& ss) {
        if (node) {
            postOrderHelper(node->pLeft, ss);
            postOrderHelper(node->pRight, ss);
            ss << node->value << " ";
        }
}
12.
void add(T value) {
        root = addRec(root, value);
}
Node* findMin(Node* node) {
    Node* current = node;
    while (current && current->pLeft) {
        current = current->pLeft;
    }
    return current;
}
Node* addRec(Node* root, T value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->value) {
        root->pLeft = addRec(root->pLeft, value);
    } else if (value == root->value) {
        root->pLeft = addRec(root->pLeft, value);
    } else {
        root->pRight = addRec(root->pRight, value);
    }

    return root;
}
Node* deleteNodeRec(Node* root, T value) {
    if (root == nullptr) {
        return root;
    }
    if (value < root->value) {
        root->pLeft = deleteNodeRec(root->pLeft, value);
    } else if (value > root->value) {
        root->pRight = deleteNodeRec(root->pRight, value);
    } else {
        if (root->pLeft == nullptr) {
            Node* temp = root->pRight;
            delete root;
            return temp;
        } else if (root->pRight == nullptr) {
            Node* temp = root->pLeft;
            delete root;
            return temp;
        }

        Node* temp = findMin(root->pRight);
        root->value = temp->value;
        root->pRight = deleteNodeRec(root->pRight, temp->value);
    }

    return root;
}
void deleteNode(T value) {
    root = deleteNodeRec(root, value);
}
13.
vector<int> levelAlterTraverse(BSTNode* root) {
    // STUDENT ANSWER
    vector<int> result;
    if (root == nullptr) {
        return result;
    }
    queue<BSTNode*> q;
    q.push(root);
    bool leftToRight = true; 
    while (!q.empty()) {
        int levelSize = q.size();
        vector<int> levelNodes;
        for (int i = 0; i < levelSize; i++) {
            BSTNode* current = q.front();
            q.pop();
            if (leftToRight) {
                levelNodes.push_back(current->val);
            } else {
                levelNodes.insert(levelNodes.begin(), current->val);
            }

            if (current->left) {
                q.push(current->left);
            }
            if (current->right) {
                q.push(current->right);
            }
        }
        result.insert(result.end(), levelNodes.begin(), levelNodes.end());
        leftToRight = !leftToRight;  
    }
    return result;
}
14.
void kthSmallestUtil(BSTNode* root, int& k, int& result) {
    if (root == nullptr || k == 0) {
        return;
    }
    kthSmallestUtil(root->left, k, result);
    k--;
    if (k == 0) {
        result = root->val;
        return;
    }
    kthSmallestUtil(root->right, k, result);
}

int kthSmallest(BSTNode* root, int k) {
    int result = -1;
    kthSmallestUtil(root, k, result);
    return result;
}
15.
int rangeCount(BTNode* root, int lo, int hi) {
     if (root == nullptr) {
        return 0;
    }
    int count = 0;
    if (root->val >= lo && root->val <= hi) {
        count++;
    }
    count += rangeCount(root->left, lo, hi);
    count += rangeCount(root->right, lo, hi);
    return count;
}
16.
int singleChild(BSTNode* root) {
    // STUDENT ANSWER
        if (root == nullptr) {
        return 0;
    }
    int count = 0;
    if ((root->left == nullptr && root->right != nullptr) || (root->left != nullptr && root->right == nullptr)) {
        count++;
    }
    count += singleChild(root->left);
    count += singleChild(root->right);
    return count;
}
17.
BSTNode* subtreeWithRange(BSTNode* root, int lo, int hi) {
    // STUDENT ANSWER
        if (root == nullptr) {
        return nullptr;
    }
    if (root->val < lo){
        return subtreeWithRange(root->right, lo, hi);
    } else if (root->val > hi){
        return subtreeWithRange(root->left, lo, hi);
    }
    root->left = subtreeWithRange(root->left, lo, hi);
    root->right = subtreeWithRange(root->right, lo, hi);
    return root;
}

int maxOfSubarray(vector<int> &nums, int i) {
    int max = nums[i];
    for (int j=i;j<=i+2;j++) {
        if (max < nums[j]) max = nums[j];
    }
    return max;
}
int sumOfMaxSubarray(vector<int>& nums, int k) {
    // STUDENT ANSWER
    int sum = 0;
    for (int i=0;i<nums.size();i++) {
        sum += maxOfSubarray(nums,i);
    }
    return sum;
}