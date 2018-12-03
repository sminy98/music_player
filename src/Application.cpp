#include "Application.h"


// Program driver.

void Application::Run()
{
	Menu();
}

int Application::Login()
{
	cout << "-----------------------" << endl;
	string id, pw;
	cout << " ID : ";
	GetCommand(id);
	cout << " PW : ";
	GetCommand(pw);
	cout << "-----------------------" << endl;

	DoublyIterator<Customer*> itor(_customers);
	while (!itor.IsNull())
	{
		if ((*itor)->GetId() == id && (*itor)->GetPw() == pw)	//아이디 비밀번호가 일치한다면
		{
			_loginedCustomer = *itor;	//로그인된 유저 포인터를 저장한다.
			success("로그인 성공!");
			Main_Menu();
			pause;
			return 1;
		}
		++itor;
	}
	error("로그인 실패! 아이디,비밀번호를 확인하세요!");
	cout << bar << endl;
	pause;
	return 0;
}


void Application::Logout()
{
	_loginedCustomer = nullptr;
}

void Application::RegisterCustomer()
{
	string id, pw, name;
	Customer* newCustomer = NULL;
	newCustomer = new Customer;	//동적할당
	((Customer*)newCustomer)->SetCustomer(id, pw, name);
	_customers.Add(newCustomer);	//유저리스트에 추가

	cls;
	cout << bar << endl;
	cout << "회원가입을 진행하겠습니다!" << endl;
	cout << ">>";
	cout << "ID : ";
	GetCommand(id);
	DoublyIterator<Customer*> itor(_customers);
	for (; !itor.IsNull(); ++itor)
	{
		if ((*itor)->GetId() == id)
		{
			error("중복되는 아이디가 존재합니다!");
			pause;
			return;
		}
	}
	cout << "PW : ";
	GetCommand(pw);
	cout << "이름 : ";
	GetCommand(name);
	newCustomer = new Customer;

	((Customer*)newCustomer)->SetCustomer(id, pw, name);
	_customers.Add(newCustomer);

	cout << bar << endl;
	success("환영합니다! 회원가입 되었습니다!");
	pause;
	return;
}

void Application::PrintCustomerInfo()
{
	cout << "ID : " << _loginedCustomer->GetId() << endl;
	cout << "이름 : " << _loginedCustomer->GetName() << endl;

}

void Application::Menu()
{
	while (1)
	{
		cout << "***************************************" << endl;
		cout << "Music is my life" << endl;
		cout << "1. 로그인" << endl;
		cout << "2. 회원가입" << endl;
		cout << "0. 종료" << endl;
		cout << "***************************************" << endl;

		int choice;
		GetCommand(choice);
		switch (choice)
		{
		case 1:	//로그인
			Login();
			break;
		case 2:	//회원가입
			RegisterCustomer();
			break;
		case 0:	//종료
			return;
			break;
		}

	}
}

void Application::Main_Menu()
{
	while (1)
	{
		m_Command = CustomerMenu();

		switch (m_Command)
		{
		case 1:		// 음악 추가
			AddItem();
			break;
		case 2:		//리스트에서 음악 삭제
			Delete();
			break;
		case 3:		//리스트에서 음악 검색
			SearchMusic();
			break;
		case 4:		// 최근에 추가된 30곡의 자세한 정보를 화면에 출력
			DisplayNewMusic();
			break;
		case 5:		// 리스트에 있는 모든 음악 정보 출력
			DisplayAll();
			break;
		case 6:		// 가수 앨범 장르별로 음악 화면출력
			DisplayMusicBy();
			break;
		case 7:		//Song name과 Genre가 일치하는 음악을 찾아서 화면에 출력
			RetrieveByNameNGenre();
			break;
		case 8:		//Song name과 Genre가 일치하는 음악을 찾아서 화면에 출력
			RecommendMusic();
			break;
		case 0:
			cout << "로그아웃 되었습니다!" << endl;
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}

// Display command on screen and get a input from keyboard.
int Application::CustomerMenu()
{
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : Add Music" << endl;
	cout << "\t   2 : Delete Music" << endl;
	cout << "\t   3 : Search Music" << endl;
	cout << "\t   4 : Display New Music" << endl;
	cout << "\t   5 : Display All Music" << endl;
	cout << "\t   6 : Display Music By" << endl;
	cout << "	   7 : Retrieve By Name And Genre" << endl;
	cout << "\t   8 : Recommend Music" <<endl;
	cout << "\t   0 : 로그아웃" << endl;
	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}


// Add new record into list.
int Application::AddItem()
{
	MusicType item;
	SimpleType s_item;
	GenreList g_item;
	ArtistList a_item;
	AlbumList al_item;
	
	bool found;
	m_List.RetrieveItem(item, found);
	item.SetNumberFromKB();

	while (found==true)
	{
		cout << "\t곡번호가 중복됩니다." << endl;
		if (found==true)
			item.SetNumberFromKB();
	}

	item.SetTitleFromKB();
	item.SetArtistFromKB();
	item.SetAlbumFromKB();
	item.SetGenreFromKB();
	item.SetLyricsFromKB();

	s_item.SetNumber(item.GetNumber());
	s_item.SetTitle(item.GetTitle());

	g_item.SetGenre(item.GetGenre());
	a_item.SetArtist(item.GetArtist());
	al_item.SetAlbum(item.GetAlbum());
	
	m_List.Add(item);
	r_List.EnQueue(s_item);

	if (g_List.GetLength() == 0)
	{
		g_List.Add(g_item);
	}

	else
	{
		g_List.RetrieveItem(g_item, found);
		while (found==false)	//중복이 아닐 때_true인지 아닌지
		{
			g_List.Add(g_item);
			break;
		}
	}

	if (a_List.GetLength() == 0)
	{
		a_List.Add(a_item);
	}

	else
	{
		a_List.RetrieveItem(a_item, found);
		while (found == false)	//중복이 아닐 때_true인지 아닌지
		{
			a_List.Add(a_item);
			break;
		}
	}

	if (al_List.GetLength() == 0)
	{
		al_List.Add(al_item);
	}

	else
	{
		al_List.RetrieveItem(al_item, found);
		while (found == false)	//중복이 아닐 때_true인지 아닌지
		{
			al_List.Add(al_item);
			break;
		}
	}



	Node<GenreList> *node = new Node<GenreList>;
	Node<GenreList> *pre;
	GenreList temp;  // 입력된 음악이 어느 장르에 속하는지 찾기 위한 더미

	node->data = g_item;
	node->right = NULL;
	g_List.ResetQ();
	while (1)
	{
		pre = pData;   //이전노드를 가리키는 포인터를 생성
		bool found;
		pData = g_List.GetPoint(temp, found); //iteration을 이용해 노드 포인터 갱신
		if (temp.GetGenre() == item.GetGenre())
		{
			pData->data.GetGenreList()->Add(s_item);
			break;
		}
	}
	Node<ArtistList> *a_node = new Node<ArtistList>;
	Node<ArtistList> *a_pre;
	ArtistList a_temp;  // 입력된 음악이 어느 장르에 속하는지 찾기 위한 더미

	a_node->data = a_item;
	a_node->right = NULL;
	a_List.ResetQ();
	while (1)
	{
		a_pre = pa_Data;   //이전노드를 가리키는 포인터를 생성
		bool found;
		pa_Data = a_List.GetPoint(a_temp, found); //iteration을 이용해 노드 포인터 갱신
		if (a_temp.GetArtist() == item.GetArtist())
		{
			pa_Data->data.GetArtistList()->Add(s_item);
			break;
		}
	}

	Node<AlbumList> *al_node = new Node<AlbumList>;
	Node<AlbumList> *al_pre;
	AlbumList al_temp;  // 입력된 음악이 어느 장르에 속하는지 찾기 위한 더미

	al_node->data = al_item;
	al_node->right = NULL;
	al_List.ResetQ();
	while (1)
	{
		al_pre = pal_Data;   //이전노드를 가리키는 포인터를 생성
		bool found;
		pal_Data = al_List.GetPoint(al_temp, found); //iteration을 이용해 노드 포인터 갱신
		if (al_temp.GetAlbum() == item.GetAlbum())
		{
			pal_Data->data.GetAlbumList()->Add(s_item);
			break;
		}
	}

	// 현재 list 출력
	DisplayAll();

	return 1;
}


// Display all records in the list on screen.
void Application::DisplayAll()
{	
	cout << endl;
	cout<<"***Current MusicList***"<<endl;
	m_List.PrintTree(cout);				// PrintTree함수를 통해서 출력
}



//찾을 Title을 사용자에게 입력받고 SortedList의 Get함수를 호출한다.
bool Application::Search()
{
	cout << "\t찾을";
	MusicType data;	//Get함수는 MusicType을 파라미터로 갖기 때문에 임의로 만들어준다.
	data.SetTitleFromKB();	//사용자에게서 Title값을 입력받는다.
	bool found;
	m_List.RetrieveItem(data, found);
	if (found=true)	//Title값만 가진 data를 Get으로 보내 나머지 정보를 채운다.
	{
		cout << "\t찾았습니다." << endl;
		data.DisplayRecordOnScreen();
		return 1;	//찾으면 그 항목을 출력해주고 1을 리턴한다.
	}
	else
		cout << "\t찾지 못했습니다." << endl;
	return 0;	//찾지 못하면 찾지 못했다는 메시지를 출력하고 0을 리턴한다.
}


//찾을 Title를 사용자에게 입력받고 SortedList의 Delete함수를 호출한다.
void Application::Delete()
{
	cout << "\t지울";
	MusicType data;	//Delete함수는 MusicType을 파라미터로 갖기 때문에 임의로 만들어준다.
	data.SetNumberFromKB();	//사용자에게서 Number값을 입력받는다.
	bool found;
	m_List.RetrieveItem(data, found);

	if (found==true)	//Delete함수에 data를 넘겨준다.
	{
		cout << "\t삭제를 완료했습니다." << endl;	//삭제에 성공했으면 메시지를 출력한다.
	}
	else
		cout << "\t삭제하지 못했습니다. 일치하는 항목을 찾을 수 없습니다." << endl;	//삭제에 실패했으면 메시지를 출력한다.
}

//사용자에게 찾고자하는 Title을 입력받고 넘겨주는 역할을 한다.
void Application::RetreiveRecordByMemberName()
{
	MusicType temp;
	cout << "\t찾을";
	temp.SetTitleFromKB();	//SearchListByMemberName함수에 넘겨줄 temp의 name을 사용자에게 입력받는다.
	temp.SetGenreFromKB();
	SearchListByMemberName(temp);	//실질적으로 찾는 동작을 하는 SearchListByMemberName함수를 호출하고 temp값을 넘겨준다.
}


//사용자가 찾고자하는 name(=Title)을 포함하는 inData로 m_List의 항목들 중 일치하는 항목을 찾고 출력해준다. **프로그램에 전반적으로 Array에 index를 직접 접근하는 방법을 선호했으나 이 함수는 Application 클래스의 메소드이므로 GetNextItem함수를 이용해 iteration을 이용했습니다.
void Application::SearchListByMemberName(MusicType &inData)
{
	MusicType temp;	//m_List의 값을 비교해주기 위한 임시 MusicType.
	m_List.ResetQ();

	int length = m_List.GetLength();
	int count = 0;
	for (int i = 0; i < length; i++)
	{
		bool found;
		m_List.GetPoint(temp,found);


		if (temp.GetGenre().find(inData.GetGenre()) != -1)
		{


			if (temp.GetTitle().find(inData.GetTitle()) != -1)
			{
				temp.DisplayRecordOnScreen();	//일치하는 문자열을 포함하는 temp의 내용을 출력한다.
				count++;	//찾은 개수를 1 늘려준다.
			}
		}
	}
	if (count == 0)
		cout << "\t찾을 수 없습니다." << endl;	//찾은 개수가 0개이면 찾을 수 없다는 메시지를 출력한다.
}


// 입력된 정보로 리스트에서 제목을 찾아 정보출력
int Application::SearchByTitle()
{
	MusicType item;
	string input;

	cout << "\t찾고자하는 음악 Title을 입력하세요 : ";
	cin >> input;
	cout << endl << endl;

	// list의 모든 데이터를 화면에 출력
	m_List.ResetQ();      //리스트값을 리셋한다. 값은 -1이 된다.
	int length = m_List.GetLength();   //리스트의 길이를 length에 저장한다.
	bool found;
	m_List.GetNextItem(item,found);

	for (int i = 0; i < m_List.GetLength(); i++)
	{
		if (item.GetTitle() == input)
		{
			item.DisplayRecordOnScreen();
		}
		bool found;
		m_List.GetNextItem(item,found);
	}

	return 0;
}

// 입력된 정보로 리스트에서 가수를 찾아 정보출력
int Application::SearchByArtist()
{
	MusicType item;
	string input;

	cout << "\t찾고자하는 음악 Artist을 입력하세요 : ";
	cin >> input;
	cout << endl << endl;

	// list의 모든 데이터를 화면에 출력
	m_List.ResetQ();      //리스트값을 리셋한다. 값은 -1이 된다.
	int length = m_List.GetLength();   //리스트의 길이를 length에 저장한다.
	bool found;
	m_List.GetNextItem(item, found);

	for (int i = 0; i < m_List.GetLength(); i++)
	{
		if (item.GetTitle() == input)
		{
			item.DisplayRecordOnScreen();
		}
		bool found;
		m_List.GetNextItem(item,found);
	}

	return 0;
}
// 입력된 정보로 리스트에서 앨범을 찾아 정보출력
int Application::SearchByAlbum()
{
	MusicType item;
	string input;

	cout << "\t찾고자하는 음악 Album을 입력하세요 : ";
	cin >> input;
	cout << endl << endl;

	// list의 모든 데이터를 화면에 출력
	m_List.ResetQ();      //리스트값을 리셋한다. 값은 -1이 된다.
	int length = m_List.GetLength();   //리스트의 길이를 length에 저장한다.
	bool found;
	m_List.GetNextItem(item,found);

	for (int i = 0; i < m_List.GetLength(); i++)
	{
		if (item.GetTitle() == input)
		{
			item.DisplayRecordOnScreen();
		}
		bool found;
		m_List.GetNextItem(item,found);
	}

	return 0;
}

// 입력된 정보로 리스트에서 장르를 찾아 정보출력
int Application::SearchByGenre()
{
	MusicType item;
	string input;

	cout << "\t찾고자하는 음악 Gnere을 입력하세요 : ";
	cin >> input;
	cout << endl << endl;

	// list의 모든 데이터를 화면에 출력
	m_List.ResetQ();      //리스트값을 리셋한다. 값은 -1이 된다.
	int length = m_List.GetLength();   //리스트의 길이를 length에 저장한다.
	bool found;
	m_List.GetNextItem(item,found);

	for (int i = 0; i < m_List.GetLength(); i++)
	{
		if (item.GetTitle() == input)
		{
			item.DisplayRecordOnScreen();
		}
		bool found;
		m_List.GetNextItem(item,found);
	}

	return 0;
}


//최근에 추가된 30곡의 자세한 정보를 화면에 출력
void Application::DisplayNewMusic()
{
	cout << "\n\tNew Music 30 list" << endl;

	MusicType item;
	SimpleType data;
	bool found;
	r_List.ResetQueue();	//r_CurPointer 초기화
	int length = r_List.GetTop(); // length에 리스트 길이 저장

	int curIndex = r_List.GetNextItem(data); // data에 첫번째 칸 정보 저장


	for (int i = length; i>0; i--)
	{
		item.SetNumber(data.GetNumber());	//SimpleType의 data에서 곡번호를 받아 MusicType의 item에 곡번호를 준다.
		m_List.RetrieveItem(item, found);		//m_List에서 item에 저장된 곡번호에 맞는 정보를 찾는다.  
		item.DisplayRecordOnScreen();		//곡번호, 곡명, 가수, 장르, 가사를 화면에 출력함.
		curIndex = r_List.GetNextItem(data);	//r_CurPointer를 다음 index로 넘긴다.
	}
}


//장르별로 음악 화면출력
int Application::DisplayMusicByGenre()
{
	GenreList data;
	GenreList dummy;

	cout << "\n\tCurrent list" << endl;

	// genre list의 모든 데이터를 화면에 출력
	g_List.ResetQ();

	for (int i = 0; i < g_List.GetLength(); i++)
	{
		bool found;
		g_List.GetNextItem(data,found);
		data.DisplayAll();
	}

	// 특정 장르의 음악 정보만 보고 싶을 때
	string name;

	cout << "찾고자하는 장르를 입력하세요 : ";
	cin >> name;
	dummy.SetGenre(name);

	GenreList g_temp;
	Node<GenreList> *pData;
	bool found;


	g_List.ResetQ();
	for (int i = 0; i < g_List.GetLength(); i++)
	{
		pData = g_List.GetPoint(g_temp,found);
		if (g_temp.GetGenre() == dummy.GetGenre())
		{
			pData->data.DisplayMusicDetailInGenre(&m_List); // 해당 장르 음악 출력
			return 1;
		}
	}
	cout << "해당 장르에 곡이 존재하지 않습니다.";
	return 1;
}


//가수별로 음악 화면출력
int Application::DisplayMusicByArtist()
{
	ArtistList data;
	ArtistList dummy;

	cout << "\n\tCurrent list" << endl;

	// artist list의 모든 데이터를 화면에 출력
	a_List.ResetQ();

	for (int i = 0; i < a_List.GetLength(); i++)
	{
		bool found;
		a_List.GetNextItem(data, found);
		data.DisplayAll();
	}

	// 특정 가수의 음악 정보만 보고 싶을 때
	string name;

	cout << "찾고자하는 가수를 입력하세요 : ";
	cin >> name;
	dummy.SetArtist(name);

	ArtistList a_temp;
	Node<ArtistList> *pa_Data;
	bool found;

	a_List.ResetQ();
	for (int i = 0; i < a_List.GetLength(); i++)
	{
		pa_Data = a_List.GetPoint(a_temp, found);
		if (a_temp.GetArtist() == dummy.GetArtist())
		{
			pa_Data->data.DisplayMusicDetailInArtist(&m_List); // 해당 가수 음악 출력
			return 1;
		}
	}
	cout << "해당 가수에 곡이 존재하지 않습니다.";
	return 1;
}

//앨범별로 음악 화면출력
int Application::DisplayMusicByAlbum()
{
	AlbumList data;
	AlbumList dummy;

	cout << "\n\tCurrent list" << endl;

	// album list의 모든 데이터를 화면에 출력
	al_List.ResetQ();

	for (int i = 0; i < al_List.GetLength(); i++)
	{
		bool found;
		al_List.GetNextItem(data, found);
		data.DisplayAll();
	}

	// 특정 앨범의 음악 정보만 보고 싶을 때
	string name;

	cout << "찾고자하는 앨범을 입력하세요 : ";
	cin >> name;
	dummy.SetAlbum(name);

	AlbumList al_temp;
	Node<AlbumList> *pal_Data;
	bool found;


	al_List.ResetQ();
	for (int i = 0; i < al_List.GetLength(); i++)
	{
		pal_Data = al_List.GetPoint(al_temp, found);
		if (al_temp.GetAlbum() == dummy.GetAlbum())
		{
			pal_Data->data.DisplayMusicDetailInAlbum(&m_List); // 해당 앨범 음악 출력
			return 1;
		}
	}
	cout << "해당 앨범에 곡이 존재하지 않습니다.";
	return 1;
}


//입력받은 범위로 정수를 입력받는 함수
bool Application::GetCommand(int& buffer, int minRange, int maxRange)
{
	int temporaryBuffer;
	if (!(cin >> temporaryBuffer) || cin.fail())	//잘못된 입력이면
	{
		cin.clear();	//플래그 초기화
		cin.ignore(INT_MAX, '\n');	//버퍼 비우기
		return false;	//실패를 반환
	}
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	if (minRange > temporaryBuffer || maxRange < temporaryBuffer)
	{
		return false;	//실패를 반환
	}
	buffer = temporaryBuffer;
	return true;	//성공을 반환
}


//버퍼로 문자열을 입력받는 함수, 로그인/로그아웃때 사용
bool Application::GetCommand(string& buffer)
{//문자열 입력받는 함수
	string temporaryBuffer;
	if (!(cin >> temporaryBuffer) || cin.fail())	//입력이 실패하면
	{
		cin.clear();	//플래그 초기화
		cin.ignore(INT_MAX, '\n');	//버퍼 비우기
		return false;	//실패를 반환
	}
	cin.clear();	//플래그 초기화
	cin.ignore(INT_MAX, '\n');	//버퍼 비우기
	buffer = temporaryBuffer;
	return true;	//성공을 반환
}

//Song name과 Genre가 일치하는 음악을 찾아서 화면에 출력
int Application::RetrieveByNameNGenre()
{
	MusicType item;
	RetreiveRecordByMemberName();
	return 1;
}

//m_List 내에서 저장된 곡들 중 랜덤으로 한 곡을 골라 준다
int Application::RecommendMusic()
{
	MusicType item;
	m_List.ResetQ();
	int length = m_List.GetLength();

	srand((unsigned int)time(NULL));		////srand: seed 생성(랜덤으로 변수만들기 위해 사용)		
	int num = (rand() % length) + 1;		//1~length까지 범위

	for (int i = 1; i < num + 1; i++)	//랜덤변수에 위치한 데이터를 얻기 위해 포인터 움직임.
	{
		bool found;
		m_List.GetNextItem(item, found);
	}
	item.DisplayRecordOnScreen();	//랜덤으로 선택한 위치에 있는 음원정보 화면에 띄우기
	return 1;
}

//m_List 내에서 저장된 곡을 검색
int Application::SearchMusic()
{
	int num;
	cout << "\t   1 : Search Music by Title" << endl;
	cout << "\t   2 : Search Music by Artist" << endl;
	cout << "\t   3 : Search Music by Album" << endl;
	cout << "\t   4 : Search Music by Genre" << endl;
	cout << endl;
	cout << "번호를 입력하세요" << endl;
	cin >> num;
	switch (num)
	{
	case 1:		//리스트에 있는 음악 검색(검색어가 곡명에 포함되면 출력)
		SearchByTitle();
		break;
	case 2:		//리스트 있는 가수 검색(검색어가 가수명에 포함되면 출력)
		SearchByArtist();
		break;
	case 3:		//리스트에 있는 앨범 검색(검색어가 앨범명에 포함되면 출력)
		SearchByAlbum();
		break;
	case 4:			//리스트에 있는 장르검색(검색어가 장르명에 포함되면 출력)
		SearchByGenre();
		break;
	default:
		break;
	}
	return 1;
}

//m_List 내에서 저장된 곡을 검색
int Application::DisplayMusicBy()
{
	int num;
	cout << "\t   1 : Display Music By Artist" << endl;
	cout << "\t   2 : Display Music By Album" << endl;
	cout << "\t   3 : Display Music By Genre" << endl;
	cout << endl;
	cout << "번호를 입력하세요" << endl;
	cin >> num;
	switch (num)
	{
	case 1:		// 가수별로 음악 화면출력
		DisplayMusicByArtist();
		break;
	case 2:		// 앨범별로 음악 화면출력
		DisplayMusicByAlbum();
		break;
	case 3:		// 장르별로 음악 화면출력
		DisplayMusicByGenre();
		break;
	default:
		break;
	}
	return 1;
}

