#include "binaryTree.h"
#include "classLib.h"

using namespace std;

int main() {
	int arr[] = { 179, 52,  1, 2, 3, 4, 5, 6, 7, 8,9,10,12,14,15,16,71, 53};
	int arr1[] = { 1, 2, 3, 4 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int j = sizeof(arr1) / sizeof(arr1[0]);

	BinaryTree Tree;
	Tree.constructBST(arr, 0, n - 1);
	Tree.printBT();
	BinaryTree newTree;
	newTree.constructBST(arr1, 0, j - 1);
	newTree.printBT();
	Tree.insertArray(Tree.root, 1, 1, newTree.root);
	Tree.printBT();
}