import java.util.Scanner;

public class EXP4 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Without using a third variable
        System.out.println("Enter two numbers to swap (without using a third variable):");
        System.out.print("Enter first number: ");
        int a = scanner.nextInt();
        System.out.print("Enter second number: ");
        int b = scanner.nextInt();

        System.out.println("Before swap:");
        System.out.println("a = " + a + ", b = " + b);

        a = a + b;
        b = a - b;
        a = a - b;

        System.out.println("After swap:");
        System.out.println("a = " + a + ", b = " + b);

        // With using a third variable
        System.out.println("\nEnter two numbers to swap (with using a third variable):");
        System.out.print("Enter first number: ");
        int x = scanner.nextInt();
        System.out.print("Enter second number: ");
        int y = scanner.nextInt();

        System.out.println("Before swap:");
        System.out.println("x = " + x + ", y = " + y);

        int temp = x;
        x = y;
        y = temp;

        System.out.println("After swap:");
        System.out.println("x = " + x + ", y = " + y);

        scanner.close();
    }
}
