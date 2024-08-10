import java.util.Scanner;

public class EXP2 {
    public static void main(String[] args) {
        Scanner obj = new Scanner(System.in);
        System.out.print("Enter first Number:");
        int num1 = obj.nextInt();
        System.out.print("Enter second Number:");
        int num2 = obj.nextInt();
        if (num1 == num2) {
            System.out.println("Numbers are equal");
        } else {
            System.out.println("Numbers are not equal");
        }

    }
}
