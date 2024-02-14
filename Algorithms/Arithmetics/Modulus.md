# Phép chia lấy dư (modulus) có một số tính chất quan trọng sau:

1. Tính chất phân phối: (a + b) % x tương đương với (a % x + b % x) % x. Điều này có nghĩa là bạn có thể tính phép chia lấy dư cho từng số trước khi cộng chúng lại.
2. Tính chất giao hoán: a % x tương đương với x % a (nếu a không bằng 0).
3. Tính chất kết hợp: (a + (b + c) % x) % x tương đương với ((a + b) % x + c) % x.
4. Tính chất phân phối của phép nhân: (a * b) % x tương đương với (a % x * b % x) % x.
