package labs;

public class LinkedList {
    Node head;
    public static void main(String[] args) {
        LinkedList list = new LinkedList();

        Append(list, 1);
        Append(list, 4);
        Append(list, 67);
        Append(list, 19);

        Display(list);

        Delete(list, 3);

        System.out.println("After deletion:");
        Display(list);

        Delete(list, 4);

        Display(list);
    }

    private static class Node {
        int data;
        Node next;

        // Constructor
        Node(int item){ data = item; };
    }

    private static LinkedList Append(LinkedList list, int item) {
        Node newNode = new Node(item);
        newNode.next = null;

        // if LinkedList is empty, set head to the new node
        if(list.head == null) {
            list.head = newNode;
        } else {
            // Else traverse list until last node and insert newNode there
            Node last = list.head;
            while(last.next != null) {
                last = last.next;
            }

            // Insert newNode at last node
            last.next = newNode;
        }
        return list;
    }

    private static LinkedList Delete(LinkedList list, int pos) {
        Node currentNode = list.head, previous = null;

        if(pos == 0 && currentNode != null) {
            list.head = currentNode.next;

            System.out.println("Item at position " + pos + " deleted.");
            return list;
        }

        int counter = 0;

        while(currentNode != null) {
            if(counter == pos) {
                previous.next = currentNode.next;

                System.out.println("Item at position " + pos + " deleted.");
                break;
            } else {
                // If current position not in the list
                // go to next node
                previous = currentNode;
                currentNode = currentNode.next;
                counter++;
            }
        }

        if(currentNode == null) {
            System.out.println("Item not found at position " + pos);
        }

        return list;
    }

    private static void Display(LinkedList list) {
        Node currentNode = list.head;
        while(currentNode != null) {
            System.out.println(currentNode.data);

            // Go to next node
            currentNode = currentNode.next;
        }
    }
}
