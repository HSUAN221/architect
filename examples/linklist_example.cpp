// Copyright (c) 2022 LucaWei
#include <architect/architect.hpp>
using architect::ListNode;
ListNode* RecursiveDisplay(ListNode* head) {
    if (!head)
        return head;
    std::cout << head->val << std::endl;
    RecursiveDisplay(head->next);
    return head;
}

int main(int argc, char **argv) {
    // define link list
    ListNode* link_list = new ListNode(1);
    link_list->next = new ListNode(2);
    link_list->next->next = new ListNode(3);
    std::cout << RecursiveDisplay(link_list)->val << std::endl;
    // 遞迴顯示 link list
    return 0;
}