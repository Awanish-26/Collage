import java.util.Scanner;

public class EXP6 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter any digit:");
        int i = scan.nextInt();
        int len = String.valueOf(i).length();
        System.out.print(len);
    }
}
