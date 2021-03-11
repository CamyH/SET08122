package labs;

public class BinarySearch {
    public static void main(String[] args) {
        int[] numbers = {20, 30, 40, 50, 60, 70, 80, 90, 100};

        BinarySearch binarySearch = new BinarySearch();

        binarySearch.Search(numbers, 40);

        binarySearch.Search(numbers, 55);
    }

    private void Search(int[] array, int key) {
        int mid = 0, upper = array.length, lower = 0, found = 0;
        for(mid=(upper+lower) / 2; lower <= upper; mid=(lower+upper)/2) {
            // Compare search key to middle element in array
            if(array[mid] == key) {
                // If there is a match then search is successful
                System.out.println("Item " + key +" is at position " + mid);
                found = 1;
                break;
            }
            // Otherwise, if the key is larger than the middle element in the array
            // Search the lower half of the array
            // Else search the upper half of the array
            if(array[mid] > key)
                upper = mid-1;
            else
                lower = mid+1;
        }
        // If item is not found, print message
        if(found == 0) {
            System.out.println("Item " + key + " is not in the array.");
        }
    }
}
