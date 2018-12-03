
#ifndef _SIMPLETYPE_H
#define _SIMPLETYPE_H

#include <string>
#include <iostream>


using namespace std;

/**
*	item information class.
*/
class SimpleType
{
public:
	/**
	*	default constructor.
	*/
	SimpleType()
	{
		s_Number = 0;
		s_Title = "";

	}

	/**
	*	destructor.
	*/
	~SimpleType() {}

	/**
	*	@brief	곡번호 받기.
	*	@pre	number is set.
	*	@post	none.
	*	@return	number.
	*/
	int GetNumber()
	{
		return s_Number;
	}

	/**
	*	@brief	곡명 받기.
	*	@pre	Title is set.
	*	@post	none.
	*	@return	Title.
	*/
	string GetTitle()
	{
		return s_Title;
	}

	/**
	*	@brief	Set Number.
	*	@pre	none.
	*	@post	Number is set.
	*	@param	inNumber	Title.
	*/
	void SetNumber(int inNumber)
	{
		s_Number = inNumber;
	}

	/**
	*	@brief	Set Title.
	*	@pre	none.
	*	@post	Title is set.
	*	@param	inTitle	Title.
	*/
	void SetTitle(string inTitle)
	{
		s_Title = inTitle;
	}

	/**
	*	@brief	display simple music information on screen.
	*/
	void DisplayAll()
	{
		cout << "Number : " << s_Number << endl;
		cout << "Title : " << s_Title << endl;
	}

	/**
	*	@brief  곡번호를 통한 비교로 연산자 오버로딩
	*	@pre	none.
	*	@post	none.
	*	@return	연산자에 맞는 1,0 값
	*/
	bool operator== (const SimpleType &T)const
	{
		if (this->s_Number == T.s_Number)return 1;
		return 0;
	}
	bool operator> (const SimpleType &T)
	{
		if (this->s_Number > T.s_Number)return 1;
		return 0;
	}
	bool operator< (const SimpleType &T)
	{
		if (this->s_Number < T.s_Number)return 1;
		return 0;
	}

	bool operator!=(const SimpleType &T)
	{
		if (this->s_Number != T.s_Number)return 1;
		return 0;
	}

	// operator overloading
	friend ostream& operator << (ostream& out, SimpleType& item)
	{
		out << "Number : " << item.GetNumber() << endl;
		out << "Title : " << item.GetTitle() << endl;

		return out;
	}

protected:
	int s_Number;	///< 곡번호
	string s_Title;			///< 곡명
};

#endif	// _SIMPLETYPE_H

