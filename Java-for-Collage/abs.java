abstract class A {
    abstract int sum(int a, int b);

    abstract int mul(int a, int b);
}

class B extends A {
    int sum(int a, int b) {
        return a + b;
    }

    int mul(int a, int b) {
        return a * b;
    }
}

class abs {
    public static void main(String[] args) {
        B obj = new B();
        System.out.println(obj.sum(56, 95));
        System.out.println(obj.mul(56, 95));
    }
}