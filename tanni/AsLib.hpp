//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - As���C�u����
//
//                    �����: �������� (wanotaitei@gmail.com)
//
//                                   Ver 0.0.6.0 Alpha
//
//     ----------     ----------     ----------     ----------     ----------

#ifndef ASLIB_ASCLL
#define ASLIB_ASCLL

#pragma once
#include <cstdint>

//AsLib�o�[�W����
constexpr int32_t ASLIB_VERSION = 0x0060;
const char* ASLIB_VERSION_STR = "0.0.6.0 Alpha";

//AsLib�o�[�W���� (UTF)
const char* ASLIB_VERSION_STR8 = u8"0.0.6.0 Alpha";
const char16_t* ASLIB_VERSION_STR16 = u"0.0.6.0 Alpha";
const char32_t* ASLIB_VERSION_STR32 = U"0.0.6.0 Alpha";

//��{�C���N���[�h
#include <string>
#include <iostream>
#include <functional>
#include <array>
#include <vector>

//��{�ϐ��^
#include "AsType.hpp"

//��{�\����
#include "AsStruct.hpp"

//��{�n
#include "AsStd.hpp"

//�l�p�`
#include "AsRect.hpp"

//�e�N�X�`��
#include "asTex.hpp"

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

//���C���Ǘ�
#include "AsMainControl.hpp"

//namespace�g�p
#ifndef AS_NON_USING_NAMESPACE
using namespace AsLib;
#endif

#endif