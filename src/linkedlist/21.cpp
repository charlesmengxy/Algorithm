//21. 合并两个有序链表
#include "iostream"
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (!list1)
    {
        return list2;
    }
    if (!list2)
    {
        return list1;
    }
    ListNode* calc = new ListNode(0);
    ListNode* ret = calc;
    while (list1|| list2)
    {
        if (!list1)
        {
            calc->next = new ListNode(list2->val);
            list2 = list2->next;
        }
        else if (!list2)
        {
            calc->next = new ListNode(list1->val);
            list1 = list1->next;
        }
        else if (list1->val < list2->val)
        {
            calc->next = new ListNode(list1->val);
            list1 = list1->next;
        }
        else
        {
            calc->next = new ListNode(list2->val);
            list2 = list2->next;
        }
        calc = calc->next;
    }
    ret = ret->next;
    return ret;
}

class Solution {
public:
   
};
//
//int main()
//{
//    ListNode* l1 = new ListNode(1);
//    l1->next = new ListNode(2);
//    l1->next->next = new ListNode(4);
//    ListNode* l2 = new ListNode(1);
//    l2->next = new ListNode(3);
//    l2->next->next = new ListNode(4);
//    ListNode* a = mergeTwoLists(l1, l2);
//    std::cout << "Hello World!\n";
//}
