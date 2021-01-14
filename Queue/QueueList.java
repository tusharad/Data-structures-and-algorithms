public class QueueList {

  class Node {
    Node next;
    int data;
  }

  Node front, rear;

  boolean isEmpty() {
    return front == null;
  }

  void insert(int val) {
    Node temp = new Node();
    temp.data = val;
    temp.next = null;
    if (isEmpty()) {
      front = rear = temp;
    } else {
      rear.next = temp;
      rear = temp;
    }
  }

  void removeQueue() {
    if (isEmpty()) {
      System.err.println("Queue UnderFlow!");
    }
    Node temp = front;
    front = front.next;
    System.out.println("Deleted element: " + temp.data);
  }

  void printQueue() {
    Node curr = front;
    while (curr != null) {
      System.out.print(curr.data + "->");
      curr = curr.next;
    }
    System.out.println();
  }

  public static void main(String[] args) {
    QueueList list = new QueueList();
    // list.removeQueue();
    list.insert(20);
    list.insert(30);
    list.insert(40);
    list.printQueue();
    list.removeQueue();
    list.printQueue();
  }
}
