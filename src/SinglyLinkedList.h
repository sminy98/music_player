#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include <iostream>
#include <fstream>	
#include <string>
using namespace std;

/**
*	Structure for NodeType to use in Linked structure.
*/
template <typename T>
struct NodeType
{
	T data;	///< A data for each node.
	NodeType* next;	///< A node pointer to point succeed node.
};


/**
*	array based simple unsorted list.
*/
template <typename T>
class SinglyLinkedList
{
public:
	/**
	*	default constructor.
	*/
	SinglyLinkedList()
	{
		m_pLength = 0;
		m_pList = NULL;
		m_pCurPointer = NULL;
	}

	/**
	*	destructor.
	*/
	~SinglyLinkedList() {}

	/**
	*	@brief	Make list empty.
	*	@pre	none.
	*	@post	clear list.
	*/
	void MakeEmpty();

	/**
	*	@brief	Get a number of records in current list.
	*	@pre	none.
	*	@post	none.
	*	@return	number of records in current list.
	*/
	int GetLength();


	/**
	*	@brief	primary key�� �������� ������ �ǵ��� �˸��� �ڸ��� �׸��� �߰��Ѵ�.
	*	@pre	list should be initialized.
	*	@post	added the new record into the list.
	*	@param	data	new data.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int Add(T item);

	/**
	*	@brief	Initialize list iterator.
	*	@pre	list should be initialized.
	*	@post	iterator is reset.
	*/
	void ResetList();

	/**
	*	@brief	move list iterator to the next item in list and get that item.
	*	@pre	list and list iterator should not be initialized.
	*	@post	Iterator is moved to next item.
	*	@param	data	get current iterator's item. it does not need to be initialized.
	*	@return	index of current iterator's item if is not end of list, oterwise return -1.
	*/
	int GetNextItem(T& item);

	/**
	*	@brief	����ڰ� ������ MusicType�� �ش��ϴ� �迭�� �ڸ��� �Ķ������ ������ �����Ѵ�.
	*	@pre	data�� ��� ������ ä�����־�� �Ѵ�.
	*	@post	����ڰ� ������ �׸��� data�� ��������.
	*	@param	data : ��� ������ ä�����ִ� MusicType.
	*	@return	���������� ���������� 1, �ƴϸ� 0�� �����Ѵ�.
	*/
	int Replace(T item);


	/**
	*	@brief	Retrieve list element whose key matches item's key (if present).
	*	@pre	Key member of item is initialized.
	*	@post	If there is an element whose key matches with item's key then the element's record is copied to the item.
	*	@return	1 if any element's primary key matches with item's, otherwise 0.
	*/
	int Get(T& item);

	/**
	*	@brief	����ڰ� ������ MusicType�� �迭���� �����Ѵ�.
	*	@pre	data�� ID ������ ä�����־�� �Ѵ�.
	*	@post	����ڰ� �Է��� �׸��� �����ǰ� length�� 1�پ���.
	*	@param	data : �Ϻθ� ä�����ִ� ItemType.
	*	@return ������ ���������� 1, �ƴϸ� 0�� �����Ѵ�.
	*/
	int Delete(T item);

	NodeType<T>* GetPoint(T& item);


private:
	NodeType<T>* m_pList;
	int m_pLength;				///< number of elements in list.
	NodeType<T>* m_pCurPointer;			///< iterator pointer.
};


// Make list empty.
template <typename T>
void SinglyLinkedList<T>::MakeEmpty()
{
	// ����Ʈ���� ��� ��� ���� �ϰ� ����Ʈ�� length�� �ʱ�ȭ
	NodeType<T>* tempPtr;

	while (m_pList != NULL)
	{
		tempPtr = m_pList;
		m_pList = m_pList->next;
		delete tempPtr;
	}

	m_pLength = 0;
}


// Get a number of records in current list.
template <typename T>
int SinglyLinkedList<T>::GetLength()
{
	return m_pLength;
}

// add a new data into list.
template <typename T>
int SinglyLinkedList<T>::Add(T item)
{
	ResetList();

	// ����Ʈ�� �߰��� ���ο� node ��ü�� ���� ��带 ����ų ������ ����
	NodeType<T> *node = new NodeType<T>;
	NodeType<T> *pre;
	T dummy;
	bool bFound = false;
	// node ��ü�� �Է¹��� ������ ���� �� �ʱ�ȭ
	node->data = item;
	node->next = NULL;


	if (!m_pLength)	//Array�� �ƹ� �׸��� ������ ���� �ʿ� ���� �߰����ش�.
	{
		m_pList = node;
		m_pLength++;
		return 1;	//�׸��� �߰������Ƿ� 1�� �������ش�.
	}


	else	//Array�� ���� �׸��� ������ ��
	{
		// ���� ������ node �� �̵� �� ����
		while (1)
		{
			// ���� ��带 ����Ű�� ������ ����
			pre = m_pCurPointer;

			// iteration �� �̿��� node ������ ����.
			GetNextItem(dummy);

			if (node->data<dummy)  //���� node�� �����Ͱ� �� �۾����� ����; �� ������ �´� ����
			{
				if (pre == NULL)	//��ó������ ���� ���ߵǴ� ���, node�� data���� ���� ������
				{
					node->next = m_pCurPointer;
					m_pList = node;		//��ó������ �ٲ�;
					m_pLength++;
					return 1;
					break;
				}
				else		//�߰��� ���� ���� ����
				{
					pre->next = node;
					node->next = m_pCurPointer;
					m_pLength++;
					return 1;
					break;
				}
			}

			// node �����Ͱ� ������ node �� ����Ű�� �� �ڿ� ���ο� node ����.
			if (m_pCurPointer->next == NULL)
			{
				// ������ node �� ���ο� node ����
				m_pCurPointer->next = node;
				m_pLength++;
				return 1;
				break;
			}
		}
	}
}

// Initialize list iterator.
template <typename T>
void SinglyLinkedList<T>::ResetList()
{
	m_pCurPointer = NULL;
}


// move list pointer to the next item in list and get that item.
template <typename T>
int SinglyLinkedList<T>::GetNextItem(T& item)
{
	// current pointer �� NULL�̶�� ó�� node�� ����Ŵ.
	if (m_pCurPointer == NULL)
	{
		m_pCurPointer = m_pList;
	}
	else
		//current position �� ���� ���� �̵�
		m_pCurPointer = m_pCurPointer->next;

	//item �� current position �� info �� ����
	item = m_pCurPointer->data;
	return 1;
}


//ID���� �����ϴ� data�� (�迭 �ȿ� �����ϴ� �׸�� ��) �˸´� �׸��� ã�� �������ش�.
template <typename T>
int SinglyLinkedList<T>::Get(T& item)
{
	bool moreToSearch, found;
	NodeType<T>* location;

	location = m_pList;
	found = false;
	moreToSearch = (location != NULL);

	while (moreToSearch && !found)
	{
		if (item == location->data)
		{
			found = true;
			item = location->data;
		}
		else
		{
			location = location->next;
			moreToSearch = (location != NULL);
		}
	}

	if (found)
		return 1;
	else
		return 0;
}


//ID���� �����ϴ� data�� �̿��Ͽ� �� ID���� ���� ID�� ������ �ִ� �׸��� �����ְ� length�� 1 ���ش�.
template <typename T>
int SinglyLinkedList<T>::Delete(T item)
{
	NodeType<T> *pre;
	NodeType<T> *toDel;
	ResetList();
	T tmp;
	bool found = false;

	while (1)
	{
		pre = m_pCurPointer;
		GetNextItem(tmp);
		if (tmp == item)		//id���� ��ġ
		{
			if (pre == NULL) //�����ؾ��� ��尡 ��ó���϶�
			{
				toDel = m_pList;	//��� �Űܵΰ� ����
				m_pList = m_pList->next;	//��ó���� �ι�°�ιٲ�
				delete toDel;
				found = true;
				break;
			}
			else
			{
				toDel = m_pCurPointer;
				pre->next = m_pCurPointer->next;	//�� �����Ϳ� ���������͸� ����
				delete toDel;
				found = true;
				break;
			}
		}
		if (m_pCurPointer->next == NULL)	//�Ǹ�����, ������ �ٵ�������
			break;
	}
	m_pLength--;
	if (found)
		return 1;
	else
		return 0;

}

template <typename T>
int SinglyLinkedList<T>::Replace(T item)
{
	NodeType<T> *pre;
	ResetList();
	T isthere = item;
	T tmp;
	bool found = false;
	if (Get(isthere) == 0)   //�ش��ϴ� ���� ������, 0������ ����
		return 0;

	while (1)
	{
		pre = m_pCurPointer; // pre == NULL�� ����
		GetNextItem(tmp);  // tmp�� m_pList�� �ȴ�.tmp == item�� �ɶ����� ���� �ݺ�

		if (tmp == item)         //'=='�����ڸ� id���� ���� �����ε�����.    
		{
			m_pCurPointer->data = item;   //id���� ������ �����͸� ��ü
			found = true;
			break;
		}
		if (m_pCurPointer->next == NULL)   //�Ǹ�����
		{
			found = true;
			break;
		}

	}
	if (found)
		return 1;
	else
		return 0;
}

// move list pointer to the next item in list and get that pointer.
template <typename T>
NodeType<T>* SinglyLinkedList<T>::GetPoint(T& item)
{
	// current pointer �� NULL�̶�� ó�� node�� ����Ŵ.
	if (m_pCurPointer == NULL)
	{
		m_pCurPointer = m_pList;
	}
	else
		//current position �� ���� ���� �̵�
		m_pCurPointer = m_pCurPointer->next;

	//item �� current position �� info �� ����
	item = m_pCurPointer->data;
	return m_pCurPointer;
}


#endif	// LINKED_LIST
