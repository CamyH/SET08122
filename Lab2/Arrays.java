package labs;

public class Arrays {
    public static void main(String[] args) {
        // Original Array
        int[] numbers = new int[5];
        // Display contents
        display(numbers);
        // Insert numbers into array
        insert(numbers, 10, 0);
        insert(numbers, 20, 1);
        insert(numbers, 30, 2);
        insert(numbers, 40, 3);
        insert(numbers, 50, 4);
        System.out.println("\n");
        // Display contents
        display(numbers);
        System.out.println("\n");
        // Delete element at position 2
        delete(numbers, 2);
        // Display contents
        display(numbers);
        // Search for 20 in numbers array
        search(numbers, 20);
        // Search for 30 in numbers array
        search(numbers, 30);
        insert(numbers, 30, 2);
        // Reverse array
        reverse(numbers);
        // Display array
        display(numbers);
    }

    /**
     * Method to display contents of the array
     * @param array Array to display contents of
     */
    private static void display(int[] array) {
        for(int item : array) {
            System.out.println(item);
        }
    }

    /**
     * Method to insert a value at a given position
     * @param array Array to perform insertion on
     * @param value Value to insert
     * @param pos Position to insert at
     */
    private static void insert(int[] array, int value, int pos) {
        // Insert value at pos by replacing index with value
        for(int i = 0; i < array.length; i++) {
            if(i == pos)
                array[i] = value;
        }
    }

    /**
     * Method to delete an element at a given position
     * @param array Array to perform deletion on
     * @param pos Location in array to delete element from
     */
    private static void delete(int[] array, int pos) {
        // Delete element at pos by replacing with zero
        for(int i = 0; i < array.length; i++) {
            if (i == pos)
                array[i] = 0;
        }
    }

    /**
     * Method to search array for given value
     * @param array Array to perform search on
     * @param value Number to search array for
     */
    private static void search(int[] array, int value) {
        // Searching through array linearly, not efficient but works
        // isFound is set to true if the item is present
        boolean isFound = false;
        for(int i = 0; i < array.length; i++) {
            if(array[i] == value) {
                System.out.println("Item " + value + " found at position " + i);
                isFound = true;
            }
        }
        if(!isFound)
            System.out.println("Item " + value + " not found in array.");
    }

    /**
     * Method to reverse array
     * @param array Array to reverse
     */
    private static void reverse(int[] array) {
        // Reversing array
        for (int i = 0; i < array.length / 2; i++) {
            // Set temp to current item in array
            int temp = array[i];
            // Set current item in array to the last element
            // array.length = 5, - 1 to set it to the last item at index 4, then -i which is the current position
            array[i] = array[array.length-1-i];
            // Set the last element that hasn't been reversed to the element from the beginning
            array[array.length-1-i] = temp;
        }
    }
}
