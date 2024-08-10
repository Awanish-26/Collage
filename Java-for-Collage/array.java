public class array {
    public static void main(String[] args) {
        int[] arr = new int[] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
        System.out.println("Number of Elements in Array:" + arr.length + "\n");
        for (int i = 0; i < arr.length; i++)
            System.out.println("Element at index " + i + " : " + arr[i]);
    }
}
