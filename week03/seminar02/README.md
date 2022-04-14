## Quick sort
In merge sort we divide list in the middle every time.

In quick sort we divide list not in the middle every time. But instead we choose pivot and swaping values on right and left.

**runtime of the algorithm**: T(N) = 2T(N/2) + O(N) = O(NlogN)

In worst scenario when all elements are sorted already algorithm will work for O(N^2) because we partition N times.

**runtime of the algorithm for the worst scenario**: T(N) = T(N-1) + O(N) = T(N-1) + N = T(N-2) + N - 1 + N = T(N-2) + 2N

we call this N times, so T(N) = N^2

So, sometimes people use another algorithm when there are less then 10 elements or so. For example, insertionsort.
![screen-gif](../../static/week03/seminar02/quick_sort_example.gif)

## Binary Heap

Could be min or max

Binary Heap - Complete binary tree. We are goin top-down-left-rigth.

When we add value to a tree we should contain the structure of the heap. So we swap parent and child until we meet the condition for min/max heap.

![heap1](../../static/week03/seminar02/heap1.jpg)
![heap2](../../static/week03/seminar02/heap2.jpg)