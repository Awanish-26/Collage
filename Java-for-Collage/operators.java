public class operators {
    public static void main(String[] args) {
        int x = 10;
        System.out.println("x=" + x + " x=" + x++ + " x=" + x); // outputs x=10 x=10 x=11
        System.out.println("x=" + x + " x=" + ++x + " x=" + x); // outputs x=11 x=12 x=12
        System.out.println("x=" + x + " x=" + x-- + " x=" + x); // outputs x=12 x=12 x=11
        System.out.println("x=" + x + " x=" + --x + " x=" + x); // outputs x=11 x=10 x=10
    }
}
