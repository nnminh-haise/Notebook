
# Chương 3 - Mã hóa nguồn | Lý thuyết thông tin

> Source encoding

---

## Mã hóa nguồn

### Khái niệm mã hóa

(*slide*)

### Mục tiêu

(*slide*)

...

### Các thông số của bộ mã và các ký hiệu

- Cơ số mã là số ký hiệu mã trong một bộ chữ mã $B$, ký hiệu $m$ (**quy ước**).

    > Ví dụ: mã nhị phân có 2 ký hiệu $0, 1 \rightarrow m = 2$.
    > Ví dụ: mã thập phân: cơ số mã $m = 10$ và bộ mã sử dụng $10$ ký hiệu: $0, 1, 2, 3, 4, 5, 6, 7, 8, 9$.

- Bộ mã: tập hợp tất cả từ mã.

    > Ví dụ: Bộ mã nhị phân.
    > | Ký hiệu | Từ mã |
    > | :---: | :---: |
    > | A | 10 |
    > | B | 01 |
    > | C | 11 |
    > | D | 00 |

- Chiều dài của **từ mã**, ký hiệu $l$ - là số ký hiệu trong từ mã.

> Bảng mã tam phân $(m = 3)$
> | Kí hiệu | Từ mã | Chiều dài từ mã $l$ |
> | :---: | :---: | :---: |
> | AB | 120 | 3 |
> | AC | 222 | 3 |
> | X | 11 | 2 |
> | Y | 0 | 1 |
> | Z | 2 | 1 |
>
> $\Rightarrow l_{\text{AB}} = 3$

---

## Các tính chất của *Bộ mã*

### 1) Tính Non-Singular

- Từ mã của các ký hiệu phải khác nhau từng dôi một

    > $\forall : x_k \neq x_n \Rightarrow u_k \neq u_n$

### 2) Tính giải mã duy nhất

### 3) Tính Prefix

- Không có từ mã nào là thành phân *mào đầu (prefix)* của từ mã khác trong bộ mã.

> ***Bảng mã 1***
> 
> | Kỹ hiệu | Từ mã |
> | :---: | :---: |
> | A | 0 |
> | B | 1 |
> | C | 00 |
> | D | 11 |
> 
> - Từ mã của A là thành phần mào đầu của từ mã của C
> - Từ mã của B là thành phần mào đầu của từ mã của D
> 
> $\Rightarrow$ **Bảng mã 1 không có tính chất Prefix**
>
> ***Bảng mã 2***
> 
> | Kỹ hiệu | Từ mã |
> | :---: | :---: |
> | A | 0 |
> | B | 10 |
> | C | 110 |
> | D | 111 |
> 
> - Từ mã của A không phải thành phần mào đầu của từ mã của B, C, D
> - Từ mã của B không phải thành phần mào đầu của từ mã của C, D
> - Từ mã của C không phải thành phần mào đầu của từ mã của D
> 
> $\Rightarrow$ **Bảng mã 2 có tính chất Prefix**

---

### Bất đẳng thức Kraft

Cho bộ mã có tính Prefix và chiều dài của các từ mã là $l_1, l_2, \ldots, l_N$.

$$
\sum\limits_{n = 1}^{N} \dfrac{1}{m^l \cdot n} \le 1
$$

> Bộ mã A
> 
> | Nguồn tin | Bộ mã A | chiều dài |
> | :---: | :---: | :---: |
> | S1 | 0 | 1 |
> | S2 | 10 | 2 |
> | S3 | 110 | 3 |
> | S4 | 1110 | 4 |
>
> $$\sum\limits_{n = 1}^{N} = \dfrac{1}{2^ln} = \dfrac{1}{2^1} + \dfrac{1}{2^2} + \dfrac{1}{2^3} + \dfrac{1}{2^4} = \dfrac{1}{2} + \dfrac{1}{4} + \dfrac{1}{8} + \dfrac{1}{16} = \dfrac{15}{16} \le 1$$
>
> $\Rightarrow$ Không phải bộ mã Prefix

### 4) Tính Prefix tối thiểu

Xét bộ mã **có tính Prefix** và $x$ là một từ mã của bộ mã. **Bộ mã sẽ có tính Prefix tối thiểu nếu $x0$ và $x1$ là từ mã hoặc thành phần mào đầu của từ mã khác trong bộ mã.**

***Xét bộ mã $A$:***

| Nguồn tin | Bộ mã A |
| :--- | :--- |
| $S_1$ | 00 |
| $S_2$ | 10 |
| $S_3$ | 110 |
| $S_4$ | 111 |

Bộ mã có tính Prefix và Prefix tối thiểu không?

***Giải:***

- Bộ mã có tính Prefix vì không có từ mã nào là thành phần mào đầu của từ mã khác trong bộ mã.
- Xét từ mã của $S_1$, thành phần mào đầu là 0.
    - Ta có: hai biến thể là 00 và 01.
    - Bởi vì 01 không phải là từ mã hoặc thành phần mào đầu của từ mã khác trong bộ mã nên bộ mã **Không có tính chất Prefix tối thiểu.**

***Xét bộ mã $B$:***

| Nguồn tin | Bộ mã B |
| :---: | :--- |
| $S_1$ | 00 |
| $S_2$ | 01 |
| $S_3$ | 100 |
| $S_4$ | 111 |

***Giải:***

Tất cả các mào đầu có thể có trong bộ mã: $0, 1, 10, 11$

Các biến thể có thể có:

| Biến thể | Loại |
| :--- | :--- |
| 00 | Từ mã |
| 01 | Từ mã |
| 10 | Mào đầu |
| 11 | Mào đầu |
| 100 | Từ mã |
| 101 | Không mào đầu hay từ mã |
| 110 | Không mào đầu hay từ mã |
| 111 | Từ mã |

$\Rightarrow$ **Vậy bộ mã không có tính Prefix tối thiểu.**

***Xét bộ mã C:***

| Nguồn tin | Bộ mã B |
| :---: | :--- |
| $A$ | 00 |
| $B$ | 01 |
| $C$ | 100 |
| $D$ | 101 |
| $E$ | 110 |
| $F$ | 111 |

- Bộ mã có tính Prefix

- Tất cả các mào đầu có thể có trong bộ mã: $0, 1, 10, 11$

Các biến thể có thể có:

| Biến thể | Loại |
| :--- | :--- |
| 00 | Từ mã |
| 01 | Từ mã |
| 10 | Mào đầu |
| 11 | Mào đầu |
| 100 | Từ mã |
| 101 | Từ mã |
| 110 | Từ mã |
| 111 | Từ mã |

$\Rightarrow$ ***Vậy bộ mã có tính Prefix tối thiểu.***

---

## Các phương pháp biểu diễn mã

### 1) Bảng đối chiếu mã

(*slide*)

### 2) Cây mã

- **Gốc:** 
- **Nhánh:** tối đa $m$ nhánh. Trong đó $m$ là cơ số mã. Mỗi nút sẽ rẽ tối đa $m$ nhánh.
- **Nút cuối:** nơi không rẽ nhánh.

***Duyệt cây mã:***

- Đi từ gốc về nút cuối để tìm từ mã.

| Nguồn tin | Bộ mã B |
| :---: | :--- |
| $A$ | 00 |
| $B$ | 01 |
| $C$ | 10 |
| $D$ | 110 |
| $E$ | 1110 |
| $F$ | 1111 |

(*Vẽ cây*)

### 3) Mặt tọa độ mã

(*slide*)

### 4) Hàm cấu trúc mã

(*slide*)

### 5) Đồ hình kết cấu mã

(*slide*)

---

## Mã đều

Mã đều là bộ mã mà các từ mã có chiều dài bằng nhau.

$$\forall : l_k = \overline{L}$$

*Ví dụ:*

| Kí hiệu $x$ | Từ mã $w$ | Chiều dài từ mã $l$ |
| :---: | :---: | :---: |
| A | 00 | 2 |
| B | 01 | 2 |
| C | 10 | 2 |
| D | 11 | 2 |

- **Bộ mã đều có tính Prefix.**

*Ví dụ:*

| Nguồn tin | Bộ mã A |
| :---: | :--- |
| $S_1$ | 009 |
| $S_2$ | 011 |
| $S_3$ | 010 |
| $S_4$ | 011 |
| $S_5$ | 100 |
| $S_6$ | 111 |

$\rightarrow$ Không phải có tính prefix tối thiểu.

*Ví dụ:*

| Nguồn tin | Bộ mã B |
| :---: | :--- |
| $S_1$ | 009 |
| $S_2$ | 011 |
| $S_3$ | 010 |
| $S_4$ | 011 |
| $S_5$ | 100 |
| $S_6$ | 101 |
| $S_7$ | 110 |
| $S_8$ | 111 |

$\rightarrow$ Có tính prefix tối thiểu.

## Bộ mã đầy

Bộ mã đều có các từ mã có chiều dài bằng $L$ và số từ mã trong bộ mã là $N = 2^L$ (nhị phân) thì là bộ mã này là bộ mã đầy.

- Mã đầy có tính chất prefix tối thiểu.

---

## Phần nguyên

$x$ là số thực, $\lbrack x \rbrack$ là phần nguyên của $x$.

Ví dụ: $\lbrack 1.1 \rbrack = 1, \lbrack -2.1 \rbrack = -2, \lbrack 3 \rbrack = 3$.

$\lfloor x \rfloor$ là số nguyên lớn nhất mà nhỏ hơn hoặc bằng $x$.

Ví dụ: $\lfloor 1.1 \rfloor = 1, \lfloor -2.1 \rfloor = -3, \lfloor 3 \rfloor = 3$.

$\lceil x \rceil$ là số nguyên nhỏ nhất mà lớn hơn hoặc bằng $x$.

Ví dụ: $\lceil 1.1 \rceil = 2, \lceil -2.1 \rceil = -2, \lceil 3 \rceil = 3$.

### Sửa bài tập

Cho nguồn tin $M$ tin, mã đều. Gọi $l$ là số bit của mỗi từ mã.

***Giải:***

Số từ mã có thể có: $2^l$. $\Rightarrow 2^l \ge M \Rightarrow l \ge \log_2(M)$.

Kết luận: $l = \lceil \log_2(M) \rceil$.

---

## Mã đều

- Có tính prefix.
- Tính prefix tối thiểu $\rightarrow$ chuyển sang bộ mã đầy.

---

## Mã hóa không đều

- Các từ mã có chiều dài khác nhau.
- Sử dụng thống kê.
- chiều dài trung bình càng ngắn càng tốt.

- Nguyên tắc: kỹ tự nào có tần suất xuất hiện càng nhiều thì mã hóa bằng từ mã có chiều dài ngắn và ngược lại.

---

## Đổi thập phân sang nhị phân

Ví dụ: Đổi $0.5$ sang nhị phân.

$$
\begin{matrix}
0.5 \times 2 = 1.0 & \\
0.0 \times 2 = 0.0 & (\text{stop}) \\
\Rightarrow 0.5_{(10)} = 0.1_{(2)}
\end{matrix}
$$

Ví dụ: Đổi $0.625$ sang nhị phân.

$$
\begin{matrix}
0.625 \times 2 = 1.25 & \\
0.25 \times 2 = 0.5 & \\
0.5 \times 2 = 1.0 & (\text{stop}) \\
\Rightarrow 0.625_{(10)} = 0.101_{(2)}
\end{matrix}
$$

Ví dụ: Đổi $0.2$ sang nhị phân.

$$
\begin{matrix}
0.2 \times 2 = 0.4 & \\
0.4 \times 2 = 0.8 & \\
0.8 \times 2 = 1.6 & \\
0.6 \times 2 = 1.2 & \\
0.2 \times 2 = 0.4 & \\
0.4 \times 2 = 0.8 & \\
0.8 \times 2 = 1.6 & \\
0.6 \times 2 = 1.2 & \\
0.2 \times 2 = 0.4 & \\
\dots \\
\Rightarrow 0.2_{(10)} = 0.00110011\ldots_{(2)} = 0.(0011)_{(2)}
\end{matrix}
$$

---

## Mã hóa Shannon

> Mã hóa nguồn có 4 ký tự với xác suất xuất hiện là $0.4, 0.3, 0.2, 0.1$ bằng mã Shannon.

| Tin | Xác suất | $Q$ | $l$ | Nhị phân | Từ mã |
| :---: | :---: | :---: | :---: | :---: | :---: |
| A | 0.4 | 0 | $l_A = - \lceil \log_2(0.4) \rceil = 2$ | $0.000000 \ldots$ | 00 |
| B | 0.3 | 0.4 | $l_B = - \lceil \log_2(0.3) \rceil = 2$ | $0.011000 \ldots$ | 01 |
| C | 0.2 | 0.7 | $l_C = - \lceil \log_2(0.2) \rceil = 3$ | $0.101110$ | 101 |
| D | 0.1 | 0.9 | $l_D = - \lceil \log_2(0.1) \rceil = 4$ | $0.111000$ | 1110 |

(*sắp xếp theo thứ tự giảm dần của xác suất*)

- $Q$ = tổng xác suất của các ký tự bên trên ký tự đang xét.
- $l_i = -\lceil \log_2(p_i) \rceil$.
- Nhị phân: đổi $Q$ sang nhị phân.
- Từ mã: là từ mã ngõ ra với chiều dài $l_i$ bit nhị phân sau dấu phẩy.

Chiều dài từ mã trung bình: $\overline{L} = 0.4 \times 2 + 0.3 \times 2 + 0.2 \times 3 + 0.1 \times 4 = 2.4$ (bit)

Entropy: $H = 0.4 \times \log_2(\dfrac{1}{0.4}) + 0.3 \times \log_2(\dfrac{1}{0.3}) + 0.2 \times \log_2(\dfrac{1}{0.2}) + 0.1 \times \log_2(\dfrac{1}{0.1}) = 1.8464$ (bit)

Hiệu suất mã hóa: $\eta = \dfrac{H}{\overline{L}} \cdot 100\% = 77 \%$

Bộ mã có tính prefix vì không có từ mã nào là thành phần mào đầu của từ mã khác trong bộ mã.

Bộ mã không có tính prefix tối thiểu vì mào đầu $10$ có biến thể $100$ không là từ mà và không là thành phần mào của từ mã nào trong bộ mã.0.4 \times \log_2(\dfrac{1}{0.4})



---

## References
