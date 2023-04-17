#pragma once
#include <list>
#include <fstream>
#include <iostream>
using namespace std;
struct Node { // ��������� ���� ��������� ������
	int value; // ���� ������
	Node* left; // ����� �������� ����
	Node* right; // ������ �������� ����
	// �����������
	Node(int data) : value(data), left(nullptr), right(nullptr) {} 
};
class BST { // �������� ������ ������
private:
	Node* root; // ������
	Node* FindMin(Node* node); // ���������� �������� � �������� ������. ������������ �-��� DeleteNode
	Node* InsertNode(int value, Node* node); // �������� ����, ����������� �-�� 
	Node* DeleteNode(int value, Node* node); // ������� ����, ����������� �-��
	void GetValues(Node* node, list<int>* l); // ������������ ������ �� �������� ������
	void PrintTree(Node* t, int l, ofstream& ofc); // ������ ��������� ������ 
	void PrintTreeCout(Node* t, int l); // ������ ��������� ������ � cout

public:
	BST(); // �����������
	void InsertNode(int x); // �-�� ���������� �� private InsertNode, ������� � ������
	void DeleteNode(int x); // �-�� ���������� �� private DeleteNode, �������� �� ������
	void GetValues(list<int>* l); // �-�� ���������� �� private GetValues, ������������ ������ �� ��������
	void DisplayTree(ofstream& ofc);  // ��������� � PrintTree, ������ ������
	void DisplayTreeCout();  // ��������� � PrintTreeCout, ������ ������ � cout 

};