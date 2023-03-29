
# Chương 4 - Mã hóa kênh | Lý thuyết thông tin

---

## Trọng số Hamming

Trọng số Hamming của một chuỗi bit là số bit $1$ trong chuỗi bit đó. Ký hiệu: $w(.)$.

*Ví dụ:* $u = 1001 \rightarrow w(u) = 2; w(11001) = 3$.

## Khoảng cách Hamming

Khoảng cách Hamming giữa hai chuỗi bit **có chiều dài bằng nhau** là số vị trí khác nhau giữa hai chuỗi. Ký hiệu: $d$.

*Ví dụ:*

$
u = 110111, v = 100110, q = 11011 \\
d(u, v) = 2, d(v, q) = \text{Không tồn tại}, d(u, q) = \text{Không tồn tại}
$

## XOR

| X | Y | Kết quả |
| :---: | :---: | :---: |
| 0 | 0 | 0 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1 | 0 |

$\Rightarrow d(u, v) = w(u \oplus v)$

## Bộ mã hóa kênh

Là tập hợp tất cả các từ mã có chiều dài bằng nhau.

## Khoảng cách Hamming của bộ mã

Là khoảng cách ngắn nhát giữa hai từ mã trong bộ mã.

*Ví dụ:* Bộ mã $A$ có $4$ từ mã: $u_1 = 11100, u_2 = 01010, u_3 = 00111, u_4 = 10111$.

**Ta có:**
$
d(u_1, u_2) = 3, d(u_1, u_3) = 4, d(u_1, u_4) = 3,\\
d(u_2, u_3) = 3, d(u_2, u_4) = 4, d(u_3, u_4) = 1
$

Vậy khoảng cách Hamming của bộ mã $A$ là $d(A) = 1$.

## Mã hóa kênh

- Thêm $(n - k)$ bit kiểm tra vào thông tin gốc $k$ bit để được từ mã $n$ bit.
- Kí hiệu: $C(n, k)$
- Để thiết bị thu có thể phát hiện sai và sửa sai.
- Tốc độ mã: $r = \dfrac{k}{n}$: thể hiện sự đánh đổi giữa khả năng sửa lỗi và tốc độ truyền bộ mã.

### Định lý

Bộ mã có khoảng cách Hamming là $d$ thì sẽ phát hiện tối đa $(d - 1)$ lỗi và sửa được tối đa $\left\lfloor\dfrac{d - 1}{2}\right\rfloor$ lỗi.

**Ví dụ:** Bộ mã $A$ có $d(A) = 5$ sẽ phát hiện được tối đa $4$ lỗi và sửa được tối đa $2$ lỗi.

Nếu $d(A) = 2 \rightarrow$ phát hiện được $1$ lỗi và không có khả năng sửa lỗi.

## Mã kiểm tra chẵn, lả (Parity)

- Mã Parity chẵn và mã Parity lẻ
- Mã Parity chẵn: thêm $1$ bit vào sau thông tin gốc để được từ mã có số bit $1$ chẵn.

*Ví dụ:*
- Thông tin gốc $m = 11011 \rightarrow$ từ mã: $w = 11011\underset{p}{\underline{0}}$
- Thông tin gốc $m = 11111 \rightarrow$ từ mã: $w = 11111\underset{p}{\underline{1}}$

- Mã Parity lẻ: thêm $1$ bit vào sau thông tin gốc để được từ mã có số bit $1$ là lẻ.

*Ví dụ:*
- Thông tin gốc $m = 11011 \rightarrow$ từ mã: $w = 11011\underset{p}{\underline{1}}$
- Thông tin gốc $m = 11111 \rightarrow$ từ mã: $w = 11111\underset{p}{\underline{0}}$

Xét mã Parity chẵn $C(3, 2)$. Thông tin gốc có $2$ bit.

**Bảng mã:**

| m | w |
| :--- | :--- |
| 00 | 000 |
| 01 | 011 |
| 10 | 101 |
| 11 | 110 |

$
d(w_1, w_2) = 2, d(w_1, w_3) = 2, d(w_1, w_4) = 2, \\
d(w_2, w_3) = 2, d(w_2, w_4) = 2, d(w_3, w_4) = 2
$

$\Rightarrow$ Khoảng cách Hamming của bộ mã bằng $2$.

Bộ mã chỉ phát hiện $1$ lỗi và không có khả năng sửa lỗi.
