
# ĐỆ QUY

## Table of contents

- [Khái niệm](#khái-niệm)

    - [Bài toán mở đầu](#bài-toán-mở-đầu)
    - [Khái niệm đệ quy](#khái-niệm-đệ-quy)

- [Hàm đệ qui và Stack](#hàm-đệ-quy-và-stack)
- [Ví dụ](#ví-dụ)

    - [Ví dụ 1 - Hàm giai thừa](#ví-dụ-1---hàm-giai-thừa)
    - [Ví dụ 2 - Hàm Fibonacci](#ví-dụ-2---hàm-fibonacci)
    - [Ví dụ 3 - Bài toán Tháp Hà Nội](#ví-dụ-3---bài-toán-tháp-hà-nội)

- [References](#references)

---

## Khái niệm

### Bài toán mở đầu

> Tính $S(n) = 1 + 2 + 3 + 4 + \ldots + n - 1 + n$

**Phân tích:**

*Ta có:*

$$
\begin{alignat}{5}
n = 1 \Rightarrow & S(1) = 1 \\
n = 2 \Rightarrow & S(2) = 1 + 2 = 3 & = & (1) + 2 & = & S(1) + 2 \\
n = 3 \Rightarrow & S(3) = 1 + 2 + 3 = 6 & = & (1 + 2) + 3 & = & S(2) + 3 \\
n = 4 \Rightarrow & S(4) = 1 + 2 + 3 + 4 = 10 & = & (1 + 2 + 3) + 4 & = & S(3) + 4 \\
n = 5 \Rightarrow & S(5) = 1 + 2 + 3 + 4 + 5 = 15 \; & = & (1 + 2 + 3 + 4) + 5 \; & = & S(4) + 5 \\
\end{alignat}
$$

Từ nhận xét trên, có thể rút ra công thức:
$$
\begin{align}
S(n) = S(n - 1) + n
\end{align}
$$

Trong công thức trên, giá trị hiện tại cần tính được tính thông qua giá trị đã tính trước đó. Hay nói cụ thể hơn thì để tính được $S(n)$ (hiện tại) thì cần phải biết được $S(n - 1)$ (trước đó). Nói cách khác, hàm $S$ phụ thuộc vào chính bản thân hàm $S$ (vì trong công thức định nghĩa của hàm $S$ có sự xuất hiện của chính hàm $S$).

### Khái niệm đệ quy

***Khái niệm:*** Một vấn đề có tính chất đệ quy là vấn đề được định nghĩa lại bằng chính nó.

Một chương trình đệ quy là một chương trình có thể được biểu diễn như bộ $P$ gồm các lệnh cơ sở $S$ (không chứa $P$) và bản thân $P$. Kí hiệu: $P = P(S_i, P)$.

> **Xét ví dụ:** Cho $n \in \Z $, tính $F(n)$ biết $F(n) = F(n - 1) \; \forall n \in \Z$.
> 
> **Thấy rằng:** Để tính $F(4)$ cần biết $F(3)$; để tính $F(3)$ cần biết $F(2)$; để tính $F(2)$ cần biết $F(1)$; để tính $F(1)$ cần biết $F(0)$.... Vòng lặp này sẽ lặp đi lặp lại vô hạn lần, khác với công thức $S(n) = S(n - 1) + n$ ở bài toán mở đầu.

Như vậy, thủ tục đệ quy có thể thực hiện các phép toán không kết thúc giống với vòng lặp vô hạn. Do đó, cần phải chú ý đến vấn đề kết thúc các phép tính trong một giải thuật đệ quy.

Có thể hình dung đơn giản là thủ tục $P$ sẽ được gọi đệ quy khi thỏa mãn một điều kiện $Q$ nào đó. Và điều kiện $Q$ này phải không thỏa mãn tại một điều kiện nào đó chắc chắn xảy ra dù cho có thể lâu. Mô hình: $P = if (Q) \; P(S_i, P)$ hay $P = (S_i, if (Q) \; P)$.

---

## Hàm đệ quy và Stack

(*pending*)

---

## Ví dụ

### Ví dụ 1 - Hàm giai thừa

> Giai thừa của một số nguyên dương $n$ được xác định bằng công thức: $n! = 1 \cdot 2 \cdot 3 \cdot 4 \cdot \ldots \cdot n$. Quy ước $0! = 1$.
>
> **Ví dụ:** 
> $$
\begin{alignat}{5}
1! & = 1 \\
2! & = 1 \cdot 2 = 2 & = & (1) \cdot 2 & = & 1! \cdot 2 \\
3! & = 1 \cdot 2 \cdot 3 = 6 & = & (1 \cdot 2) \cdot 3 & = & 2! \cdot 3 \\
4! & = 1 \cdot 2 \cdot 3 \cdot 4 = 24 & = & (1 \cdot 2 \cdot 3) \cdot 4 & = & 3! \cdot 4 \\
5! & = 1 \cdot 2 \cdot 3 \cdot 4 \cdot 5 = 120 \; & = & (1 \cdot 2 \cdot 3 \cdot 4) \cdot 5 \; & = & 4! \cdot 5 \\
\end{alignat}
$$
>
> Như vậy, có thể rút ra nhận xét: $n! = (n - 1)! \cdot n = n \cdot (n - 1)!$.

Từ kết luận trên, có thể thấy hàm tính giai thừa là một hàm có tính chất đệ qui. Bên cạnh đó, điều kiện dừng của hàm là là qui ước $n = 0 \Rightarrow n! = 0! = 1$.

***Hàm đệ qui:***

```cpp
long long factorial(long long n) {
    if (n == 0) { 
        return 1;
    }
    
    return n * factorial(n - 1);
}
```

*Hoặc:*

```cpp
long long factorial(long long n) {
    return (n == 0) ? 1 : n * factorial(n - 1);
}
```

***Hàm không đệ qui:***

```cpp
long long factorial(long long n) {
    long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }

    return result;
}
```

### Ví dụ 2 - Hàm Fibonacci

> Số Fibonacci được định nghĩa như sau:
> $$
F_n = 
\begin{cases}
1 & ; n = 0, 1 \\
F_{n + 1} + F_{n + 2} & ; n \ge 2 
\end{cases}
> $$

Từ định nghĩa của số Fibonacci thứ $n$, ta thấy rằng đây là một hàm có tính chất đệ qui với điều kiện dừng là khi $n$ là hai giá trị $0$ và $1$.

***Hàm đệ qui:***

```cpp
long long fibonacci(long long n) {
    if (n == 0 | n == 1) {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}
```

***Hàm không đệ qui:***

```cpp
long long fibonacci(long long n) {
    if (n == 0 || n == 1) {
        return 1;
    }

    int fib1 = 1, fib2 = 1, fib3 = fib1 + fib2;
    for (int i = 2; i <= n; ++i) {
        fib3 = fib1 + fib2;
        fib1 = fib2;
        fib2 = fib3;
    }

    return fib3;
}
```

### Ví dụ 3 - Bài toán Tháp Hà Nội

> Có $3$ cột $A, B, C$. Ban đầu, cột $A$ có $n$ đĩa kích thước khác nhau và được sắp xếp theo chiều tăng dần về kích thước từ trên xuống dưới. Nghĩa là đĩa ở trên sẽ bé hơn đĩa ở dưới. Hãy dời $n$ đĩa từ cột $A$ sang cột $C$ coi cột $B$ là cột trung gian với điều kiện mỗi lần chỉ được di chuyển đúng $1$ đĩa và đĩa ở trên bao giờ cũng nhỏ hơn đĩa ở dưới.
>
> **Lời giải:** Tạm thời bỏ qua cách chuyển các đĩa như thế nào, có thể hình dung lời giải tổng quát khi chuyển $n$ đĩa từ cột $A$ sang cột $C$ lấy cột $B$ là trung gian chính là chuyển $n - 1$ đĩa từ cột $A$ sang cột $B$ và chuyển đĩa thứ $n$ sang cột $C$. Sau đó chuyển $n - 1$ đĩa từ cột $B$ sang cột $C$ lấy cột $A$ làm trung gian.

***Hàm đệ qui:***

```cpp
void hanoiTower(int n, char pollA, char pollB, char pollC) {
    if (n == 1) {
        std::cout << "Move 1 disk from " << pollA << " to " << pollC << std::endl;
        return;
    }
    hanoiTower(n - 1, pollA, pollC, pollB);
    hanoiTower(1, pollA, pollB, pollC);
    hanoiTower(n - 1, pollB, pollA, pollC);
}
```

---

## Thuật toán lần ngược - quay lui (Back Tracking)

---

## References


