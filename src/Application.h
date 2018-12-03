#ifndef _APPLICATION_H
#define _APPLICATION_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>		//rand ���� ���� �Լ�
#include <ctime>
using namespace std;

#include "CircularQueueType.h"
#include "GenreList.h"
#include "ArtistList.h"
#include "AlbumList.h"
#include "Customer.h"
#include "DoublySortedLinkedList.h"

#define FILENAMESIZE 1024
#define pause system("pause")
#define cls system("cls")
#define bar "=================================================="
#define error(a) cout << "ERROR! " << a <<endl
#define success(a) cout << "SUCCESS! " << a <<endl

/**
*	application class for item management simply.
*/
class Application
{
public:
	/**
	*	default constructor.
	*/
	Application()
	{
		this->_loginedCustomer = NULL;
		Customer* newCustomer = NULL;
	}

	/**
	*	destructor.
	*/
	~Application() { }

	/**
	*	@brief	Program driver.
	*	@pre	program is started.
	*	@post	program is finished.
	*/
	void Run();

	/**
	*	@brief	�޴��� ����ϴ� �Լ�
	*	@pre	����
	*	@post	�޴��� ȭ��� ����� �ȴ�.
	*/
	void Menu();   //�޴� ���

	/**
	*	@brief	Display command on screen and get a input from keyboard.
	*	@pre	none.
	*	@post	none.
	*	@return	Customer's command.
	*/
	void Main_Menu();

	//�������� �����ִ� �޴�
	int CustomerMenu();

	/**
	*	@brief	Add new record into list.
	*	@pre	list should be initialized.
	*	@post	new record is added into the list.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int AddItem();

	/**
	*	@brief	Display all records in the list on screen.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayAll();

	/**
	*	@brief	����ڿ��� Title�� �Է¹޾� SortedList�� Get�Լ��� �Ѱ��ִ� ������ �Ѵ�.
	*	@pre	����.
	*	@post	�ҿ����� data�� ������ ��� ä������ �� ����� ��µȴ�.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	bool Search();

	/**
	*	@brief	����ڿ��� Title�� �Է¹޾� SortedList�� Delete�Լ��� �Ѱ��ִ� ������ �Ѵ�.
	*	@pre	����.
	*	@post	����ڰ� �Է��� Title�� ������ �ִ� MusicType�� m_List���� �������.
	*	@return	����.
	*/
	void Delete();

	/**
	*	@brief	��ü�� ���� ��, ���ڿ��� �Է¹޴´�.
	*	@pre	����.
	*	@post	SearchListByMemberName�Լ��� ���ڿ��� ������ ��ü�� �����Ѵ�.
	*	@return	����.
	*/
	void RetreiveRecordByMemberName();

	/**
	*	@brief	inData�� �̸� �κ��� �����ϴ� ���ڿ��� ã�� ����Ѵ�.
	*	@pre	inData�� �̸� �κ��� �ʱ�ȭ�Ǿ��־�� �Ѵ�.
	*	@post	inData�� �˸��� �׸��� ����ȴ�.
	*	@param	inData	�̸��� �����Ǿ��ְ� �������� ����ִ� MusicType.
	*	@return	����.
	*/
	void SearchListByMemberName(MusicType &inData);

	/**
	*	@brief	����ڿ��� Title�� �Է¹޾� Title�� ã�� �����͸� ���
	*	@pre	ã������ Title�� ��ġ�ϴ� �����Ͱ� �����ؾ� ��.
	*	@post	����.
	*	@return		ã������ ����� �й��� ��ġ�ϴ� �����͸� ȭ�鿡 ���� 1�� �����ϰ� �׷��� ������ 0�� ������.
	*/
	int SearchByTitle();

	/**
	*	@brief	����ڿ��� ������ �Է¹޾� ������ ã�� �����͸� ���
	*	@pre	ã������ ������ ��ġ�ϴ� �����Ͱ� �����ؾ� ��.
	*	@post	����.
	*	@return		ã������ ������ ��ġ�ϴ� �����͸� ȭ�鿡 ���� 1�� �����ϰ� �׷��� ������ 0�� ������.
	*/
	int SearchByArtist();

	/**
	*	@brief	����ڿ��� �ٹ��� �Է¹޾� �ٹ��� ã�� �����͸� ���
	*	@pre	ã������ �ٹ��� ��ġ�ϴ� �����Ͱ� �����ؾ� ��.
	*	@post	����.
	*	@return		ã������ �ٹ��� ��ġ�ϴ� �����͸� ȭ�鿡 ���� 1�� �����ϰ� �׷��� ������ 0�� ������.
	*/
	int SearchByAlbum();

	/**
	*	@brief	����ڿ��� �帣�� �Է¹޾� �帣�� ã�� �����͸� ���
	*	@pre	ã������ �帣�� ��ġ�ϴ� �����Ͱ� �����ؾ� ��.
	*	@post	����.
	*	@return		ã������ �帣�� ��ġ�ϴ� �����͸� ȭ�鿡 ���� 1�� �����ϰ� �׷��� ������ 0�� ������.
	*/
	int SearchByGenre();

	/**
	*	@brief	�ֱٿ� �߰��� 30���� �ڼ��� ������ ȭ�鿡 ���
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayNewMusic();

	/**
	*	@brief	�帣���� ���� ȭ�����
	*	@pre	none.
	*	@post	none.
	*/
	int DisplayMusicByGenre();

	/**
	*	@brief	�ٹ����� ���� ȭ�����
	*	@pre	none.
	*	@post	none.
	*/
	int DisplayMusicByAlbum();


	/**
	*	@brief	�������� ���� ȭ�����
	*	@pre	none.
	*	@post	none.
	*/
	int DisplayMusicByArtist();

	/**
	*	@brief	Retrieve item in the list.
	*	@pre	none.
	*	@post	none.
	*	@return	1 if the target item is exist in the list, otherwise 0.
	*/
	int RetrieveByNameNGenre();

	/**
	*	@brief	m_List ������ �������� �ϳ��� ���� ȭ�鿡 ���´�.
	*	@pre	m_List ���� �� ������ ����Ǿ� �־�� ��.
	*	@post	������ �ڼ��� �� ������ ȭ�鿡 ����.
	*/
	int RecommendMusic();	//m_List ������ ����� ��� �� �������� �� ���� ȭ�鿡 ���.

	/**
	*	@brief	�α����ϴ� �Լ�
	*	@pre	����
	*	@post	����
	*	@return	�α��� �����ϸ� 1, �����ϸ� 0
	*/
	int Login();   //�α���

	/**
	*	@brief	�α׾ƿ��ϴ� �Լ�
	*	@pre	����
	*	@post	����
	*/
	void Logout();	//�α׾ƿ�

	/**
	*	@brief	ȸ�������ϴ� �Լ�
	*	@pre	����
	*	@post	ȸ�������� �� ȸ���� �߰��ȴ�
	*/
	void RegisterCustomer();    //ȸ�� ���


	/**
	*	@brief	���������� ����ϴ� �Լ�
	*	@pre	����
	*	@post	�α��ε� ������ ������ ��µȴ�
	*/
	void PrintCustomerInfo();   //�α��ε� �������� ���

	/**
	*	@brief	�����Է��� �޴� �Լ�
	*	@pre	����
	*	@post	����
	*	@return	�Է¹������� �ùٸ� ���̸� true, �����ϸ� false
	*/
	bool GetCommand(int& buffer, int minRange = INT_MIN, int maxRange = INT_MAX);

	/**
	*	@brief	���ڿ��Է��� �޴� �Լ�
	*	@pre	����
	*	@post	����
	*	@return	�Է¹������� �ùٸ� ���̸� true, �����ϸ� false
	*/
	bool GetCommand(string& buffer);
	
	//����Ʈ���� ���� �˻�
	int SearchMusic();

	//���� �ٹ� �帣 ���� ���� �˻�
	int DisplayMusicBy();


private:
	ifstream m_InFile;		///< input file descriptor.
	ofstream m_OutFile;		///< output file descriptor.
	int m_Command;			///< current command number0
	BinarySearchTree<MusicType> m_List;		///< item list.
	BinarySearchTree<SimpleType> s_List;		///< s_item list.
	BinarySearchTree<GenreList> g_List;			///<  g_item list
	BinarySearchTree<ArtistList> a_List;			///<  a_item list
	BinarySearchTree<AlbumList> al_List;			///<  al_item list
	CircularQueueType<SimpleType> r_List;	///< AddRecentlyMuusic list 
	Node<GenreList> *pData = NULL; // mGenreList�� �ش� �帣�� �����ͷ� ����Ű�� ���� ����
	Node<AlbumList> *pal_Data = NULL; // AlbumList�� �ش� �ٹ��� �����ͷ� ����Ű�� ���� ����
	Node<ArtistList> *pa_Data = NULL; // ArtistList�� �ش� ������ �����ͷ� ����Ű�� ���� ����
	Customer* _loginedCustomer;	//���� �α��� �ϰ� �ִ� ����ڸ� �����ͷ� ����Ŵ
	DoublySortedLinkedList<Customer*> _customers; 	//����� ����Ʈ
};
#endif	// _APPLICATION_H
