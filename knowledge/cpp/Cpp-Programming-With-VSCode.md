# LẬP TRÌNH C++ VỚI VISUAL STUDIO CODE

---

## Mục lục

- [Cài đặt Visual Studio Code](#cài-đặt-visual-studio-code)
- [Cài đặt vài tiện ích mở rộng](#cài-đặt-vài-tiện-ích-mở-rộng)
- [Cài đặt bộ dịch ngôn ngữ C/C++](#cài-đặt-bộ-dịch-ngôn-ngữ-cc)
- [Viết chương trình C++ đầu tiên](#viết-chương-trình-c-đầu-tiên)
- [Tổng kết](#tổng-kết)

---

## Cài đặt Visual Studio Code

Bạn có thể ghé thăm trang chủ của VS Code ở [đây](https://code.visualstudio.com/) và chọn mục [Download](https://code.visualstudio.com/Download) để chọn phiên bản phù hợp với hệ điều hành đang dùng và tải xuống.

---

## Cài đặt vài tiện ích mở rộng

VS Code là một text editor (trình soạn thảo) có một cộng đồng hỗ trợ rất lớn ở trên khắp thế giới. Nhưng vì không phải là một IDE hoàn chỉnh cho ngôn ngữ lập trình C++ như CodeBlocks hay Visual Studio nên ta cần phải cài thêm một số tiện ích để việc viết Code được nhanh và tiện hơn.

Đầu tiên bạn mở VS Code lên và vào mục Extensions. Trong hộp tìm kiếm, tìm từ khóa `C++` và bạn sẽ thấy rất nhiều những Extension (tiện ích mở rộng) được sắp xếp theo mức độ phổ biến trên toàn thế giới.

***C/C++ by Microsoft***

> *Trang chủ của tiện ích: [C/C++ by Microsoft](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools).*

Đây là một tiện ích giúp bạn kiểm tra lỗi cú pháp, làm nổi bật cú pháp và đưa những thông tin về các hàm hoặc các từ khóa có sẵn liên quan đến ngôn ngữ C++.

***Indent Rainbow***

> *Trang chủ của tiện ích: [indent-rainbow](https://marketplace.visualstudio.com/items?itemName=oderwat.indent-rainbow).*

Không hỗ trợ trực tiếp hay khiến bạn code giỏi hơn nhưng tiện ích này sẽ thêm màu vào những phần thụt lề của bạn, khiến cho phần nhìn của bạn trong lúc học tập và làm việc sẽ bớt đi phần nhàm chán.

***Material Icon và Material Theme***

> *Trang chủ của tiện ích: [Material icon](https://marketplace.visualstudio.com/items?itemName=PKief.material-icon-theme) và [Material Theme](https://marketplace.visualstudio.com/items?itemName=Equinusocio.vsc-material-theme).*

Tùy theo sở thích thì bạn có thể trang trí VS Code theo ý bạn. Mình đưa ra hai gợi ý này vì với mình dù đã thử qua một vài theme và icon khác nhau nhưng vẫn quay về với phong cách thiết kế Material này. Thử xem, biết đâu lại nghiện thì sao?

***Better Comments và TODO Highlight***

> *Trang chủ của tiện ích: [Better Comments](https://marketplace.visualstudio.com/items?itemName=aaron-bond.better-comments) và [TODO Highlight](https://marketplace.visualstudio.com/items?itemName=wayou.vscode-todo-highlight).*

Lại là một sự gợi ý nữa từ mình. Với mình đây là combo tiện ích giúp mình làm việc mạch lạc và dễ dàng hơn rất nhiều. Mình có thể lên kế hoạch và quản lí các bài tập và dự án rất tốt với Better Comments và được nhắc nhở bởi TODO Highlight. Nếu bạn đang muốn tìm một cách nào đó để quản lí các bài tập và dự án tốt hơn thì đây là hai sự lựa chọn không tồi để bắt đầu.

---

## Cài đặt bộ dịch ngôn ngữ C/C++

Dừng một lát để giải thích cho những bạn đọc chưa phân biệt được các khái niệm IDE, Text editor và Compiler là gì.

- **Text editor**: là một trình soạn thảo. Có lẽ bạn có thể nghe qua "trình soạn thảo văn bản" ở trước đây rồi, thì text editor cũng tương tự như vậy. Nhưng bạn sẽ không chỉ soạn thảo các văn bản Word mà bạn sẽ viết code. Sử dụng ngôn ngữ lập trình để giao tiếp với máy tính, sáng tạo và tạo ra những ứng dụng thay đổi thế giới.

- **Compiler**: trình biên dịch. Đây là một công cụ không thể thiếu khi lập trình. Như đã nói ở trên, lập trình viên sẽ sử dụng ngôn ngữ lập trình để giao tiếp với máy tính. Song máy tính không thể hiếu được những gì cũng ta gõ mà cần phải có một ứng dụng thứ ba, biến những gì ta viết ở trong code thành mã máy từ đó máy tính mới có thể hiểu được và thực thi những gì chúng ta muốn.

- **IDE - Integrated development environment**: là một môi trường làm việc được tích hợp sẵn hai thành phần kể trên vào một ứng dụng hoàn chỉnh và tối ưu thêm nhiều chức năng khác. Đó là một IDE. Đối với ngôn ngữ lập trình C/C++ thì một vài IDE nổi tiếng như Visual Studio, DevC và CodeBlocks. Cá nhân mình đã ít nhiều dùng qua cả ba thì mình thích CodeBlocks nhất chính vì sự cân bằng giữa sự nhẹ nhàng và thông minh của IDE này.

Vậy là bạn đọc đã nắm được sơ sơ về ba khái niệm rất quan trọng này. Mình tiếp tục setup cho VS Code nào.

Ở bước này mình sẽ cài đặt một Compiler cho máy tính để máy tính có thể dịch được code của chúng ta. Mình chọn MinGW để cài ở Windows. Lí do thì hong gì đặc biệt cả mình chỉ sử dụng trình biên dịch này từ lâu rồi và không có vấn đề gì phát sinh.

Bạn có thể tải MinGW ở [đây](https://sourceforge.net/projects/mingw/) hoặc tải compiler mà bạn thích.

***Đặt MinGW vào môi trường PATH***

Đây là một phần cài đặt mình nghĩ là nên làm đối với những bạn sử dụng Windows vì ở các hệ điều hành UNIX thì compiler của C++ đã đi kèm khi cài đặt hệ điều hành, bạn chỉ cần tra cứu cách nâng cấp compiler thôi.

- Bước 1: Mở Settings và tìm kiếm từ khóa `Edit environment variables`.
- Bước 2: Sau khi bảng chọn Environment Variables hiện lên, bạn hình theo cột Variables của người dùng của bạn và chọn dòng `PATH` rồi chọn `Edit`.
- Bước 3: Một bảng chọn mới sẽ hiện lên, bạn chọn `New` rồi `Browse` sau đó trỏ đến thư mục `MinGW/bin` ở trong máy tính của bạn. Thông thường thì sẽ ở địa chỉ: `C:\MinGW\bin`. Rồi bạn lưu tùy chọn này lại.

Sau khi cài đặt xong, bạn có thể mở PowerShell/CommandLine hay Terminal lên và thử lệnh:

```bash
$ c++ --version
```

Hoặc

```bash
$ g++ --version
```

Nếu hiện ra thông báo về phiên bản thì bạn đã cài đặt bộ dịch thành công. Ngược lại bạn hãy thử kiểm tra lại quá trình cài đặt xem sao. Đối với Windows thì nếu bạn thử và hệ thống vẫn chưa nhận diện được compiler thì bạn có thể restart lại máy tính và thử dùng lệnh để kiểm tra lại thử xem.

---

## Viết chương trình C++ đầu tiên

***Viết code:***

Ở bước này mình sẽ khuyên bạn tạo cho bản thân một thư mục chứa code riêng cho mình. Với thư mục này bạn sẽ lưu các bài tập hay dự án của bạn. Nếu bạn đã đi làm hoặc có nhiều dự án thì sẽ chia theo nhiều thư mục khác nhau tùy theo mục đích của bạn.

Cá nhân mình đã gặp rất nhiều bạn có vấn đề với việc lưu trữ và tìm kiếm code của chính họ nên mình nghĩ đối với người mới bắt đầu, hãy tạo cho mình một thư mục cố định ở một nơi bạn dễ tìm và khó xóa đi để tránh mất code như `\desktop` hoặc ở ổ `D:\`. Sau đó vào VS Code, chọn `File` $\to$ `Open Folder` rồi trỏ đến thư mục bạn vừa tạo. VS Code sẽ hiện lên cây thư mục mà bạn vừa trỏ, từ bây giờ bạn có thể lưu trữ code của mình ở trong đây mà không phải suy nghĩ tìm nó ở một thư mục nào khác.

Bây giờ mình sẽ viết một chương trình C++ đầu tiên, Hello World, dĩ nhiên rồi.

```c++
#include <iostream>

using namespace std;

int main() {
    cout << "Hello World\n";
    return 0;
}
```

Nếu bạn đã biết và muốn sử dụng một code khác thì bạn có thể thay đổi theo ý thích của bạn. Không thì bạn có thể sử dụng đoạn code này của mình.

Tên file mình lưu là `helloworld.cpp`. Đuôi `*.cpp` sẽ giúp máy tính hiểu đây là một file văn bản sử dụng ngôn ngữ lập trình C++ hoặc mã nguồn C++.

***Dịch và chạy chương trình:***

Ở trên thanh công cụ, bạn chọn `Terminal` $\to$ `Run Build Task...`. Một bảng chọn nhỏ sẽ hiện ra như hình dưới đây:

![Build selections](https://code.visualstudio.com/assets/docs/languages/cpp/gpp-build-task-msys64.png)

Dựa vào kinh nghiệm của mình thì mình sẽ khuyên bạn chọn một trong hai cái cuối. Mình chưa tìm hiểu quá nhiều về sự khác biệt giữa `g++` và `cpp`, nếu có thời gian mình sẽ tìm hiểu và chia sẽ cho bạn đọc.

Trong trường hợp này mình sẽ chọn cái cuối. Nhấn `ENTER` bạn sẽ thấy màn hình Terminal bên dưới hiện lên chạy vài dòng và thông báo: **`Build finished successfully.`** và bên trái ở cây thư mục bạn sẽ thấy file `tên file bạn lưu code + đuôi .exe` với mình thì sẽ là file `helloworld.exe`. Vậy là bạn đã dịch code thành công. Nếu chương trình có lỗi cú pháp thì chương trình sẽ thông báo cho bạn biết.

Tiếp theo bạn sẽ dùng file `*.exe` vừa xuất hiện để chạy chương trình. Bạn có thể dùng Terminal của hệ điều hành, với mình thì mình sẽ dùng cái nào miễn là tiện. Do vậy mình sẽ sử dụng Terminal tích hợp của VS Code. Bạn cần trỏ đến thư mục chứa file `*.exe` vừa tạo và dùng lệnh `.\*` (thay dấu `*` bằng tên file phù hợp) và nhấn Enter.

Ví dụ với mình thí sẽ là lệnh:

```bash
$ .\helloworld
```

Hoặc

```bash
$ .\helloworld.exe
```

Nếu bạn gặp lỗi thì hãy kiểm tra lại địa chỉ thư mục đang trỏ đến và tên của đường dẫn. Tên của file hay thư mục nên được ngăn cách nhau bởi dấu gạch dưới hoặc viết hoa các chữ cái đầu của từng từ để phân biệt.

Bạn nên thu được kết quả gần giống vầy:

![Description image](https://code.visualstudio.com/assets/docs/languages/cpp/run-hello-world.png)

---

## Tổng kết

Mình và bạn vừa cài đặt VS Code và đi qua quá trình biên dịch và thực thi code sử dụng ngôn ngữ C++. Mình hi vọng bạn đã có những kiến thức và thông tin cần thiết qua bài viết này.

Đây là bài viết mình dịch và viết dựa trên nguồn ở đây: [C/C++ for Visual Studio Code](https://code.visualstudio.com/docs/languages/cpp).