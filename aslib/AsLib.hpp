//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - AsProject Library
//
//                    Created by Gaccho (wanotaitei@gmail.com)
//
//                                   Ver 0.2.1.0 Alpha
//
//     ----------     ----------     ----------     ----------     ----------

#if !defined(ASLIB_ASCLL)
#define ASLIB_ASCLL

#pragma once
#include <cstdint>

//AsLib�o�[�W����
constexpr int32_t ASLIB_VERSION = 0x0210;
const char* const ASLIB_VERSION_STR = "0.2.1.0 Alpha";

//AsLib�o�[�W���� (UTF)
const char* const ASLIB_VERSION_STR8 = u8"0.2.1.0 Alpha";
const char16_t* const ASLIB_VERSION_STR16 = u"0.2.1.0 Alpha";
const char32_t* const ASLIB_VERSION_STR32 = U"0.2.1.0 Alpha";

enum:size_t{
	aslib_platform_empty,
	aslib_platform_pc,
	aslib_platform_sp,
};

int32_t asMain();
namespace AsLib { const int32_t asEnd(); }
//�����C�u�����C���N���[�h
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
//�v���b�g�t�H�[��
#if !defined(AS_PLATFORM_WINDOWS)
#define AS_PLATFORM_WINDOWS
#endif
constexpr size_t aslib_platform = aslib_platform_pc;
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
//�v���b�g�t�H�[��
#if !defined(AS_PLATFORM_ANDROID)
#define AS_PLATFORM_ANDROID
#endif
constexpr size_t aslib_platform = aslib_platform_sp;
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
	constexpr size_t aslib_platform = aslib_platform_pc;
#include <Windows.h>
#endif
void Main() { asMain(); AsLib::asEnd(); return; }

#elif defined(ASLIB_INCLUDE_NO)
	constexpr size_t aslib_platform = aslib_platform_empty;
int main() { return int(asMain() && AsLib::asEnd()); }
#define ANIME_TEXTURE_3
#elif defined(ASLIB_INCLUDE_OF)
	constexpr size_t aslib_platform = aslib_platform_pc;
#include <ofMain.h>
int main() { return int(asMain()); }
#define ANIME_TEXTURE_1
#elif defined(ASLIB_INCLUDE_C2)
#include "cocos2d.h"
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	constexpr size_t aslib_platform = aslib_platform_pc;
#define ANIME_TEXTURE_4
#ifndef __MAIN_H__
#define __MAIN_H__
	//Exclude rarely-used stuff from Windows headers
#define WIN32_LEAN_AND_MEAN
	//Windows�w�b�_�[�t�@�C��
#include <windows.h>
#include <tchar.h>
	// C RunTime�w�b�_�[�t�@�C��
#include "platform/CCStdC.h"
#endif//__MAIN_H__
	USING_NS_CC;
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow) {
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);
	return int(asMain());
}
#endif
#elif defined(ASLIB_INCLUDE_SF)

#elif defined(ASLIB_INCLUDE_TP)
	constexpr size_t aslib_platform = aslib_platform_empty;
int main() { return int(asMain()); }
#define ANIME_TEXTURE_3
#else
#if !defined(ASLIB_INCLUDE_NO)
#define ASLIB_INCLUDE_NO
#endif
	constexpr size_t aslib_platform = aslib_platform_empty;
int main() { return int(asMain() && AsLib::asEnd()); }
#define ANIME_TEXTURE_3
#endif
//#elif defined\(ASLIB_INCLUDE_T��P\)
//#elif defined(ASLIB_INCLUDE_C2)\nreturn 0;\n#elif defined(ASLIB_INCLUDE_T��P)

//--------------------------------------------------
//��{�C���N���[�h
//--------------------------------------------------
#include <cmath>
#include <ctime>
#include <cstring>
#include <memory>
#include <utility>
#include <functional>
#include <array>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

//--------------------------------------------------
//�ʃC���N���[�h
//--------------------------------------------------

//��{�ϐ��^ (T)
#include "AsType.hpp"

//���C�Z���X (T)
#include "AsLicense.hpp"

//�����n(All) (N)
#include "AsRand.hpp"

//�F�\����(All) (N)
#include "AsColor.hpp"

//��{�\����(All) (N)
#include "AsPos.hpp"

//��{�I�Ȓ萔�錾(All) (N)
#include "AsConst.hpp"

//�`��Ǘ�
#include "AsDraw.hpp"

//Base64
#include "AsBase64.hpp"

//�N���b�v�{�[�h
#include "AsClipboard.hpp"

//�^�b�`�J�E���g(All) (N)
#include "AsCounter.hpp"

//
#include "AsEffect.hpp"

//��{�t�@�C���ǂݏ���(DL/S3/NO/All) (N)
#include "AsFile.hpp"

//��{�n(DL/S3) (T)
#include "AsStd.hpp"

//�X�N���[��
#include "AsScreen.hpp"

//�^�b�`�n(DL/S3?) (T)
#include "AsTouch.hpp"

//�L�[�{�[�h (T)
#include "AsKey.hpp"

//�}�E�X (T)
#include "AsMouse.hpp"

//UTF (N)
#include "AsUTF.hpp"

//���� (T)
#include "AsDistance.hpp"

//�l�p�` (T)
#include "AsRect.hpp"

//��
#include "AsSound.hpp"

//�t�H���g (T)
#include "AsFont.hpp"

//�e�N�X�`��
#include "AsTexture.hpp"

//�{�^��
#include "AsButton.hpp"

//��b�֘A
#include "AsTolk.hpp"

//�C���x���g��
#include "AsInventory.hpp"

//���C�����[�v(DL/S3/NO) (T)
#include "AsLoop.hpp"

//�t�@�C���ǂݏ���(All) (N)
#include "AsAsFile.hpp"

//�ꎞ��~(DL/S3?/NO) (T)
#include "AsStop.hpp"

//�L�[�{�[�h���� (T)
#include "AsKeyInput.hpp"

//�Q�[���p�b�h (T)
#include "AsGamePad.hpp"

//���H�A���S���Y��
#include "AsMaze.hpp"

//�}�b�v�t�@�C��
#include "AsMapFile.hpp"

//��Ԃ�����(All) (N)
#include "AsMap.hpp"

//�~�`�� (T)
#include "AsCircle.hpp"

//�d�� (T)
#include "AsBattery.hpp"

//Wi-Fi (T)
#include "AsWiFi.hpp"

//SNS (T)
#include "AsSNS.hpp"

//���C���Ǘ� (N)
#include "AsMainControl.hpp"

//�������C�u����----------------------------------------

#include "AsDL.hpp"

#include "AsUsing.hpp"

//namespace�g�p
#ifndef AS_NON_USING_NAMESPACE
using namespace AsLib;
#endif

#endif