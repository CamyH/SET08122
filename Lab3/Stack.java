package labs;

public class Stack {
    private static class InitStack {
        public static int top = -1;
    }
    public static void main(String[] args) {
        int[]numbers = new int[10];

        push(numbers, 2);
        push(numbers, 4);
        push(numbers, 7);
        push(numbers, 20);
        push(numbers, 100);
        push(numbers, 1);
        push(numbers, 9);
        push(numbers, 42);
        push(numbers, 71);
        push(numbers, -14);
        push(numbers, 19);
        push(numbers, 420);
        push(numbers, 712);
        push(numbers, -5);

        display(numbers);

        System.out.println("##############");

        Integer num = null;
        num = pop(numbers);
        System.out.println("Number popped: "+ num);
        num = pop(numbers);
        System.out.println("Number popped: "+ num);
        num = pop(numbers);
        System.out.println("Number popped: "+ num);
        num = pop(numbers);
        System.out.println("Number popped: "+ num);

        System.out.println("##############");

        display(numbers);
    }

    /**
     * Method to display contents of Stack
     * @param array Array to add to front of
     */
    private static void display(int[] array) {
        for(int item : array) {
            System.out.println(item);
        }
    }

    /**
     * Method to push an item onto the front of the stack
     * @param array Array to push to front of
     * @param item Item to add onto the front of the stack
     */
    private static void push(int[] array, int item) {
        if(InitStack.top == (array.length-1)) {
            System.out.println("Stack is full. Couldn't push " + item + " to stack.");
        } else{
            InitStack.top++;
            array[InitStack.top] = item;
        }
    }

    /**
     * Method to pop an item from the end of the stack
     * @param array Array to pop item from
     * @return Item that was removed
     */
    private static Integer pop(int[] array) {
        int item;
        if(InitStack.top == -1){
            System.out.println("Stack is empty.");
            return null;
        }
        item = array[InitStack.top];
        array[InitStack.top] = 0;
        InitStack.top--;
        return item;
    }
}
