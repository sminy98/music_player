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
		if ((*itor)->GetId() == id && (*itor)->GetPw() == pw)	//���̵� ��й�ȣ�� ��ġ�Ѵٸ�
		{
			_loginedCustomer = *itor;	//�α��ε� ���� �����͸� �����Ѵ�.
			success("�α��� ����!");
			Main_Menu();
			pause;
			return 1;
		}
		++itor;
	}
	error("�α��� ����! ���̵�,��й�ȣ�� Ȯ���ϼ���!");
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
	newCustomer = new Customer;	//�����Ҵ�
	((Customer*)newCustomer)->SetCustomer(id, pw, name);
	_customers.Add(newCustomer);	//��������Ʈ�� �߰�

	cls;
	cout << bar << endl;
	cout << "ȸ�������� �����ϰڽ��ϴ�!" << endl;
	cout << ">>";
	cout << "ID : ";
	GetCommand(id);
	DoublyIterator<Customer*> itor(_customers);
	for (; !itor.IsNull(); ++itor)
	{
		if ((*itor)->GetId() == id)
		{
			error("�ߺ��Ǵ� ���̵� �����մϴ�!");
			pause;
			return;
		}
	}
	cout << "PW : ";
	GetCommand(pw);
	cout << "�̸� : ";
	GetCommand(name);
	newCustomer = new Customer;

	((Customer*)newCustomer)->SetCustomer(id, pw, name);
	_customers.Add(newCustomer);

	cout << bar << endl;
	success("ȯ���մϴ�! ȸ������ �Ǿ����ϴ�!");
	pause;
	return;
}

void Application::PrintCustomerInfo()
{
	cout << "ID : " << _loginedCustomer->GetId() << endl;
	cout << "�̸� : " << _loginedCustomer->GetName() << endl;

}

void Application::Menu()
{
	while (1)
	{
		cout << "***************************************" << endl;
		cout << "Music is my life" << endl;
		cout << "1. �α���" << endl;
		cout << "2. ȸ������" << endl;
		cout << "0. ����" << endl;
		cout << "***************************************" << endl;

		int choice;
		GetCommand(choice);
		switch (choice)
		{
		case 1:	//�α���
			Login();
			break;
		case 2:	//ȸ������
			RegisterCustomer();
			break;
		case 0:	//����
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
		case 1:		// ���� �߰�
			AddItem();
			break;
		case 2:		//����Ʈ���� ���� ����
			Delete();
			break;
		case 3:		//����Ʈ���� ���� �˻�
			SearchMusic();
			break;
		case 4:		// �ֱٿ� �߰��� 30���� �ڼ��� ������ ȭ�鿡 ���
			DisplayNewMusic();
			break;
		case 5:		// ����Ʈ�� �ִ� ��� ���� ���� ���
			DisplayAll();
			break;
		case 6:		// ���� �ٹ� �帣���� ���� ȭ�����
			DisplayMusicBy();
			break;
		case 7:		//Song name�� Genre�� ��ġ�ϴ� ������ ã�Ƽ� ȭ�鿡 ���
			RetrieveByNameNGenre();
			break;
		case 8:		//Song name�� Genre�� ��ġ�ϴ� ������ ã�Ƽ� ȭ�鿡 ���
			RecommendMusic();
			break;
		case 0:
			cout << "�α׾ƿ� �Ǿ����ϴ�!" << endl;
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
	cout << "\t   0 : �α׾ƿ�" << endl;
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
		cout << "\t���ȣ�� �ߺ��˴ϴ�." << endl;
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
		while (found==false)	//�ߺ��� �ƴ� ��_true���� �ƴ���
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
		while (found == false)	//�ߺ��� �ƴ� ��_true���� �ƴ���
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
		while (found == false)	//�ߺ��� �ƴ� ��_true���� �ƴ���
		{
			al_List.Add(al_item);
			break;
		}
	}



	Node<GenreList> *node = new Node<GenreList>;
	Node<GenreList> *pre;
	GenreList temp;  // �Էµ� ������ ��� �帣�� ���ϴ��� ã�� ���� ����

	node->data = g_item;
	node->right = NULL;
	g_List.ResetQ();
	while (1)
	{
		pre = pData;   //������带 ����Ű�� �����͸� ����
		bool found;
		pData = g_List.GetPoint(temp, found); //iteration�� �̿��� ��� ������ ����
		if (temp.GetGenre() == item.GetGenre())
		{
			pData->data.GetGenreList()->Add(s_item);
			break;
		}
	}
	Node<ArtistList> *a_node = new Node<ArtistList>;
	Node<ArtistList> *a_pre;
	ArtistList a_temp;  // �Էµ� ������ ��� �帣�� ���ϴ��� ã�� ���� ����

	a_node->data = a_item;
	a_node->right = NULL;
	a_List.ResetQ();
	while (1)
	{
		a_pre = pa_Data;   //������带 ����Ű�� �����͸� ����
		bool found;
		pa_Data = a_List.GetPoint(a_temp, found); //iteration�� �̿��� ��� ������ ����
		if (a_temp.GetArtist() == item.GetArtist())
		{
			pa_Data->data.GetArtistList()->Add(s_item);
			break;
		}
	}

	Node<AlbumList> *al_node = new Node<AlbumList>;
	Node<AlbumList> *al_pre;
	AlbumList al_temp;  // �Էµ� ������ ��� �帣�� ���ϴ��� ã�� ���� ����

	al_node->data = al_item;
	al_node->right = NULL;
	al_List.ResetQ();
	while (1)
	{
		al_pre = pal_Data;   //������带 ����Ű�� �����͸� ����
		bool found;
		pal_Data = al_List.GetPoint(al_temp, found); //iteration�� �̿��� ��� ������ ����
		if (al_temp.GetAlbum() == item.GetAlbum())
		{
			pal_Data->data.GetAlbumList()->Add(s_item);
			break;
		}
	}

	// ���� list ���
	DisplayAll();

	return 1;
}


// Display all records in the list on screen.
void Application::DisplayAll()
{	
	cout << endl;
	cout<<"***Current MusicList***"<<endl;
	m_List.PrintTree(cout);				// PrintTree�Լ��� ���ؼ� ���
}



//ã�� Title�� ����ڿ��� �Է¹ް� SortedList�� Get�Լ��� ȣ���Ѵ�.
bool Application::Search()
{
	cout << "\tã��";
	MusicType data;	//Get�Լ��� MusicType�� �Ķ���ͷ� ���� ������ ���Ƿ� ������ش�.
	data.SetTitleFromKB();	//����ڿ��Լ� Title���� �Է¹޴´�.
	bool found;
	m_List.RetrieveItem(data, found);
	if (found=true)	//Title���� ���� data�� Get���� ���� ������ ������ ä���.
	{
		cout << "\tã�ҽ��ϴ�." << endl;
		data.DisplayRecordOnScreen();
		return 1;	//ã���� �� �׸��� ������ְ� 1�� �����Ѵ�.
	}
	else
		cout << "\tã�� ���߽��ϴ�." << endl;
	return 0;	//ã�� ���ϸ� ã�� ���ߴٴ� �޽����� ����ϰ� 0�� �����Ѵ�.
}


//ã�� Title�� ����ڿ��� �Է¹ް� SortedList�� Delete�Լ��� ȣ���Ѵ�.
void Application::Delete()
{
	cout << "\t����";
	MusicType data;	//Delete�Լ��� MusicType�� �Ķ���ͷ� ���� ������ ���Ƿ� ������ش�.
	data.SetNumberFromKB();	//����ڿ��Լ� Number���� �Է¹޴´�.
	bool found;
	m_List.RetrieveItem(data, found);

	if (found==true)	//Delete�Լ��� data�� �Ѱ��ش�.
	{
		cout << "\t������ �Ϸ��߽��ϴ�." << endl;	//������ ���������� �޽����� ����Ѵ�.
	}
	else
		cout << "\t�������� ���߽��ϴ�. ��ġ�ϴ� �׸��� ã�� �� �����ϴ�." << endl;	//������ ���������� �޽����� ����Ѵ�.
}

//����ڿ��� ã�����ϴ� Title�� �Է¹ް� �Ѱ��ִ� ������ �Ѵ�.
void Application::RetreiveRecordByMemberName()
{
	MusicType temp;
	cout << "\tã��";
	temp.SetTitleFromKB();	//SearchListByMemberName�Լ��� �Ѱ��� temp�� name�� ����ڿ��� �Է¹޴´�.
	temp.SetGenreFromKB();
	SearchListByMemberName(temp);	//���������� ã�� ������ �ϴ� SearchListByMemberName�Լ��� ȣ���ϰ� temp���� �Ѱ��ش�.
}


//����ڰ� ã�����ϴ� name(=Title)�� �����ϴ� inData�� m_List�� �׸�� �� ��ġ�ϴ� �׸��� ã�� ������ش�. **���α׷��� ���������� Array�� index�� ���� �����ϴ� ����� ��ȣ������ �� �Լ��� Application Ŭ������ �޼ҵ��̹Ƿ� GetNextItem�Լ��� �̿��� iteration�� �̿��߽��ϴ�.
void Application::SearchListByMemberName(MusicType &inData)
{
	MusicType temp;	//m_List�� ���� �����ֱ� ���� �ӽ� MusicType.
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
				temp.DisplayRecordOnScreen();	//��ġ�ϴ� ���ڿ��� �����ϴ� temp�� ������ ����Ѵ�.
				count++;	//ã�� ������ 1 �÷��ش�.
			}
		}
	}
	if (count == 0)
		cout << "\tã�� �� �����ϴ�." << endl;	//ã�� ������ 0���̸� ã�� �� ���ٴ� �޽����� ����Ѵ�.
}


// �Էµ� ������ ����Ʈ���� ������ ã�� �������
int Application::SearchByTitle()
{
	MusicType item;
	string input;

	cout << "\tã�����ϴ� ���� Title�� �Է��ϼ��� : ";
	cin >> input;
	cout << endl << endl;

	// list�� ��� �����͸� ȭ�鿡 ���
	m_List.ResetQ();      //����Ʈ���� �����Ѵ�. ���� -1�� �ȴ�.
	int length = m_List.GetLength();   //����Ʈ�� ���̸� length�� �����Ѵ�.
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

// �Էµ� ������ ����Ʈ���� ������ ã�� �������
int Application::SearchByArtist()
{
	MusicType item;
	string input;

	cout << "\tã�����ϴ� ���� Artist�� �Է��ϼ��� : ";
	cin >> input;
	cout << endl << endl;

	// list�� ��� �����͸� ȭ�鿡 ���
	m_List.ResetQ();      //����Ʈ���� �����Ѵ�. ���� -1�� �ȴ�.
	int length = m_List.GetLength();   //����Ʈ�� ���̸� length�� �����Ѵ�.
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
// �Էµ� ������ ����Ʈ���� �ٹ��� ã�� �������
int Application::SearchByAlbum()
{
	MusicType item;
	string input;

	cout << "\tã�����ϴ� ���� Album�� �Է��ϼ��� : ";
	cin >> input;
	cout << endl << endl;

	// list�� ��� �����͸� ȭ�鿡 ���
	m_List.ResetQ();      //����Ʈ���� �����Ѵ�. ���� -1�� �ȴ�.
	int length = m_List.GetLength();   //����Ʈ�� ���̸� length�� �����Ѵ�.
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

// �Էµ� ������ ����Ʈ���� �帣�� ã�� �������
int Application::SearchByGenre()
{
	MusicType item;
	string input;

	cout << "\tã�����ϴ� ���� Gnere�� �Է��ϼ��� : ";
	cin >> input;
	cout << endl << endl;

	// list�� ��� �����͸� ȭ�鿡 ���
	m_List.ResetQ();      //����Ʈ���� �����Ѵ�. ���� -1�� �ȴ�.
	int length = m_List.GetLength();   //����Ʈ�� ���̸� length�� �����Ѵ�.
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


//�ֱٿ� �߰��� 30���� �ڼ��� ������ ȭ�鿡 ���
void Application::DisplayNewMusic()
{
	cout << "\n\tNew Music 30 list" << endl;

	MusicType item;
	SimpleType data;
	bool found;
	r_List.ResetQueue();	//r_CurPointer �ʱ�ȭ
	int length = r_List.GetTop(); // length�� ����Ʈ ���� ����

	int curIndex = r_List.GetNextItem(data); // data�� ù��° ĭ ���� ����


	for (int i = length; i>0; i--)
	{
		item.SetNumber(data.GetNumber());	//SimpleType�� data���� ���ȣ�� �޾� MusicType�� item�� ���ȣ�� �ش�.
		m_List.RetrieveItem(item, found);		//m_List���� item�� ����� ���ȣ�� �´� ������ ã�´�.  
		item.DisplayRecordOnScreen();		//���ȣ, ���, ����, �帣, ���縦 ȭ�鿡 �����.
		curIndex = r_List.GetNextItem(data);	//r_CurPointer�� ���� index�� �ѱ��.
	}
}


//�帣���� ���� ȭ�����
int Application::DisplayMusicByGenre()
{
	GenreList data;
	GenreList dummy;

	cout << "\n\tCurrent list" << endl;

	// genre list�� ��� �����͸� ȭ�鿡 ���
	g_List.ResetQ();

	for (int i = 0; i < g_List.GetLength(); i++)
	{
		bool found;
		g_List.GetNextItem(data,found);
		data.DisplayAll();
	}

	// Ư�� �帣�� ���� ������ ���� ���� ��
	string name;

	cout << "ã�����ϴ� �帣�� �Է��ϼ��� : ";
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
			pData->data.DisplayMusicDetailInGenre(&m_List); // �ش� �帣 ���� ���
			return 1;
		}
	}
	cout << "�ش� �帣�� ���� �������� �ʽ��ϴ�.";
	return 1;
}


//�������� ���� ȭ�����
int Application::DisplayMusicByArtist()
{
	ArtistList data;
	ArtistList dummy;

	cout << "\n\tCurrent list" << endl;

	// artist list�� ��� �����͸� ȭ�鿡 ���
	a_List.ResetQ();

	for (int i = 0; i < a_List.GetLength(); i++)
	{
		bool found;
		a_List.GetNextItem(data, found);
		data.DisplayAll();
	}

	// Ư�� ������ ���� ������ ���� ���� ��
	string name;

	cout << "ã�����ϴ� ������ �Է��ϼ��� : ";
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
			pa_Data->data.DisplayMusicDetailInArtist(&m_List); // �ش� ���� ���� ���
			return 1;
		}
	}
	cout << "�ش� ������ ���� �������� �ʽ��ϴ�.";
	return 1;
}

//�ٹ����� ���� ȭ�����
int Application::DisplayMusicByAlbum()
{
	AlbumList data;
	AlbumList dummy;

	cout << "\n\tCurrent list" << endl;

	// album list�� ��� �����͸� ȭ�鿡 ���
	al_List.ResetQ();

	for (int i = 0; i < al_List.GetLength(); i++)
	{
		bool found;
		al_List.GetNextItem(data, found);
		data.DisplayAll();
	}

	// Ư�� �ٹ��� ���� ������ ���� ���� ��
	string name;

	cout << "ã�����ϴ� �ٹ��� �Է��ϼ��� : ";
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
			pal_Data->data.DisplayMusicDetailInAlbum(&m_List); // �ش� �ٹ� ���� ���
			return 1;
		}
	}
	cout << "�ش� �ٹ��� ���� �������� �ʽ��ϴ�.";
	return 1;
}


//�Է¹��� ������ ������ �Է¹޴� �Լ�
bool Application::GetCommand(int& buffer, int minRange, int maxRange)
{
	int temporaryBuffer;
	if (!(cin >> temporaryBuffer) || cin.fail())	//�߸��� �Է��̸�
	{
		cin.clear();	//�÷��� �ʱ�ȭ
		cin.ignore(INT_MAX, '\n');	//���� ����
		return false;	//���и� ��ȯ
	}
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	if (minRange > temporaryBuffer || maxRange < temporaryBuffer)
	{
		return false;	//���и� ��ȯ
	}
	buffer = temporaryBuffer;
	return true;	//������ ��ȯ
}


//���۷� ���ڿ��� �Է¹޴� �Լ�, �α���/�α׾ƿ��� ���
bool Application::GetCommand(string& buffer)
{//���ڿ� �Է¹޴� �Լ�
	string temporaryBuffer;
	if (!(cin >> temporaryBuffer) || cin.fail())	//�Է��� �����ϸ�
	{
		cin.clear();	//�÷��� �ʱ�ȭ
		cin.ignore(INT_MAX, '\n');	//���� ����
		return false;	//���и� ��ȯ
	}
	cin.clear();	//�÷��� �ʱ�ȭ
	cin.ignore(INT_MAX, '\n');	//���� ����
	buffer = temporaryBuffer;
	return true;	//������ ��ȯ
}

//Song name�� Genre�� ��ġ�ϴ� ������ ã�Ƽ� ȭ�鿡 ���
int Application::RetrieveByNameNGenre()
{
	MusicType item;
	RetreiveRecordByMemberName();
	return 1;
}

//m_List ������ ����� ��� �� �������� �� ���� ��� �ش�
int Application::RecommendMusic()
{
	MusicType item;
	m_List.ResetQ();
	int length = m_List.GetLength();

	srand((unsigned int)time(NULL));		////srand: seed ����(�������� ��������� ���� ���)		
	int num = (rand() % length) + 1;		//1~length���� ����

	for (int i = 1; i < num + 1; i++)	//���������� ��ġ�� �����͸� ��� ���� ������ ������.
	{
		bool found;
		m_List.GetNextItem(item, found);
	}
	item.DisplayRecordOnScreen();	//�������� ������ ��ġ�� �ִ� �������� ȭ�鿡 ����
	return 1;
}

//m_List ������ ����� ���� �˻�
int Application::SearchMusic()
{
	int num;
	cout << "\t   1 : Search Music by Title" << endl;
	cout << "\t   2 : Search Music by Artist" << endl;
	cout << "\t   3 : Search Music by Album" << endl;
	cout << "\t   4 : Search Music by Genre" << endl;
	cout << endl;
	cout << "��ȣ�� �Է��ϼ���" << endl;
	cin >> num;
	switch (num)
	{
	case 1:		//����Ʈ�� �ִ� ���� �˻�(�˻�� ��� ���ԵǸ� ���)
		SearchByTitle();
		break;
	case 2:		//����Ʈ �ִ� ���� �˻�(�˻�� ������ ���ԵǸ� ���)
		SearchByArtist();
		break;
	case 3:		//����Ʈ�� �ִ� �ٹ� �˻�(�˻�� �ٹ��� ���ԵǸ� ���)
		SearchByAlbum();
		break;
	case 4:			//����Ʈ�� �ִ� �帣�˻�(�˻�� �帣�� ���ԵǸ� ���)
		SearchByGenre();
		break;
	default:
		break;
	}
	return 1;
}

//m_List ������ ����� ���� �˻�
int Application::DisplayMusicBy()
{
	int num;
	cout << "\t   1 : Display Music By Artist" << endl;
	cout << "\t   2 : Display Music By Album" << endl;
	cout << "\t   3 : Display Music By Genre" << endl;
	cout << endl;
	cout << "��ȣ�� �Է��ϼ���" << endl;
	cin >> num;
	switch (num)
	{
	case 1:		// �������� ���� ȭ�����
		DisplayMusicByArtist();
		break;
	case 2:		// �ٹ����� ���� ȭ�����
		DisplayMusicByAlbum();
		break;
	case 3:		// �帣���� ���� ȭ�����
		DisplayMusicByGenre();
		break;
	default:
		break;
	}
	return 1;
}

