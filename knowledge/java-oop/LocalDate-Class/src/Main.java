import java.time.LocalDate;

public class Main {

    public static void main(String[] args) {
        LocalDate currentDate = LocalDate.now();
        System.out.println("Current day: " + currentDate.toString());

        System.out.println("The next 100 days is: " + currentDate.plusDays(100).toString());
    }
}