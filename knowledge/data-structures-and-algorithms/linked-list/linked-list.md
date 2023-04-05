
# Linked List - Danh sách liên kết

---

<!-- @import "[TOC]" {cmd="toc" depthFrom=2 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

- [Kiến thức yêu cầu](#kiến-thức-yêu-cầu)
  - [Kiến thức nền tảng](#kiến-thức-nền-tảng)
  - [Khái niệm nâng cao sẽ xuất hiện](#khái-niệm-nâng-cao-sẽ-xuất-hiện)
  - [Một số điểm chú ý khác](#một-số-điểm-chú-ý-khác)
- [Mở đầu về danh sách liên kết](#mở-đầu-về-danh-sách-liên-kết)
- [Xây dựng danh sách liên kết](#xây-dựng-danh-sách-liên-kết)
  - [Xây dựng từng node của danh sách](#xây-dựng-từng-node-của-danh-sách)
  - [Initialize - Module khởi tạo.](#initialize---module-khởi-tạo)
  - [IsEmpty - Module kiểm tra danh sách rỗng](#isempty---module-kiểm-tra-danh-sách-rỗng)
  - [Traversal - Module duyệt danh sách](#traversal---module-duyệt-danh-sách)
  - [Search - Module tìm kiếm phần tử dựa trên `info`](#search---module-tìm-kiếm-phần-tử-dựa-trên-info)
  - [InsertFirst - Module thêm phần tử có nội dung `info` vào đầu danh sách](#insertfirst---module-thêm-phần-tử-có-nội-dung-info-vào-đầu-danh-sách)
  - [InsertLast - Module thêm phần tử có `info` vào cuối danh sách](#insertlast---module-thêm-phần-tử-có-info-vào-cuối-danh-sách)
  - [InsertAfter - Thêm phần tử có nội dung `info` vào sau phần tử `p` trong danh sách](#insertafter---thêm-phần-tử-có-nội-dung-info-vào-sau-phần-tử-p-trong-danh-sách)
  - [DeleteFirst - Module xóa phần tử đứng đầu danh sách](#deletefirst---module-xóa-phần-tử-đứng-đầu-danh-sách)
  - [DeleteAfter - Module xóa phần tử đứng sau phần tử `p`](#deleteafter---module-xóa-phần-tử-đứng-sau-phần-tử-p)
  - [InsertLast - Module xóa phần tử ở cuối danh sách](#insertlast---module-xóa-phần-tử-ở-cuối-danh-sách)
  - [DeleteInfo - Module xóa phần tử có nội dung `info`](#deleteinfo---module-xóa-phần-tử-có-nội-dung-info)

<!-- /code_chunk_output -->

---

## Kiến thức yêu cầu

> *Đây là một số kiến thức yêu cầu do chính bản thân mình đặt ra để việc tiếp cận với bài viết trở nên thuận tiện hơn vì nhiều lí do. Các bạn có thể bỏ qua phần này, song việc tiếp cận bài viết có thể sẽ trở nên khó khăn, mình nghĩ bạn nên cân nhắc.*

### Kiến thức nền tảng

- Kiến thức cơ bản ngôn ngữ lập trình. Ở đây mình chọn `C++`.
- Khái niệm `pointer` (con trỏ).
- Khái niệm `struct` và `class`.
- Khái niệm `function prototype` hay `function declaration` và `function definition` trong C++.
- Phân biệt giữa `procedure` và `function` (thủ tục và hàm).

### Khái niệm nâng cao sẽ xuất hiện

- Khái niệm `namespace` trong `C++`.
- Khái niệm `header file` trong `C++`.
- Khái niệm `reference` (tham chiếu) trong `C++`.

IDE sử dụng: Clion hoặc Visual Studio. Các bạn cũng có thể sử dụng VS Code. Song vì VS Code không hỗ trợ Linker nên việc áp dụng hoàn toàn theo Handbook sẽ có đôi chút khác, các bạn nên lưu ý.

### Một số điểm chú ý khác

1. Mình sử dụng IDE Visual Studio để viết code với ngôn ngữ `C++`.
2. Mình không viết logic của code ở trong `header file` (file `.h`) vì cách hoạt động của `header file` là nội dung của nó sẽ được sao chép lại vào nơi gọi nó. Do đó để tránh việc các `method` bị định nghĩa nhiều lần dẫn đến lỗi thì mình sẽ viết `function declaration` ở `header file` còn `function definition` sẽ được viết trong `.cpp` file có tên tương ứng.
3. Mình sử dụng `namespace` để tránh việc khi các bạn sử dụng code của mình trong các project hay bài tập lớn tránh bị trùng tên biến. Mình cũng khuyến khích các bạn làm điều tương tự khi học, khi làm bài tập lớn, project cá nhân hay bài tập nhóm.

---

## Mở đầu về danh sách liên kết


```mermaid
flowchart LR

0[2] --> 1[3] --> 2[1] --> 3[7] --> 4[8] --> 5[10] --> 6[6] --> 7[4] --> 8[5] --> NULL

```

Danh sách liên kết về bản chất là một danh sách dùng để lưu trữ dữ liệu. Song, khác với danh sách tuyến tính thì danh sách liên kết có những ưu điểm riêng biệt khiến cho danh sách liên kết có nhiều điểm mạnh hơn so với danh sách tuyến tính trong một số trường hợp cụ thể.

Danh sách liên kết là một **"danh sách"** nên nó cũng là một tập hợp các phần tử cùng kiểu dữ liệu. Song, khác với danh sách tuyến tính thì:

- Xét về mặt địa chỉ, thì các phần tử trong danh sách liên kết không nhất thiết phải liên tiếp nhau.
- Mối quan hệ giữa hai phần tử được xác định bởi "liên kết", là điều khiến danh sách liên kết đặc biệt.
- Mỗi phần tử trong danh sách liên kết, ngoài việc chứa dữ liệu cần lưu trữ thì sẽ chứa một "liên kết" dẫn đến phần tử tiếp theo trong danh sách. Liên kết này có thể bị loại bỏ hoặc thay đổi tùy thuộc vào nhu cầu.

Một số điểm cần lưu ý về danh sách liên kết:

1. Kích thước của danh sách liên kết là không giới hạn.
2. Việc thêm phần tử vào danh sách liên kết tùy vào vị trí thêm sẽ có độ phức tạp khác nhau.
3. Có nhiều loại danh sách liên kết khác nhau.
4. Để truy cập đến một phàn tử thuộc danh sách cần phải duyệt từ đầu danh sách đến vị trí cần truy cập, không thể truy cập qua chỉ số như danh sách tuyến tính.

---

## Xây dựng danh sách liên kết

> *Trong khuôn khổ bài viết, mình sẽ xây dựng danh sách liên kết đơn, mỗi phần tử chỉ sở hữu duy nhất một liên kết dẫn đến phần tử kế tiếp trong danh sách. Do vậy, từ phần sau của tài liệu, khi nói đến danh sách liên kết (hay danh sách), ta hiểu đó là danh sách liên kết đơn!*

***Mục tiêu:*** Ta sẽ xây dựng cấu trúc dữ liệu danh sách liên kết chứa các phần tử có kiểu dữ liệu là số nguyên kiểu `int`.

***Quy ước:***

1. Khi danh sách được khởi tạo là một danh sách rỗng.
2. Ta sẽ quản lí phần tử đầu tiên của danh sách chứ không quản lí toàn bộ phần tử trong danh sách. Ta gọi phần tử này là `First` hoặc `Head` ở một số tài liệu khác. Về bản chất, `First` sẽ là một con trỏ, trỏ tới địa chỉ của phần tử đầu tiên của danh sách tuyến tính.
3. Danh sách được xem là **rỗng** nếu phần tử `First` bằng `NULL`.
4. Phần tử cuối cùng của danh sách có liên kết trỏ tới giá trị `NULL`.

### Xây dựng từng node của danh sách

Đối với danh sách liên kết ta đang xây dựng, mỗi phần tử sẽ lưu trữ hai thông tin:

1. `info`: là giá trị cần lưu trữ trong danh sách.
2. `next`: là con trỏ lưu trữ địa chỉ của phần tử tiếp theo trong danh sách. Đây chính là "liên kết" giữa phần tử hiện tại và phần tử kết tiếp trong danh sách.

Như vậy, có thể sử dụng `struct` hoặc `class` để xây dựng `node` cho danh sách. Song, nếu dữ liệu liên quan đến `node` không quá phức tạp, nên sử dụng `struct` cho đơn giản. Ở đây mình sẽ sử dụng `struct`.

`LinkedList.h`

```cpp
namespace LinkedList {
    struct Node {
        int info;
        Node* next;
    };
    typedef Node* Pointer;
}
```

**Giải thích Code:**

Bên trên là `struct Node` gồm hai `field` là `info` và `next` có ý nghĩa như mô tả ở trên. Cụ thể:

- Field `info` có kiểu dữ liệu `int` chứa các số nguyên là giá trị được lưu trữ.
- Field `next` có kiểu dữ liệu `Node*` là một con trỏ, trỏ tới ô nhớ có kiểu dữ liệu là một `Node` (trỏ tới `node` tiếp theo).
- Bên cạnh đó, ta tạm định nghĩa lại kiểu `Node*` là `Pointer` cho dễ hiểu là con trỏ.

### Initialize - Module khởi tạo.

Như đã quy ước, danh sách khi được khởi tạo sẽ là một danh sách rỗng. Do đó, `First` sẽ có giá trị là `NULL` khi danh sách được khởi tạo.

`LinkedList.h`

```cpp
namespace LinkedList {
    void Initialize(Pointer& First);
}
```

`LinkedList.cpp`

```cpp
void LinkedList::Initialize(LinkedList::Pointer& First) {
    First = nullptr;
}
```

**Giải thích Code:** 

- Thủ tục `Initialize` có chưc năng khởi tạo cho danh sách được truyền vào.
- Vì danh sách được truyền vào sẽ bị `modify` (thay đổi), do đó, danh sách sẽ được truyền vào thủ tục theo dạng tham chiếu.
- Theo như quy ước, danh sách khi khỏi tạo sẽ rỗng, do đó giá trị của `First` sẽ bằng `NULL`. Vì vậy, ta gán giá trị cho biến `First` là `nullptr`.

### IsEmpty - Module kiểm tra danh sách rỗng

Theo như quy ước trên, danh sách rỗng khi giá trị `First` bằng `NULL`. Do đó, ta lập luận, nếu `First` bằng `NULL` thì kết luận danh sách rỗng và ngược lại.

`LinkedList.h`

```cpp
namespace LinkedList {
    bool IsEmpty(const Pointer& First);
}
```

`LinkedList.cpp`

```cpp
bool LinkedList::IsEmpty(const LinkedList::Pointer& First) {
    return First == nullptr;
}
```

**Giải thích Code:**

- Hàm trả về giá trị thuộc kiểu `bool` và nhận vào tham chiếu hằng `First` đại diện cho danh sách.
- Nếu `First` bằng `nullptr` thì danh sách rỗng và trả về `true` và ngược lại.

### Traversal - Module duyệt danh sách

Để có thể làm việc tốt với dữ liệu thì việc hiểu và hình dung được nó là một điều cần thiết. Và dễ dàng nhất là khi ta có thể nhìn thấy được dữ liệu đang chứa gì. Có được khả năng xem toàn bộ danh sách bất cứ lúc nào sẽ giúp cho việc làm việc với danh sách trở nên thuận tiện hơn nhiều.

Với danh sách tuyến tính, ta chỉ quản lí phần tử đầu tiên của danh sách, do vậy ta phải duyệt tuần tự từ đầu đến cuối danh sách dựa trên các liên kết giữa các phần tử đã thiết lập sẵn.

`LinkedList.h`

```cpp
namespace LinkedList {
    void Traversal(Pointer First, const std::string& message = "List: ");
}
```

`LinkedList.cpp`

```cpp
void LinkedList::Traversal(LinkedList::Pointer First, const std::string& message) {
    std::cout << message << ": [";

    for (; First != nullptr; First = First->next) {
        std::cout << First->info;
        if (First->next != nullptr) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}
```

**Giải thích code:**

Thủ tục sẽ thực hiện duyệt và in từng phần tử của danh sách ra màn hình console cùng với một tham số `message` được đưa vào.

Thủ tục nhận hai tham số lần lượt là phần tử quản lí `First` của danh sách và thông điệp `message` sẽ được in ra.

Ta quy định thủ tục sẽ in ra màn hình console như sau: `<message>: [a, b, c, ..., x, y, z]`. Trong đó, chuỗi `message` sẽ được thay thế cho `<message>` và nội dung của các phần tử trong danh sách sẽ thay cho `a, b, c, ..., x, y, z` (dấu `,` sẽ được dùng để ngăn cách các nội dung).

Ta sử dụng vòng lặp `for` để duyêt qua danh sách. Ta sẽ dừng lại khi duyệt hết danh sách, nghĩa là duyệt đến giá trị `nullptr` và sau mỗi lần lặp, ta sẽ di chuyển sang phần tử kế tiếp bằng lệnh `First = First->next`. Trong mỗi lần lặp, ta sẽ in ra `info` của `First` và sử dụng câu lệnh `if` để xem xét có cần in dấu `,` hay không.

***Lưu ý:*** Đây chỉ là một cách in do mình gợi í, bạn có thể tùy biến lại theo cách bạn muốn hoặc đơn giản hóa nó đi.

### Search - Module tìm kiếm phần tử dựa trên `info`

Một phép toán thường thấy khi làm việc với cơ sở dữ liệu là phép tìm kiếm dữ liệu cần thiết. Ở đây, ta sẽ xây dựng một module tìm kiến trong danh sách phần tử có nội dung `info` và trả về con trỏ của phần tử đó nếu có, hoặc trả về `NULL` nếu không.

`LinkedList.h`

```cpp
namespace LinkedList {
    Pointer Search(const Pointer& First, int info);
}
```

`LinkedList.cpp`

```cpp
LinkedList::Pointer LinkedList::Search(LinkedList::Pointer const &First, const int info) {
    for (LinkedList::Pointer p = First; p != nullptr; p = p->next) {
        if (p->info == info) {
            return p;
        }
    }
    return nullptr;
}
```

**Giải thích Code:**

- Hàm sẽ nhận hai tham số, trong đó một tham biến hằng `First` là con trỏ đại diện cho danh sách và một bằng số `info` là giá trị cần tìm.
- Hàm trả về con trỏ trỏ đến phần tử có nội dung trùng với `info` và trả về `nullptr` trong trường hợp ngược lại.
- Ta sẽ dùng vòng lặp `for` để duyệt qua danh sách, dừng lại khi gặp con trỏ `nullptr` và sẽ di chuyển từ phần tử này sang phần tử khác qua câu lệnh `p = p->next`.
- Trong mỗi bước lặp, ta kiểm tra, nếu `p->info` bằng với `info` thì `p` chính là con trỏ, trỏ tới phần tử có nội dung trùng với `info`. Khi đó, ta trả về `p` là kết quả cần tìm.
- Khi ta kết thúc vòng lặp `for` nghĩa là ta đã duyệt hết danh sách, lúc này ta trả về con trỏ `nullptr` vì ta đã duyệt hết danh sách nhưng vẫn không tìm ra phần tử cần tìm.

### InsertFirst - Module thêm phần tử có nội dung `info` vào đầu danh sách

Khi thêm một phần tử vào danh sách, thường sẽ có $3$ vị trí có thể thêm vào đó là đầu, giữa và cuối danh sách. Đây là module thực hiện chức năng thêm một phần tử có nội dung là `info` vào danh sách.

Ý tưởng của thuật toán như sau:

1. Tạo `node` mới có `info` là `info` được truyền vào.
2. Tạo liên kết giữa phần tử `First` hiện tại của danh sách với `node` mới.

Ở đây, ta sẽ lợi dụng `constructor function` có sẵn trong `struct` để thực hiện tạo một `node` mới một cách nhanh chóng như sau:

`LinkedList.h`

```cpp
namespace LinkedList {
    struct Node {
        int info;
        Node* next;

        Node();

        Node(int value, Node* nextNode);
    };
}
```

`LinkedList.cpp`

```cpp
LinkedList::Node::Node() {
    this->info = 0;
    this->next = nullptr;
}

LinkedList::Node::Node(int value, Node* nextNode) {
    this->info = value;
    this->next = nextNode;
}
```

**Giải thích Code:**

Trong file `LinkedList.h`, tại `struct Node` ta sẽ thêm hai `constructor function`: `Node()` và `Node(int value, Node* nextNode)` vào để thực hiện `struct Node` có thêm chức năng tạo `node` mới một cách ngắn gọn hơn.

1. `Node()` là `default constuctor` - Phương thức khởi tạo mặc định. Sẽ gán các giá trị mặc định cho các `field` có trong `struct Node`. Ở đây, quy ước giá trị mặc định cho các `field`: `info` và `next` sẽ là $0$ và `nullptr`.
2. `Node(int value, Node* nextNode)` là `parameterized constructor` - Phương thức khởi tạo có tham số, nhận hai tham số là `value` và `nextNode` lần lượt là giá trị của `node` được tạo ra và con trỏ trỏ đến `node` kế tiếp trong danh sách.

Với $2$ `constructor function` vừa xây dựng thêm cho `struct Node` ta sẽ thiết kế module `InsertLast` như sau:

`LinkedList.h`

```cpp
namespace LinkedList {
    void InsertFirst(Pointer& First, int value);
}
```

`LinkedList.cpp`

```cpp
void LinkedList::InsertFirst(LinkedList::Pointer& First, int value) {
    LinkedList::Pointer newNode = new Node(value, First);
    First = newNode;
}
```

**Giải thích Code:**

- Thủ tục có $2$ tham số đầu vào là tham chiếu `First` đại diện cho danh sách và tham biến `value` là giá trị của `node` mới sẽ được thêm vào danh sách.
- Ta tạo một con trỏ `nweNode` là con trỏ trỏ tới `node` mới sẽ được tạo ra và thêm vào danh sách. Con trỏ `newNode` này có kiểu là `Node*` hay `Pointer` như ta đã tái định nghĩa ở đầu bài viết.
- Ta sử dụng từ khóa `new` để tạo ra một con trỏ mới trỏ tới ô nhớ chứa biến có kiểu `Node`. Kết hợp với `parameterized constructor` ta đã viết ở trên ta có dòng lệnh dưới đầy.

```cpp
LinkedList::Pointer newNode = new Node(value, First);
```

Ở vế phải toán tử `=`, ta tạo ra một `Node` mới, có giá trị của `info` là `value` và `next` là `First`. Cụ thể:

- `Node(value, First)` sẽ gọi và chạy `paramaterized constructor` của `struct Node` tạo ra một `Node` mới với giá trị các `field` tương ứng dụa trên tham số được truyền vào.
- Sau đó, con trỏ của `Node` này sẽ được lưu vào biến `newNode` ở bên vế trái của toán tử `=`.

`newNode` vừa được tạo ra có `info` là `value` được truyền vào và `next` là địa chỉ của phần tử đầu tiên của danh sách cũ. Điều này đồng nghĩa `newNode` đang đứng trước `First` trong danh sách. Do đó ta sẽ cập nhật lại biến `First` bằng `newNode` vì lúc này, `newNode` chính là phần tử đầu mới của danh sách.

### InsertLast - Module thêm phần tử có `info` vào cuối danh sách

Trong $3$ vị trí thêm có thể khi thêm một phần tử mới vào danh sách thì đây là vị trí tốn nhiều chi phí nhất.

Như đã nói ở trước, ta chỉ quản lí phần tử đầu tiên của danh sách, do vậy, để thêm phần tử vào cuối danh sách thì ta phải di chuyển đến phần tử cuối cùng của danh sách hiện tại rồi sau đó mới thêm phần tử mới vào danh sách.


`LinkedList.h`

```cpp
namespace LinkedList {
    void InsertLast(Pointer& First, int value);
}
```

`LinkedList.cpp`

```cpp
void LinkedList::InsertLast(LinkedList::Pointer& First, int value) {
    LinkedList::Pointer newNode = new Node(value, nullptr);

    if (LinkedList::IsEmpty(First)) {
        First = newNode;
        return;
    }

    LinkedList::Pointer Last = First;
    for (; Last->next != nullptr; Last = Last->next);
    Last->next = newNode;
}
```

**Giải thích code:**

Khi thêm một phần tử vào cuối danh sách, ta thấy, nếu danh sách rỗng thì ta chỉ cần trỏ `First` vào phần tử mới. Ngược lại, ta sẽ duyệt đến cuối danh sách và thêm phần tử mới vào.

- Thủ tục nhận $2$ tham số bao gồm một tham số hình thứ biến `First` đại diện cho danh sách và `value` là giá trị của phần tử sẽ được thêm vào.
- Ta sử dụng từ khóa `new` để tạo ra một `struct Node` mới và lưu địa chỉ của nó vào con trỏ `newNode`. `struct Node` mới này có nội dung là `value` và giá trị của con trỏ `next` trỏ tới `nullptr` vì phần tử được thêm vào cuối danh sách.
- Như đã nói, nếu danh sách rỗng, ta chỉ cần trỏ `First` tới `newNoed`. Ngược lại, ta sẽ duyệt đến phần tử cuối cùng của danh sách, là phần tử có trường `next` bằng `nullptr`, gọi phần tử đó là `Last`. Khi đó, ta chỉ cần tạo liên kết từ `Last` đến `newNote`.

### InsertAfter - Thêm phần tử có nội dung `info` vào sau phần tử `p` trong danh sách

Bên cạnh việc thêm phần tử vào đầu hoặc cuối danh sách thì việc thêm phần tử vào giữa danh sách, tại một vị trí cụ thể nào đó là một phép toán thường gặp. Đối với danh sách liên kết thì việc thêm một phần tử vào vị trí bất kì trong danh sách tương đối khó khăn vì khác với danh sách tuyến tính thì danh sách liên kết không có truy cập phần tử dựa trên chỉ số (indexing access).

Để giải quyết vấn đề này ta sẽ sử dụng thêm thuật toán tìm kiếm. Ví dụ, ta có một danh sách như sau:

***Hình vẽ minh họa quá trình thêm một phần tử vào sau phần tử `p`:***

```mermaid
flowchart TB
    subgraph one [Original]
        direction LR
        A0[10] ==> B0[11] ==> C0[12] ==> D0[13] ==> F0[15] ==> G0[16] ==> Z0[NULL]
    end
```

Giả sử ta cần thêm một phần tử có nội dung $14$ vào sau phần tử có nội dung là $13$ ta sẽ làm như sau:

1. Đầu tiên, cần tìm con trỏ của phần tử chứa nội dung $13$ trong danh sách. Để làm được điều này, ta sẽ sử dụng module `Search()` đã viết ở trên.
2. Sau khi tìm được con trỏ của phần tử chứa nội dung $13$ ta sẽ tạo một `node` mới và thêm vào sau phần tử có nội dung là $13$ và trước phần tử có nội dung là $15$.

Module `InsertAfter()` sẽ giúp ta thực hiện công việc ở bước 2 với giả định ta luôn tìm được kết quả ở bước 1.

`LinkedList.h`

```cpp
namespace LinkedList {
    void InsertAfter(Pointer& First, Pointer& p, int value);
}
```

`LinkedList.cpp`

```cpp
void LinkedList::InsertAfter(LinkedList::Pointer &First, LinkedList::Pointer& p, int value) {
    if (p == nullptr || LinkedList::IsEmpty(First)) {
        LinkedList::InsertFirst(First, value);
        return;
    }

    LinkedList::Pointer q = p->next;
    LinkedList::Pointer newNode = new LinkedList::Node(value, q);
    p->next = newNode;
}
```

**Giải thích Code:**

- Thủ tục sẽ nhận ba tham số đầu vào, lần lượt là:

    1. Tham số hình thức biến `First` là phần tử đầu tiên đại diện cho danh sách.
    2. Tham số hình thức biến `p` là con trỏ trỏ đến phần tử mà phần tử mới sẽ được thêm vào.
    3. Tham biến `value` là nội dung của `node` mới sẽ được thêm vào.

- Ta sẽ thấy có một vài trường hợp như con trỏ `p` bằng `nullptr` hoặc danh sách rỗng thì ta sẽ quay lại trường hợp thêm phần tử vào đầu danh sách.
- Khi con trỏ `p` khác `nullptr` thì ta sẽ thực hiện thêm phần tử mới vào danh sách sau `p` như sau:

    1. Gọi `q` là con trỏ của phần tử tiếp theo đứng ngay sau `p` trong danh sách.
    2. Dùng từ khóa `new` để tạo ra con trỏ `newNode` trỏ đến phần tử mới sẽ được thêm vào danh sách. `newNodw` sẽ có `info` bằng với `value` và `next` sẽ trỏ đến `q`.
    3. Ta sẽ xóa bỏ liên kết từ `p` đến `q` và thay bằng liên kết từ `p` đến `newNode` bằng câu lệnh `p->next = newNode`.

**Hình vẽ minh họa quá trình thêm một phần tử vào sau phần tử `p`:**

```mermaid
flowchart TD
    subgraph one [Original]
        direction LR
        A0[10] ==> B0[11] ==> C0[12] ==> D0[13] ==> F0[15] ==> G0[16] ==> Z0[NULL]
    end

    subgraph two [Step 1 and 2]
        direction LR
        A[10] ==> B[11] ==> C[12] ==> D[13] ==> F[15] ==> G[16] ==> Z[NULL]

        E[14]

        E -- Step 1 --> F

        D -- Step 2 --> E
    end

    subgraph three [Step 3]
        direction LR
            1A[10] ==> 1B[11] ==> 1C[12] ==> 1D[13] x-. Step 3 .-x 1F[15] ==> 1G[16] ==> 1Z[NULL]

            1E[14]

            1E -- Step 1 --> 1F

            1D -- Step 2 --> 1E
    end

    subgraph final [Final list]
        direction LR
            2A[10] ==> 2B[11] ==> 2C[12] ==> 2D[13] ==> 2E[14] ==> 2F[15] ==> 2G[16] ==> 2Z[NULL]
    end

    one --> two --> three --> final
```

### DeleteFirst - Module xóa phần tử đứng đầu danh sách

Trong quá trình làm việc với danh sách thì thao tác loại bỏ phần tử (hay còn gọi là xóa) là một thao tác thường gặp. Ở đây mình cùng nói đến thao tác xóa đơn giản nhất là xóa phần tử đầu tiên của danh sách.

`LinkedList.h`

```cpp
namespace LinkedList {
    bool DeleteFirst(Pointer& First);
}
```

`LinkedList.cpp`

```cpp
bool LinkedList::DeleteFirst(LinkedList::Pointer& First) {
    if (LinkedList::IsEmpty(First)) {
        return 0;
    }

    LinkedList::Pointer p = First;
    First = p->next;
    delete p;
    return 1;
}
```

**Giải thích Code:**

Module sẽ trả về `true` hoặc `false` tương ứng với việc module đã xóa thành công hoặc không.

Trước hết, ta sẽ kiểm tra, nếu danh sách rỗng, thì ta sẽ không cần xóa phần tử nào, nghĩa là ta đã không xóa thành công, nên trả về `false`.

- Module nhận vào một tham số hình thức biến `First` là phần tử đại diện cho dãy cũng là phần tử đầu tiên của dãy. Vì danh sách sẽ bị biến đổi, cụ thể là phần tử đầu tiên của danh sách, cũng chính là `First`.
- Đầu tiên, ta tạo một con trỏ `p` chứa phần tử đầu tiên của danh sách, nghĩa là chứa `First`.
- Khi xóa phần tử đầu tiên trong danh sách, thì phần tử kế tiếp đứng sau nó sẽ trở thành phần tử đầu danh sách mới. Do đó, ta cần cập nhật lại `First` để `First` trỏ đến phần tử đầu tiên mới.
- Cuối cùng, ta dùng `delete` để xóa con trỏ `p`, lúc này đang chứa địa chỉ của phần tử cần xóa. Lúc này, ta đã hoàn toàn xóa đi phần tử đầu tiên khỏi danh sách và `First` cũng đã lưu trữ được phần tử đầu tiên mới của danh sách rồi trả về `true` để đánh dấu xóa thành công.

Ở một số trường hợp, mình sẽ có thể thay đổi giá trị trả về từ `true/false` thành `int` với ý nghĩa là số lượng phần tử đã xóa khỏi danh sách, bạn có thể lưu ý điểm này để ứng dụng vào bài tập.

### DeleteAfter - Module xóa phần tử đứng sau phần tử `p`

Trong khi xử lí dữ liệu, ta có thể gặp một số thao tác cần xóa một phần tử đứng sau một phần tử khác, đối với danh sách tuyến tính, ta sẽ thực hiện như sau.

`LinkedList.h`

```cpp
namespace LinkedList {
    int DeleteAfter(Pointer target);
}
```

`LinkedList.cpp`

```cpp
int LinkedList::DeleteAfter(Pointer target) {
    if (target == nullptr || target->next == nullptr) {
        return 0;
    }

    LinkedList::Pointer deleteNode = target->next;
    target->next = deleteNode->next;
    delete deleteNode;
    return 1;
}
```

**Giải thích Code:**

Module trả về giá trị kiểu `int` với ý nghĩa là số lượng phần tử đã loại bỏ khỏi danh sách.

- Module nhận vào một tham biến là con trỏ mà phần tử đứng sau nó sẽ bị xóa.
- Trước tiên, cần loại bỏ ra những trường hợp không thể thực hiện quá trình xóa như danh sách rỗng, hoặc danh sách chỉ có một phần tử. Khi đó, ta không xóa phần tử nào, trả về `false`.
- Tiếp theo, ta lưu con trỏ của phần tử cần xóa là `deleteNode` là phần tử đứng sau phần tử hiện tại lại.
- Sau đó, vì để tránh mất mát dữ liệu khi xóa phần tử, thì ta sẽ tạo liên kết từ phần tử hiện tại đến những phần tử đứng sau phần tử cần xóa.
- Cuối cùng, ta dùng từ khóa `delete` để xóa `deleteNode` và trả về $1$ vì chỉ xóa duy nhất một phần tử.

### DeleteLast - Module xóa phần tử ở cuối danh sách

Vị trí cuối cùng có thể xóa nếu cần là vị trí cuối danh sách. Khác với danh sách tuyến tính, việc xóa phần tử cuối cùng trong danh sách liên kết sẽ cần phải thực hiện như sau.

`LinkedList.h`

```cpp
namespace LinkedList {
    bool DeleteLast(Pointer& First);
}
```

`LinkedList.cpp`

```cpp
bool LinkedList::DeleteLast(LinkedList::Pointer &First) {
    if (LinkedList::IsEmpty(First)) {
        return false;
    }

    if (First->next == nullptr) {
        delete First;
        First = nullptr;
        return true;
    }

    LinkedList::Pointer Last = First;
    for (; Last->next->next != nullptr; Last = Last->next);
    delete Last->next;
    Last->next = nullptr;
    return true;
}
```

**Giải thích Code:**

Module nhận vào một tham số hình thức biến `First` có ý nghĩa là phần tử đầu tiên của danh sách, quản lí cả danh sách.

Trước hết, ta cần xử lí một số trường hợp đặc biệt sau:

1. Nếu danh sách rỗng thì ta sẽ không xóa được, lúc này ta trả về `false` vì không xóa được phần tử nào.
2. Nếu danh sách chỉ có 1 phần tử, ta sẽ xóa `First` rồi gán `nullptr` cho `First` để đánh dấu là danh sách rỗng. Rồi trả về `true` vì đã xóa đi phần tử cuối cùng.

Sau khi bỏ đi các trường hợp đặc biệt, ta chắc chắn danh sách sẽ có tối thiểu $2$ phần tử trở lên, khi đó, ta sẽ thực hiện như sau:

- Đầu tiên, ta gọi một con trỏ `Last` là phần tử cuối cùng của danh sách, khởi tạo tại phần tử `First`.
- Sau đó, ta sẽ duyệt từ đầu đến phần tử kế cuối của danh sách, lúc này, ta sẽ có `Last` là phần tử kế cuối của danh sách, và `Last->next` là phần tử cuối của danh sách.
- Lúc này ta sử dụng `delete` để xóa `Last->next` và gán `nullptr` cho `Last->next` vì lúc này nó trở thành phần tử cuối của danh sách.

### DeleteInfo - Module xóa phần tử có nội dung `info`

Trong những bài toán làm việc với dữ liệu thì việc xóa phần tử có nội dung theo yêu cầu là một bài toán thường gặp, với danh sách liên kết ta sẽ giải quyết bài toán đó như sau:

`LinkedList.h`

```cpp
namespace LinkedList {
    int DeleteInfo(Pointer& First, int info);
}
```

`LinkedList.cpp`

```cpp
int LinkedList::DeleteInfo(LinkedList::Pointer &First, int info) {
    if (LinkedList::IsEmpty(First)) {
        return 0;
    }

    if (First->info == info) {
        LinkedList::DeleteFirst(First);
        return 1;
    }

    LinkedList::Pointer p = First;
    for (; p->next != nullptr && p->next->info != info; p = p->next);

    if (p->next == nullptr) {
        return 0;
    }

    LinkedList::DeleteAfter(p);

    return 1;
}
```

**Giải thích Code:**

Module sẽ xóa phần tử đầu tiên có nội dung `info` theo yêu cầu và trả về `true/false` tương ứng với việc xóa thành công hoặc không.

Module nhận hai tham số, trong đó, tham số đầu tiên là tham số hình thức biến `First` đại diện cho danh sách, tham số thứ hai là `info` là nội dung của phần tử cần xóa.

Trước tiên, như mọi khi, ta cần xử lí trước một số các trường hợp đặc biệt như sau:

1. Nếu danh sách rỗng thì ta sẽ không xóa phần tử nào và trả về `false`.
2. Nếu phần tử đầu tiên là phần tử cần tìm, ta sẽ thực hiện thuật toán `DeleteFirst()` đã nói ở trên.

Sau khi giải quyết các trường hợp đặc biệt, ta sẽ thực hiện xóa phần tử như sau:

- Gọi `p` là con trỏ trỏ đến phần tử đứng trước phần tử cần xóa. Ta khởi tạo `p = First`.
- Ta dùng vòng lặp `for` (hoặc `while`) và duyệt đến khi gặp phần tử cuối cùng hoặc `p->next` (là phần tử kế tiếp của `p` đang xét hiện tại) có nội dung là `info`. Lúc này, xảy ra một trong hai trường hợp sau:

    1. Nếu `p->next->info` bằng với `info`, có nghĩa là ta đang xét nội dung của phần tử đứng sau `p` có phải là phần tử ta đang tìm kiếm hay không? Nếu phải, thì vòng lặp ta dừng lại và sử dụng thuật toán `DeleteAfter()` để xóa đi phần tử đứng sau `p`, là phần tử `p->next`, cũng chính là phần tử cần xóa.
    2. Nếu `p->next` bằng với `nullptr` thì `p` chính là phần tử cuối cùng, lúc này, vì cách ta kiểm tra phần tử liền sau có phải là phần tử cần tìm hay không nên ta khẳng định ta không tìm được phần tử cần xóa và trả về `false`.

***Chứng minh vì sao trường hợp $2$ không cần xét điều kiện `p->info == info`:***

Để chứng mình điều này, mình sẽ áp dụng phương pháp phản chứng như sau:

- Mình giả thuyết, vòng lặp dừng ở điều kiện `p->next == nullptr` là phần tử cuối cùng của danh sách và ta cần kiểm tra điều kiện `p->info == info`, nghĩa là phần tử cuối cùng của danh sách cũng là phần tử cần tìm.
- Gọi `u` là phần tử liền trước `p`, nghĩa là `u->next == p`. Theo giả thuyết của mình ở trên, ta sẽ có: `u->next->info == info`, vì giả thuyết ta có `p->info == info`.
- Vì `u` đứng trước `p`, nên ta sẽ duyệt qua `u` trước, rồi mới duyệt đến `p`. Lúc này, trong lúc duyệt, ta thấy `u->next->info == info`, điều kiện này vi phạm vào điều kiện lặp của vòng lặp, nghĩa là vòng lặp sẽ phải kết thúc khi xét đến `u`. Điều này có nghĩa rằng, ta sẽ không duyệt đến `p`, và dĩ nhiên, `p` sẽ khác `nullptr`, và ta sẽ thực hiện thuật toán `DeleteAfter()` đối với `Last = u`.
- Điều này cũng có nghĩa, giả thuyết của mình đặt ra sẽ sai và theo phương pháp phản chứng, thì ta không cần xét điều kiện `p->info == info`.

---

Trên đây là những thuật toán cơ bản thường gặp khi làm việc với cấu trúc dữ liệu `Linked list`. Đây là handbook của mình dựa trên quá trình học môn Cấu trúc dữ liệu và Giải thuật ở Học viện Cơ sở do thầy Lưu Nguyễn Kì Thư giảng dạy. 

**Lưu ý:** đây không phải tài liệu giáo khoa mà là tài liệu tham khảo do mình biên soạn và tóm tắt lại.
