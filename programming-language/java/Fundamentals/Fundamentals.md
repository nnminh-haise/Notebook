
# Kiến thức nền tảng

---

## Chương trình Java đơn giản

Dưới đây là chương trình Java đơn giản in ra một lời chào ra màn hình.

```java
public class Main {
    public static void main(String[] args) {
        System.out.println("Hi, my name is Haise");
    }
}
```

### Những điểm cần lưu ý khi sử dụng Java

1. Java phân biệt giữa chữ hoa và chữ thường.
2. `public`: Từ khóa thay đổi quyền truy cập (*access modifier*) - từ khóa này sẽ quy định quyền truy cập của đối tượng. Bên cạnh từ khóa `public` còn có các từ khóa khác.
3. `class`: Lớp là đơn vị nhỏ nhất của một chương trình Java. Do đó, chương trình Java là tập hợp các lớp.
4. `Main`: tên của lớp hiện tại.
5. Tên của source code (file chứa code) phải giống tên của `public class`.
6. Một chương trình Java phải có phương thức `main` (`main method`).

### Ghi chú trong Java

> Ghi chú - Comments: là những dòng lệnh được trình biên dịch (compiler) bỏ qua khi biên dịch (compile) code. Tận dụng tính chất này, ta có thẻ viết các ghi chú cá nhân, hoặc giải thích code, giúp tăng hiệu quả học tập và làm việc.

```java
// inline comments - Ghi chú trên một dòng.

/*
Multiplelines comments - Ghi chú trên nhiều dòng hay còn gọi là comment block (khối ghi chú).
*/

/*
* Generate documents - Tài liệu ghi chú.
*/
```

---

## Kiểu dữ liệu

Java cung cấp $8$ kiểu dữ liệu nguyên thủy khác nhau như sau:

| Kiểu dữ liệu | Kích thước | Miền giả trị                                                                           |
| :----------: | :--------: | :------------------------------------------------------------------------------------- |
|    `int`     |  4 bytes   | $-2, 147, 483, 648$ đến $2, 147, 483, 647$                                             |
|   `short`    |  2 bytes   | $-32, 768$ đến $32, 767$                                                               |
|    `long`    |  8 bytes   | $-9, 223, 372, 036, 854, 775, 808$ đến $9, 223, 372, 036, 854, 775, 807$               |
|    `byte`    |  1 bytes   | $-128$ đến $127$                                                                       |
|   `float`    |  4 bytes   | Gần bằng $\pm 3.40282347\text{E} + 38\text{F}$ (6 - 7 chữ số sau dấu phẩy thập phân)   |
|   `double`   |  8 bytes   | Gần bằng $\pm 1.7976931348623157\text{E} + 308$ (15 chữ số sau dấu phẩy thập phân)     |
|    `char`    |  4 bytes   | Biểu diễn các kí tự có giá trị thập lục phân từ `\u0000` đến `\uFFFF` (Bảng mã UTF-16) |
|    `bool`    |   1 bit    | `true` hoặc `false`                                                                    |


Bên cạnh $8$ kiểu dữ liệu trên, Java còn có $3$ giá trị dấu phẩy động đặc biệt:

- Giá trị âm vô cùng.
- Giá trị dương vô cùng.
- `NaN` - Not a number - Giá trị không phải số.

$3$ giá trị này được dùng để xác dịnh các trường hợp tràn số hoặc lỗi toán học.

Ví dụ: kết quả của phép chia một số dương cho $0$ sẽ là âm vô cùng. Hay khi tính toán kết quả của phép chia $0 \div 0$ hay $\sqrt(-1)$ sẽ cho ra kết quả là `NaN`.

### Bảng kí tự đặc biệt

| Kí tự thoát | Tên gọi        | Giá trị Unicode |
| :---------: | :------------- | :-------------: |
|    `\b`     | Backspace      |    `\u0008`     |
|    `\t`     | Tab            |    `\u0009`     |
|    `\n`     | Linefeed       |    `\u000a`     |
|    `\r`     | Cariage return |    `\u000d`     |
|    `\"`     | Double quote   |    `\u0022`     |
|    `\'`     | Single quote   |    `\u0027`     |
|    `\\`     | Backslash      |    `\u005c`     |


**Lưu ý:** 

- Ký tự thoát của bảng mã Unicode sẽ được dịch trước! 

    Cụ thể, ta xét chuỗi `"\u0022 + \u0022"`, biết kí tự `\u0022` là kí tự `"`. Ta sẽ không thu được kết quả là `"+"` mà thay vào đó sẽ là một chuỗi rỗng. Vì kí tự `\u0022` sẽ được chuyển thành `"` trước, sau đó chương trình sẽ hiểu `"\u0022` là `""`. Khi đó chương trình sẽ hiểu chuối ban đầu của ta như sau: `"" + ""` thì ta sẽ thu được kết quả là một chuỗi rỗng.

- Khi sử dụng kí tự `\u` trong ghi chú cần phải cẩn thận!

    Ví dụ ta có ghi chú: `// \u000A is a newline`, thì khi chạy chương trình với ghi chú này, ta sẽ gặp lỗi biên dịch. Khi biên dịch, chương trình sẽ thay thế kí tự `\u000A` bằng một dòng mới. Do đó, chuỗi ` is a newline` sẽ xuống dòng và gây lỗi.

    Tương tự với ghi chú `c:\users` cũng sẽ gây ra lỗi!

---

## Biến
