#include "MusicType.h"


// Set Music Number from keyboard.
void MusicType::SetNumberFromKB()
{
	cout << "\tNumber : ";
	cin >> m_Number;
}

// Set Music Title from keyboard.
void MusicType::SetTitleFromKB()
{
	cout << "\tTitle : ";
	cin >> m_Title;
}


// Set Music Artist from keyboard.
void MusicType::SetArtistFromKB()
{
	cout << "\tArtist : ";
	cin >> m_sArtist;
}


// Set Music Album from keyboard.
void MusicType::SetAlbumFromKB()
{
	cout << "\tAlbum : ";
	cin >> m_sAlbum;
}

// Set Music Genre from keyboard.
void MusicType::SetGenreFromKB()
{
	cout << "\tGenre : ";
	cin >> m_sGenre;
}

// Set Music Lyrics from keyboard. 띄어쓰기도 인식할 수 있어야 함.
void MusicType::SetLyricsFromKB()
{
	cout << "\tLyrics : ";
	getline(cin, m_sLyrics);	//앞에 엔터키가 들어가서 한 번 더 getline 써줘야 함.
	getline(cin, m_sLyrics);
}


// Set Music record from keyboard.
void MusicType::SetRecordFromKB()
{
	SetNumberFromKB();
	SetTitleFromKB();
	SetArtistFromKB();
	SetAlbumFromKB();
	SetGenreFromKB();
	SetLyricsFromKB();
}


// Read a record from file.
int MusicType::ReadDataFromFile(ifstream& fin)
{
	fin >> m_Number;
	fin >> m_Title;
	fin >> m_sArtist;
	fin >> m_sAlbum;
	fin >> m_sGenre;
	fin >> m_sLyrics;
	return 1;
};


// Write a record into file.
int MusicType::WriteDataToFile(ofstream& fout)
{
	fout << endl;
	fout << m_Number << " ";
	fout << m_Title << " ";
	fout << m_sArtist << " ";
	fout << m_sAlbum << " ";
	fout << m_sGenre << " ";
	fout << m_sLyrics << " ";
	return 1;
}
