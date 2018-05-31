//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - Asライブラリ
//
//                    制作者: がっちょ (wanotaitei@gmail.com)
//
//                                   Ver 0.0.10.0 Alpha
//
//     ----------     ----------     ----------     ----------     ----------

#ifndef ASLIB_ASCLL
#define ASLIB_ASCLL

#pragma once
#include <cstdint>

//AsLibバージョン
constexpr int32_t ASLIB_VERSION = 0x00a0;
const char* ASLIB_VERSION_STR = "0.0.10.0 Alpha";

//AsLibバージョン (UTF)
const char* ASLIB_VERSION_STR8 = u8"0.0.10.0 Alpha";
const char16_t* ASLIB_VERSION_STR16 = u"0.0.10.0 Alpha";
const char32_t* ASLIB_VERSION_STR32 = U"0.0.10.0 Alpha";

//基本インクルード
#include <string>
#include <iostream>
#include <functional>
#include <array>
#include <vector>

//基本変数型
#include "AsType.hpp"

//乱数系
#include "AsRand.hpp"

//色構造体
#include "AsColor.hpp"

//基本構造体
#include "AsStruct.hpp"

//
#include "AsConst.hpp"

//
#include "AsCounter.hpp"

//タッチ系
#include "AsTouch.hpp"

//基本系
#include "AsStd.hpp"

//四角形
#include "AsRect.hpp"

//テクスチャ
#include "AsTex.hpp"

//主要クラス
#include "AsClass.hpp"

//メインループ
#include "AsLoop.hpp"

//フォント
#include "AsFont.hpp"

//ファイル読み書き
#include "AsFile.hpp"

//一時停止
#include "AsStop.hpp"

//キーボード入力
#include "AsKeyInput.hpp"

//ゲームパッド
#include "AsGamePad.hpp"

//
#include "AsMap.hpp"

//メイン管理
#include "AsMainControl.hpp"

//MainControl関連----------------------------------------

//タイトルロゴのシーンチェンジ関連
#include "AsMC_LogoDraw.hpp"

#include "AsMC_Rand.hpp"

//唯一のライブラリ選定
#if defined(__DXLIB) //DxLib
#define ASLIB_INCLUDE_C
#elif defined(SIV3D_INCLUDED) //Siv3D
#define ASLIB_INCLUDE_CPP
#else //Console
#define ASLIB_INCLUDE_CUI
#endif

//namespace使用
#ifndef AS_NON_USING_NAMESPACE
using namespace AsLib;
#endif

#endif