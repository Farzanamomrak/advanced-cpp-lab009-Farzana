# Heap Analysis Laboratory

## Heap Property and Array Representation

A max-heap is a binary tree when every parent node must be greater than or equal to its children, the root always contains the maximum value and the tree must remain a complete binary tree.The heap is stored in a vector instead of using separate node pointers. This makes it easier to access parent and child nodes using array indices.

For an element at index i, the formulas are:

- Parent: (i - 1) / 2
- Left child: 2 * i + 1
- Right child: 2 * i + 2

## Implementation of Heap Operations

- Push
The push() function inserts a new value at the end of the vector. It then calls heapifyUp() to compare the new value with its parent and swap them when necessary. This continues until the max-heap property is restored. It has time Complexity of O(log n). In the worst case, the new value moves from the bottom of the heap to the root. Also, the height of a complete binary tree is logarithmic.

- Pop
The pop() function removes and returns the maximum value from the root. First, it saves the root value. Then it moves the last element to the root, removes the last element, and calls heapifyDown() to restore the heap property. If the heap is empty, the function throws a std::logic_error. It has a time Complexity of O(log n) aswell. It is possible fot the replacement value to move down through the height of the tree.

- Top
The top() function returns the maximum value without removing it. Since the maximum is always stored at the root, it only needs to access the first vector element. If the heap is empty, it throws a std::logic_error. It has a time Complexity of O(1). 

- Contains
The contains() function checks whether a value exists in the heap. It uses a loop to examine the elements in the vector. A heap does not maintain the complete ordering needed for binary search, so it may need to examine every element, therefore its time Complexity is O(n).

- BuildHeap
The buildHeap() function creates a heap from an existing vector of values. It copies the values into the heap and uses bottom-up heap construction. Starting from the last non-leaf node, it calls heapifyDown() until the root is reached. This approach is more efficient than inserting every element separately because it does not require each element to move from the bottom to the top. It's Time Complexity is also O(n). Although an individual heapifyDown() operation can take O(log n), most nodes are near the bottom of the tree and require fewer movements. This makes the total construction time O(n).

- HeapifyUp
The heapifyUp() function restores the max-heap property after inserting a new value.
It compares the current node with its parent. If the current node is larger, the two values are swapped. The process continues until the value reaches its correct position, which gives time Complexity of O(log n). 

- HeapifyDown
The heapifyDown() function restores the max-heap property after removing the root. It compares the current node with its left and right children. It swaps with the largest child when necessary and continues moving downward, which also has time Complexity of O(log n). 

- HeapSort
The heapSort() function returns the heap elements in ascending order. In my implementation, I create a copy of the current heap and repeatedly remove the maximum element. Since removing maximum values produces descending order, I reverse the resulting vector to get ascending order. The original heap remains unchanged. This will result in O(n log n) time complexity. There are n removal operations and each removal takes O(log n).

## complexity summary
- push: O(log n)
- pop: O(log n)
- top: O(1)
- contains: O(n)
- buildHeap: O(n)
- heapSort: O(n log n)
- heapifyUp: O(log n)
- heapifyDown: O(log n)

## Memory Complexity

The heap uses a dynamic vector to store its elements. The vector requires O(n) memory because it stores n values. The heap operations use O(1) auxiliary space, excluding any additional vector capacity or temporary storage. The heapSort() implementation creates a copy of the heap and a separate sorted vector. Therefore, heap sort uses O(n) additional memory. This shows that the heap requires O(n) storage.


### Heap vs. Binary Search Tree

A heap is useful when the main goal is to quickly retrieve the maximum value. It provides O(1) access to the maximum and O(log n) insertion and removal.
A balanced binary search tree supports searching, insertion, and deletion in O(log n) time. However, an ordinary heap does not provide efficient searching for an arbitrary value.

### Heap vs. Sorted Vector

A sorted vector allows efficient access to its maximum element, but inserting a new value may require shifting several elements.
A heap provides O(log n) insertion and removal while maintaining the maximum at the root.

### Heap vs. Priority Queue

A priority queue is an abstract data type that processes elements according to their priority.
A heap is one way to implement a priority queue. A max-heap always gives priority to the largest value.

## When a Heap Is Useful

A heap is useful when an application needs to repeatedly find and remove the highest-priority element. Heaps are especially useful when insertion and maximum retrieval need to be efficient.

Some examples include:

- Priority scheduling in operating systems.
- Finding the largest or smallest elements.
- Graph algorithms such as Dijkstra's algorithm.
- Event scheduling and task management.
- Heap sort.