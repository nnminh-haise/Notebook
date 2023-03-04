public class Main {
    public static void main(String[] args) {
        System.out.println(Custom.SQR(10));

        int value = 100;
        Custom.TrySQR(value);
        System.out.println("after = " + value);

        Custom.TrySQR(10);
    }
}