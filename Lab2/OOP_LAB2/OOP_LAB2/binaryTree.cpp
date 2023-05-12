#include "binaryTree.h"

BinaryTree::BinaryTree() : root(nullptr) {}

BinaryTree::~BinaryTree() {
    deleteTree(root);
}

BinaryTree::BinaryTree(const BinaryTree& BinaryTree) {
    root = new Node(*BinaryTree.root);
}
BinaryTree::BinaryTree(int* arr) {
    int lenght = sizeof(arr) / sizeof(int);
    int midl = lenght / 2;

}

BinaryTree::Node* BinaryTree::contains(int value){
    Node* node = root;
    while (node != nullptr) {
        if (value < node->data) {
            node = node->left;
        }
        else if (value > node->data) {
            node = node->right;
        }
        else {
            return node;
        }
    }
    return root;
}

void BinaryTree::deleteTree(Node* node) {
    if (node == nullptr) {
        return;
    }
    if (node->left != nullptr) {
        deleteTree(node->left);
    }
    if (node->right != nullptr) {
        deleteTree(node->right);
    }
    delete node;
}

void BinaryTree::insertArray(Node*& node, int i, int j, Node*& newRoot) {
    int* arr1 = new int[18]();
    int x1 = 0;
    in_order_traversal(root, arr1, x1, false);
    for (int i = 0; i < 18; i++) {
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;
    int index = pow(2, i) + j - 1;
    //Node*& temp = lookup(node, index);
    Node* temp = contains(arr1[index-1]);
    int n = countNodes(root) - countNodes(temp) + countNodes(newRoot);
    //std::cout << countNodes(root) <<  " " << countNodes(temp) << " " << countNodes(newRoot) << " " << temp->data;
    int* arr = new int[n]();
    char prefix[1024] = "";
    printBT(prefix, temp, false);
    //deleteTree(temp);
    //temp = nullptr;
    temp = newRoot;
    int x = 0;
    printBT();
    in_order_traversal(root, arr, x , false);
    bubbleSort(arr, n);
    constructBST(arr, 0, n - 1);
}

int BinaryTree::countNodes(Node* node) {
    if (node == NULL) {
        return 0;
    }
    return countNodes(node->left) + countNodes(node->right) + 1;
}

BinaryTree::Node*& BinaryTree::lookup(Node* node, int index) {
    int leftCount = countNodes(node->left);
    if (index < leftCount) {
        return lookup(node->left, index);
    }
    else if (index == leftCount) {
        return node;
    }
    else {
        return lookup(node->right, index - leftCount - 1);
    }
}

void BinaryTree::in_order_traversal(Node* node, int* arr, int& index, bool isLeft) {
    if (node != nullptr)
    {
        arr[index] = node->data;
        index++;
        in_order_traversal( node->left, arr,index, true);
        in_order_traversal( node->right, arr, index, false);
    }
    //if (node == nullptr) {
    //    return;
    //}
    //if (node != nullptr) {
    //    std::cout << " " << node->data;
    //    std::cout << " " << node;
    //    std::cout << " " << arr[index];
    //    arr[++index] = node->data;
    //    in_order_traversal(node->left, arr, index);
    //    //arr[index++] = node->data;
    //    in_order_traversal(node->right, arr, index);
    //}
}

void BinaryTree::bubbleSort(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void BinaryTree::constructBST(int* arr, int start, int end) {
    bubbleSort(arr, end+1);
    root = constructBST(arr, start, end, root);
}

BinaryTree::Node* BinaryTree::constructBST(int* arr, int start, int end, Node* node) {
    if (start > end) {
        return nullptr;
    }

    int mid = (start + end) / 2;
    node = new Node(arr[mid]);
    node->left = constructBST(arr, start, mid - 1, node);
    node->right = constructBST(arr, mid + 1, end, node);

    return node;
}
void BinaryTree::printBT()
{
    char prefix[1024] = "";
    printBT(prefix, root, false);
}
void BinaryTree::printBT(const char* prefix, const Node* node, bool isLeft)
{
    if (node != nullptr)
    {
        std::cout << prefix;
        std::cout << (isLeft ? "├──" : "└──");

        std::cout << node->data << std::endl;

        char newPrefix[1024];
        sprintf_s(newPrefix, "%s%s", prefix, isLeft ? "│   " : "    ");
        printBT(newPrefix, node->left, true);
        printBT(newPrefix, node->right, false);
    }
}

