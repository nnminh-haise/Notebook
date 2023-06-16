
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

## Mã Hamming

### Mã hóa

- Các bit kiểm tra được đặt ở các vị trí $2^a$ trong từ mã ($2^a = 1, 2, 4, 8, \ldots$)
- Tìm vị trí các bit $1$ trong từ mã $\rightarrow$ đổi vị trí sang nhị phân.
- XOR các số nhị phân để tìm các bit kiểm tra.

**Ví dụ:** Tìm từ mã tương ứng với thông tin gốc $m = 1010$ sử dụng mã Hamming $C(7, 4)$.

$C(7, 4)$ thông tin gốc có $4$ bit và từ mã có $7$ bit.

Từ mã: $w = c_1 c_2 1 c_4 0 1 0$
- Có 2 bit 1 trong từ mã ở các vị trí: $3, 6$.
- Đổi sang nhị phân: $3 \rightarrow 011$, $6 \rightarrow 110$, $011 \bigoplus 110 = 101$.
- Bit kiểm tra (từ phải sang trái): $c_1 = 1, c_2 = 0, c_4 = 1$.

Từ mã: $w = 1011010$  

Từ mã nhận được: $r = w \bigoplus e$, $e$ gọi là vector lỗi.
Ví dụ: $r = \underset{w}{1011010} \bigoplus \underset{e}{0000000} \rightarrow$ không lỗi.
Ví dụ: $r = 1011010 \bigoplus 0001000 = 1010010 \rightarrow$ lỗi ở bit thứ tự.

### Giải mã

- Xác định vị trí các bit $1$ trong từ mã nhận được $r \rightarrow$ đổi các vị trí này sang nhị phân và XOR lại.
- Nếu kết quả sau khi XOR là vector zero $\rightarrow$ từ mã đúng.
- Nếu kết quả sau khi XOR là vector khác 0 $\rightarrow$ từ mã sai.

**Ví dụ:** Giả sử từ mã nhận được sai ở bit thứ 5 $r = w \bigoplus e = 1011010 \bigoplus 0000100 = 1011110$.

- Vị trí các bit 1 (từ trái sang phải): $1, 3, 4, 5, 6$.
    - $1 \rightarrow 001$
    - $3 \rightarrow 011$
    - $4 \rightarrow 100$
    - $5 \rightarrow 101$
    - $6 \rightarrow 110$
    - $\bigoplus = 101$
- Do $101 \neq 000$ nên từ mã nhận được chắc chắn sai.
- $101_2 = 5 \rightarrow$ sai ở vị trí số 5.
- Sửa sai: $r = 1011\underline{0}10$

### Giới hạn của mã Hamming

- Khoảng cách Hamming của bộ mã bằng 3
    - Phát hiện tối đa 2 lỗi.
    - Chỉ sửa được 1 lỗi.

## Mã khối tuyến tính

### Trường Galois Field (2 - trường nhị phân)

> Trường nhị phân chỉ có hai phần tử là 0 và 1. Chỉ có hai phép toán là nhân và cộng.
>
> $x + y = 0011 + 0101 = 0110$ (cộng không nhớ tương ứng với XOR)
> $x \times y = 0011 \times 0101 = 0001$ (tương ứng với AND)

### Nhân ma trận

$
\begin{bmatrix}
1 & 1
\end{bmatrix}
\times
\begin{bmatrix}
1 & 0 \\
1 & 1
\end{bmatrix}
= \begin{bmatrix}
0 & 1
\end{bmatrix}
$

$
\begin{bmatrix}
1 & 0 \\
1 & 0 \\
\end{bmatrix}
\times
\begin{bmatrix}
1 & 1 \\
0 & 1
\end{bmatrix}=
\begin{bmatrix}
1 & 1 \\
1 & 1
\end{bmatrix}
$

$
\begin{bmatrix}
1 & 0 & 1 \\
\end{bmatrix}
\times
\begin{bmatrix}
1 & 0 & 0 \\
1 & 1 & 0 \\
0 & 1 & 1
\end{bmatrix}=
\begin{bmatrix}
1 & 1 & 1
\end{bmatrix}
$

$
\begin{bmatrix}
1 & 1 \\
0 & 1 \\
\end{bmatrix}
\times
\begin{bmatrix}
1 & 1 \\
\end{bmatrix}
\neq
$

### Mã khối tuyến tính

Mã khối tuyến tính C(n, k) có ma trận sinh $G_{k \times n}$ (Generating matrix). Từ mã $w$ được tìm ra bằng cách nhân thông tin gốc $m$ với ma trận $G$.

$$w = m \times G$$

Trong đó: $m$ là vector thông tin gốc.

- Từ mã hệ thông dạng I: Các bit kiểm tra nằm sau thông tin gốc trong mã.
- Ma trận sinh hệ thống dạng I:

$$
G_{k \times n} =
\begin{bmatrix}
I_{k \times k} & \vdots &  P_{k \times (n - k)}
\end{bmatrix}
$$

Ma trận nào là ma trận sinh, ma trận sinh hệ thống dạng I.

$
G_1 =
\begin{bmatrix}
1 & 0 \\
1 & 1 \\
\end{bmatrix},
G_2 = 
\begin{bmatrix}
1 & 0 & 1 \\
1 & 1 & 1 \\
\end{bmatrix},
G_3 =
\begin{bmatrix}
1 & 1 & 1 \\
0 & 0 & 0 \\
1 & 1 & 1 \\
1 & 1 & 0 \\
\end{bmatrix},
G_4 =
\begin{bmatrix}
1 & 0 & 1 & 0 \\
0 & 1 & 1 & 1 \\
\end{bmatrix},
$

$G_1$ dạng C(2, 2): không là ma trận sinh vì không có bit kiểm tra.
$G_2$ dạng C(3, 2): ma trận sinh.
$G_3$ dạng C(3, 4): không độc lập tuyến tính, nên không phải ma trận sinh
$G_4$ dạng C(4, 2): ma trận sinh hệ thống dạng I.

### Ví dụ

Cho mã khối tuyến tính C(4, 2) có ma trận sinh:

$$
G = 
\begin{bmatrix}
1 & 0 & 0 & 0 \\
0 & 1 & 1 & 1 \\
\end{bmatrix}
$$

Hãy tìm tất cả các từ mã của bộ mã. Tìm khoảng cách Hamming của bộ mã.

***Giải:***

Thông tin gốc có 2 bit.

| Từ mã (m) | Bộ mã (w) |
| :--- | :--- |
| 00 | 0000 |
| 01 | 0111 |
| 10 | 1000 |
| 11 | 1111 |

> *Ma trận sinh hệ thống dạng 1 sẽ cho ra bộ mã, có các từ mã, có $k$ bit đầu giống với bộ mã gốc.*

**Khoảng cách Hamming của *mã khối tuyến tính* bằng trọng số Hamming nhỏ nhất khác 0 của các từ mã.**

Bởi vì trọng số Hamming nhỏ nhất khác 0 bằng $1$ nên khoảng cách Hamming của bộ mã bằng $1$.

Suy ra bộ mã phát hiện 01 lỗi và không có khả năng sửa lỗi.

**Giải bài 4.7:**

## Ma trận kiểm tra H

Có dạng: $G \cdot H^T = 0$, với $H^T$ là ma trận chuyển vị của ma trận $H$.

Nếu $G$ là ma trận sinh hệ thống dạng I thì $
H =
\begin{bmatrix}
p^T & | & I
\end{bmatrix}
$

***Ví dụ:*** (bài 4.6)

$
H = \begin{bmatrix}
1 & 0 & 1 & 1 & \vdots & 1 & 0 & 0 \\
1 & 1 & 0 & 1 & \vdots & 0 & 1 & 0 \\
1 & 1 & 1 & 0 & \vdots & 0 & 0 & 1 \\
\end{bmatrix}
$

### Phát hiện sai và sửa sai

- Tính syndrome $s = rH^T$
- Nếu $s = 0 \rightarrow$ từ mã $r$ đúng.
- Nếu $s \neq 0 \rightarrow$ từ mã $r$ sai.
    - Tìm vector lỗi $e$.
    - Cập nhật $r + e = w$.

***Ví dụ:***

$m = 101$ và $
G = \begin{bmatrix}
1 & 0 & 0 & 0 & 1 & 1 \\
0 & 1 & 0 & 1 & 0 & 1 \\
0 & 0 & 1 & 1 & 1 & 1 \\
\end{bmatrix}
\Rightarrow
w = \begin{bmatrix}
1 & 0 & 1 & 1 & 0 & 0
\end{bmatrix}
$

Từ mã nhận được: $r = w + e = w + 001000 = 100100$

Giải mã:

- Tìm $H$:

    - Ta có: $
    P = \begin{bmatrix}
    0 & 1 & 1 \\
    1 & 0 & 1 \\
    1 & 1 & 1 \\
    \end{bmatrix}
    \Rightarrow
    P^T = \begin{bmatrix}
    0 & 1 & 1 \\
    1 & 0 & 1 \\
    1 & 1 & 1 \\
    \end{bmatrix}
    $

    - $\Rightarrow 
    H = \begin{bmatrix}
    P^T & I
    \end{bmatrix}
    = \begin{bmatrix}
    0 & 1 & 1 & 1 & 0 & 0 \\
    1 & 0 & 1 & 0 & 1 & 0 \\
    1 & 1 & 1 & 0 & 0 & 1 \\
    \end{bmatrix}
    $

    - Tính syndrome: $s = rH^T = 
    \begin{bmatrix}
    1 & 0 & 0 & 1 & 0 & 0 \\
    \end{bmatrix}
    \times
    \begin{bmatrix}
    0 & 1 & 1 \\
    1 & 0 & 1 \\
    1 & 1 & 1 \\
    1 & 0 & 0 \\
    0 & 1 & 0 \\
    0 & 0 & 1 \\
    \end{bmatrix}
    = \begin{bmatrix}
    1 & 1 & 1 \\
    \end{bmatrix}
    \neq \begin{bmatrix}
    0 & 0 & 0 \\
    \end{bmatrix}
    \Rightarrow
    $ Từ mã sai

- Tím $e$:

    - Bộ mã có khoảng cách Hamming bằng $3$.
        - Bộ mã chỉ sửa được 01 lỗi.
        - Chỉ tìm lỗi đơn.

    | $e$ | $s = eH^T$ |
    | :--- | :--- |
    | 000001 | 001 |
    | 000010 | 010 |
    | 000100 | 100 |
    | **001000** | **111** |
    | 010000 | 101 |
    | 100000 | 011 |

    Vì $s = 111$ nên $e = 001000 \rightarrow$ cập nhật: $r + e = 100100 + 001000 = 101100$

***Ví dụ: (bài 4.8)***

Cho bộ mã: C(7, 4) có ma trận sinh:

$
G = \begin{bmatrix}
1 & 0 & 0 & 0 & 1 & 1 & 1 \\
0 & 1 & 0 & 0 & 0 & 1 & 1 \\
0 & 0 & 1 & 0 & 1 & 0 & 1 \\
0 & 0 & 0 & 1 & 1 & 1 & 0 \\
\end{bmatrix}
$

Giả sử từ mã nhận được là $r = 1000010$. Hãy xác định từ mã đã được truyền đi $w$ bằng phương pháp syndrome.

**Giải:**

Ta có: $
p = \begin{bmatrix}
1 & 1 & 1 \\
0 & 1 & 1 \\
1 & 0 & 1 \\
1 & 1 & 0 \\
\end{bmatrix}
\Rightarrow
p^T = \begin{bmatrix}
1 & 0 & 1 & 1 \\
1 & 1 & 0 & 1 \\
1 & 1 & 1 & 0 \\
\end{bmatrix}
\Rightarrow
H = \begin{bmatrix}
p^T & \vdots & I \\
\end{bmatrix}
= \begin{bmatrix}
1 & 0 & 1 & 1 & 1 & 0 & 0 \\
1 & 1 & 0 & 1 & 0 & 1 & 0 \\
1 & 1 & 1 & 0 & 0 & 0 & 1 \\
\end{bmatrix}
$

Syndrome: $
s = rH^T
= \begin{bmatrix}
1 & 0 & 0 & 0 & 0 & 1 & 0
\end{bmatrix}
\times \begin{bmatrix}
1 & 1 & 1 \\
0 & 1 & 1 \\
1 & 0 & 1 \\
1 & 1 & 0 \\
1 & 0 & 0 \\
0 & 1 & 0 \\
0 & 0 & 1 \\
\end{bmatrix}
= \begin{bmatrix}
1 & 0 & 1 \\
\end{bmatrix}
\neq \begin{bmatrix}
0 & 0 & 0 \\
\end{bmatrix}
\Rightarrow
$ từ mã sai

(Giải ra khoảng cách Hamming bằng 3 "*Giải tay*")

Bộ mã sửa được 01 lỗi nên chỉ xét trường hợp vector $e$ có lỗi đơn.

| $e$ | $s = eH^T$ |
| :---: | :---: |
| 0000001 | 001 |
| 0000010 | 010 |
| 0000100 | 100 |
| 0001000 | 110 |
| **0010000** | **101** |
| 0100000 | 011 |
| 1000000 | 111 |

Bởi vì $s = 101$ nên vector $e$ lằ $0010000$.

Do đó, từ mã đúng là $w = r + e = 1000010 + 0010000 = 1010010$
