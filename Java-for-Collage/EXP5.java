
// switch statement
import java.util.Scanner;

public class EXP5 {
    public static void main(String[] args) {
        System.out.print("Enter the day number(1-7):");
        Scanner scan = new Scanner(System.in);
        int i = scan.nextInt();
        switch (i) {
            case 1:
                System.out.println("Sunday");
                break;
            case 2:
                System.out.println("Monday");
                break;
            case 3:
                System.out.println("Tuesday");
                break;
            case 4:
                System.out.println("Wednesday");
                break;
            case 5:
                System.out.println("Thursday");
                break;
            case 6:
                System.out.println("Friday");
                break;
            case 7:
                System.out.println("Saturaday");
                break;
            default:
                System.out.println("You cutiya");
                break;
        }
    }
}
