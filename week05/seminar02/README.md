## Open address hashing

Hash table should have hash function.

    struct hashdata{
        int key;
        data;
    };

    hash_function():
        key -> index

Open address hashing looks for the open spot to store, if the address is occupied, then move one by one to another memory spot.

### Runtime
            add            find/remove
    array | O(1)         | O(N)
    hash  | O(1) -> O(N) | O(1) -> O(N)

**How to avoid collisions?**

We can use linked list for the same index. So, apart from open address hashing we store linked list in the same index.
    
    [4]
     |
    [2][0]   [6]
     |  |     |
    [1][2][3][4]

**How to look for needed index?**

Look for the incoming index until you encounter empty spot. If you encounter empty spot, then there is no this element in the array.

**What is the best number for the table size to avoid collisions?**

Prime number is the best number to avoid collisions.

**Can we increase the capacity of the table?**

We can, but we should re-hash. So it's better not to increase the capacity.

**How to check if the spot doesn't have any data?**

We can use pointers and check. Or we can use some euristhics.

Code: https://github.com/alexvishnevskiy/CSCI_61/tree/master/week05/seminar02