#pragma once
#include <string>
#include "DoublySortedLinkedList.h"

using namespace std;
/**
*	@brief	Customer 클래스.
*/
class Customer
{
public:
	/**
	*	@brief	기본생성자
	*/
	Customer() {};

	/**
	*	@brief	기본소멸자
	*/
	~Customer() {};
	/**
	*	@brief	아이디를 반환하는 함수
	*	@pre	없음
	*	@post	없음
	*	@return	아이디가 반환된다
	*/
	string GetId() { return _id; }	//아이디 반환

	/**
	*	@brief	비밀번호를 반환하는 함수
	*	@pre	없음
	*	@post	없음
	*	@return	비밀번호가 반환된다.
	*/
	string GetPw() { return _passWord; }	//비밀번호 반환

	/**
	*	@brief	이름를 반환하는 함수
	*	@pre	없음
	*	@post	없음
	*	@return	이름이 반환된다
	*/
	string GetName() { return _name; }   //이름 반환


	/**
	*brief	아이디를 세팅하는 함수
	*	@pre	없음
	*	@post	입력받은값으로 아이디가 세팅된다
	*/
	void SetId(string id) { _id = id; }	//아이디세팅

	/**
	*	@brief	비밀번호를 세팅하는 함수
	*	@pre	없음
	*	@post	입력받은값으로 비밀번호가 세팅된다
	*/
	void SetPw(string pw) { _passWord = pw; }	//비밀번호 세팅

	/**
	*	@brief	이름를 세팅하는 함수
	*	@pre	없음
	*	@post	입력받은값으로 이름이 세팅된다
	*/
	void SetName(string name) { _name = name; }	//ID 세팅

	/**
	*	@brief	고객설정을 세팅하는 함수
	*	@pre	없음
	*	@post	없음
	*/
	void SetCustomer(string id, string passWord, string name)
	{
		_id = id;
		_passWord = passWord;
		_name = name;
		return;
	}

	/**
	*	@brief	고객정보(private key)비교를 위한 ==연산자 오버로딩
	*	@pre	없음
	*	@post	없음
	*	@return id가 같을시 true, 다를시 false
	*/
	bool operator==(Customer customer) { return _id == customer.GetId(); };

	/**
	*	@brief	고객정보(private key)비교를 위한 <연산자 오버로딩
	*	@pre	없음
	*	@post	없음
	*	@return	id가 우항이 클시 true, 작으면 false
	*/
	bool operator<(Customer customer) { return _id < customer.GetId(); };

	/**
	*	@brief	고객정보(private key)비교를 위한 >연산자 오버로딩
	*	@pre	없음
	*	@post	없음
	*	@return	id가 우항이 작을시 true, 크면 false
	*/
	bool operator>(Customer customer) { return _id > customer.GetId(); };

protected:
	string _id;	//아이디
	string _passWord;	//비밀번호
	string _name;  //이름
};