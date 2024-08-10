
class Person {
    int age;
    String name;

    Person(int age, String name) {
        this.name = name;
        this.age = age;
    }
}

class Emp extends Person {
    int salary;

    Emp(int age, String name, int salary) {
        super(age, name);
        this.salary = salary;
    }
}

public class newone {
    public static void main(String[] args) {
        Emp e1 = new Emp(12, "Aman", 30000);
        System.out.println(e1.age + e1.name + e1.salary);
    }
}