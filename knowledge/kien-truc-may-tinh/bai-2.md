
# Bài 2 - General purpose computer & Stored program | Kiến trúc máy tính

---

## Sự xuất hiện stored-program và general-purpose hardware

- Một tập nhỏ các linh kiện logic cơ bản có thể kết hợp với nhau theo các cách khác nhau để lưu trữ dữ liệu nhị phân và thực hiện các phép toán số học và luận lý trên dữ liệu đó.
- Khi cần một tính toán nào đó, một cấu hình kết nối các thành phần logic được thiết kế và thực hiện. *Có thể hiểu đó chính là dạng lập trình.*

- Nếu tất cả các ứng dụng đều thực hiện bằng hardwired program -> bất tiện và khả năng của máy tính rất hạn chế.
- Xây dựng các chức năng số học và luận lý tổng quát (general-purpose hardware).
- Hoạt động dựa vào tín hiệu điều khiển.

---

## Phát sinh tín hiệu điều khiển

- Toàn bộ chương trình là một tuần tự gồm nhiều bước.
- Mỗi bước cần tiến hành một vài phép số học và luận lý trên data nào đó.
- Mỗi bước cần một tập tín hiệu tương ứng.
Một code duy nhất cho một tập tín hiệu có thể.
- Một segment tương ứng trong phần cứng tổng quát chấp nhận một tập tín hiệu điều khiển được phát ra.

- Lập trình bây giờ: thay vì nối dây phần cứng cho mỗi chương trình mới, chỉ cần cung cấp một tuần tự mới của các code.
- Mỗi code thực ra là một instruction, được phần biên dịch tiếp nhận và phát ra tập tín hiệu điều khiển tương tự.
- Tuần tự các instruction đó là software.

---

## Ba khái niệm cơ bản về stored program

- Data và instruction được lưu trữ trong một bộ nhớ đọc - ghi.
- Nội dung trong bộ nhớ được định vị theo vị trí, không cần biết kiểu data là gì.
- Thực thi chương trình theo kiểu tuần tự, từ instruction này đến instruction kế tiếp.

Bài tập bài 3: xem lại Von nunnumann

---

## References

- [Computer organization & architecture - design for performance, William Stalling, 10th edition, Prentice-Hall International, Inc]
- [Principle of computer architecture, Miles Murdocca & Vincent Heuring]
- [Slide bài giảng (onedrive)]
