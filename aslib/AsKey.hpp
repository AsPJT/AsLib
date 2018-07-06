//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - Asライブラリ
//
//                    制作者: がっちょ (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{
	//キーボード配列ID
	enum :size_t {
		Keyboard_Unknown,
		Keyboard_grave_accentilde,
		Keyboard_1,
		Keyboard_2,
		Keyboard_3,
		Keyboard_4,
		Keyboard_5,
		Keyboard_6,
		Keyboard_7,
		Keyboard_8,
		Keyboard_9,
		Keyboard_0,
		Keyboard_hyphennderscore,
		Keyboard_equallus,
		Keyboard_International3,
		Keyboard_DELETE_Backspace,
		Keyboard_Tab,
		Keyboard_q,
		Keyboard_w,
		Keyboard_e,
		Keyboard_r,
		Keyboard_t,
		Keyboard_y,
		Keyboard_u,
		Keyboard_i,
		Keyboard_o,
		Keyboard_p,
		Keyboard_left_square_bracketeft_curly_bracket,
		Keyboard_right_square_bracketight_curly_bracket,
		Keyboard_ertical_line,
		Keyboard_Caps_Lock,
		Keyboard_a,
		Keyboard_s,
		Keyboard_d,
		Keyboard_f,
		Keyboard_g,
		Keyboard_h,
		Keyboard_j,
		Keyboard_k,
		Keyboard_l,
		Keyboard_semicolon,
		Keyboard_colon,
		Keyboard_Non_US_numberilde,
		Keyboard_Return_ENTER,
		Keyboard_left_shift,
		Keyboard_Unknown1,
		Keyboard_z,
		Keyboard_x,
		Keyboard_c,
		Keyboard_v,
		Keyboard_b,
		Keyboard_n,
		Keyboard_m,
		Keyboard_commaess_than_sign,
		Keyboard_full_stopreater_than_sign,
		Keyboard_solidusuestion,
		Keyboard_International1,
		Keyboard_right_shift,
		Keyboard_left_control,
		Keyboard_Unknown2,
		Keyboard_left_alt,
		Keyboard_Spacebar,
		Keyboard_right_alt,
		Keyboard_Unknown3,
		Keyboard_right_control,
		Keyboard_Unknown4,
		Keyboard_Unknown5,
		Keyboard_Unknown6,
		Keyboard_Unknown7,
		Keyboard_Unknown8,
		Keyboard_Unknown9,
		Keyboard_Unknown10,
		Keyboard_Unknown11,
		Keyboard_Unknown12,
		Keyboard_Unknown13,
		Keyboard_Insert,
		Keyboard_Delete_Forward,
		Keyboard_Unknown14,
		Keyboard_Unknown15,
		Keyboard_LeftArrow,
		Keyboard_Home,
		Keyboard_End,
		Keyboard_Unknown16,
		Keyboard_UpArrow,
		Keyboard_DownArrow,
		Keyboard_PageUp,
		Keyboard_PageDown,
		Keyboard_Unknown17,
		Keyboard_Unknown18,
		Keyboard_RightArrow,
		Keypad_Num_Locklear,
		Keypad_7,
		Keypad_4,
		Keypad_1,
		Keyboard_Unknown19,
		Keypad_solidus,
		Keypad_8,
		Keypad_5,
		Keypad_2,
		Keypad_0,
		Keypad_asterisk,
		Keypad_9,
		Keypad_6,
		Keypad_3,
		Keypad_full_stopelete,
		Keypad_hyphen,
		Keypad_plus,
		Keyboard_Unknown20,
		Keypad_ENTER,
		Keyboard_Unknown21,
		Keyboard_ESCAPE,
		Keyboard_Unknown22,
		Keyboard_F1,
		Keyboard_F2,
		Keyboard_F3,
		Keyboard_F4,
		Keyboard_F5,
		Keyboard_F6,
		Keyboard_F7,
		Keyboard_F8,
		Keyboard_F9,
		Keyboard_F10,
		Keyboard_F11,
		Keyboard_F12,
		Keyboard_PrintScreen,
		Keyboard_Scroll_Lock,
		Keyboard_Pause,
		Keyboard_Left_GUI,
		Keyboard_Right_GUI,
		Keyboard_Application,
		Keyboard_Unknown23,
		Keyboard_International5,
		Keyboard_International4,
		Keyboard_International2,
		Keyboard_KeyLast,
	};

	class KeyControl
	{
	public:

	private:
		std::array<int32_t, 256>key = {};
		//std::array<int32_t, 256>config = {};
		//std::array<Counter, 256> counter = {};
	};

	enum :size_t {
bba0
,KEY_INPUT_ESCAPE0x01//EscキーD_DIK_ESCAPE
,KEY_INPUT_10x02//１キーD_DIK_1
,KEY_INPUT_20x03//２キーD_DIK_2
,KEY_INPUT_30x04//３キーD_DIK_3
,KEY_INPUT_40x05//４キーD_DIK_4
,KEY_INPUT_50x06//５キーD_DIK_5
,KEY_INPUT_60x07//６キーD_DIK_6
,KEY_INPUT_70x08//７キーD_DIK_7
,KEY_INPUT_80x09//８キーD_DIK_8
,KEY_INPUT_90x0A//９キーD_DIK_9
,KEY_INPUT_00x0B//０キーD_DIK_0
,KEY_INPUT_MINUS0x0C//－キーD_DIK_MINUS
,bba13
,KEY_INPUT_BACK0x0E//BackSpaceキーD_DIK_BACK
,KEY_INPUT_TAB0x0F//TabキーD_DIK_TAB
,KEY_INPUT_Q0x10//ＱキーD_DIK_Q
,KEY_INPUT_W0x11//ＷキーD_DIK_W
,KEY_INPUT_E0x12//ＥキーD_DIK_E
,KEY_INPUT_R0x13//ＲキーD_DIK_R
,KEY_INPUT_T0x14//ＴキーD_DIK_T
,KEY_INPUT_Y0x15//ＹキーD_DIK_Y
,KEY_INPUT_U0x16//ＵキーD_DIK_U
,KEY_INPUT_I0x17//ＩキーD_DIK_I
,KEY_INPUT_O0x18//ＯキーD_DIK_O
,KEY_INPUT_P0x19//ＰキーD_DIK_P
,KEY_INPUT_LBRACKET0x1A//［キーD_DIK_LBRACKET
,KEY_INPUT_RBRACKET0x1B//］キーD_DIK_RBRACKET
,KEY_INPUT_RETURN0x1C//EnterキーD_DIK_RETURN
,KEY_INPUT_LCONTROL0x1D//左CtrlキーD_DIK_LCONTROL
,KEY_INPUT_A0x1E//ＡキーD_DIK_A
,KEY_INPUT_S0x1F//ＳキーD_DIK_S
,KEY_INPUT_D0x20//ＤキーD_DIK_D
,KEY_INPUT_F0x21//ＦキーD_DIK_F
,KEY_INPUT_G0x22//ＧキーD_DIK_G
,KEY_INPUT_H0x23//ＨキーD_DIK_H
,KEY_INPUT_J0x24//ＪキーD_DIK_J
,KEY_INPUT_K0x25//ＫキーD_DIK_K
,KEY_INPUT_L0x26//ＬキーD_DIK_L
,KEY_INPUT_SEMICOLON0x27//；キーD_DIK_SEMICOLON
,bba40
,bba41
,KEY_INPUT_LSHIFT0x2A//左ShiftキーD_DIK_LSHIFT
,KEY_INPUT_BACKSLASH0x2B//＼キーD_DIK_BACKSLASH
,KEY_INPUT_Z0x2C//ＺキーD_DIK_Z
,KEY_INPUT_X0x2D//ＸキーD_DIK_X
,KEY_INPUT_C0x2E//ＣキーD_DIK_C
,KEY_INPUT_V0x2F//ＶキーD_DIK_V
,KEY_INPUT_B0x30//ＢキーD_DIK_B
,KEY_INPUT_N0x31//ＮキーD_DIK_N
,KEY_INPUT_M0x32//ＭキーD_DIK_M
,KEY_INPUT_COMMA0x33//，キーD_DIK_COMMA
,KEY_INPUT_PERIOD0x34//．キーD_DIK_PERIOD
,KEY_INPUT_SLASH0x35//／キーD_DIK_SLASH
,KEY_INPUT_RSHIFT0x36//右ShiftキーD_DIK_RSHIFT
,KEY_INPUT_MULTIPLY0x37//テンキー＊キーD_DIK_MULTIPLY
,KEY_INPUT_LALT0x38//左AltキーD_DIK_LALT
,KEY_INPUT_SPACE0x39//スペースキーD_DIK_SPACE
,KEY_INPUT_CAPSLOCK0x3A//CaspLockキーD_DIK_CAPSLOCK
,KEY_INPUT_F10x3B//Ｆ１キーD_DIK_F1
,KEY_INPUT_F20x3C//Ｆ２キーD_DIK_F2
,KEY_INPUT_F30x3D//Ｆ３キーD_DIK_F3
,KEY_INPUT_F40x3E//Ｆ４キーD_DIK_F4
,KEY_INPUT_F50x3F//Ｆ５キーD_DIK_F5
,KEY_INPUT_F60x40//Ｆ６キーD_DIK_F6
,KEY_INPUT_F70x41//Ｆ７キーD_DIK_F7
,KEY_INPUT_F80x42//Ｆ８キーD_DIK_F8
,KEY_INPUT_F90x43//Ｆ９キーD_DIK_F9
,KEY_INPUT_F100x44//Ｆ１０キーD_DIK_F10
,KEY_INPUT_NUMLOCK0x45//テンキーNumLockキーD_DIK_NUMLOCK
,KEY_INPUT_SCROLL0x46//ScrollLockキーD_DIK_SCROLL
,KEY_INPUT_NUMPAD70x47//テンキー７D_DIK_NUMPAD7
,KEY_INPUT_NUMPAD80x48//テンキー８D_DIK_NUMPAD8
,KEY_INPUT_NUMPAD90x49//テンキー９D_DIK_NUMPAD9
,KEY_INPUT_SUBTRACT0x4A//テンキー－キーD_DIK_SUBTRACT
,KEY_INPUT_NUMPAD40x4B//テンキー４D_DIK_NUMPAD4
,KEY_INPUT_NUMPAD50x4C//テンキー５D_DIK_NUMPAD5
,KEY_INPUT_NUMPAD60x4D//テンキー６D_DIK_NUMPAD6
,KEY_INPUT_ADD0x4E//テンキー＋キーD_DIK_ADD
,KEY_INPUT_NUMPAD10x4F//テンキー１D_DIK_NUMPAD1
,KEY_INPUT_NUMPAD20x50//テンキー２D_DIK_NUMPAD2
,KEY_INPUT_NUMPAD30x51//テンキー３D_DIK_NUMPAD3
,KEY_INPUT_NUMPAD00x52//テンキー０D_DIK_NUMPAD0
,KEY_INPUT_DECIMAL0x53//テンキー．キーD_DIK_DECIMAL
,bba84
,bba85
,bba86
,KEY_INPUT_F110x57//Ｆ１１キーD_DIK_F11
,KEY_INPUT_F120x58//Ｆ１２キーD_DIK_F12
,bba89
,bba90
,bba91
,bba92
,bba93
,bba94
,bba95
,bba96
,bba97
,bba98
,bba99
,bba100
,bba101
,bba102
,bba103
,bba104
,bba105
,bba106
,bba107
,bba108
,bba109
,bba110
,bba111
,bba112
,KEY_INPUT_KANA0x70//カナキーD_DIK_KANA
,bba113
,bba114
,bba115
,bba116
,bba117
,bba118
,bba119
,bba120
,KEY_INPUT_CONVERT0x79//変換キーD_DIK_CONVERT
,bba122
,KEY_INPUT_NOCONVERT0x7B//無変換キーD_DIK_NOCONVERT
,bba124
,KEY_INPUT_YEN0x7D//￥キーD_DIK_YEN
,bba126
,bba127
,bba128
,bba129
,bba130
,bba131
,bba132
,bba133
,bba134
,bba135
,bba136
,bba137
,bba138
,bba139
,bba140
,bba141
,bba142
,bba143
,KEY_INPUT_PREVTRACK0x90//＾キーD_DIK_PREVTRACK
,KEY_INPUT_AT0x91//＠キーD_DIK_AT
,KEY_INPUT_COLON0x92//：キーD_DIK_COLON
,bba147
,KEY_INPUT_KANJI0x94//漢字キーD_DIK_KANJI
,bba149
,bba150
,bba151
,bba152
,bba153
,bba154
,bba155
,KEY_INPUT_NUMPADENTER0x9C//テンキーのエンターキーD_DIK_NUMPADENTER
,KEY_INPUT_RCONTROL0x9D//右CtrlキーD_DIK_RCONTROL
,bba158
,bba159
,bba160
,bba161
,bba162
,bba163
,bba164
,bba165
,bba166
,bba167
,bba168
,bba169
,bba170
,bba171
,bba172
,bba173
,bba174
,bba175
,bba176
,bba177
,bba178
,bba179
,bba180
,KEY_INPUT_DIVIDE0xB5//テンキー／キーD_DIK_DIVIDE
,bba182
,KEY_INPUT_SYSRQ0xB7//PrintScreenキーD_DIK_SYSRQ
,KEY_INPUT_RALT0xB8//右AltキーD_DIK_RALT
,bba185
,bba186
,bba187
,bba188
,bba189
,bba190
,bba191
,bba192
,bba193
,bba194
,bba195
,bba196
,KEY_INPUT_PAUSE0xC5//PauseBreakキーD_DIK_PAUSE
,bba198
,KEY_INPUT_HOME0xC7//HomeキーD_DIK_HOME
,KEY_INPUT_UP0xC8//上キーD_DIK_UP
,KEY_INPUT_PGUP0xC9//PageUpキーD_DIK_PGUP
,bba202
,KEY_INPUT_LEFT0xCB//左キーD_DIK_LEFT
,bba204
,KEY_INPUT_RIGHT0xCD//右キーD_DIK_RIGHT
,bba206
,KEY_INPUT_END0xCF//EndキーD_DIK_END
,KEY_INPUT_DOWN0xD0//下キーD_DIK_DOWN
,KEY_INPUT_PGDN0xD1//PageDownキーD_DIK_PGDN
,KEY_INPUT_INSERT0xD2//InsertキーD_DIK_INSERT
,KEY_INPUT_DELETE0xD3//DeleteキーD_DIK_DELETE
,bba212
,bba213
,bba214
,bba215
,bba216
,bba217
,bba218
,KEY_INPUT_LWIN0xDB//左WinキーD_DIK_LWIN
,KEY_INPUT_RWIN0xDC//右WinキーD_DIK_RWIN
,KEY_INPUT_APPS0xDD//アプリケーションメニューキーD_DIK_APPS
,bba222
, bba223
, bba224
, bba225
, bba226
, bba227
, bba228
, bba229
, bba230
, bba231
, bba232
, bba233
, bba234
, bba235
, bba236
, bba237
, bba238
, bba239
, bba240
, bba241
, bba242
, bba243
, bba244
, bba245
, bba246
, bba247
, bba248
, bba249
, bba250
, bba251
, bba252
, bba253
, bba254
, bba255
, bba256
};


#if defined(ASLIB_INCLUDE_DL) //DxLib
	
void checkKey(bool* const AS_key)
{
	constexpr std::array<size_t, Keyboard_KeyLast> DL_AS_key{
		0,
		KEY_INPUT_KANJI,
		KEY_INPUT_1,
		KEY_INPUT_2,
		KEY_INPUT_3,
		KEY_INPUT_4,
		KEY_INPUT_5,
		KEY_INPUT_6,
		KEY_INPUT_7,
		KEY_INPUT_8,
		KEY_INPUT_9,
		KEY_INPUT_0,
		KEY_INPUT_MINUS,
		KEY_INPUT_PREVTRACK,
		KEY_INPUT_YEN,
		KEY_INPUT_BACK,
		KEY_INPUT_TAB,
		KEY_INPUT_Q,
		KEY_INPUT_W,
		KEY_INPUT_E,
		KEY_INPUT_R,
		KEY_INPUT_T,
		KEY_INPUT_Y,
		KEY_INPUT_U,
		KEY_INPUT_I,
		KEY_INPUT_O,
		KEY_INPUT_P,
		KEY_INPUT_AT,
		KEY_INPUT_LBRACKET,
		KEY_INPUT_BACKSLASH,
		KEY_INPUT_CAPSLOCK,
		KEY_INPUT_A,
		KEY_INPUT_S,
		KEY_INPUT_D,
		KEY_INPUT_F,
		KEY_INPUT_G,
		KEY_INPUT_H,
		KEY_INPUT_J,
		KEY_INPUT_K,
		KEY_INPUT_L,
		KEY_INPUT_SEMICOLON,
		KEY_INPUT_COLON,
		KEY_INPUT_RBRACKET,
		KEY_INPUT_RETURN,
		KEY_INPUT_LSHIFT,
		0,
		KEY_INPUT_Z,
		KEY_INPUT_X,
		KEY_INPUT_C,
		KEY_INPUT_V,
		KEY_INPUT_B,
		KEY_INPUT_N,
		KEY_INPUT_M,
		KEY_INPUT_COMMA,
		KEY_INPUT_PERIOD,
		KEY_INPUT_SLASH,
		KEY_INPUT_BACKSLASH,
		KEY_INPUT_RSHIFT,
		KEY_INPUT_LCONTROL,
		0,
		KEY_INPUT_LALT,
		KEY_INPUT_SPACE,
		KEY_INPUT_RALT,
		0,
		KEY_INPUT_RCONTROL,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		KEY_INPUT_INSERT,
		KEY_INPUT_DELETE,
		0,
		0,
		KEY_INPUT_LEFT,
		KEY_INPUT_HOME,
		KEY_INPUT_END,
		0,
		KEY_INPUT_UP,
		KEY_INPUT_DOWN,
		KEY_INPUT_PGUP,
		KEY_INPUT_PGDN,
		0,
		0,
		KEY_INPUT_RIGHT,
		0,//KEY_INPUT_NUMPADNUM_LOCKLEAR,
		KEY_INPUT_NUMPAD7,
		KEY_INPUT_NUMPAD4,
		KEY_INPUT_NUMPAD1,
		0,
		KEY_INPUT_DIVIDE,
		KEY_INPUT_NUMPAD8,
		KEY_INPUT_NUMPAD5,
		KEY_INPUT_NUMPAD2,
		KEY_INPUT_NUMPAD0,
		KEY_INPUT_MULTIPLY,
		KEY_INPUT_NUMPAD9,
		KEY_INPUT_NUMPAD6,
		KEY_INPUT_NUMPAD3,
		KEY_INPUT_DECIMAL,
		KEY_INPUT_SUBTRACT,
		KEY_INPUT_ADD,
		0,
		KEY_INPUT_NUMPADENTER,
		0,
		KEY_INPUT_ESCAPE,
		0,
		KEY_INPUT_F1,
		KEY_INPUT_F2,
		KEY_INPUT_F3,
		KEY_INPUT_F4,
		KEY_INPUT_F5,
		KEY_INPUT_F6,
		KEY_INPUT_F7,
		KEY_INPUT_F8,
		KEY_INPUT_F9,
		KEY_INPUT_F10,
		KEY_INPUT_F11,
		KEY_INPUT_F12,
		0,//KEY_INPUT_PRINTSCREEN,
		0,//KEY_INPUT_SCROLL_LOCK,
		KEY_INPUT_PAUSE,
		0,//KEY_INPUT_LEFT_GUI,
		0,//KEY_INPUT_RIGHT_GUI,
		0,//KEY_INPUT_APPLICATION,
		0,
		0,//KEY_INPUT_INTERNATIONAL5,
		0,//KEY_INPUT_INTERNATIONAL4,
		0,//KEY_INPUT_INTERNATIONAL2,
		//Last
	};

	std::array<char, 256> DL_key;
	DxLib::GetHitKeyStateAll(DL_key.data());
	for (size_t i = 0; i < Keyboard_KeyLast; ++i) {
		if (DL_key[DL_AS_key[i]] != 0) AS_key[i] = true;
		else AS_key[i] = false;
	}
	return;
}

//	bool* checkKey9() {
//		constexpr std::array<size_t, 256> AS_DL_key{
//			Keyboard_Unknown,//Ka0 
//			Keyboard_ESCAPE,//KESCAPE0x01//EscキーD_DIK_ESCAPE 
//			Keyboard_1,//K10x02//１キーD_DIK_1 
//			Keyboard_2,//K20x03//２キーD_DIK_2 
//			Keyboard_3,//K30x04//３キーD_DIK_3 
//			Keyboard_4,//K40x05//４キーD_DIK_4 
//			Keyboard_5,//K50x06//５キーD_DIK_5 
//			Keyboard_6,//K60x07//６キーD_DIK_6 
//			Keyboard_7,//K70x08//７キーD_DIK_7 
//			Keyboard_8,//K80x09//８キーD_DIK_8 
//			Keyboard_9,//K90x0A//９キーD_DIK_9 
//			Keyboard_0,//K00x0B//０キーD_DIK_0 
//			0,//KMINUS0x0C//－キーD_DIK_MINUS 
//			Keyboard_Unknown,//Ka13 
//			0,//KBACK0x0E//BackSpaceキーD_DIK_BACK 
//			0,//KTAB0x0F//TabキーD_DIK_TAB 
//			Keyboard_q,//KQ0x10//ＱキーD_DIK_Q 
//			Keyboard_w,//KW0x11//ＷキーD_DIK_W 
//			Keyboard_e,//KE0x12//ＥキーD_DIK_E 
//			Keyboard_r,//KR0x13//ＲキーD_DIK_R 
//			Keyboard_t,//KT0x14//ＴキーD_DIK_T 
//			Keyboard_y,//KY0x15//ＹキーD_DIK_Y 
//			Keyboard_u,//KU0x16//ＵキーD_DIK_U 
//			Keyboard_i,//KI0x17//ＩキーD_DIK_I 
//			Keyboard_o,//KO0x18//ＯキーD_DIK_O 
//			Keyboard_p,//KP0x19//ＰキーD_DIK_P 
//			0,//KLBRACKET0x1A//［キーD_DIK_LBRACKET 
//			0,//KRBRACKET0x1B//］キーD_DIK_RBRACKET 
//			0,//KRETURN0x1C//EnterキーD_DIK_RETURN 
//			0,//KLCONTROL0x1D//左CtrlキーD_DIK_LCONTROL 
//			Keyboard_a,//KA0x1E//ＡキーD_DIK_A 
//			Keyboard_s,//KS0x1F//ＳキーD_DIK_S 
//			Keyboard_d,//KD0x20//ＤキーD_DIK_D 
//			Keyboard_f,//KF0x21//ＦキーD_DIK_F 
//			Keyboard_g,//KG0x22//ＧキーD_DIK_G 
//			Keyboard_h,//KH0x23//ＨキーD_DIK_H 
//			Keyboard_j,//KJ0x24//ＪキーD_DIK_J 
//			Keyboard_k,//KK0x25//ＫキーD_DIK_K 
//			Keyboard_l,//KL0x26//ＬキーD_DIK_L 
//			Keyboard_semicolon,//KSEMICOLON0x27//；キーD_DIK_SEMICOLON 
//			Keyboard_Unknown,//Ka40 
//			Keyboard_Unknown,//Ka41 
//			0,//KLSHIFT0x2A//左ShiftキーD_DIK_LSHIFT 
//			0,//KBACKSLASH0x2B//＼キーD_DIK_BACKSLASH 
//			Keyboard_z,//KZ0x2C//ＺキーD_DIK_Z 
//			Keyboard_x,//KX0x2D//ＸキーD_DIK_X 
//			Keyboard_c,//KC0x2E//ＣキーD_DIK_C 
//			Keyboard_v,//KV0x2F//ＶキーD_DIK_V 
//			Keyboard_b,//KB0x30//ＢキーD_DIK_B 
//			Keyboard_n,//KN0x31//ＮキーD_DIK_N 
//			Keyboard_m,//KM0x32//ＭキーD_DIK_M 
//			0,//KCOMMA0x33//，キーD_DIK_COMMA 
//			0,//KPERIOD0x34//．キーD_DIK_PERIOD 
//			0,//KSLASH0x35//／キーD_DIK_SLASH 
//			0,//KRSHIFT0x36//右ShiftキーD_DIK_RSHIFT 
//			0,//KMULTIPLY0x37//テンキー＊キーD_DIK_MULTIPLY 
//			0,//KLALT0x38//左AltキーD_DIK_LALT 
//			0,//KSPACE0x39//スペースキーD_DIK_SPACE 
//			0,//KCAPSLOCK0x3A//CaspLockキーD_DIK_CAPSLOCK 
//			Keyboard_F1,//KF10x3B//Ｆ１キーD_DIK_F1 
//			Keyboard_F2,//KF20x3C//Ｆ２キーD_DIK_F2 
//			Keyboard_F3,//KF30x3D//Ｆ３キーD_DIK_F3 
//			Keyboard_F4,//KF40x3E//Ｆ４キーD_DIK_F4 
//			Keyboard_F5,//KF50x3F//Ｆ５キーD_DIK_F5 
//			Keyboard_F6,//KF60x40//Ｆ６キーD_DIK_F6 
//			Keyboard_F7,//KF70x41//Ｆ７キーD_DIK_F7 
//			Keyboard_F8,//KF80x42//Ｆ８キーD_DIK_F8 
//			Keyboard_F9,//KF90x43//Ｆ９キーD_DIK_F9 
//			Keyboard_F10,//KF100x44//Ｆ１０キーD_DIK_F10 
//			0,//KNUMLOCK0x45//テンキーNumLockキーD_DIK_NUMLOCK 
//			0,//KSCROLL0x46//ScrollLockキーD_DIK_SCROLL 
//			Keypad_7,//KNUMPAD70x47//テンキー７D_DIK_NUMPAD7 
//			Keypad_8,//KNUMPAD80x48//テンキー８D_DIK_NUMPAD8 
//			Keypad_9,//KNUMPAD90x49//テンキー９D_DIK_NUMPAD9 
//			0,//KSUBTRACT0x4A//テンキー－キーD_DIK_SUBTRACT 
//			Keypad_4,//KNUMPAD40x4B//テンキー４D_DIK_NUMPAD4 
//			Keypad_5,//KNUMPAD50x4C//テンキー５D_DIK_NUMPAD5 
//			Keypad_6,//KNUMPAD60x4D//テンキー６D_DIK_NUMPAD6 
//			Keyboard_Unknown,//KaDD0x4E//テンキー＋キーD_DIK_ADD 
//			Keypad_1,//KNUMPAD10x4F//テンキー１D_DIK_NUMPAD1 
//			Keypad_2,//KNUMPAD20x50//テンキー２D_DIK_NUMPAD2 
//			Keypad_3,//KNUMPAD30x51//テンキー３D_DIK_NUMPAD3 
//			Keypad_0,//KNUMPAD00x52//テンキー０D_DIK_NUMPAD0 
//			0,//KDECIMAL0x53//テンキー．キーD_DIK_DECIMAL 
//			Keyboard_Unknown,//Ka84 
//			Keyboard_Unknown,//Ka85 
//			Keyboard_Unknown,//Ka86 
//			Keyboard_F11,//KF110x57//Ｆ１１キーD_DIK_F11 
//			Keyboard_F12,//KF120x58//Ｆ１２キーD_DIK_F12 
//			Keyboard_Unknown,//Ka89 
//			Keyboard_Unknown,//Ka90 
//			Keyboard_Unknown,//Ka91 
//			Keyboard_Unknown,//Ka92 
//			Keyboard_Unknown,//Ka93 
//			Keyboard_Unknown,//Ka94 
//			Keyboard_Unknown,//Ka95 
//			Keyboard_Unknown,//Ka96 
//			Keyboard_Unknown,//Ka97 
//			Keyboard_Unknown,//Ka98 
//			Keyboard_Unknown,//Ka99 
//			Keyboard_Unknown,//Ka100 
//			Keyboard_Unknown,//Ka101 
//			Keyboard_Unknown,//Ka102 
//			Keyboard_Unknown,//Ka103 
//			Keyboard_Unknown,//Ka104 
//			Keyboard_Unknown,//Ka105 
//			Keyboard_Unknown,//Ka106 
//			Keyboard_Unknown,//Ka107 
//			Keyboard_Unknown,//Ka108 
//			Keyboard_Unknown,//Ka109 
//			Keyboard_Unknown,//Ka110 
//			Keyboard_Unknown,//Ka111 
//			0,//KKANA0x70//カナキーD_DIK_KANA 
//			Keyboard_Unknown,//Ka113 
//			Keyboard_Unknown,//Ka114 
//			Keyboard_Unknown,//Ka115 
//			Keyboard_Unknown,//Ka116 
//			Keyboard_Unknown,//Ka117 
//			Keyboard_Unknown,//Ka118 
//			Keyboard_Unknown,//Ka119 
//			Keyboard_Unknown,//Ka120 
//			0,//KCONVERT0x79//変換キーD_DIK_CONVERT 
//			Keyboard_Unknown,//Ka122 
//			0,//KNOCONVERT0x7B//無変換キーD_DIK_NOCONVERT 
//			Keyboard_Unknown,//Ka124 
//			0,//KYEN0x7D//￥キーD_DIK_YEN 
//			Keyboard_Unknown,//Ka126 
//			Keyboard_Unknown,//Ka127 
//			Keyboard_Unknown,//Ka128 
//			Keyboard_Unknown,//Ka129 
//			Keyboard_Unknown,//Ka130 
//			Keyboard_Unknown,//Ka131 
//			Keyboard_Unknown,//Ka132 
//			Keyboard_Unknown,//Ka133 
//			Keyboard_Unknown,//Ka134 
//			Keyboard_Unknown,//Ka135 
//			Keyboard_Unknown,//Ka136 
//			Keyboard_Unknown,//Ka137 
//			Keyboard_Unknown,//Ka138 
//			Keyboard_Unknown,//Ka139 
//			Keyboard_Unknown,//Ka140 
//			Keyboard_Unknown,//Ka141 
//			Keyboard_Unknown,//Ka142 
//			Keyboard_Unknown,//Ka143 
//			0,//KPREVTRACK0x90//＾キーD_DIK_PREVTRACK 
//			Keyboard_Unknown,//KaT0x91//＠キーD_DIK_AT 
//			0,//KCOLON0x92//：キーD_DIK_COLON 
//			Keyboard_Unknown,//Ka147 
//			Keyboard_grave_accentilde,//KKANJI0x94//漢字キーD_DIK_KANJI 
//			Keyboard_Unknown,//Ka149 
//			Keyboard_Unknown,//Ka150 
//			Keyboard_Unknown,//Ka151 
//			Keyboard_Unknown,//Ka152 
//			Keyboard_Unknown,//Ka153 
//			Keyboard_Unknown,//Ka154 
//			Keyboard_Unknown,//Ka155 
//			Keypad_ENTER,//KNUMPADENTER0x9C//テンキーのエンターキーD_DIK_NUMPADENTER 
//			0,//KRCONTROL0x9D//右CtrlキーD_DIK_RCONTROL 
//			Keyboard_Unknown,//Ka158 
//			Keyboard_Unknown,//Ka159 
//			Keyboard_Unknown,//Ka160 
//			Keyboard_Unknown,//Ka161 
//			Keyboard_Unknown,//Ka162 
//			Keyboard_Unknown,//Ka163 
//			Keyboard_Unknown,//Ka164 
//			Keyboard_Unknown,//Ka165 
//			Keyboard_Unknown,//Ka166 
//			Keyboard_Unknown,//Ka167 
//			Keyboard_Unknown,//Ka168 
//			Keyboard_Unknown,//Ka169 
//			Keyboard_Unknown,//Ka170 
//			Keyboard_Unknown,//Ka171 
//			Keyboard_Unknown,//Ka172 
//			Keyboard_Unknown,//Ka173 
//			Keyboard_Unknown,//Ka174 
//			Keyboard_Unknown,//Ka175 
//			Keyboard_Unknown,//Ka176 
//			Keyboard_Unknown,//Ka177 
//			Keyboard_Unknown,//Ka178 
//			Keyboard_Unknown,//Ka179 
//			Keyboard_Unknown,//Ka180 
//			0,//KDIVIDE0xB5//テンキー／キーD_DIK_DIVIDE 
//			Keyboard_Unknown,//Ka182 
//			0,//KSYSRQ0xB7//PrintScreenキーD_DIK_SYSRQ 
//			0,//KRALT0xB8//右AltキーD_DIK_RALT 
//			Keyboard_Unknown,//Ka185 
//			Keyboard_Unknown,//Ka186 
//			Keyboard_Unknown,//Ka187 
//			Keyboard_Unknown,//Ka188 
//			Keyboard_Unknown,//Ka189 
//			Keyboard_Unknown,//Ka190 
//			Keyboard_Unknown,//Ka191 
//			Keyboard_Unknown,//Ka192 
//			Keyboard_Unknown,//Ka193 
//			Keyboard_Unknown,//Ka194 
//			Keyboard_Unknown,//Ka195 
//			Keyboard_Unknown,//Ka196 
//			0,//KPAUSE0xC5//PauseBreakキーD_DIK_PAUSE 
//			Keyboard_Unknown,//Ka198 
//			0,//KHOME0xC7//HomeキーD_DIK_HOME 
//				Keyboard_UpArrow,//KUP0xC8//上キーD_DIK_UP 
//			0,//KPGUP0xC9//PageUpキーD_DIK_PGUP 
//			Keyboard_Unknown,//Ka202 
//				Keyboard_LeftArrow,//KLEFT0xCB//左キーD_DIK_LEFT 
//			Keyboard_Unknown,//Ka204 
//				Keyboard_RightArrow,//KRIGHT0xCD//右キーD_DIK_RIGHT 
//			Keyboard_Unknown,//Ka206 
//			0,//KEND0xCF//EndキーD_DIK_END 
//				Keyboard_DownArrow,//KDOWN0xD0//下キーD_DIK_DOWN 
//			0,//KPGDN0xD1//PageDownキーD_DIK_PGDN 
//			0,//KINSERT0xD2//InsertキーD_DIK_INSERT 
//			0,//KDELETE0xD3//DeleteキーD_DIK_DELETE 
//			Keyboard_Unknown,//Ka212 
//			Keyboard_Unknown,//Ka213 
//			Keyboard_Unknown,//Ka214 
//			Keyboard_Unknown,//Ka215 
//			Keyboard_Unknown,//Ka216 
//			Keyboard_Unknown,//Ka217 
//			Keyboard_Unknown,//Ka218 
//			0,//KLWIN0xDB//左WinキーD_DIK_LWIN 
//			0,//KRWIN0xDC//右WinキーD_DIK_RWIN 
//			Keyboard_Unknown,//KaPPS0xDD//アプリケーションメニューキーD_DIK_APPS 
//			Keyboard_Unknown,//Ka222 
//			Keyboard_Unknown,//Ka223 
//			Keyboard_Unknown,//Ka224 
//			Keyboard_Unknown,//Ka225 
//			Keyboard_Unknown,//Ka226 
//			Keyboard_Unknown,//Ka227 
//			Keyboard_Unknown,//Ka228 
//			Keyboard_Unknown,//Ka229 
//			Keyboard_Unknown,//Ka230 
//			Keyboard_Unknown,//Ka231 
//			Keyboard_Unknown,//Ka232 
//			Keyboard_Unknown,//Ka233 
//			Keyboard_Unknown,//Ka234 
//			Keyboard_Unknown,//Ka235 
//			Keyboard_Unknown,//Ka236 
//			Keyboard_Unknown,//Ka237 
//			Keyboard_Unknown,//Ka238 
//			Keyboard_Unknown,//Ka239 
//			Keyboard_Unknown,//Ka240 
//			Keyboard_Unknown,//Ka241 
//			Keyboard_Unknown,//Ka242 
//			Keyboard_Unknown,//Ka243 
//			Keyboard_Unknown,//Ka244 
//			Keyboard_Unknown,//Ka245 
//			Keyboard_Unknown,//Ka246 
//			Keyboard_Unknown,//Ka247 
//			Keyboard_Unknown,//Ka248 
//			Keyboard_Unknown,//Ka249 
//			Keyboard_Unknown,//Ka250 
//			Keyboard_Unknown,//Ka251 
//			Keyboard_Unknown,//Ka252 
//			Keyboard_Unknown,//Ka253 
//			Keyboard_Unknown,//Ka254 
//			Keyboard_Unknown//Ka255 
//		};
//		bool AS_key[Keyboard_KeyLast] = { false };
//
//		std::array<char,256> DL_key;
//		DxLib::GetHitKeyStateAll(DL_key.data());
//		for (size_t i = 0; i < 256; ++i) {
//			if (DL_key[i] != 0) {
//				//AS_key[AS_DL_key[i]] = true;
//			}
//		}
//		return AS_key;
//}

#elif defined(ASLIB_INCLUDE_S3) //Siv3D

void checkKey(bool* const AS_key)
{
	AS_key[Keyboard_1] = bool(s3d::Key1.pressed());
	AS_key[Keyboard_2] = bool(s3d::Key2.pressed());
	AS_key[Keyboard_3] = bool(s3d::Key3.pressed());
	AS_key[Keyboard_4] = bool(s3d::Key4.pressed());
	AS_key[Keyboard_5] = bool(s3d::Key5.pressed());
	AS_key[Keyboard_6] = bool(s3d::Key6.pressed());
	AS_key[Keyboard_7] = bool(s3d::Key7.pressed());
	AS_key[Keyboard_8] = bool(s3d::Key8.pressed());
	AS_key[Keyboard_9] = bool(s3d::Key9.pressed());
	AS_key[Keyboard_0] = bool(s3d::Key0.pressed());
	AS_key[Keyboard_a] = bool(s3d::KeyA.pressed());
	AS_key[Keyboard_b] = bool(s3d::KeyB.pressed());
	AS_key[Keyboard_c] = bool(s3d::KeyC.pressed());
	AS_key[Keyboard_d] = bool(s3d::KeyD.pressed());
	AS_key[Keyboard_e] = bool(s3d::KeyE.pressed());
	AS_key[Keyboard_f] = bool(s3d::KeyF.pressed());
	AS_key[Keyboard_g] = bool(s3d::KeyG.pressed());
	AS_key[Keyboard_h] = bool(s3d::KeyH.pressed());
	AS_key[Keyboard_i] = bool(s3d::KeyI.pressed());
	AS_key[Keyboard_j] = bool(s3d::KeyJ.pressed());
	AS_key[Keyboard_k] = bool(s3d::KeyK.pressed());
	AS_key[Keyboard_l] = bool(s3d::KeyL.pressed());
	AS_key[Keyboard_m] = bool(s3d::KeyM.pressed());
	AS_key[Keyboard_n] = bool(s3d::KeyN.pressed());
	AS_key[Keyboard_o] = bool(s3d::KeyO.pressed());
	AS_key[Keyboard_p] = bool(s3d::KeyP.pressed());
	AS_key[Keyboard_q] = bool(s3d::KeyQ.pressed());
	AS_key[Keyboard_r] = bool(s3d::KeyR.pressed());
	AS_key[Keyboard_s] = bool(s3d::KeyS.pressed());
	AS_key[Keyboard_t] = bool(s3d::KeyT.pressed());
	AS_key[Keyboard_u] = bool(s3d::KeyU.pressed());
	AS_key[Keyboard_v] = bool(s3d::KeyV.pressed());
	AS_key[Keyboard_w] = bool(s3d::KeyW.pressed());
	AS_key[Keyboard_x] = bool(s3d::KeyX.pressed());
	AS_key[Keyboard_y] = bool(s3d::KeyY.pressed());
	AS_key[Keyboard_z] = bool(s3d::KeyZ.pressed());
	AS_key[Keyboard_F1] = bool(s3d::KeyF1.pressed());
	AS_key[Keyboard_F2] = bool(s3d::KeyF2.pressed());
	AS_key[Keyboard_F3] = bool(s3d::KeyF3.pressed());
	AS_key[Keyboard_F4] = bool(s3d::KeyF4.pressed());
	AS_key[Keyboard_F5] = bool(s3d::KeyF5.pressed());
	AS_key[Keyboard_F6] = bool(s3d::KeyF6.pressed());
	AS_key[Keyboard_F7] = bool(s3d::KeyF7.pressed());
	AS_key[Keyboard_F8] = bool(s3d::KeyF8.pressed());
	AS_key[Keyboard_F9] = bool(s3d::KeyF9.pressed());
	AS_key[Keyboard_F10] = bool(s3d::KeyF10.pressed());
	AS_key[Keyboard_F11] = bool(s3d::KeyF11.pressed());
	AS_key[Keyboard_F12] = bool(s3d::KeyF12.pressed());
	AS_key[Keyboard_LeftArrow] = bool(s3d::KeyLeft.pressed());
	AS_key[Keyboard_RightArrow] = bool(s3d::KeyRight.pressed());
	AS_key[Keyboard_UpArrow] = bool(s3d::KeyUp.pressed());
	AS_key[Keyboard_DownArrow] = bool(s3d::KeyDown.pressed());
	AS_key[Keyboard_left_shift] = bool(s3d::KeyLShift.pressed());
	AS_key[Keyboard_right_shift] = bool(s3d::KeyRShift.pressed());
	AS_key[Keyboard_left_control] = bool(s3d::KeyLControl.pressed());
	AS_key[Keyboard_right_control] = bool(s3d::KeyRControl.pressed());
	AS_key[Keyboard_left_alt] = bool(s3d::KeyLAlt.pressed());
	AS_key[Keyboard_right_alt] = bool(s3d::KeyRAlt.pressed());
	return;
}
#elif defined(ASLIB_INCLUDE_TP)
void checkKey(bool* const AS_key)
{
	return;
}
#else //Console
void checkKey(bool* const AS_key)
{
	return;
}
#endif

const bool updateKey_(const size_t id_ = 0, const bool is_update = false)
{
	static bool key[Keyboard_KeyLast];
	if (is_update) checkKey(key);
	return key[id_];
}

//
inline const bool asKey(const size_t& id_) { return updateKey_(id_, false); }
inline const int32_t updateKey() { updateKey_(0, true); return 0; }

}
