// Copyright (c) 2022 LucaWei
#include <architect/architect.hpp>
using architect::ListNode;
// ListNode* RecursiveDisplay(ListNode* head) {
//     if (head) {
//         std::cout << head->val << std::endl;
//         RecursiveDisplay(head->next);
//         return head;
//     }
// }

int main(int argc, char **argv) {
    // define link list
    ListNode* link_list = new ListNode(1);
    link_list->next = new ListNode(2);
    link_list->next->next = new ListNode(3);
    // std::cout << "- " << RecursiveDisplay(link_list)->val << std::endl;
    // 遞迴顯示 link list
    ListNode* head = link_list;
    // head->next = nullptr;
    // std::cout << " f s " << head << " " << link_list << std::endl;
    while (head) {
        std::cout << "j " << head->val << std::endl;
        head = head->next;
    }

    class DecreasingSort {
     public:
        bool operator() (int a, int b) {
            return a > b;
        }
    };
    std::priority_queue<int, std::vector<int>, DecreasingSort> pq;
    pq.push(1);
    pq.push(3);
    pq.push(5);
    pq.push(8);
    while (!pq.empty()) {
        std::cout << pq.top() << std::endl;
        pq.pop();
    }
    return 0;
}
