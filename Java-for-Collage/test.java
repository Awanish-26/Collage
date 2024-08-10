class test {
    static int a = 10;
    static {
        System.out.println("Inisde");
    }

    static String m() {
        return "Hello";
    }

    public static void main(String[] args) {
        System.out.println(a);
        System.out.println(m());
    }
}
