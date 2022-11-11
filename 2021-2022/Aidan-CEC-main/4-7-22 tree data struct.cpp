#include<iostream>
using namespace std;

class Node
{
public:
	int generation;
	string name;
	class Node* left;
	class Node* right;
	Node(int gen, string n);
	void print();
};

void printTree(class Node* node);

int main() {
	cout << "Hello data structures!" << endl;
	Node* root = new Node(0, "Anna");

	root->left = new Node(1, "Andre");
	root->right = new Node(1, "Dianna");

	root->left->left = new Node(2, "Aidan");
	root->left->right = new Node(2, "Noah");

	root->left->left->left = new Node(3, "Milo");
	root->left->left->right = new Node(3, "Felix");
	printTree(root);
}

Node::Node(int gen, string n) {
	generation = gen;
	name = n;
}

void Node::print() {
	cout << "Hi my name is " << name << " and I am generation " << generation << "." << endl;
}

void printTree(class Node* node) {
	if (node == NULL)
		return;

	printTree(node->left);

	cout << "Hello, I'm " << node->name << " and I'm generation " << node->generation << endl;

	printTree(node->right);
}
