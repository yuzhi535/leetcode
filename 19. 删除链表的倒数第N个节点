/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//上述链表定义
//老办法，指针数组
/*
*方法二，可以考虑用滑动窗口解决，右指针正常移动，直到左右指针差距题目要求距离，左右指针同时移动
*当右指针移动到末尾时，此时做指针正好到目标位置，将此删除即可。此方法只需遍历一次。
*/

using Head = ListNode*;

class Solution {
public:
   ListNode* removeNthFromEnd(ListNode* head, int n) {
       if (!head)
            return NULL;
       ListNode* ans, * temp;
       vector<Head> check;
       int index = 0;
       while (head != NULL)
       {
           check.push_back(head);
           ++index;
           head = head->next;
       }
       int i = 0;
       ans = new ListNode(0);
       ans->next = new ListNode(0);
       temp = ans;
       while (i < index)
       {
           if (i == index - n)
           {
               ++i;
               if (i == index)
                   break;
           }

           temp = temp->next;
           temp->val = check[i]->val;
           ++i;
           temp->next = new ListNode(0);
       }
       delete temp->next;
       temp->next = NULL;
       return ans->next;
   }
};
