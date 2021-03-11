package labs;

public class Queue {

    private static int front = -1;
    private static int rear = -1;

    public static void main(String[] args) {

        Queue queue = new Queue();

        int[] numbers = new int[15];

        queue.Enqueue(numbers, 5);
        queue.Enqueue(numbers, 10);
        queue.Enqueue(numbers, 56);
        queue.Enqueue(numbers, 3);
        queue.Enqueue(numbers, 400);
        queue.Enqueue(numbers, 12);

        queue.Display(numbers);

        int item = queue.Dequeue(numbers);
        System.out.println(item);
        item = queue.Dequeue(numbers);
        System.out.println(item);
    }

    /**
     * Method to display contents of supplied array
     * @param array Array to display contents of
     */
    private void Display(int[] array) {
        System.out.println("Contents of Array: ");
        for(int i = 0; i < array.length; i++) {
            System.out.println(array[i]);
        }
    }

    /**
     * Method to add a number to the queue
     * @param array Array
     * @param item Item to add
     */
    private void Enqueue(int[] array, int item) {
        // Check if array is full
        if(rear == array.length-1)
            System.out.println("Queue is full.");
        else {
            System.out.println("Enqueueing " + item);
            rear++;
            array[rear] = item;

            if(front == -1)
                front = 0;
        }
    }

    /**
     * Method to remove the next item in the queue
     * @param array Array to remove item from
     * @return Item removed from queue
     */
    private int Dequeue(int[] array) {
        int item = array[front];
        System.out.println("Dequeueing " + item + " from the queue.");
        array[front] = 0;

        // Move items along one so the next item is at the front
        if(front == rear)
            front = rear = -1;
        else
            front++;

        return item;
    }
}
