#pragma once
#include "sorting.h"

// heapSort
template <typename _T> void heap_sort(std::vector<_T>& v, int n);


// function to heapify the tree
template <typename _T> 
void _heapify(std::vector<_T>& v, int n, int root)
{
    int largest = root; // root is the largest element
    int l = 2*root + 1; // left = 2*root + 1
    int r = 2*root + 2; // right = 2*root + 2
    
    // If left child is larger than root
    if (l < n && v[l] > v[largest])
    largest = l;
    
    // If right child is larger than largest so far
    if (r < n && v[r] > v[largest])
    largest = r;
  
    // If largest is not root
    if (largest != root)
        {
        //swap root and largest
        std::swap(v[root], v[largest]);
    
        // Recursively heapify the sub-tree
        _heapify(v, n, largest);
        }
}
  
// implementing heap sort
template <typename _T> 
void heap_sort(std::vector<_T>& v, int n)
{
    // build heap
    for (int i = n / 2 - 1; i >= 0; i--) {
    _heapify(v, n, i);
    }
    
    // extracting elements from heap one by one
    for (int i=n-1; i>=0; i--) {
        // Move current root to end
        std::swap(v[0],  v[i]);
    
        // again call max heapify on the reduced heap
        _heapify(v, i, 0);
    }
}


/*
heapify(array)
   Root = array[0]
   Largest = largest( array[0] , array [2 * 0 + 1]. array[2 * 0 + 2])
   if(Root != Largest)
       Swap(Root, Largest)

Example of “heapify”:
        30(0)                 
       /   \         
    70(1)   50(2)

Child (70(1)) is greater than the parent (30(0))

Swap Child (70(1)) with the parent (30(0))
        70(0)                 
       /   \         
    30(1)   50(2)


Heap Sort Algorithm for sorting in increasing order: 
1. Build a max heap from the input data. 
2. At this point, the largest item is stored at the root of the heap. Replace it with the last item of the heap followed by reducing the size of heap by 1. Finally, heapify the root of the tree. 
3. Repeat step 2 while the size of the heap is greater than 1.


Input data: 4, 10, 3, 5, 1
         4(0)
        /   \
     10(1)   3(2)
    /   \
 5(3)    1(4)

The numbers in bracket represent the indices in the array 
representation of data.

Applying heapify procedure to index 1:
         4(0)
        /   \
    10(1)    3(2)
    /   \
5(3)    1(4)

Applying heapify procedure to index 0:
        10(0)
        /  \
     5(1)  3(2)
    /   \
 4(3)    1(4)
The heapify procedure calls itself recursively to build heap
 in top down manner.
*/
