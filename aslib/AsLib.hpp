//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - Asライブラリ
//
//                    制作者: がっちょ (wanotaitei@gmail.com)
//
//                                   Ver 0.1.4.0 Alpha
//
//     ----------     ----------     ----------     ----------     ----------

#ifndef ASLIB_ASCLL
#define ASLIB_ASCLL

#pragma once
#include <cstdint>

//AsLibバージョン
constexpr int32_t ASLIB_VERSION = 0x0140;
const char* ASLIB_VERSION_STR = "0.1.4.0 Alpha";

//AsLibバージョン (UTF)
const char* ASLIB_VERSION_STR8 = u8"0.1.4.0 Alpha";
const char16_t* ASLIB_VERSION_STR16 = u"0.1.4.0 Alpha";
const char32_t* ASLIB_VERSION_STR32 = U"0.1.4.0 Alpha";

int32_t AsMain();
namespace AsLib { int32_t asEnd(); }
//他ライブラリインクルード
#if defined(ASLIB_INCLUDE_AS)
#include <Windows.h>
int WINAPI WinMain(HINSTANCE hI, HINSTANCE hPI, LPSTR lCL, int nCS) { const int i = int(AsMain()); AsLib::asEnd(); return i; }

#elif defined(ASLIB_INCLUDE_DL)
#define DX_NON_USING_NAMESPACE_DXLIB
#include "DxLib.h"
#if defined(__WINDOWS__)
#include <Windows.h>
int WINAPI WinMain(HINSTANCE hI, HINSTANCE hPI, LPSTR lCL, int nCS) { const int i = int(AsMain()); AsLib::asEnd(); return i; }
#elif defined(__ANDROID__)
int android_main() { const int i = int(AsMain()); AsLib::asEnd(); return i; }
#endif

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

#if defined(__ANDROID__) //Android専用
#if !defined(__STDINT_LIMITS)
#define INT8_MIN         (-127 - 1)
#define INT16_MIN        (-32767 - 1)
#define INT32_MIN        (-2147483647 - 1)
#define INT64_MIN        (-9223372036854775807 - 1)
#define INT8_MAX         127
#define INT16_MAX        32767
#define INT32_MAX        2147483647
#define INT64_MAX        9223372036854775807
#define UINT8_MAX        0xff
#define UINT16_MAX       0xffff
#define UINT32_MAX       0xffffffff
#define UINT64_MAX       0xffffffffffffffff
#endif
#endif

//基本インクルード
#include <string>
#include <iostream>
#include <functional>
#include <array>
#include <vector>
#include <memory>
#include <utility>

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

//主要クラス(All)
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

//円描画
#include "AsCircle.hpp"

//電源
#include "AsBattery.hpp"

//Wi-Fi
#include "AsWiFi.hpp"

//マウス
#include "AsMouse.hpp"

//ライセンス
#include "AsLicense.hpp"

//SNS
#include "AsSNS.hpp"

//メイン管理
#include "AsMainControl.hpp"

//MainControl関連----------------------------------------

//タイトルロゴのシーンチェンジ関連(MC-All)
#include "AsMC_LogoDraw.hpp"

//管理クラス乱数(MC-All)
#include "AsMC_Rand.hpp"

//ポジション
#include "AsMC_Pos.hpp"

//namespace使用
#ifndef AS_NON_USING_NAMESPACE
using namespace AsLib;
#endif

#endif