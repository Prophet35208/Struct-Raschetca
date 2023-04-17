#include "Header.h"
#include <iostream>;
using namespace std;
// �����������
BST::BST()
{
	root = nullptr;
}
// ���������� �������� � ������. 
// ���������� ����� �� ����� ����� ������. 
// ������� ����������. ���-�� ������� ������������ �������� ������(G). ������ ��������� O(G).
// � ������ ������ G=N, ������ ��������� O(N)
Node* BST::FindMin(Node* node)
{
	if (node == nullptr)
		// ������� ��� ������ ��������� ����
		return nullptr;
	else
		if (node->left == nullptr)
			// ����������� �������������� ����
			return node;
		else
			// ������� � ���������� ����, ���� �� ����������.
			// ����� ��������� �-�� ,������ ��������� ��������� ����� ������������ ����
			return FindMin(node->left);
}
// ������� ����� � ������.
// ������� ����������. ���-�� ������� ������������ �������� ������(G). ������ ��������� O(G).
// � ������ ������ G=N, ������ ��������� O(N)
Node* BST::InsertNode(int value, Node* node)
{
	if (node == nullptr)
	{
		// �������� ����. ����� �� �������� �������� �����, ���� ����� ������ �-�� ������� ����
		node = new Node(value);
		node->left = node->right = nullptr;
	}
	else
		if (value < node->value)
			// ���� ����� ������ ����� �������� ����, �� ������� �� ����� �����
			node->left = InsertNode(value, node->left);
		else
			if (value > node->value)
				// ���� ����� ������ ����� �������� ����, �� ������� �� ������ �����
				node->right = InsertNode(value, node->right);
	// ������� �������� ���������������� ����. ������ ��������� �-�� ��������� ������ ��� ��������� ��������
	return node;
}
// �������� ���� �� ������.
// ������� ����������. ���-�� ������� ������������ N. ������ ��������� O(N).
Node* BST::DeleteNode(int value, Node* node)
{
	// ��������������� ������ ��� ��������
	Node* temp;
	if (node == nullptr)
		return nullptr;
	else
		// ���� ������� �������� ������ �������� �������� ����, �� ������� �� ����� �����
		if (value < node->value)
			node->left = DeleteNode(value, node->left);
		else
			// ���� ������� �������� ������ �������� �������� ����, �� ������� �� ������ �����
			if (value > node->value)
				node->right = DeleteNode(value, node->right);
			else
				if (node->left && node->right)
				{
				// ���� � ���������� ���� ���� 2 ��������, ����� ����� ������ ���������� ���� ��������
				// ����������� ���� ������� ��������, ��� ������ ��������-��������� ���� 
					temp = FindMin(node->right);
					node->value = temp->value;
					// �������� �������� ��������
					node->right = DeleteNode(node->value, node->right);
				}
				else
				{
					// ������� ��� ����� ������� ��� �� ��� �� ����������
					temp = node;
					// ���� ���� ������ ������ �������, �� �������� ���������� ��
					if (node->left == nullptr)
						node = node->right;
					else 
					// ���� ���� ������ ����� �������, �� �������� ���������� ��
						if (node->right == nullptr)
						node = node->left;
					delete temp;
				}
	return node;
}
// ��������� �������� � ������. ��� ���� � ������ ����������� N ��������
void BST::GetValues(Node* node,list<int>* l)
{
	if (node == NULL)
		// ������� ��� ���������� �����
		return;
	// ������� �� ����� �����
	GetValues(node->left, l);
	l->push_back(node->value);
	// ������� �� ������ �����
	GetValues(node->right,l);
}

// �-��, ��������������� ������������. ��������� ������� ����
void BST::InsertNode(int x)
{
	// �������� �����, ���� ��� �� ����. � ���� ������ �������� ����� �� ���������
	root = InsertNode(x, root);
}
// �-��, ��������������� ������������. ��������� ������� ����
void BST::DeleteNode(int x)
{
	// ���� ������ �� ��� �����, �� �� �� ���������. ���� ������ �����, ������������ �����
	root = DeleteNode(x, root);
}

// ��������� � GetValues
void BST::GetValues(list<int>* l)
{
	GetValues(root, l);
}

// ����� ������ � �����
void BST::PrintTree(Node* t, int l, ofstream& ofc)
{
	if (t == NULL)
		return;
	PrintTree(t->right, l + 1, ofc);
	for (int i = 0; i < l; ++i)
		// ������ ������ �� �������� ������ ������
		ofc << "\t";
	ofc << t->value << endl;
	PrintTree(t->left, l + 1, ofc);
}
// ��������� � PrintTree �� ������� ������������
void BST::DisplayTree(ofstream& ofc)
{
	PrintTree(root, 0, ofc);
}
// ����� ������ � cout
void BST::PrintTreeCout(Node* t, int l)
{
	if (t == NULL)
		return;
	PrintTreeCout(t->right, l + 1);
	for (int i = 0; i < l; ++i)
		// ������ ������ �� �������� ������ ������
		cout << "\t";
	cout << t->value << endl;
	PrintTreeCout(t->left, l + 1);
}
// ��������� � PrintTreeCout �� ������� ������������
void BST::DisplayTreeCout()
{
	PrintTreeCout(root, 0);
}



