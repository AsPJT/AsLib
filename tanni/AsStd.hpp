//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - As���C�u����
//
//                    �����: �������� (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{
#if defined(_MSC_VER)

	//�t�@�C���ǂݍ���
	int32_t AsRead(const char* const file_name, void* const read_buf, const size_t read_size, const size_t read_nmemb)
	{
		FILE  *cfp_fp;
		const errno_t cfp_error = fopen_s(&cfp_fp, file_name, "rb");
		if (cfp_error) return -1;

		fread(read_buf, read_size, read_nmemb, cfp_fp);
		fclose(cfp_fp);
		return 0;
	}

	//�t�@�C����������
	int32_t AsWrite(const char* const file_name, void* const write_buf, const size_t write_size, const size_t write_nmemb)
	{
		FILE  *cfp_fp;
		const errno_t cfp_error = fopen_s(&cfp_fp, file_name, "wb");
		if (cfp_error) return -1;

		fwrite(write_buf, write_size, write_nmemb, cfp_fp);
		fclose(cfp_fp);
		return 0;
	}

#endif

#if defined(__DXLIB) //DxLib

	//��ʃT�C�Y�ύX
	int32_t AsChangeWindowSize(const Pos2& window_size = WINDOW_SIZE)
	{
		return int32_t(DxLib::SetGraphMode(window_size.x, window_size.y, 32));
	}

	//�w�i�F�ύX
	int32_t AsChangeColorBG(const ColorRGB& BG_color = BG_COLOR)
	{
		return int32_t(DxLib::SetBackgroundColor(BG_color.r, BG_color.g, BG_color.b));
	}

	//�^�C�g���ύX
	int32_t AsChangeTitle(const char* const title)
	{
		return int32_t(DxLib::SetMainWindowText(title));
	}

	int32_t AsChangeTitle(const std::string& title)
	{
		return int32_t(DxLib::SetMainWindowText(title.c_str()));
	}

	//������
	int32_t AsInit(const Pos2& window_size = WINDOW_SIZE, const ColorRGB& BG_color = BG_COLOR)
	{
		if (DxLib::SetOutApplicationLogValidFlag(FALSE) == -1) return -1;
#if defined(__WINDOWS__)
		if (DxLib::ChangeWindowMode(TRUE) == -1) return -1;
		if (AsChangeWindowSize(window_size) == -1) return -1;
#endif
		if (AsChangeColorBG(BG_color) == -1) return -1;
		if (DxLib::DxLib_Init() == -1) return -1;

		if (DxLib::SetChangeScreenModeGraphicsSystemResetFlag(FALSE) == -1) return -1;
		if (DxLib::SetDXArchiveExtension("as") == -1) return -1;

		if (DxLib::SetDrawScreen(DX_SCREEN_BACK)) return -1;
		return 0;
	}

	//�I������
	int32_t AsEnd()
	{
		if (DxLib::DxLib_End() == -1) return -1;
		return 0;
	}

	//DxLib��p�J���[�R�[�h�ϊ�
	unsigned int AsDxColor(const ColorRGB& colorRGB = {})
	{
		return DxLib::GetColor(int(colorRGB.r), int(colorRGB.g), int(colorRGB.b));
	}

	unsigned int AsDxColor(const ColorRGBA& colorRGBA = {})
	{
		return DxLib::GetColor(int(colorRGBA.r), int(colorRGBA.g), int(colorRGBA.b));
	}

	//�����o��
	template<typename... Rest>
	inline int32_t AsPrint(const char* format_string, const Rest&... rest)
	{
		if (DxLib::printfDx(format_string, rest...) == -1) return -1;
		return 0;
	}

	template<typename... Rest>
	inline int32_t AsPrint(const std::string& format_string, const Rest&... rest)
	{
		if (DxLib::printfDx(format_string.c_str(), rest...) == -1) return -1;
		return 0;
}


#elif defined(SIV3D_INCLUDED) //Siv3D

#else //Console

#endif

	int32_t AsInit(const char* const title = "", const Pos2& window_size = WINDOW_SIZE, const ColorRGB& BG_color = BG_COLOR)
	{
		if (AsChangeTitle(title) == -1) return -1;
		return AsInit(window_size, BG_color);
	}

	int32_t AsInit(const std::string& title = "", const Pos2& window_size = WINDOW_SIZE, const ColorRGB& BG_color = BG_COLOR)
	{
		if (AsChangeTitle(title.c_str()) == -1) return -1;
		return AsInit(window_size, BG_color);
	}


}