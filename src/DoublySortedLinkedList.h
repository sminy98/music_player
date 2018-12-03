#pragma once
#include "DoublyIterator.h"

/**
*	@brief	DoublyNodeType ����ü
*/
template <class T>
struct DoublyNodeType
{	//Node�� ����ü
	/**
	*	@brief	�⺻������
	*	@post	��尡 �ʱ�ȭ�ȴ�.
	*/
	DoublyNodeType() :prev(nullptr), next(nullptr) {};

	/**
	*	@brief	����� ���������
	*	@post	�Է¹��� ���� ��尡 deepcopy�ȴ�,
	*/
	DoublyNodeType(const DoublyNodeType<T>& node);
	T data;		///������
	DoublyNodeType *prev;		///������ ����Ű�� ������
	DoublyNodeType *next;		///������ ����Ű�� ������

	/**
	*	@brief	���Կ����� �����ε�
	*	@post	�Է¹��� ���� ��尡 deepcopy�ȴ�.
	*	@return	this�����Ͱ� ��ȯ�ȴ�.
	*/
	DoublyNodeType<T>& operator=(const DoublyNodeType<T>& node);
};

/**
*	@brief	DoublySortedLinkedList Ŭ����.
*/
template <class T>
class DoublySortedLinkedList
{
	friend class DoublyIterator<T>;	//private����� ����ϱ����� ������ ����
public:
	/**
	*	@brief	�⺻������
	*/
	DoublySortedLinkedList();

	DoublySortedLinkedList(const DoublySortedLinkedList<T>& list);

	/**
	*	@brief	�⺻ �Ҹ���
	*/
	~DoublySortedLinkedList();

	/**
	*	@brief	�� item�� ������ �� �ִ��� ��ȯ�� �ִ� �Լ�
	*	@pre	����
	*	@post	����
	*	@return	������ �޸𸮰� �ִٸ� true, ���ٸ� false
	*/
	bool IsFull();

	/**
	*	@brief	Initialize list to empty state.
	*	@pre	None
	*	@post	List is empty.
	*/
	void MakeEmpty();

	/**
	*	@brief	Get number of elements in the list.
	*	@pre	None.
	*	@post	Function value = number of elements in list.
	*	@return	Number of elements in this list.
	*/
	int GetLength() const;

	/**
	*	@brief	Add item into this list.
	*	@pre	List is not full. item is not in list.
	*	@post	Item is inserted in this list.
	*	@return	1 if this function works well, otherwise 0.
	*/
	void Add(T item);

	/**
	*	@brief	����Ʈ���� id�� ��ġ�ϴ� �������� ������
	*	@pre	item���� �Է¹��� item�� operator== �� �����ε� �Ǿ��־�� �Ѵ�.
	*	@post	����Ʈ���� ���ڷ� ���� item�� id�� ��ġ�ϴ� ��带 ã�Ƽ� ����(�Ҵ�����)�Ѵ�.
	*/
	void Delete(T item);

	/**
	*	@brief	����Ʈ���� id�� ��ġ�ϴ� �������� ������
	*	@pre	item���� �Է¹��� item�� operator== �� �����ε� �Ǿ��־�� �Ѵ�.
	*	@post	����Ʈ���� �Է¹��� item���� private key(id)�� �̿��� ������ �������� ã�� �ش� node�� �����Ѵ�.
	*/
	void Replace(T item);

	/**
	*	@brief	�Է¹��� item�� ���� private key(id)�� �̿��� ���̵� ã��
	*	@pre	item���� �Է¹��� item�� operator== �� �����ε� �Ǿ��־�� �Ѵ�.
	*	@post	�Է¹��� item�� private key(id)�� ��ġ�ϴ� �������� ã�´�.
	*	@return	ã���� 1,��ã���� 0�� ��ȯ
	*/
	int Get(T &item);

	/**
	*	@brief	�������� �˻��ϴ� �Լ�
	*	@return	item�� ã���� item�� ������, ��ã���� NULL�� ��ȯ.
	*/
	T* SearchItem(const T& item);

	/**
	*	@brief	����Ʈ�� ��ī�����ִ� ���������
	*	@post	�Է¹��� ����Ʈ�� ��ī���Ѵ�.
	*	@return	this�����Ͱ� ��ȯ�ȴ�.
	*/
	DoublySortedLinkedList<T>& operator=(const DoublySortedLinkedList<T>& list);

private:
	///����Ʈ�� ó���� ����Ŵ
	DoublyNodeType<T> *m_pFirst;
	///����Ʈ�� �������� ����Ŵ
	DoublyNodeType<T> *m_pLast;
	///����Ʈ�� ����ִ� ����� ��
	int m_nLength;
};


//�⺻������
template <typename T>
DoublySortedLinkedList<T>::DoublySortedLinkedList()
{
	m_nLength = 0;
	m_pFirst = NULL;
	m_pLast = NULL;
	return;
}

//���������
template<class T>
 DoublySortedLinkedList<T>::DoublySortedLinkedList(const DoublySortedLinkedList<T>& list)
{
	m_nLength = 0;
	m_pFirst = nullptr;
	DoublyIterator<T> itor(list);
	for ( ;itor.NotNull(); ++itor)
	{
		Add(*itor);
	}
	return;
}

//�⺻ �Ҹ���
template <typename T>
DoublySortedLinkedList<T>::~DoublySortedLinkedList()
{
	MakeEmpty();	//����Ʈ�� �ʱ�ȭ����(�Ҵ�����)
	return;
}

//�� item�� ������ �� �ִ��� ��ȯ�� �ִ� �Լ�
template<class T>
bool DoublySortedLinkedList<T>::IsFull()
{
	DoublyNodeType<T> *location;	//�ӽ� node��ü
	try		//���� �ڵ鸵�� �Ѵ�.
	{
		location = new DoublyNodeType<T>;	//�ӽ� node��ü�� Node�� �����Ҵ�
		delete location;	//�����Ҵ��� Node ����
		return false;	//������ ��ȯ (���� ���� �ʾҴ�)
	}
	castch(bad_alloc exception)	//allocation ���� exception�� ���
	{
		return true;	//���� ��ȯ (���� á��)
	}
}

//����Ʈ�� �ʱ�ȭ����
template<class T>
void DoublySortedLinkedList<T>::MakeEmpty()
{
	DoublyNodeType<T> *pItem;		//Node�ּҸ� ������ �ӽ�������
	DoublyIterator<T> itor(*this);	//�ݺ��ڼ���

	while (itor.NotNull())	//�ݺ��ڰ� �������� �Ѿ������ �ݺ�
	{
		pItem = itor.m_pCurPointer;	//�ӽú����� �ݺ����� ���� �����͸� ����
		itor.Next();	//�ݺ��ڸ� ��������
		delete pItem;	//�ӽ� �����ͷ� ������ ����
	}
	m_pFirst = m_pLast = NULL;	//ó��,���� NULL��
	m_nLength = 0;	//������ 0����
	return;
}

//node�� ������ ��ȯ�� �ִ� �Լ�
template<class T>
int DoublySortedLinkedList<T>::GetLength() const
{
	return m_nLength;	//node�� ������ ��ȯ
}

//node�� �߰��ϴ� �Լ�
template<class T>
void DoublySortedLinkedList<T>::Add(T item)
{
	DoublyNodeType<T> *newNode = new DoublyNodeType<T>;	//������ node�� �����Ҵ�
	newNode->prev = NULL;	//������ NODE�� ������ NULL��
	newNode->next = NULL;	//������ NODE�� ������ NULL��
	newNode->data = item;	//������ Node�� �Է¹��� �������� �Ҵ�

	if (GetLength() == 0)	//����Ʈ�� ����ִٸ�
	{
		m_pFirst = newNode;	//ó�� = ������ node
		m_pLast = newNode;	//������ = ������ node
		m_nLength++;	//node���� ����
		return;
	}

	DoublyIterator<T> iter(*this);	//�ݺ��� ����
	while (iter.NotNull())	//���� �ݺ��ڰ� ����Ű�°� NULL�� �ƴ϶��
	{
		if (iter.GetCurrentNode().data > item)	//���� �����尡 �Է� item���� ũ�ٸ�
		{
			if (iter.m_pCurPointer == m_pFirst)	//ù��°�� ���� �ȴٸ�
			{
				newNode->prev = NULL;	//������ node�� ������ NULL��
				newNode->next = iter.m_pCurPointer;	//������ node�� ������ ���������ͷ�
				iter.m_pCurPointer->prev = newNode;	//������������ ������ ������ node��
				m_pFirst = newNode;	//first�� ������ node��
				m_nLength++;	//������ ������Ŵ
				return;
			}
			//ù��° ���� �ɰ� �ƴ϶��
			newNode->next = iter.m_pCurPointer;	//������ node�� ������ ���������ͷ�
			newNode->prev = iter.m_pCurPointer->prev;	//������ node�� ������ ������������ ��������
			iter.m_pCurPointer->prev->next = newNode;	//���� �������� ������ ������ node��
			iter.m_pCurPointer->prev = newNode;	//���� �������� ������ ������ node��
			m_nLength++;	//���� ����
			return;
		}

		if (iter.m_pCurPointer->next == NULL)	//�������� ���� �Ѵٸ�
		{
			newNode->prev = iter.m_pCurPointer;	//������ node�� ������ ���� �����ͷ�
			newNode->next = NULL;	//������ node�� ������ NULL��
			iter.m_pCurPointer->next = newNode;	//������������ ������ ������ node��
			m_pLast = newNode;	//last�� ������ node��
			m_nLength++;	//���� ����
			return;
		}
		iter.Next();	//�ݺ��ڸ� �������� �Ѱܼ� �ݺ�
	}

	return;
}

//�Է¹��� item�� �����ϴ� �Լ�.
template<class T>
void DoublySortedLinkedList<T>::Delete(T item)
{
	DoublyIterator<T> iter(*this);	//�ݺ��� ����
	while (iter.NotNull())	//Null�� �ƴϸ� �ݺ�
	{
		if (iter.GetCurrentNode().data == item)	//���� ��� �����Ͷ� item�̶� ���ٸ�
		{
			if (iter.m_pCurPointer == m_pFirst)	//���� �����Ϸ��°� ó���̸�
				m_pFirst = iter.m_pCurPointer->next;	//ó���� �����ɷ� ����
			if (iter.m_pCurPointer == m_pLast)	//���� �����Ϸ��°� �������̸�
				m_pLast = iter.m_pCurPointer->prev;		//�������� �����ɷ� ����

			if (iter.m_pCurPointer->prev != NULL)	//�տ� ��尡 �ִٸ�
				iter.m_pCurPointer->prev->next = iter.m_pCurPointer->next;	//�ճ���� next�� �������� next�� ����
			if (iter.m_pCurPointer->next != NULL)	//���� �ڿ� �ִ� ��尡 �ƴ϶��
				iter.m_pCurPointer->next->prev = iter.m_pCurPointer->prev;	//�޳���� prev�� �������� prev�� ����

			delete iter.m_pCurPointer;	//���� ��� ����
			m_nLength--;	//���� ����
			return;
		}
		iter.Next();	//���� ����
	}
	return;
}

//private key(id)�� ��ġ�ϴ� node�� ã�Ƽ� ������
template<class T>
void DoublySortedLinkedList<T>::Replace(T item)
{
	if (Get(item))	//�ش� (id�� ����) �������� ����Ʈ�� �����Ѵٸ�
	{
		Delete(item);	//id�� ��ġ�ϴ� �������� �����ϰ�
		Add(item);	//���� �Է¹��� �������� �߰���
	}
	return;
}

//private key(id)�� ��ġ�ϴ� node�� �ִ��� Ȯ���ϴ� �Լ�.
template<class T>
int DoublySortedLinkedList<T>::Get(T & item)
{
	DoublyIterator<T> iter(*this);	//�ݺ��� ����
	while (iter.NotNull())	//Null�� �ɶ����� �ݺ�
	{
		if (iter.GetCurrentNode().data == item)	//����node�� �������� item�� private key�� ��ġ�ϸ�
			return 1;	//���� ��ȯ
		iter.Next();	//�ݺ��ڸ� �������� �Ѱ� ��� �ݺ�
	}
	return 0;	//��ã�� ������ ��ȯ
}
//�������� �˻��ϴ� �Լ�
template<class T>
T * DoublySortedLinkedList<T>::SearchItem(const T & item)
{
	DoublyNodeType<T>* currentNode = m_pFirst;	//�����带 ó������ ����
	while (currentNode != NULL)	//����Ʈ������ �ݺ�
	{
		if (currentNode->data == item)	//�Է¹��������۰� ���ٸ�
			return &currentNode->data;	//���� ������ �����͸� ��ȯ
		currentNode = currentNode->next;
	}
	return NULL;
}
//���Կ����� �����ε�
template<class T>
DoublySortedLinkedList<T>& DoublySortedLinkedList<T>::operator=(const DoublySortedLinkedList<T>& list)
{
	m_nLength = 0;
	m_pFirst = nullptr;
	DoublyIterator<T> itor(list);
	for (; itor.NotNull(); ++itor)
	{
		Add(*itor);
	}
	return *this;
}

//���������
template<class T>
DoublyNodeType<T>::DoublyNodeType(const DoublyNodeType<T>& node)
{
	data = node.data;	//�����͸� �����س���
	DoublyNodeType<T>* currentNode1;
	DoublyNodeType<T>* currentNode2;

	if (node.next == NULL)	//��(������)����̸�
	{
		next = NULL;	//�ؽ�Ʈ�� NULL
		prev = NULL;
	}
	else
	{
		currentNode2 = new DoublyNodeType<T>;	//�� ��带����
		next = currentNode2;	//next�� ���θ��� ���� ���Ը���
		currentNode2->data = node.next->data;	//���θ��� ����� �����͸� �Է¹��� ����� ���� �����ͷ� ����
		currentNode2->prev = this;
		currentNode1 = node.next->next;	//�ٸ� ��忡 �ٴ��� ���� ����

		while (currentNode1 != NULL)	//�ٴ�����尡 �������϶����� �ݺ�
		{
			currentNode2->next = new DoublyNodeType<T>;	//����带 ����
			currentNode2->next->prev = currentNode2;
			currentNode2 = currentNode2->next;	//���� ���� �̵��Ѵ�
			currentNode2->data = currentNode1->data;	//�̵��� ����� �����͸� �����Ѵ�
			currentNode1 = currentNode1->next;	//�ٴ�����嵵 �̵��Ѵ�.
		}
		currentNode2->next = NULL;	//���� ��带 NULL�� �����Ѵ�.
	}

}

//���Կ����� �����ε�
template<class T>
DoublyNodeType<T>& DoublyNodeType<T>::operator=(const DoublyNodeType<T>& node)
{
	data = node.data;	//�����͸� �����س���
	DoublyNodeType<T>* currentNode1;
	DoublyNodeType<T>* currentNode2;

	if (node.next == NULL)	//��(������)����̸�
	{
		next = NULL;	//�ؽ�Ʈ�� NULL
		prev = NULL;
	}
	else
	{
		currentNode2 = new DoublyNodeType<T>;	//�� ��带����
		next = currentNode2;	//next�� ���θ��� ���� ���Ը���
		currentNode2->data = node.next->data;	//���θ��� ����� �����͸� �Է¹��� ����� ���� �����ͷ� ����
		currentNode2->prev = this;
		currentNode1 = node.next->next;	//�ٸ� ��忡 �ٴ��� ���� ����

		while (currentNode1 != NULL)	//�ٴ�����尡 �������϶����� �ݺ�
		{
			currentNode2->next = new DoublyNodeType<T>;	//����带 ����
			currentNode2->next->prev = currentNode2;
			currentNode2 = currentNode2->next;	//���� ���� �̵��Ѵ�
			currentNode2->data = currentNode1->data;	//�̵��� ����� �����͸� �����Ѵ�
			currentNode1 = currentNode1->next;	//�ٴ�����嵵 �̵��Ѵ�.
		}
		currentNode2->next = NULL;	//���� ��带 NULL�� �����Ѵ�.
	}
	return *this;
}

