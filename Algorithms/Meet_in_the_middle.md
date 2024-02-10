# Meet in the middle

[CSES - Meet in the middle](https://cses.fi/problemset/task/1628/)

## Backtracking $(O(2^n))$
```cpp
#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, cnt = 0, target;
vector<int> a;

void backtrack(int i, int sum)
{
    if (sum > target) return;

    if (i == n)
    {
        if (sum == target) cnt++;
        else return;
    }
    
    else
    {
        backtrack(i+1, sum + a[i]); // include a[i]
        backtrack(i+1, sum); // exclude
    }
}

int32_t main()
{
    cin >> n >> target;
    a.resize(n);
    for (auto &i : a) cin >> i;
    backtrack(0, 0);
    cout << cnt << endl;
}
```

## Optimize: Meet in the middle
- Divide array to 2 subarrays: A: [0 -> n/2] and B: [n/2 + 1 -> n]
- Backtrack A
- Backtrack B
- Using binary search or two pointers to count the numbers of element is satisfying the condition
  
### Using binary search
- sort B
- Iterate array A, for each sumA we using binary search to count the numbers of elements (x - A[i]) in B.
It's more optimistic because $O(2^{\frac{n}{2}}) = O(\sqrt{2^n})$

### Using two pointers
- Let rest = target - sumA ==> count B[i] which satisfying B[i] = rest = target - sumA
- Use 2 pointers: j1 (B[j1] > rest) and j2 (B[j2] >= rest), (j1 & j2) < B.size()
- Iterate array A, with each sum of A, while j1 and j2 are satisfy the condition, we increase two pointers
- (j2 - j1) is the numbers of elements satisfying of each iteration
  
> [!NOTE]
> Because A is decreasing and B is ascending ==> A[i] > A[i+1], B[i] < B[i+1] ==> target - A[i] = rest1 < target - A[i+1] = rest2 ==> rest1 < rest2. So j1 and j2 are alway ascending(shift to the right of array)

### Code:
```cpp
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define All(x) (x).begin(), (x).end()

int n, cnt = 0, target;
vector<int> A, B;
vector<int> a;

void tryX(int i, int sum)
{
    if (sum > target) return; // ==> A and B have the values <= x
    if (i == n/2 + 1) A.push_back(sum);
    else
    {
        tryX(i + 1, sum);
        tryX(i + 1, sum + a[i]);
    }
}

void tryY(int i, int sum)
{
    if (sum > target) return;
    if (i == n) B.push_back(sum);
    else
    {
        tryY(i + 1, sum);
        tryY(i + 1, sum + a[i]);
    }
}

int32_t main()
{
    cin >> n >> target;
    a.resize(n);
    for (auto &i : a) cin >> i;
    tryX(0, 0); // [0, n/2] - O(2^K), K = n/2
    tryY(n/2 + 1, 0); // [n/2 + 1, n-1] - O(2^K)

    sort(B.begin(), B.end()); // O(n.log(n))

    // Iterate through A and B and use binary search: count the number of elements in B have value = target - A[i]
    for (int sumA : A) // O(n/2) = O(n)
    {
        cnt += upper_bound(All(B), target - sumA) - lower_bound(All(B), target - sumA); // O(log(n/2)) = O(log(n))
    }
    cout << cnt << endl;
}
```

### Time complexity: $O(2^K + 2^K + n.log(n)) = O(2^K)$ 

### Explaination:
- `lower_bound` return the **first** address of element which has value is not greater than x (>=)
- `upper_bound` return the address of element which has value is greater than x (>)
- `x - A[i]` is always >= 0 because all the elements of A and B is not greater than x (<= x). Let `x - A[i] = rest`, so it has two cases:
  + **lower_bound and upper_bound return the same address**: So `lower_bound - upperbound = 0` ==> Does not exits element of B is equal **rest**
    ```
    rest = 4;
    int B[] = [1, 3, 5, 7];
    --> index = 2 (5) is a first element is >= and > of rest in B
    ```
    
  + **lower_bound and upper_bound return the other address**: So `lower_bound - upper_bound >= 1` ==> It has at least 1 element in B is equal **rest** 
    ```
    rest = 4
    int B[] = [1, 3, 4, 4, 4, 6];
    // index = 0, 1, 2, 3, 4, 5
    --> lower_bound(4) = 2, upper_bound(4) = 5
    --> upper_bound - lower_bound = 5 - 2 = 3 elements
    ```
