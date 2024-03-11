# Multiset in C++ STL

## Introduction
A multiset is a set that allows duplicate elements. It is an associative container that contains a sorted set of objects of type Key. It is usually implemented using Red-Black Tree. It allows for logarithmic lookups, insertions, and deletions. It is generally used to store elements in sorted order.

## Declaration
```cpp
multiset <int> ms; // Creates a multiset of integers
```

## Useful Functions
**erase()** - Removes the element from the multiset. Time complexity is O(log(n)).
```cpp
ms.erase(5); // Removes all occurrences of 5 from the multiset
ms.erase(Iterator); // Removes the element pointed by the iterator 
```

**insert()** - Inserts elements into the multiset. Time complexity is O(log(n)).
```cpp
ms.insert(5); // Inserts 5 into the multiset
ms.insert(5); // You can insert duplicate elements
```

**lower_bound() and upper_bound()** - Returns an iterator pointing to the first element that is not less than/greater than the given value. Time complexity is O(log(n)).
```cpp
ms.lower_bound(5); // Returns an iterator pointing to the first element that is not less than 5
ms.upper_bound(5); // Returns an iterator pointing to the first element that is greater than 5
```

## Uses
- It is used to store elements in sorted order and allows duplicate elements, instead of using array or vector and then sorting it.
- It help to erase elements in faster way than array or vector.

# Practice Problems
<!-- - [CSES - Playlist](https://cses.fi/problemset/task/1141) -->
- [CSES - Concert Tickets](https://cses.fi/problemset/task/1091)

