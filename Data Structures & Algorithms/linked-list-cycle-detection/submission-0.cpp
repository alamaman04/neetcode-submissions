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
    bool hasCycle(ListNode* head) {
        unordered_map<ListNode*,bool> vis ;
        ListNode* curr = head ;
        while(curr){
            if(vis.find(curr)!=vis.end()) return true ;
            vis[curr] = true ;
            curr = curr->next;
        }
        return false ;
    }
};
