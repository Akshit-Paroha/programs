/*#include <iostream>
using namespace std;

struct MyListNode
{
    int val;
    MyListNode *next;
    MyListNode(int x) : val(x), next(nullptr) {}
};*/

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *dummyHead = new ListNode(0);
        ListNode *current = dummyHead;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry)
        {
            int sum = carry;
            if (l1 != nullptr)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr)
            {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;
        }

        return dummyHead->next;
    }
};

/*
int main()
{
    Solution solution;

    MyListNode *l1 = new MyListNode(2);
    l1->next = new MyListNode(4);
    l1->next->next = new MyListNode(3);

    MyListNode *l2 = new MyListNode(5);
    l2->next = new MyListNode(6);
    l2->next->next = new MyListNode(4);

    MyListNode *result = solution.addTwoNumbers(l1, l2);

    cout << "Result: ";
    while (result != nullptr)
    {
        cout << result->val;
        if (result->next != nullptr)
            cout << " -> ";
        result = result->next;
    }
    cout << endl;

    return 0;
}
* /