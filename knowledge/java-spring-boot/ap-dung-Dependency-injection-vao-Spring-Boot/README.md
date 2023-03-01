
# Áp dụng Dependency injection vào Spring Boot

---

## Module Coupling

### Khái niệm Module coupling

- Coupling là mối quan hệ giữa hai module có sự phụ thuộc vào nhau, có liên quan đến nhau.
- Gồm hai loại coupling:
    - Tight coupling: hai module có quan hệ chặt chẽ, liên kết chặt chẽ với nhau.
    - Loose coupling: hai module liên kết rời rạc nhau.

![](./img/module-coupling.png)

- Trong chương trình sẽ có nhiều module riêng lẻ, mỗi module lại có quan hệ với nhau (tương tác hoặc kế thừa).

***Ví dụ:***

```java
public static class Point() {
    int x, y;
}

public static class Segment() {
    private Point A;
    private Point B;
}
```

### Nguyên tắc về sự phụ thuộc

> *Để code dễ bảo trì và sửa đổi thì nguyên tắc là giảm sự phụ thuộc giữa các module.*
> *Nghĩa là biến đổi từ quan hệ tight coupling thành loose coupling.*

Trong ví dụ trên:
- Nếu sửa đổi class `Point` thì cần sửa dối class `Segment`.
- Khó test module.
- Khó bảo trì module.

---

## Nguyên lý Dependency inversion

### Dependency inversion principle

> *Đây là nguyên lý số 5 trong SOLID principle, tượng trưng cho chữ D, giúp thiết kế các module sao cho hạn chế sự phụ thuộc nhất có thể.*

***Dependency inversion principle có hai ý chính:***

- Các module cấp cao không nên phụ thuộc (trực tiếp) vào các module cấp thấp. Cả hai nên phụ thuộc vào abstraction (OOP).
- Abstraction không nên phụ thuộc vào chi tiết mà ngược lại.

### Dependency là gì?

Trong ví dụ trên, class `Segment` phụ thuộc vào class `Point` nên claas `Point` là một dependency (phụ thuộc) của `Segment` $\Rightarrow$ Lúc này, class `Segment` là một module **cấp cao** còn `Point` là một module **cấp thấp**.

### Ý nghĩa thứ nhất của Dependency Inversion Principle

Đoạn code trên đã vi phạm ý 1 của DI Principle. Vì class `Segment` phụ thuộc trực tiếp vào class `Point`.

Để đúng với DI Principle thì ta cho hai module cùng phụ thuộc vào abstraction (Trong OOP thường là Interface).

```java
// Interface đại diện cho tọa độ trong hệ tọa độ đa chiều.
interface Coordinate {
    ...
}

// Point là một điểm có tọa độ
class Point impelements Coordinate {
    ...
}

/*
* Segment là một đoạn thẳng có tọa độ (nói chung). Không cụ thể tọa độ nào.
* Loại điểm cụ thể sẽ được inject vào lúc tạo (không phải hard code).
* Do đó có thể tạo Segment với nhiều loại tọa độ khác nhau.
*/
class Segment {
    private Coordinate A;
    pricate Coordinate B;

    public Segment(Coordinate x, Coordinate y) {
        this.A = x;
        this.B = y;
    }
}
```

Đoạn code trên sử dụng tính đa hình của OOP để chuyển đổi giữa các loại `Point` mà không có lỗi gì xảy ra.

***Giải thích code:***

Sau khi sửa lại thì `Point` và `Segment` đều phụ thuộc vào Interface `Coordinate` (đại diện cho abstraction). Như thế đúng với nguyên lí DI đặt ra.

- `Point` là một loại `Coordinate` (có thể có tọa độ nhiều chiều). `Coordinate` có những method nào thì `Point` sẽ phải implement những method đó. Do vậy, khi đưa vào `Segment` thì chức năng của các loại `Coordinate` đều giống nhau và có trong các `Point` khác nhau.
- `Segment` sử dụng `Point` làm tọa độ thay vì một class cụ thể nào đó. Do đó chỉ cần `Point` thuộc interface `Coordiante` thì đều đưa được vào `Segment`.

Lúc này mỗi quan hệ giữa `Segment` và `Point` đã lỏng lẻo hơn rất nhiều. Khi đó, có thể có thêm một class `Point` khác như sau:

```java
class ThreeDimensionPoint implements Coordinate {
    ...
}
```

Khi tạo ra đối tượng `Segment` thì ta sẽ đưa đối tượng `Point` phù hợp vào:

```java
Coordinate PointTypeA = new Point();
Coordinate PointTypeB = new ThreeDimensionPoint();

Segment SegmentTypeA = new Segment(PointTypeA);
Segment SegmentTypeB = new Segment(PointTypeB);
```

Kỹ thuật này gọi là **Constructor-based Injection**.

### Ý nghĩa thứ hai của Dependency Inversion Principle

`Abstraction` không phụ thuộc vào chi tiết mà ngược lại. Nghĩa là `Abstraction` chỉ lấy những thuộc tính, hành động chung nhất mà không quan tâm đến chi tiết hoạt động như nào.

Ví dụ như trên, thì ta chỉ cần quan tâm đến những yếu tố chung nhất của `Coordinate` mà không quan tâm đến cách hoạt động hay chức năng của từng loại `Coordinate`.

---

## Inversion of Control - IoC

> IoC nhằm mục đích đơn giản hóa quá trình tạo đối tượng và liên kết giữa chúng, bằng cách tuân theo nguyên tắc: Không tạo đối tượng, chỉ mô tả cách chúng sẽ được tạo ra.
>
> *Do quá trình này phức tạp và khó implement, nên đã có nhiều framework ra đời hỗ trợ IoC, điển hình như Spring cho Java hoặc Angular của JavaScript.*

- IoC framework sẽ có các thành phần có sẵn làm nhiệm vụ tạo, quản lý các đối tượng trong chương trình.
- IoC sẽ quản lý, phân tích các mối phụ thuộc, tạo các đối tượng theo thứ tự phù hợp nhất và liên kết chúng lại với nhau, theo cách lập trình viên mô tả.

> *Inversion of control có nhiều kiểu để thực hiện, như dùng ServiceLocator, Delegate,… nhưng phổ biến nhất là Dependency injection.*

### Ví dụ

Không cần viết code như sau nữa:

```java
Coordinate PointTypeA = new Point();
Segment SegmentTypeA = new Segment(PointTypeA);
```

Thay vì viết code như trên, ta có thể đánh dấu (mark) trên các `class` và IoC sẽ giúp tạo các `object` tương ứng.

```java
@Component
class Point implements Coordinate {
    ...
}

@Component
class Segment {
    @Autowired // tìm object tương ứng và inject vào.
    private Coordinate A;

    @Autowired // tìm object tương ứng và inject vào.
    private Coordinate B;
}
```

Mỗi `class` được đánh dấu `@Component` (cái này gọi là Annotation trong Java) sẽ được IoC hiểu là một module:

- `@Component` sẽ bảo IoC container tạo một `object` duy nhất (singleton).
- `@Autowired` tìm module tương ứng (đã tạo trước đó) và inject vào.

> 💡 *Nhờ có IoC framework, việc tạo và liên kết các module dễ dàng hơn nhiều. Tuy nhiên, IoC chỉ nên áp dụng trên các module, object lớn, còn các object nhỏ nhỏ, linh tinh, dùng tạm thời thì không nên dùng.*

---

## Dependency Injection

### Dependency Injection là gì

> 💡 *Dependency Injection (viết tắt DI)*

DI là một dạng IoC, bằng cách inject module vào một module khác cần nó. Ví dụ: Module cấp cao `Segment` cần có module cấp thấp `Coordinate` thì DI sẽ thực hiện như sau:

- Tìm và tạo module tương ứng với `Coordinate` (class nào có implements `Coordinate` interface).
- Tạo module `Segment`, vì `Segment` phụ thuộc vào module `Coordinate` nên IoC tìm và lấy ra đối tượng `Coordinate` đã tạo trước đó và Inject vào module `Segment`.

> 💡 *Mọi module trong IoC đều gọi là dependency, mặc dù có những module không bị phụ thuộc bởi module nào khác. Khi chương trình chạy, IoC sẽ quét tất cả class đánh dấu dependency, tạo một đối tượng duy nhất (singleton), và bỏ vào cái túi gọi là IoC container, lúc nào cần thì lấy ra sử dụng. Do đó, các module đảm bảo được IoC tạo ra duy nhất một object, giúp tiết kiệm bộ nhớ và quản lý cũng dễ hơn.*
>
> 💡 *Nếu khi tạo module nào đó, mà module đó cần một module khác phụ thuộc, thì IoC sẽ tìm trong IoC container xem có không, nếu có thì inject vào, nếu chưa thì tạo mới, bỏ vào container và inject vào. Việc inject tự động các dependency (module) như thế được gọi là Dependency injection.*

### Các loại Injection

Có hai loại chính:

- `Constructor-based Injection`: Dùng để inject các module bắt buộc. Các module được inject nằm trong constructor, và được gán lần lượt vào các field.
- `Setter-based Injection`: Dùng để inject các module tùy chọn. Mỗi module sẽ được inject thông qua `setter`, nằm ở tham số và cũng gán cho field nào đó.

```java
@Component
class Segment {
    // Đoạn thẳng được tạo từ hai tọa độ, bắt buộc phải có.
    private Coordinate A;
    private Coordinate B;

    // Tên gọi cho đoạn thẳng (có thể có hoặc không).
    private String label;

    // Vì Coordinate A và B là bắt buộc nên phải dùng constructor-based injection
    // Constructor-based injection có thể inject nhiều dependency cùng lúc.
    public Segment(Coordinate A, Coordinate B) {
        this.A = A;
        this.B = B;
    }

    // Do label là tùy chọn nên dùng setter-based injection
    // Setter-based injection chỉ inject một dependency mỗi setter
    public void setCoordinateA(Coordinate A) {
        this.A = A;
    }
    public void setCoordinateB(Coordinate B) {
        this.B = B;
    }
}
```

---

## Áp dụng vào Spring Boot

Spring là một framework được xây dựng dựa trên nguyên lý Dependency injection. Bản thân Spring có chứa IoC container, có nhiệm vụ tạo và quản lý các module:

- IoC của Spring Boot được gọi là **Application Context**.
- Cán module chứa trong IoC container của Spring là **Bean**.

Spring Boot sử dụng các **annotation** dạng như `@Component` để đánh dấu lên class, chỉ ra rằng class đó cần tạo một module. Ngoài `@Component`, thì còn có các annotation khác như: `@Service`, `@Repository`, `@Controller`, ... cũng được đánh dấu là module.

Khi ứng dụng Spring Boot chạy thì IoC container sẽ thực hiện quá trình như sau:

- Quét tìm (scan) các class được đánh dấu là **Bean**, và tạo một object singleton, bỏ vào IoC container.
- Khi có một **Bean** phụ thuộc vào **Bean** khác, thì IoC sẽ tìm trong container, nếu chưa có thì tạo mới, nếu đã có thì lấy ra và inject vào **Bean** cần nó.

---
