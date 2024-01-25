# Tính lũy thừa $a^n$ nhanh nhất - Đpt $O(log(n))$ thay vì $O(n)$
Giả sử cần tính $a^n$ với $n$ = $10^{18}$, thay vì phải thực hiện $O(n)$ tức là $10^{18}$ phép nhân, ta chỉ cần thực hiện $O(\log_2(n))$ ~ 60 phép nhân
### Tư tưởng chính: Chia để trị (Devide and Conquer)
## Cách 1: Thao tác trên số thông thường
### Nếu n chẵn: $$a^n = a^{n/2} . a^{n/2}$$ 
### Nếu n lẻ: $$a^n = a . a^{n/2} . a^{n/2}$$ 

* Lưu ý: có phép chia $MOD$

### Đệ quy:
```cpp
typedef long long ll;
ll mod = 1e9+7;

ll Pow(ll a, ll n) {
    if (n == 0) return 1;
    if (n == 1) return a;
    ll temp = Pow(a, n/2);
    if (n % 2 == 0) return temp * temp % mod;
    return (temp * temp % mod) * a % mod;
}
```

### Vòng lặp:
```cpp
typedef long long ll;
ll mod = 1e9+7;

ll Pow(ll a, ll n) {
    ll ans = 1;
    while (n) 
    {
        if (n % 2 == 1) ans = ans * a % mod;
        a = a * a % mod;
        n /= 2;
    }
    return ans;
}
```

## Cách 2: Chuyển đối số mũ sang hệ nhị phân (thao tác trên bit)
### *Nhận xét: 
<!-- Sử dụng cú pháp LaTeX để định dạng các công thức toán học -->
Giả sử $n$ có dạng nhị phân: $$n = p_0.2^0 + p_1.2^1 + p_2.2^2 + ... + p_k.2^k$$
$$=> a^n = a^{p_0.2^0 + p_1.2^1 + p_2.2^2 + ... + p_k.2^k} = a^{p_0.2^0} * a^{p_1.2^1} * a^{p_2.2^2} * ... * a^{p_k.2^k}$$ 
với $p_i \in \{0, 1\}$, $2^k$ là số lớn nhất nhỏ hơn $n$, $k = \log_2(n)$ 

Ví dụ: Tính $2^4 = 64$
(Ta dựa vào các bit để tính toán từ phải qua trái (<-- ) )
$$4 = 100(binary) = 0.2^0 + 0.2^1 + 1.2^2$$
$$=> ans = 2^4 = 2^{0.2^0} * 2^{0.2^1} * 2^{1.2^2}$$
$$=> ans = 2^4 = 2^0 * 2^0 * 2^2$$

| n (nhị phân) | temp | $p_i$ | ans | n (update)| 
|--------------|---|-------|-----|-----------|
| 100          | $2^1 . 2^1 = 2^2$ | 0  |  1 |  10  |
| 10           | $2^2 . 2^2 = 2^4$ | 0  |  1 |  1   |
| 1            | $2^4 . 2^4 = 2^8$ | 1  |  $1 . 2^4 = 2^4$ | 0 |


### *Giải thích:
- Xét ans = $a^{p_0.2^0} * a^{p_1.2^1} * a^{p_2.2^2} * ... * a^{p_k.2^k}$
- Ta dùng 1 biến **temp** lưu các giá trị $a^{2^i}$ với $i \in \{0,1,2,...,k\}$ => temp = $\{a^1, a^2, a^4, a^8,..., a^{2^k}\}$
    + Nếu $p_i = 0$ nghĩa là $a^{p_i.2^i} = 1$ -> ans = ans * 1 = ans -> bỏ qua
    + Nếu $p_i = 1$ nghĩa là $a^{p_i.2^i} = a^{2^i}$ -> ans = ans * $a^{2^i}$ = ans * temp
- Để xét bit tiếp theo, ta dịch bit của n sang phải 1 bit (n = n >> 1), giá trị tại bit đó sẽ là temp = temp * temp = $a^{2^i}$ * $a^{2^i} = a^{2^i+2^i} = a^{2.2^i} = a^{2^(i+1)}$

```cpp
typedef long long ll;
ll mod = 1e9+7;

ll Pow(ll a, ll n) {
    ll ans = 1;
    ll temp = a; // temp = a^(2^0) = a^1 = a
    while(n)
    {
        if (n & 1) ans = ans * temp % mod;
        temp = temp * temp % mod; // temp = a^(2^(i+1))
        n >>= 1;
    }
    return ans;
}
```
