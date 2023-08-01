import java.time.LocalDate;

class Employee {

    // Instance fields
    private String name;
    private double salary;
    private LocalDate hireday;

    // Constructors
    Employee(String name, double salary, int day, int month, int year) {
        this.name = name;
        this.salary = salary;
        this.hireday = LocalDate.of(year, month, day);
    }

    Employee(String name, double salary) {
        this.name = name;
        this.salary = salary;
        this.hireday = LocalDate.now();
    }

    // Methods
    public String getName() {
        return this.name;
    }

    public double getSalary() {
        return this.salary;
    }

    public LocalDate getHireDate() {
        return this.hireday;
    }
}