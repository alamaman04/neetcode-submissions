/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node* , Node*> mpp ;
    Node* copyRandomList(Node* head) {
        if(!head) return head ;
        if(mpp.find(head)!=mpp.end()) return mpp[head] ;
        Node* copy = new Node(head->val) ;
        mpp[head] = copy ;
        copy->next =copyRandomList(head->next) ;
        copy->random = mpp[head->random] ;
        return copy ;

    }
};
