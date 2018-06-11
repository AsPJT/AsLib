//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - As���C�u����
//
//                    �����: �������� (wanotaitei@gmail.com)
//
//                                   Ver 0.1.7.0 Alpha
//
//     ----------     ----------     ----------     ----------     ----------

#if !defined(ASLIB_ASCLL)
#define ASLIB_ASCLL

#pragma once
#include <cstdint>

//AsLib�o�[�W����
constexpr int32_t ASLIB_VERSION = 0x0170;
const char* ASLIB_VERSION_STR = "0.1.7.0 Alpha";

//AsLib�o�[�W���� (UTF)
const char* ASLIB_VERSION_STR8 = u8"0.1.7.0 Alpha";
const char16_t* ASLIB_VERSION_STR16 = u"0.1.7.0 Alpha";
const char32_t* ASLIB_VERSION_STR32 = U"0.1.7.0 Alpha";

int32_t AsMain();
namespace AsLib { int32_t asEnd(); }
//�����C�u�����C���N���[�h
#if defined(ASLIB_INCLUDE_AS)
#include <Windows.h>
int WINAPI WinMain(HINSTANCE hI, HINSTANCE hPI, LPSTR lCL, int nCS) { const int i = int(AsMain()); AsLib::asEnd(); return i; }

#elif defined(ASLIB_INCLUDE_DL)
#if !defined(DX_NON_USING_NAMESPACE_DXLIB)
#define DX_NON_USING_NAMESPACE_DXLIB
#endif
#include "DxLib.h"
#if !defined(ANIME_TEXTURE_2)
#define ANIME_TEXTURE_2
#endif
#if defined(__WINDOWS__)
#include <Windows.h>
int WINAPI WinMain(HINSTANCE hI, HINSTANCE hPI, LPSTR lCL, int nCS) { const int i = int(AsMain()); AsLib::asEnd(); return i; }
#elif defined(__ANDROID__)
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
int android_main() { const int i = int(AsMain()); AsLib::asEnd(); return i; }
#endif

#elif defined(ASLIB_INCLUDE_S3)
#if !defined(NO_S3D_USING)
#define NO_S3D_USING
#endif
#include "Siv3D.hpp"
#if !defined(ANIME_TEXTURE_1)
#define ANIME_TEXTURE_1
#endif
#if defined(SIV3D_TARGET_WINDOWS)
#include <Windows.h>
#endif
void Main() { AsMain(); AsLib::asEnd(); return; }

#elif defined(ASLIB_INCLUDE_NO)
int main() { return int(AsMain() && AsLib::asEnd()); }
#else
#if !defined(ASLIB_INCLUDE_NO)
#define ASLIB_INCLUDE_NO
#endif
int main() { return int(AsMain() && AsLib::asEnd()); }
#endif

//��{�C���N���[�h
#include <string>
#include <iostream>
#include <functional>
#include <array>
#include <vector>
#include <memory>
#include <utility>
#include <cmath>
#include <ctime>

//��{�ϐ��^
#include "AsType.hpp"

//�����n(All)
#include "AsRand.hpp"

//�F�\����(All)
#include "AsColor.hpp"

//��{�\����(All)
#include "AsStruct.hpp"

//��{�I�Ȓ萔�錾(All)
#include "AsConst.hpp"

//�^�b�`�J�E���g(All)
#include "AsCounter.hpp"

//�^�b�`�n(DL/S3?)
#include "AsTouch.hpp"

//��{�t�@�C���ǂݏ���(DL/S3/NO/All)
#include "AsFile.hpp"

//��{�n(DL/S3)
#include "AsStd.hpp"

//�l�p�`
#include "AsRect.hpp"

//�e�N�X�`��
#include "AsTex.hpp"

//��v�N���X(All)
#include "AsClass.hpp"

//���C�����[�v(DL/S3/NO)
#include "AsLoop.hpp"

//�t�H���g
#include "AsFont.hpp"

//�t�@�C���ǂݏ���(All)
#include "AsAsFile.hpp"

//�ꎞ��~(DL/S3?/NO)
#include "AsStop.hpp"

//�L�[�{�[�h����
#include "AsKeyInput.hpp"

//�Q�[���p�b�h
#include "AsGamePad.hpp"

//��Ԃ�����(All)
#include "AsMap.hpp"

//�~�`��
#include "AsCircle.hpp"

//�d��
#include "AsBattery.hpp"

//Wi-Fi
#include "AsWiFi.hpp"

//�}�E�X
#include "AsMouse.hpp"

//���C�Z���X
#include "AsLicense.hpp"

//SNS
#include "AsSNS.hpp"

//���C���Ǘ�
#include "AsMainControl.hpp"

//MainControl�֘A----------------------------------------

//�^�C�g�����S�̃V�[���`�F���W�֘A(MC-All)
#include "AsMC_LogoDraw.hpp"

//�Ǘ��N���X����(MC-All)
#include "AsMC_Rand.hpp"

//�|�W�V����
#include "AsMC_Pos.hpp"

//namespace�g�p
#ifndef AS_NON_USING_NAMESPACE
using namespace AsLib;
#endif

#endif