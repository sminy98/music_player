#ifndef _ARTISTLIST_H
#define _ARTISTLIST_H

#include <iostream>
#include <fstream>	
#include <string>
using namespace std;

#include "SimpleType.h"
#include "BinarySearchTree.h"
#include "MusicType.h"
#include "SinglyLinkedList.h"

class ArtistList
{
public:
	/**
	*	default constructor.
	*/
	ArtistList()
	{
		artist = "";
	}
	/**
	*	destructor.
	*/
	~ArtistList() {}

	void SetArtist(string m_artist)	//music List�� album�� ����.
	{
		artist = m_artist;
	}

	string GetArtist()
	{
		return artist;
	}

	//�帣 ����Ʈ ������ 2�� ����Ʈ�� mg_List�� Application���� ����ϱ� ���� �Լ�
	SinglyLinkedList<SimpleType>* GetArtistList()
	{
		return &ma_List;
	}

	/**
	*	@brief	display genre information on screen.
	*/
	void DisplayAll()
	{
		cout << "Artist : " << artist << endl;
	}

	/**
	*	@brief	add a music information into this genre.
	*	@param[in]	indata	music information.
	*/
	void AddMusicInArtist(SimpleType indata);

	/**
	*	@brief	Display all music information in this artist.
	*	@param[in]	list	music list.
	*/
	void DisplayMusicDetailInArtist(BinarySearchTree<MusicType>* a_list);


	/**
	*	@brief  ���ȣ�� ���� �񱳷� ������ �����ε�
	*	@pre	none.
	*	@post	none.
	*	@return	�����ڿ� �´� 1,0 ��
	*/
	bool operator== (const  ArtistList &T)const
	{
		if (this->artist == T.artist)
			return 1;
		return 0;
	}
	bool operator> (const  ArtistList &T)
	{
		if (this->artist > T.artist)
			return 1;
		return 0;
	}
	bool operator< (const  ArtistList &T)
	{
		if (this->artist < T.artist)
			return 1;
		return 0;
	}

	bool operator!=(const  ArtistList &T)
	{
		if (this->artist != T.artist)
			return 1;
		return 0;
	}


private:
	string artist;
	SinglyLinkedList<SimpleType> ma_List;
};
#endif //_ARTISTLIST_H
