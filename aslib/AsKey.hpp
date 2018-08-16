//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - AsProject Library
//
//                    Created by Gaccho (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{
	//dir
	enum :size_t
	{
		MOB_DOWN,
		MOB_UP,
		MOB_LEFT,
		MOB_RIGHT,
		MOB_LEFT_UP,
		MOB_RIGHT_UP,
		MOB_LEFT_DOWN,
		MOB_RIGHT_DOWN,
		MOB_CENTER,
	};

	//キーボード配列ID
	enum :size_t {
		aslib_key_unknown,
		aslib_key_grave_accentilde,
		aslib_key_1,
		aslib_key_2,
		aslib_key_3,
		aslib_key_4,
		aslib_key_5,
		aslib_key_6,
		aslib_key_7,
		aslib_key_8,
		aslib_key_9,
		aslib_key_0,
		aslib_key_hyphennderscore,
		aslib_key_equallus,
		aslib_key_international3,
		aslib_key_dELETE_Backspace,
		aslib_key_tab,
		aslib_key_q,
		aslib_key_w,
		aslib_key_e,
		aslib_key_r,
		aslib_key_t,
		aslib_key_y,
		aslib_key_u,
		aslib_key_i,
		aslib_key_o,
		aslib_key_p,
		aslib_key_left_square_bracketeft_curly_bracket,
		aslib_key_right_square_bracketight_curly_bracket,
		aslib_key_ertical_line,
		aslib_key_caps_Lock,
		aslib_key_a,
		aslib_key_s,
		aslib_key_d,
		aslib_key_f,
		aslib_key_g,
		aslib_key_h,
		aslib_key_j,
		aslib_key_k,
		aslib_key_l,
		aslib_key_semicolon,
		aslib_key_colon,
		aslib_key_non_US_numberilde,
		aslib_key_enter,
		aslib_key_left_shift,
		aslib_key_unknown1,
		aslib_key_z,
		aslib_key_x,
		aslib_key_c,
		aslib_key_v,
		aslib_key_b,
		aslib_key_n,
		aslib_key_m,
		aslib_key_commaess_than_sign,
		aslib_key_full_stopreater_than_sign,
		aslib_key_solidusuestion,
		aslib_key_international1,
		aslib_key_right_shift,
		aslib_key_left_control,
		aslib_key_unknown2,
		aslib_key_left_alt,
		aslib_key_space,
		aslib_key_right_alt,
		aslib_key_unknown3,
		aslib_key_right_control,
		aslib_key_unknown4,
		aslib_key_unknown5,
		aslib_key_unknown6,
		aslib_key_unknown7,
		aslib_key_unknown8,
		aslib_key_unknown9,
		aslib_key_unknown10,
		aslib_key_unknown11,
		aslib_key_unknown12,
		aslib_key_unknown13,
		aslib_key_insert,
		aslib_key_delete_Forward,
		aslib_key_unknown14,
		aslib_key_unknown15,
		aslib_key_left,
		aslib_key_home,
		aslib_key_end,
		aslib_key_unknown16,
		aslib_key_up,
		aslib_key_down,
		aslib_key_pageUp,
		aslib_key_pageDown,
		aslib_key_unknown17,
		aslib_key_unknown18,
		aslib_key_right,
		Keypad_Num_Locklear,
		Keypad_7,
		Keypad_4,
		Keypad_1,
		aslib_key_unknown19,
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
		aslib_key_unknown20,
		Keypad_ENTER,
		aslib_key_unknown21,
		aslib_key_eSCAPE,
		aslib_key_unknown22,
		aslib_key_f1,
		aslib_key_f2,
		aslib_key_f3,
		aslib_key_f4,
		aslib_key_f5,
		aslib_key_f6,
		aslib_key_f7,
		aslib_key_f8,
		aslib_key_f9,
		aslib_key_f10,
		aslib_key_f11,
		aslib_key_f12,
		aslib_key_printScreen,
		aslib_key_scroll_Lock,
		aslib_key_pause,
		aslib_key_left_GUI,
		aslib_key_right_GUI,
		aslib_key_application,
		aslib_key_unknown23,
		aslib_key_international5,
		aslib_key_international4,
		aslib_key_international2,
		aslib_key_keyLast,
		aslib_key_135,
		aslib_key_136,
		aslib_key_137,
		aslib_key_138,
		aslib_key_139,
		aslib_key_140,
		aslib_key_141,
		aslib_key_142,
		aslib_key_143,
		aslib_key_144,
		aslib_key_145,
		aslib_key_146,
		aslib_key_147,
		aslib_key_148,
		aslib_key_149,
		aslib_key_150,
		aslib_key_151,
		aslib_key_152,
		aslib_key_153,
		aslib_key_154,
		aslib_key_155,
		aslib_key_156,
		aslib_key_157,
		aslib_key_158,
		aslib_key_159,
		aslib_key_160,
		aslib_key_161,
		aslib_key_162,
		aslib_key_163,
		aslib_key_164,
		aslib_key_165,
		aslib_key_166,
		aslib_key_167,
		aslib_key_168,
		aslib_key_169,
		aslib_key_170,
		aslib_key_171,
		aslib_key_172,
		aslib_key_173,
		aslib_key_174,
		aslib_key_175,
		aslib_key_176,
		aslib_key_177,
		aslib_key_178,
		aslib_key_179,
		aslib_key_180,
		aslib_key_181,
		aslib_key_182,
		aslib_key_183,
		aslib_key_184,
		aslib_key_185,
		aslib_key_186,
		aslib_key_187,
		aslib_key_188,
		aslib_key_189,
		aslib_key_190,
		aslib_key_191,
		aslib_key_192,
		aslib_key_193,
		aslib_key_194,
		aslib_key_195,
		aslib_key_196,
		aslib_key_197,
		aslib_key_198,
		aslib_key_199,
		aslib_key_200,
		aslib_key_201,
		aslib_key_202,
		aslib_key_203,
		aslib_key_204,
		aslib_key_205,
		aslib_key_206,
		aslib_key_207,
		aslib_key_208,
		aslib_key_209,
		aslib_key_210,
		aslib_key_211,
		aslib_key_212,
		aslib_key_213,
		aslib_key_214,
		aslib_key_215,
		aslib_key_216,
		aslib_key_217,
		aslib_key_218,
		aslib_key_219,
		aslib_key_220,
		aslib_key_221,
		aslib_key_222,
		aslib_key_223,
		aslib_key_224,
		aslib_key_225,
		aslib_key_226,
		aslib_key_227,
		aslib_key_228,
		aslib_key_229,
		aslib_key_230,
		aslib_key_231,
		aslib_key_232,
		aslib_key_233,
		aslib_key_234,
		aslib_key_235,
		aslib_key_236,
		aslib_key_237,
		aslib_key_238,
		aslib_key_239,
		aslib_key_240,
		aslib_key_241,
		aslib_key_242,
		aslib_key_243,
		aslib_key_244,
		aslib_key_245,
		aslib_key_246,
		aslib_key_247,
		aslib_key_248,
		aslib_key_249,
		aslib_key_250,
		aslib_key_251,
		aslib_key_252,
		aslib_key_253,
		aslib_key_254,
		aslib_key_255,
		aslib_key_left_up,
		aslib_key_right_up,
		aslib_key_left_down,
		aslib_key_right_down,
		aslib_key_w_a,
		aslib_key_w_d,
		aslib_key_s_a,
		aslib_key_s_d,
	};

	//class KeyControl
	//{
	//public:

	//private:
	//	std::array<int32_t, 256>aslib_update_key = {};
	//	//std::array<int32_t, 256>config = {};
	//	//std::array<Counter, 256> counter = {};
	//};

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
	
void checkKey(bool* const AS_key,Counter* const AS_count)
{
	constexpr std::array<size_t, aslib_key_keyLast> DL_AS_key{
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
		0//KEY_INPUT_INTERNATIONAL2,
	};

	std::array<char, 256> DL_key;
	DxLib::GetHitKeyStateAll(DL_key.data());
	for (size_t i = 0; i < aslib_key_keyLast; ++i) {
		if (DL_key[DL_AS_key[i]] != 0) AS_key[i] = true;
		else AS_key[i] = false;
		AS_count[i].update(bool(AS_key[i]));
	}
	return;
}

#elif defined(ASLIB_INCLUDE_S3) //Siv3D

void checkKey(bool* const AS_key, Counter* const AS_count)
{
	for (size_t i = 0; i < aslib_key_keyLast; ++i) {
		AS_key[i] = false;
	}
	AS_key[aslib_key_1] = bool(s3d::Key1.pressed());
	AS_key[aslib_key_2] = bool(s3d::Key2.pressed());
	AS_key[aslib_key_3] = bool(s3d::Key3.pressed());
	AS_key[aslib_key_4] = bool(s3d::Key4.pressed());
	AS_key[aslib_key_5] = bool(s3d::Key5.pressed());
	AS_key[aslib_key_6] = bool(s3d::Key6.pressed());
	AS_key[aslib_key_7] = bool(s3d::Key7.pressed());
	AS_key[aslib_key_8] = bool(s3d::Key8.pressed());
	AS_key[aslib_key_9] = bool(s3d::Key9.pressed());
	AS_key[aslib_key_0] = bool(s3d::Key0.pressed());
	AS_key[aslib_key_a] = bool(s3d::KeyA.pressed());
	AS_key[aslib_key_b] = bool(s3d::KeyB.pressed());
	AS_key[aslib_key_c] = bool(s3d::KeyC.pressed());
	AS_key[aslib_key_d] = bool(s3d::KeyD.pressed());
	AS_key[aslib_key_e] = bool(s3d::KeyE.pressed());
	AS_key[aslib_key_f] = bool(s3d::KeyF.pressed());
	AS_key[aslib_key_g] = bool(s3d::KeyG.pressed());
	AS_key[aslib_key_h] = bool(s3d::KeyH.pressed());
	AS_key[aslib_key_i] = bool(s3d::KeyI.pressed());
	AS_key[aslib_key_j] = bool(s3d::KeyJ.pressed());
	AS_key[aslib_key_k] = bool(s3d::KeyK.pressed());
	AS_key[aslib_key_l] = bool(s3d::KeyL.pressed());
	AS_key[aslib_key_m] = bool(s3d::KeyM.pressed());
	AS_key[aslib_key_n] = bool(s3d::KeyN.pressed());
	AS_key[aslib_key_o] = bool(s3d::KeyO.pressed());
	AS_key[aslib_key_p] = bool(s3d::KeyP.pressed());
	AS_key[aslib_key_q] = bool(s3d::KeyQ.pressed());
	AS_key[aslib_key_r] = bool(s3d::KeyR.pressed());
	AS_key[aslib_key_s] = bool(s3d::KeyS.pressed());
	AS_key[aslib_key_t] = bool(s3d::KeyT.pressed());
	AS_key[aslib_key_u] = bool(s3d::KeyU.pressed());
	AS_key[aslib_key_v] = bool(s3d::KeyV.pressed());
	AS_key[aslib_key_w] = bool(s3d::KeyW.pressed());
	AS_key[aslib_key_x] = bool(s3d::KeyX.pressed());
	AS_key[aslib_key_y] = bool(s3d::KeyY.pressed());
	AS_key[aslib_key_z] = bool(s3d::KeyZ.pressed());
	AS_key[aslib_key_f1] = bool(s3d::KeyF1.pressed());
	AS_key[aslib_key_f2] = bool(s3d::KeyF2.pressed());
	AS_key[aslib_key_f3] = bool(s3d::KeyF3.pressed());
	AS_key[aslib_key_f4] = bool(s3d::KeyF4.pressed());
	AS_key[aslib_key_f5] = bool(s3d::KeyF5.pressed());
	AS_key[aslib_key_f6] = bool(s3d::KeyF6.pressed());
	AS_key[aslib_key_f7] = bool(s3d::KeyF7.pressed());
	AS_key[aslib_key_f8] = bool(s3d::KeyF8.pressed());
	AS_key[aslib_key_f9] = bool(s3d::KeyF9.pressed());
	AS_key[aslib_key_f10] = bool(s3d::KeyF10.pressed());
	AS_key[aslib_key_f11] = bool(s3d::KeyF11.pressed());
	AS_key[aslib_key_f12] = bool(s3d::KeyF12.pressed());
	AS_key[aslib_key_left] = bool(s3d::KeyLeft.pressed());
	AS_key[aslib_key_right] = bool(s3d::KeyRight.pressed());
	AS_key[aslib_key_up] = bool(s3d::KeyUp.pressed());
	AS_key[aslib_key_down] = bool(s3d::KeyDown.pressed());
	AS_key[aslib_key_left_shift] = bool(s3d::KeyLShift.pressed());
	AS_key[aslib_key_right_shift] = bool(s3d::KeyRShift.pressed());
	AS_key[aslib_key_left_control] = bool(s3d::KeyLControl.pressed());
	AS_key[aslib_key_right_control] = bool(s3d::KeyRControl.pressed());
	AS_key[aslib_key_left_alt] = bool(s3d::KeyLAlt.pressed());
	AS_key[aslib_key_right_alt] = bool(s3d::KeyRAlt.pressed());
	AS_key[aslib_key_enter] = bool(s3d::KeyEnter.pressed());

	for (size_t i = 0; i < aslib_key_keyLast; ++i) {
		AS_count[i].update(bool(AS_key[i]));
	}
	return;
}
#elif defined(ASLIB_INCLUDE_OF)
void checkKey(bool* const AS_key, Counter* const AS_count)
{
	return;
}
#elif defined(ASLIB_INCLUDE_TP)
void checkKey(bool* const AS_key, Counter* const AS_count)
{
	return;
}
#else //Console
void checkKey(bool* const AS_key, Counter* const AS_count)
{
	return;
}
#endif

enum :size_t {
	aslib_counter_empty,
	aslib_counter_touch,
	aslib_counter_up,
	aslib_counter_down,
	aslib_counter_touch0,
	aslib_counter_up0,
	aslib_counter_down0,
};

const bool updateKey_(const size_t id_ = 0, const bool is_update = false, const size_t count_id = aslib_counter_empty,const bool is_set=false)
{
	static bool aslib_update_key[aslib_key_keyLast];
	static Counter aslib_update_count[aslib_key_keyLast];
	if (is_update) checkKey(aslib_update_key, aslib_update_count);
	switch (count_id)
	{
	case aslib_counter_touch: return aslib_update_count[id_].count();
	case aslib_counter_up: return aslib_update_count[id_].up();
	case aslib_counter_down: return aslib_update_count[id_].down();
	case aslib_counter_touch0: return aslib_update_count[id_].count0();
	case aslib_counter_up0: return aslib_update_count[id_].up0();
	case aslib_counter_down0: return aslib_update_count[id_].down0();
	default: break;
	}
	if (is_set) {
		aslib_update_key[id_] = true;
		aslib_update_count[id_].update(true);
	}
	return aslib_update_key[id_];
}

inline const bool asKeySet(const size_t& id_) { return updateKey_(id_, false, aslib_counter_empty, true); }
inline const bool asKey(const size_t& id_) { return updateKey_(id_, false); }
inline const bool asKeyTouch(const size_t& id_) { return updateKey_(id_, false, aslib_counter_touch); }
inline const bool asKeyTouch0(const size_t& id_) { return updateKey_(id_, false, aslib_counter_touch0); }
inline const bool asKeyUp(const size_t& id_) { return updateKey_(id_, false, aslib_counter_up); }
inline const bool asKeyUp0(const size_t& id_) { return updateKey_(id_, false, aslib_counter_up0); }
inline const bool asKeyDown(const size_t& id_) { return updateKey_(id_, false, aslib_counter_down); }
inline const bool asKeyDown0(const size_t& id_) { return updateKey_(id_, false, aslib_counter_down0); }

inline const bool asKeyA() { return updateKey_(aslib_key_a, false); }
inline const bool asKeyA_Touch() { return updateKey_(aslib_key_a, false, aslib_counter_touch); }
inline const bool asKeyA_Touch0() { return updateKey_(aslib_key_a, false, aslib_counter_touch0); }
inline const bool asKeyA_Up() { return updateKey_(aslib_key_a, false, aslib_counter_up); }
inline const bool asKeyA_Up0() { return updateKey_(aslib_key_a, false, aslib_counter_up0); }
inline const bool asKeyA_Down() { return updateKey_(aslib_key_a, false, aslib_counter_down); }
inline const bool asKeyA_Down0() { return updateKey_(aslib_key_a, false, aslib_counter_down0); }

inline const bool asKeyB() { return updateKey_(aslib_key_b, false); }
inline const bool asKeyB_Touch() { return updateKey_(aslib_key_b, false, aslib_counter_touch); }
inline const bool asKeyB_Touch0() { return updateKey_(aslib_key_b, false, aslib_counter_touch0); }
inline const bool asKeyB_Up() { return updateKey_(aslib_key_b, false, aslib_counter_up); }
inline const bool asKeyB_Up0() { return updateKey_(aslib_key_b, false, aslib_counter_up0); }
inline const bool asKeyB_Down() { return updateKey_(aslib_key_b, false, aslib_counter_down); }
inline const bool asKeyB_Down0() { return updateKey_(aslib_key_b, false, aslib_counter_down0); }

inline const bool asKeyC() { return updateKey_(aslib_key_c, false); }
inline const bool asKeyC_Touch() { return updateKey_(aslib_key_c, false, aslib_counter_touch); }
inline const bool asKeyC_Touch0() { return updateKey_(aslib_key_c, false, aslib_counter_touch0); }
inline const bool asKeyC_Up() { return updateKey_(aslib_key_c, false, aslib_counter_up); }
inline const bool asKeyC_Up0() { return updateKey_(aslib_key_c, false, aslib_counter_up0); }
inline const bool asKeyC_Down() { return updateKey_(aslib_key_c, false, aslib_counter_down); }
inline const bool asKeyC_Down0() { return updateKey_(aslib_key_c, false, aslib_counter_down0); }

inline const bool asKeyD() { return updateKey_(aslib_key_d, false); }
inline const bool asKeyD_Touch() { return updateKey_(aslib_key_d, false, aslib_counter_touch); }
inline const bool asKeyD_Touch0() { return updateKey_(aslib_key_d, false, aslib_counter_touch0); }
inline const bool asKeyD_Up() { return updateKey_(aslib_key_d, false, aslib_counter_up); }
inline const bool asKeyD_Up0() { return updateKey_(aslib_key_d, false, aslib_counter_up0); }
inline const bool asKeyD_Down() { return updateKey_(aslib_key_d, false, aslib_counter_down); }
inline const bool asKeyD_Down0() { return updateKey_(aslib_key_d, false, aslib_counter_down0); }

inline const bool asKeyE() { return updateKey_(aslib_key_e, false); }
inline const bool asKeyE_Touch() { return updateKey_(aslib_key_e, false, aslib_counter_touch); }
inline const bool asKeyE_Touch0() { return updateKey_(aslib_key_e, false, aslib_counter_touch0); }
inline const bool asKeyE_Up() { return updateKey_(aslib_key_e, false, aslib_counter_up); }
inline const bool asKeyE_Up0() { return updateKey_(aslib_key_e, false, aslib_counter_up0); }
inline const bool asKeyE_Down() { return updateKey_(aslib_key_e, false, aslib_counter_down); }
inline const bool asKeyE_Down0() { return updateKey_(aslib_key_e, false, aslib_counter_down0); }

inline const bool asKeyF() { return updateKey_(aslib_key_f, false); }
inline const bool asKeyF_Touch() { return updateKey_(aslib_key_f, false, aslib_counter_touch); }
inline const bool asKeyF_Touch0() { return updateKey_(aslib_key_f, false, aslib_counter_touch0); }
inline const bool asKeyF_Up() { return updateKey_(aslib_key_f, false, aslib_counter_up); }
inline const bool asKeyF_Up0() { return updateKey_(aslib_key_f, false, aslib_counter_up0); }
inline const bool asKeyF_Down() { return updateKey_(aslib_key_f, false, aslib_counter_down); }
inline const bool asKeyF_Down0() { return updateKey_(aslib_key_f, false, aslib_counter_down0); }

inline const bool asKeyG() { return updateKey_(aslib_key_g, false); }
inline const bool asKeyG_Touch() { return updateKey_(aslib_key_g, false, aslib_counter_touch); }
inline const bool asKeyG_Touch0() { return updateKey_(aslib_key_g, false, aslib_counter_touch0); }
inline const bool asKeyG_Up() { return updateKey_(aslib_key_g, false, aslib_counter_up); }
inline const bool asKeyG_Up0() { return updateKey_(aslib_key_g, false, aslib_counter_up0); }
inline const bool asKeyG_Down() { return updateKey_(aslib_key_g, false, aslib_counter_down); }
inline const bool asKeyG_Down0() { return updateKey_(aslib_key_g, false, aslib_counter_down0); }

inline const bool asKeyH() { return updateKey_(aslib_key_h, false); }
inline const bool asKeyH_Touch() { return updateKey_(aslib_key_h, false, aslib_counter_touch); }
inline const bool asKeyH_Touch0() { return updateKey_(aslib_key_h, false, aslib_counter_touch0); }
inline const bool asKeyH_Up() { return updateKey_(aslib_key_h, false, aslib_counter_up); }
inline const bool asKeyH_Up0() { return updateKey_(aslib_key_h, false, aslib_counter_up0); }
inline const bool asKeyH_Down() { return updateKey_(aslib_key_h, false, aslib_counter_down); }
inline const bool asKeyH_Down0() { return updateKey_(aslib_key_h, false, aslib_counter_down0); }

inline const bool asKeyI() { return updateKey_(aslib_key_i, false); }
inline const bool asKeyI_Touch() { return updateKey_(aslib_key_i, false, aslib_counter_touch); }
inline const bool asKeyI_Touch0() { return updateKey_(aslib_key_i, false, aslib_counter_touch0); }
inline const bool asKeyI_Up() { return updateKey_(aslib_key_i, false, aslib_counter_up); }
inline const bool asKeyI_Up0() { return updateKey_(aslib_key_i, false, aslib_counter_up0); }
inline const bool asKeyI_Down() { return updateKey_(aslib_key_i, false, aslib_counter_down); }
inline const bool asKeyI_Down0() { return updateKey_(aslib_key_i, false, aslib_counter_down0); }

inline const bool asKeyJ() { return updateKey_(aslib_key_j, false); }
inline const bool asKeyJ_Touch() { return updateKey_(aslib_key_j, false, aslib_counter_touch); }
inline const bool asKeyJ_Touch0() { return updateKey_(aslib_key_j, false, aslib_counter_touch0); }
inline const bool asKeyJ_Up() { return updateKey_(aslib_key_j, false, aslib_counter_up); }
inline const bool asKeyJ_Up0() { return updateKey_(aslib_key_j, false, aslib_counter_up0); }
inline const bool asKeyJ_Down() { return updateKey_(aslib_key_j, false, aslib_counter_down); }
inline const bool asKeyJ_Down0() { return updateKey_(aslib_key_j, false, aslib_counter_down0); }

inline const bool asKeyK() { return updateKey_(aslib_key_k, false); }
inline const bool asKeyK_Touch() { return updateKey_(aslib_key_k, false, aslib_counter_touch); }
inline const bool asKeyK_Touch0() { return updateKey_(aslib_key_k, false, aslib_counter_touch0); }
inline const bool asKeyK_Up() { return updateKey_(aslib_key_k, false, aslib_counter_up); }
inline const bool asKeyK_Up0() { return updateKey_(aslib_key_k, false, aslib_counter_up0); }
inline const bool asKeyK_Down() { return updateKey_(aslib_key_k, false, aslib_counter_down); }
inline const bool asKeyK_Down0() { return updateKey_(aslib_key_k, false, aslib_counter_down0); }

inline const bool asKeyL() { return updateKey_(aslib_key_l, false); }
inline const bool asKeyL_Touch() { return updateKey_(aslib_key_l, false, aslib_counter_touch); }
inline const bool asKeyL_Touch0() { return updateKey_(aslib_key_l, false, aslib_counter_touch0); }
inline const bool asKeyL_Up() { return updateKey_(aslib_key_l, false, aslib_counter_up); }
inline const bool asKeyL_Up0() { return updateKey_(aslib_key_l, false, aslib_counter_up0); }
inline const bool asKeyL_Down() { return updateKey_(aslib_key_l, false, aslib_counter_down); }
inline const bool asKeyL_Down0() { return updateKey_(aslib_key_l, false, aslib_counter_down0); }

inline const bool asKeyM() { return updateKey_(aslib_key_m, false); }
inline const bool asKeyM_Touch() { return updateKey_(aslib_key_m, false, aslib_counter_touch); }
inline const bool asKeyM_Touch0() { return updateKey_(aslib_key_m, false, aslib_counter_touch0); }
inline const bool asKeyM_Up() { return updateKey_(aslib_key_m, false, aslib_counter_up); }
inline const bool asKeyM_Up0() { return updateKey_(aslib_key_m, false, aslib_counter_up0); }
inline const bool asKeyM_Down() { return updateKey_(aslib_key_m, false, aslib_counter_down); }
inline const bool asKeyM_Down0() { return updateKey_(aslib_key_m, false, aslib_counter_down0); }

inline const bool asKeyN() { return updateKey_(aslib_key_n, false); }
inline const bool asKeyN_Touch() { return updateKey_(aslib_key_n, false, aslib_counter_touch); }
inline const bool asKeyN_Touch0() { return updateKey_(aslib_key_n, false, aslib_counter_touch0); }
inline const bool asKeyN_Up() { return updateKey_(aslib_key_n, false, aslib_counter_up); }
inline const bool asKeyN_Up0() { return updateKey_(aslib_key_n, false, aslib_counter_up0); }
inline const bool asKeyN_Down() { return updateKey_(aslib_key_n, false, aslib_counter_down); }
inline const bool asKeyN_Down0() { return updateKey_(aslib_key_n, false, aslib_counter_down0); }

inline const bool asKeyO() { return updateKey_(aslib_key_o, false); }
inline const bool asKeyO_Touch() { return updateKey_(aslib_key_o, false, aslib_counter_touch); }
inline const bool asKeyO_Touch0() { return updateKey_(aslib_key_o, false, aslib_counter_touch0); }
inline const bool asKeyO_Up() { return updateKey_(aslib_key_o, false, aslib_counter_up); }
inline const bool asKeyO_Up0() { return updateKey_(aslib_key_o, false, aslib_counter_up0); }
inline const bool asKeyO_Down() { return updateKey_(aslib_key_o, false, aslib_counter_down); }
inline const bool asKeyO_Down0() { return updateKey_(aslib_key_o, false, aslib_counter_down0); }

inline const bool asKeyP() { return updateKey_(aslib_key_p, false); }
inline const bool asKeyP_Touch() { return updateKey_(aslib_key_p, false, aslib_counter_touch); }
inline const bool asKeyP_Touch0() { return updateKey_(aslib_key_p, false, aslib_counter_touch0); }
inline const bool asKeyP_Up() { return updateKey_(aslib_key_p, false, aslib_counter_up); }
inline const bool asKeyP_Up0() { return updateKey_(aslib_key_p, false, aslib_counter_up0); }
inline const bool asKeyP_Down() { return updateKey_(aslib_key_p, false, aslib_counter_down); }
inline const bool asKeyP_Down0() { return updateKey_(aslib_key_p, false, aslib_counter_down0); }

inline const bool asKeyQ() { return updateKey_(aslib_key_q, false); }
inline const bool asKeyQ_Touch() { return updateKey_(aslib_key_q, false, aslib_counter_touch); }
inline const bool asKeyQ_Touch0() { return updateKey_(aslib_key_q, false, aslib_counter_touch0); }
inline const bool asKeyQ_Up() { return updateKey_(aslib_key_q, false, aslib_counter_up); }
inline const bool asKeyQ_Up0() { return updateKey_(aslib_key_q, false, aslib_counter_up0); }
inline const bool asKeyQ_Down() { return updateKey_(aslib_key_q, false, aslib_counter_down); }
inline const bool asKeyQ_Down0() { return updateKey_(aslib_key_q, false, aslib_counter_down0); }

inline const bool asKeyR() { return updateKey_(aslib_key_r, false); }
inline const bool asKeyR_Touch() { return updateKey_(aslib_key_r, false, aslib_counter_touch); }
inline const bool asKeyR_Touch0() { return updateKey_(aslib_key_r, false, aslib_counter_touch0); }
inline const bool asKeyR_Up() { return updateKey_(aslib_key_r, false, aslib_counter_up); }
inline const bool asKeyR_Up0() { return updateKey_(aslib_key_r, false, aslib_counter_up0); }
inline const bool asKeyR_Down() { return updateKey_(aslib_key_r, false, aslib_counter_down); }
inline const bool asKeyR_Down0() { return updateKey_(aslib_key_r, false, aslib_counter_down0); }

inline const bool asKeyS() { return updateKey_(aslib_key_s, false); }
inline const bool asKeyS_Touch() { return updateKey_(aslib_key_s, false, aslib_counter_touch); }
inline const bool asKeyS_Touch0() { return updateKey_(aslib_key_s, false, aslib_counter_touch0); }
inline const bool asKeyS_Up() { return updateKey_(aslib_key_s, false, aslib_counter_up); }
inline const bool asKeyS_Up0() { return updateKey_(aslib_key_s, false, aslib_counter_up0); }
inline const bool asKeyS_Down() { return updateKey_(aslib_key_s, false, aslib_counter_down); }
inline const bool asKeyS_Down0() { return updateKey_(aslib_key_s, false, aslib_counter_down0); }

inline const bool asKeyT() { return updateKey_(aslib_key_t, false); }
inline const bool asKeyT_Touch() { return updateKey_(aslib_key_t, false, aslib_counter_touch); }
inline const bool asKeyT_Touch0() { return updateKey_(aslib_key_t, false, aslib_counter_touch0); }
inline const bool asKeyT_Up() { return updateKey_(aslib_key_t, false, aslib_counter_up); }
inline const bool asKeyT_Up0() { return updateKey_(aslib_key_t, false, aslib_counter_up0); }
inline const bool asKeyT_Down() { return updateKey_(aslib_key_t, false, aslib_counter_down); }
inline const bool asKeyT_Down0() { return updateKey_(aslib_key_t, false, aslib_counter_down0); }

inline const bool asKeyU() { return updateKey_(aslib_key_u, false); }
inline const bool asKeyU_Touch() { return updateKey_(aslib_key_u, false, aslib_counter_touch); }
inline const bool asKeyU_Touch0() { return updateKey_(aslib_key_u, false, aslib_counter_touch0); }
inline const bool asKeyU_Up() { return updateKey_(aslib_key_u, false, aslib_counter_up); }
inline const bool asKeyU_Up0() { return updateKey_(aslib_key_u, false, aslib_counter_up0); }
inline const bool asKeyU_Down() { return updateKey_(aslib_key_u, false, aslib_counter_down); }
inline const bool asKeyU_Down0() { return updateKey_(aslib_key_u, false, aslib_counter_down0); }

inline const bool asKeyV() { return updateKey_(aslib_key_v, false); }
inline const bool asKeyV_Touch() { return updateKey_(aslib_key_v, false, aslib_counter_touch); }
inline const bool asKeyV_Touch0() { return updateKey_(aslib_key_v, false, aslib_counter_touch0); }
inline const bool asKeyV_Up() { return updateKey_(aslib_key_v, false, aslib_counter_up); }
inline const bool asKeyV_Up0() { return updateKey_(aslib_key_v, false, aslib_counter_up0); }
inline const bool asKeyV_Down() { return updateKey_(aslib_key_v, false, aslib_counter_down); }
inline const bool asKeyV_Down0() { return updateKey_(aslib_key_v, false, aslib_counter_down0); }

inline const bool asKeyW() { return updateKey_(aslib_key_w, false); }
inline const bool asKeyW_Touch() { return updateKey_(aslib_key_w, false, aslib_counter_touch); }
inline const bool asKeyW_Touch0() { return updateKey_(aslib_key_w, false, aslib_counter_touch0); }
inline const bool asKeyW_Up() { return updateKey_(aslib_key_w, false, aslib_counter_up); }
inline const bool asKeyW_Up0() { return updateKey_(aslib_key_w, false, aslib_counter_up0); }
inline const bool asKeyW_Down() { return updateKey_(aslib_key_w, false, aslib_counter_down); }
inline const bool asKeyW_Down0() { return updateKey_(aslib_key_w, false, aslib_counter_down0); }

inline const bool asKeyX() { return updateKey_(aslib_key_x, false); }
inline const bool asKeyX_Touch() { return updateKey_(aslib_key_x, false, aslib_counter_touch); }
inline const bool asKeyX_Touch0() { return updateKey_(aslib_key_x, false, aslib_counter_touch0); }
inline const bool asKeyX_Up() { return updateKey_(aslib_key_x, false, aslib_counter_up); }
inline const bool asKeyX_Up0() { return updateKey_(aslib_key_x, false, aslib_counter_up0); }
inline const bool asKeyX_Down() { return updateKey_(aslib_key_x, false, aslib_counter_down); }
inline const bool asKeyX_Down0() { return updateKey_(aslib_key_x, false, aslib_counter_down0); }

inline const bool asKeyY() { return updateKey_(aslib_key_y, false); }
inline const bool asKeyY_Touch() { return updateKey_(aslib_key_y, false, aslib_counter_touch); }
inline const bool asKeyY_Touch0() { return updateKey_(aslib_key_y, false, aslib_counter_touch0); }
inline const bool asKeyY_Up() { return updateKey_(aslib_key_y, false, aslib_counter_up); }
inline const bool asKeyY_Up0() { return updateKey_(aslib_key_y, false, aslib_counter_up0); }
inline const bool asKeyY_Down() { return updateKey_(aslib_key_y, false, aslib_counter_down); }
inline const bool asKeyY_Down0() { return updateKey_(aslib_key_y, false, aslib_counter_down0); }

inline const bool asKeyZ() { return updateKey_(aslib_key_z, false); }
inline const bool asKeyZ_Touch() { return updateKey_(aslib_key_z, false, aslib_counter_touch); }
inline const bool asKeyZ_Touch0() { return updateKey_(aslib_key_z, false, aslib_counter_touch0); }
inline const bool asKeyZ_Up() { return updateKey_(aslib_key_z, false, aslib_counter_up); }
inline const bool asKeyZ_Up0() { return updateKey_(aslib_key_z, false, aslib_counter_up0); }
inline const bool asKeyZ_Down() { return updateKey_(aslib_key_z, false, aslib_counter_down); }
inline const bool asKeyZ_Down0() { return updateKey_(aslib_key_z, false, aslib_counter_down0); }

inline const bool asKey0() { return updateKey_(aslib_key_0, false); }
inline const bool asKey0_Touch() { return updateKey_(aslib_key_0, false, aslib_counter_touch); }
inline const bool asKey0_Touch0() { return updateKey_(aslib_key_0, false, aslib_counter_touch0); }
inline const bool asKey0_Up() { return updateKey_(aslib_key_0, false, aslib_counter_up); }
inline const bool asKey0_Up0() { return updateKey_(aslib_key_0, false, aslib_counter_up0); }
inline const bool asKey0_Down() { return updateKey_(aslib_key_0, false, aslib_counter_down); }
inline const bool asKey0_Down0() { return updateKey_(aslib_key_0, false, aslib_counter_down0); }

inline const bool asKey1() { return updateKey_(aslib_key_1, false); }
inline const bool asKey1_Touch() { return updateKey_(aslib_key_1, false, aslib_counter_touch); }
inline const bool asKey1_Touch0() { return updateKey_(aslib_key_1, false, aslib_counter_touch0); }
inline const bool asKey1_Up() { return updateKey_(aslib_key_1, false, aslib_counter_up); }
inline const bool asKey1_Up0() { return updateKey_(aslib_key_1, false, aslib_counter_up0); }
inline const bool asKey1_Down() { return updateKey_(aslib_key_1, false, aslib_counter_down); }
inline const bool asKey1_Down0() { return updateKey_(aslib_key_1, false, aslib_counter_down0); }

inline const bool asKey2() { return updateKey_(aslib_key_2, false); }
inline const bool asKey2_Touch() { return updateKey_(aslib_key_2, false, aslib_counter_touch); }
inline const bool asKey2_Touch0() { return updateKey_(aslib_key_2, false, aslib_counter_touch0); }
inline const bool asKey2_Up() { return updateKey_(aslib_key_2, false, aslib_counter_up); }
inline const bool asKey2_Up0() { return updateKey_(aslib_key_2, false, aslib_counter_up0); }
inline const bool asKey2_Down() { return updateKey_(aslib_key_2, false, aslib_counter_down); }
inline const bool asKey2_Down0() { return updateKey_(aslib_key_2, false, aslib_counter_down0); }

inline const bool asKey3() { return updateKey_(aslib_key_3, false); }
inline const bool asKey3_Touch() { return updateKey_(aslib_key_3, false, aslib_counter_touch); }
inline const bool asKey3_Touch0() { return updateKey_(aslib_key_3, false, aslib_counter_touch0); }
inline const bool asKey3_Up() { return updateKey_(aslib_key_3, false, aslib_counter_up); }
inline const bool asKey3_Up0() { return updateKey_(aslib_key_3, false, aslib_counter_up0); }
inline const bool asKey3_Down() { return updateKey_(aslib_key_3, false, aslib_counter_down); }
inline const bool asKey3_Down0() { return updateKey_(aslib_key_3, false, aslib_counter_down0); }

inline const bool asKey4() { return updateKey_(aslib_key_4, false); }
inline const bool asKey4_Touch() { return updateKey_(aslib_key_4, false, aslib_counter_touch); }
inline const bool asKey4_Touch0() { return updateKey_(aslib_key_4, false, aslib_counter_touch0); }
inline const bool asKey4_Up() { return updateKey_(aslib_key_4, false, aslib_counter_up); }
inline const bool asKey4_Up0() { return updateKey_(aslib_key_4, false, aslib_counter_up0); }
inline const bool asKey4_Down() { return updateKey_(aslib_key_4, false, aslib_counter_down); }
inline const bool asKey4_Down0() { return updateKey_(aslib_key_4, false, aslib_counter_down0); }

inline const bool asKey5() { return updateKey_(aslib_key_5, false); }
inline const bool asKey5_Touch() { return updateKey_(aslib_key_5, false, aslib_counter_touch); }
inline const bool asKey5_Touch0() { return updateKey_(aslib_key_5, false, aslib_counter_touch0); }
inline const bool asKey5_Up() { return updateKey_(aslib_key_5, false, aslib_counter_up); }
inline const bool asKey5_Up0() { return updateKey_(aslib_key_5, false, aslib_counter_up0); }
inline const bool asKey5_Down() { return updateKey_(aslib_key_5, false, aslib_counter_down); }
inline const bool asKey5_Down0() { return updateKey_(aslib_key_5, false, aslib_counter_down0); }

inline const bool asKey6() { return updateKey_(aslib_key_6, false); }
inline const bool asKey6_Touch() { return updateKey_(aslib_key_6, false, aslib_counter_touch); }
inline const bool asKey6_Touch0() { return updateKey_(aslib_key_6, false, aslib_counter_touch0); }
inline const bool asKey6_Up() { return updateKey_(aslib_key_6, false, aslib_counter_up); }
inline const bool asKey6_Up0() { return updateKey_(aslib_key_6, false, aslib_counter_up0); }
inline const bool asKey6_Down() { return updateKey_(aslib_key_6, false, aslib_counter_down); }
inline const bool asKey6_Down0() { return updateKey_(aslib_key_6, false, aslib_counter_down0); }

inline const bool asKey7() { return updateKey_(aslib_key_7, false); }
inline const bool asKey7_Touch() { return updateKey_(aslib_key_7, false, aslib_counter_touch); }
inline const bool asKey7_Touch0() { return updateKey_(aslib_key_7, false, aslib_counter_touch0); }
inline const bool asKey7_Up() { return updateKey_(aslib_key_7, false, aslib_counter_up); }
inline const bool asKey7_Up0() { return updateKey_(aslib_key_7, false, aslib_counter_up0); }
inline const bool asKey7_Down() { return updateKey_(aslib_key_7, false, aslib_counter_down); }
inline const bool asKey7_Down0() { return updateKey_(aslib_key_7, false, aslib_counter_down0); }

inline const bool asKey8() { return updateKey_(aslib_key_8, false); }
inline const bool asKey8_Touch() { return updateKey_(aslib_key_8, false, aslib_counter_touch); }
inline const bool asKey8_Touch0() { return updateKey_(aslib_key_8, false, aslib_counter_touch0); }
inline const bool asKey8_Up() { return updateKey_(aslib_key_8, false, aslib_counter_up); }
inline const bool asKey8_Up0() { return updateKey_(aslib_key_8, false, aslib_counter_up0); }
inline const bool asKey8_Down() { return updateKey_(aslib_key_8, false, aslib_counter_down); }
inline const bool asKey8_Down0() { return updateKey_(aslib_key_8, false, aslib_counter_down0); }

inline const bool asKey9() { return updateKey_(aslib_key_9, false); }
inline const bool asKey9_Touch() { return updateKey_(aslib_key_9, false, aslib_counter_touch); }
inline const bool asKey9_Touch0() { return updateKey_(aslib_key_9, false, aslib_counter_touch0); }
inline const bool asKey9_Up() { return updateKey_(aslib_key_9, false, aslib_counter_up); }
inline const bool asKey9_Up0() { return updateKey_(aslib_key_9, false, aslib_counter_up0); }
inline const bool asKey9_Down() { return updateKey_(aslib_key_9, false, aslib_counter_down); }
inline const bool asKey9_Down0() { return updateKey_(aslib_key_9, false, aslib_counter_down0); }

inline const bool asKeyEnter() { return updateKey_(aslib_key_enter, false); }
inline const bool asKeyEnterTouch() { return updateKey_(aslib_key_enter, false, aslib_counter_touch); }
inline const bool asKeyEnterTouch0() { return updateKey_(aslib_key_enter, false, aslib_counter_touch0); }
inline const bool asKeyEnterUp() { return updateKey_(aslib_key_enter, false, aslib_counter_up); }
inline const bool asKeyEnterUp0() { return updateKey_(aslib_key_enter, false, aslib_counter_up0); }
inline const bool asKeyEnterDown() { return updateKey_(aslib_key_enter, false, aslib_counter_down); }
inline const bool asKeyEnterDown0() { return updateKey_(aslib_key_enter, false, aslib_counter_down0); }

inline const bool asKeyUp() { return updateKey_(aslib_key_up, false); }
inline const bool asKeyUpTouch() { return updateKey_(aslib_key_up, false, aslib_counter_touch); }
inline const bool asKeyUpTouch0() { return updateKey_(aslib_key_up, false, aslib_counter_touch0); }
inline const bool asKeyUpUp() { return updateKey_(aslib_key_up, false, aslib_counter_up); }
inline const bool asKeyUpUp0() { return updateKey_(aslib_key_up, false, aslib_counter_up0); }
inline const bool asKeyUpDown() { return updateKey_(aslib_key_up, false, aslib_counter_down); }
inline const bool asKeyUpDown0() { return updateKey_(aslib_key_up, false, aslib_counter_down0); }

inline const bool asKeyDown() { return updateKey_(aslib_key_down, false); }
inline const bool asKeyDownTouch() { return updateKey_(aslib_key_down, false, aslib_counter_touch); }
inline const bool asKeyDownTouch0() { return updateKey_(aslib_key_down, false, aslib_counter_touch0); }
inline const bool asKeyDownUp() { return updateKey_(aslib_key_down, false, aslib_counter_up); }
inline const bool asKeyDownUp0() { return updateKey_(aslib_key_down, false, aslib_counter_up0); }
inline const bool asKeyDownDown() { return updateKey_(aslib_key_down, false, aslib_counter_down); }
inline const bool asKeyDownDown0() { return updateKey_(aslib_key_down, false, aslib_counter_down0); }

inline const bool asKeyLeft() { return updateKey_(aslib_key_left, false); }
inline const bool asKeyLeftTouch() { return updateKey_(aslib_key_left, false, aslib_counter_touch); }
inline const bool asKeyLeftTouch0() { return updateKey_(aslib_key_left, false, aslib_counter_touch0); }
inline const bool asKeyLeftUp() { return updateKey_(aslib_key_left, false, aslib_counter_up); }
inline const bool asKeyLeftUp0() { return updateKey_(aslib_key_left, false, aslib_counter_up0); }
inline const bool asKeyLeftDown() { return updateKey_(aslib_key_left, false, aslib_counter_down); }
inline const bool asKeyLeftDown0() { return updateKey_(aslib_key_left, false, aslib_counter_down0); }

inline const bool asKeyRight() { return updateKey_(aslib_key_right, false); }
inline const bool asKeyRightTouch() { return updateKey_(aslib_key_right, false, aslib_counter_touch); }
inline const bool asKeyRightTouch0() { return updateKey_(aslib_key_right, false, aslib_counter_touch0); }
inline const bool asKeyRightUp() { return updateKey_(aslib_key_right, false, aslib_counter_up); }
inline const bool asKeyRightUp0() { return updateKey_(aslib_key_right, false, aslib_counter_up0); }
inline const bool asKeyRightDown() { return updateKey_(aslib_key_right, false, aslib_counter_down); }
inline const bool asKeyRightDown0() { return updateKey_(aslib_key_right, false, aslib_counter_down0); }

//inline const bool asKeyA() { return updateKey_(aslib_key_a, false); }
//inline const bool asKeyA_Touch() { return updateKey_(aslib_key_a, false, aslib_counter_touch); }
//inline const bool asKeyA_Touch0() { return updateKey_(aslib_key_a, false, aslib_counter_touch0); }
//inline const bool asKeyA_Up() { return updateKey_(aslib_key_a, false, aslib_counter_up); }
//inline const bool asKeyA_Up0() { return updateKey_(aslib_key_a, false, aslib_counter_up0); }
//inline const bool asKeyA_Down() { return updateKey_(aslib_key_a, false, aslib_counter_down); }
//inline const bool asKeyA_Down0() { return updateKey_(aslib_key_a, false, aslib_counter_down0); }

inline void updateKey() { updateKey_(0, true); }


//switch (player_move_left_up[i])
//{
//case aslib_key_w_a:
//	if (asKeyW_Touch() && asKeyA_Touch()) return MOB_LEFT_UP;
//	break;
//case aslib_key_w_d:
//	if (asKeyW_Touch() && asKeyD_Touch()) return MOB_RIGHT_UP;
//	return MOB_CENTER;
//case aslib_key_s_a:
//	if (asKeyS_Touch() && asKeyA_Touch()) return MOB_LEFT_DOWN;
//	return MOB_CENTER;
//case aslib_key_s_d:
//	if (asKeyS_Touch() && asKeyD_Touch()) return MOB_RIGHT_DOWN;
//	return MOB_CENTER;
//case aslib_key_left_up:
//	if (asKeyLeftTouch() && asKeyUpTouch()) return MOB_LEFT_UP;
//	return MOB_CENTER;
//case aslib_key_right_up:
//	if (asKeyRightTouch() && asKeyUpTouch()) return MOB_RIGHT_UP;
//	return MOB_CENTER;
//case aslib_key_left_down:
//	if (asKeyLeftTouch() && asKeyDownTouch()) return MOB_LEFT_DOWN;
//	return MOB_CENTER;
//case aslib_key_right_down:
//	if (asKeyRightTouch() && asKeyDownTouch()) return MOB_RIGHT_DOWN;
//	return MOB_CENTER;
//}

struct AsKeyList {

	AsKeyList() = default;

	//プレイヤー系
	std::vector<size_t> player_move_down;
	std::vector<size_t> player_move_up;
	std::vector<size_t> player_move_left;
	std::vector<size_t> player_move_right;
	std::vector<size_t> player_move_left_up;
	std::vector<size_t> player_move_right_up;
	std::vector<size_t> player_move_left_down;
	std::vector<size_t> player_move_right_down;

	//通常系
	std::vector<size_t> ok;
	std::vector<size_t> back;
	std::vector<size_t> menu;

	const bool is_ok() const {
		for (size_t i = 0; i < ok.size(); ++i) {
			if (ok[i] < 256 && asKeyUp(ok[i])) return true;
		}
		return false;
	}

	AsKeyList& addKeyOK() {
		ok.emplace_back(aslib_key_enter);
		ok.emplace_back(aslib_key_space);
		ok.emplace_back(aslib_key_z);
		return *this;
	}
	AsKeyList& addKeyBack() {
		back.emplace_back(aslib_key_x);
		return *this;
	}
	AsKeyList& addKeyUpDown() {
		player_move_down.emplace_back(aslib_key_down);
		player_move_up.emplace_back(aslib_key_up);
		return *this;
	}
	AsKeyList& addKeyCross() {
		player_move_down.emplace_back(aslib_key_down);
		player_move_up.emplace_back(aslib_key_up);
		player_move_left.emplace_back(aslib_key_left);
		player_move_right.emplace_back(aslib_key_right);
		player_move_left_up.emplace_back(aslib_key_left_up);
		player_move_right_up.emplace_back(aslib_key_right_up);
		player_move_left_down.emplace_back(aslib_key_left_down);
		player_move_right_down.emplace_back(aslib_key_right_down);
		return *this;
	}
	AsKeyList& addKeyCrossW() {
		player_move_down.emplace_back(aslib_key_s);
		player_move_up.emplace_back(aslib_key_w);
		player_move_left.emplace_back(aslib_key_a);
		player_move_right.emplace_back(aslib_key_d);
		player_move_left_up.emplace_back(aslib_key_w_a);
		player_move_right_up.emplace_back(aslib_key_w_d);
		player_move_left_down.emplace_back(aslib_key_s_a);
		player_move_right_down.emplace_back(aslib_key_s_d);
		return *this;
	}

	const bool isTouch(const size_t is_) const {
		switch (is_)
		{
		case aslib_key_w_a:
			if (asKeyW_Touch() && asKeyA_Touch()) return true;
			return false;
		case aslib_key_w_d:
			if (asKeyW_Touch() && asKeyD_Touch()) return true;
			return false;
		case aslib_key_s_a:
			if (asKeyS_Touch() && asKeyA_Touch()) return true;
			return false;
		case aslib_key_s_d:
			if (asKeyS_Touch() && asKeyD_Touch()) return true;
			return false;
		case aslib_key_left_up:
			if (asKeyLeftTouch() && asKeyUpTouch()) return true;
			return false;
		case aslib_key_right_up:
			if (asKeyRightTouch() && asKeyUpTouch()) return true;
			return false;
		case aslib_key_left_down:
			if (asKeyLeftTouch() && asKeyDownTouch()) return true;
			return false;
		case aslib_key_right_down:
			if (asKeyRightTouch() && asKeyDownTouch()) return true;
			return false;
		}
		return false;
	}

	const size_t playerMove4() const {
		for (size_t i = 0; i < player_move_down.size(); ++i) {
			if (player_move_down[i] > 255) {
				if (isTouch(player_move_down[i])) return MOB_DOWN;
				else continue;
			}
			if (asKeyTouch(player_move_down[i])) return MOB_DOWN;
		}
		for (size_t i = 0; i < player_move_up.size(); ++i) {
			if (player_move_up[i] > 255) {
				if (isTouch(player_move_up[i])) return MOB_UP;
				else continue;
			}
			if (asKeyTouch(player_move_up[i])) return MOB_UP;
		}
		for (size_t i = 0; i < player_move_left.size(); ++i) {
			if (player_move_left[i] > 255) {
				if (isTouch(player_move_left[i])) return MOB_LEFT;
				else continue;
			}
			if (asKeyTouch(player_move_left[i])) return MOB_LEFT;
		}
		for (size_t i = 0; i < player_move_right.size(); ++i) {
			if (player_move_right[i] > 255) {
				if (isTouch(player_move_right[i])) return MOB_RIGHT;
				else continue;
			}
			if (asKeyTouch(player_move_right[i])) return MOB_RIGHT;
		}
		return MOB_CENTER;
	}

	const size_t playerMove8() const {
		for (size_t i = 0; i < player_move_left_up.size(); ++i) {
			if (player_move_left_up[i] > 255) {
				if (isTouch(player_move_left_up[i])) return MOB_LEFT_UP;
				else continue;
			}
			if (asKeyTouch(player_move_left_up[i])) return MOB_LEFT_UP;
		}
		for (size_t i = 0; i < player_move_right_up.size(); ++i) {
			if (player_move_right_up[i] > 255) {
				if (isTouch(player_move_right_up[i])) return MOB_RIGHT_UP;
				else continue;
			}
			if (asKeyTouch(player_move_right_up[i])) return MOB_RIGHT_UP;
		}
		for (size_t i = 0; i < player_move_left_down.size(); ++i) {
			if (player_move_left_down[i] > 255) {
				if (isTouch(player_move_left_down[i])) return MOB_LEFT_DOWN;
				else continue;
			}
			if (asKeyTouch(player_move_left_down[i])) return MOB_LEFT_DOWN;
		}
		for (size_t i = 0; i < player_move_right_down.size(); ++i) {
			if (player_move_right_down[i] > 255) {
				if (isTouch(player_move_right_down[i])) return MOB_RIGHT_DOWN;
				else continue;
			}
			if (asKeyTouch(player_move_right_down[i])) return MOB_RIGHT_DOWN;
		}
		return playerMove4();
	}

};


}

//	bool* checkKey9() {
//		constexpr std::array<size_t, 256> AS_DL_key{
//			aslib_key_unknown,//Ka0 
//			aslib_key_eSCAPE,//KESCAPE0x01//EscキーD_DIK_ESCAPE 
//			aslib_key_1,//K10x02//１キーD_DIK_1 
//			aslib_key_2,//K20x03//２キーD_DIK_2 
//			aslib_key_3,//K30x04//３キーD_DIK_3 
//			aslib_key_4,//K40x05//４キーD_DIK_4 
//			aslib_key_5,//K50x06//５キーD_DIK_5 
//			aslib_key_6,//K60x07//６キーD_DIK_6 
//			aslib_key_7,//K70x08//７キーD_DIK_7 
//			aslib_key_8,//K80x09//８キーD_DIK_8 
//			aslib_key_9,//K90x0A//９キーD_DIK_9 
//			aslib_key_0,//K00x0B//０キーD_DIK_0 
//			0,//KMINUS0x0C//－キーD_DIK_MINUS 
//			aslib_key_unknown,//Ka13 
//			0,//KBACK0x0E//BackSpaceキーD_DIK_BACK 
//			0,//KTAB0x0F//TabキーD_DIK_TAB 
//			aslib_key_q,//KQ0x10//ＱキーD_DIK_Q 
//			aslib_key_w,//KW0x11//ＷキーD_DIK_W 
//			aslib_key_e,//KE0x12//ＥキーD_DIK_E 
//			aslib_key_r,//KR0x13//ＲキーD_DIK_R 
//			aslib_key_t,//KT0x14//ＴキーD_DIK_T 
//			aslib_key_y,//KY0x15//ＹキーD_DIK_Y 
//			aslib_key_u,//KU0x16//ＵキーD_DIK_U 
//			aslib_key_i,//KI0x17//ＩキーD_DIK_I 
//			aslib_key_o,//KO0x18//ＯキーD_DIK_O 
//			aslib_key_p,//KP0x19//ＰキーD_DIK_P 
//			0,//KLBRACKET0x1A//［キーD_DIK_LBRACKET 
//			0,//KRBRACKET0x1B//］キーD_DIK_RBRACKET 
//			0,//KRETURN0x1C//EnterキーD_DIK_RETURN 
//			0,//KLCONTROL0x1D//左CtrlキーD_DIK_LCONTROL 
//			aslib_key_a,//KA0x1E//ＡキーD_DIK_A 
//			aslib_key_s,//KS0x1F//ＳキーD_DIK_S 
//			aslib_key_d,//KD0x20//ＤキーD_DIK_D 
//			aslib_key_f,//KF0x21//ＦキーD_DIK_F 
//			aslib_key_g,//KG0x22//ＧキーD_DIK_G 
//			aslib_key_h,//KH0x23//ＨキーD_DIK_H 
//			aslib_key_j,//KJ0x24//ＪキーD_DIK_J 
//			aslib_key_k,//KK0x25//ＫキーD_DIK_K 
//			aslib_key_l,//KL0x26//ＬキーD_DIK_L 
//			aslib_key_semicolon,//KSEMICOLON0x27//；キーD_DIK_SEMICOLON 
//			aslib_key_unknown,//Ka40 
//			aslib_key_unknown,//Ka41 
//			0,//KLSHIFT0x2A//左ShiftキーD_DIK_LSHIFT 
//			0,//KBACKSLASH0x2B//＼キーD_DIK_BACKSLASH 
//			aslib_key_z,//KZ0x2C//ＺキーD_DIK_Z 
//			aslib_key_x,//KX0x2D//ＸキーD_DIK_X 
//			aslib_key_c,//KC0x2E//ＣキーD_DIK_C 
//			aslib_key_v,//KV0x2F//ＶキーD_DIK_V 
//			aslib_key_b,//KB0x30//ＢキーD_DIK_B 
//			aslib_key_n,//KN0x31//ＮキーD_DIK_N 
//			aslib_key_m,//KM0x32//ＭキーD_DIK_M 
//			0,//KCOMMA0x33//，キーD_DIK_COMMA 
//			0,//KPERIOD0x34//．キーD_DIK_PERIOD 
//			0,//KSLASH0x35//／キーD_DIK_SLASH 
//			0,//KRSHIFT0x36//右ShiftキーD_DIK_RSHIFT 
//			0,//KMULTIPLY0x37//テンキー＊キーD_DIK_MULTIPLY 
//			0,//KLALT0x38//左AltキーD_DIK_LALT 
//			0,//KSPACE0x39//スペースキーD_DIK_SPACE 
//			0,//KCAPSLOCK0x3A//CaspLockキーD_DIK_CAPSLOCK 
//			aslib_key_f1,//KF10x3B//Ｆ１キーD_DIK_F1 
//			aslib_key_f2,//KF20x3C//Ｆ２キーD_DIK_F2 
//			aslib_key_f3,//KF30x3D//Ｆ３キーD_DIK_F3 
//			aslib_key_f4,//KF40x3E//Ｆ４キーD_DIK_F4 
//			aslib_key_f5,//KF50x3F//Ｆ５キーD_DIK_F5 
//			aslib_key_f6,//KF60x40//Ｆ６キーD_DIK_F6 
//			aslib_key_f7,//KF70x41//Ｆ７キーD_DIK_F7 
//			aslib_key_f8,//KF80x42//Ｆ８キーD_DIK_F8 
//			aslib_key_f9,//KF90x43//Ｆ９キーD_DIK_F9 
//			aslib_key_f10,//KF100x44//Ｆ１０キーD_DIK_F10 
//			0,//KNUMLOCK0x45//テンキーNumLockキーD_DIK_NUMLOCK 
//			0,//KSCROLL0x46//ScrollLockキーD_DIK_SCROLL 
//			Keypad_7,//KNUMPAD70x47//テンキー７D_DIK_NUMPAD7 
//			Keypad_8,//KNUMPAD80x48//テンキー８D_DIK_NUMPAD8 
//			Keypad_9,//KNUMPAD90x49//テンキー９D_DIK_NUMPAD9 
//			0,//KSUBTRACT0x4A//テンキー－キーD_DIK_SUBTRACT 
//			Keypad_4,//KNUMPAD40x4B//テンキー４D_DIK_NUMPAD4 
//			Keypad_5,//KNUMPAD50x4C//テンキー５D_DIK_NUMPAD5 
//			Keypad_6,//KNUMPAD60x4D//テンキー６D_DIK_NUMPAD6 
//			aslib_key_unknown,//KaDD0x4E//テンキー＋キーD_DIK_ADD 
//			Keypad_1,//KNUMPAD10x4F//テンキー１D_DIK_NUMPAD1 
//			Keypad_2,//KNUMPAD20x50//テンキー２D_DIK_NUMPAD2 
//			Keypad_3,//KNUMPAD30x51//テンキー３D_DIK_NUMPAD3 
//			Keypad_0,//KNUMPAD00x52//テンキー０D_DIK_NUMPAD0 
//			0,//KDECIMAL0x53//テンキー．キーD_DIK_DECIMAL 
//			aslib_key_unknown,//Ka84 
//			aslib_key_unknown,//Ka85 
//			aslib_key_unknown,//Ka86 
//			aslib_key_f11,//KF110x57//Ｆ１１キーD_DIK_F11 
//			aslib_key_f12,//KF120x58//Ｆ１２キーD_DIK_F12 
//			aslib_key_unknown,//Ka89 
//			aslib_key_unknown,//Ka90 
//			aslib_key_unknown,//Ka91 
//			aslib_key_unknown,//Ka92 
//			aslib_key_unknown,//Ka93 
//			aslib_key_unknown,//Ka94 
//			aslib_key_unknown,//Ka95 
//			aslib_key_unknown,//Ka96 
//			aslib_key_unknown,//Ka97 
//			aslib_key_unknown,//Ka98 
//			aslib_key_unknown,//Ka99 
//			aslib_key_unknown,//Ka100 
//			aslib_key_unknown,//Ka101 
//			aslib_key_unknown,//Ka102 
//			aslib_key_unknown,//Ka103 
//			aslib_key_unknown,//Ka104 
//			aslib_key_unknown,//Ka105 
//			aslib_key_unknown,//Ka106 
//			aslib_key_unknown,//Ka107 
//			aslib_key_unknown,//Ka108 
//			aslib_key_unknown,//Ka109 
//			aslib_key_unknown,//Ka110 
//			aslib_key_unknown,//Ka111 
//			0,//KKANA0x70//カナキーD_DIK_KANA 
//			aslib_key_unknown,//Ka113 
//			aslib_key_unknown,//Ka114 
//			aslib_key_unknown,//Ka115 
//			aslib_key_unknown,//Ka116 
//			aslib_key_unknown,//Ka117 
//			aslib_key_unknown,//Ka118 
//			aslib_key_unknown,//Ka119 
//			aslib_key_unknown,//Ka120 
//			0,//KCONVERT0x79//変換キーD_DIK_CONVERT 
//			aslib_key_unknown,//Ka122 
//			0,//KNOCONVERT0x7B//無変換キーD_DIK_NOCONVERT 
//			aslib_key_unknown,//Ka124 
//			0,//KYEN0x7D//￥キーD_DIK_YEN 
//			aslib_key_unknown,//Ka126 
//			aslib_key_unknown,//Ka127 
//			aslib_key_unknown,//Ka128 
//			aslib_key_unknown,//Ka129 
//			aslib_key_unknown,//Ka130 
//			aslib_key_unknown,//Ka131 
//			aslib_key_unknown,//Ka132 
//			aslib_key_unknown,//Ka133 
//			aslib_key_unknown,//Ka134 
//			aslib_key_unknown,//Ka135 
//			aslib_key_unknown,//Ka136 
//			aslib_key_unknown,//Ka137 
//			aslib_key_unknown,//Ka138 
//			aslib_key_unknown,//Ka139 
//			aslib_key_unknown,//Ka140 
//			aslib_key_unknown,//Ka141 
//			aslib_key_unknown,//Ka142 
//			aslib_key_unknown,//Ka143 
//			0,//KPREVTRACK0x90//＾キーD_DIK_PREVTRACK 
//			aslib_key_unknown,//KaT0x91//＠キーD_DIK_AT 
//			0,//KCOLON0x92//：キーD_DIK_COLON 
//			aslib_key_unknown,//Ka147 
//			aslib_key_grave_accentilde,//KKANJI0x94//漢字キーD_DIK_KANJI 
//			aslib_key_unknown,//Ka149 
//			aslib_key_unknown,//Ka150 
//			aslib_key_unknown,//Ka151 
//			aslib_key_unknown,//Ka152 
//			aslib_key_unknown,//Ka153 
//			aslib_key_unknown,//Ka154 
//			aslib_key_unknown,//Ka155 
//			Keypad_ENTER,//KNUMPADENTER0x9C//テンキーのエンターキーD_DIK_NUMPADENTER 
//			0,//KRCONTROL0x9D//右CtrlキーD_DIK_RCONTROL 
//			aslib_key_unknown,//Ka158 
//			aslib_key_unknown,//Ka159 
//			aslib_key_unknown,//Ka160 
//			aslib_key_unknown,//Ka161 
//			aslib_key_unknown,//Ka162 
//			aslib_key_unknown,//Ka163 
//			aslib_key_unknown,//Ka164 
//			aslib_key_unknown,//Ka165 
//			aslib_key_unknown,//Ka166 
//			aslib_key_unknown,//Ka167 
//			aslib_key_unknown,//Ka168 
//			aslib_key_unknown,//Ka169 
//			aslib_key_unknown,//Ka170 
//			aslib_key_unknown,//Ka171 
//			aslib_key_unknown,//Ka172 
//			aslib_key_unknown,//Ka173 
//			aslib_key_unknown,//Ka174 
//			aslib_key_unknown,//Ka175 
//			aslib_key_unknown,//Ka176 
//			aslib_key_unknown,//Ka177 
//			aslib_key_unknown,//Ka178 
//			aslib_key_unknown,//Ka179 
//			aslib_key_unknown,//Ka180 
//			0,//KDIVIDE0xB5//テンキー／キーD_DIK_DIVIDE 
//			aslib_key_unknown,//Ka182 
//			0,//KSYSRQ0xB7//PrintScreenキーD_DIK_SYSRQ 
//			0,//KRALT0xB8//右AltキーD_DIK_RALT 
//			aslib_key_unknown,//Ka185 
//			aslib_key_unknown,//Ka186 
//			aslib_key_unknown,//Ka187 
//			aslib_key_unknown,//Ka188 
//			aslib_key_unknown,//Ka189 
//			aslib_key_unknown,//Ka190 
//			aslib_key_unknown,//Ka191 
//			aslib_key_unknown,//Ka192 
//			aslib_key_unknown,//Ka193 
//			aslib_key_unknown,//Ka194 
//			aslib_key_unknown,//Ka195 
//			aslib_key_unknown,//Ka196 
//			0,//KPAUSE0xC5//PauseBreakキーD_DIK_PAUSE 
//			aslib_key_unknown,//Ka198 
//			0,//KHOME0xC7//HomeキーD_DIK_HOME 
//				aslib_key_up,//KUP0xC8//上キーD_DIK_UP 
//			0,//KPGUP0xC9//PageUpキーD_DIK_PGUP 
//			aslib_key_unknown,//Ka202 
//				aslib_key_left,//KLEFT0xCB//左キーD_DIK_LEFT 
//			aslib_key_unknown,//Ka204 
//				aslib_key_right,//KRIGHT0xCD//右キーD_DIK_RIGHT 
//			aslib_key_unknown,//Ka206 
//			0,//KEND0xCF//EndキーD_DIK_END 
//				aslib_key_down,//KDOWN0xD0//下キーD_DIK_DOWN 
//			0,//KPGDN0xD1//PageDownキーD_DIK_PGDN 
//			0,//KINSERT0xD2//InsertキーD_DIK_INSERT 
//			0,//KDELETE0xD3//DeleteキーD_DIK_DELETE 
//			aslib_key_unknown,//Ka212 
//			aslib_key_unknown,//Ka213 
//			aslib_key_unknown,//Ka214 
//			aslib_key_unknown,//Ka215 
//			aslib_key_unknown,//Ka216 
//			aslib_key_unknown,//Ka217 
//			aslib_key_unknown,//Ka218 
//			0,//KLWIN0xDB//左WinキーD_DIK_LWIN 
//			0,//KRWIN0xDC//右WinキーD_DIK_RWIN 
//			aslib_key_unknown,//KaPPS0xDD//アプリケーションメニューキーD_DIK_APPS 
//			aslib_key_unknown,//Ka222 
//			aslib_key_unknown,//Ka223 
//			aslib_key_unknown,//Ka224 
//			aslib_key_unknown,//Ka225 
//			aslib_key_unknown,//Ka226 
//			aslib_key_unknown,//Ka227 
//			aslib_key_unknown,//Ka228 
//			aslib_key_unknown,//Ka229 
//			aslib_key_unknown,//Ka230 
//			aslib_key_unknown,//Ka231 
//			aslib_key_unknown,//Ka232 
//			aslib_key_unknown,//Ka233 
//			aslib_key_unknown,//Ka234 
//			aslib_key_unknown,//Ka235 
//			aslib_key_unknown,//Ka236 
//			aslib_key_unknown,//Ka237 
//			aslib_key_unknown,//Ka238 
//			aslib_key_unknown,//Ka239 
//			aslib_key_unknown,//Ka240 
//			aslib_key_unknown,//Ka241 
//			aslib_key_unknown,//Ka242 
//			aslib_key_unknown,//Ka243 
//			aslib_key_unknown,//Ka244 
//			aslib_key_unknown,//Ka245 
//			aslib_key_unknown,//Ka246 
//			aslib_key_unknown,//Ka247 
//			aslib_key_unknown,//Ka248 
//			aslib_key_unknown,//Ka249 
//			aslib_key_unknown,//Ka250 
//			aslib_key_unknown,//Ka251 
//			aslib_key_unknown,//Ka252 
//			aslib_key_unknown,//Ka253 
//			aslib_key_unknown,//Ka254 
//			aslib_key_unknown//Ka255 
//		};
//		bool AS_key[aslib_key_keyLast] = { false };
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