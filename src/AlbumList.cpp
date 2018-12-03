#include "AlbumList.h"

void AlbumList::AddMusicInAlbum(SimpleType indata)
{
	mal_List.Add(indata);		//al_List안의 리스트인 mal_List안에 저장함.
}

//장르 선택을 받고 원하는 장르에 해당하는 구체적인 곡 정보를 받는 합수
void AlbumList::DisplayMusicDetailInAlbum(BinarySearchTree<MusicType> *al_list)
{
	SimpleType data;
	MusicType m_item;

	cout << "\n\tCurrent list" << endl;

	mal_List.ResetList();
	al_list->ResetQ();
	bool found;

	for (int i = 0; i < mal_List.GetLength(); i++)
	{
		mal_List.GetNextItem(data);
		al_list->GetNextItem(m_item, found);

		while (data.GetNumber() != m_item.GetNumber())
		{
			al_list->GetNextItem(m_item, found);
		}
		m_item.DisplayRecordOnScreen();
	}
}