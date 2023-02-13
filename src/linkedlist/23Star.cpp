//23. 合并K个升序链表
#include<vector>
#include <queue>

//个人解法：用大顶堆
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
//class Solution {
//public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //for (vector<ListNode*>::iterator iter = lists.begin(); iter != lists.end(); iter++)
       // for (auto iter = lists.begin(); iter != lists.end(); iter++)
        //priority_queue<int> pq;
        if (lists.size() == 0)
            return nullptr;
        priority_queue<int, vector<int>, greater<int> > pq;
        ListNode* calc = nullptr;;
        ListNode* ret = nullptr;;
        for (size_t i = 0; i < lists.size(); i++)
        {
            while (lists[i])
            {
                pq.push(lists[i]->val);
                lists[i] = lists[i]->next;
            }
        }
        int popval = 0;
        while (!pq.empty())
        {
            popval = (int)pq.top();
            pq.pop();
            if (!calc)
            {
                calc = new ListNode(popval);
                ret = calc;
            }
            else
            {
                ListNode* newNode = new ListNode(popval);
                calc->next = newNode;
                calc = calc->next;
            }

        }
        return ret;
    }
//};

int main()
{
    ListNode* l1 = nullptr;
    vector<ListNode*> lists;
    lists.push_back(l1);
    mergeKLists(lists);
}

//最优解，递归两两合并链表
//
//class Solution{
//public:
//    ListNode * mergeTwoList(ListNode * l1, ListNode * l2) {
//        if (l1 == nullptr) return l2;
//        if (l2 == nullptr) return l1;
//        if (l1->val <= l2->val) {
//            l1->next = mergeTwoList(l1->next, l2);
//            return l1;
//        }
//        else {
//            l2->next = mergeTwoList(l2->next, l1);
//            return l2;
//        }
//    }
//
//    ListNode * merge(vector <ListNode*> &lists, int l, int r) {
//        if (l == r) return lists[l];
//        if (l > r) return nullptr;
//        int mid = (l + r) >> 1;
//        return mergeTwoList(merge(lists, l, mid), merge(lists, mid + 1, r));
//    }
//
//    ListNode * mergeKLists(vector<ListNode*>&lists) {
//        return merge(lists, 0, lists.size() - 1);
//    }
//};