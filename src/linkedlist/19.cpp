//给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (!head)
        return nullptr;
    int count = 0;
    int deleteIndex = 0;
    ListNode * calc = head;
    ListNode * ret = head;
    while (head)
    {
        head = head->next;
        count++;
    }
    if (n == count)
    {
        calc = calc->next;
        return calc;
    }
    deleteIndex = count - n;
    for (short i = 0; i < deleteIndex-1; i++)
    {
        calc = calc->next;
    }
    ListNode* deleteNode = calc->next;
    calc->next = calc->next->next;
    delete(deleteNode);
    return ret;
}


//int main()
//{
//    ListNode* l1 = new ListNode(1);
//    l1->next = new ListNode(2);
//    l1->next->next = new ListNode(4);
//    ListNode* l2 = new ListNode(1);
//    l2->next = new ListNode(3);
//    l2->next->next = new ListNode(4);
//    ListNode* a = removeNthFromEnd(l1, 1);
//    std::cout << "Hello World!\n";
//}
