#include "AlbumList.h"

void AlbumList::AddMusicInAlbum(SimpleType indata)
{
	mal_List.Add(indata);		//al_List���� ����Ʈ�� mal_List�ȿ� ������.
}

//�帣 ������ �ް� ���ϴ� �帣�� �ش��ϴ� ��ü���� �� ������ �޴� �ռ�
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