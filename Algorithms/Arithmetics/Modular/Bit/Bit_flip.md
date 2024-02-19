Change all the bits of a number, 1->0 and 0->1: Example 1001 -> 0110
## Formula:
```cpp
not N = (2^Len - 1) - N
```
Example: Len = 32bits, N = 1
```cpp
not 1 = (1<<31 + 1<<31 - 1) - 1 // 1<<31 + 1<<31 = 1<<32 = 2^32, should not use 1<<32 or pow(2, 32)
```
Or we can use:
```cpp
#include <limits>

int n = 1;
n = numeric_limits<int>::max() - n;
```
