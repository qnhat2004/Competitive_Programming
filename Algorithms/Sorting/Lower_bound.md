- Problem: [Concert Tickets - CSES](https://cses.fi/problemset/task/1091)

- Solution: 
    - Find a ticket with the nearest possible price such that it does not exceed the max price -> find the ticket that is less or equal to the max price
    - If the max is 5, and the price is 2 3 4, then the answer is 4. We can see, if we convert all the prices to negative: [-2,-3,-4] and the max is -5, we can use **lower_bound** to find the element is greater or equal to -5, then the answer is -4, we can convert it again to positive. It's the answer we need.

```cpp
void solve()
{
    multiset<int> s;
    int n, m;
    cin >> n >> m;
    int h[n];
    
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
        s.insert(-h[i]);
    }  
    
    int tmp;  
    for (int i = 0; i < m; ++i) {
        cin >> tmp;
        auto it = s.lower_bound(-tmp);
        if (it == s.end()) cout << -1;
        else {
            cout << -*it;
            s.erase(it);
        }
        cout << endl;
    }
}
```

