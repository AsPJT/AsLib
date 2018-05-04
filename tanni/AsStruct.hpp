//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - As���C�u����
//
//                    �����: �������� (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------

constexpr bool IS_HEIGHT = true;
constexpr bool IS_WIDTH = false;

namespace AsLib
{
	//�傫��(2D)
	struct Pos2
	{
		int32_t x = 100;
		int32_t y = 100;
	};

	//�l�p�`
	struct Pos4
	{
		int32_t x1 = 0;
		int32_t x2 = 100;
		int32_t y1 = 0;
		int32_t y2 = 100;
	};

	//�R�F
	struct ColorRGB
	{
		uint8_t r = 255;
		uint8_t g = 255;
		uint8_t b = 255;
	};

	//�R�F�{����
	struct ColorRGBA
	{
		uint8_t r = 255;
		uint8_t g = 255;
		uint8_t b = 255;
		uint8_t a = 255;
	};

	//�f�t�H���g�w�i�F
	constexpr uint8_t BG_COLOR_R = 230;
	constexpr uint8_t BG_COLOR_G = 230;
	constexpr uint8_t BG_COLOR_B = 230;
	constexpr ColorRGB BG_COLOR = { BG_COLOR_R ,BG_COLOR_G ,BG_COLOR_B };

	//�f�t�H���g�E�B���h�E�T�C�Y
	constexpr int32_t WINDOW_SIZE_X = 360;
	constexpr int32_t WINDOW_SIZE_Y = 640;
	constexpr Pos2 WINDOW_SIZE = { WINDOW_SIZE_X ,WINDOW_SIZE_Y };


	//�F
	constexpr ColorRGB white = { 250 ,250 ,250 };
	constexpr ColorRGBA whiteA = { 250 ,250 ,250 ,255 };

	//���_�ʒu
	constexpr Pos2 pos2_0 = { 0,0 };
	constexpr Pos4 pos4_0 = { 0,0,0,0 };
}