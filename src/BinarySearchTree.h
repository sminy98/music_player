#ifndef _BINARYSEARCHTREE_H
#define _BINARYSEARCHTREE_H

#include <iostream>
#include <fstream>	
#include <string>

#include "CircularQueueType.h"
using namespace std;

enum OrderType { PRE_ORDER, IN_ORDER, POST_ORDER };

// Tree�� �����ϴ� Node (node data, left ������, right ������)
template<typename T>
struct Node
{
	T data;
	Node* left;
	Node* right;
};

// Binary Search Tree 
template<typename T>
class BinarySearchTree
{
public:
	// ������
	BinarySearchTree();
	// �Ҹ���
	~BinarySearchTree() { }

	/**
	*	@brief	Tree�� Empty���� Ȯ��
	*	@pre	none
	*	@post	none
	*	@return	Tree�� ��������� true����, �ƴϸ� false ����
	*/
	bool IsEmpty()const;

	/**
	*	@brief	Tree�� Full���� Ȯ��
	*	@pre	none
	*	@post	none
	*	@return	Tree�� Full�̸� true ����, �ƴϸ� false ����
	*/
	bool IsFull()const;

	/**
	*	@brief	Tree�� ����
	*	@pre	none
	*	@post	none
	*/
	void MakeEmpty();

	/**
	*	@brief	Tree�� node�� �� ������ Ȯ����
	*	@pre	none
	*	@post	none
	*	@return	Tree�� node ������ ����
	*/
	int GetLength() const;

	/**
	*	@brief	Tree�� �� node�� �߰��Ѵ�
	*	@pre	ItemType�� ��ü�� ����
	*	@post	Tree�� �� node�� �߰���
	*/
	void Add(T item);

	/**
	*	@brief	Tree���� ������� �ϴ� node�� ã�� ����
	*	@pre	ItemType�� ��ü�� ����
	*	@post	Tree���� �Է��� node�� ������
	*/
	void DeleteItem(T item);

	/**
	*	@brief	�Է��� ���� node�� Tree���� �˻���
	*	@pre	ã���� �ϴ� item�� �˻������ ���� found ����
	*	@post	node�� Tree�� �ִ��� �˻������ �˷���
	*/
	void RetrieveItem(T& item, bool &found)const;

	/**
	*	@brief	Tree�� node�� ��ũ���� ����Ѵ�.
	*	@pre	none
	*	@post	��ũ���� Tree�� InOrder, PreOrder, PostOrder ������� ���� ��µ�.
	*/
	void PrintTree(ostream &out)const;

	void GetNextItem(T& item, bool& found);

	Node<T>* GetPoint(T& item, bool& found);

	void ResetQ();


private:
	Node<T>* root;		// Node Ÿ���� root
//	CircularQueueType<T> preQue;
	CircularQueueType<T> inQue;
//	CircularQueueType<T> postQue;

};

// ������
template<typename T>
BinarySearchTree<T>::BinarySearchTree()
{
	root = NULL;
}

// Tree�� ����ִ��� Ȯ��
template<typename T>
bool BinarySearchTree<T>::IsEmpty()const
{
	if (root == NULL)			// root ��尡 NULL�� ��� true ����
		return true;
	else
		return false;			// root ��尡 NULL�� �ƴ� ��� false ����
}

// Tree�� Full���� Ȯ��
template<typename T>
bool BinarySearchTree<T>::IsFull()const
{
	Node* room;					// �ӽ��� node�� �����
	try
	{
		room = new Node;		// �� ��带 �߰��� �� �ִ��� Ȯ��
		delete room;			// �ӽ÷� ���� room ��带 ����
		return false;			// isFull�� ���� false ����
	}
	catch (std::bad_alloc exception)		// �� �̻� ������ �߰��� �� �� ���� Full�� ���
	{
		return true;					// isFull�� ���� true ����
	}
}

// Tree�� ���
template<typename T>
void BinarySearchTree<T>::MakeEmpty()
{
	MakeEmptyTree(root);				// Tree �ʱ�ȭ �Լ� ȣ��
}

// Tree�� node������ �˷���
template<typename T>
int BinarySearchTree<T>::GetLength()const
{
	return CountNodes(root);			// node ������ ���� �Լ� ȣ��
}

// Tree�� ���ο� node �߰�
template<typename T>
void BinarySearchTree<T>::Add(T item)
{
	Insert(root, item);					// �� node �߰��ϴ� �Լ� ȣ��
}

// Tree�� node�� ����
template<typename T>
void BinarySearchTree<T>::DeleteItem(T item)
{
	Delete(root, item);					// �����ϴ� node �����ϴ� �Լ��� ȣ��
}

// Tree���� ã���� �ϴ� ���� node�� �˻�
template<typename T>
void BinarySearchTree<T>::RetrieveItem(T& item, bool &found)const
{
	Retrieve(root, item, found);		// Tree �˻� �Լ� ȣ��
}


template<typename T>
void BinarySearchTree<T>::ResetQ()
{

	return InOrder(root, inQue);
}

template<typename T>
void BinarySearchTree<T>::GetNextItem(T& item, bool& found)
{
	found = false;

	OrderType order;

	order = IN_ORDER;

	inQue.DeQueue(item);
	if (inQue.IsEmpty())
		found = true;
}

template<typename T>
Node<T>*  BinarySearchTree<T>::GetPoint(T& item, bool& found)
{
	found = false;

	OrderType order;

	order = IN_ORDER;

	inQue.DeQueue(item);
	if (inQue.IsEmpty())
		found = true;

	return root;
}



// Tree�� node�� ������ ������ �����
template<typename T>
void BinarySearchTree<T>::PrintTree(ostream &out)const
{
//	cout << "[InOrder]" << endl;
	PrintInOrderTraversal(root, out);			// InOrder ������� ���
//	cout << endl << "[PreOrder]" << endl;
//	PrintPreOrderTraversal(root, out);			// PreOrder ������� ���
//	cout << endl << "[PostOrder]" << endl;
//	PrintPostOrderTraversal(root, out);			// PostOrder ������� ���
}



/////////////////////////////Global functions//////////////////////////
// Tree�� �ʱ�ȭ�ϴ� �Լ�
template<typename T>
void MakeEmptyTree(Node<T>*& root)
{
	root = NULL;			// root ��带 Null�� ��
}

// Tree�� node ������ ���� �Լ�
template<typename T>
int CountNodes(Node<T>* root)
{
	if (root == NULL)		// root ��尡 null�ϰ�� 0�� ����
		return 0;
	else
		return CountNodes(root->left) + CountNodes(root->right) + 1;		// ����� ����, �����ʿ� ���� ����� ȣ��� root�� �ش��ϴ� 1�� ���ؼ� ���� ����
}

// BinarySearchTree�� ���ο� ��� �߰�
template<typename T>
void Insert(Node<T>*& root, T item)
{
	if (root == NULL)				// root�� null�� ��� 
	{
		root = new Node<T>;	// root ��� ����
		root->left = NULL;			// root ����̹Ƿ� left�� right�� NULL�� ����
		root->right = NULL;
		root->data = item;			// root ����� ��
	}
	else if (root->data > item)		// root�� �����ϰ�, �� ���� ���ο� item ������ Ŭ ��
		Insert(root->left, item);	// root�� �������� Insert �Լ� �ٽ� ȣ��
	else if (root->data < item)		// root�� �����ϰ�, �� ���� ���ο� item ������ ���� ��
		Insert(root->right, item);	// root�� ���������� Insert �Լ� �ٽ� ȣ��
}

// ���� ū ���� ã�� �Լ� 
template<typename T>
void GetPredecessor(Node<T> *root, T& item)
{
	while (root->right != NULL)			// root�� �������� ������ ���
		root = root->right;				// root�� ������ ��尪�� root�� ������ �Ѵ�
	item = root->data;					// root ����� ���� item�� �����Ѵ�.
}

// ������� ��带 ã���� ������ Ʈ������ �� ��带 ����� �Լ�
template<typename T>
void DeleteNode(Node<T> *&root)
{
	T item;
	Node<T>* tempPtr;			// �ӽ� ��带 �����ϰ� root ��带 �ӽ� ��忡 ����
	tempPtr = root;

	if (root->left == NULL)				// ���ʳ�尡 ���� ��
	{
		root = root->right;				// ������ ��尡 root�� �ǵ��� �����ϰ� �ӽó�带 ����
		delete tempPtr;
	}
	else if (root->right == NULL)		// �����ʳ�尡 ���� ��
	{
		root = root->left;				// ���� ��尡 root�� �ǵ��� �����ϰ� �ӽó�带 ����
		delete tempPtr;
	}
	else
	{
		GetPredecessor(root->left, item);	// �߰��� �ִ� ��带 ����� ���� �� (left, right, child ��� ���� ���)
		root->data = item;					// ������� ��庸�� ���� ���� �߿� ���� ū ��带 ã��
		Delete(root->left, item);			// �� ���� ���� ��忡 ���縦 �ؼ� ���� ��ó�� ������
	}
}

// ���� ������� �ϴ� ��带 ã�� recursive �Լ�
template<typename T>
void Delete(Node<T> *&root, T item)
{
	if (item < root->data)				// root��尪���� item��尡 ���� ��
		Delete(root->left, item);		// ���ʳ��� ���� delete�Լ� ȣ��
	else if (item > root->data)			// root��尪���� item��尡 Ŭ ��
		Delete(root->right, item);		// �����ʳ��� ���� delete�Լ� ȣ��
	else
		DeleteNode(root);				// ã���� �ϴ� ���� ��ġ�ϴ� ��� deletenode �Լ� ȣ��
}

// Tree���� node�� �˻��ϴ� �Լ�
template<typename T>
void Retrieve(Node<T> *root, T& item, bool &found)
{
	if (root == NULL)						// root�� NULL�� ��� found�� false 
		found = false;
	else if (item < root->data)				// ã���� �ϴ� �����۰��� root������ ���� �� 
		Retrieve(root->left, item, found);	// ���� ���� ���� retrieve �Լ� ȣ��
	else if (item > root->data)				// ã���� �ϴ� �����۰��� root������ Ŭ ��
		Retrieve(root->right, item, found);	// ������ ���� ���� retrieve �Լ� ȣ��
	else
	{										// ã���� �ϴ� ���� ��ġ�� ��
		item = root->data;					// item�� ��� ������ ����
		found = true;						// found���� true�� �ؼ� ã�� ������ ����
	}
}


// InOrder ������� ����ϴ� �Լ� 
template<typename T>
void PrintInOrderTraversal(Node<T>* root, ostream& out)
{
	if (root != NULL)								// root�� �����ϴ� ���
	{
		PrintInOrderTraversal(root->left, out);		// root�� �������� ���� �ٽ� InOrder �Լ� ȣ��
		out << root->data;							// root�� �� ���										//		out << root->data;							// root ���
		PrintInOrderTraversal(root->right, out);	// root�� ���������� ���� �ٽ� InOrder �Լ� ȣ��
	}
}

// PreOrder ������� ����ϴ� �Լ�
template<typename T>
void PrintPreOrderTraversal(Node<T>* root, ostream& out)
{
	if (root != NULL)								// root�� �����ϴ� ���
	{
		out << root->data;							// root�� ���� ���
		PrintPreOrderTraversal(root->left, out);	// root�� �������� ���� PreOrder �Լ� �ٽ� ȣ��
		PrintPreOrderTraversal(root->right, out);	// root�� ���������� ���� PreOrder �Լ� �ٽ� ȣ��
	}
}

// PostOrder ������� ����ϴ� �Լ�
template<typename T>
void PrintPostOrderTraversal(Node<T>* root, ostream& out)
{
	if (root != NULL)								// root�� �����ϴ� ���
	{
		PrintPostOrderTraversal(root->left, out);	// root�� �������� ���� �ٽ� PostOrder �Լ� ȣ��
		PrintPostOrderTraversal(root->right, out);	// root�� ���������� ���� �ٽ� PostOrder �Լ� ȣ��
		out << root->data;							// root�� �� ���
	}
}

template<typename T>
void GetSuccessor(Node<T>* root, T* &item)
{
	while (root->left != NULL)
		root = root->left;
	item = &(root->data);
}


template<typename T>
void PreOrder(Node<T>* root, CircularQueueType<T>& preQue)
{
	if (root != NULL)
	{
		preQue.EnQueue(root->data);
		PreOrder(root->left, preQue);
		PreOrder(root->right, preQue);
	}
}

template<typename T>
void InOrder(Node<T>* root, CircularQueueType<T>& inQue)
{
	if (root != NULL)
	{

		InOrder(root->left, inQue);
		inQue.EnQueue(root->data);
		InOrder(root->right, inQue);
	}
}

template<typename T>
void PostOrder(Node<T>* root, CircularQueueType<T>& postQue)
{
	if (root != NULL)
	{

		PostOrder(root->left, postQue);
		PostOrder(root->right, postQue);
		postQue.EnQueue(root->data);

	}
}


#endif	// _BINARYSEARCHTREE_H