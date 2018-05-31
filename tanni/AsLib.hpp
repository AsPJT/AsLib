//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - As���C�u����
//
//                    �����: �������� (wanotaitei@gmail.com)
//
//                                   Ver 0.0.10.0 Alpha
//
//     ----------     ----------     ----------     ----------     ----------

#ifndef ASLIB_ASCLL
#define ASLIB_ASCLL

#pragma once
#include <cstdint>

//AsLib�o�[�W����
constexpr int32_t ASLIB_VERSION = 0x00a0;
const char* ASLIB_VERSION_STR = "0.0.10.0 Alpha";

//AsLib�o�[�W���� (UTF)
const char* ASLIB_VERSION_STR8 = u8"0.0.10.0 Alpha";
const char16_t* ASLIB_VERSION_STR16 = u"0.0.10.0 Alpha";
const char32_t* ASLIB_VERSION_STR32 = U"0.0.10.0 Alpha";

//��{�C���N���[�h
#include <string>
#include <iostream>
#include <functional>
#include <array>
#include <vector>

//��{�ϐ��^
#include "AsType.hpp"

//�����n
#include "AsRand.hpp"

//�F�\����
#include "AsColor.hpp"

//��{�\����
#include "AsStruct.hpp"

//
#include "AsConst.hpp"

//
#include "AsCounter.hpp"

//�^�b�`�n
#include "AsTouch.hpp"

//��{�n
#include "AsStd.hpp"

//�l�p�`
#include "AsRect.hpp"

//�e�N�X�`��
#include "AsTex.hpp"

//��v�N���X
#include "AsClass.hpp"

//���C�����[�v
#include "AsLoop.hpp"

//�t�H���g
#include "AsFont.hpp"

//�t�@�C���ǂݏ���
#include "AsFile.hpp"

//�ꎞ��~
#include "AsStop.hpp"

//�L�[�{�[�h����
#include "AsKeyInput.hpp"

//�Q�[���p�b�h
#include "AsGamePad.hpp"

//
#include "AsMap.hpp"

//���C���Ǘ�
#include "AsMainControl.hpp"

//MainControl�֘A----------------------------------------

//�^�C�g�����S�̃V�[���`�F���W�֘A
#include "AsMC_LogoDraw.hpp"

#include "AsMC_Rand.hpp"

//�B��̃��C�u�����I��
#if defined(__DXLIB) //DxLib
#define ASLIB_INCLUDE_C
#elif defined(SIV3D_INCLUDED) //Siv3D
#define ASLIB_INCLUDE_CPP
#else //Console
#define ASLIB_INCLUDE_CUI
#endif

//namespace�g�p
#ifndef AS_NON_USING_NAMESPACE
using namespace AsLib;
#endif

#endif