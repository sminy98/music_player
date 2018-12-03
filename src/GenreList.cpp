#include "GenreList.h"

void GenreList::AddMusicInGenre(SimpleType indata)
{
	gg_List.Add(indata);		//g_List���� ����Ʈ�� gg_List�ȿ� ������.
}

//�帣 ������ �ް� ���ϴ� �帣�� �ش��ϴ� ��ü���� �� ������ �޴� �ռ�
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