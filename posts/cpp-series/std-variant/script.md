
# Variant trong C++

<!-- Nội dung bài viết -->
Trong lập trình, khả năng lưu trữ đa dạng các kiểu dữ liệu cho cùng một biến là một tính năng đặc biệt và rất hữu dụng trong nhiều trường hợp. Một số ngôn ngữ lập trình khác đã đem tính năng này làm tính năng mặc định cho ngôn ngữ đó như `python` nhưng đối với `C++` thì đây là một tính năng vừa được đưa vào cách đây không lâu ở phiên bản `C++17`.

<!-- Mô tả ảnh 1 -->
Trước tiên, để sử dụng tính năng này, chúng ta sẽ sử dụng thư viện `std::variant` với phiên bản `C++17` và thêm câu lệnh `#include <variant>` vào trong code.

<!-- Nội dung ảnh 1 -->
Để sử dụng kiểu `std::variant` ta sử dụng từ khóa `std::variant` theo sau đó là cặp ngoặc nhọn `<>` bên trong là các kiểu dữ liệu `T` có thể được chứa trong biến đó.

<!-- Ảnh 1 -->
```cpp
#include <iostream>
#include <string>
#include <variant>

int main() {
    std::variant<int, std::string> data;

    data = 10;
    std::cout << "data = " << std::get<int>(data) << std::endl;
    
    data = "10 as string";
    std::cout << "data = " << std::get<std::string>(data) << std::endl;

    return 0;
}
```

 <!-- Ảnh 2 -->
Biến `data` được định nghĩa với cấu trúc `std::variant<int, std::string>` thì `data` có thể lưu được dữ liệu thuộc kiểu `int` hoặc kiểu `std::string` tại cùng một thời điểm.

Để lấy dữ liệu thuộc kiểu dữ liệu mà ta mong muốn, ta phải sử dụng thêm `std::get` với tham số là kiểu dữ liệu mong muốn và biến thuộc kiểu `std::variant` có chứa kiểu đó.

- Để lấy kiểu dữ liệu `int` từ biến `data` ta dùng như sau: `std::get<int>(data)` để lấy dữ liệu từ biến `data` có kiểu `int`.
- Để lấy kiểu dữ liệu `std::string` từ biến `data` ta dùng như sau: `std::get<std::string>(data)` để lấy dữ liệu từ biến `data` có kiểu `std::string`.

<!-- Ảnh 3 -->
Có một số lưu ý về các kiểu dữ liệu `T` có thể được chứa trong `std::variant`:

- Các biến thuộc kiểu `std::variant` trong một thời điểm chỉ có thể lưu trữ dữ liệu thuộc một trong các kiểu dữ liệu thay thế đã liệt kê.
- Các kiểu dữ liệu `T` không được là: tham chiếu, mảng hay `void`.
- Nếu bạn không gán giá trị khởi tạo cho variant, thì nó sẽ tự khởi tạo giá trị cho nó tương ứng với giá trị khởi tạo của kiểu dữ liệu đầu tiên trong variant đó.
- `std::variant` không thực hiện [**heap memory allocation**](https://www.geeksforgeeks.org/stack-vs-heap-memory-allocation/).

<!-- Mô tả ảnh 4 -->
Để khắc phục nhược điểm không thể lưu trữ mảng, ta có thể sử dụng `std::array` hoặc `std::vector`. Ta có thể xem xét ví dụ sau:

<!-- Ảnh 4 -->
```cpp
#include <iostream>
#include <variant>
#include <vector>
#include <array>

int main() {
    std::variant<std::vector<int>, std::array<int, 3>> data;

    std::vector<int> arr = {3, 4, 5};
    data = arr;
    for (int item: std::get<std::vector<int>>(data)) {
        std::cout << item << "\n";
    }

    std::array<int, 3> arr2 = {10, 11, 12};
    data = arr2;
    for (int item: std::get<std::array<int, 3>>(data)) {
        std::cout << item << "\n";
    }

    return 0;
}
```

<!-- Mô tả ảnh 5 -->
Để biết được hiện tại một variant đang lưu trữ dữ liệu thuộc kiểu gì, `std::variant` cung cấp phương thức `index()` trả về một số nguyên không âm là chỉ số của kiểu dữ liệu tương ứng được khai báo trong variant.

Ví dụ: nếu ta có một variant được khai báo là `std::variant<int, char, bool> data` thì nếu `data` đang chứa dữ liệu thuộc kiểu `int` thì `data.index()` sẽ bằng $0$ và lần lượt là $1$ và $2$ nếu lần lượt chứa dữ liệu thuộc kiểu `char` và `bool`.

<!-- Ảnh 5 -->
```cpp
#include <iostream>
#include <string>
#include <variant>

void ShowValue(std::variant<int, std::string>& data) {
    if (data.index() == 0) {
        int value = std::get<int>(data);
        std::cout << "value is an integer = " << value << std::endl;
    }
    else {
        std::string value = std::get<std::string>(data);
        std::cout << "value is a string = " << value << std::endl;
    }
}

int main() {
    std::variant<int, std::string> data{};
    
    data = 10;
    ShowValue(data); // Print: value is an integer = 10
    
    data = "100";
    ShowValue(data); // Print: value is a string = 100

    return 0;
}
```

<!-- Mô tả ảnh 6 -->
Với `std::get_if` ta có thể viết lại hàm trên theo cách khác như dưới đây.

<!-- Ảnh 6 -->
```cpp
#include <iostream>
#include <string>
#include <variant>

template<typename T>
void ShowValue(std::variant<int, std::string>& data) {
    
    auto* value = std::get_if<T>(&data);
    if (value) {
        std::cout << "value = " << *value << std::endl;
    }
    else {
        std::cout << "value type is not correct!" << std::endl;
    }
}

int main() {
    std::variant<int, std::string> data{};
    
    data = 10;
    ShowValue<int>(data);
    
    data = "100";
    ShowValue<int>(data);
    
    data = "100";
    ShowValue<std::string>(data);

    return 0;
}
```

<!-- Mô tả anh 7 -->
Hoặc ta có thể sử dụng `try...catch` để xử lí trường hợp có thể gặp lỗi.

<!-- Ảnh 7 -->
```cpp
#include <iostream>
#include <string>
#include <variant>

void ShowIntValue(std::variant<int, std::string>& data) {
    try {
        int value = std::get<int>(data);
        std::cout << "The int value is: " << value << std::endl;
    }
    catch (std::bad_variant_access&) {
        std::cout << "the variant doesn't hold an int at this moment!" << std::endl;
    }
}

int main() {
    std::variant<int, std::string> data;

    data = 10;
    ShowIntValue(data);
    
    data = "100";
    ShowIntValue(data);

    return 0;
}
```

<!-- Mô tả ảnh 8 -->
Một ứng dụng khác của `std::variant` là cho ta sự linh hoạt khi thiết kế các hàm. Ví dụ ta cần thiết kế một hàm đọc dữ liệu từ một file và lưu dưới dạng chuỗi. Hàm sẽ nhận vào tham số là đường dẫn đến file, hàm sẽ thực hiện các thủ tục cần thiết và sẽ trả về chuỗi đọc được. Vậy nếu vì nhiều lí do mà hàm không đọc được file thì ta sẽ xử lí như thế nào? Thường thấy ta sẽ phải thêm một tham chiếu để trả về lỗi. Với `std::variant` ta có thể làm như dưới đây.

<!-- Ảnh 8 -->
```cpp
enum class ErrorCode {
    None,
    FileNotFound,
    NoAccess
};

std::variant<std::string, ErrorCode> ReadFileAsString(std::string file) {
    // process and return the corresponding result.
}
```

<!-- Mô tả ảnh 9 -->
## Kích thước của một variant

Đoạn code dưới đây cho thấy kích thước của các kiểu dữ liệu `int`, `std::string`, `std::variant<int, std::string>` và một `struct` gồm một biến kiểu `int` và một biến kiểu `std::string`.

<!-- Ảnh 9 -->
```cpp
#include <iostream>
#include <string>
#include <variant>

struct MyData {
    int a;
    std::string b;
};

int main() {
    std::variant<int, std::string> data;
    
    std::cout << "Size of int: " << sizeof(int) << std::endl; // Size of int: 4
    std::cout << "Size of std::string: " << sizeof(std::string) << std::endl; // Size of int: 32
    std::cout << "Size of data: " << sizeof(data) << std::endl; // Size of int: 40
    std::cout << "Size of MyData: " << sizeof(MyData) << std::endl; // Size of int: 40

    return 0;
}
```

<!-- Nội dung ảnh 9 -->
Kích thước của một variant tương đương với một `struct` đồng dạng nhưng chỉ cho phép lưu trữ dữ liệu có kiểu của một trong các kiểu đã được khai báo.

Song, không vì vậy mà variant là một "bước lùi" so với `struct`! Trong các trường hợp, trừ khi bạn thật sự quan tâm rất nhiều đến tối ưu hóa bộ nhớ thì bạn nên sử dụng `union`, ngược lại bạn nên sử dụng `std::variant`.

<!-- Ảnh 10 -->
## Ưu và nhược điểm

***Ưu điểm:***

- Cho phép lưu trữ đa dạng kiểu dữ liệu trong cùng một biến.
- Đảm bảo sự chặt chẽ về dữ liệu khi giới hạn số lượng các kiểu dữ liệu có thể được lưu trữ.
- Không thực hiện heap memory allocation.

***Nhược điểm:***

- Giới hạn số lượng các kiểu dữ liệu có thể được lưu trữ.
- Yêu cầu thiết kế hệ thống và chương trình kỹ càng để tránh hạn chế mất thời gian khi phải sửa lại code.
- Sử dụng nhiều bộ nhớ hơn `union` với khả năng tương tự.

## Lí do sử dụng

- Khi bạn cần nhiều kiểu dữ liệu cùng tồn tại trong một biến duy nhất.
- Khi thực hiện các thao tác xử lí lỗi.
- Và nhiều lí do khác.

<!-- Bỏ qua -->
## Một số bài viết tham khảo

1. [Everything You Need to Know About std::variant from C++17 | cppstories.com](https://www.cppstories.com/2018/06/variant/)
2. [variant | learn.microsoft.com](https://learn.microsoft.com/en-us/cpp/standard-library/variant?view=msvc-170)
3. [std::variant | cppreference.com](https://en.cppreference.com/w/cpp/utility/variant)
