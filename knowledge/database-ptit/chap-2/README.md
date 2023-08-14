
# Mô Hình Thực Thể Kết Hợp ER (Entity Relationship)

---

## Quy Trình Thiết Kế CSDL

- Thu thập và phân tích yêu cầu
- Thiết kế mức quan niệm
- Ánh xạ thiết kế logic/mô hình dữ liệu
- Thiết kế mức vật lý

## Mô Hình Thực Thể Kết Hợp ER

- Dùng để thiết kế CSDL ở mức quan niệm
- Độc lập với tất cả các xem xét về vật lý: DBMS, OS.
- Lược đồ CSDL trong mô hình ER có thể được thực hiện dưới dạng giản đồ ER.

## Vấn Đề Khi Thiết Kế Database

- Các thực thể nào và mối quan hệ nào cần quan tâm?
- Thông tin nào về thực thể và mối quan hệ giữa các thực thể cần lưu trữ trong CSDL?
- Các ràng buộc nào cần được đảm bảo với thực thể và các mối kết hợp?

## Các Khái Niệm

- Thực thể (Entity): "thing" or object.
- Tập thực thể (Entity Set): collection of similar entities (similar to class in OOP).
- Thuộc tính (Attribute): property of entity.
    1. Generally all entities in a set have the same properties.
    2. Attributes are simple values, e.g. Integers or character strings.

## Các Loại Thuộc Tính

- Đơn trị (simple): chỉ duy nhất 1 giá trị.
- Đa trị (multi value): có thể chứa nhiều giá trị
    > Không khuyến khích sử dụng thuộc tính đa trị vì gây khó khăn trong việc xử lí truy vấn. Tùy thuộc vào yêu cầu mà hạn chế sử dụng.
- Dẫn xuất (derived): tính được từ các thuộc tính khác trong quan hệ: ví dụ như tính trị giá.
    > Tùy vào cách dẫn xuất mà quyết định có lưu vào db hay không? Nếu dấn xuất đơn giản, ví du như một phép tính nhân hai trường thì không lưu. Ngược lại, nếu dẫn xuất phức tạp như tính toán cần nhiều dữ liệu hoặc tốn thời gian, có thể cần tính lại nhiều lần thì nên lưu vào db để hạn chế tính toán lặp lại nhiều lần.
- Giá trị NULL của thuộc tính 

## Giá Trị Của Tập Thuộc Tính

- "Miền giá trị" của thuộc tính.
- Tập giá trị có thể được gán cho thuộc tính đó đối với mỗi loại thực thể riêng.
- Không được thể hiện trên giản đồ ER.
