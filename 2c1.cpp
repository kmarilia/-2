#include <iostream>
using namespace std;

// Структура узла списка
struct ListNode {
    int val;
    ListNode* next;
    
    ListNode(int value) : val(value), next(nullptr) {}
};

class LinkedListReversal {
public:
    static ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;    // Предыдущий узел
        ListNode* current = head;    // Текущий узел
        
        while (current != nullptr) {
            ListNode* nextTemp = current->next; // Сохраняем следующий узел
            current->next = prev;    // Разворачиваем указатель
            prev = current;          // Перемещаем prev на текущий
            current = nextTemp;      // Перемещаем current на следующий
        }
        
        return prev; // Новый головной узел
    }
    
    // Вспомогательная функция для печати списка
    static void printList(ListNode* head) {
        ListNode* current = head;
        while (current != nullptr) {
            cout << current->val << " → ";
            current = current->next;
        }
        cout << "null" << endl;
    }
    
    // Функция для очистки памяти
    static void deleteList(ListNode* head) {
        while (head != nullptr) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    // Создаем список: 1 → 2 → 3 → 4 → null
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    
    cout << "Исходный список: ";
    LinkedListReversal::printList(head);
    
    // Разворачиваем список
    head = LinkedListReversal::reverseList(head);
    
    cout << "Развернутый список: ";
    LinkedListReversal::printList(head);
    
    // Очищаем память
    LinkedListReversal::deleteList(head);
    
    return 0;
}