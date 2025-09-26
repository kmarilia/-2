#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    
    ListNode(int value) : val(value), next(nullptr) {}
};

class CycleDetection {
public:
    static bool hasCycle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return false;
        }
        
        ListNode* slow = head; // Медленный указатель
        ListNode* fast = head; // Быстрый указатель
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;          // 1 шаг
            fast = fast->next->next;    // 2 шага
            
            if (slow == fast) {
                return true; // Найден цикл
            }
        }
        
        return false; // Цикла нет
    }
    
    // Создание списка с циклом для тестирования
    static ListNode* createListWithCycle() {
        ListNode* head = new ListNode(1);
        ListNode* node2 = new ListNode(2);
        ListNode* node3 = new ListNode(3);
        ListNode* node4 = new ListNode(4);
        
        head->next = node2;
        node2->next = node3;
        node3->next = node4;
        node4->next = node2; // Создаем цикл
        
        return head;
    }
    
    // Очистка памяти для циклического списка (осторожно!)
    static void deleteCyclicList(ListNode* head) {
        if (head == nullptr) return;
        
        // Для циклического списка нужна специальная логика очистки
        // В реальном коде лучше использовать умные указатели
        ListNode* current = head;
        ListNode* temp;
        
        // Разрываем цикл перед удалением
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                // Нашли цикл, разрываем его
                slow->next = nullptr;
                break;
            }
        }
        
        // Теперь можно безопасно удалять
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    // Тестируем список с циклом
    ListNode* cyclicList = CycleDetection::createListWithCycle();
    cout << "Список с циклом: " << boolalpha << CycleDetection::hasCycle(cyclicList) << endl;
    
    // Тестируем список без цикла
    ListNode* normalList = new ListNode(1);
    normalList->next = new ListNode(2);
    normalList->next->next = new ListNode(3);
    
    cout << "Список без цикла: " << boolalpha << CycleDetection::hasCycle(normalList) << endl;
    
    // Очищаем память
    CycleDetection::deleteCyclicList(cyclicList);
    
    // Очищаем нормальный список
    while (normalList != nullptr) {
        ListNode* temp = normalList;
        normalList = normalList->next;
        delete temp;
    }
    
    return 0;
}