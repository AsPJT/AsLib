//ゲームエンジン
#define DX_NON_USING_NAMESPACE_DXLIB
#include "DxLib.h"
#include "AsLib.hpp"

//メイン関数
int32_t AsMain()
{
	AsInitData as = AsReadInit("b.txt", "あいうえお", WINDOW_SIZE, BG_COLOR);

	//画面上部のUI情報
	constexpr int UI_DIVIDE_SIZE = 10;
	constexpr int UI_DIVIDE_STR_SIZE = 20;
	//Pos2 UI_size = { as.windowSize().x, as.windowSize().y / UI_DIVIDE_SIZE };

	const Pos2 UI_size = AsReadPos2("a.txt");

	ColorRGB UI_color = { 165, 212, 173 };

	//フォント
	std::string select_font = "Meiryo UI";

	AsFont font_handle = AsMakeFont(as.windowSize().y / UI_DIVIDE_STR_SIZE, select_font);

	AsWritePos2("a.txt", UI_size);
	AsWriteInit("b.txt", as);

	Texture texture("mihon.jpg");

	while (AsLoop())
	{

		AsRect(UI_size, UI_color);

		AsStr(font_handle, "こんにちは！ようこそ！", pos2_0, white);

		texture(pos4R_all, as.windowSize(), TEXTURE_RATIO_X).draw();
	}

	return AsEnd();
}

//----------------------------------------------------------------------------------------------------

//各ライブラリのメイン関数
#if defined(__DXLIB) //DxLib
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	return int(AsMain());
}
#elif defined(SIV3D_INCLUDED) //Siv3D
void Main()
{
	AsMain();
	return;
}
#else //Console
int main()
{
	return int(AsMain());
}
#endif