#ifndef _GENRELIST_H
#define _GENRELIST_H

#pragma once
#include <iostream>
#include <fstream>	
#include <string>
using namespace std;

#include "SimpleType.h"
#include "BinarySearchTree.h"
#include "MusicType.h"
#include "SinglyLinkedList.h"

class GenreList
{
public:
	/**
	*	default constructor.
	*/
	GenreList()
	{
		genre = "";
	}
	/**
	*	destructor.
	*/
	~GenreList() {}

	void SetGenre(string m_genre)	//music List�� genre�� ����.
	{
		genre = m_genre;
	}

	string GetGenre()
	{
		return genre;
	}

	//�帣 ����Ʈ ������ 2�� ����Ʈ�� mg_List�� Application���� ����ϱ� ���� �Լ�
	SinglyLinkedList<SimpleType>* GetGenreList()
	{
		return &gg_List;
	}

	/**
	*	@brief	display genre information on screen.
	*/
	void DisplayAll()
	{
		cout << "Genre : " << genre << endl;
	}

	/**
	*	@brief	add a music information into this genre.
	*	@param[in]	indata	music information.
	*/
	void AddMusicInGenre(SimpleType indata);

	/**
	*	@brief	Display all music information in this genre.
	*	@param[in]	list	music list.
	*/
	void DisplayMusicDetailInGenre(BinarySearchTree<MusicType>* list);

	/**
	*	@brief  ���ȣ�� ���� �񱳷� ������ �����ε�
	*	@pre	none.
	*	@post	none.
	*	@return	�����ڿ� �´� 1,0 ��
	*/
	bool operator== (const GenreList &T)const
	{
		if (this->genre == T.genre)
			return 1;
		return 0;
	}
	bool operator> (const GenreList &T)
	{
		if (this->genre > T.genre)
			return 1;
		return 0;
	}
	bool operator< (const GenreList &T)
	{
		if (this->genre < T.genre)
			return 1;
		return 0;
	}

	bool operator!=(const GenreList &T)
	{
		if (this->genre != T.genre)
			return 1;
		return 0;
	}


private:
	string genre;
	SinglyLinkedList<SimpleType> gg_List;
};
#endif //_GENRELIST_H
