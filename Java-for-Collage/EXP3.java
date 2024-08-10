import java.util.Scanner;

public class EXP3 {
    public static void main(String[] args) {
        Scanner obj = new Scanner(System.in);
        System.out.println("Enter Numbers:");
        int num1 = obj.nextInt();
        int num2 = obj.nextInt();
        int num3 = obj.nextInt();
        System.out.print("Greatest:");
        if (num1 > num2 && num1 > num3) {
            System.out.print(num1);
        } else if (num2 > num1 && num2 > num3) {
            System.out.print(num2);
        } else if (num3 > num1 && num3 > num2) {
            System.out.print(num3);
        } else {
            System.out.print("All Numbers are equal");
        }
    }
}
