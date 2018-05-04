//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - As���C�u����
//
//                    �����: �������� (wanotaitei@gmail.com)
//
//                                   Ver 0.0.2.0 Alpha
//
//     ----------     ----------     ----------     ----------     ----------

#ifndef ASLIB_ASCLL
#define ASLIB_ASCLL

#pragma once
#include <cstdint>

//AsLib�o�[�W����
constexpr int32_t ASLIB_VERSION = 0x0020;
const char* ASLIB_VERSION_STR = "0.0.2.0 Alpha";

//AsLib�o�[�W���� (UTF)
const char* ASLIB_VERSION_STR8 = u8"0.0.2.0 Alpha";
const char16_t* ASLIB_VERSION_STR16 = u"0.0.2.0 Alpha";
const char32_t* ASLIB_VERSION_STR32 = U"0.0.2.0 Alpha";

//��{�C���N���[�h
#include <string>


//��{�ϐ��^
#include "AsType.hpp"

//��{�\����
#include "AsStruct.hpp"

//��{�n
#include "AsStd.hpp"

//��v�N���X
#include "AsClass.hpp"

//���C�����[�v
#include "AsLoop.hpp"

//�l�p�`
#include "AsRect.hpp"

//�t�H���g
#include "AsFont.hpp"

//�t�@�C���ǂݏ���
#include "AsFile.hpp"

//namespace�g�p
#ifndef AS_NON_USING_NAMESPACE
using namespace AsLib;
#endif

#endif