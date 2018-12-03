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

	void SetGenre(string m_genre)	//music List의 genre를 받음.
	{
		genre = m_genre;
	}

	string GetGenre()
	{
		return genre;
	}

	//장르 리스트 내에서 2중 리스트인 mg_List를 Application에서 사용하기 위한 함수
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
	*	@brief  곡번호를 통한 비교로 연산자 오버로딩
	*	@pre	none.
	*	@post	none.
	*	@return	연산자에 맞는 1,0 값
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
