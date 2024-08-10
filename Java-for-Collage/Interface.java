import java.lang.*;

interface calculator {
    public int add(int a, int b);

    public int sub(int a, int b);

    public int mul(int a, int b);

    public int div(int a, int b);
}

interface scientific_calculator {
    double log(double a);

    double sqrt(double a);
}

class B implements calculator, scientific_calculator {
    @Override
    public int add(int a, int b) {
        return a + b;
    }

    public int sub(int a, int b) {
        return a - b;
    }

    public int mul(int a, int b) {
        return a * b;
    }

    public int div(int a, int b) {
        return a / b;
    }

    public double log(double a) {
        double c = Math.log(a);
        return c;
    }

    public double sqrt(double a) {
        double c = Math.sqrt(a);
        return c;
    }
}

public class Interface {
    public static void main(String[] args) {
        B obj = new B();
        System.out.println(obj.add(5, 4));
        System.out.println(obj.sub(8, 4));
        System.out.println(obj.mul(2, 4));
        System.out.println(obj.div(16, 4));
        System.out.println(obj.log(2));
        System.out.println(obj.sqrt(16));
    }
}
