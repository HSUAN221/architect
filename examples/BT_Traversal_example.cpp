// Copyright (c) 2022 LucaWei
#include <architect/architect.hpp>
using architect::tree_node;
using architect::binary_tree;


int main(int argc, char **argv) {
    using node_ptr_type = std::shared_ptr<tree_node>;

    // initialize tree_node
    node_ptr_type nodeA = std::make_shared<tree_node>("A");
    node_ptr_type nodeB = std::make_shared<tree_node>("B");
    node_ptr_type nodeC = std::make_shared<tree_node>("C");
    node_ptr_type nodeD = std::make_shared<tree_node>("D");
    node_ptr_type nodeE = std::make_shared<tree_node>("E");
    node_ptr_type nodeF = std::make_shared<tree_node>("F");
    node_ptr_type nodeG = std::make_shared<tree_node>("G");
    node_ptr_type nodeH = std::make_shared<tree_node>("H");
    node_ptr_type nodeI = std::make_shared<tree_node>("I");

    // construct the Binary Tree
    nodeA->setLeft(nodeB);
    nodeA->setRight(nodeC);

    nodeB->setLeft(nodeD);
    nodeB->setRight(nodeE);

    nodeE->setLeft(nodeG);
    nodeE->setRight(nodeH);

    nodeC->setLeft(nodeF);
    nodeF->setRight(nodeI);

    // link parent pointer
    nodeB->setParent(nodeA);
    nodeC->setParent(nodeA);

    nodeD->setParent(nodeB);
    nodeE->setParent(nodeB);

    nodeG->setParent(nodeE);
    nodeH->setParent(nodeE);

    nodeF->setParent(nodeC);

    nodeI->setParent(nodeF);

    binary_tree BT(nodeA);

    BT.inorder_reverse(BT.root());
    return 0;
}
