public class Main {

    public static void ModifySalary(Employee employee) {
        int currentSalary = employee.getSalary();
        employee.setSalary(currentSalary * 300);
    }

    public static void main(String[] args) {
        Employee employee = new Employee("sam", 1000);
        employee.ShowSalary(); // 1000
        ModifySalary(employee);
        employee.ShowSalary(); // 300000
    }
}