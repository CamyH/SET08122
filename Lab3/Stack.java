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
     * @param stack Array to add to front of
     */
    private static void display(int[] stack) {
        for(int item : stack) {
            System.out.println(item);
        }
    }

    /**
     * Method to push an item onto the front of the stack
     * @param stack Array to push to front of
     * @param item Item to add onto the front of the stack
     */
    private static void push(int[] stack, int item) {
        // If top is equal to the size of the stack - 1 (for zero indexing) then the stack is full
        if(InitStack.top == (stack.length-1)) {
            System.out.println("Stack is full. Couldn't push " + item + " to stack.");
        } else{
            // If stack is not full increment top by 1
            InitStack.top++;
            // Add item to top of stack
            stack[InitStack.top] = item;
        }
    }

    /**
     * Method to pop an item from the end of the stack
     * @param stack Array to pop item from
     * @return Item that was removed
     */
    private static Integer pop(int[] stack) {
        int item;
        // If top is -1 then stack is empty
        if(InitStack.top == -1){
            System.out.println("Stack is empty.");
            return null;
        }
        // Set item to pop to the last item in the stack
        item = stack[InitStack.top];
        // Set back to 0
        stack[InitStack.top] = 0;
        // Decrease top so next time pop is called the next item down is popped
        InitStack.top--;
        return item;
    }
}
