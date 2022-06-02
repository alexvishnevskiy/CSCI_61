## Searching
### Linear
Time complexity: O(N)
### Binary
Every time divide by two and search in the part that is lower that the target.

start = 0, end = 8, middle = (start + end)/2

Algorithm:

    while (start <= end):
        If A[middle] == target
            return middle
        If A[middle] < target:
            start = middle + 1
        elif A[middle] > target:
            end = middle - 1
        else:
            return middle
    return -1

The recursive function that is **tail recursive**, the compiler will compile it as for loop. Tail recursive is the recursive function the last function which is the recursive function itself.

Runtime:

    O(logN) - for iterative approach
    T(N) = T(N/2) + C = O(logN) - for recursive

### Hashing
"one" -> 1

"two" -> 2

"three" -> 3

    vector<string> data;
    data[hash("one")] = "one";
    data[hash("two")] = "two";
    data[hash("three")] = "three";

How to find using O(1)?

We can use hash functions and arrays.

data[hash(str)] = ?

Code: https://github.com/alexvishnevskiy/CSCI_61/tree/master/week05/seminar01