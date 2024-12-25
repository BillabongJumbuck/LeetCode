struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr)
            return nullptr;

        bool flag = false;
        if(head->next && head->val == head->next->val){
            head = head->next;
            flag = true;
        }
        ListNode *node1 = head;
        ListNode *node2 = node1->next;
        while(node1){
            bool flag2 = false;
            while(node2->next && node2->val == node2->next->val){
                node2 = node2->next;
                flag2 = true;
            }
            if(flag2){
                node1->next = node2->next;
            }else{
                node1->next = node2;
            }
            node1 = node1->next;
            node2 = node1->next;
        }
        if(flag){
            return head->next;
        }else{
            return head;
        }
    }
};