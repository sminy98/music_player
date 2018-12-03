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

template <typename T>   //generic data을 위해 template 선언
class CircularQueueType
{
public:
   /**
   *   @brief   size에 해당하는 크기의 배열을 동적할당
   *   @post   size의 값에 해당되는 크기의 배열이 만들어짐,각 멤버변수들이 초기화됨
   */
   CircularQueueType(int size);
   /**
   *   @brief   최대크기로 생성
   *   @pre   최대크기가 정해져야함
   *   @post   최대크기의 배열이 만들어지고, 각 멤버변수들이 초기화됨
   */
   CircularQueueType(void);

   ~CircularQueueType(void);


   /**
   *   @brief   queue가 가득차있는지 확인.
   *   @pre   queue가 초기화 되어야함.
   *   @post   차있으면 ture 아니면 false
   */
   bool IsFull() const; // 읽기전용 함수, 선언과 정의 모두에서 const 써야한다. 

                   /**
                   *   @brief   queue가 비어있는지 확인
                   *   @pre   queue가 초기화 되어야함.
                   *   @post   비어있으면 ture 아니면 false
                   */
   bool IsEmpty() const;

   /**
   *   @brief   queue에 회전하면서 값을 채움.
   *   @pre   queue가 초기화 되어야함
   *   @post   가득차있으면 FullStack Exception을 throw함, 아니면 새로운 값을 추가함,rear값 증가
   */
   void EnQueue(T item);

   /**
   *   @brief   queue에 회전하면서 값을 삭제(=front값이 하나 증가)
   *   @pre   Stack has been initialized.
   *   @post   비어있으면 empty Exception을 throw;아니면 맨위의 값을 삭제
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
   *   @brief 이전 인덱스를 선택한다.
   *   @pre   초기화되어 있어야 한다.
   *   @post  이전 인덱스로 넘어간다.
   */
   int GetNextItem(T& data);


   /**
   *   @brief  Queue를 초기화 시켜준다.
   *   @pre   없음
   *   @post   m_CurPointer를 m_iFront +1로 바꾼다.
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
   *   @brief top를 가져온다.
   *   @pre   없음
   *   @post  top을 사용할 수 있음
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
   items = new T[size];   //T의 자료형으로 동적할당
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

   if ((m_iRear + 1) % m_nMaxQueue == m_iFront)   //rear의 다음칸에 front인지 아닌지 검사
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
//   if (IsEmpty())         //비어있는지 검사
//     throw EmptyStack();
//   else
//   {
      m_iFront = (m_iFront + 1) % m_nMaxQueue; //front를 앞으로 한칸 이동
      item = items[m_iFront];   //지워지는, 접근되지 않을 값을 알기위해서 item에 해당 값을 전달

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

// top을 가져온다. 
template <typename T>
int CircularQueueType<T>::GetTop()
{
   return top;
}


// Print all the items in the CircularQueueType on screen
template <typename T>
void CircularQueueType<T>::Print()
{
   if (IsEmpty())            //비었으면 it is empty출력. Empty Stack을 throw하면 프로그램이 종료되어서 다시 Enqueue할수없으므로
      cout << "It is empty!" << endl;            //부득이하게 새로운 예외처리
   else
   {
      cout << "CircularQueueType: ";
      // CircularQueueType 내의모든element 출력.
      int first = m_iFront;
      int last = m_iRear;
      while (first != last)            //Rear값과 front가 같지 않을동안만. front로 시작해서 값을 하나씩 출력.Enqueue하면 rear가 front에 비해 앞서있으므로
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
   m_iFront = m_iRear; //Front랑 rear랑 값이 같으면 isEmpty에서 텅빈것으로 연산됨
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
   //초기화 값은 m_iFront다. 
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

