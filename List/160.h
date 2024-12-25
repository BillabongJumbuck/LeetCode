struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        while(headA && headB){
            if (find(headA ,headB))
                return headB;
            headB = headB->next;
        }
        return nullptr;
    }
    bool find(ListNode *L, ListNode *X){
        while(L){
            if(L == X)
                return true;
            L = L->next;
        }
        return false;
    }
};