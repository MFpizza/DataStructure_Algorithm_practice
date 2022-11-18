#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
using namespace std;

struct  Node
{
	int data;
	Node* left;
	Node* right;
};

Node* newnode(int a)
{
	Node* temp = new Node;
	temp->data = a;
	temp->left = temp->right = nullptr;

	return temp;
}

vector<int> mark(vector<int>& inorder, vector<int>& preorder) {
	int n = inorder.size();
	vector<int> number;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (inorder[j] == preorder[i]) {
				number.push_back(j);
				continue;
			}


		}

	}
	/*for (int k = 0; k < number.size();k++) {
		cout << number[k];

	}*/

	return number;

}
Node* buildtree(int start, int end, vector<int>& preorder, int& c, vector<int>& number)
{
	if (start > end)
		return nullptr;

	int key = 0;
	Node* root = newnode(preorder[c]);
	key = number[c];
	c++;

	//int key = number[root->data];
	root->left = buildtree(start, key - 1, preorder, c, number);
	root->right = buildtree(key + 1, end, preorder, c, number);

	return root;

}

vector<int> tree2;
void printpreorder(Node* root, int num) {
	if (tree2.size() < num + 1)
	{
		int count = 2;
		while (count-1 < num)
			count *= 2;
		for (int i = tree2.size(); i < count; i++) {
			tree2.push_back(-1);
		}
	}
	tree2[num] = root->data;
	if (root->left != NULL)
		printpreorder(root->left, 2 * num);
	if (root->right != NULL)
		printpreorder(root->right, 2 * num + 1);
}
int main()
{


	vector<int> inorder = { 3, 7, 8, 6, 11, 2, 5, 4, 9 };
	vector<int> preorder = { 2, 7, 3, 6, 8, 11, 5, 9,4 };
	vector<int>a;
	a = mark(inorder, preorder);
	int n = inorder.size();
	int label = 0;
	Node* root = buildtree(0, n - 1, preorder, label, a);

	if (root == nullptr)
	{
		cout << "-1";
		return 0;
	}
	else {
		printpreorder(root, 1);
	}
	int count = 1;
	for (int i = 1; i < tree2.size(); i++) {
		cout << tree2[i]<<' ';
		if (i == count) {
			cout << endl;
			count = 2 * count + 1;
		}
	}
	system("pause");
	return 0;
}