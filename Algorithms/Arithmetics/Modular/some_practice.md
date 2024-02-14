## Link problem: https://codeforces.com/contest/1931/problem/D

## Explanation:
```
total = a[i] + a[j]   (i < j)
diff = a[i] - a[j]    (i < j)

  total % x = 0
<-> (a[i] + a[j]) % x = 0
<-> (a[i] % x + a[j] % x) % x = 0
Let a[i] % x = r1, a[j] % x = r2 (r: remainder)
<-> (r1 + r2) % x = 0
  Notice that:
0 <= r1 < x
0 <= r2 < x
<-> 0 <= r1 + r2 < 2x
<-> (r1 + r2) is in [0, 2x)
  Because the total is divisible by x (chia hết), in range [0, 2x) it has two values that are multiple of x: 0 or x
<-> r1 + r2 = 0 or r1 + r2 = x
<-> r1 = -r2 or r1 + r2 = x
  r1 = x - r2 
<-> a[i] mod x = (x - a[j] mod x) (*)

  diff % y = 0
<-> (r1 - r2) % y = 0
  Notice that:
0 <= r1 < y
0 <= r2 < y
<-> -y < r1 - r2 < y
<-> (r1 - r2) is in range (-y, y)
  Because the difference is divisible by y, so in range (-y, y) it has only one value is multiple of y: 0
<-> r1 - r2 = 0
<-> r1 = r2
<-> a[i] % y = a[j] % y

  Merge (*) and (**), so the pair is beautiful if it satisfies 2 conditions:
+> i < j
+> a[i] mod x = x - a[j] mod x
+> a[i] mod y = a[j] mod y

```  
