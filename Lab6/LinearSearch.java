package labs;

public class LinearSearch {
    public static void main(String[] args) {
        int[] numbers = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

        LinearSearch linearSearch = new LinearSearch();

        linearSearch.Search(numbers, 50);

        linearSearch.Search(numbers, 65);
    }

    private void Search(int[] array, int item) {
        boolean found = false;
        for(int i = 0; i < array.length; i++) {
            if(array[i] == item)
            {
                found = true;
                System.out.println(item + " found at position " + i);
            }
        }
        if(!found)
            System.out.println(item + " not found in array.");
    }
}
