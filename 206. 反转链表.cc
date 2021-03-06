/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 //上面是题目给的链表定义
 //思路是构建指针数组，接着进行反转
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //排除特殊情况
        if (!head)
            return head;
        if (!head->next)
            return head;
            
        vector<ListNode*> arr;
        ListNode* p = head;
        while (p)
        {
            arr.push_back(p);
            p = p->next;
        }
        //反转链表。这只是简单的把值对换，其实也可以对换指针
        size_t i = 0;
        while (i < arr.size() / 2)
        {
            int t = arr.at(i)->val;
            arr.at(i)->val = arr.at(arr.size() - 1 - i)->val;
            arr.at(arr.size() - 1 - i)->val = t;
            ++i;
        }
        return head;
    }
    
    //还有一种递归解法，可以理解为暂时将head视为最终的节点，后面的节点都已反转好，只剩head一个，再处理这一个就行了
    ListNode* reverse_list(ListNode* head)             
    {
        if (head->next == nullptr || head == nullptr)  //判断空链表和入栈终点
            return head;
        ListNode* tmp = reverse_list(head->next);      //假设head后面的节点已经反转好了
        head->next->next = head;                       //将head后面的节点指向head，即开始反转,同时这里改变上一层的nullptr的操作
        head->next = nullptr;                          //这里暂时将head->next设为nullptr,为的是当递归将要结束时，可以判断递归终点
        return tmp;                                    //返回结果
    }
   	
};
