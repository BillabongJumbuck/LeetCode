//
// Created by QinJM on 2023/10/13.
//

#ifndef LEETCODE_155_H
#define LEETCODE_155_H
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int val, ListNode* next):val(val), next(next){}
};
class MinStack {
private:
    ListNode *head;
public:
    MinStack() {
        head = new ListNode(0, nullptr);
    }

    void push(int val) {
        ListNode *tmp = new ListNode(val, head->next);
        head->next =tmp;
    }

    void pop() {
        ListNode *tmp = head->next;
        if(tmp == nullptr)
            return;
        head->next = tmp->next;
        delete tmp;
    }

    int top() {
        return head->next == nullptr? 0 : head->next->val;
    }

    int getMin() {
        ListNode *tmp = head->next;
        int min = tmp->val;
        while(tmp){
            if(tmp->val < min)
                min = tmp->val;
            tmp = tmp->next;
        }
        return min;
    }
};
#endif //LEETCODE_155_H
