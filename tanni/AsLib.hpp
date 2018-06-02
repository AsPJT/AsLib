//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - Asライブラリ
//
//                    制作者: がっちょ (wanotaitei@gmail.com)
//
//                                   Ver 0.0.11.0 Alpha
//
//     ----------     ----------     ----------     ----------     ----------

#ifndef ASLIB_ASCLL
#define ASLIB_ASCLL

#pragma once
#include <cstdint>

//AsLibバージョン
constexpr int32_t ASLIB_VERSION = 0x00b0;
const char* ASLIB_VERSION_STR = "0.0.11.0 Alpha";

//AsLibバージョン (UTF)
const char* ASLIB_VERSION_STR8 = u8"0.0.11.0 Alpha";
const char16_t* ASLIB_VERSION_STR16 = u"0.0.11.0 Alpha";
const char32_t* ASLIB_VERSION_STR32 = U"0.0.11.0 Alpha";

int32_t AsMain();
namespace AsLib { int32_t asEnd(); }
//他ライブラリインクルード
#if defined(ASLIB_INCLUDE_DL)
#define DX_NON_USING_NAMESPACE_DXLIB
#include "DxLib.h"
int WINAPI WinMain(HINSTANCE hI, HINSTANCE hPI, LPSTR lCL, int nCS) { return int(AsMain() && AsLib::asEnd()); }
#elif defined(ASLIB_INCLUDE_S3)
#define NO_S3D_USING
#include "Siv3D.hpp"
void Main() { AsMain(); AsLib::asEnd(); return; }
#elif defined(ASLIB_INCLUDE_NO)
int main() { return int(AsMain() && AsLib::asEnd()); }
#else
#define ASLIB_INCLUDE_NO
int main() { return int(AsMain() && AsLib::asEnd()); }
#endif

//基本インクルード
#include <string>
#include <iostream>
#include <functional>
#include <array>
#include <vector>

//基本変数型
#include "AsType.hpp"

//乱数系(All)
#include "AsRand.hpp"

//色構造体(All)
#include "AsColor.hpp"

//基本構造体(All)
#include "AsStruct.hpp"

//基本的な定数宣言(All)
#include "AsConst.hpp"

//タッチカウント(All)
#include "AsCounter.hpp"

//タッチ系(DL/S3?)
#include "AsTouch.hpp"

//基本ファイル読み書き(DL/S3/NO/All)
#include "AsFile.hpp"

//基本系(DL/S3)
#include "AsStd.hpp"

//四角形
#include "AsRect.hpp"

//テクスチャ
#include "AsTex.hpp"

//主要クラス
#include "AsClass.hpp"

//メインループ(DL/S3/NO)
#include "AsLoop.hpp"

//フォント
#include "AsFont.hpp"

//ファイル読み書き(All)
#include "AsAsFile.hpp"

//一時停止(DL/S3?/NO)
#include "AsStop.hpp"

//キーボード入力
#include "AsKeyInput.hpp"

//ゲームパッド
#include "AsGamePad.hpp"

//空間を扱う(All)
#include "AsMap.hpp"

//メイン管理
#include "AsMainControl.hpp"

//MainControl関連----------------------------------------

//タイトルロゴのシーンチェンジ関連(MC-All)
#include "AsMC_LogoDraw.hpp"

//管理クラス乱数(MC-All)
#include "AsMC_Rand.hpp"

//namespace使用
#ifndef AS_NON_USING_NAMESPACE
using namespace AsLib;
#endif

#endif