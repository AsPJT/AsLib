//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - As���C�u����
//
//                    �����: �������� (wanotaitei@gmail.com)
//
//                                   Ver 0.0.11.0 Alpha
//
//     ----------     ----------     ----------     ----------     ----------

#ifndef ASLIB_ASCLL
#define ASLIB_ASCLL

#pragma once
#include <cstdint>

//AsLib�o�[�W����
constexpr int32_t ASLIB_VERSION = 0x00b0;
const char* ASLIB_VERSION_STR = "0.0.11.0 Alpha";

//AsLib�o�[�W���� (UTF)
const char* ASLIB_VERSION_STR8 = u8"0.0.11.0 Alpha";
const char16_t* ASLIB_VERSION_STR16 = u"0.0.11.0 Alpha";
const char32_t* ASLIB_VERSION_STR32 = U"0.0.11.0 Alpha";

int32_t AsMain();
namespace AsLib { int32_t asEnd(); }
//�����C�u�����C���N���[�h
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

//��{�C���N���[�h
#include <string>
#include <iostream>
#include <functional>
#include <array>
#include <vector>

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

//��v�N���X
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

//���C���Ǘ�
#include "AsMainControl.hpp"

//MainControl�֘A----------------------------------------

//�^�C�g�����S�̃V�[���`�F���W�֘A(MC-All)
#include "AsMC_LogoDraw.hpp"

//�Ǘ��N���X����(MC-All)
#include "AsMC_Rand.hpp"

//namespace�g�p
#ifndef AS_NON_USING_NAMESPACE
using namespace AsLib;
#endif

#endif