#pragma once
#include <iostream>
using namespace std;

#define maxsize 31

/**
*   @brief   Exception class thrown by Push when stack is full.
*/
class FullStack
{
public:
   /**
   *   @brief   Display a message for full stack on screen.
   */
   void print()
   {
      cout << "FullStack exception thrown." << endl;
   }
};

/**
*   @brief   Exception class thrown by Pop and Top when stack is empty.
*/
class EmptyStack
{
public:
   /**
   *   @brief   Display a message for full stack on screen.
   */
   void print()
   {
      cout << "EmtpyStack exception thrown." << endl;
   }
};

template <typename T>   //generic data�� ���� template ����
class CircularQueueType
{
public:
   /**
   *   @brief   size�� �ش��ϴ� ũ���� �迭�� �����Ҵ�
   *   @post   size�� ���� �ش�Ǵ� ũ���� �迭�� �������,�� ����������� �ʱ�ȭ��
   */
   CircularQueueType(int size);
   /**
   *   @brief   �ִ�ũ��� ����
   *   @pre   �ִ�ũ�Ⱑ ����������
   *   @post   �ִ�ũ���� �迭�� ���������, �� ����������� �ʱ�ȭ��
   */
   CircularQueueType(void);

   ~CircularQueueType(void);


   /**
   *   @brief   queue�� �������ִ��� Ȯ��.
   *   @pre   queue�� �ʱ�ȭ �Ǿ����.
   *   @post   �������� ture �ƴϸ� false
   */
   bool IsFull() const; // �б����� �Լ�, ����� ���� ��ο��� const ����Ѵ�. 

                   /**
                   *   @brief   queue�� ����ִ��� Ȯ��
                   *   @pre   queue�� �ʱ�ȭ �Ǿ����.
                   *   @post   ��������� ture �ƴϸ� false
                   */
   bool IsEmpty() const;

   /**
   *   @brief   queue�� ȸ���ϸ鼭 ���� ä��.
   *   @pre   queue�� �ʱ�ȭ �Ǿ����
   *   @post   ������������ FullStack Exception�� throw��, �ƴϸ� ���ο� ���� �߰���,rear�� ����
   */
   void EnQueue(T item);

   /**
   *   @brief   queue�� ȸ���ϸ鼭 ���� ����(=front���� �ϳ� ����)
   *   @pre   Stack has been initialized.
   *   @post   ��������� empty Exception�� throw;�ƴϸ� ������ ���� ����
   */
   void DeQueue(T& item);

   /**
   *   @brief   Returns a copy of top item on the stack.
   *   @pre   Stack has been initialized.
   *   @post   If (stack is empty), EmptyStack exception is thrown; otherwise, top element has been removed from stack.
   */
   T Top();

   /**
   *   @brief   Print all the items in the stack on screen
   *   @pre   Stack has been initialized.
   *   @post   None.
   */
   void Print();
   void MakeEmpty();

   /**
   *   @brief   Get music key
   *   @pre   music key is set.
   *   @post   none.
   *   @return   music key.
   */
   int GetKey()
   {
      return r_Key;
   }


   /**
   *   @brief   Get music title
   *   @pre   music title is set.
   *   @post   none.
   *   @return   music title.
   */
   string GetTitle()
   {
      return r_sTitle;
   }

   /**
   *   @brief   Set music Key.
   *   @pre   none.
   *   @post   music Key is set.
   *   @param   inTitle   music Key.
   */
   void SetKey(int inKey)
   {
      r_Key = inKey;
   }


   /**
   *   @brief   Set music Title.
   *   @pre   none.
   *   @post   music Title is set.
   *   @param   inTitle   music Title.
   */
   void SetTitle(string inTitle)
   {
      r_sTitle = inTitle;
   }

   /**
   *   @brief ���� �ε����� �����Ѵ�.
   *   @pre   �ʱ�ȭ�Ǿ� �־�� �Ѵ�.
   *   @post  ���� �ε����� �Ѿ��.
   */
   int GetNextItem(T& data);


   /**
   *   @brief  Queue�� �ʱ�ȭ �����ش�.
   *   @pre   ����
   *   @post   m_CurPointer�� m_iFront +1�� �ٲ۴�.
   */
   void ResetQueue();

   /**
   *   Compare two MusicTypes.
   *   @brief   Compare two item types by item key.
   *   @pre   two item types should be initialized.
   *   @post   the target file is included the new item record.
   *   @param   data   target item for comparing.
   *   @return   return LESS if this.key < data.key,
   *         return GREATER if this.key > data.key then,
   *         otherwise return EQUAL.
   */
   T CompareByKey(const T &data);

   /**
   *   @brief top�� �����´�.
   *   @pre   ����
   *   @post  top�� ����� �� ����
   */
   int GetTop();

private:
   int m_iFront;
   int m_iRear;
   int m_nMaxQueue;
   int top;   ///< Number of elements.
   T *items;   ///< Pointer for a stack.
   int r_CurPointer;

};

template <typename T>
CircularQueueType<T>::CircularQueueType(int size)
{
   items = new T[size];   //T�� �ڷ������� �����Ҵ�
   m_iFront = size - 1;
   m_iRear = size - 1;
   m_nMaxQueue = size;
   //top = -1;
   top = 0;
}
template <typename T>
CircularQueueType<T>::CircularQueueType()
{
   items = new T[maxsize];
   m_iFront = maxsize - 1;
   m_iRear = maxsize - 1;
   m_nMaxQueue = maxsize;
   top = -1;
   top = 0;
}


// Destruct the object. Free the array dynamically allocated.
template <typename T>
CircularQueueType<T>::~CircularQueueType()
{
   delete[] items;
}


// Determines whether the CircularQueueType is full.
template <typename T>
bool CircularQueueType<T>::IsEmpty() const
{
   if (m_iRear == m_iFront)
      return true;
   else
      return false;
}


// Determines whether the CircularQueueType is empty.
template <typename T>
bool CircularQueueType<T>::IsFull() const
{

   if ((m_iRear + 1) % m_nMaxQueue == m_iFront)   //rear�� ����ĭ�� front���� �ƴ��� �˻�
      return true;
   else
      return false;

}


// Adds newItem to the top of the CircularQueueType.
template <typename T>
void CircularQueueType<T>::EnQueue(T newItem)
{
   if (IsFull())
   {
      m_iFront = (m_iFront + 1) % m_nMaxQueue;
      top--;
   }
   //throw FullStack();

   m_iRear = (m_iRear + 1) % m_nMaxQueue;
   items[m_iRear%m_nMaxQueue] = newItem;
   //items[m_iRear] = newItem;
   top++;
}


// Removes top item from the CircularQueueType.
template <typename T>
void CircularQueueType<T>::DeQueue(T& item)
{
   top--;
//   if (IsEmpty())         //����ִ��� �˻�
//     throw EmptyStack();
//   else
//   {
      m_iFront = (m_iFront + 1) % m_nMaxQueue; //front�� ������ ��ĭ �̵�
      item = items[m_iFront];   //��������, ���ٵ��� ���� ���� �˱����ؼ� item�� �ش� ���� ����

//   }
}


// Removes top item from the CircularQueueType.
template <typename T>
T CircularQueueType<T>::Top()
{
   if (IsEmpty())
      throw EmptyStack();
   else
      return items[top];
}

// top�� �����´�. 
template <typename T>
int CircularQueueType<T>::GetTop()
{
   return top;
}


// Print all the items in the CircularQueueType on screen
template <typename T>
void CircularQueueType<T>::Print()
{
   if (IsEmpty())            //������� it is empty���. Empty Stack�� throw�ϸ� ���α׷��� ����Ǿ �ٽ� Enqueue�Ҽ������Ƿ�
      cout << "It is empty!" << endl;            //�ε����ϰ� ���ο� ����ó��
   else
   {
      cout << "CircularQueueType: ";
      // CircularQueueType ���Ǹ��element ���.
      int first = m_iFront;
      int last = m_iRear;
      while (first != last)            //Rear���� front�� ���� �������ȸ�. front�� �����ؼ� ���� �ϳ��� ���.Enqueue�ϸ� rear�� front�� ���� �ռ������Ƿ�
      {
         cout << items[(first + 1) % m_nMaxQueue] << " - ";
         first = (first + 1) % m_nMaxQueue;
      }
      cout << endl;
   }
}

template <typename T>
void CircularQueueType<T>::MakeEmpty()
{
   m_iFront = m_iRear; //Front�� rear�� ���� ������ isEmpty���� �ֺ������ �����
   top = 0;
}


template <typename T>
int CircularQueueType<T>::GetNextItem(T& data)
{
   r_CurPointer = (r_CurPointer + (m_nMaxQueue - 1)) % m_nMaxQueue;
   data = items[r_CurPointer];

   return r_CurPointer;
}


template <typename T>
void CircularQueueType<T>::ResetQueue()
{
   //�ʱ�ȭ ���� m_iFront��. 
   r_CurPointer = m_iRear + 1;
}

// Compare two MusicTypes.
template <typename T>
T  CircularQueueType<T>::CompareByKey(const T &data)
{
   if (this->r_Key > data.r_Key)
      return GREATER;
   else if (this->r_Key < data.r_Key)
      return LESS;
   else
      return EQUAL;
}

