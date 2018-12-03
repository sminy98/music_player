#include "ArtistList.h"

void ArtistList::AddMusicInArtist(SimpleType indata)
{
	ma_List.Add(indata);		//a_List안의 리스트인 ma_List안에 저장함.
}

//가수 선택을 받고 원하는 가수에 해당하는 구체적인 곡 정보를 받는 합수
void ArtistList::DisplayMusicDetailInArtist(BinarySearchTree<MusicType>* a_list)
{
	SimpleType data;
	MusicType m_item;

	cout << "\n\tCurrent list" << endl;

	ma_List.ResetList();
	a_list->ResetQ();
	bool found;

	for (int i = 0; i < ma_List.GetLength(); i++)
	{
		ma_List.GetNextItem(data);
		a_list->GetNextItem(m_item, found);

		while (data.GetNumber() != m_item.GetNumber())
		{
			a_list->GetNextItem(m_item, found);
		}
		m_item.DisplayRecordOnScreen();

	}
}

