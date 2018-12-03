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
	*	@brief	primary key를 기준으로 정렬이 되도록 알맞은 자리에 항목을 추가한다.
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
	*	@brief	사용자가 지정한 MusicType에 해당하는 배열의 자리에 파라미터의 내용을 복사한다.
	*	@pre	data의 모든 변수가 채워져있어야 한다.
	*	@post	사용자가 지정한 항목이 data와 같아진다.
	*	@param	data : 모든 변수가 채워져있는 MusicType.
	*	@return	성공적으로 수정했으면 1, 아니면 0을 리턴한다.
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
	*	@brief	사용자가 지정한 MusicType을 배열에서 삭제한다.
	*	@pre	data의 ID 변수는 채워져있어야 한다.
	*	@post	사용자가 입력한 항목은 삭제되고 length가 1줄어든다.
	*	@param	data : 일부만 채워져있는 ItemType.
	*	@return 삭제에 성공했으면 1, 아니면 0을 리턴한다.
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
	// 리스트내의 모든 노드 제거 하고 리스트의 length를 초기화
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

	// 리스트에 추가할 새로운 node 객체와 이전 노드를 가리킬 포인터 선언
	NodeType<T> *node = new NodeType<T>;
	NodeType<T> *pre;
	T dummy;
	bool bFound = false;
	// node 객체에 입력받은 데이터 설정 및 초기화
	node->data = item;
	node->next = NULL;


	if (!m_pLength)	//Array에 아무 항목이 없으면 비교할 필요 없이 추가해준다.
	{
		m_pList = node;
		m_pLength++;
		return 1;	//항목을 추가했으므로 1을 리턴해준다.
	}


	else	//Array에 기존 항목이 존재할 때
	{
		// 가장 마지막 node 로 이동 후 삽입
		while (1)
		{
			// 이전 노드를 가리키는 포인터 갱신
			pre = m_pCurPointer;

			// iteration 을 이용해 node 포인터 갱신.
			GetNextItem(dummy);

			if (node->data<dummy)  //값이 node의 데이터가 더 작아지는 순간; 즉 순서에 맞는 순간
			{
				if (pre == NULL)	//맨처음으로 값이 들어가야되는 경우, node의 data값이 가장 작을때
				{
					node->next = m_pCurPointer;
					m_pList = node;		//맨처음으로 바꿈;
					m_pLength++;
					return 1;
					break;
				}
				else		//중간에 값이 들어가는 순간
				{
					pre->next = node;
					node->next = m_pCurPointer;
					m_pLength++;
					return 1;
					break;
				}
			}

			// node 포인터가 마지막 node 를 가리키면 그 뒤에 새로운 node 삽입.
			if (m_pCurPointer->next == NULL)
			{
				// 마지막 node 와 새로운 node 연결
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
	// current pointer 이 NULL이라면 처음 node를 가리킴.
	if (m_pCurPointer == NULL)
	{
		m_pCurPointer = m_pList;
	}
	else
		//current position 을 다음 노드로 이동
		m_pCurPointer = m_pCurPointer->next;

	//item 에 current position 의 info 를 삽입
	item = m_pCurPointer->data;
	return 1;
}


//ID값만 존재하는 data에 (배열 안에 존재하는 항목들 중) 알맞는 항목을 찾아 복사해준다.
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


//ID값만 존재하는 data를 이용하여 그 ID값과 같은 ID를 가지고 있는 항목을 지워주고 length를 1 빼준다.
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
		if (tmp == item)		//id값이 일치
		{
			if (pre == NULL) //삭제해야할 노드가 맨처음일때
			{
				toDel = m_pList;	//잠시 옮겨두고 삭제
				m_pList = m_pList->next;	//맨처음을 두번째로바꿈
				delete toDel;
				found = true;
				break;
			}
			else
			{
				toDel = m_pCurPointer;
				pre->next = m_pCurPointer->next;	//전 포인터와 다음포인터를 연결
				delete toDel;
				found = true;
				break;
			}
		}
		if (m_pCurPointer->next == NULL)	//맨마지막, 루프를 다돌았을때
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
	if (Get(isthere) == 0)   //해당하는 값이 없으면, 0보내고 종료
		return 0;

	while (1)
	{
		pre = m_pCurPointer; // pre == NULL로 시작
		GetNextItem(tmp);  // tmp가 m_pList가 된다.tmp == item이 될때까지 무한 반복

		if (tmp == item)         //'=='연산자를 id값에 대해 오버로딩했음.    
		{
			m_pCurPointer->data = item;   //id값이 같으면 데이터를 대체
			found = true;
			break;
		}
		if (m_pCurPointer->next == NULL)   //맨마지막
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
	// current pointer 이 NULL이라면 처음 node를 가리킴.
	if (m_pCurPointer == NULL)
	{
		m_pCurPointer = m_pList;
	}
	else
		//current position 을 다음 노드로 이동
		m_pCurPointer = m_pCurPointer->next;

	//item 에 current position 의 info 를 삽입
	item = m_pCurPointer->data;
	return m_pCurPointer;
}


#endif	// LINKED_LIST
