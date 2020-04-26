/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //思路：分治，类似于快速排序，利用合并两个排序链表的代码，利用二分法进行排序
 
class Solution
{
public:
    ListNode* mergeLists(ListNode* a, ListNode* b)
    {
        if (!a || !b)
            return a ? a : b;
        ListNode head(0), * tail = &head;
        while (a && b)
        {
            if (a->val > b->val)
            {
                tail->next = b;
                b = b->next;
            }
            else
            {
                tail->next = a;
                a = a->next;
            }
            tail = tail->next;
        }
        tail->next = a ? a : b;
        return head.next;
    }

    ListNode* mergeTwoList(vector<ListNode*>& lists, int l, int r)
    {
        if (l == r)
            return lists[l];
        if (l > r)
            return nullptr;
        int m = (r - l) >> 2;
        return mergeLists(mergeTwoList(lists, l, l + m), mergeTwoList(lists, l + m + 1, r));
    }

    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        if (lists.empty())
            return nullptr;
        return mergeTwoList(lists, 0, lists.size() - 1);
    }
};
