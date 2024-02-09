# Meet in the middle

[CSES - Meet in the middle](https://cses.fi/problemset/task/1628/)

## Backtracking $(O(2^n))$
```cpp
#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, cnt = 0, x;
vector<int> a;

void backtrack(int i, int sum)
{
    if (sum > x) return;

    if (i == n)
    {
        if (sum == x) cnt++;
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
    cin >> n >> x;
    a.resize(n);
    for (auto &i : a) cin >> i;
    backtrack(0, 0);
    cout << cnt << endl;
}
```

## Optimize: Meet in the middle
- Divide array to 2 subarrays: A(0 -> n/2) and B(n/2 + 1 -> n - 1)
- Backtrack A
- Backtrack B
- sort B
- Iterate array A, using binary search to count the numbers of elements (x - A[i]) in B

```cpp
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define All(x) (x).begin(), (x).end()

int n, cnt = 0, x;
vector<int> A, B;
vector<int> a;

void tryX(int i, int sum)
{
    if (sum > x) return; // ==> A and B have the values <= x
    if (i == n/2 + 1) A.push_back(sum);
    else
    {
        tryX(i + 1, sum);
        tryX(i + 1, sum + a[i]);
    }
}

void tryY(int i, int sum)
{
    if (sum > x) return;
    if (i == n) B.push_back(sum);
    else
    {
        tryY(i + 1, sum);
        tryY(i + 1, sum + a[i]);
    }
}

int32_t main()
{
    cin >> n >> x;
    a.resize(n);
    for (auto &i : a) cin >> i;
    tryX(0, 0); // 0 -> n/2
    tryY(n/2 + 1, 0); // n/2 + 1 -> n - 1

    sort(B.begin(), B.end());

    // Iterate through A and B and use binary search: count the number of elements in B have value = x - A[i]
    for (int sum : A) // O(n/2) = O(n)
    {
        cnt += upper_bound(All(B), x - sum) - lower_bound(All(B), x - sum); // O(log(n/2)) = O(log(n))
    }
    cout << cnt << endl;
}
```
Time complexity: O(n.log(n))
### Explaination:
- `lower_bound` return the **first** address of element which has value is not greater than x (>=)
- `upper_bound` return the address of element which has value is greater than x (>)
- `x - A[i]` is always >= 0 because all the elements of A and B is not greater than x (<= x). Let `x - A[i] = rest`, so it has two cases:
  + **lower_bound and upper_bound return the same address**: So does not exits element of B is equal **rest**
    Example:
    ```
    rest = 4;
    int B[] = [1, 3, 5, 7];
    --> index = 2 (5) is a first element is >= and > of rest in B
    ```
  + **lower_bound and upper_bound return the other address**: So it has at least 1 element in B is equal **rest**
    Example:
    ```
    rest = 4
    int B[] = [1, 3, 4, 4, 4, 6];
    // index = 0, 1, 2, 3, 4, 5
    --> lower_bound(4) = 2, upper_bound(4) = 5
    --> upper_bound - lower_bound = 5 - 2 = 3 elements
    ```
