
# Lý thuyết thông tin

---

## Mục lục

- [Chương 1 - Tổng quan và ôn tập](#chapter-1)
- [Chương 2](#chapter-2)
    - [Kiến thức cơ bản](#kiến-thức-cơ-bản)
        - [Lượng tin](#lượng-tin)
- [Reference](#references)

---

## Chương 1 - Tổng quan và ôn tập

---

## Chương 2

### Kiến thức cơ bản

#### Lượng tin

- Lượng tin đưa ra **khả năng dự đoán được** của tin.
- Một tin có xác suất xuất hiện càng nhỏ thì có độ bất ngờ càng lớn, lượng tin càng lớn, và ngược lại.
    
    - Lượng tin tỉ lệ nghịch với xác suất xuất hiện của tin tương ứng.
    - Nếu tin có xác suất xuất hiện bằng $1$ thì lượng tin bằng $0$.

- Xét nguồn tin $X$ rời rạc sinh ra các tin $i$ với xác suất là $p(i)$, lượng tin $i$ phải là một hàm có đặc điểm sau:

    - Tỉ lệ nghịch với xác suất xuất hiện $p(i), f(1 \div p(i))$

- Nếu hai tin độc lạp thống kê là $i$ và $j$ đồng thời xuất hiện ta có tin là $(i, j)$, thì lượng tin chung phải bằng tổng lượng tin của từng tin.

$$f(1 \div p(i, j) = f(1 \div p(i)) + f(1 \div p(j))$$

- Với luật nhân xác suất thì:

...

- Lượng tin của một tin $i$ được ký hiệu là $I(i)$. Định nghĩa lượng tin của một tin $i$:

$$
I(i) = \log \dfrac{1}{p(i)} = -\log p(i) \\
\because
\begin{cases}
\log{\dfrac{a}{b}} = \log(a) - \log(b) \\
\log(1) = 0
\end{cases}
\Rightarrow
\log{\dfrac{1}{a}} = - \log{a}
$$

- Đơn vị là `bit` hay `nat` hay `hartley` khi cơ số là $2, e$ hay $10$.
- Cơ số $2$ hay được chọn.
- Khoảng giá trị của lượng tin

$$
\begin{align}
I(i) = \log_2{(\dfrac{1}{p(i)})} (bit) \\
\begin{split}
I(i) & = \log_e{(\dfrac{1}{p(i)})} \\
& = - \ln{(p(i))} (nat)
\end{split} \\
\begin{split}
I(i) & = \log_{10}{(\dfrac{1}{p(i)})} \\
& = - \lg{(p(i))} (hartley)
\end{split} \\
\end{align}
$$

> ***Ví dụ:*** Tung $1$ đồng xu, hãy tính lượng tin trong thông điệp "Mạt xuất hiện là mặt sấp".
>
> **Giải:** Xác suất xuất hiện mặt sấp là $p = \dfrac{1}{2}$. Nên lượng tin chứa trong thông điệp là:
> 
> $$I = \log_{2}{\dfrac{1}{p}} = \log_2{(2)} = 1 \quad (bit)$$

> ***Ví dụ:*** Trung $3$ đồng xu, tính lượng tin chứa trong các thông điệp sau:
> 
> - Thông điệp $1$: "Cả $3$ mặt đều sấp".
> - Thông điệp $2$: "Xuất hiện $2$ mặt sấp và $1$ mặt ngửa".
> 
> **Giải:**
> 
> - Xác suất xuất hiện cả $3$ mặt sấp là $p = {\left(\dfrac{1}{2}\right)}^3 = \dfrac{1}{8}$. Nên lượng tin chứa trong thông điệp là:
> 
> $$I(1) = \log_2{\dfrac{1}{p} = \log_2{8}} = 3 \quad (bit)$$
> 
> - Tổng số khả năng: $8$.
> - Số khả năng xuất hiện $2$ sấp (S) và $1$ ngửa (N) là: (SSN, SNS, NSS). Suy ra xác suất xuất hiện $2$ mặt sấp và $1$ mặt ngửa là: $p = \dfrac{3}{8}$. Nên lượng tin chứa trong thông điệp là:
> 
> $$I(2) = \log_2{\dfrac{1}{p} = \log_2{\dfrac{8}{3}}} \quad (bit)$$

***Ví dụ:*** Rút $3$ lá bài từ bộ bài $52$ lá. Tính lượng tin trong các thông điệp sau:

- Thông điệp $1$: "$3$ lá bài giống nhau và không có hình mặt người".
- Thông điệp $2$: "Cả $3$ lá bài đều có hình mặt người".

**Giải:**

- Xác suất bốc $3$ lá bài giống nhau và không có hình mặt người: $p_1 = \dfrac{10 \cdot C_4^3}{C_{52}^3} \Rightarrow I_1 = \log_2{(\dfrac{1}{p_1})}$.

- Xác suất bốc $3$ lá bài đều có hình mặt người: $p_2 = \dfrac{C_{12}^3}{C_{52}^3} \Rightarrow I_2 = \log_2{(\dfrac{1}{p_2})}$.









---

## References

- [GS.TS Nguyễn Bình, LTTT, 2007]
- [Bài giảng lý thuyết thông tin]
- [Nguyễn Thúy Vân, Lý thuyết mã]

