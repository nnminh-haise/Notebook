
# Linked List - Danh sách liên kết

---

## Kiến thức yêu cầu

- Kiến thức cơ bản ngôn ngữ lập trình `C++`.
- Khái niệm pointer (con trỏ).
- Khái niệm `struct` và `class`.

Một số khái niệm sẽ xuất hiện thêm (khuyến khích tìm hiểu):

- Khái niệm `namespace` trong `C++`.
- Khái niệm `header` trong `C++`.
- Khái niệm `reference` (tham chiếu) trong `C++`.

***Lưu ý:*** Mình sẽ mặc định các bạn đọc đã biết và hiểu các kiến thức yêu cầu ở trên để việc học và áp dụng xây dựng cấu trúc dữ liệu được hiệu quả hơn.

---

## Mở đầu về danh sách liên kết

![Ví dụ về Linked list (danh sách liên kết)](./img/linked-list.png)

Hình trên mô tả mô hình hoạt động của danh sách liên kết đơn (*loại danh sách liên kết đơn giản nhất*) có $5$ phần tử. Phần tử đứng trước liên kết với phần tử đứng liền sau (*theo mũi tên*) và phần tử cuối cùng liên kết giá trị `null` (*giá trị không xác định*)

Mỗi phần tử trong danh sách được gọi là một `node` (nút). Mỗi `node` sẽ thường có thành phần chứa giá trị (hoặc thông tin) gọi là `info` và một con trỏ `next` trỏ đến phần tử kế tiếp (*liên kết*).

---

## Xây dựng danh sách liên kết

***Mục tiêu:*** Xây dựng danh sách liên kết chứa các số nguyên kiểu `int` (*xem trên hình vẽ*).

### Xây dựng từng node của danh sách

Như đã mô tả mỗi `node` của danh sách sẽ có hai thành phần là `info` (chứa giá trị của `node` ) và con trỏ `next` trỏ đến phần tử kế tiếp.

Như vậy, có thể sử dụng `struct` hoặc `class` để xây dựng `node` cho danh sách. Song, nếu dữ liệu liên quan đến `node` không quá phức tạp, nên sử dụng `struct` cho đơn giản. Ở đây mình sẽ sử dụng `struct`.

```cpp
struct Node {
    int info;
    Node* next;
}
```

***Giải thích Code:***

Bên trên là `struct Node` gồm hai `field` là `info` và `next` có ý nghĩa như mô tả ở trên. Cụ thể:

- Field `info` có kiểu dữ liệu `int` chứa các số nguyên là giá trị được lưu trữ.
- Field `next` có kiểu dữ liệu `Node*` là một con trỏ, trỏ tới ô nhớ có kiểu dữ liệu là một `Node` (trỏ tới `node` tiếp theo).




