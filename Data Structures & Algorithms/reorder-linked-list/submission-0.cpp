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
    ListNode* reverseList(ListNode* node){
        if(!node ||  !node->next) return node; 
        ListNode* newHead = reverseList(node->next) ;
        node->next->next = node ;
        node->next = nullptr ;
        return newHead ;
    }

    void reorderList(ListNode* head) {
        if(!head->next || !head->next->next) return ;
        ListNode* slow = head ; ListNode* fast = head ;
        while(fast && fast->next) {
            slow = slow->next ;
            fast = fast->next->next ;
        }

        ListNode* second = reverseList(slow->next) ;
        slow->next = nullptr;
        ListNode* first = head;

        while(second){
            // insert head2 after head1 ;
            ListNode* temp = first->next ;
            first->next = second ;
            second = second->next ;
            first->next->next = temp ;
            first = temp ;
        }
        return  ;

    }
};
