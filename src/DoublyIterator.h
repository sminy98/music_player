#pragma once

template <class T> class DoublySortedLinkedList;	//교차헤더 포함을 피하기위한 명시적 선언
template <class T> struct DoublyNodeType;	//교차헤더 포함을 피하기위한 명시적 선언

/**
*	@brief	DoublyIterator 클래스
*/
template <class T>
class DoublyIterator
{
	friend class DoublySortedLinkedList<T>;	//private변수 접근을 위한 프렌드선언
public:

	/**
	*	@brief	사용자 정의 생성자
	*	@post	list와 m_pCurPointer를 리스트의 첫 주소로 만든다.
	*/
	DoublyIterator(const DoublySortedLinkedList<T> &list) :m_List(&list), m_pCurPointer(list.m_pFirst) {};

	/**
	*	@brief	기본 소멸자
	*/
	~DoublyIterator();

	/**
	*	@brief	현재 포인터가 가리키는 노드가 NULL인지 확인하는 함수
	*	@return	현재 포인터가 가리키는 노드가 NULL이 아니면 true,맞으면 true;
	*/
	bool NotNull();

	/**
	*	@brief	현재 포인터가 Null인지 확인하는 함수
	*	@return	현재 포인터가 NULL이면 true, 아니면 false
	*/
	bool IsNull() { return m_pCurPointer == NULL; }

	/**
	*	@brief	현재 포인터의 다음을 가리키는 포인터가 NULL인지 확인하는 함수
	*	@pre	현재 포인터가 NULL이면 안된다
	*	@return	현재 포인터의 다음을 가리키는 포인터가 NULL이 아니면 true, NULL이면 false
	*/
	bool NextNotNull();

	/**
	*	@brief	첫 node의 item을 리턴해주는 함수
	*	@return	list의 첫 node의 item을 리턴
	*/
	T First();

	/**
	*	@brief	다음 node로 이동하고 아이템을 리턴해 주는 함수
	*	@pre	없음
	*	@post	현재 포인터가 다음 node로 이동하고 아이템을 반환해줌
	*	@return	다음 node로 이동하고 해당 node의 아이템을 리턴, 이동후 마지막 이라면 쓰레기값을 반환.
	*/
	T Next();

	/**
	*	@brief	현재 Node를 반환해 주는 함수
	*	@pre	없음
	*	@post	없음
	*	@return	현재 Node를 반환.
	*/
	DoublyNodeType<T> GetCurrentNode();

	/**
	*	@brief	레퍼런스를 반환하는 *연산자 오버로딩
	*	@pre	현재포인터가 노드를 가르키고 있어야 한다.
	*	@return	현재 포인터의 데이터 레퍼런스가 반환된다.
	*/
	T& operator*();

	/**
	*	@brief	현재포인터를 다음으로 넘어가는 전위증가연산자 오버로딩
	*	@pre	현재포인터가 노드를 가르키고 있어야 한다.
	*	@post	현재포인터가 다음 노드로 넘어간다.
	*	@return	this포인터가 반환된다.
	*/
	DoublyIterator<T>& operator++();

	/**
	*	@brief	현재포인터를 다음으로 넘어가는 후위증가연산자 오버로딩
	*	@pre	현재포인터가 노드를 가르키고 있어야 한다.
	*	@post	현재포인터가 다음 노드로 넘어간다.
	*	@return	증가하기전 복사된 iterator가 반환된다.
	*/
	DoublyIterator<T> operator++(int);

	/**
	*	@brief	현재포인터를 이전으로 넘어가는 전위감소연산자 오버로딩
	*	@pre	현재포인터가 노드를 가르키고 있어야 한다.
	*	@post	현재포인터가 이전 노드로 넘어간다.
	*	@return	this포인터가 반환된다.
	*/
	DoublyIterator<T>& operator--();

	/**
	*	@brief	현재포인터를 이전으로 넘어가는 후위감소연산자 오버로딩
	*	@pre	현재포인터가 노드를 가르키고 있어야 한다.
	*	@post	현재포인터가 이전 노드로 넘어간다.
	*	@return	감소하기전 복사된 iterator가 반환된다.
	*/
	DoublyIterator<T> operator--(int);

	/**
	*	@brief	iterator비교를 위한 ==연산자 오버로딩
	*	@return	iterator가 같으면 true, 다르면 false를 반환
	*/
	bool operator==(DoublyIterator<T>& itor);

	/**
	*	@brief	대입연산자 오버로딩
	*	@post	넘겨받은 list로 현재포인터와 리스트가 변경된다.
	*	@return	this포인터가 반환된다.
	*/
	DoublyIterator<T>& operator=(DoublySortedLinkedList<T>& list);
private:
	///사용할 리스트의 참조 변수
	const DoublySortedLinkedList<T>* m_List;
	///iterator 변수
	DoublyNodeType<T> *m_pCurPointer;
};

//기본 소멸자
template <class T>
DoublyIterator<T>::~DoublyIterator()
{
}

//현재 포인터가 가리키는 노드가 NULL인지 확인하는 함수
template<class T>
bool DoublyIterator<T>::NotNull()
{
	return m_pCurPointer != NULL;	//현재 포인터가 NULL이면 true,아니면 false
}

//현재 포인터의 다음을 가리키는 포인터가 NULL인지 확인하는 함수
template<class T>
bool DoublyIterator<T>::NextNotNull()
{
	return m_pCurPointer->next != NULL;	//현재 포인터의 다음이 NULL이면 true, 아니면 false
}

//첫 node의 item을 리턴해주는 함수
template<class T>
T DoublyIterator<T>::First()
{
	return m_List.m_pFirst->data;	//처음을 가리키는 것을 반환
}

//다음 node로 이동하고 아이템을 리턴해 주는 함수
template<class T>
T DoublyIterator<T>::Next()
{
	m_pCurPointer = m_pCurPointer->next;	//다음으로 포인터를 이동
	if (m_pCurPointer == NULL)	//이동후 포인터가 NULL(마지막)이라면
		return T();	//쓰레기값 반환
	return m_pCurPointer->data;	//현재 포인터가 가리키는 데이터를 반환
}

//현재 Node를 반환해 주는 함수
template<class T>
DoublyNodeType<T> DoublyIterator<T>::GetCurrentNode()
{
	return *m_pCurPointer;	//현재포인터가 가리키는 Node를 복사해서 반환
}

//현재포인터의 데이터의 레퍼런스를 반환하는 연산자 오버로딩
template<class T>
T & DoublyIterator<T>::operator*()
{
	return m_pCurPointer->data;
}

//전위증가연산자 오버로딩
template<class T>
DoublyIterator<T>& DoublyIterator<T>::operator++()
{
	m_pCurPointer = m_pCurPointer->next;
	return *this;
}

//후위증가연산자 오버로딩
template<class T>
DoublyIterator<T> DoublyIterator<T>::operator++(int)
{
	DoublyIterator<T> temporaryItem = *this;
	m_pCurPointer = m_pCurPointer->next;
	return temporaryItem;	//임시객체를 반환한다.
}

//전위감소연산자 오버로딩
template<class T>
DoublyIterator<T>& DoublyIterator<T>::operator--()
{
	m_pCurPointer = m_pCurPointer->prev;
	return *this;
}

//후위감소연산자 오버로딩
template<class T>
DoublyIterator<T> DoublyIterator<T>::operator--(int)
{
	DoublyIterator<T> temporaryItem = *this;
	m_pCurPointer = m_pCurPointer->prev;
	return temporaryItem;	//임시객체를 반환한다.
}

//비교연산자 오버로딩
template<class T>
 bool DoublyIterator<T>::operator==(DoublyIterator<T>& itor)
{
	return itor.m_pCurPointer == m_pCurPointer;
}

//대입연산자 오버로딩
template<class T>
 DoublyIterator<T>& DoublyIterator<T>::operator=(DoublySortedLinkedList<T>& list)
{
	m_pCurPointer = list.m_pFirst;
	m_List = &list;
	return *this;
}

