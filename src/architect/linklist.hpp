// Copyright (c)
#ifndef SRC_ARCHITECT_LINKLIST_HPP_
#define SRC_ARCHITECT_LINKLIST_HPP_
namespace architect {


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

}  // namespace architect
#endif  // SRC_ARCHITECT_LINKLIST_HPP_
