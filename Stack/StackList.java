public class StackList<E> {
    class Node {
        Node next;
        E data;

        Node(E val) {
            this.data = val;
        }
    }

    private Node top;

    boolean isEmpty() {
        return top == null;
    }

    void push(E val) {
        Node temp = new Node(val);
        temp.next = top;
        top = temp;
    }

    void pop() {
        if (isEmpty()) {
            System.err.println("Stack UnderFlow");
        }
        Node temp = top;
        top = top.next;
        temp.next = null;
    }

    E peek() {
        return top.data;
    }

    void printStack() {
        Node curr = top;
        while (curr != null) {
            System.out.print(curr.data + "->");
            curr = curr.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        StackList<String> sl = new StackList<String>();

        sl.push("ABC");
        sl.push("XYZ");
        sl.push("PQR");
        sl.printStack();
        sl.pop();
        System.out.println("To be poped element: " + sl.peek());
        sl.printStack();

    }
}
