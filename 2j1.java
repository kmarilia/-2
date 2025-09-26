// Класс узла списка
class ListNode {
    int val;
    ListNode next;
    
    ListNode(int val) {
        this.val = val;
        this.next = null;
    }
}

public class LinkedListReversal {
    
    public static ListNode reverseList(ListNode head) {
        ListNode prev = null;    // Предыдущий узел
        ListNode current = head; // Текущий узел
        
        while (current != null) {
            ListNode nextTemp = current.next; // Сохраняем следующий узел
            current.next = prev;  // Разворачиваем указатель
            prev = current;       // Перемещаем prev на текущий
            current = nextTemp;   // Перемещаем current на следующий
        }
        
        return prev; // Новый головной узел
    }
    
    // Вспомогательная функция для печати списка
    public static void printList(ListNode head) {
        ListNode current = head;
        while (current != null) {
            System.out.print(current.val + " → ");
            current = current.next;
        }
        System.out.println("null");
    }
    
    public static void main(String[] args) {
        // Создаем список: 1 → 2 → 3 → 4 → null
        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(3);
        head.next.next.next = new ListNode(4);
        
        System.out.print("Исходный список: ");
        printList(head);
        
        // Разворачиваем список
        head = reverseList(head);
        
        System.out.print("Развернутый список: ");
        printList(head);
    }
}