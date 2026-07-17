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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int total = 0 ;
        ListNode* node = head ;
        while(node){
            total ++ ;
            node = node->next ;
        }
        int x = total - n ;
        if(x==0) return head->next ;
        node = head ;
        while(x>1){
            node = node->next ;
            x--;
        }
        node -> next = node->next->next;
        return head;
    }
};
