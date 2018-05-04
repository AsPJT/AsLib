//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - Asライブラリ
//
//                    制作者: がっちょ (wanotaitei@gmail.com)
//
//                                   Ver 0.0.2.0 Alpha
//
//     ----------     ----------     ----------     ----------     ----------

#ifndef ASLIB_ASCLL
#define ASLIB_ASCLL

#pragma once
#include <cstdint>

//AsLibバージョン
constexpr int32_t ASLIB_VERSION = 0x0020;
const char* ASLIB_VERSION_STR = "0.0.2.0 Alpha";

//AsLibバージョン (UTF)
const char* ASLIB_VERSION_STR8 = u8"0.0.2.0 Alpha";
const char16_t* ASLIB_VERSION_STR16 = u"0.0.2.0 Alpha";
const char32_t* ASLIB_VERSION_STR32 = U"0.0.2.0 Alpha";

//基本インクルード
#include <string>


//基本変数型
#include "AsType.hpp"

//基本構造体
#include "AsStruct.hpp"

//基本系
#include "AsStd.hpp"

//主要クラス
#include "AsClass.hpp"

//メインループ
#include "AsLoop.hpp"

//四角形
#include "AsRect.hpp"

//フォント
#include "AsFont.hpp"

//ファイル読み書き
#include "AsFile.hpp"

//namespace使用
#ifndef AS_NON_USING_NAMESPACE
using namespace AsLib;
#endif

#endif