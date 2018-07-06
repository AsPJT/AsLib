//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - Asライブラリ
//
//                    制作者: がっちょ (wanotaitei@gmail.com)
//
//                                   Ver 0.2.0.0 Alpha
//
//     ----------     ----------     ----------     ----------     ----------

#if !defined(ASLIB_ASCLL)
#define ASLIB_ASCLL

#pragma once
#include <cstdint>

//AsLibバージョン
constexpr int32_t ASLIB_VERSION = 0x0200;
const char* const ASLIB_VERSION_STR = "0.2.0.0 Alpha";

//AsLibバージョン (UTF)
const char* const ASLIB_VERSION_STR8 = u8"0.2.0.0 Alpha";
const char16_t* const ASLIB_VERSION_STR16 = u"0.2.0.0 Alpha";
const char32_t* const ASLIB_VERSION_STR32 = U"0.2.0.0 Alpha";

int32_t asMain();
namespace AsLib { const int32_t asEnd(); }
//他ライブラリインクルード
#if defined(__DXLIB)
#if !defined(ASLIB_INCLUDE_DL)
#defined ASLIB_INCLUDE_DL
#endif
#elif defined(SIV3D_INCLUDED)
#if !defined(ASLIB_INCLUDE_S3)
#defined ASLIB_INCLUDE_S3
#endif
#endif
#if defined(ASLIB_INCLUDE_AS)
#include <Windows.h>
int WINAPI WinMain(HINSTANCE hI, HINSTANCE hPI, LPSTR lCL, int nCS) { const int i = int(asMain()); AsLib::asEnd(); return i; }

#elif defined(ASLIB_INCLUDE_DL)
#if !defined(DX_NON_USING_NAMESPACE_DXLIB)
#define DX_NON_USING_NAMESPACE_DXLIB
#endif
#if !defined(__DXLIB)
#include <DxLib.h>
#endif
#if !defined(ANIME_TEXTURE_2)
#define ANIME_TEXTURE_2
#endif
#if defined(__WINDOWS__)
#include <Windows.h>
int WINAPI WinMain(HINSTANCE hI, HINSTANCE hPI, LPSTR lCL, int nCS) { const int i = int(asMain()); AsLib::asEnd(); return i; }
//プラットフォーム
#if !defined(AS_PLATFORM_WINDOWS)
#define AS_PLATFORM_WINDOWS
#endif
#if !defined(AS_PLATFORM_PC)
#define AS_PLATFORM_PC
#endif
#elif defined(__ANDROID__)
const float abs(const float f_) { return (f_ < 0.0f) ? -f_ : f_; }
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
int android_main() { const int i = int(asMain()); AsLib::asEnd(); return i; }
//プラットフォーム
#if !defined(AS_PLATFORM_ANDROID)
#define AS_PLATFORM_ANDROID
#endif
#if !defined(AS_PLATFORM_SP)
#define AS_PLATFORM_SP
#endif
#endif

#elif defined(ASLIB_INCLUDE_S3)
#if !defined(NO_S3D_USING)
#define NO_S3D_USING
#endif
#if !defined(SIV3D_INCLUDED)
#include <Siv3D.hpp>
#endif
#if !defined(ANIME_TEXTURE_1)
#define ANIME_TEXTURE_1
#endif
#if defined(SIV3D_TARGET_WINDOWS)
#include <Windows.h>
#endif
void Main() { asMain(); AsLib::asEnd(); return; }

#elif defined(ASLIB_INCLUDE_NO)
int main() { return int(asMain() && AsLib::asEnd()); }
#define ANIME_TEXTURE_3
#elif defined(ASLIB_INCLUDE_TP)
int main() { return int(asMain()); }
#define ANIME_TEXTURE_3
#else
#if !defined(ASLIB_INCLUDE_NO)
#define ASLIB_INCLUDE_NO
#endif
int main() { return int(asMain() && AsLib::asEnd()); }
#define ANIME_TEXTURE_3
#endif

//基本インクルード
#include <string>
#include <iostream>
#include <functional>
#include <array>
#include <vector>
#include <memory>
#include <utility>
#include <cmath>
#include <ctime>

//基本変数型 (T)
#include "AsType.hpp"

//乱数系(All) (N)
#include "AsRand.hpp"

//色構造体(All) (N)
#include "AsColor.hpp"

//基本構造体(All) (N)
#include "AsPos.hpp"

//基本的な定数宣言(All) (N)
#include "AsConst.hpp"

//タッチカウント(All) (N)
#include "AsCounter.hpp"

//タッチ系(DL/S3?) (T)
#include "AsTouch.hpp"

//基本ファイル読み書き(DL/S3/NO/All) (N)
#include "AsFile.hpp"

//基本系(DL/S3) (T)
#include "AsStd.hpp"

//マウス (T)
#include "AsMouse.hpp"

//UTF (N)
#include "AsUTF.hpp"

//距離 (T)
#include "AsDistance.hpp"

//四角形 (T)
#include "AsRect.hpp"

//テクスチャ
#include "AsTexure.hpp"

//主要クラス(All) (N)
#include "AsClass.hpp"

//メインループ(DL/S3/NO) (T)
#include "AsLoop.hpp"

//フォント (T)
#include "AsFont.hpp"

//ファイル読み書き(All) (N)
#include "AsAsFile.hpp"

//一時停止(DL/S3?/NO) (T)
#include "AsStop.hpp"

//キーボード入力 (T)
#include "AsKeyInput.hpp"

//キーボード (T)
#include "AsKey.hpp"

//ゲームパッド (T)
#include "AsGamePad.hpp"

//空間を扱う(All) (N)
#include "AsMap.hpp"

//円描画 (T)
#include "AsCircle.hpp"

//電源 (T)
#include "AsBattery.hpp"

//Wi-Fi (T)
#include "AsWiFi.hpp"

//ライセンス (T)
#include "AsLicense.hpp"

//SNS (T)
#include "AsSNS.hpp"

//ログ(DL/S3/NO/All) (T)
#include "AsLog.hpp"

//メイン管理 (N)
#include "AsMainControl.hpp"

//MainControl関連----------------------------------------

//タイトルロゴのシーンチェンジ関連(MC-All) (N)
#include "AsMC_LogoDraw.hpp"

//管理クラス乱数(MC-All) (N)
#include "AsMC_Rand.hpp"

//ポジション(MC-All) (N)
#include "AsMC_Pos.hpp"


//共存ライブラリ----------------------------------------

#include "AsDL.hpp"

//namespace使用
#ifndef AS_NON_USING_NAMESPACE
using namespace AsLib;
#endif

#endif