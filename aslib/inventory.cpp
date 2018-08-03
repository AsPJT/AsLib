#define ASLIB_INCLUDE_DL
#include "AsLib.hpp"
int32_t asMain()
{
	//640,360//960, 540//320,180
	MainControl mc(u8"Voice", asPlatformPos(Pos2(960, 540), aslib_full_screen));

	//アイテムUIの画像
	Texture item_ui(u8"p/itemUI.png");
	Texture item_ui2(u8"p/itemUI2.png");
	//アイテムの画像
	Texture mushroom_texture(u8"p/mushroom.png");
	Texture mushroom_texture2(u8"p/mushroom2.png");
	
	//アイテムデータ
	std::vector<Item> item;
	item.push_back(Item(item_ui, u8"Empty"));
	item.push_back(Item(mushroom_texture, 10,u8"mushroom"));
	item.push_back(Item(mushroom_texture2, 5,u8"mushroom2"));

	enum :size_t
	{
		aslib_item_empty,
		aslib_item_mushroom,
		aslib_item_mushroom2,
	};

	const PosA4 item_pos(Pos4F(0.45f, 0.7f, 0.55f, 0.9f).ratio());
	Font item_font(item_pos.w / 3,u8"Algerian");

	ShareItem share_item(8);
	share_item.push(0, aslib_item_mushroom, 5);
	share_item.push(1, aslib_item_mushroom2, 95);
	share_item.add(aslib_item_mushroom2, 25, item[aslib_item_mushroom2].stack_max);

	Inventory inv(item_ui, item_ui2, item_font, share_item, item_pos, 8, 0);



	//asStop();
	while (asLoop()) {
		if (asKeyU_Up()) share_item.sortDown();
		//inv.selectAdd(mouseWheel()).draw(item);
		inv.addSize(mouseWheel()).draw(item);

		if (asKeyY_Up()) inv.itemClear();

		inv.isSelectUp(asKeyL_Up()).isSelectDown(asKeyK_Up());
	}
	return 0;
}