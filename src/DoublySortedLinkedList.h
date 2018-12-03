#pragma once
#include "DoublyIterator.h"

/**
*	@brief	DoublyNodeType 구조체
*/
template <class T>
struct DoublyNodeType
{	//Node의 구조체
	/**
	*	@brief	기본생성자
	*	@post	노드가 초기화된다.
	*/
	DoublyNodeType() :prev(nullptr), next(nullptr) {};

	/**
	*	@brief	노드의 복사생성자
	*	@post	입력받은 노드로 노드가 deepcopy된다,
	*/
	DoublyNodeType(const DoublyNodeType<T>& node);
	T data;		///데이터
	DoublyNodeType *prev;		///다음을 가리키는 포인터
	DoublyNodeType *next;		///이전을 가리키는 포인터

	/**
	*	@brief	대입연산자 오버로딩
	*	@post	입력받은 노드로 노드가 deepcopy된다.
	*	@return	this포인터가 반환된다.
	*/
	DoublyNodeType<T>& operator=(const DoublyNodeType<T>& node);
};

/**
*	@brief	DoublySortedLinkedList 클래스.
*/
template <class T>
class DoublySortedLinkedList
{
	friend class DoublyIterator<T>;	//private멤버를 사용하기위한 프렌드 선언
public:
	/**
	*	@brief	기본생성자
	*/
	DoublySortedLinkedList();

	DoublySortedLinkedList(const DoublySortedLinkedList<T>& list);

	/**
	*	@brief	기본 소멸자
	*/
	~DoublySortedLinkedList();

	/**
	*	@brief	더 item을 생성할 수 있는지 반환해 주는 함수
	*	@pre	없음
	*	@post	없음
	*	@return	생성할 메모리가 있다면 true, 없다면 false
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
	*	@brief	리스트에서 id가 일치하는 아이템을 제거함
	*	@pre	item으로 입력받은 item의 operator== 이 오버로딩 되어있어야 한다.
	*	@post	리스트에서 인자로 받은 item의 id와 일치하는 노드를 찾아서 제거(할당해제)한다.
	*/
	void Delete(T item);

	/**
	*	@brief	리스트에서 id가 일치하는 아이템을 변경함
	*	@pre	item으로 입력받은 item의 operator== 이 오버로딩 되어있어야 한다.
	*	@post	리스트에서 입력받은 item으로 private key(id)를 이용해 동일한 아이템을 찾아 해당 node를 변경한다.
	*/
	void Replace(T item);

	/**
	*	@brief	입력받은 item을 통해 private key(id)를 이용해 아이디를 찾음
	*	@pre	item으로 입력받은 item의 operator== 이 오버로딩 되어있어야 한다.
	*	@post	입력받은 item과 private key(id)가 일치하는 아이템을 찾는다.
	*	@return	찾으면 1,못찾으면 0을 반환
	*/
	int Get(T &item);

	/**
	*	@brief	아이템을 검색하는 함수
	*	@return	item을 찾으면 item의 포인터, 못찾으면 NULL을 반환.
	*/
	T* SearchItem(const T& item);

	/**
	*	@brief	리스트를 딥카피해주는 복사생성자
	*	@post	입력받은 리스트를 딥카피한다.
	*	@return	this포인터가 반환된다.
	*/
	DoublySortedLinkedList<T>& operator=(const DoublySortedLinkedList<T>& list);

private:
	///리스트의 처음을 가리킴
	DoublyNodeType<T> *m_pFirst;
	///리스트의 마지막을 가리킴
	DoublyNodeType<T> *m_pLast;
	///리스트에 들어있는 노드의 수
	int m_nLength;
};


//기본생성자
template <typename T>
DoublySortedLinkedList<T>::DoublySortedLinkedList()
{
	m_nLength = 0;
	m_pFirst = NULL;
	m_pLast = NULL;
	return;
}

//복사생성자
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

//기본 소멸자
template <typename T>
DoublySortedLinkedList<T>::~DoublySortedLinkedList()
{
	MakeEmpty();	//리스트를 초기화해줌(할당해제)
	return;
}

//더 item을 생성할 수 있는지 반환해 주는 함수
template<class T>
bool DoublySortedLinkedList<T>::IsFull()
{
	DoublyNodeType<T> *location;	//임시 node객체
	try		//에러 핸들링을 한다.
	{
		location = new DoublyNodeType<T>;	//임시 node객체에 Node를 동적할당
		delete location;	//동적할당한 Node 제거
		return false;	//거짓을 반환 (가득 차지 않았다)
	}
	castch(bad_alloc exception)	//allocation 관련 exception일 경우
	{
		return true;	//참을 반환 (가득 찼다)
	}
}

//리스트를 초기화해줌
template<class T>
void DoublySortedLinkedList<T>::MakeEmpty()
{
	DoublyNodeType<T> *pItem;		//Node주소를 저장할 임시포인터
	DoublyIterator<T> itor(*this);	//반복자선언

	while (itor.NotNull())	//반복자가 마지막을 넘어갈때까지 반복
	{
		pItem = itor.m_pCurPointer;	//임시변수에 반복자의 현재 포인터를 넣음
		itor.Next();	//반복자를 다음으로
		delete pItem;	//임시 포인터로 아이템 제거
	}
	m_pFirst = m_pLast = NULL;	//처음,끝을 NULL로
	m_nLength = 0;	//개수를 0으로
	return;
}

//node의 개수를 반환해 주는 함수
template<class T>
int DoublySortedLinkedList<T>::GetLength() const
{
	return m_nLength;	//node의 개수를 반환
}

//node를 추가하는 함수
template<class T>
void DoublySortedLinkedList<T>::Add(T item)
{
	DoublyNodeType<T> *newNode = new DoublyNodeType<T>;	//삽입할 node를 동적할당
	newNode->prev = NULL;	//생성된 NODE의 이전을 NULL로
	newNode->next = NULL;	//생성된 NODE의 다음을 NULL로
	newNode->data = item;	//생성된 Node에 입력받은 아이템을 할당

	if (GetLength() == 0)	//리스트가 비어있다면
	{
		m_pFirst = newNode;	//처음 = 생성된 node
		m_pLast = newNode;	//마지막 = 생성된 node
		m_nLength++;	//node개수 증가
		return;
	}

	DoublyIterator<T> iter(*this);	//반복자 선언
	while (iter.NotNull())	//만약 반복자가 가리키는게 NULL이 아니라면
	{
		if (iter.GetCurrentNode().data > item)	//만약 현재노드가 입력 item보다 크다면
		{
			if (iter.m_pCurPointer == m_pFirst)	//첫번째에 들어가야 된다면
			{
				newNode->prev = NULL;	//생성된 node의 이전을 NULL로
				newNode->next = iter.m_pCurPointer;	//생성된 node의 다음을 현재포인터로
				iter.m_pCurPointer->prev = newNode;	//현재포인터의 이전을 생성된 node로
				m_pFirst = newNode;	//first를 생성된 node로
				m_nLength++;	//개수를 증가시킴
				return;
			}
			//첫번째 들어가야 될게 아니라면
			newNode->next = iter.m_pCurPointer;	//생성된 node의 다음을 현재포인터로
			newNode->prev = iter.m_pCurPointer->prev;	//생성된 node의 이전을 현재포인터의 이전으로
			iter.m_pCurPointer->prev->next = newNode;	//이전 포인터의 다음을 생성된 node로
			iter.m_pCurPointer->prev = newNode;	//현재 포인터의 이전을 생성된 node로
			m_nLength++;	//개수 증가
			return;
		}

		if (iter.m_pCurPointer->next == NULL)	//마지막에 들어가야 한다면
		{
			newNode->prev = iter.m_pCurPointer;	//생성된 node의 이전을 현재 포인터로
			newNode->next = NULL;	//생성된 node의 다음을 NULL로
			iter.m_pCurPointer->next = newNode;	//현재포인터의 다음을 생성된 node로
			m_pLast = newNode;	//last를 생성된 node로
			m_nLength++;	//개수 증가
			return;
		}
		iter.Next();	//반복자를 다음으로 넘겨서 반복
	}

	return;
}

//입력받은 item을 제거하는 함수.
template<class T>
void DoublySortedLinkedList<T>::Delete(T item)
{
	DoublyIterator<T> iter(*this);	//반복자 선언
	while (iter.NotNull())	//Null이 아니면 반복
	{
		if (iter.GetCurrentNode().data == item)	//현재 노드 데이터랑 item이랑 같다면
		{
			if (iter.m_pCurPointer == m_pFirst)	//만약 제거하려는게 처음이면
				m_pFirst = iter.m_pCurPointer->next;	//처음을 다음걸로 설정
			if (iter.m_pCurPointer == m_pLast)	//만약 제거하려는게 마지막이면
				m_pLast = iter.m_pCurPointer->prev;		//마지막을 이전걸로 설정

			if (iter.m_pCurPointer->prev != NULL)	//앞에 노드가 있다면
				iter.m_pCurPointer->prev->next = iter.m_pCurPointer->next;	//앞노드의 next를 현재노드의 next로 설정
			if (iter.m_pCurPointer->next != NULL)	//제일 뒤에 있는 노드가 아니라면
				iter.m_pCurPointer->next->prev = iter.m_pCurPointer->prev;	//뒷노드의 prev를 현재노드의 prev로 설정

			delete iter.m_pCurPointer;	//현재 노드 삭제
			m_nLength--;	//개수 감소
			return;
		}
		iter.Next();	//다음 노드로
	}
	return;
}

//private key(id)가 일치하는 node를 찾아서 변경함
template<class T>
void DoublySortedLinkedList<T>::Replace(T item)
{
	if (Get(item))	//해당 (id를 가진) 아이템이 리스트에 존재한다면
	{
		Delete(item);	//id가 일치하는 아이템을 제거하고
		Add(item);	//새로 입력받은 아이템을 추가함
	}
	return;
}

//private key(id)가 일치하는 node가 있는지 확인하는 함수.
template<class T>
int DoublySortedLinkedList<T>::Get(T & item)
{
	DoublyIterator<T> iter(*this);	//반복자 선언
	while (iter.NotNull())	//Null이 될때까지 반복
	{
		if (iter.GetCurrentNode().data == item)	//현재node의 아이템이 item과 private key가 일치하면
			return 1;	//참을 반환
		iter.Next();	//반복자를 다음으로 넘겨 계속 반복
	}
	return 0;	//못찾음 거짓을 반환
}
//아이템을 검색하는 함수
template<class T>
T * DoublySortedLinkedList<T>::SearchItem(const T & item)
{
	DoublyNodeType<T>* currentNode = m_pFirst;	//현재노드를 처음으로 설정
	while (currentNode != NULL)	//리스트끝까지 반복
	{
		if (currentNode->data == item)	//입력받은아이템과 같다면
			return &currentNode->data;	//현재 데이터 포인터를 반환
		currentNode = currentNode->next;
	}
	return NULL;
}
//대입연산자 오버로딩
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

//복사생성자
template<class T>
DoublyNodeType<T>::DoublyNodeType(const DoublyNodeType<T>& node)
{
	data = node.data;	//데이터를 복사해놓음
	DoublyNodeType<T>* currentNode1;
	DoublyNodeType<T>* currentNode2;

	if (node.next == NULL)	//끝(마지막)노드이면
	{
		next = NULL;	//넥스트는 NULL
		prev = NULL;
	}
	else
	{
		currentNode2 = new DoublyNodeType<T>;	//새 노드를만듬
		next = currentNode2;	//next를 새로만든 노드랑 같게만듬
		currentNode2->data = node.next->data;	//새로만든 노드의 데이터를 입력받은 노드의 다음 데이터로 설정
		currentNode2->prev = this;
		currentNode1 = node.next->next;	//다른 노드에 다다음 노드로 설정

		while (currentNode1 != NULL)	//다다음노드가 마지막일때까지 반복
		{
			currentNode2->next = new DoublyNodeType<T>;	//새노드를 만듬
			currentNode2->next->prev = currentNode2;
			currentNode2 = currentNode2->next;	//다음 노드로 이동한다
			currentNode2->data = currentNode1->data;	//이동한 노드의 데이터를 설정한다
			currentNode1 = currentNode1->next;	//다다음노드도 이동한다.
		}
		currentNode2->next = NULL;	//다음 노드를 NULL로 설정한다.
	}

}

//대입연산자 오버로딩
template<class T>
DoublyNodeType<T>& DoublyNodeType<T>::operator=(const DoublyNodeType<T>& node)
{
	data = node.data;	//데이터를 복사해놓음
	DoublyNodeType<T>* currentNode1;
	DoublyNodeType<T>* currentNode2;

	if (node.next == NULL)	//끝(마지막)노드이면
	{
		next = NULL;	//넥스트는 NULL
		prev = NULL;
	}
	else
	{
		currentNode2 = new DoublyNodeType<T>;	//새 노드를만듬
		next = currentNode2;	//next를 새로만든 노드랑 같게만듬
		currentNode2->data = node.next->data;	//새로만든 노드의 데이터를 입력받은 노드의 다음 데이터로 설정
		currentNode2->prev = this;
		currentNode1 = node.next->next;	//다른 노드에 다다음 노드로 설정

		while (currentNode1 != NULL)	//다다음노드가 마지막일때까지 반복
		{
			currentNode2->next = new DoublyNodeType<T>;	//새노드를 만듬
			currentNode2->next->prev = currentNode2;
			currentNode2 = currentNode2->next;	//다음 노드로 이동한다
			currentNode2->data = currentNode1->data;	//이동한 노드의 데이터를 설정한다
			currentNode1 = currentNode1->next;	//다다음노드도 이동한다.
		}
		currentNode2->next = NULL;	//다음 노드를 NULL로 설정한다.
	}
	return *this;
}

