#ifndef _ALBUMLIST_H
#define _ALBUMLIST_H

#include <iostream>
#include <fstream>	
#include <string>
using namespace std;

#pragma once
#include "SimpleType.h"
#include "BinarySearchTree.h"
#include "MusicType.h"
#include "SinglyLinkedList.h"


class AlbumList
{
public:
	/**
	*	default constructor.
	*/
	AlbumList()
	{
		album= "";
	}
	/**
	*	destructor.
	*/
	~AlbumList() 
	{}

	void SetAlbum(string m_album)	//music List의 album를 받음.
	{
		album = m_album;
	}

	string GetAlbum()
	{
		return album;
	}

	//앨범 리스트 내에서 2중 리스트인 mal_List를 Application에서 사용하기 위한 함수
	SinglyLinkedList<SimpleType>* GetAlbumList()
	{
		return &mal_List;
	}
	
	/**
	*	@brief	display album information on screen.
	*/
	void DisplayAll()
	{
		cout << "Album : " << album << endl;
	}

	/**
	*	@brief	add a music information into this album.
	*	@param[in]	indata	music information.
	*/
	void AddMusicInAlbum(SimpleType indata);

	/**
	*	@brief	Display all music information in this album.
	*	@param[in]	list	music list.
	*/
	void DisplayMusicDetailInAlbum(BinarySearchTree<MusicType>* al_list);


	/**
	*	@brief  곡번호를 통한 비교로 연산자 오버로딩
	*	@pre	none.
	*	@post	none.
	*	@return	연산자에 맞는 1,0 값
	*/
	bool operator== (const AlbumList &T)const
	{
		if (this->album == T.album)
			return 1;
		return 0;
	}
	bool operator> (const AlbumList &T)
	{
		if (this->album > T.album)
			return 1;
		return 0;
	}
	bool operator< (const AlbumList &T)
	{
		if (this->album < T.album)
			return 1;
		return 0;
	}

	bool operator!=(const AlbumList &T)
	{
		if (this->album != T.album)
			return 1;
		return 0;
	}


private:
	string album;
	SinglyLinkedList<SimpleType> mal_List;
};
#endif //_ALBUMLIST_H
