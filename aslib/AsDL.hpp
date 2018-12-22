//    ----------     ----------     ----------     ----------     ----------
//
//                             AsLib - AsProject Library
//
//                   Created by Gaccho (wanotaitei@gmail.com)
//
//    ----------     ----------     ----------     ----------     ----------
#ifndef INCLUDED_AS_PROJECT_LIBRARY_DL
#define INCLUDED_AS_PROJECT_LIBRARY_DL



namespace AsLib
{

#if !defined(ASLIB_INCLUDE_DL)
	constexpr double DX_PI = 3.1415926535897932384626433832795;
	constexpr float DX_PI_F = 3.1415926535897932384626433832795f;
	constexpr double DX_TWO_PI = 3.1415926535897932384626433832795  * 2.0;
	constexpr float DX_TWO_PI_F = 3.1415926535897932384626433832795f * 2.0f;

	using DX_CHAR = char;

	#define  DX_DEFINE_START

	constexpr int MAX_IMAGE_NUM = 32768;
	constexpr int MAX_2DSURFACE_NUM = 32768;
	constexpr int MAX_3DSURFACE_NUM = 65536;
	constexpr int MAX_IMAGE_DIVNUM = 64;
	constexpr int MAX_SURFACE_NUM = 65536;
	constexpr int MAX_SHADOWMAP_NUM = 8192;
	constexpr int MAX_SOFTIMAGE_NUM = 8192;

	constexpr int MAX_SOUND_NUM = 32768;
	constexpr int MAX_SOFTSOUND_NUM = 8192;
	constexpr int MAX_MUSIC_NUM = 256;
	constexpr int MAX_MOVIE_NUM = 100;
	constexpr int MAX_MASK_NUM = 512;
	constexpr int MAX_FONT_NUM = 40;
	constexpr int MAX_INPUT_NUM = 256;
	constexpr int MAX_SOCKET_NUM = 8192;
	constexpr int MAX_LIGHT_NUM = 4096;
	constexpr int MAX_SHADER_NUM = 4096;
	constexpr int MAX_CONSTANT_BUFFER_NUM = 8192;
	constexpr int MAX_MODEL_BASE_NUM = 32768;
	constexpr int MAX_MODEL_NUM = 32768;
	constexpr int MAX_VERTEX_BUFFER_NUM = 16384;
	constexpr int MAX_INDEX_BUFFER_NUM = 16384;
	constexpr int MAX_FILE_NUM = 32768;
	constexpr int MAX_JOYPAD_NUM = 16;

constexpr int DEFAULT_SCREEN_SIZE_X = 640;
constexpr int DEFAULT_SCREEN_SIZE_Y = 480;
constexpr int DEFAULT_COLOR_BITDEPTH = 16;
constexpr int DEFAULT_ZBUFFER_BITDEPTH = 16;
constexpr float DEFAULT_FOV = 60.0F * 3.1415926535897932384626433832795F / 180.0F;
constexpr float DEFAULT_TAN_FOV_HALF = 0.57735026918962576450914878050196F;
constexpr float DEFAULT_NEAR = 0.0F;
constexpr float DEFAULT_FAR = 20000.0F;
constexpr int DX_DEFAULT_FONT_HANDLE = -2;
constexpr int DEFAULT_FONT_SIZE = 16;
constexpr int DEFAULT_FONT_THINCK = 6;
constexpr int DEFAULT_FONT_EDGESIZE = 1;

constexpr int MAX_USERIMAGEREAD_FUNCNUM = 10;

	//ＷＩＮＤＯＷＳのバージョンマクロ
constexpr int DX_WINDOWSVERSION_31 = 0x000;
constexpr int DX_WINDOWSVERSION_95 = 0x001;
constexpr int DX_WINDOWSVERSION_98 = 0x002;
constexpr int DX_WINDOWSVERSION_ME = 0x003;
constexpr int DX_WINDOWSVERSION_NT31 = 0x104;
constexpr int DX_WINDOWSVERSION_NT40 = 0x105;
constexpr int DX_WINDOWSVERSION_2000 = 0x106;
constexpr int DX_WINDOWSVERSION_XP = 0x107;
constexpr int DX_WINDOWSVERSION_VISTA = 0x108;
constexpr int DX_WINDOWSVERSION_7 = 0x109;
constexpr int DX_WINDOWSVERSION_8 = 0x10A;
constexpr int DX_WINDOWSVERSION_8_1 = 0x10B;
constexpr int DX_WINDOWSVERSION_10 = 0x10C;
constexpr int DX_WINDOWSVERSION_NT_TYPE = 0x100;

	//DirectXのバージョン
constexpr int DX_DIRECTXVERSION_NON = 0;
constexpr int DX_DIRECTXVERSION_1 = 0x10000;
constexpr int DX_DIRECTXVERSION_2 = 0x20000;
constexpr int DX_DIRECTXVERSION_3 = 0x30000;
constexpr int DX_DIRECTXVERSION_4 = 0x40000;
constexpr int DX_DIRECTXVERSION_5 = 0x50000;
constexpr int DX_DIRECTXVERSION_6 = 0x60000;
constexpr int DX_DIRECTXVERSION_6_1 = 0x60100;
constexpr int DX_DIRECTXVERSION_7 = 0x70000;
constexpr int DX_DIRECTXVERSION_8 = 0x80000;
constexpr int DX_DIRECTXVERSION_8_1 = 0x80100;

	//Direct3Dのバージョン
	enum :int {
		DX_DIRECT3D_NONE,
		DX_DIRECT3D_9,
		DX_DIRECT3D_9EX,
		DX_DIRECT3D_11,
	};

	//Direct3D11 の Feature Level
	constexpr int DX_DIRECT3D_11_FEATURE_LEVEL_9_1 = 0x9100;
	constexpr int DX_DIRECT3D_11_FEATURE_LEVEL_9_2 = 0x9200;
	constexpr int DX_DIRECT3D_11_FEATURE_LEVEL_9_3 = 0x9300;
	constexpr int DX_DIRECT3D_11_FEATURE_LEVEL_10_0 = 0xa000;
	constexpr int DX_DIRECT3D_11_FEATURE_LEVEL_10_1 = 0xa100;
	constexpr int DX_DIRECT3D_11_FEATURE_LEVEL_11_0 = 0xb000;
	constexpr int DX_DIRECT3D_11_FEATURE_LEVEL_11_1 = 0xb100;

	//文字セット
	enum :int {
		DX_CHARSET_DEFAULT,
		DX_CHARSET_SHFTJIS,
		DX_CHARSET_HANGEUL,
		DX_CHARSET_BIG5,
		DX_CHARSET_GB2312,
		DX_CHARSET_WINDOWS_1252,
		DX_CHARSET_ISO_IEC_8859_15,
		DX_CHARSET_UTF8,
		DX_CHARSET_NUM,
	};

	//文字コード形式
	constexpr int DX_CHARCODEFORMAT_SHIFTJIS = 932;
	constexpr int DX_CHARCODEFORMAT_GB2312 = 936;
	constexpr int DX_CHARCODEFORMAT_UHC = 949;
	constexpr int DX_CHARCODEFORMAT_BIG5 = 950;
	constexpr int DX_CHARCODEFORMAT_UTF16LE = 1200;
	constexpr int DX_CHARCODEFORMAT_UTF16BE = 1201;
	constexpr int DX_CHARCODEFORMAT_WINDOWS_1252 = 1252;
	constexpr int DX_CHARCODEFORMAT_ISO_IEC_8859_15 = 32764;
	constexpr int DX_CHARCODEFORMAT_UTF8 = 65001;
	constexpr int DX_CHARCODEFORMAT_ASCII = 32765;
	constexpr int DX_CHARCODEFORMAT_UTF32LE = 32766;
	constexpr int DX_CHARCODEFORMAT_UTF32BE = 32767;

	//ＭＩＤＩの演奏モード定義
	enum :int {
		DX_MIDIMODE_MCI,
		DX_MIDIMODE_DM,
		DX_MIDIMODE_DIRECT_MUSIC_REVERB,
		DX_MIDIMODE_DIRECT_MUSIC_NORMAL,
		DX_MIDIMODE_NUM,
	};

	//描画モード定義
	enum :int {
		DX_DRAWMODE_NEAREST,
		DX_DRAWMODE_BILINEAR,
		DX_DRAWMODE_ANISOTROPIC,
		DX_DRAWMODE_OTHER,
		DX_DRAWMODE_NUM,
	};

	//フォントのタイプ
	constexpr int DX_FONTTYPE_NORMAL = 0x00;
	constexpr int DX_FONTTYPE_EDGE = 0x01;
	constexpr int DX_FONTTYPE_ANTIALIASING = 0x02;
	constexpr int DX_FONTTYPE_ANTIALIASING_4X4 = 0x12;
	constexpr int DX_FONTTYPE_ANTIALIASING_8X8 = 0x22;
	constexpr int DX_FONTTYPE_ANTIALIASING_EDGE = 0x03;
	constexpr int DX_FONTTYPE_ANTIALIASING_EDGE_4X4 = 0x13;
	constexpr int DX_FONTTYPE_ANTIALIASING_EDGE_8X8 = 0x23;

	constexpr int DEFAULT_FONT_TYPE = DX_FONTTYPE_NORMAL;

	//フォント画像の階調ビット数
	enum :int {
		DX_FONTIMAGE_BIT_1,
		DX_FONTIMAGE_BIT_4,
		DX_FONTIMAGE_BIT_8,
	};

	//描画ブレンドモード定義
	enum :int {
		DX_BLENDMODE_NOBLEND,
		DX_BLENDMODE_ALPHA,
		DX_BLENDMODE_ADD,
		DX_BLENDMODE_SUB,
		DX_BLENDMODE_MUL,
		//(内部処理用)
		DX_BLENDMODE_SUB2,
		DX_BLENDMODE_XOR,
		DX_BLENDMODE_BLINEALPHA,//
		DX_BLENDMODE_DESTCOLOR,
		DX_BLENDMODE_INVDESTCOLOR,
		DX_BLENDMODE_INVSRC,
		DX_BLENDMODE_MULA,
		DX_BLENDMODE_ALPHA_X4,
		DX_BLENDMODE_ADD_X4,
		DX_BLENDMODE_SRCCOLOR,
		DX_BLENDMODE_HALF_ADD,
		DX_BLENDMODE_SUB1,
		DX_BLENDMODE_PMA_ALPHA,
		DX_BLENDMODE_PMA_ADD,
		DX_BLENDMODE_PMA_SUB,
		DX_BLENDMODE_PMA_INVSRC,
		DX_BLENDMODE_PMA_ALPHA_X4,
		DX_BLENDMODE_PMA_ADD_X4,
		DX_BLENDMODE_NUM,
	};

	//DrawGraphF 等の浮動小数点値で座標を指定する関数における座標タイプ
	enum :int {
		DX_DRAWFLOATCOORDTYPE_DIRECT3D9,
		DX_DRAWFLOATCOORDTYPE_DIRECT3D10,
	};

	//画像合成タイプ
	enum :int {
		DX_BLENDGRAPHTYPE_NORMAL,
		DX_BLENDGRAPHTYPE_WIPE,
		DX_BLENDGRAPHTYPE_ALPHA,
		DX_BLENDGRAPHTYPE_NUM,
	};

	//画像合成座標タイプ
	enum :int {
		DX_BLENDGRAPH_POSMODE_DRAWGRAPH,
		DX_BLENDGRAPH_POSMODE_SCREEN,
		DX_BLENDGRAPH_POSMODE_NUM,
	};

	//グラフィックフィルタータイプ
	enum :int {
		DX_GRAPH_FILTER_MONO,
		DX_GRAPH_FILTER_GAUSS,
		DX_GRAPH_FILTER_DOWN_SCALE,
		DX_GRAPH_FILTER_BRIGHT_CLIP,
		DX_GRAPH_FILTER_BRIGHT_SCALE,
		DX_GRAPH_FILTER_HSB,
		DX_GRAPH_FILTER_INVERT,
		DX_GRAPH_FILTER_LEVEL,
		DX_GRAPH_FILTER_TWO_COLOR,
		DX_GRAPH_FILTER_GRADIENT_MAP,
		DX_GRAPH_FILTER_PREMUL_ALPHA,
		DX_GRAPH_FILTER_INTERP_ALPHA,
		DX_GRAPH_FILTER_YUV_TO_RGB,
		DX_GRAPH_FILTER_Y2UV1_TO_RGB,
		DX_GRAPH_FILTER_YUV_TO_RGB_RRA,
		DX_GRAPH_FILTER_Y2UV1_TO_RGB_RRA,
		DX_GRAPH_FILTER_BICUBIC_SCALE,
		DX_GRAPH_FILTER_LANCZOS3_SCALE,
		DX_GRAPH_FILTER_PMA_BRIGHT_CLIP,
		DX_GRAPH_FILTER_PMA_BRIGHT_SCALE,
		DX_GRAPH_FILTER_PMA_HSB,
		DX_GRAPH_FILTER_PMA_INVERT,
		DX_GRAPH_FILTER_PMA_LEVEL,
		DX_GRAPH_FILTER_PMA_TWO_COLOR,
		DX_GRAPH_FILTER_PMA_GRADIENT_MAP,
		DX_GRAPH_FILTER_NUM,
	};

	//グラフィックブレンドタイプ
	enum :int {
		DX_GRAPH_BLEND_NORMAL,
		DX_GRAPH_BLEND_RGBA_SELECT_MIX,
		DX_GRAPH_BLEND_MULTIPLE,
		DX_GRAPH_BLEND_DIFFERENCE,
		DX_GRAPH_BLEND_ADD,
		DX_GRAPH_BLEND_SCREEN,
		DX_GRAPH_BLEND_OVERLAY,
		DX_GRAPH_BLEND_DODGE,
		DX_GRAPH_BLEND_BURN,
		DX_GRAPH_BLEND_DARKEN,
		DX_GRAPH_BLEND_LIGHTEN,
		DX_GRAPH_BLEND_SOFTLIGHT,
		DX_GRAPH_BLEND_HARDLIGHT,
		DX_GRAPH_BLEND_EXCLUSION,
		DX_GRAPH_BLEND_NORMAL_ALPHACH,
		DX_GRAPH_BLEND_ADD_ALPHACH,
		DX_GRAPH_BLEND_MULTIPLE_A_ONLY,
		DX_GRAPH_BLEND_PMA_NORMAL,
		DX_GRAPH_BLEND_PMA_RGBA_SELECT_MIX,
		DX_GRAPH_BLEND_PMA_MULTIPLE,
		DX_GRAPH_BLEND_PMA_DIFFERENCE,
		DX_GRAPH_BLEND_PMA_ADD,
		DX_GRAPH_BLEND_PMA_SCREEN,
		DX_GRAPH_BLEND_PMA_OVERLAY,
		DX_GRAPH_BLEND_PMA_DODGE,
		DX_GRAPH_BLEND_PMA_BURN,
		DX_GRAPH_BLEND_PMA_DARKEN,
		DX_GRAPH_BLEND_PMA_LIGHTEN,
		DX_GRAPH_BLEND_PMA_SOFTLIGHT,
		DX_GRAPH_BLEND_PMA_HARDLIGHT,
		DX_GRAPH_BLEND_PMA_EXCLUSION,
		DX_GRAPH_BLEND_PMA_NORMAL_ALPHACH,
		DX_GRAPH_BLEND_PMA_ADD_ALPHACH,
		DX_GRAPH_BLEND_PMA_MULTIPLE_A_ONLY,
		DX_GRAPH_BLEND_NUM,
	};

	//DX_GRAPH_BLEND_RGBA_SELECT_MIX 用の色選択用定義
	enum :int {
		DX_RGBA_SELECT_SRC_R,
		DX_RGBA_SELECT_SRC_G,
		DX_RGBA_SELECT_SRC_B,
		DX_RGBA_SELECT_SRC_A,
		DX_RGBA_SELECT_BLEND_R,
		DX_RGBA_SELECT_BLEND_G,
		DX_RGBA_SELECT_BLEND_B,
		DX_RGBA_SELECT_BLEND_A,
	};

	//フィルモード
	constexpr int DX_FILL_WIREFRAME=2;
	constexpr int DX_FILL_SOLID=3;

	//ポリゴンカリングモード
	enum :int {
		DX_CULLING_NONE,
		DX_CULLING_LEFT,
		DX_CULLING_RIGHT,
		DX_CULLING_NUM,
	};

	//クリッピング方向
	constexpr int DX_CAMERACLIP_LEFT=0x01;
	constexpr int DX_CAMERACLIP_RIGHT=0x02;
	constexpr int DX_CAMERACLIP_BOTTOM=0x04;
	constexpr int DX_CAMERACLIP_TOP=0x08;
	constexpr int DX_CAMERACLIP_BACK=0x10;
	constexpr int DX_CAMERACLIP_FRONT=0x20;

	//MV1モデルの頂点タイプ
	enum :int {
		DX_MV1_VERTEX_TYPE_1FRAME,
		DX_MV1_VERTEX_TYPE_4FRAME,
		DX_MV1_VERTEX_TYPE_8FRAME,
		DX_MV1_VERTEX_TYPE_FREE_FRAME,
		DX_MV1_VERTEX_TYPE_NMAP_1FRAME,
		DX_MV1_VERTEX_TYPE_NMAP_4FRAME,
		DX_MV1_VERTEX_TYPE_NMAP_8FRAME,
		DX_MV1_VERTEX_TYPE_NMAP_FREE_FRAME,
		DX_MV1_VERTEX_TYPE_NUM,
	};

	//メッシュの種類
	enum :int {
		DX_MV1_MESHCATEGORY_NORMAL,
		DX_MV1_MESHCATEGORY_OUTLINE,
		DX_MV1_MESHCATEGORY_OUTLINE_ORIG_SHADER,
		DX_MV1_MESHCATEGORY_NUM,
	};

	//MV1ファイルの保存タイプ
	constexpr int MV1_SAVETYPE_MESH=0x0001;
	constexpr int MV1_SAVETYPE_ANIM=0x0002;
	constexpr int MV1_SAVETYPE_NORMAL=(MV1_SAVETYPE_MESH | MV1_SAVETYPE_ANIM);

	//アニメーションキーデータタイプ
	constexpr int MV1_ANIMKEY_DATATYPE_ROTATE = 0;
	constexpr int MV1_ANIMKEY_DATATYPE_ROTATE_X = 1;
	constexpr int MV1_ANIMKEY_DATATYPE_ROTATE_Y = 2;
	constexpr int MV1_ANIMKEY_DATATYPE_ROTATE_Z = 3;
	constexpr int MV1_ANIMKEY_DATATYPE_SCALE = 5;
	constexpr int MV1_ANIMKEY_DATATYPE_SCALE_X = 6;
	constexpr int MV1_ANIMKEY_DATATYPE_SCALE_Y = 7;
	constexpr int MV1_ANIMKEY_DATATYPE_SCALE_Z = 8;
	constexpr int MV1_ANIMKEY_DATATYPE_TRANSLATE = 10;
	constexpr int MV1_ANIMKEY_DATATYPE_TRANSLATE_X = 11;
	constexpr int MV1_ANIMKEY_DATATYPE_TRANSLATE_Y = 12;
	constexpr int MV1_ANIMKEY_DATATYPE_TRANSLATE_Z = 13;
	constexpr int MV1_ANIMKEY_DATATYPE_MATRIX4X4C = 15;
	constexpr int MV1_ANIMKEY_DATATYPE_MATRIX3X3 = 17;
	constexpr int MV1_ANIMKEY_DATATYPE_SHAPE = 18;
	constexpr int MV1_ANIMKEY_DATATYPE_OTHRE = 20;

	//タイムタイプ
	enum :int {
		MV1_ANIMKEY_TIME_TYPE_ONE,
		MV1_ANIMKEY_TIME_TYPE_KEY,
	};

	//アニメーションキータイプ
	enum :int {
		MV1_ANIMKEY_TYPE_QUATERNION_X,
		MV1_ANIMKEY_TYPE_VECTOR,
		MV1_ANIMKEY_TYPE_MATRIX4X4C,
		MV1_ANIMKEY_TYPE_MATRIX3X3,
		MV1_ANIMKEY_TYPE_FLAT,
		MV1_ANIMKEY_TYPE_LINEAR,
		MV1_ANIMKEY_TYPE_BLEND,
		MV1_ANIMKEY_TYPE_QUATERNION_VMD,
	};

	//描画先画面指定用定義
	constexpr int DX_SCREEN_FRONT = 0xfffffffc;
	constexpr int DX_SCREEN_BACK = 0xfffffffe;
	constexpr int DX_SCREEN_WORK = 0xfffffffd;
	constexpr int DX_SCREEN_TEMPFRONT = 0xfffffff0;
	constexpr int DX_SCREEN_OTHER = 0xfffffffa;
	constexpr int DX_NONE_GRAPH = 0xfffffffb;

	//グラフィック減色時の画像劣化緩和処理モード
	enum :int {
		DX_SHAVEDMODE_NONE,
		DX_SHAVEDMODE_DITHER,
		DX_SHAVEDMODE_DIFFUS,
	};

	//画像の保存タイプ
	enum :int {
		DX_IMAGESAVETYPE_BMP,
		DX_IMAGESAVETYPE_JPEG,
		DX_IMAGESAVETYPE_PNG,
		DX_IMAGESAVETYPE_DDS,
	};

	//サウンド再生形態指定用定義
	constexpr int DX_PLAYTYPE_LOOPBIT = 0x0002;
	constexpr int DX_PLAYTYPE_BACKBIT = 0x0001;

	constexpr int DX_PLAYTYPE_NORMAL = 0;
	constexpr int DX_PLAYTYPE_BACK = DX_PLAYTYPE_BACKBIT;
	constexpr int DX_PLAYTYPE_LOOP = (DX_PLAYTYPE_LOOPBIT | DX_PLAYTYPE_BACKBIT);

	//動画再生タイプ定義
	enum :int {
		DX_MOVIEPLAYTYPE_BCANCEL,
		DX_MOVIEPLAYTYPE_NORMAL,
	};

	//サウンドのタイプ
	enum :int {
		DX_SOUNDTYPE_NORMAL,
		DX_SOUNDTYPE_STREAMSTYLE,
	};

	//サウンドデータタイプのマクロ
	enum :int {
		DX_SOUNDDATATYPE_MEMNOPRESS,
		DX_SOUNDDATATYPE_MEMNOPRESS_PLUS,
		DX_SOUNDDATATYPE_MEMPRESS,
		DX_SOUNDDATATYPE_FILE,
	};

	//読み込み処理のタイプ
	constexpr int DX_READSOUNDFUNCTION_PCM=(1 << 0);
	constexpr int DX_READSOUNDFUNCTION_OGG=(1 << 1);
	constexpr int DX_READSOUNDFUNCTION_OPUS=(1 << 2);
	constexpr int DX_READSOUNDFUNCTION_DEFAULT_NUM=3;

	//３Ｄサウンドリバーブエフェクトのプリセット
	enum :int {
		DX_REVERB_PRESET_DEFAULT,
		DX_REVERB_PRESET_GENERIC,
		DX_REVERB_PRESET_PADDEDCELL,
		DX_REVERB_PRESET_ROOM,
		DX_REVERB_PRESET_BATHROOM,
		DX_REVERB_PRESET_LIVINGROOM,
		DX_REVERB_PRESET_STONEROOM,
		DX_REVERB_PRESET_AUDITORIUM,
		DX_REVERB_PRESET_CONCERTHALL,
		DX_REVERB_PRESET_CAVE,
		DX_REVERB_PRESET_ARENA,
		DX_REVERB_PRESET_HANGAR,
		DX_REVERB_PRESET_CARPETEDHALLWAY,
		DX_REVERB_PRESET_HALLWAY,
		DX_REVERB_PRESET_STONECORRIDOR,
		DX_REVERB_PRESET_ALLEY,
		DX_REVERB_PRESET_FOREST,
		DX_REVERB_PRESET_CITY,
		DX_REVERB_PRESET_MOUNTAINS,
		DX_REVERB_PRESET_QUARRY,
		DX_REVERB_PRESET_PLAIN,
		DX_REVERB_PRESET_PARKINGLOT,
		DX_REVERB_PRESET_SEWERPIPE,
		DX_REVERB_PRESET_UNDERWATER,
		DX_REVERB_PRESET_SMALLROOM,
		DX_REVERB_PRESET_MEDIUMROOM,
		DX_REVERB_PRESET_LARGEROOM,
		DX_REVERB_PRESET_MEDIUMHALL,
		DX_REVERB_PRESET_LARGEHALL,
		DX_REVERB_PRESET_PLATE,
		DX_REVERB_PRESET_NUM,
	};

	//マスク透過色モード
	enum :int {
		DX_MASKTRANS_WHITE,
		DX_MASKTRANS_BLACK,
		DX_MASKTRANS_NONE,
	};

	//マスク画像チャンネル
	enum :int {
		DX_MASKGRAPH_CH_A,
		DX_MASKGRAPH_CH_R,
		DX_MASKGRAPH_CH_G,
		DX_MASKGRAPH_CH_B,
	};

	//Ｚバッファ書き込みモード
	enum :int {
		DX_ZWRITE_MASK,
		DX_ZWRITE_CLEAR,
	};

	//比較モード
	enum :int {
		DX_CMP_NEVER = 1,
		DX_CMP_LESS,
		DX_CMP_EQUAL,
		DX_CMP_LESSEQUAL,
		DX_CMP_GREATER,
		DX_CMP_NOTEQUAL,
		DX_CMP_GREATEREQUAL,
		DX_CMP_ALWAYS,
	};
	constexpr int DX_ZCMP_DEFAULT=DX_CMP_LESSEQUAL;
	constexpr int DX_ZCMP_REVERSE=DX_CMP_GREATEREQUAL;

	//シェーディングモード
	enum :int {
		DX_SHADEMODE_FLAT = 1,
		DX_SHADEMODE_GOURAUD,
	};

	//フォグモード
	enum :int {
		DX_FOGMODE_NONE,
		DX_FOGMODE_EXP,
		DX_FOGMODE_EXP2,
		DX_FOGMODE_LINEAR,
	};

	//マテリアルタイプ
	enum :int {
		DX_MATERIAL_TYPE_NORMAL,
		DX_MATERIAL_TYPE_TOON,
		DX_MATERIAL_TYPE_TOON_2,
		DX_MATERIAL_TYPE_MAT_SPEC_LUMINANCE_UNORM,
		DX_MATERIAL_TYPE_MAT_SPEC_LUMINANCE_CLIP_UNORM,
		DX_MATERIAL_TYPE_MAT_SPEC_LUMINANCE_CMP_GREATEREQUAL,
		DX_MATERIAL_TYPE_MAT_SPEC_POWER_UNORM,
		DX_MATERIAL_TYPE_MAT_SPEC_POWER_CLIP_UNORM,
		DX_MATERIAL_TYPE_MAT_SPEC_POWER_CMP_GREATEREQUAL,
		DX_MATERIAL_TYPE_NUM,
	};

	//マテリアルブレンドタイプ
	enum :int {
		DX_MATERIAL_BLENDTYPE_TRANSLUCENT,
		DX_MATERIAL_BLENDTYPE_ADDITIVE,
		DX_MATERIAL_BLENDTYPE_MODULATE,
		DX_MATERIAL_BLENDTYPE_NONE,
	};

	//テクスチャアドレスタイプ
	enum :int {
		DX_TEXADDRESS_WRAP = 1,
		DX_TEXADDRESS_MIRROR,
		DX_TEXADDRESS_CLAMP,
		DX_TEXADDRESS_BORDER,
		DX_TEXADDRESS_NUM,
	};

	//シェーダータイプ
	enum :int {
		DX_SHADERTYPE_VERTEX,
		DX_SHADERTYPE_PIXEL,
		DX_SHADERTYPE_GEOMETRY,
		DX_SHADERTYPE_COMPUTE,
		DX_SHADERTYPE_DOMAIN,
		DX_SHADERTYPE_HULL,
	};

	//頂点データタイプ
	enum :int {
		DX_VERTEX_TYPE_NORMAL_3D,
		DX_VERTEX_TYPE_SHADER_3D,
		DX_VERTEX_TYPE_NUM,
	};

	//インデックスデータタイプ
	enum :int {
		DX_INDEX_TYPE_16BIT,
		DX_INDEX_TYPE_32BIT,
	};

	//モデルファイル読み込み時の物理演算モード
	enum :int {
		DX_LOADMODEL_PHYSICS_LOADCALC,
		DX_LOADMODEL_PHYSICS_DISABLE,
		DX_LOADMODEL_PHYSICS_REALTIME,
	};

	//モデルファイル読み込み時の物理演算無効名前ワードのモード
	enum :int {
		DX_LOADMODEL_PHYSICS_DISABLENAMEWORD_ALWAYS,
		DX_LOADMODEL_PHYSICS_DISABLENAMEWORD_DISABLEPHYSICSFILEONLY,
		DX_LOADMODEL_PHYSICS_DISABLENAMEWORD_NUM,
	};

	//PMD, PMX ファイル読み込み時のアニメーションの FPS モード( 主に IK 部分の精度に影響します )
	enum :int {
		DX_LOADMODEL_PMD_PMX_ANIMATION_FPSMODE_30,
		DX_LOADMODEL_PMD_PMX_ANIMATION_FPSMODE_60,
	};

	//モデルの半透明要素がある箇所に関する描画モード
	enum :int {
		DX_SEMITRANSDRAWMODE_ALWAYS,
		DX_SEMITRANSDRAWMODE_SEMITRANS_ONLY,
		DX_SEMITRANSDRAWMODE_NOT_SEMITRANS_ONLY,
	};

	//キューブマップの面番号
	enum :int {
		DX_CUBEMAP_FACE_POSITIVE_X,
		DX_CUBEMAP_FACE_NEGATIVE_X,
		DX_CUBEMAP_FACE_POSITIVE_Y,
		DX_CUBEMAP_FACE_NEGATIVE_Y,
		DX_CUBEMAP_FACE_POSITIVE_Z,
		DX_CUBEMAP_FACE_NEGATIVE_Z,
	};

	//ポリゴン描画タイプ
	constexpr int DX_PRIMTYPE_POINTLIST=1;
	constexpr int DX_PRIMTYPE_LINELIST=2;
	constexpr int DX_PRIMTYPE_LINESTRIP=3;
	constexpr int DX_PRIMTYPE_TRIANGLELIST=4;
	constexpr int DX_PRIMTYPE_TRIANGLESTRIP=5;
	constexpr int DX_PRIMTYPE_TRIANGLEFAN=6;
	constexpr int DX_PRIMTYPE_MIN=1;
	constexpr int DX_PRIMTYPE_MAX=6;

	//ライトタイプ
	constexpr int DX_LIGHTTYPE_D3DLIGHT_POINT=1;
	constexpr int DX_LIGHTTYPE_D3DLIGHT_SPOT=2;
	constexpr int DX_LIGHTTYPE_D3DLIGHT_DIRECTIONAL=3;
	constexpr int DX_LIGHTTYPE_POINT=1;
	constexpr int DX_LIGHTTYPE_SPOT=2;
	constexpr int DX_LIGHTTYPE_DIRECTIONAL=3;

	//グラフィックイメージフォーマットの定義
	enum :int {
		DX_GRAPHICSIMAGE_FORMAT_3D_PAL4,
		DX_GRAPHICSIMAGE_FORMAT_3D_PAL8,
		DX_GRAPHICSIMAGE_FORMAT_3D_ALPHA_PAL4,
		DX_GRAPHICSIMAGE_FORMAT_3D_ALPHA_PAL8,
		DX_GRAPHICSIMAGE_FORMAT_3D_ALPHATEST_PAL4,
		DX_GRAPHICSIMAGE_FORMAT_3D_ALPHATEST_PAL8,
		DX_GRAPHICSIMAGE_FORMAT_3D_RGB16,
		DX_GRAPHICSIMAGE_FORMAT_3D_RGB32,
		DX_GRAPHICSIMAGE_FORMAT_3D_ALPHA_RGB16,
		DX_GRAPHICSIMAGE_FORMAT_3D_ALPHA_RGB32,
		DX_GRAPHICSIMAGE_FORMAT_3D_ALPHATEST_RGB16,
		DX_GRAPHICSIMAGE_FORMAT_3D_ALPHATEST_RGB32,
		DX_GRAPHICSIMAGE_FORMAT_3D_DXT1,
		DX_GRAPHICSIMAGE_FORMAT_3D_DXT2,
		DX_GRAPHICSIMAGE_FORMAT_3D_DXT3,
		DX_GRAPHICSIMAGE_FORMAT_3D_DXT4,
		DX_GRAPHICSIMAGE_FORMAT_3D_DXT5,
		DX_GRAPHICSIMAGE_FORMAT_3D_PLATFORM0,
		DX_GRAPHICSIMAGE_FORMAT_3D_PLATFORM1,
		DX_GRAPHICSIMAGE_FORMAT_3D_PLATFORM2,
		DX_GRAPHICSIMAGE_FORMAT_3D_PLATFORM3,
		DX_GRAPHICSIMAGE_FORMAT_3D_YUV,
		DX_GRAPHICSIMAGE_FORMAT_3D_ABGR_I16,
		DX_GRAPHICSIMAGE_FORMAT_3D_ABGR_F16,
		DX_GRAPHICSIMAGE_FORMAT_3D_ABGR_F32,
		DX_GRAPHICSIMAGE_FORMAT_3D_ONE_I8,
		DX_GRAPHICSIMAGE_FORMAT_3D_ONE_I16,
		DX_GRAPHICSIMAGE_FORMAT_3D_ONE_F16,
		DX_GRAPHICSIMAGE_FORMAT_3D_ONE_F32,
		DX_GRAPHICSIMAGE_FORMAT_3D_TWO_I8,
		DX_GRAPHICSIMAGE_FORMAT_3D_TWO_I16,
		DX_GRAPHICSIMAGE_FORMAT_3D_TWO_F16,
		DX_GRAPHICSIMAGE_FORMAT_3D_TWO_F32,
		DX_GRAPHICSIMAGE_FORMAT_3D_DRAWVALID_RGB16,
		DX_GRAPHICSIMAGE_FORMAT_3D_DRAWVALID_RGB32,
		DX_GRAPHICSIMAGE_FORMAT_3D_DRAWVALID_ALPHA_RGB32,
		DX_GRAPHICSIMAGE_FORMAT_3D_DRAWVALID_ABGR_I16,
		DX_GRAPHICSIMAGE_FORMAT_3D_DRAWVALID_ABGR_F16,
		DX_GRAPHICSIMAGE_FORMAT_3D_DRAWVALID_ABGR_F32,
		DX_GRAPHICSIMAGE_FORMAT_3D_DRAWVALID_ONE_I8,
		DX_GRAPHICSIMAGE_FORMAT_3D_DRAWVALID_ONE_I16,
		DX_GRAPHICSIMAGE_FORMAT_3D_DRAWVALID_ONE_F16,
		DX_GRAPHICSIMAGE_FORMAT_3D_DRAWVALID_ONE_F32,
		DX_GRAPHICSIMAGE_FORMAT_3D_DRAWVALID_TWO_I8,
		DX_GRAPHICSIMAGE_FORMAT_3D_DRAWVALID_TWO_I16,
		DX_GRAPHICSIMAGE_FORMAT_3D_DRAWVALID_TWO_F16,
		DX_GRAPHICSIMAGE_FORMAT_3D_DRAWVALID_TWO_F32,
		DX_GRAPHICSIMAGE_FORMAT_3D_NUM,
		DX_GRAPHICSIMAGE_FORMAT_2D,
		DX_GRAPHICSIMAGE_FORMAT_R5G6B5,
		DX_GRAPHICSIMAGE_FORMAT_X8A8R5G6B5,
		DX_GRAPHICSIMAGE_FORMAT_X8R8G8B8,
		DX_GRAPHICSIMAGE_FORMAT_A8R8G8B8,
		DX_GRAPHICSIMAGE_FORMAT_NUM,
	};
	//基本イメージのピクセルフォーマット
	enum :int {
		DX_BASEIMAGE_FORMAT_NORMAL,
		DX_BASEIMAGE_FORMAT_DXT1,
		DX_BASEIMAGE_FORMAT_DXT2,
		DX_BASEIMAGE_FORMAT_DXT3,
		DX_BASEIMAGE_FORMAT_DXT4,
		DX_BASEIMAGE_FORMAT_DXT5,
		DX_BASEIMAGE_FORMAT_PLATFORM0,
		DX_BASEIMAGE_FORMAT_PLATFORM1,
		DX_BASEIMAGE_FORMAT_PLATFORM2,
		DX_BASEIMAGE_FORMAT_PLATFORM3,
		DX_BASEIMAGE_FORMAT_YUV,
	};

	//ムービーのサーフェスモード
	enum :int {
		DX_MOVIESURFACE_NORMAL,
		DX_MOVIESURFACE_OVERLAY,
		DX_MOVIESURFACE_FULLCOLOR,
	};

	//ウインドウの奥行き位置設定タイプ
	enum :int {
		DX_WIN_ZTYPE_NORMAL,
		DX_WIN_ZTYPE_BOTTOM,
		DX_WIN_ZTYPE_TOP,
		DX_WIN_ZTYPE_TOPMOST,
	};

	//ツールバーのボタンの状態
	enum :int {
		TOOLBUTTON_STATE_ENABLE,
		TOOLBUTTON_STATE_PRESSED,
		TOOLBUTTON_STATE_DISABLE,
		TOOLBUTTON_STATE_PRESSED_DISABLE,
		TOOLBUTTON_STATE_NUM,
	};

	//ツールバーのボタンのタイプ
	enum :int {
		TOOLBUTTON_TYPE_NORMAL,
		TOOLBUTTON_TYPE_CHECK,
		TOOLBUTTON_TYPE_GROUP,
		TOOLBUTTON_TYPE_SEP,
		TOOLBUTTON_TYPE_NUM,
	};

	//親メニューのＩＤ
	constexpr int MENUITEM_IDTOP = (int)0xabababab;

	//メニューに追加する際のタイプ
	enum :int {
		MENUITEM_ADD_CHILD,
		MENUITEM_ADD_INSERT,
	};

	//メニューの横に付くマークタイプ
	enum :int {
		MENUITEM_MARK_NONE,
		MENUITEM_MARK_CHECK,
		MENUITEM_MARK_RADIO,
	};

	//文字変換タイプ定義
	enum :int {
		DX_NUMMODE_10,
		DX_NUMMODE_16,
		DX_STRMODE_NOT0,
		DX_STRMODE_USE0,
	};

	//CheckHitKeyAll で調べる入力タイプ
	constexpr int DX_CHECKINPUT_KEY = 0x0001;
	constexpr int DX_CHECKINPUT_PAD = 0x0002;
	constexpr int DX_CHECKINPUT_MOUSE = 0x0004;
	constexpr int DX_CHECKINPUT_ALL = (DX_CHECKINPUT_KEY | DX_CHECKINPUT_PAD | DX_CHECKINPUT_MOUSE);

	//パッド入力取得パラメータ
	constexpr int DX_INPUT_KEY_PAD1 = 0x1001;
	constexpr int DX_INPUT_PAD1 = 0x0001;
	constexpr int DX_INPUT_PAD2 = 0x0002;
	constexpr int DX_INPUT_PAD3 = 0x0003;
	constexpr int DX_INPUT_PAD4 = 0x0004;
	constexpr int DX_INPUT_PAD5 = 0x0005;
	constexpr int DX_INPUT_PAD6 = 0x0006;
	constexpr int DX_INPUT_PAD7 = 0x0007;
	constexpr int DX_INPUT_PAD8 = 0x0008;
	constexpr int DX_INPUT_PAD9 = 0x0009;
	constexpr int DX_INPUT_PAD10 = 0x000a;
	constexpr int DX_INPUT_PAD11 = 0x000b;
	constexpr int DX_INPUT_PAD12 = 0x000c;
	constexpr int DX_INPUT_PAD13 = 0x000d;
	constexpr int DX_INPUT_PAD14 = 0x000e;
	constexpr int DX_INPUT_PAD15 = 0x000f;
	constexpr int DX_INPUT_PAD16 = 0x0010;
	constexpr int DX_INPUT_KEY = 0x1000;

	//タッチの同時接触検出対応最大数
	constexpr int TOUCHINPUTPOINT_MAX = 16;

	//パッド入力定義
	constexpr int PAD_INPUT_DOWN = 0x00000001;
	constexpr int PAD_INPUT_LEFT = 0x00000002;
	constexpr int PAD_INPUT_RIGHT = 0x00000004;
	constexpr int PAD_INPUT_UP = 0x00000008;
	constexpr int PAD_INPUT_A = 0x00000010;
	constexpr int PAD_INPUT_B = 0x00000020;
	constexpr int PAD_INPUT_C = 0x00000040;
	constexpr int PAD_INPUT_X = 0x00000080;
	constexpr int PAD_INPUT_Y = 0x00000100;
	constexpr int PAD_INPUT_Z = 0x00000200;
	constexpr int PAD_INPUT_L = 0x00000400;
	constexpr int PAD_INPUT_R = 0x00000800;
	constexpr int PAD_INPUT_START = 0x00001000;
	constexpr int PAD_INPUT_M = 0x00002000;
	constexpr int PAD_INPUT_D = 0x00004000;
	constexpr int PAD_INPUT_F = 0x00008000;
	constexpr int PAD_INPUT_G = 0x00010000;
	constexpr int PAD_INPUT_H = 0x00020000;
	constexpr int PAD_INPUT_I = 0x00040000;
	constexpr int PAD_INPUT_J = 0x00080000;
	constexpr int PAD_INPUT_K = 0x00100000;
	constexpr int PAD_INPUT_LL = 0x00200000;
	constexpr int PAD_INPUT_N = 0x00400000;
	constexpr int PAD_INPUT_O = 0x00800000;
	constexpr int PAD_INPUT_P = 0x01000000;
	constexpr int PAD_INPUT_RR = 0x02000000;
	constexpr int PAD_INPUT_S = 0x04000000;
	constexpr int PAD_INPUT_T = 0x08000000;
	constexpr int PAD_INPUT_U = 0x10000000;
	constexpr int PAD_INPUT_V = 0x20000000;
	constexpr int PAD_INPUT_W = 0x40000000;
	constexpr int PAD_INPUT_XX = 0x80000000;

	constexpr int PAD_INPUT_1 = 0x00000010;
	constexpr int PAD_INPUT_2 = 0x00000020;
	constexpr int PAD_INPUT_3 = 0x00000040;
	constexpr int PAD_INPUT_4 = 0x00000080;
	constexpr int PAD_INPUT_5 = 0x00000100;
	constexpr int PAD_INPUT_6 = 0x00000200;
	constexpr int PAD_INPUT_7 = 0x00000400;
	constexpr int PAD_INPUT_8 = 0x00000800;
	constexpr int PAD_INPUT_9 = 0x00001000;
	constexpr int PAD_INPUT_10 = 0x00002000;
	constexpr int PAD_INPUT_11 = 0x00004000;
	constexpr int PAD_INPUT_12 = 0x00008000;
	constexpr int PAD_INPUT_13 = 0x00010000;
	constexpr int PAD_INPUT_14 = 0x00020000;
	constexpr int PAD_INPUT_15 = 0x00040000;
	constexpr int PAD_INPUT_16 = 0x00080000;
	constexpr int PAD_INPUT_17 = 0x00100000;
	constexpr int PAD_INPUT_18 = 0x00200000;
	constexpr int PAD_INPUT_19 = 0x00400000;
	constexpr int PAD_INPUT_20 = 0x00800000;
	constexpr int PAD_INPUT_21 = 0x01000000;
	constexpr int PAD_INPUT_22 = 0x02000000;
	constexpr int PAD_INPUT_23 = 0x04000000;
	constexpr int PAD_INPUT_24 = 0x08000000;
	constexpr int PAD_INPUT_25 = 0x10000000;
	constexpr int PAD_INPUT_26 = 0x20000000;
	constexpr int PAD_INPUT_27 = 0x40000000;
	constexpr int PAD_INPUT_28 = 0x80000000;

	//XInputボタン入力定義
	enum :int {
		XINPUT_BUTTON_DPAD_UP,
		XINPUT_BUTTON_DPAD_DOWN,
		XINPUT_BUTTON_DPAD_LEFT,
		XINPUT_BUTTON_DPAD_RIGHT,
		XINPUT_BUTTON_START,
		XINPUT_BUTTON_BACK,
		XINPUT_BUTTON_LEFT_THUMB,
		XINPUT_BUTTON_RIGHT_THUMB,
		XINPUT_BUTTON_LEFT_SHOULDER,
		XINPUT_BUTTON_RIGHT_SHOULDER,
		XINPUT_BUTTON_A = 12,
		XINPUT_BUTTON_B,
		XINPUT_BUTTON_X,
		XINPUT_BUTTON_Y,
	};

	//マウス入力定義
	constexpr int aslib_mouse_INPUT_LEFT = 0x0001;
	constexpr int aslib_mouse_INPUT_RIGHT = 0x0002;
	constexpr int aslib_mouse_INPUT_MIDDLE = 0x0004;
	constexpr int aslib_mouse_INPUT_1 = 0x0001;
	constexpr int aslib_mouse_INPUT_2 = 0x0002;
	constexpr int aslib_mouse_INPUT_3 = 0x0004;
	constexpr int aslib_mouse_INPUT_4 = 0x0008;
	constexpr int aslib_mouse_INPUT_5 = 0x0010;
	constexpr int aslib_mouse_INPUT_6 = 0x0020;
	constexpr int aslib_mouse_INPUT_7 = 0x0040;
	constexpr int aslib_mouse_INPUT_8 = 0x0080;

	//マウスのログ情報タイプ
	enum :int {
		aslib_mouse_INPUT_LOG_DOWN,
		aslib_mouse_INPUT_LOG_UP,
	};

	//キー定義
enum :size_t {
	KEY_INPUT_NON0
	, KEY_INPUT_ESCAPE
	, KEY_INPUT_1
	, KEY_INPUT_2
	, KEY_INPUT_3
	, KEY_INPUT_4
	, KEY_INPUT_5
	, KEY_INPUT_6
	, KEY_INPUT_7
	, KEY_INPUT_8
	, KEY_INPUT_9
	, KEY_INPUT_0
	, KEY_INPUT_MINUS
	, KEY_INPUT_NON13
	, KEY_INPUT_BACK
	, KEY_INPUT_TAB
	, KEY_INPUT_Q
	, KEY_INPUT_W
	, KEY_INPUT_E
	, KEY_INPUT_R
	, KEY_INPUT_T
	, KEY_INPUT_Y
	, KEY_INPUT_U
	, KEY_INPUT_I
	, KEY_INPUT_O
	, KEY_INPUT_P
	, KEY_INPUT_LBRACKET
	, KEY_INPUT_RBRACKET
	, KEY_INPUT_RETURN
	, KEY_INPUT_LCONTROL
	, KEY_INPUT_A
	, KEY_INPUT_S
	, KEY_INPUT_D
	, KEY_INPUT_F
	, KEY_INPUT_G
	, KEY_INPUT_H
	, KEY_INPUT_J
	, KEY_INPUT_K
	, KEY_INPUT_L
	, KEY_INPUT_SEMICOLON
	, KEY_INPUT_NON40
	, KEY_INPUT_NON41
	, KEY_INPUT_LSHIFT
	, KEY_INPUT_BACKSLASH
	, KEY_INPUT_Z
	, KEY_INPUT_X
	, KEY_INPUT_C
	, KEY_INPUT_V
	, KEY_INPUT_B
	, KEY_INPUT_N
	, KEY_INPUT_M
	, KEY_INPUT_COMMA
	, KEY_INPUT_PERIOD
	, KEY_INPUT_SLASH
	, KEY_INPUT_RSHIFT
	, KEY_INPUT_MULTIPLY
	, KEY_INPUT_LALT
	, KEY_INPUT_SPACE
	, KEY_INPUT_CAPSLOCK
	, KEY_INPUT_F1
	, KEY_INPUT_F2
	, KEY_INPUT_F3
	, KEY_INPUT_F4
	, KEY_INPUT_F5
	, KEY_INPUT_F6
	, KEY_INPUT_F7
	, KEY_INPUT_F8
	, KEY_INPUT_F9
	, KEY_INPUT_F10
	, KEY_INPUT_NUMLOCK
	, KEY_INPUT_SCROLL
	, KEY_INPUT_NUMPAD7
	, KEY_INPUT_NUMPAD8
	, KEY_INPUT_NUMPAD9
	, KEY_INPUT_SUBTRACT
	, KEY_INPUT_NUMPAD4
	, KEY_INPUT_NUMPAD5
	, KEY_INPUT_NUMPAD6
	, KEY_INPUT_ADD
	, KEY_INPUT_NUMPAD1
	, KEY_INPUT_NUMPAD2
	, KEY_INPUT_NUMPAD3
	, KEY_INPUT_NUMPAD0
	, KEY_INPUT_DECIMAL
	, KEY_INPUT_NON84
	, KEY_INPUT_NON85
	, KEY_INPUT_NON86
	, KEY_INPUT_F11
	, KEY_INPUT_F12
	, KEY_INPUT_NON89
	, KEY_INPUT_NON90
	, KEY_INPUT_NON91
	, KEY_INPUT_NON92
	, KEY_INPUT_NON93
	, KEY_INPUT_NON94
	, KEY_INPUT_NON95
	, KEY_INPUT_NON96
	, KEY_INPUT_NON97
	, KEY_INPUT_NON98
	, KEY_INPUT_NON99
	, KEY_INPUT_NON100
	, KEY_INPUT_NON101
	, KEY_INPUT_NON102
	, KEY_INPUT_NON103
	, KEY_INPUT_NON104
	, KEY_INPUT_NON105
	, KEY_INPUT_NON106
	, KEY_INPUT_NON107
	, KEY_INPUT_NON108
	, KEY_INPUT_NON109
	, KEY_INPUT_NON110
	, KEY_INPUT_NON111
	, KEY_INPUT_NON112
	, KEY_INPUT_KANA
	, KEY_INPUT_NON114
	, KEY_INPUT_NON115
	, KEY_INPUT_NON116
	, KEY_INPUT_NON117
	, KEY_INPUT_NON118
	, KEY_INPUT_NON119
	, KEY_INPUT_NON120
	, KEY_INPUT_CONVERT
	, KEY_INPUT_NON122
	, KEY_INPUT_NOCONVERT
	, KEY_INPUT_NON124
	, KEY_INPUT_YEN
	, KEY_INPUT_NON126
	, KEY_INPUT_NON127
	, KEY_INPUT_NON128
	, KEY_INPUT_NON129
	, KEY_INPUT_NON130
	, KEY_INPUT_NON131
	, KEY_INPUT_NON132
	, KEY_INPUT_NON133
	, KEY_INPUT_NON134
	, KEY_INPUT_NON135
	, KEY_INPUT_NON136
	, KEY_INPUT_NON137
	, KEY_INPUT_NON138
	, KEY_INPUT_NON139
	, KEY_INPUT_NON140
	, KEY_INPUT_NON141
	, KEY_INPUT_NON142
	, KEY_INPUT_NON143
	, KEY_INPUT_PREVTRACK
	, KEY_INPUT_AT
	, KEY_INPUT_COLON
	, KEY_INPUT_NON147
	, KEY_INPUT_KANJI
	, KEY_INPUT_NON149
	, KEY_INPUT_NON150
	, KEY_INPUT_NON151
	, KEY_INPUT_NON152
	, KEY_INPUT_NON153
	, KEY_INPUT_NON154
	, KEY_INPUT_NON155
	, KEY_INPUT_NUMPADENTER
	, KEY_INPUT_RCONTROL
	, KEY_INPUT_NON158
	, KEY_INPUT_NON159
	, KEY_INPUT_NON160
	, KEY_INPUT_NON161
	, KEY_INPUT_NON162
	, KEY_INPUT_NON163
	, KEY_INPUT_NON164
	, KEY_INPUT_NON165
	, KEY_INPUT_NON166
	, KEY_INPUT_NON167
	, KEY_INPUT_NON168
	, KEY_INPUT_NON169
	, KEY_INPUT_NON170
	, KEY_INPUT_NON171
	, KEY_INPUT_NON172
	, KEY_INPUT_NON173
	, KEY_INPUT_NON174
	, KEY_INPUT_NON175
	, KEY_INPUT_NON176
	, KEY_INPUT_NON177
	, KEY_INPUT_NON178
	, KEY_INPUT_NON179
	, KEY_INPUT_NON180
	, KEY_INPUT_DIVIDE
	, KEY_INPUT_NON182
	, KEY_INPUT_SYSRQ
	, KEY_INPUT_RALT
	, KEY_INPUT_NON185
	, KEY_INPUT_NON186
	, KEY_INPUT_NON187
	, KEY_INPUT_NON188
	, KEY_INPUT_NON189
	, KEY_INPUT_NON190
	, KEY_INPUT_NON191
	, KEY_INPUT_NON192
	, KEY_INPUT_NON193
	, KEY_INPUT_NON194
	, KEY_INPUT_NON195
	, KEY_INPUT_NON196
	, KEY_INPUT_PAUSE
	, KEY_INPUT_NON198
	, KEY_INPUT_HOME
	, KEY_INPUT_UP
	, KEY_INPUT_PGUP
	, KEY_INPUT_NON202
	, KEY_INPUT_LEFT
	, KEY_INPUT_NON204
	, KEY_INPUT_RIGHT
	, KEY_INPUT_NON206
	, KEY_INPUT_END
	, KEY_INPUT_DOWN
	, KEY_INPUT_PGDN
	, KEY_INPUT_INSERT
	, KEY_INPUT_DELETE
	, KEY_INPUT_NON212
	, KEY_INPUT_NON213
	, KEY_INPUT_NON214
	, KEY_INPUT_NON215
	, KEY_INPUT_NON216
	, KEY_INPUT_NON217
	, KEY_INPUT_NON218
	, KEY_INPUT_LWIN
	, KEY_INPUT_RWIN
	, KEY_INPUT_APPS
	, KEY_INPUT_NON222
	, KEY_INPUT_NON223
	, KEY_INPUT_NON224
	, KEY_INPUT_NON225
	, KEY_INPUT_NON226
	, KEY_INPUT_NON227
	, KEY_INPUT_NON228
	, KEY_INPUT_NON229
	, KEY_INPUT_NON230
	, KEY_INPUT_NON231
	, KEY_INPUT_NON232
	, KEY_INPUT_NON233
	, KEY_INPUT_NON234
	, KEY_INPUT_NON235
	, KEY_INPUT_NON236
	, KEY_INPUT_NON237
	, KEY_INPUT_NON238
	, KEY_INPUT_NON239
	, KEY_INPUT_NON240
	, KEY_INPUT_NON241
	, KEY_INPUT_NON242
	, KEY_INPUT_NON243
	, KEY_INPUT_NON244
	, KEY_INPUT_NON245
	, KEY_INPUT_NON246
	, KEY_INPUT_NON247
	, KEY_INPUT_NON248
	, KEY_INPUT_NON249
	, KEY_INPUT_NON250
	, KEY_INPUT_NON251
	, KEY_INPUT_NON252
	, KEY_INPUT_NON253
	, KEY_INPUT_NON254
	, KEY_INPUT_NON255
	, KEY_INPUT_NON256
};

	//アスキーコントロールキーコード
constexpr int CTRL_CODE_BS=0x08;
constexpr int CTRL_CODE_TAB=0x09;
constexpr int CTRL_CODE_CR=0x0d;
constexpr int CTRL_CODE_DEL=0x10;

constexpr int CTRL_CODE_COPY=0x03;
constexpr int CTRL_CODE_PASTE=0x16;
constexpr int CTRL_CODE_CUT=0x18;
constexpr int CTRL_CODE_ALL=0x01;

constexpr int CTRL_CODE_LEFT=0x1d;
constexpr int CTRL_CODE_RIGHT=0x1c;
constexpr int CTRL_CODE_UP=0x1e;
constexpr int CTRL_CODE_DOWN=0x1f;

constexpr int CTRL_CODE_HOME=0x1a;
constexpr int CTRL_CODE_END=0x19;
constexpr int CTRL_CODE_PAGE_UP=0x17;
constexpr int CTRL_CODE_PAGE_DOWN=0x15;

constexpr int CTRL_CODE_ESC=0x1b;
constexpr int CTRL_CODE_CMP=0x20;

	//SetKeyInputStringColor2 に渡す色変更対象を指定するための識別子
	enum :int {
		DX_KEYINPSTRCOLOR_NORMAL_STR,
		DX_KEYINPSTRCOLOR_NORMAL_STR_EDGE,
		DX_KEYINPSTRCOLOR_NORMAL_CURSOR,
		DX_KEYINPSTRCOLOR_SELECT_STR,
		DX_KEYINPSTRCOLOR_SELECT_STR_EDGE,
		DX_KEYINPSTRCOLOR_SELECT_STR_BACK,
		DX_KEYINPSTRCOLOR_IME_STR,
		DX_KEYINPSTRCOLOR_IME_STR_EDGE,
		DX_KEYINPSTRCOLOR_IME_STR_BACK,
		DX_KEYINPSTRCOLOR_IME_CURSOR,
		DX_KEYINPSTRCOLOR_IME_LINE,
		DX_KEYINPSTRCOLOR_IME_SELECT_STR,
		DX_KEYINPSTRCOLOR_IME_SELECT_STR_EDGE,
		DX_KEYINPSTRCOLOR_IME_SELECT_STR_BACK,
		DX_KEYINPSTRCOLOR_IME_CONV_WIN_STR,
		DX_KEYINPSTRCOLOR_IME_CONV_WIN_STR_EDGE,
		DX_KEYINPSTRCOLOR_IME_CONV_WIN_SELECT_STR,
		DX_KEYINPSTRCOLOR_IME_CONV_WIN_SELECT_STR_EDGE,
		DX_KEYINPSTRCOLOR_IME_CONV_WIN_SELECT_STR_BACK,
		DX_KEYINPSTRCOLOR_IME_CONV_WIN_EDGE,
		DX_KEYINPSTRCOLOR_IME_CONV_WIN_BACK,
		DX_KEYINPSTRCOLOR_IME_MODE_STR,
		DX_KEYINPSTRCOLOR_IME_MODE_STR_EDGE,
		DX_KEYINPSTRCOLOR_NUM,
	};

	//文字列入力処理の入力文字数が限界に達している状態で、文字列の末端部分で入力が行われた場合の処理モード
	enum :int {
		DX_KEYINPSTR_ENDCHARAMODE_OVERWRITE,
		DX_KEYINPSTR_ENDCHARAMODE_NOTCHANGE,
	};

	//フルスクリーン解像度モード定義
	enum :int {
		DX_FSRESOLUTIONMODE_DESKTOP,
		DX_FSRESOLUTIONMODE_NATIVE,
		DX_FSRESOLUTIONMODE_MAXIMUM,
	};

	//フルスクリーン拡大モード定義
	enum :int {
		DX_FSSCALINGMODE_BILINEAR,
		DX_FSSCALINGMODE_NEAREST,
	};

	//SetGraphMode 戻り値定義
	constexpr int DX_CHANGESCREEN_OK = 0;
	constexpr int DX_CHANGESCREEN_RETURN = -1;
	constexpr int DX_CHANGESCREEN_DEFAULT = -2;
	constexpr int DX_CHANGESCREEN_REFRESHNORMAL = -3;

	//ストリームデータ読み込み処理コード簡略化関連
#define STTELL( st ) ((st)->ReadShred.Tell( (st)->DataPoint ))
#define STSEEK( st, pos, type ) ((st)->ReadShred.Seek( (st)->DataPoint, (pos), (type) ))
#define STREAD( buf, length, num, st ) ((st)->ReadShred.Read( (buf), (length), (num), (st)->DataPoint ))
#define STWRITE( buf, length, num, st ) ((st)->ReadShred.Write( (buf), (length), (num), (st)->DataPoint ))
#define STEOF( st ) ((st)->ReadShred.Eof( (st)->DataPoint ))
#define STCLOSE( st )	 ((st)->ReadShred.Close( (st)->DataPoint ))

	//ストリームデータ制御のシークタイプ定義
	constexpr int STREAM_SEEKTYPE_SET = SEEK_SET;
	constexpr int STREAM_SEEKTYPE_END = SEEK_END;
	constexpr int STREAM_SEEKTYPE_CUR = SEEK_CUR;

	//グラフィックロード時のイメージタイプ
	enum :int {
		LOADIMAGE_TYPE_FILE,
		LOADIMAGE_TYPE_MEM,
		LOADIMAGE_TYPE_NONE = -1,
	};

	//HTTP エラー
	enum :int {
		HTTP_ERR_SERVER,
		HTTP_ERR_NOTFOUND,
		HTTP_ERR_MEMORY,
		HTTP_ERR_LOST,
		HTTP_ERR_NONE = -1,
	};

	//HTTP 処理の結果
	enum :int {
		HTTP_RES_COMPLETE,
		HTTP_RES_STOP,
		HTTP_RES_ERROR,
		HTTP_RES_NOW = -1,
	};

#endif

#if defined(USING_DXLIB)
	namespace test
	{

		enum:size_t
		{
			USING_DL_GRAPH_LOAD,
			USING_DL_GRAPH_SIMPLE_DRAW,
			USING_DL_GRAPH_DRAW,
			USING_DL_GRAPH_EXTEND_DRAW,
			USING_DL_GRAPH_PIXEL_SIZE,
		};

		inline const bool ControlHandle(const int handle_, const size_t id_) { return (handle_ < 0 || size_t(handle_) >= id_); }
		const int ControlGraph(const size_t id_, const int handle_ = -1, const char* const f_ = nullptr, const Pos4& p_ = pos4_0, const Pos2& p2_ = pos2_0, int* const x_ = nullptr, int* const y_ = nullptr) {
			static std::vector<AsTexture> DL_tmd;
			switch (id_)
			{
			case USING_DL_GRAPH_LOAD:
				DL_tmd.emplace_back(1,asLoadTexture(f_, 1));
				return int(DL_tmd.size() - 1);
			case USING_DL_GRAPH_DRAW:
				if (ControlHandle(handle_, DL_tmd.size())) return -1;
				DL_tmd[size_t(handle_)].draw(p2_);
				return 0;
			case USING_DL_GRAPH_SIMPLE_DRAW:
				if (ControlHandle(handle_, DL_tmd.size())) return -1;
				DL_tmd[size_t(handle_)].draw();
				return 0;
			case USING_DL_GRAPH_EXTEND_DRAW:
				if (ControlHandle(handle_, DL_tmd.size())) return -1;
				DL_tmd[size_t(handle_)].draw(p_);
				return 0;
			case USING_DL_GRAPH_PIXEL_SIZE:
				if (ControlHandle(handle_, DL_tmd.size())) {
					*x_ = *y_ = 0;
					return -1;
				}
				const Pos2 p = DL_tmd[size_t(handle_)].pixelSize();
				*x_ = int(p.x);
				*y_ = int(p.y);
				return 0;
			}
			return 0;
		}
		inline const int ControlPixelGraph(const int handle_, int* const x_, int* const y_) { return ControlGraph(USING_DL_GRAPH_PIXEL_SIZE, handle_, nullptr, pos4_0, pos2_0, x_, y_); }

		const int MouseControl()
		{
			int input = 0;
			Counter count[mouse_button_num];
			mouseButton(count);

			if (count[aslib_mouse_left].count() > 0)input += aslib_mouse_INPUT_LEFT;
			if (count[aslib_mouse_right].count() > 0)input += aslib_mouse_INPUT_RIGHT;
			if (count[aslib_mouse_middle].count() > 0)input += aslib_mouse_INPUT_MIDDLE;
			if (count[aslib_mouse_4].count() > 0)input += aslib_mouse_INPUT_4;
			if (count[aslib_mouse_5].count() > 0)input += aslib_mouse_INPUT_5;
			if (count[aslib_mouse_6].count() > 0)input += aslib_mouse_INPUT_6;
			if (count[aslib_mouse_7].count() > 0)input += aslib_mouse_INPUT_7;
			if (count[aslib_mouse_8].count() > 0)input += aslib_mouse_INPUT_8;
			return input;
		}

		//使用必須関数
		inline const int DxLib_Init() { return 0; }
		inline const int DxLib_End() { return 0; }
		inline const bool ProcessMessageControl(const bool is_ = true, const bool on_ = false) { static bool is_message = false; if (on_) is_message = is_; return is_message; }
		inline const int ProcessMessage() { return ProcessMessageControl(); }

		//図形描画関数
		inline const int DrawBox(const int x1, const int y1, const int x2, const int y2, const unsigned int col_, const int flag = 1) { asRect(Pos4(int32_t(x1), int32_t(y1), int32_t(x2), int32_t(y2)), Color(col_)); return 0; }
		inline const int DrawBox(const int x1, const int y1, const int x2, const int y2, const Color& col_, const int flag = 1) { asRect(Pos4(int32_t(x1), int32_t(y1), int32_t(x2), int32_t(y2)), col_); return 0; }
		inline const int DrawBox(const Pos4& p_, const Color& col_, const int flag = 1) { asRect(Pos4(p_.x1, p_.y1, p_.x2, p_.y2), col_); return 0;}
		inline const int DrawBox(const Color& col_, const Pos4& p_, const int flag = 1) { asRect(Pos4(p_.x1, p_.y1, p_.x2, p_.y2), col_); return 0;}
		inline const int DrawBox(const Pos4& p_, const unsigned int col_, const int flag = 1) { asRect(Pos4(p_.x1, p_.y1, p_.x2, p_.y2), Color(col_)); return 0;}

		//グラフィックデータ制御関数
		inline const int LoadGraph(const char* const f_) { return ControlGraph(USING_DL_GRAPH_LOAD, -1, f_); }
		inline const int DrawGraph(const int handle, const int flag = 1) { return ControlGraph(USING_DL_GRAPH_SIMPLE_DRAW, handle,nullptr); }
		inline const int DrawGraph(const int x, const int y, const int handle, const int flag = 1) { return ControlGraph(USING_DL_GRAPH_DRAW, handle, nullptr, pos4_0, Pos2(int32_t(x), int32_t(y))); }//todo
		inline const int DrawExtendGraph(const int x1, const int y1, const int x2, const int y2, const int handle, const int flag=1) { return ControlGraph(USING_DL_GRAPH_EXTEND_DRAW, handle, nullptr, Pos4(int32_t(x1), int32_t(y1), int32_t(x2), int32_t(y2))); }
		inline const int DrawExtendGraph(const Pos4& p_, const int handle, const int flag = 1) { return ControlGraph(USING_DL_GRAPH_EXTEND_DRAW, handle, nullptr, p_); }
		inline const int GetGraphSize(const int handle, int * const x_, int * const y_) { return ControlPixelGraph(handle, x_, y_); }
		//const int LoadGraphScreen(const int x_, const int y_, const char* const f_, const int flag = 1) { AsTexture(1, asLoadTexture(f_, 1)).draw(0, Pos2(int32_t(x_), int32_t(y_))); return 0; }

		//簡易画面出力関数
		template<typename... Rest>inline const int printfDx(const char* const format_string, const Rest&... rest) { return int(asPrint(format_string, rest...)); }

		//タッチパネル入力関連関数
		inline const int GetTouchInputNum() { return int(asTouchNum()); }

		//その他画面操作系関数
		inline const int SetGraphMode(const int x_, const int y_, const int bit_ = 32) { asSetWindowSize(Pos2(int32_t(x_), int32_t(y_))); return 0; }
		inline const int SetGraphMode(const Pos2& pos_, const int bit_ = 32) { asSetWindowSize(pos_); return 0; }
		inline const int SetFullScreenResolutionMode(const int ResolutionMode = 1) { return 0; }
		inline const int SetFullScreenScalingMode(const int ScalingMode = 1) { return 0; }
		const int GetScreenState(int* const x_, int* const y_, int* const col) { const Pos2 p = asWindowSize(); *x_ = int(p.x); *y_ = int(p.y); *col = 32; return 0; }
		const int GetScreenState(int* const x_, int* const y_) { const Pos2 p = asWindowSize(); *x_ = int(p.x); *y_ = int(p.y); return 0; }
		const int GetScreenState(int& x_, int& y_, int* const col) { const Pos2 p = asWindowSize(); x_ = int(p.x); y_ = int(p.y); *col = 32; return 0; }
		const int GetScreenState(int& x_, int& y_) { const Pos2 p = asWindowSize(); x_ = int(p.x); y_ = int(p.y); return 0; }
		const int GetScreenState(Pos2& pos_, int* const col) { pos_ = asWindowSize(); *col = 32; return 0; }
		const int GetScreenState(Pos2& pos_) { pos_ = asWindowSize(); return 0; }
		const int GetScreenState(Pos2* const pos_, int* const col) { *pos_ = asWindowSize(); *col = 32; return 0; }
		const int GetScreenState(Pos2* const pos_) { *pos_ = asWindowSize(); return 0; }
		inline const int SetDrawArea(const int x1, const int y1, const int x2, const int y2) { return 0; }//todo
		inline const int SetDrawArea(const Pos4& p_) { return 0; }//todo
		inline const int ClearDrawScreen() { return 0; }
		inline const int SetBackgroundColor(const int r_, const int g_, const int b_) { return asSetBackGround(ColorRGB(uint8_t(r_ & 0xff), uint8_t(g_ & 0xff), uint8_t(b_ & 0xff))); }
		inline const unsigned int GetColor(const int r_, const int g_, const int b_) { return ((unsigned int)((r_ & 0xff) << 0x10) + (unsigned int)((g_ & 0xff) << 0x8) + (unsigned int)(b_ & 0xff)); }
		inline const unsigned int GetColor(const Color& col_) { return ((unsigned int)((col_.r & 0xff) << 0x10) + (unsigned int)((col_.g & 0xff) << 0x8) + (unsigned int)(col_.b & 0xff)); }
		inline const int SetDrawScreen(const int draw_screen = 1) { return 0; }
		const int ScreenFlip() { if (asLoop() == false) { ProcessMessageControl(true, true); return -1; } return 0; }

		//ウインドウモード関係
		inline const int ChangeWindowMode(const int flag = 1) { return 0; }
		inline const int SetMainWindowText(const char* const t_) { return int(asSetTitle(t_)); }
		inline const int SetWindowIconID(const int ID = 1) { return 0; }
		inline const int SetWindowSizeChangeEnableFlag(const int flag = 1) { return 0; }
		inline const int SetWindowSizeExtendRate(const double ExRate = 1.0) { return 0; }

		//マウス入力関連関数
		inline const int SetMouseDispFlag(const int DispFlag = 1) { return 0; }
		const int GetMousePoint(int* const x_, int* const y_) { const Pos2 p = mousePos(); *x_ = int(p.x); *y_ = int(p.y); return 0; }
		const int GetMousePoint(int& x_, int& y_) { const Pos2 p = mousePos(); x_ = int(p.x); y_ = int(p.y); return 0; }
		const int GetMousePoint(Pos2& p_) { p_ = mousePos(); return 0; }
		inline const int SetMousePoint(const int x_, const int y_) { return 0; }
		inline const int GetMouseInput() { return MouseControl(); }
		inline const int GetMouseInputLog2(int* const Button, int* const ClickX, int* const ClickY, int* const LogType, const int LogDelete) { return 0; }
		inline const int GetMouseWheelRotVol() { return int(mouseWheel()); }

		//乱数取得関数
		inline const int GetRand(const int rand_) { return int(asRand32(int32_t(rand_))); }
		inline const int asSRand32(const int seed_) { return int(asSRand32(int32_t(seed_))); }
	}
#endif

}

#endif //Included AsProject Library