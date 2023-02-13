#include <iostream>


 //Definition for singly-linked list.
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
         if (l1 == nullptr)
         {
             return l2;
         }
         if (l2 == nullptr)
         {
             return l1;
         }
         ListNode* pre1 = new ListNode(0);
         ListNode* pre2 = new ListNode(0);
         pre1->next = l1;
         pre2->next = l2;
         ListNode* calc = new ListNode(0);
         ListNode* ret = calc;
         short hasCarry = 0;
         while (/*pre1!= nullptr || pre2!= nullptr ||*/pre1->next != nullptr || pre2->next != nullptr)
         {
             calc->next = new ListNode(0);
             if (hasCarry)
             {
                 calc->next = new ListNode(0);
                 calc->next->val = 1;
             }
             if (pre1 != nullptr && pre1->next != nullptr)
             {
                 calc->next->val += pre1->next->val;
                 pre1 = pre1->next;
             }
             if (pre2 != nullptr && pre2->next != nullptr)
             {
                 calc->next->val += pre2->next->val;
                 pre2 = pre2->next;
             }
             calc = calc->next;
             if (calc->val >= 10)
             {
                 calc->val %= 10;
                 hasCarry = 1;
             }
             else
             {
                 hasCarry = 0;
             }
         }
         if (hasCarry)
         {
             calc->next = new ListNode(0);
             calc->next->val = 1;
         }
         if (ret->next != nullptr)
         {
             ret = ret->next;
         }
         return ret;
     }
 };

 //beat 100
 //class Solution {
 //public:
 //    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
 //        ListNode* newHead = new ListNode(0);
 //        ListNode* p = l1;
 //        ListNode* q = l2;
 //        ListNode* curr = newHead;
 //        int carry = 0;
 //        while (p != NULL || q != NULL) {
 //            int sum = 0, x = 0, y = 0;
 //            if (p) {
 //                x = p->val;
 //                p = p->next;
 //            }

 //            if (q) {
 //                y = q->val;
 //                q = q->next;
 //            }
 //            sum = x + y + carry;
 //            carry = sum / 10;
 //            curr->next = new ListNode(sum % 10);
 //            curr = curr->next;
 //        }

 //        if (carry) {
 //            curr->next = new ListNode(carry);
 //        }

 //        return newHead->next;
 //    }
 //};

 //ver2
 //class Solution {
 //public:
 //    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

 //        //当需要特判第一个节点时，可以创建一个虚拟节点。
 //        auto dummy = new ListNode(-1), curr = dummy;
 //        int t = 0; //表示进位

 //        while (l1 || l2 || t)
 //        {
 //            if (l1) t += l1->val, l1 = l1->next;
 //            if (l2) t += l2->val, l2 = l2->next;
 //            curr = curr->next = new ListNode(t % 10);
 //            t /= 10;
 //        }

 //        return dummy->next;



 //    }
 //};
