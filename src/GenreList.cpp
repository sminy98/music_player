#include "GenreList.h"

void GenreList::AddMusicInGenre(SimpleType indata)
{
	gg_List.Add(indata);		//g_List안의 리스트인 gg_List안에 저장함.
}

//장르 선택을 받고 원하는 장르에 해당하는 구체적인 곡 정보를 받는 합수
void GenreList::DisplayMusicDetailInGenre(BinarySearchTree<MusicType>* list)
{
	SimpleType data;
	MusicType m_item;

	cout << "\n\tCurrent list" << endl;

	gg_List.ResetList();
	list->ResetQ();
	bool found;
	
	for (int i = 0; i < gg_List.GetLength(); i++)
	{
		gg_List.GetNextItem(data);
		list->GetNextItem(m_item,found);

		while (data.GetNumber() != m_item.GetNumber())
		{
			list->GetNextItem(m_item,found);
		}
		m_item.DisplayRecordOnScreen();
	}
}