#include "ArtistList.h"

void ArtistList::AddMusicInArtist(SimpleType indata)
{
	ma_List.Add(indata);		//a_List���� ����Ʈ�� ma_List�ȿ� ������.
}

//���� ������ �ް� ���ϴ� ������ �ش��ϴ� ��ü���� �� ������ �޴� �ռ�
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

