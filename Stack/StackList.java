public class StackList {
    class Node {
        Node next;
        int data;

        Node(int val) {
            this.data = val;
        }
    }

    private Node top;

    boolean isEmpty() {
        return top == null;
    }

    void push(int val) {
        Node temp = new Node(val);
        temp.next = top;
        top = temp;
    }

    void pop() {
        Node temp = top;
        top = top.next;
        temp.next = null;
    }

    int peek() {
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
        StackList sl = new StackList();
        sl.push(10);
        sl.push(15);
        sl.push(18);
        sl.printStack();
        sl.pop();
        System.out.println(sl.peek());
        sl.printStack();
    }
}
