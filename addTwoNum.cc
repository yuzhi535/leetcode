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

#include <bits/stdc++.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode(), * head = ans, * last = ans;
        int ano = 0;
        while (l1 || l2 || ano) {
            ans->val += ano;
            int num = (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            ans->val += num;
            if (ans->val >= 10) {
                ano = ans->val / 10;
                ans->val %= 10;
            }
            l1 = (l1 ? l1->next : l1); (l2 = l2 ? l2->next : l2);
            ans->next = new ListNode();
            last = ans;
            ans = ans->next;
        }
        delete ans;
        last->next = nullptr;
        return head;
    }
};

int main(int argc, char** argv) {
    ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));

    Solution s;
    auto re = s.addTwoNumbers(l1, l2);
    for (; re; ) {
        printf("%d\n", re->val);
        re = re->next;
    }
    return 0;
}