#pragma once

template <class T> class DoublySortedLinkedList;	//������� ������ ���ϱ����� ����� ����
template <class T> struct DoublyNodeType;	//������� ������ ���ϱ����� ����� ����

/**
*	@brief	DoublyIterator Ŭ����
*/
template <class T>
class DoublyIterator
{
	friend class DoublySortedLinkedList<T>;	//private���� ������ ���� �����弱��
public:

	/**
	*	@brief	����� ���� ������
	*	@post	list�� m_pCurPointer�� ����Ʈ�� ù �ּҷ� �����.
	*/
	DoublyIterator(const DoublySortedLinkedList<T> &list) :m_List(&list), m_pCurPointer(list.m_pFirst) {};

	/**
	*	@brief	�⺻ �Ҹ���
	*/
	~DoublyIterator();

	/**
	*	@brief	���� �����Ͱ� ����Ű�� ��尡 NULL���� Ȯ���ϴ� �Լ�
	*	@return	���� �����Ͱ� ����Ű�� ��尡 NULL�� �ƴϸ� true,������ true;
	*/
	bool NotNull();

	/**
	*	@brief	���� �����Ͱ� Null���� Ȯ���ϴ� �Լ�
	*	@return	���� �����Ͱ� NULL�̸� true, �ƴϸ� false
	*/
	bool IsNull() { return m_pCurPointer == NULL; }

	/**
	*	@brief	���� �������� ������ ����Ű�� �����Ͱ� NULL���� Ȯ���ϴ� �Լ�
	*	@pre	���� �����Ͱ� NULL�̸� �ȵȴ�
	*	@return	���� �������� ������ ����Ű�� �����Ͱ� NULL�� �ƴϸ� true, NULL�̸� false
	*/
	bool NextNotNull();

	/**
	*	@brief	ù node�� item�� �������ִ� �Լ�
	*	@return	list�� ù node�� item�� ����
	*/
	T First();

	/**
	*	@brief	���� node�� �̵��ϰ� �������� ������ �ִ� �Լ�
	*	@pre	����
	*	@post	���� �����Ͱ� ���� node�� �̵��ϰ� �������� ��ȯ����
	*	@return	���� node�� �̵��ϰ� �ش� node�� �������� ����, �̵��� ������ �̶�� �����Ⱚ�� ��ȯ.
	*/
	T Next();

	/**
	*	@brief	���� Node�� ��ȯ�� �ִ� �Լ�
	*	@pre	����
	*	@post	����
	*	@return	���� Node�� ��ȯ.
	*/
	DoublyNodeType<T> GetCurrentNode();

	/**
	*	@brief	���۷����� ��ȯ�ϴ� *������ �����ε�
	*	@pre	���������Ͱ� ��带 ����Ű�� �־�� �Ѵ�.
	*	@return	���� �������� ������ ���۷����� ��ȯ�ȴ�.
	*/
	T& operator*();

	/**
	*	@brief	���������͸� �������� �Ѿ�� �������������� �����ε�
	*	@pre	���������Ͱ� ��带 ����Ű�� �־�� �Ѵ�.
	*	@post	���������Ͱ� ���� ���� �Ѿ��.
	*	@return	this�����Ͱ� ��ȯ�ȴ�.
	*/
	DoublyIterator<T>& operator++();

	/**
	*	@brief	���������͸� �������� �Ѿ�� �������������� �����ε�
	*	@pre	���������Ͱ� ��带 ����Ű�� �־�� �Ѵ�.
	*	@post	���������Ͱ� ���� ���� �Ѿ��.
	*	@return	�����ϱ��� ����� iterator�� ��ȯ�ȴ�.
	*/
	DoublyIterator<T> operator++(int);

	/**
	*	@brief	���������͸� �������� �Ѿ�� �������ҿ����� �����ε�
	*	@pre	���������Ͱ� ��带 ����Ű�� �־�� �Ѵ�.
	*	@post	���������Ͱ� ���� ���� �Ѿ��.
	*	@return	this�����Ͱ� ��ȯ�ȴ�.
	*/
	DoublyIterator<T>& operator--();

	/**
	*	@brief	���������͸� �������� �Ѿ�� �������ҿ����� �����ε�
	*	@pre	���������Ͱ� ��带 ����Ű�� �־�� �Ѵ�.
	*	@post	���������Ͱ� ���� ���� �Ѿ��.
	*	@return	�����ϱ��� ����� iterator�� ��ȯ�ȴ�.
	*/
	DoublyIterator<T> operator--(int);

	/**
	*	@brief	iterator�񱳸� ���� ==������ �����ε�
	*	@return	iterator�� ������ true, �ٸ��� false�� ��ȯ
	*/
	bool operator==(DoublyIterator<T>& itor);

	/**
	*	@brief	���Կ����� �����ε�
	*	@post	�Ѱܹ��� list�� ���������Ϳ� ����Ʈ�� ����ȴ�.
	*	@return	this�����Ͱ� ��ȯ�ȴ�.
	*/
	DoublyIterator<T>& operator=(DoublySortedLinkedList<T>& list);
private:
	///����� ����Ʈ�� ���� ����
	const DoublySortedLinkedList<T>* m_List;
	///iterator ����
	DoublyNodeType<T> *m_pCurPointer;
};

//�⺻ �Ҹ���
template <class T>
DoublyIterator<T>::~DoublyIterator()
{
}

//���� �����Ͱ� ����Ű�� ��尡 NULL���� Ȯ���ϴ� �Լ�
template<class T>
bool DoublyIterator<T>::NotNull()
{
	return m_pCurPointer != NULL;	//���� �����Ͱ� NULL�̸� true,�ƴϸ� false
}

//���� �������� ������ ����Ű�� �����Ͱ� NULL���� Ȯ���ϴ� �Լ�
template<class T>
bool DoublyIterator<T>::NextNotNull()
{
	return m_pCurPointer->next != NULL;	//���� �������� ������ NULL�̸� true, �ƴϸ� false
}

//ù node�� item�� �������ִ� �Լ�
template<class T>
T DoublyIterator<T>::First()
{
	return m_List.m_pFirst->data;	//ó���� ����Ű�� ���� ��ȯ
}

//���� node�� �̵��ϰ� �������� ������ �ִ� �Լ�
template<class T>
T DoublyIterator<T>::Next()
{
	m_pCurPointer = m_pCurPointer->next;	//�������� �����͸� �̵�
	if (m_pCurPointer == NULL)	//�̵��� �����Ͱ� NULL(������)�̶��
		return T();	//�����Ⱚ ��ȯ
	return m_pCurPointer->data;	//���� �����Ͱ� ����Ű�� �����͸� ��ȯ
}

//���� Node�� ��ȯ�� �ִ� �Լ�
template<class T>
DoublyNodeType<T> DoublyIterator<T>::GetCurrentNode()
{
	return *m_pCurPointer;	//���������Ͱ� ����Ű�� Node�� �����ؼ� ��ȯ
}

//������������ �������� ���۷����� ��ȯ�ϴ� ������ �����ε�
template<class T>
T & DoublyIterator<T>::operator*()
{
	return m_pCurPointer->data;
}

//�������������� �����ε�
template<class T>
DoublyIterator<T>& DoublyIterator<T>::operator++()
{
	m_pCurPointer = m_pCurPointer->next;
	return *this;
}

//�������������� �����ε�
template<class T>
DoublyIterator<T> DoublyIterator<T>::operator++(int)
{
	DoublyIterator<T> temporaryItem = *this;
	m_pCurPointer = m_pCurPointer->next;
	return temporaryItem;	//�ӽð�ü�� ��ȯ�Ѵ�.
}

//�������ҿ����� �����ε�
template<class T>
DoublyIterator<T>& DoublyIterator<T>::operator--()
{
	m_pCurPointer = m_pCurPointer->prev;
	return *this;
}

//�������ҿ����� �����ε�
template<class T>
DoublyIterator<T> DoublyIterator<T>::operator--(int)
{
	DoublyIterator<T> temporaryItem = *this;
	m_pCurPointer = m_pCurPointer->prev;
	return temporaryItem;	//�ӽð�ü�� ��ȯ�Ѵ�.
}

//�񱳿����� �����ε�
template<class T>
 bool DoublyIterator<T>::operator==(DoublyIterator<T>& itor)
{
	return itor.m_pCurPointer == m_pCurPointer;
}

//���Կ����� �����ε�
template<class T>
 DoublyIterator<T>& DoublyIterator<T>::operator=(DoublySortedLinkedList<T>& list)
{
	m_pCurPointer = list.m_pFirst;
	m_List = &list;
	return *this;
}

