
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

## Bất đẳng thức Kraft

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



---

## References
