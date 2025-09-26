class ListNode {
    int val;
    ListNode next;
    
    ListNode(int val) {
        this.val = val;
        this.next = null;
    }
}

public class CycleDetection {
    
    public static boolean hasCycle(ListNode head) {
        if (head == null || head.next == null) {
            return false;
        }
        
        ListNode slow = head; // Медленный указатель (черепаха)
        ListNode fast = head; // Быстрый указатель (заяц)
        
        while (fast != null && fast.next != null) {
            slow = slow.next;          // Черепаха делает 1 шаг
            fast = fast.next.next;     // Заяц делает 2 шага
            
            if (slow == fast) {
                return true; // Указатели встретились - есть цикл
            }
        }
        
        return false; // fast достиг конца списка - цикла нет
    }
    
    // Создание списка с циклом для тестирования
    public static ListNode createListWithCycle() {
        ListNode head = new ListNode(1);
        ListNode node2 = new ListNode(2);
        ListNode node3 = new ListNode(3);
        ListNode node4 = new ListNode(4);
        
        head.next = node2;
        node2.next = node3;
        node3.next = node4;
        node4.next = node2; // Создаем цикл: 4 → 2
        
        return head;
    }
    
    public static void main(String[] args) {
        // Тестируем список с циклом
        ListNode cyclicList = createListWithCycle();
        System.out.println("Список с циклом: " + hasCycle(cyclicList));
        
        // Тестируем список без цикла
        ListNode normalList = new ListNode(1);
        normalList.next = new ListNode(2);
        normalList.next.next = new ListNode(3);
        
        System.out.println("Список без цикла: " + hasCycle(normalList));
    }
}