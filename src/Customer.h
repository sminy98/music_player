#pragma once
#include <string>
#include "DoublySortedLinkedList.h"

using namespace std;
/**
*	@brief	Customer Ŭ����.
*/
class Customer
{
public:
	/**
	*	@brief	�⺻������
	*/
	Customer() {};

	/**
	*	@brief	�⺻�Ҹ���
	*/
	~Customer() {};
	/**
	*	@brief	���̵� ��ȯ�ϴ� �Լ�
	*	@pre	����
	*	@post	����
	*	@return	���̵� ��ȯ�ȴ�
	*/
	string GetId() { return _id; }	//���̵� ��ȯ

	/**
	*	@brief	��й�ȣ�� ��ȯ�ϴ� �Լ�
	*	@pre	����
	*	@post	����
	*	@return	��й�ȣ�� ��ȯ�ȴ�.
	*/
	string GetPw() { return _passWord; }	//��й�ȣ ��ȯ

	/**
	*	@brief	�̸��� ��ȯ�ϴ� �Լ�
	*	@pre	����
	*	@post	����
	*	@return	�̸��� ��ȯ�ȴ�
	*/
	string GetName() { return _name; }   //�̸� ��ȯ


	/**
	*brief	���̵� �����ϴ� �Լ�
	*	@pre	����
	*	@post	�Է¹��������� ���̵� ���õȴ�
	*/
	void SetId(string id) { _id = id; }	//���̵���

	/**
	*	@brief	��й�ȣ�� �����ϴ� �Լ�
	*	@pre	����
	*	@post	�Է¹��������� ��й�ȣ�� ���õȴ�
	*/
	void SetPw(string pw) { _passWord = pw; }	//��й�ȣ ����

	/**
	*	@brief	�̸��� �����ϴ� �Լ�
	*	@pre	����
	*	@post	�Է¹��������� �̸��� ���õȴ�
	*/
	void SetName(string name) { _name = name; }	//ID ����

	/**
	*	@brief	�������� �����ϴ� �Լ�
	*	@pre	����
	*	@post	����
	*/
	void SetCustomer(string id, string passWord, string name)
	{
		_id = id;
		_passWord = passWord;
		_name = name;
		return;
	}

	/**
	*	@brief	������(private key)�񱳸� ���� ==������ �����ε�
	*	@pre	����
	*	@post	����
	*	@return id�� ������ true, �ٸ��� false
	*/
	bool operator==(Customer customer) { return _id == customer.GetId(); };

	/**
	*	@brief	������(private key)�񱳸� ���� <������ �����ε�
	*	@pre	����
	*	@post	����
	*	@return	id�� ������ Ŭ�� true, ������ false
	*/
	bool operator<(Customer customer) { return _id < customer.GetId(); };

	/**
	*	@brief	������(private key)�񱳸� ���� >������ �����ε�
	*	@pre	����
	*	@post	����
	*	@return	id�� ������ ������ true, ũ�� false
	*/
	bool operator>(Customer customer) { return _id > customer.GetId(); };

protected:
	string _id;	//���̵�
	string _passWord;	//��й�ȣ
	string _name;  //�̸�
};