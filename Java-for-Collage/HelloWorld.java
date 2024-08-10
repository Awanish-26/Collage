class A {
    int sum(int x, int y) {
        return x + y;
    }

    double sum(double x, double y) {
        return x + y;
    }

    int sum(int x, int y, int z) {
        return x + y + z;
    }
}

public class HelloWorld {
    public static void main(String args[]) {
        A obj = new A();
        System.out.println(obj.sum(9, 1) + "\n" + obj.sum(9, 10, 9) + "\n" + obj.sum(10.3, 9.66));
        // System.out.println(obj.sum(9, 10, 96));
        // System.out.println(obj.sum(10.3, 9.66));
    }
}