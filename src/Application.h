#ifndef _APPLICATION_H
#define _APPLICATION_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>		//rand 난수 생성 함수
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
	*	@brief	메뉴를 출력하는 함수
	*	@pre	없음
	*	@post	메뉴가 화면상에 출력이 된다.
	*/
	void Menu();   //메뉴 출력

	/**
	*	@brief	Display command on screen and get a input from keyboard.
	*	@pre	none.
	*	@post	none.
	*	@return	Customer's command.
	*/
	void Main_Menu();

	//선택지를 보여주는 메뉴
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
	*	@brief	사용자에게 Title을 입력받아 SortedList의 Get함수에 넘겨주는 역할을 한다.
	*	@pre	없다.
	*	@post	불완전한 data의 정보가 모두 채워지고 그 결과가 출력된다.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	bool Search();

	/**
	*	@brief	사용자에게 Title을 입력받아 SortedList의 Delete함수에 넘겨주는 역할을 한다.
	*	@pre	없다.
	*	@post	사용자가 입력한 Title를 가지고 있는 MusicType이 m_List에서 사라진다.
	*	@return	없다.
	*/
	void Delete();

	/**
	*	@brief	객체를 생성 후, 문자열을 입력받는다.
	*	@pre	없다.
	*	@post	SearchListByMemberName함수에 문자열이 설정된 객체를 전달한다.
	*	@return	없다.
	*/
	void RetreiveRecordByMemberName();

	/**
	*	@brief	inData의 이름 부분을 포함하는 문자열을 찾아 출력한다.
	*	@pre	inData의 이름 부분이 초기화되어있어야 한다.
	*	@post	inData에 알맞은 항목이 복사된다.
	*	@param	inData	이름이 설정되어있고 나머지는 비어있는 MusicType.
	*	@return	없다.
	*/
	void SearchListByMemberName(MusicType &inData);

	/**
	*	@brief	사용자에게 Title을 입력받아 Title을 찾아 데이터를 출력
	*	@pre	찾으려는 Title에 일치하는 데이터가 존재해야 함.
	*	@post	없음.
	*	@return		찾으려는 사용자 학번에 일치하는 데이터를 화면에 띄우면 1을 리턴하고 그렇지 않으면 0을 리턴함.
	*/
	int SearchByTitle();

	/**
	*	@brief	사용자에게 가수를 입력받아 가수를 찾아 데이터를 출력
	*	@pre	찾으려는 가수에 일치하는 데이터가 존재해야 함.
	*	@post	없음.
	*	@return		찾으려는 가수에 일치하는 데이터를 화면에 띄우면 1을 리턴하고 그렇지 않으면 0을 리턴함.
	*/
	int SearchByArtist();

	/**
	*	@brief	사용자에게 앨범을 입력받아 앨범을 찾아 데이터를 출력
	*	@pre	찾으려는 앨범에 일치하는 데이터가 존재해야 함.
	*	@post	없음.
	*	@return		찾으려는 앨범에 일치하는 데이터를 화면에 띄우면 1을 리턴하고 그렇지 않으면 0을 리턴함.
	*/
	int SearchByAlbum();

	/**
	*	@brief	사용자에게 장르를 입력받아 장르를 찾아 데이터를 출력
	*	@pre	찾으려는 장르에 일치하는 데이터가 존재해야 함.
	*	@post	없음.
	*	@return		찾으려는 장르에 일치하는 데이터를 화면에 띄우면 1을 리턴하고 그렇지 않으면 0을 리턴함.
	*/
	int SearchByGenre();

	/**
	*	@brief	최근에 추가된 30곡의 자세한 정보를 화면에 출력
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayNewMusic();

	/**
	*	@brief	장르별로 음악 화면출력
	*	@pre	none.
	*	@post	none.
	*/
	int DisplayMusicByGenre();

	/**
	*	@brief	앨범별로 음악 화면출력
	*	@pre	none.
	*	@post	none.
	*/
	int DisplayMusicByAlbum();


	/**
	*	@brief	가수별로 음악 화면출력
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
	*	@brief	m_List 내에서 랜덤으로 하나의 곡이 화면에 나온다.
	*	@pre	m_List 내에 곡 정보가 저장되어 있어야 함.
	*	@post	랜덤한 자세한 곡 정보가 화면에 나옴.
	*/
	int RecommendMusic();	//m_List 내에서 저장된 곡들 중 랜덤으로 한 곡을 화면에 띄움.

	/**
	*	@brief	로그인하는 함수
	*	@pre	없음
	*	@post	없음
	*	@return	로그인 성공하면 1, 실패하면 0
	*/
	int Login();   //로그인

	/**
	*	@brief	로그아웃하는 함수
	*	@pre	없음
	*	@post	없음
	*/
	void Logout();	//로그아웃

	/**
	*	@brief	회원가입하는 함수
	*	@pre	없음
	*	@post	회원정보에 새 회원이 추가된다
	*/
	void RegisterCustomer();    //회원 등록


	/**
	*	@brief	유저정보를 출력하는 함수
	*	@pre	없음
	*	@post	로그인된 유저의 정보가 출력된다
	*/
	void PrintCustomerInfo();   //로그인된 유저정보 출력

	/**
	*	@brief	정수입력을 받는 함수
	*	@pre	없음
	*	@post	없음
	*	@return	입력받은값이 올바른 값이면 true, 실패하면 false
	*/
	bool GetCommand(int& buffer, int minRange = INT_MIN, int maxRange = INT_MAX);

	/**
	*	@brief	문자열입력을 받는 함수
	*	@pre	없음
	*	@post	없음
	*	@return	입력받은값이 올바른 값이면 true, 실패하면 false
	*/
	bool GetCommand(string& buffer);
	
	//리스트에서 음악 검색
	int SearchMusic();

	//가수 앨범 장르 별로 음악 검색
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
	Node<GenreList> *pData = NULL; // mGenreList의 해당 장르를 포인터로 가리키기 위한 더미
	Node<AlbumList> *pal_Data = NULL; // AlbumList의 해당 앨범을 포인터로 가리키기 위한 더미
	Node<ArtistList> *pa_Data = NULL; // ArtistList의 해당 가수를 포인터로 가리키기 위한 더미
	Customer* _loginedCustomer;	//현재 로그인 하고 있는 사용자를 포인터로 가르킴
	DoublySortedLinkedList<Customer*> _customers; 	//사용자 리스트
};
#endif	// _APPLICATION_H
