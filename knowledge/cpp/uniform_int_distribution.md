
# std::uniform_int_distribution

---

**Class template:** `template <class IntType = int> class uniform_int_distribution;`

## Uniform discrete distribution

Quá trình phân phối các số nguyên được sinh ngẫu nhiên được dựa trên uniform discrete distribution (phân phối đều rời rạc).

Uniform discrete distribution được dựa trên probability mass function dưới đây:

$$P(i | a, b) = \dfrac{1}{b - a + 1} \; , \; a \le i \le b$$

Phân phối sẽ trả về các số nguyên ngẫu nhiên trong đoạn $[a, b]$ với mỗi số sẽ có xác suất xuất hiện là như nhau. Đây là hàm phân phối thường thấy ở trong các thủ tục sinh ngẫu nhiên thông dụng.

## Template parameters

> IntType

Kiểu số nguyên tương tự với `return_type` (kiểu dữ liệu trả về). Mặc định là kiểu `int`.

## Member types

| Member types | Definition | Notes |
| :--- | :--- | :--- |
| `return_type` | Tham số của template (IntType) | Kiểu dữ liệu của giá trị trả về (mặc định là `int`) |
| `param_type` | (không được định nghĩa) | Kiểu được trả về bởi thành viên [`param`](https://cplusplus.com/reference/random/uniform_int_distribution/param/) |

## Member functions

| Function | Description |
| :--- | :--- |
| (constructor) | Khởi tạo phân phối đều rời rạc |
| operator() | Sinh ngẫu nhiên các số |
| reset | Reset phân phối |
| param | Tham số phân phối |
| min | Giá trị nhỏ nhất |
| max | Giá trị lớn nhất |





## Tài liệu tham khảo

1. [std::uniform_int_distribution | cplusplus.com](https://cplusplus.com/reference/random/uniform_int_distribution/).
2. [Uniform discrete distribution (phân phối đều rời rạc) | Wikipedia](https://en.wikipedia.org/wiki/Discrete_uniform_distribution).
3. [Probability mass function (hàm khối xác suất)](https://en.wikipedia.org/wiki/Probability_mass_function).
