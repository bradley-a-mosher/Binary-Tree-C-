//Brad Mosher
//COP 2535
//Binary search tree
#include <iostream>
#include <vector>
using namespace std;

class BTreeNode
{
private:
	struct TreeNode
	{
		double value;
		TreeNode *left;
		TreeNode *right;
		TreeNode(double value1, TreeNode *left1 = nullptr, TreeNode *right1 = nullptr)
		{
			value = value1;
			left = left1;
			right = right1;
		}
	};
	TreeNode *root;
	void insert(TreeNode *&, double);
	void inorder(vector<double>&tlist, TreeNode *t);
	bool search(double x, TreeNode *t);
public:
	BTreeNode()
	{
		root = nullptr;
	}
	void insert(double num)
	{
		insert(root, num);
	}
	void inorder(vector<double> & v) { inorder(v, root); }
	bool search(double x)
	{
		return search(x, root);
	}
};

void BTreeNode::insert(TreeNode * &tree, double num)
{
	if (!tree)
	{
		tree = new TreeNode(num);
		return;
	}
	if (tree->value == num)
		return;
	if (num < tree->value)
		insert(tree->left, num);
	else
		insert(tree->right, num);
}
void BTreeNode::inorder(vector<double> & orderedList, TreeNode *tree)
{
	if (tree == NULL) return;
	inorder(orderedList, tree->left);
	orderedList.push_back(tree->value);
	inorder(orderedList, tree->right);
}
bool BTreeNode::search(double x, TreeNode *tree)
{
	if (tree == NULL)
		return false;
	if (tree->value == x)
		return true;
	if (tree->value > x) return search(x, tree->left);
	else
		return search(x, tree->right);

}

int main()
{
	BTreeNode tree;

	for (int i = 0; i < 5; i++)
	{
		double x = rand() % 100 + 1;
		tree.insert(x);
	}	
	
	vector<double> orderedList;
	orderedList.clear();
	tree.inorder(orderedList);

	
	cout << "TRY TO GUESS THE NUMBER BETWEEN 1 AND 100\n";
	cout << "-----------------------------------------\n";
	cout << "\nEnter a number to search for: ";
	double c;
	cin >> c;
	if (tree.search(c))
		cout << "The number you searched for was found!";
	else
		cout << "The number you searched for was not found.";
	cout << endl << endl;
	cout << "Here are the numbers that were generated " << endl;
	cout << "----------------------------------------" << endl;

	for (int j = 0; j < orderedList.size(); j++)
	{
		cout << orderedList[j] << " ";
	}
	cout << endl << endl;
	

	return 0;

}