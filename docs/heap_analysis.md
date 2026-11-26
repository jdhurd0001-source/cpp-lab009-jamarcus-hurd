# Heap Analysis Laboratory

## Required data structure
Students must implement a priority queue as a max-heap using a dynamic array/vector. The heap must satisfy the max-heap property:

- every parent node is greater than or equal to its children;
- the root contains the maximum value;
- the left and right child indices follow the formulas:
  - left child index = 2 * i + 1
  - right child index = 2 * i + 2
  - parent index = (i - 1) / 2

## Required operations
Students must implement and analyze:

- `push(value)`
- `pop()`
- `top()`
- `contains(value)`
- `buildHeap(values)`
- `heapSort()`
- `heapifyUp(index)`
- `heapifyDown(index)`

## Analysis requirements
Students should discuss the complexity of the following operations:

- insertion into a heap;
- deletion of the maximum;
- building a heap from an array;
- searching for an item in an array-backed heap;
- heap sort;
- memory usage.

Students should provide Big-Oh analysis for:

- push
- pop
- top
- buildHeap
- heapSort
- contains

## Expected complexity summary
- push: O(log n)
- pop: O(log n)
- top: O(1)
- buildHeap: O(n)
- heapSort: O(n log n)
- contains: O(n) in a standard heap

Students should also compare a heap to:

- a binary search tree;
- a sorted array;
- a priority queue abstraction.

## Complexity analysis

Let $n$ be the number of elements currently in the heap.

- `push(value)`: $O(\log n)$ worst-case time. The value is appended, then it travels upward along at most the height of the heap. Amortized vector growth is also relevant: occasional reallocation costs $O(n)$, but amortized insertion remains $O(\log n)$ and the vector normally does not reallocate on every insertion.
- `pop()`: $O(\log n)$ worst-case time. The root is replaced by the final element and that element travels downward along at most one root-to-leaf path.
- `top()`: $O(1)$ time because the maximum is always stored at index zero.
- `buildHeap(values)`: $O(n)$ time with bottom-up heap construction. Nodes near the bottom require little or no repair, while nodes near the top are few.
- `contains(value)`: $O(n)$ worst-case time because a heap imposes no ordering among siblings and a matching value may be anywhere in the array.
- `heapSort()`: $O(n \log n)$ time and $O(n)$ auxiliary space. The implementation copies the heap and repeatedly extracts the maximum; reversing the descending result produces ascending order.

The heap itself uses $O(n)$ contiguous storage. Heapify operations use $O(1)$ additional working space.

## Trade-offs

Compared with a sorted vector, a heap provides fast insertion and maximum extraction but does not support fast arbitrary lookup or ordered iteration. Inserting into or deleting from an arbitrary position in a sorted vector can require $O(n)$ movement, whereas a heap update is logarithmic. A sorted vector is preferable when the data is mostly static and repeated ordered scans or binary searches are important.

Compared with a balanced binary search tree, a heap is more compact, faster to construct, and has simpler array-based operations. A balanced BST supports $O(\log n)$ search and ordered traversal, but its height-balancing and node structure add implementation and storage overhead. An unbalanced BST can degrade to $O(n)$ operations.

A heap is the usual implementation of a priority queue. It is preferable when only the highest-priority item must be accessible quickly and the priority set changes frequently. It is less suitable when members must be searched by key efficiently or when all elements must remain sorted.
