import java.util.Scanner;

class EXP1 {
    public static void main(String args[]) {
        Scanner myObj = new Scanner(System.in);
        System.out.print("Enter Number:");
        int Num = myObj.nextInt();
        for (int i = 1; i <= 10; i++) {
            System.out.println(Num + "*" + i + "=" + Num * i);
        }

    }
}
