# Object and Classes

---

## Introduction to Object-Oriented Programming

### Classes

- `Class` là template để `Object` dựa vào đó và được tạo ra.
- Tạo một `Object` từ một `Class` thì `Object` đó là một *instance* (phiên bản/trường hợp) của `Class`.
- **Encapsulation** - Tính bao đóng:
    - Kết hợp dữ liệu và hành vi của nó vào trong một bộ, giấu chi tiết cách hoạt động khỏi người dùng.
    - Dữ liệu là một instance của một field và mỗi hành vi được xem như một method.
    - Mỗi `Object` cụ thể có các giá trị cụ thể cho một field của nó đại diện cho một trạng thái của `Class` đó.
    - Chương trình chỉ tương tác với `Object` thông qua các method của nó.
- Trong `Java`, khi tạo ra một `Object` mới từ một `Object` đã có sẵn thì `Object` mới sẽ có những field và method của `Object` gốc.

### Objects

- Ba đặc tính chủ chốt của `Object`:
    1. **Hành vi của `Object`** - "Đối tượng đó sẽ làm gì?".
    2. **Trạng thái của `Object`** - Thông tin của `Object` mô tả hình dáng của `Object`. Cách `Object` hoạt động khi gọi các method của nó.
    3. **Danh tính của `Object`** - Cách các `Object` có  thể phân biệt với nhau nếu những `Object` có cùng hành vi và trạng thái.

### Định nghĩa các Class

- Định danh của các `Class` nên là các **danh từ** đại diện cho ý nghĩa của `Cless` đó.
- Định danh của các `method` của `Class` nên là các **động từ** chỉ hoạt động của phương thức đó.

### Quan hệ giữa các Class

Các quan hệ thông dụng nhất giữa các `Class`:

- Dependence - Quan hệ phụ thuộc.
- Aggregation - Quan hệ thu nạp (*hoặc quan hệ kết hợp*).
- Inheritance - Quan hệ kế thừa.

#### Dependence - Quan hệ phụ thuộc

- Trong kỹ nghệ phần mềm (software engineering) thì sự phụ thuộc (dependence) hay sự liên kết (coupling) giữa hai lớp khác nhau là khi phương thức của lớp này sử dụng hoặc thao tác lớp khác.

> ➣ *English:* Dependence or coupling in software engineering: a class depends on 
another class if its methods use or manipulate objects of that class.

***Ví dụ:***

Lớp `Order` sẽ sử dụng lớp `Account` để kiểm tra trạng thái thanh toán của tài khoản đó.

#### Aggregation - Quan hệ thu nạp

- Khi đối tượng $A$ của lớp này **chứa** đối tượng $B$ của lớp khác thì hai lớp đó được gọi là có quan hệ thu nạp.

#### Inheritance - Quan hệ kế thừa

> 💡 *Một lớp tổng quát và một lớp cụ thể.*

- Nếu lớp $A$ là một lớp mở rộng (extend) từ lớp $B$ thì lớp $A$ sẽ có tất cả những gì mà lớp $B$ có (bao gồm tất cả các field và method) và thêm những khả năng mới.

***Ví dụ:***

- Lớp `Order` là lớp các loại đơn đặt hàng.
- Lớp `RushOrder` là một lớp chỉ các đơn đặt hàng nhanh.
- Lớp `RughOrder` là một lớp được mở rộng từ lớp `Order`: vì cả hai đều có điểm chung là đơn đặt hàng. Sonh lớp `RushOrder` có thêm những field và method mới đặc trưng cho các loại đơn đặt hàng nhanh.

---

## Objects and Object variables

- Khai báo một Object variable:

```java
Date birthday; // Không ám chỉ đến một đối tượng nào cụ thể.
```

- Khởi tạo một Object sử dụng các Constructor:

```java
Date birthday = new Date();
```

- Constructors sẽ có tên trùng với đối tượng của Constructors tương ứng.

![Object constructors](./img/object-constructors.png)

- Một hàm `toString()` trong đối tượng `Date` có chức năng trả về một chuỗi đại diện cho đối tượng đó là một ngày theo định dạng ngày tháng năm phù hợp.

```java
String strBirthday = birthday.toString();
```

- Phép gán:

```java
Date deadline = birthday;
```

![](./img/multiple-instance-of-one-class.png)

Cả hai biến `birthday` và `deadline` đều có chung một lớp là `Date`


### Mutator and Accessor methods

- **Mutator methods**: là những phương thức tác động lên một đối tượng và thay đổi trạng thái của đối tượng đó.
- **Accessor methods:** là những phương thức chỉ tác động lên một đối tượng mà không thay đổi trạng thái của đối tượng đó.

---

## Tạo một đối tượng trong Java



---

## References
