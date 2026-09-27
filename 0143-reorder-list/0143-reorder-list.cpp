/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || head->next == nullptr){
            return;
            
        }

        ListNode *slow = head , *fast = head;

        while(fast->next != nullptr && fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* secondhalf = slow->next;
        slow->next = nullptr;
        


        ListNode *current = secondhalf , *prev = nullptr;

        while (current != nullptr){
            ListNode* temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
        }

        secondhalf = prev;
        ListNode* second = secondhalf;
        ListNode* first = head;


        while(second != nullptr){
            ListNode *temp1 = first->next , *temp2 = second->next;
            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;

        }



        

        
        
    }
};