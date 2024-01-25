# Giải thuật Euclid tìm UCLN

Giải thuật Euclid dựa trên nguyên tắc là UCLN của 2 số không đổi khi thay số lớn hơn bằng hiệu số của chúng.

VD: UCLN(12, 8) = UCLN(12 - 8, 8) = UCLN(4, 8) = UCLN(4, 8 - 4) = UCLN(4, 4) = 4

## Ứng dụng:
- Rút gọn phân số
- Kiểm tra 2 số nguyên tố cùng nhau
- Tìm số nguyên tố cùng nhau với 1 số cho trước
- Tìm số nguyên tố lớn/nhỏ nhất nhỏ hơn 1 số cho trước

## Cài đặt:

```cpp
int UCLN(int a, int b) {
    if (a == 0 || b == 0) return a + b; 
    while (a != b) {
        if (a > b) a -= b;
        else b -= a;
    }
    return a;
}
```

## Cải tiến: Sử dụng phép mod thay vì phép trừ
==> Giảm số lần tính toán

```cpp
int UCLN(int a, int b) {
    if (a == 0 || b == 0) return a + b; 
    while (a != b) {
        if (a > b) a %= b;
        else b %= a;
    }
    return a;
}
```

## Độ phức tạp: $O(\log(max(a, b)))$

# Tìm BCNN

Công thức: $$BCNN(a, b) = \frac{a \times b}{UCLN(a, b)}$$