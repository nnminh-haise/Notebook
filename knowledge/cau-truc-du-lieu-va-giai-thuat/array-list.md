
# Danh sách tuyến tính

---

## Table of contents

- [Khái niệm danh sách tuyến tính](#khái-niệm-danh-sách-tuyến-tính)
- [Danh sách tuyến tính](#danh-sách-tuyến-tính)

    - [Khai báo](#khai-báo)
    - [Các phép toán trên danh sách tuyến tính](#các-phép-toán-trên-danh-sách-tuyến-tính)

- [References](#references)

---

## Khái niệm danh sách tuyến tính

- Danh sách là một tập hợp có $n$ phần tử $a_0, a_1, a_2, \ldots, a_{n - 1}$ có cùng kiểu dữ liệu.

- Danh sách tuyến tính là một danh sách các phần tử có cùng kiểu dữ liệu được sắp xếp liên tiếp nhau trong bộ nhớ.

- Tính tuyến tính của danh sách thể hiện ở sự ràng buộc giữa các phần tử trong danh sách với nhau. Từ vị trí của phần tử $a_i$ ta sẽ tìm được giá trị của phần tử $a_{i + 1}$.

<div id="memory-sample">

| Địa chỉ | Giá trị |
| :---: | :---: |
| 0100 |   |
| 0104 | 0 |
| 0108 | 1 |
| 0112 | 2 |
| ... | ... |
| ... | n - 1|

<p>
Mô hình hoạt động của bộ nhớ trong máy tính.
</p>

</div>

***Đặc điểm của danh sách tuyến tính:***

- Kích thước của danh sách sẽ được cấp phát theo khai báo.
- Các phần tử của danh sách nằm liên tục nhau trong bộ nhớ (giữa các phần tử này không có khoảng trống).
- Tiêu biểu cho danh sách đặc là dãy (array). Để cài đặt danh sách tuyến tính, ta sử dụng mảng một chiều.

---

## Danh sách tuyến tính

### Khai báo

Khai báo một `struct` gồm hai `field`:

- $n$: số lượng phần tử có trong danh sách. Nếu $n = 0$ thì danh sách rỗng.
- $nodes$: là mảng một chiều, mỗi phần tử của mảng là $1$ phần tử trong danh sách.

Để tạo một danh sách tuyến tính, ta có thể khai báo theo $3$ cách sau:

***Cách 1 - cấp phát tĩnh***

```cpp
const int MAX_SIZE = 1000;

typedef struct List {
    int n;
    int nodes[MAX_SIZE];
};

List list;
```

***Cách 2 - Cấp phát động***

```cpp
typedef struct List {
    int n;
    int* nodes;
};

List list;

void Init(List& list) {
    std::cin >> list.n;
    list.nodes = new int[list.n];
}
```

***Cách 3 - Cấp phát tĩnh và động - Mảng con trỏ***

```cpp
const int MAX_SIZE = 1000;

struct Person {
    std::string name;
    int age;
    char gender;
};

typedef struct List {
    int n;
    Person* nodes[MAX_SIZE];
};

void Init(List& list) {
    std::cin >> list.n;
    for (int i = 0; i < list.n; ++i) {
        list.nodes[i] = new Person;
    }
}
```

### Các phép toán trên danh sách tuyến tính

---

## References



