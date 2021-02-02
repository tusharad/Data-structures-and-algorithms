import java.util.Scanner;

public class LinkedList {
    Scanner in = new Scanner(System.in);

    class Node {
        Node next;
        int data;

        Node(int val) {
            data = val;
            next = null;
        }

        public Node() {
        }
    }

    Node head;

    void printList() {
        Node curr = head.next;
        while (curr != null) {
            System.out.print(curr.data + "->");
            curr = curr.next;
        }
        System.out.println();
    }

    void createList() {
        System.out.println("Testing");
        int n = in.nextInt();
        head = new Node(n);

        Node curr = head, temp;

        for (int i = 0; i < n; i++) {
            System.out.println("Enter " + (i + 1) + " value");
            int val = in.nextInt();
            temp = new Node(val);
            curr.next = temp;
            curr = temp;
        }
    }

    void deleteList(int pos) {
        Node curr = head;
        for (int i = 0; i < pos - 1; i++) {
            curr = curr.next;
        }
        curr.next = curr.next.next;
        head.data--;
    }

    Node traverse(Node curr, int pos) {
        for (int i = 0; i < pos; i++)
            curr = curr.next;
        return curr;
    }

    void insertList(int pos, int val) {
        Node curr = head, temp;
        temp = new Node(val);
        curr = traverse(curr, pos - 1);
        temp.next = curr.next;
        curr.next = temp;
        head.data++;
    }

    void reverse() {
        Node curr = head.next, prev = null, nex;
        while (curr != null) {
            nex = curr.next;
            curr.next = prev;
            prev = curr;
            curr = nex;
        }
        head.next = prev;
    }

    public static void main(String[] args) {
        LinkedList list = new LinkedList();
        list.createList();
        list.printList();
        list.insertList(3, 100);
        // list.reverse();
        list.printList();
    }
}
