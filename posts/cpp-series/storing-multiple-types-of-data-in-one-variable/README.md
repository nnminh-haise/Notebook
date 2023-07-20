
# Structure Bindings Trong C++

Trong lập trình, ta thường chỉ thấy mỗi một hàm chỉ trả về một giá trị nhất định. Song, thực tế thì ngược lại, vậy khi gặp tình huống mà hàm cần phải trả về nhiều hơn một giá trị thì ta sẽ làm như thế nào? Đối với một số ngôn ngữ như `Python` thì việc này tương đối đơn giản vì `Python` có hỗ trợ cho việc này.

```python
def return_more_than_one_values():
    return 1, 2, 3
    
print(return_more_than_one_values())
```

Nhưng còn đối với `C++` thì sao? Để dễ dàng hơn mình sẽ cùng đi qua một ví dụ đơn giản như sau: viết một hàm nhận vào một mảng các số nguyên và kích thước của mảng, trả về giá trị lớn nhất và giá trị nhỏ nhất của mảng.

Mình sẽ đưa ra một lời giải gợi ý đơn giản như ở dưới đây.

```cpp
#include <iostream>

struct MinAndMax {
    int minValue = 0;
    int maxValue = 0;
};

MinAndMax GetMinAndMax(int a[], int n) {
    MinAndMax result;
    result.minValue = a[0];
    result.maxValue = a[0];
    
    for (int i = 1; i < n; ++i) {
        result.minValue = std::min(result.minValue, a[i]);
        result.maxValue = std::max(result.maxValue, a[i]);
    }
    
    return result;
}

int main() {
    int a[] = {1, 2, 3, 4, 5};
    MinAndMax res = GetMinAndMax(a, 5);
    std::cout << res.minValue << " " << res.maxValue << std::endl;

    return 0;
}
```

Ta tạo một `struct` để lưu trữ các dữ liệu cần trả về, khi đó ta chỉ cần trả về một đối tượng thuộc kiểu vừa tạo là vấn đề được giải quyết! Cách này có ưu điểm: nếu trong quá trình code, ta cần mở rộng thêm số lượng các kiểu dữ liệu cần trả về, ta chỉ cần thay đổi `struct` và thay đổi ở code xử lí nếu cần.

Bên cạnh việc sử dụng `struct` ta có thể sử dụng `std::tuple` để đơn giản hóa thao tác này đi một chút như sau:

```cpp
#include <iostream>
#include <tuple>

std::tuple<int, int> GetMinAndMax(int a[], int n) {
    int minValue = a[0];
    int maxValue = a[0];
    
    for (int i = 1; i < n; ++i) {
        minValue = std::min(minValue, a[i]);
        maxValue = std::max(maxValue, a[i]);
    }
    
    return {minValue, maxValue};
}

int main() {
    int a[] = {1, 2, 3, 4, 5};
    std::tuple<int, int> res = GetMinAndMax(a, 5);
    std::cout << std::get<0>(res) << " " << std::get<1>(res) << std::endl;

    // or

    int minValue{}, maxValue{};
    std::tie(minValue, maxValue) = GetMinAndMax(a, 5);
    std::cout << minValue << " " << maxValue << std::endl;

    return 0;
}
```

Cách viết này tương đối gọn gàng và khiến cho việc đọc hiểu code đơn giản hơn nhiều. Đỡ phải tốn công đi tạo ra một `struct` riêng. Song việc xử lí dữ liệu có phần hơi cồng kềnh, ta có thể cải thiện một chút bằng cách sử dụng `std::tie` như trên.

Với việc cung cấp structure bindings trong phiên bản `C++17` thì việc này đã trở nên dễ dàng hơn nữa. Cụ thể, ta vẫn sẽ sử dụng `std::tuple` nhưng thay vì lấy dữ liệu ra theo cách cồng kềnh như trên ta sẽ làm như sau:

```cpp
int main() {
    int a[] = {1, 2, 3, 4, 5};
    
    auto[minValue, maxValue] = GetMinAndMax(a, 5);
    std::cout << minValue << " " << maxValue << std::endl;

    return 0;
}
```

Ta sử dụng từ khóa `auto` sau đó là một cặp ngoặc vuông, bên trong là số lượng biến tương ứng với số kiểu mà `tuple` trả về. Các biến `minValue` và `maxValue` sẽ được tự động tạo ra với kiểu dữ liệu theo thứ tự tương ứng với `tuple` được trả về. Ta chỉ việc sử dụng các biến này trực tiếp mà không cần phải viết những đoạn code khó hiểu như trên.

**Lưu ý:** Tính năng structure bindings này chỉ xuất hiện từ phiên bản `C++17` trở lên!

***Vậy khi nào nên sử dụng structure bindings?***

Khi dữ liệu trả về không có tính tái sử dụng cao. Ví dụ khi hàm trả về một đơn hàng, bạn sẽ muốn lưu lại đơn hàng để có thể truy vấn cho các yêu cầu khác. Lúc này việc lưu trữ các dữ liệu đó là cần thiết nên sử dụng `struct` sẽ hợp lí hơn. Còn đối với ví dụ trên là khi dữ liệu không có quá nhiều ý nghĩa quan trọng và mức độ tái sử dụng thấp thì việc sử dụng structure bindings sẽ giúp cho việc viết code được đơn giản và dễ dàng hơn!
