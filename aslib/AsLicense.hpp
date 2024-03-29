﻿/*#######################################################################################
	Made by Kasugaccho
	Made by As Project
	https://github.com/Kasugaccho/AsLib
	wanotaitei@gmail.com

	This code is licensed under CC0.
#######################################################################################*/
#ifndef INCLUDED_AS_PROJECT_LIBRARY_LICENSE
#define INCLUDED_AS_PROJECT_LIBRARY_LICENSE


namespace AsLib
{
	//ライセンス一覧
	enum :std::size_t {
		AsLib_LICENSE,
		Abseil_LICENSE,
		AngelCode_Scripting_Library_LICENSE,
		Base64_LICENSE,
		Box2D_LICENSE,
		Bullet_LICENSE,
		cereal_LICENSE,
		clip2tri_LICENSE,
		Clipper_LICENSE,
		Convenient_Constructs_For_Stepping_Through_a_Range_of_Values_LICENSE,
		cpptoml_LICENSE,
		DirectXMath_LICENSE,
		double_conversion_LICENSE,
		DX_Library_LICENSE,
		Easing_Equations_LICENSE,
		easyexif_LICENSE,
		FID_LICENSE,
		fmt_LICENSE,
		Font_Awesome_LICENSE,
		FreeType_LICENSE,
		frontal_cat_face_detector_LICENSE,
		giflib_LICENSE,
		HamFramework_LICENSE,
		HarfBuzz_LICENSE,
		hopscotch_map_LICENSE,
		JUMAN_LICENSE,
		kld_intersections_LICENSE,
		kld_polynomial_LICENSE,
		lbpcascade_animeface_LICENSE,
		libjpeg_LICENSE,
		libjpeg_turbo_LICENSE,
		libogg_LICENSE,
		libpng_LICENSE,
		libsvm_LICENSE,
		libtiff_LICENSE,
		LineSegmentIntersection_LICENSE,
		Mersenne_Twister_LICENSE,
		miniutf_LICENSE,
		msinttypes_r29_LICENSE,
		muparser_LICENSE,
		nanoflann_LICENSE,
		Noto_Fonts_LICENSE,
		OpenCV_LICENSE,
		openFrameworks_LICENSE,
		Opus_audio_codec_LICENSE,
		Opusfile_LICENSE,
		pffft_LICENSE,
		Poly2Tri_LICENSE,
		QRCode_LICENSE,
		quirc_LICENSE,
		RapidJSON_LICENSE,
		Recast_Detour_LICENSE,
		SFMT_LICENSE,
		Simple_DirectMedia_Layer_LICENSE,
		Siv3D_Engine_LICENSE,
		TinySoundFont_LICENSE,
		TinyXML_2_LICENSE,
		utflib_LICENSE,
		xxHash_LICENSE,
		zlib_LICENSE,
		Zstandard_LICENSE,
	};

	//使用中のライセンス
	constexpr std::size_t aslib_license[] = {
		AsLib_LICENSE,
#if defined(ASLIB_INCLUDE_S3) //Siv3D
		Abseil_LICENSE,
#endif
#if defined(ASLIB_INCLUDE_S3) //Siv3D
		AngelCode_Scripting_Library_LICENSE,
#endif
		Base64_LICENSE,
#if defined(ASLIB_INCLUDE_S3) //Siv3D
		Box2D_LICENSE,
#endif
#if defined(ASLIB_INCLUDE_DL) //DxLib
		Bullet_LICENSE,
#endif
#if defined(ASLIB_INCLUDE_S3) //Siv3D
		cereal_LICENSE,
#endif
#if defined(ASLIB_INCLUDE_S3) //Siv3D
		clip2tri_LICENSE,
#endif
#if defined(ASLIB_INCLUDE_S3) //Siv3D
		Clipper_LICENSE,
#endif
#if defined(ASLIB_INCLUDE_S3) //Siv3D
		Convenient_Constructs_For_Stepping_Through_a_Range_of_Values_LICENSE,
#endif
#if defined(ASLIB_INCLUDE_S3) //Siv3D
		cpptoml_LICENSE,
#endif
#if defined(ASLIB_INCLUDE_S3) //Siv3D
		DirectXMath_LICENSE,
#endif
#if defined(ASLIB_INCLUDE_DL) //DxLib
		DX_Library_LICENSE,
#endif
#if defined(ASLIB_INCLUDE_S3) //Siv3D
		double_conversion_LICENSE,
#endif
#if defined(ASLIB_INCLUDE_S3) //Siv3D
		Easing_Equations_LICENSE,
#endif
#if defined(ASLIB_INCLUDE_S3) //Siv3D
		easyexif_LICENSE,
#endif
#if defined(ASLIB_INCLUDE_S3) //Siv3D
		FID_LICENSE,
#endif
#if defined(ASLIB_INCLUDE_S3) //Siv3D
		fmt_LICENSE,
#endif
#if defined(ASLIB_INCLUDE_S3) //Siv3D
		Font_Awesome_LICENSE,
#endif
#if defined(ASLIB_INCLUDE_S3) //Siv3D
		FreeType_LICENSE,
#endif
#if defined(ASLIB_INCLUDE_S3) //Siv3D
		frontal_cat_face_detector_LICENSE,
#endif
#if defined(ASLIB_INCLUDE_S3) //Siv3D
		giflib_LICENSE,
#endif
#if defined(ASLIB_INCLUDE_S3) //Siv3D
		HamFramework_LICENSE,
#endif
#if defined(ASLIB_INCLUDE_S3) //Siv3D
		HarfBuzz_LICENSE,
#endif
#if defined(ASLIB_INCLUDE_S3) //Siv3D
		hopscotch_map_LICENSE,
#endif
#if defined(ASLIB_INCLUDE_S3) //Siv3D
		JUMAN_LICENSE,
#endif
#if defined(ASLIB_INCLUDE_S3) //Siv3D
		kld_intersections_LICENSE,
#endif
#if defined(ASLIB_INCLUDE_S3) //Siv3D
		kld_polynomial_LICENSE,
#endif
#if defined(ASLIB_INCLUDE_S3) //Siv3D
		lbpcascade_animeface_LICENSE,
#endif
#if defined(ASLIB_INCLUDE_S3) || defined(ASLIB_INCLUDE_DL)
		libjpeg_LICENSE,
#endif
#if defined(ASLIB_INCLUDE_S3) //Siv3D
		libjpeg_turbo_LICENSE,
#endif
#if defined(ASLIB_INCLUDE_DL) //DxLib
		libogg_LICENSE,
#endif
#if defined(ASLIB_INCLUDE_S3) || defined(ASLIB_INCLUDE_DL)
		libpng_LICENSE,
#endif
#if defined(ASLIB_INCLUDE_S3) //Siv3D
			libsvm_LICENSE,
#endif
#if defined(ASLIB_INCLUDE_DL) //DxLib
		libtiff_LICENSE,
#endif
#if defined(ASLIB_INCLUDE_S3) //Siv3D
		LineSegmentIntersection_LICENSE,
#endif
#if defined(ASLIB_INCLUDE_DL) //DxLib
		Mersenne_Twister_LICENSE,
#endif
#if defined(ASLIB_INCLUDE_S3) //Siv3D
		miniutf_LICENSE,
#endif
#if defined(ASLIB_INCLUDE_S3) //Siv3D
		msinttypes_r29_LICENSE,
#endif
#if defined(ASLIB_INCLUDE_S3) //Siv3D
		muparser_LICENSE,
#endif
#if defined(ASLIB_INCLUDE_S3) //Siv3D
		nanoflann_LICENSE,
#endif
#if defined(ASLIB_INCLUDE_S3) //Siv3D
		Noto_Fonts_LICENSE,
#endif
#if defined(ASLIB_INCLUDE_DL) //DxLib
		Opus_audio_codec_LICENSE,
#endif
#if defined(ASLIB_INCLUDE_DL) //DxLib
		Opusfile_LICENSE,
#endif
#if defined(ASLIB_INCLUDE_S3) //Siv3D
		OpenCV_LICENSE,
#endif
#if defined(ASLIB_INCLUDE_OF) //Siv3D
			openFrameworks_LICENSE,
#endif
#if defined(ASLIB_INCLUDE_S3) //Siv3D
		pffft_LICENSE,
#endif
#if defined(ASLIB_INCLUDE_S3) //Siv3D
		Poly2Tri_LICENSE,
#endif
#if defined(ASLIB_INCLUDE_S3) //Siv3D
		QRCode_LICENSE,
#endif
#if defined(ASLIB_INCLUDE_S3) //Siv3D
		quirc_LICENSE,
#endif
#if defined(ASLIB_INCLUDE_S3) //Siv3D
		RapidJSON_LICENSE,
#endif
#if defined(ASLIB_INCLUDE_S3) //Siv3D
		Recast_Detour_LICENSE,
#endif
#if defined(ASLIB_INCLUDE_S3) //Siv3D
		SFMT_LICENSE,
#endif
#if defined(ASLIB_INCLUDE_S3) //Siv3D
		Simple_DirectMedia_Layer_LICENSE,
#endif
#if defined(ASLIB_INCLUDE_S3) //Siv3D
		Siv3D_Engine_LICENSE,
#endif
#if defined(ASLIB_INCLUDE_S3) //Siv3D
		TinySoundFont_LICENSE,
#endif
#if defined(ASLIB_INCLUDE_S3) //Siv3D
		TinyXML_2_LICENSE,
#endif
			utflib_LICENSE,
#if defined(ASLIB_INCLUDE_S3) //Siv3D
		xxHash_LICENSE,
#endif
#if defined(ASLIB_INCLUDE_S3) || defined(ASLIB_INCLUDE_DL)
		zlib_LICENSE,
#endif
#if defined(ASLIB_INCLUDE_S3) //Siv3D
		Zstandard_LICENSE,
#endif
	};

	constexpr std::size_t aslib_license_size{ sizeof(aslib_license) / sizeof(std::size_t) };

	struct Copyright {
		const char* const c;
		const std::int32_t start_year;
		const std::int32_t end_year;
		constexpr Copyright(const char* const c_, const std::int32_t s_, const std::int32_t e_) :c(c_), start_year(s_), end_year(e_) {};

		const char* const write() const noexcept {
			if (start_year == 0) return c;

			static std::string str;
			str = "Copyright (c) ";

#if defined(__ANDROID__)
			std::stringstream ss;
			ss << start_year;
			str += ss.str();
#else
			str += std::to_string(start_year);
#endif
			if (end_year != 0) {
				str += "-";
#if defined(__ANDROID__)
				std::stringstream ss2;
				ss2 << end_year;
				str += ss2.str();
#else
				str += std::to_string(end_year);
#endif
			}
			str += " ";
			str += c;
			return str.c_str();
		}
	};

	void asLicense(const std::size_t i, std::string& name_, std::vector<Copyright>& copyright_, std::string& str_) noexcept
	{
		switch (i)
		{
		case(AsLib_LICENSE):
			name_ = "AsLib";
			str_ = "This software is licensed under CC0.";
			return;
		case(Base64_LICENSE):
			name_ = "Base64Lib";
			str_ = "This software is licensed under CC0.";
			return;
		case(libjpeg_LICENSE):
			name_ = "libjpeg";
			str_ = "This software is based in part on the work of the Independent JPEG Group.";
			return;
		case(libpng_LICENSE):
			name_ = "libpng";
			copyright_.emplace_back(Copyright("Glenn Randers-Pehrson", 1998, 2017));
			str_ = "The PNG Reference Library is supplied \"AS IS\". The Contributing Authors<br>and Group 42, Inc. disclaim all warranties, expressed or implied,<br>including, without limitation, the warranties of merchantability and of<br>fitness for any purpose. The Contributing Authors and Group 42, Inc.<br>assume no liability for direct, indirect, incidental, special, exemplary,<br>or consequential damages, which may result from the use of the PNG<br>Reference Library, even if advised of the possibility of such damage.<br><br>Permission is hereby granted to use, copy, modify, and distribute this<br>source code, or portions hereof, for any purpose, without fee, subject<br>to the following restrictions:<br><br>1. The origin of this source code must not be_pos misrepresented.<br><br>2. Altered versions must be_pos plainly marked as such and must not<br>be_pos misrepresented as being the original source.<br><br>3. This Copyright notice may not be_pos removed or altered from any<br>source or altered source distribution.";
			return;
		case(libtiff_LICENSE):
			name_ = "libtiff";
			copyright_.emplace_back(Copyright("Sam Leffler", 1988, 1997));
			copyright_.emplace_back(Copyright("Silicon Graphics, Inc.", 1991, 1997));
			str_ = "Permission to use, copy, modify, distribute, and sell this software and <br>its documentation for any purpose is hereby granted without fee, provided<br>that (i) the above copyright notices and this permission notice appear in<br>all copies of the software and related documentation, and (ii) the names of<br>Sam Leffler and Silicon Graphics may not be_pos used in any advertising or<br>publicity relating to the software without the specific, prior written<br>permission of Sam Leffler and Silicon Graphics.<br><br>THE SOFTWARE IS PROVIDED \"AS-IS\" AND WITHOUT WARRANTY OF ANY KIND, <br>EXPRESS, IMPLIED OR OTHERWISE, INCLUDING WITHOUT LIMITATION, ANY <br>WARRANTY OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.  <br><br>IN NO EVENT SHALL SAM LEFFLER OR SILICON GRAPHICS BE LIABLE FOR<br>ANY SPECIAL, INCIDENTAL, INDIRECT OR CONSEQUENTIAL DAMAGES OF ANY KIND,<br>OR NY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,<br>WHETHER OR NOT ADVISED OF THE POSSIBILITY OF DAMAGE, AND ON ANY THEORY OF <br>LIBILITY, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE <br>OF THIS SOFTWARE.";
			return;
		case(libogg_LICENSE):
			name_ = "libogg";
			copyright_.emplace_back(Copyright("Xiph.org Foundation", 2002, 2009));
			str_ = "Redistribution and use in source and binary forms, with or without<br>modification, are permitted provided that the following conditions<br>are met:<br><br>- Redistributions of source code must retain the above copyright<br>notice, this list of conditions and the following disclaimer.<br><br>- Redistributions in binary form must reproduce the above copyright<br>notice, this list of conditions and the following disclaimer in the<br>documentation and/or other materials provided with the distribution.<br><br>- Neither the name of the Xiph.org Foundation nor the names of its<br>contributors may be_pos used to endorse or promote products derived from<br>this software without specific prior written permission.<br><br>THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS<br>``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT<br>LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR<br>A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION<br>OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,<br>SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT<br>LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,<br>DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY<br>THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT<br>(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE<br>OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.";
			return;
		case(Opus_audio_codec_LICENSE):
			name_ = "Opus audio codec";
			copyright_.emplace_back(Copyright("Xiph.Org, Skype Limited, Octasic, Jean - Marc Valin, Timothy B.Terriberry, CSIRO, Gregory Maxwell, Mark Borgerding, Erik de Castro Lopo", 2001, 2011));
			str_ = "Redistribution and use in source and binary forms, with or without<br>modification, are permitted provided that the following conditions<br>are met:<br><br>- Redistributions of source code must retain the above copyright<br>notice, this list of conditions and the following disclaimer.<br><br>- Redistributions in binary form must reproduce the above copyright<br>notice, this list of conditions and the following disclaimer in the<br>documentation and/or other materials provided with the distribution.<br><br>- Neither the name of Internet Society, IETF or IETF Trust, nor the<br>names of specific contributors, may be_pos used to endorse or promote<br>products derived from this software without specific prior written<br>permission.<br><br>THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS<br>``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT<br>LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR<br>A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER<br>OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,<br>EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,<br>PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR<br>PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF<br>LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING<br>NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS<br>SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.";
			return;
		case(Opusfile_LICENSE):
			name_ = "Opusfile";
			copyright_.emplace_back(Copyright("Xiph.Org Foundation and contributors", 1994, 2013));
			str_ = "Redistribution and use in source and binary forms, with or without<br>modification, are permitted provided that the following conditions<br>are met:<br><br>- Redistributions of source code must retain the above copyright<br>notice, this list of conditions and the following disclaimer.<br><br>- Redistributions in binary form must reproduce the above copyright<br>notice, this list of conditions and the following disclaimer in the<br>documentation and/or other materials provided with the distribution.<br><br>- Neither the name of the Xiph.Org Foundation nor the names of its<br>contributors may be_pos used to endorse or promote products derived from<br>this software without specific prior written permission.<br><br>THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS<br>``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT<br>LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR<br>A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION<br>OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,<br>SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT<br>LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,<br>DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY<br>THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT<br>(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE<br>OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.";
			return;
		case(Mersenne_Twister_LICENSE):
			name_ = "Mersenne Twister";
			copyright_.emplace_back(Copyright("Makoto Matsumoto and Takuji Nishimura, All rights reserved.", 1997, 2002));
			str_ = "Redistribution and use in source and binary forms, with or without<br>modification, are permitted provided that the following conditions<br>are met:<br><br>1. Redistributions of source code must retain the above copyright<br>   notice, this list of conditions and the following disclaimer.<br><br>2. Redistributions in binary form must reproduce the above copyright<br>   notice, this list of conditions and the following disclaimer in the<br>   documentation and/or other materials provided with the distribution.<br><br>3. The name of the author may not be_pos used to endorse or promote products<br>   derived from this software without specific prior written permission.<br><br>   THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR<br>IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES<br>OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.<br>IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,<br>INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT<br>NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,<br>DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY<br>THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT<br>(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF<br>THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.";
			return;
		case(Bullet_LICENSE):
			name_ = "Bullet";
			copyright_.emplace_back(Copyright("Erwin Coumans.", 2003, 2006));
			str_ = "";
			return;
		case(DX_Library_LICENSE):
			name_ = "DX Library";
			copyright_.emplace_back(Copyright("Takumi Yamada.", 2001, 2018));
			str_ = "";
			return;
		case(Siv3D_Engine_LICENSE):
			name_ = "Siv3D Engine";
			copyright_.emplace_back(Copyright("Ryo Suzuki", 2008, 2018));
			copyright_.emplace_back(Copyright("OpenSiv3D Project", 2016, 2018));
			str_ = "Permission is hereby granted, free of charge, to any person obtaining a copy<br>of this software and associated documentation files(the “Software”), to deal<br>in the Software without restriction, including without limitation the rights<br>to use, copy, modify, merge, publish, distribute, sublicense, and/or sell<br>copies of the Software, and to permit persons to whom the Software is<br>furnished to do so, subject to the following conditions :<br><br>The above copyright notice and this permission notice shall be_pos included in all<br>copies or substantial portions of the Software.<br><br>THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR<br>IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,<br>FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE<br>AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER<br>LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,<br>OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE<br>SOFTWARE.";
			return;
		case(HamFramework_LICENSE):
			name_ = "HamFramework";
			copyright_.emplace_back(Copyright("HAMSTRO", 2014, 2018));
			copyright_.emplace_back(Copyright("OpenSiv3D Project", 2016, 2018));
			str_ = "Permission is hereby granted, free of charge, to any person obtaining a copy<br>of this software and associated documentation files(the “Software”), to deal<br>in the Software without restriction, including without limitation the rights<br>to use, copy, modify, merge, publish, distribute, sublicense, and/or sell<br>copies of the Software, and to permit persons to whom the Software is<br>furnished to do so, subject to the following conditions :<br><br>The above copyright notice and this permission notice shall be_pos included in all<br>copies or substantial portions of the Software.<br><br>THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR<br>IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,<br>FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE<br>AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER<br>LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,<br>OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE<br>SOFTWARE.";
			return;
		case(Abseil_LICENSE):
			name_ = "Abseil";
			copyright_.emplace_back(Copyright("The Abseil Authors.", 2017, 0));
			str_ = "Licensed under the Apache License, Version 2.0 (the \"License\");<br>you may not use this file except in compliance with the License.<br>You may obtain a copy of the License at<br><br>    http://www.apache.org/licenses/LICENSE-2.0<br><br>Unless required by applicable law or agreed to in writing, software<br>distributed under the License is distributed on an \"AS IS\" BASIS,<br>WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.<br>See the License for the specific language governing permissions and<br>limitations under the License.";
			return;
		case(AngelCode_Scripting_Library_LICENSE):
			name_ = "AngelCode Scripting Library";
			copyright_.emplace_back(Copyright("Andreas Jonsson", 2003, 2017));
			str_ = "This software is provided 'as-is', without any express or implied<br>warranty. In no event will the authors be_pos held liable for any<br>damages arising from the use of this software.<br><br>Permission is granted to anyone to use this software for any<br>purpose, including commercial applications, and to alter it and<br>redistribute it freely, subject to the following restrictions:<br><br>1. The origin of this software must not be_pos misrepresented; you<br>must not claim that you wrote the original software. If you use<br>this software in a product, an acknowledgment in the product<br>documentation would be_pos appreciated but is not required.<br><br>2. Altered source versions must be_pos plainly marked as such, and<br>must not be_pos misrepresented as being the original software.<br><br>3. This notice may not be_pos removed or altered from any source<br>distribution.";
			return;
		case(Box2D_LICENSE):
			name_ = "Box2D";
			copyright_.emplace_back(Copyright("Erin Catto http://www.box2d.org", 2006, 2017));
			str_ = "This software is provided 'as-is', without any express or implied<br>warranty. In no event will the authors be_pos held liable for any damages<br>arising from the use of this software.<br><br>Permission is granted to anyone to use this software for any purpose,<br>including commercial applications, and to alter it and redistribute it<br>freely, subject to the following restrictions:<br><br>1. The origin of this software must not be_pos misrepresented; you must not<br>   claim that you wrote the original software. If you use this software<br>   in a product, an acknowledgment in the product documentation would be_pos<br>   appreciated but is not required.<br>2. Altered source versions must be_pos plainly marked as such, and must not be_pos<br>   misrepresented as being the original software.<br>3. This notice may not be_pos removed or altered from any source distribution.";
			return;
		case(cereal_LICENSE):
			name_ = "cereal";
			copyright_.emplace_back(Copyright("Randolph Voorhies, Shane Grant All rights reserved.", 2014, 0));
			str_ = "Redistribution and use in source and binary forms, with or without<br>modification, are permitted provided that the following conditions are met:<br>    * Redistributions of source code must retain the above copyright<br>      notice, this list of conditions and the following disclaimer.<br>    * Redistributions in binary form must reproduce the above copyright<br>      notice, this list of conditions and the following disclaimer in the<br>      documentation and/or other materials provided with the distribution.<br>    * Neither the name of cereal nor the<br>      names of its contributors may be_pos used to endorse or promote products<br>      derived from this software without specific prior written permission.<br><br>THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS \"AS IS\" AND<br>ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED<br>WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE<br>DISCLAIMED. IN NO EVENT SHALL RANDOLPH VOORHIES OR SHANE GRANT BE LIABLE FOR ANY<br>DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES<br>(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;<br>LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND<br>ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT<br>(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS<br>SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.";
			return;
		case(Convenient_Constructs_For_Stepping_Through_a_Range_of_Values_LICENSE):
			name_ = "Convenient Constructs For Stepping Through a Range of Values";
			copyright_.emplace_back(Copyright("Mikhail Semenov", 0, 0));
			str_ = "Licenced with the Code Project Open Licence (CPOL) http://www.codeproject.com/info/cpol10.aspx";
			return;
		case(clip2tri_LICENSE):
			name_ = "clip2tri";
			copyright_.emplace_back(Copyright("Bitfighter developers", 2014, 0));
			str_ = "Permission is hereby granted, free of charge, to any person obtaining a copy<br>of this software and associated documentation files (the “Software”), to deal<br>in the Software without restriction, including without limitation the rights<br>to use, copy, modify, merge, publish, distribute, sublicense, and/or sell<br>copies of the Software, and to permit persons to whom the Software is<br>furnished to do so, subject to the following conditions:<br><br>The above copyright notice and this permission notice shall be_pos included in all<br>copies or substantial portions of the Software.<br><br>THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR<br>IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,<br>FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE<br>AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER<br>LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,<br>OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE<br>SOFTWARE.";
			return;
		case(Clipper_LICENSE):
			name_ = "Clipper";
			copyright_.emplace_back(Copyright("Angus Johnson", 2010, 2014));
			str_ = "Released under the Boost Software License - Version 1.0 - August 17th, 2003<br>http://www.boost.org/LICENSE_1_0.txt";
			return;
		case(cpptoml_LICENSE):
			name_ = "cpptoml";
			copyright_.emplace_back(Copyright("Chase Geigle", 2014, 0));
			str_ = "Permission is hereby granted, free of charge, to any person obtaining a copy of<br>this software and associated documentation files (the \"Software\"), to deal in<br>the Software without restriction, including without limitation the rights to<br>use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of<br>the Software, and to permit persons to whom the Software is furnished to do so,<br>subject to the following conditions:<br><br>The above copyright notice and this permission notice shall be_pos included in all<br>copies or substantial portions of the Software.<br><br>THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR<br>IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS<br>FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR<br>COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER<br>IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN<br>CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.";
			return;
		case(DirectXMath_LICENSE):
			name_ = "DirectXMath";
			copyright_.emplace_back(Copyright("Microsoft Corp", 2017, 0));
			str_ = "Permission is hereby granted, free of charge, to any person obtaining a copy of this<br>software and associated documentation files (the \"Software\"), to deal in the Software<br>without restriction, including without limitation the rights to use, copy, modify,<br>merge, publish, distribute, sublicense, and/or sell copies of the Software, and to<br>permit persons to whom the Software is furnished to do so, subject to the following<br>conditions:<br><br>The above copyright notice and this permission notice shall be_pos included in all copies<br>or substantial portions of the Software.<br><br>THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,<br>INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A<br>PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT<br>HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF<br>CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE<br>OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.";
			return;
		case(double_conversion_LICENSE):
			name_ = "double-conversion";
			copyright_.emplace_back(Copyright("the V8 project authors. All rights reserved.", 2006, 2011));
			str_ = "Redistribution and use in source and binary forms, with or without<br>modification, are permitted provided that the following conditions are<br>met:<br><br>* Redistributions of source code must retain the above copyright<br>notice, this list of conditions and the following disclaimer.<br>* Redistributions in binary form must reproduce the above<br>copyright notice, this list of conditions and the following<br>disclaimer in the documentation and/or other materials provided<br>with the distribution.<br>* Neither the name of Google Inc. nor the names of its<br>contributors may be_pos used to endorse or promote products derived<br>from this software without specific prior written permission.<br><br>THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS<br>\"AS IS\" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT<br>LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR<br>A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT<br>OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,<br>SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT<br>LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,<br>DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY<br>THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT<br>(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE<br>OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.";
			return;
		case(Easing_Equations_LICENSE):
			name_ = "Easing Equations";
			copyright_.emplace_back(Copyright("Robert Penner", 2001, 0));
			str_ = "Redistribution and use in source and binary forms, with or without<br>modification, are permitted provided that the following conditions are<br>met:<br><br>* Redistributions of source code must retain the above copyright<br>notice, this list of conditions and the following disclaimer.<br>* Redistributions in binary form must reproduce the above<br>copyright notice, this list of conditions and the following<br>disclaimer in the documentation and/or other materials provided<br>with the distribution.<br>* Neither the name of the author nor the names of its<br>contributors may be_pos used to endorse or promote products derived<br>from this software without specific prior written permission.<br><br>THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS<br>\"AS IS\" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT<br>LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR<br>A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT<br>OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,<br>SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT<br>LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,<br>DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY<br>THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT<br>(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE<br>OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.";
			return;
		case(easyexif_LICENSE):
			name_ = "easyexif";
			copyright_.emplace_back(Copyright("Mayank Lahiri", 2010, 2015));
			str_ = "Redistribution and use in source and binary forms, with or without<br>modification, are permitted provided that the following conditions are met:<br>-- Redistributions of source code must retain the above copyright notice,<br>    this list of conditions and the following disclaimer.<br>-- Redistributions in binary form must reproduce the above copyright notice,<br>    this list of conditions and the following disclaimer in the documentation<br>    and/or other materials provided with the distribution.<br>THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ``AS IS'' AND ANY EXPRESS<br>OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES<br>OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN<br>NO EVENT SHALL THE FREEBSD PROJECT OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,<br>INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,<br>BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,<br>DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY<br>OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING<br>NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,<br>EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.";
			return;
		case(FID_LICENSE):
			name_ = "FID";
			copyright_.emplace_back(Copyright("hec", 2017, 0));
			str_ = "Permission is hereby granted, free of charge, to any person obtaining a copy<br>of this software and associated documentation files (the \"Software\"), to deal<br>in the Software without restriction, including without limitation the rights<br>to use, copy, modify, merge, publish, distribute, sublicense, and/or sell<br>copies of the Software, and to permit persons to whom the Software is<br>furnished to do so, subject to the following conditions:<br><br>The above copyright notice and this permission notice shall be_pos included in all<br>copies or substantial portions of the Software.<br><br>THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR<br>IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,<br>FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE<br>AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER<br>LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,<br>OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE<br>SOFTWARE.";
			return;
		case(fmt_LICENSE):
			name_ = "fmt";
			copyright_.emplace_back(Copyright("Victor Zverovich", 2012, 2016));
			str_ = "Redistribution and use in source and binary forms, with or without<br>modification, are permitted provided that the following conditions are met:<br><br>1. Redistributions of source code must retain the above copyright notice, this<br>list of conditions and the following disclaimer.<br>2. Redistributions in binary form must reproduce the above copyright notice,<br>this list of conditions and the following disclaimer in the documentation<br>and/or other materials provided with the distribution.<br><br>THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS \"AS IS\" AND<br>ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED<br>WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE<br>DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR<br>ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES<br>(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;<br>LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND<br>ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT<br>(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS<br>SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.";
			return;
		case(Font_Awesome_LICENSE):
			name_ = "Font Awesome";
			str_ = "Licensed under SIL Open Font License v1.1.";
			return;
		case(FreeType_LICENSE):
			name_ = "FreeType";
			str_ = "This software is based in part of the work of the FreeType Team.";
			return;
		case(frontal_cat_face_detector_LICENSE):
			name_ = "frontal cat face detector";
			copyright_.emplace_back(Copyright("Joseph Howse (Nummist Media Corporation Limited, Halifax, Nova Scotia, Canada). All rights reserved.", 2014, 2016));
			str_ = "Redistribution and use in source and binary forms, with or without<br>modification, are permitted provided that the following conditions are<br>met:<br><br>   * Redistributions of source code must retain the above copyright<br>      notice, this list of conditions and the following disclaimer.<br>   * Redistributions in binary form must reproduce the above<br>     copyright notice, this list of conditions and the following<br>     disclaimer in the documentation and/or other materials provided<br>     with the distribution.<br>   * The name of Contributor may not used to endorse or promote products<br>     derived from this software without specific prior written permission.<br><br>THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS<br>\"AS IS\" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT<br>LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR<br>A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE<br>CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,<br>EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,<br>PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR<br>PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF<br>LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING<br>NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS<br>SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.";
			return;
		case(giflib_LICENSE):
			name_ = "giflib";
			copyright_.emplace_back(Copyright("Eric S.Raymond ", 1997, 0));
			str_ = "Permission is hereby granted, free of charge, to any person obtaining a copy<br>of this software and associated documentation files(the \"Software\"), to deal<br>in the Software without restriction, including without limitation the rights<br>to use, copy, modify, merge, publish, distribute, sublicense, and/or sell<br>copies of the Software, and to permit persons to whom the Software is<br>furnished to do so, subject to the following conditions :<br><br>The above copyright notice and this permission notice shall be_pos included in<br>all copies or substantial portions of the Software.<br><br>THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR<br>IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,<br>FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE<br>AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER<br>LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,<br>OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN<br>THE SOFTWARE.";
			return;
		case(HarfBuzz_LICENSE):
			name_ = "HarfBuzz";
			copyright_.emplace_back(Copyright("Google, Inc.", 2010, 2012));
			copyright_.emplace_back(Copyright("Mozilla Foundation", 2012, 0));
			copyright_.emplace_back(Copyright("Codethink Limited", 2011, 0));
			copyright_.emplace_back(Copyright("Nokia Corporation and/or its subsidiary(-ies)", 2008, 2010));
			copyright_.emplace_back(Copyright("Keith Stribley", 2009, 0));
			copyright_.emplace_back(Copyright("Martin Hosken and SIL International", 2009, 0));
			copyright_.emplace_back(Copyright("Chris Wilson", 2007, 0));
			copyright_.emplace_back(Copyright("Behdad Esfahbod", 2006, 0));
			copyright_.emplace_back(Copyright("David Turner", 2005, 0));
			copyright_.emplace_back(Copyright("Red Hat, Inc.", 2004, 2010));
			copyright_.emplace_back(Copyright("David Turner and Werner Lemberg", 1998, 2004));
			str_ = "Permission is hereby granted, without written agreement and without<br>license or royalty fees, to use, copy, modify, and distribute this<br>software and its documentation for any purpose, provided that the<br>above copyright notice and the following two paragraphs appear in<br>all copies of this software.<br><br>IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE TO ANY PARTY FOR<br>DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES<br>ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN<br>IF THE COPYRIGHT HOLDER HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH<br>DAMAGE.<br><br>THE COPYRIGHT HOLDER SPECIFICALLY DISCLAIMS ANY WARRANTIES, INCLUDING,<br>BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND<br>FITNESS FOR A PARTICULAR PURPOSE. THE SOFTWARE PROVIDED HEREUNDER IS<br>ON AN \"AS IS\" BASIS, AND THE COPYRIGHT HOLDER HAS NO OBLIGATION TO<br>PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.";
			return;
		case(hopscotch_map_LICENSE):
			name_ = "hopscotch-map";
			copyright_.emplace_back(Copyright("Tessil", 2017, 0));
			str_ = "Permission is hereby granted, free of charge, to any person obtaining a copy<br>of this software and associated documentation files (the \"Software\"), to deal<br>in the Software without restriction, including without limitation the rights<br>to use, copy, modify, merge, publish, distribute, sublicense, and/or sell<br>copies of the Software, and to permit persons to whom the Software is<br>furnished to do so, subject to the following conditions:<br><br>The above copyright notice and this permission notice shall be_pos included in all<br>copies or substantial portions of the Software.<br><br>THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR<br>IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,<br>FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE<br>AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER<br>LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,<br>OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE<br>SOFTWARE.";
			return;
		case(kld_intersections_LICENSE):
			name_ = "kld-intersections";
			copyright_.emplace_back(Copyright("Kevin Lindsey. All rights reserved.", 2013, 0));
			str_ = "Redistribution and use in source and binary forms, with or without modification,<br>are permitted provided that the following conditions are met:<br><br>Redistributions of source code must retain the above copyright notice, this<br>list of conditions and the following disclaimer.<br><br>Redistributions in binary form must reproduce the above copyright notice, this<br>list of conditions and the following disclaimer in the documentation and/or<br>other materials provided with the distribution.<br><br>Neither the name of the {organization} nor the names of its<br>contributors may be_pos used to endorse or promote products derived from<br>this software without specific prior written permission.<br><br>THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS \"AS IS\" AND<br>ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED<br>WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE<br>DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR<br>ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES<br>(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;<br>LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON<br>ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT<br>(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS<br>SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.";
			return;
		case(JUMAN_LICENSE):
			name_ = "JUMAN++";
			copyright_.emplace_back(Copyright("The Juman++ Authors https://github.com/ku-nlp/jumanpp", 2016, 2018));
			str_ = "Licensed under the Apache License, Version 2.0 (the \"License\");<br>you may not use this file except in compliance with the License.<br>You may obtain a copy of the License at<br><br>    http://www.apache.org/licenses/LICENSE-2.0<br><br>Unless required by applicable law or agreed to in writing, software<br>distributed under the License is distributed on an \"AS IS\" BASIS,<br>WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.<br>See the License for the specific language governing permissions and<br>limitations under the License.";
			return;
		case(kld_polynomial_LICENSE):
			name_ = "kld-polynomial";
			copyright_.emplace_back(Copyright("Kevin Lindsey. All rights reserved.", 2013, 0));
			str_ = "Redistribution and use in source and binary forms, with or without modification,<br>are permitted provided that the following conditions are met:<br><br>Redistributions of source code must retain the above copyright notice, this<br>list of conditions and the following disclaimer.<br><br>Redistributions in binary form must reproduce the above copyright notice, this<br>list of conditions and the following disclaimer in the documentation and/or<br>other materials provided with the distribution.<br><br>Neither the name of the {organization} nor the names of its<br>contributors may be_pos used to endorse or promote products derived from<br>this software without specific prior written permission.<br><br>THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS \"AS IS\" AND<br>ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED<br>WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE<br>DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR<br>ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES<br>(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;<br>LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON<br>ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT<br>(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS<br>SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.";
			return;
		case(lbpcascade_animeface_LICENSE):
			name_ = "lbpcascade animeface";
			copyright_.emplace_back(Copyright("by nagadomi@nurs.or.jp", 2011, 0));
			str_ = "Permission is hereby granted, free of charge, to any person obtaining a copy<br>of this software and associated documentation files (the \"Software\"), to deal<br>in the Software without restriction, including without limitation the rights<br>to use, copy, modify, merge, publish, distribute, sublicense, and/or sell<br>copies of the Software, and to permit persons to whom the Software is<br>furnished to do so, subject to the following conditions:<br><br>The above copyright notice and this permission notice shall be_pos included in<br>all copies or substantial portions of the Software.<br><br>THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR<br>IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,<br>FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE<br>AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER<br>LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,<br>OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN<br>THE SOFTWARE.";
			return;
		case(libjpeg_turbo_LICENSE):
			name_ = "libjpeg-turbo";
			copyright_.emplace_back(Copyright("D. R. Commander. All Rights Reserved.", 2009, 2016));
			str_ = "Redistribution and use in source and binary forms, with or without<br>modification, are permitted provided that the following conditions are met:<br><br>- Redistributions of source code must retain the above copyright notice,<br>this list of conditions and the following disclaimer.<br>- Redistributions in binary form must reproduce the above copyright notice,<br>this list of conditions and the following disclaimer in the documentation<br>and/or other materials provided with the distribution.<br>- Neither the name of the libjpeg-turbo Project nor the names of its<br>contributors may be_pos used to endorse or promote products derived from this<br>software without specific prior written permission.<br><br>THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS \"AS IS\",<br>AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE<br>IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE<br>ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE<br>LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR<br>CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF<br>SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS<br>INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN<br>CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)<br>ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE<br>POSSIBILITY OF SUCH DAMAGE.";
			return;
		case(libsvm_LICENSE):
			name_ = "libsvm";
			copyright_.emplace_back(Copyright("Chih-Chung Chang and Chih-Jen Lin", 2000, 2014));
			str_ = "Redistribution and use in source and binary forms, with or without<br>modification, are permitted provided that the following conditions<br>are met:<br><br>1. Redistributions of source code must retain the above copyright<br>notice, this list of conditions and the following disclaimer.<br><br>2. Redistributions in binary form must reproduce the above copyright<br>notice, this list of conditions and the following disclaimer in the<br>documentation and/or other materials provided with the distribution.<br><br>3. Neither name of copyright holders nor the names of its contributors<br>may be_pos used to endorse or promote products derived from this software<br>without specific prior written permission.<br><br><br>THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS<br>``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT<br>LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR<br>A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR<br>CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,<br>EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,<br>PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR<br>PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF<br>LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING<br>NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS<br>SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.";
			return;
		case(LineSegmentIntersection_LICENSE):
			name_ = "LineSegmentIntersection";
			copyright_.emplace_back(Copyright("Kristian Lindberg Vinther", 2015, 0));
			str_ = "Licenced with the Code Project Open Licence (CPOL) http://www.codeproject.com/info/cpol10.aspx";
			return;
		case(miniutf_LICENSE):
			name_ = "miniutf";
			copyright_.emplace_back(Copyright("Dropbox, Inc.", 2013, 0));
			str_ = "Permission is hereby granted, free of charge, to any person obtaining a copy<br>of this software and associated documentation files (the \"Software\"), to deal<br>in the Software without restriction, including without limitation the rights<br>to use, copy, modify, merge, publish, distribute, sublicense, and/or sell<br>copies of the Software, and to permit persons to whom the Software is<br>furnished to do so, subject to the following conditions:<br><br>The above copyright notice and this permission notice shall be_pos included in<br>all copies or substantial portions of the Software.<br><br>THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR<br>IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,<br>FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE<br>AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER<br>LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,<br>OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN<br>THE SOFTWARE.";
			return;
		case(msinttypes_r29_LICENSE):
			name_ = "msinttypes r29";
			copyright_.emplace_back(Copyright("Alexander Chemeris", 2006, 2013));
			str_ = "Redistribution and use in source and binary forms, with or without<br>modification, are permitted provided that the following conditions are met:<br><br>- Redistributions of source code must retain the above copyright notice,<br>this list of conditions and the following disclaimer.<br>- Redistributions in binary form must reproduce the above copyright notice,<br>this list of conditions and the following disclaimer in the documentation<br>and/or other materials provided with the distribution.<br>- Neither the name of copyright holder nor the names of its contributors<br>may be_pos used to endorse or promote products derived from this software<br>without specific prior written permission.<br><br>THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS \"AS IS\",<br>AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE<br>IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE<br>ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE<br>LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR<br>CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF<br>SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS<br>INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN<br>CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)<br>ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE<br>POSSIBILITY OF SUCH DAMAGE.";
			return;
		case(muparser_LICENSE):
			name_ = "muparser";
			copyright_.emplace_back(Copyright("Ingo Berg", 2011, 0));
			str_ = "Permission is hereby granted, free of charge, to any person obtaining a copy of this<br>software and associated documentation files(the \"Software\"), to deal in the Software<br>without restriction, including without limitation the rights to use, copy, modify,<br>merge, publish, distribute, sublicense, and / or sell copies of the Software, and to<br>permit persons to whom the Software is furnished to do so, subject to the following conditions:<br><br>The above copyright notice and this permission notice shall be_pos included in all copies or<br>substantial portions of the Software.<br><br>THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT<br>NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND<br>NONINFRINGEMENT.IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,<br>DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,<br>OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.<br>OR OTHER DEALINGS IN THE SOFTWARE.";
			return;
		case(nanoflann_LICENSE):
			name_ = "nanoflann";
			copyright_.emplace_back(Copyright("Marius Muja (mariusm@cs.ubc.ca). All rights reserved.", 2008, 2009));
			copyright_.emplace_back(Copyright("David G. Lowe (lowe@cs.ubc.ca). All rights reserved.", 2008, 2009));
			copyright_.emplace_back(Copyright("Jose L. Blanco (joseluisblancoc@gmail.com). All rights reserved.", 2011, 0));
			str_ = "THE BSD LICENSE<br><br>Redistribution and use in source and binary forms, with or without<br>modification, are permitted provided that the following conditions<br>are met:<br><br>1. Redistributions of source code must retain the above copyright<br>   notice, this list of conditions and the following disclaimer.<br>2. Redistributions in binary form must reproduce the above copyright<br>   notice, this list of conditions and the following disclaimer in the<br>   documentation and/or other materials provided with the distribution.<br><br>THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR<br>IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES<br>OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.<br>IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,<br>INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT<br>NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,<br>DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY<br>THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT<br>(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF<br>THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.";
			return;
		case(Noto_Fonts_LICENSE):
			name_ = "Noto Fonts";
			str_ = "Licensed under SIL Open Font License v1.1.";
			return;
		case(OpenCV_LICENSE):
			name_ = "OpenCV";
			copyright_.emplace_back(Copyright("Intel Corporation, all rights reserved.", 2000, 2018));
			copyright_.emplace_back(Copyright("Willow Garage Inc., all rights reserved.", 2009, 2011));
			copyright_.emplace_back(Copyright("NVIDIA Corporation, all rights reserved.", 2009, 2016));
			copyright_.emplace_back(Copyright("Advanced Micro Devices, Inc., all rights reserved.", 2010, 2013));
			copyright_.emplace_back(Copyright("OpenCV Foundation, all rights reserved.", 2015, 2016));
			copyright_.emplace_back(Copyright("Itseez Inc., all rights reserved.", 2015, 2016));
			copyright_.emplace_back(Copyright("Third party copyrights are property of their respective owners.", 0, 0));
			str_ = "Redistribution and use in source and binary forms, with or without modification,<br>are permitted provided that the following conditions are met:<br><br>  * Redistributions of source code must retain the above copyright notice,<br>    this list of conditions and the following disclaimer.<br><br>  * Redistributions in binary form must reproduce the above copyright notice,<br>    this list of conditions and the following disclaimer in the documentation<br>    and/or other materials provided with the distribution.<br><br>  * Neither the names of the copyright holders nor the names of the contributors<br>    may be_pos used to endorse or promote products derived from this software<br>    without specific prior written permission.<br><br>This software is provided by the copyright holders and contributors \"as is\" and<br>any express or implied warranties, including, but not limited to, the implied<br>warranties of merchantability and fitness for a particular purpose are disclaimed.<br>In no event shall copyright holders or contributors be_pos liable for any direct,<br>indirect, incidental, special, exemplary, or consequential damages<br>(including, but not limited to, procurement of substitute goods or services;<br>loss of use, data, or profits; or business interruption) however caused<br>and on any theory of liability, whether in contract, strict liability,<br>or tort (including negligence or otherwise) arising in any way out of<br>the use of this software, even if advised of the possibility of such damage.";
			return;
		case(openFrameworks_LICENSE):
			name_ = "openFrameworks";
			copyright_.emplace_back(Copyright("openFrameworks Community", 2004, 2018));
			str_ = "Permission is hereby granted, free of charge,<br> to any person obtaining a copy of this software and associated documentation files (the \"Software\"),<br> to deal in the Software without restriction, including without limitation the rights to use,<br> copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software,<br> and to permit persons to whom the Software is furnished to do so,<br> subject to the following conditions:<br>The above copyright notice and this permission notice shall be_pos included in all copies or substantial portions of the Software.<br>THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,<br> INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.<br> IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,<br> DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,<br> OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.";
			return;
			return;
		case(Poly2Tri_LICENSE):
			name_ = "Poly2Tri";
			copyright_.emplace_back(Copyright("Poly2Tri Contributors. All rights reserved.", 2009, 2010));
			str_ = "Redistribution and use in source and binary forms, with or without modification,<br>are permitted provided that the following conditions are met:<br><br>* Redistributions of source code must retain the above copyright notice,<br>this list of conditions and the following disclaimer.<br>* Redistributions in binary form must reproduce the above copyright notice,<br>this list of conditions and the following disclaimer in the documentation<br>and/or other materials provided with the distribution.<br>* Neither the name of Poly2Tri nor the names of its contributors may be_pos<br>used to endorse or promote products derived from this software without specific<br>prior written permission.<br><br>THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS<br>\"AS IS\" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT<br>LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR<br>A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR<br>CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,<br>EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,<br>PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR<br>PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF<br>LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING<br>NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS<br>SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.";
			return;
		case(pffft_LICENSE):
			name_ = "pffft";
			copyright_.emplace_back(Copyright("Julien Pommier ( pommier@modartt.com )", 2013, 0));
			str_ = "Based on original fortran 77 code from FFTPACKv4 from NETLIB<br>(http://www.netlib.org/fftpack), authored by Dr Paul Swarztrauber<br>of NCAR, in 1985.<br><br>As confirmed by the NCAR fftpack software curators, the following<br>FFTPACKv5 license applies to FFTPACKv4 sources. My changes are<br>released under the same terms.<br><br>FFTPACK license:<br><br>http://www.cisl.ucar.edu/css/software/fftpack5/ftpk.html<br><br>Copyright (c) 2004 the University Corporation for Atmospheric<br>Research (\"UCAR\"). All rights reserved. Developed by NCAR's<br>Computational and Information Systems Laboratory, UCAR,<br>www.cisl.ucar.edu.<br><br>Redistribution and use of the Software in source and binary forms,<br>with or without modification, is permitted provided that the<br>following conditions are met:<br><br>- Neither the names of NCAR's Computational and Information Systems<br>Laboratory, the University Corporation for Atmospheric Research,<br>nor the names of its sponsors or contributors may be_pos used to<br>endorse or promote products derived from this Software without<br>specific prior written permission.  <br><br>- Redistributions of source code must retain the above copyright<br>notices, this list of conditions, and the disclaimer below.<br><br>- Redistributions in binary form must reproduce the above copyright<br>notice, this list of conditions, and the disclaimer below in the<br>documentation and/or other materials provided with the<br>distribution.<br><br>THIS SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND,<br>EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO THE WARRANTIES OF<br>MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND<br>NONINFRINGEMENT. IN NO EVENT SHALL THE CONTRIBUTORS OR COPYRIGHT<br>HOLDERS BE LIABLE FOR ANY CLAIM, INDIRECT, INCIDENTAL, SPECIAL,<br>EXEMPLARY, OR CONSEQUENTIAL DAMAGES OR OTHER LIABILITY, WHETHER IN AN<br>ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN<br>CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS WITH THE<br>SOFTWARE.";
			return;
		case(QRCode_LICENSE):
			name_ = "QRCode";
			copyright_.emplace_back(Copyright("Richard Moore", 2017, 0));
			str_ = "Permission is hereby granted, free of charge, to any person obtaining a copy<br>of this software and associated documentation files (the \"Software\"), to deal<br>in the Software without restriction, including without limitation the rights<br>to use, copy, modify, merge, publish, distribute, sublicense, and/or sell<br>copies of the Software, and to permit persons to whom the Software is<br>furnished to do so, subject to the following conditions:<br><br>The above copyright notice and this permission notice shall be_pos included in<br>all copies or substantial portions of the Software.<br><br>THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR<br>IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,<br>FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE<br>AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER<br>LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,<br>OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN<br>THE SOFTWARE.";
			return;
		case(quirc_LICENSE):
			name_ = "quirc";
			copyright_.emplace_back(Copyright("Daniel Beer", 2010, 2012));
			str_ = "Permission to use, copy, modify, and/or distribute this software for<br>any purpose with or without fee is hereby granted, provided that the<br>above copyright notice and this permission notice appear in all<br>copies.<br><br>THE SOFTWARE IS PROVIDED \"AS IS\" AND THE AUTHOR DISCLAIMS ALL<br>WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED<br>WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE<br>AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL<br>DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR<br>PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER<br>TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR<br>PERFORMANCE OF THIS SOFTWARE.";
			return;
		case(RapidJSON_LICENSE):
			name_ = "RapidJSON";
			copyright_.emplace_back(Copyright("THL A29 Limited, a Tencent company, and Milo Yip. All rights reserved.", 2015, 0));
			str_ = "Permission is hereby granted, free of charge, to any person obtaining a copy of this<br>software and associated documentation files(the \"Software\"), to deal in the Software<br>without restriction, including without limitation the rights to use, copy, modify,<br>merge, publish, distribute, sublicense, and / or sell copies of the Software, and to<br>permit persons to whom the Software is furnished to do so, subject to the following conditions:<br><br>The above copyright notice and this permission notice shall be_pos included in all copies or<br>substantial portions of the Software.<br><br>THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT<br>NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND<br>NONINFRINGEMENT.IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,<br>DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,<br>OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.<br>OR OTHER DEALINGS IN THE SOFTWARE.";
			return;
		case(Recast_Detour_LICENSE):
			name_ = "Recast & Detour";
			copyright_.emplace_back(Copyright("Mikko Mononen memon@inside.org", 2009, 0));
			str_ = "This software is provided 'as-is', without any express or implied<br>warranty.  In no event will the authors be_pos held liable for any damages<br>arising from the use of this software.<br><br>Permission is granted to anyone to use this software for any purpose,<br>including commercial applications, and to alter it and redistribute it<br>freely, subject to the following restrictions:<br><br>1. The origin of this software must not be_pos misrepresented; you must not<br>claim that you wrote the original software. If you use this software<br>in a product, an acknowledgment in the product documentation would be_pos<br>appreciated but is not required.<br>2. Altered source versions must be_pos plainly marked as such, and must not be_pos<br>misrepresented as being the original software.<br>3. This notice may not be_pos removed or altered from any source distribution.";
			return;
		case(SFMT_LICENSE):
			name_ = "SFMT";
			copyright_.emplace_back(Copyright("Mutsuo Saito, Makoto Matsumoto and Hiroshima University.", 2006, 2007));
			copyright_.emplace_back(Copyright("Mutsuo Saito, Makoto Matsumoto, Hiroshima University and The University of Tokyo.", 2012, 0));
			str_ = "Redistribution and use in source and binary forms, with or without<br>modification, are permitted provided that the following conditions are<br>met:<br><br>* Redistributions of source code must retain the above copyright<br>notice, this list of conditions and the following disclaimer.<br>* Redistributions in binary form must reproduce the above<br>copyright notice, this list of conditions and the following<br>disclaimer in the documentation and/or other materials provided<br>with the distribution.<br>* Neither the names of Hiroshima University, The University of<br>Tokyo nor the names of its contributors may be_pos used to endorse<br>or promote products derived from this software without specific<br>prior written permission.<br><br>THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS<br>\"AS IS\" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT<br>LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR<br>A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT<br>OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,<br>SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT<br>LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,<br>DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY<br>THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT<br>(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE<br>OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.";
			return;
		case(Simple_DirectMedia_Layer_LICENSE):
			name_ = "Simple DirectMedia Layer";
			copyright_.emplace_back(Copyright("Sam Lantinga", 1997, 2017));
			str_ = "This software is provided 'as-is', without any express or implied<br>warranty.  In no event will the authors be_pos held liable for any damages<br>arising from the use of this software.<br><br>Permission is granted to anyone to use this software for any purpose,<br>including commercial applications, and to alter it and redistribute it<br>freely, subject to the following restrictions:<br>  <br>1. The origin of this software must not be_pos misrepresented; you must not<br>   claim that you wrote the original software. If you use this software<br>   in a product, an acknowledgment in the product documentation would be_pos<br>   appreciated but is not required. <br>2. Altered source versions must be_pos plainly marked as such, and must not be_pos<br>   misrepresented as being the original software.<br>3. This notice may not be_pos removed or altered from any source distribution.";
			return;
		case(TinySoundFont_LICENSE):
			name_ = "TinySoundFont";
			copyright_.emplace_back(Copyright("Bernhard Schelling Based on SFZero,", 2017, 0));
			copyright_.emplace_back(Copyright("Steve Folta (https://github.com/stevefolta/SFZero)", 2012, 0));
			str_ = "Permission is hereby granted, free of charge, to any person obtaining a copy of<br>this software and associated documentation files (the \"Software\"), to deal in<br>the Software without restriction, including without limitation the rights to<br>use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies<br>of the Software, and to permit persons to whom the Software is furnished to do<br>so, subject to the following conditions:<br><br>The above copyright notice and this permission notice shall be_pos included in all<br>copies or substantial portions of the Software.<br><br>THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR<br>IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,<br>FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE<br>AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER<br>LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,<br>OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE<br>SOFTWARE.";
			return;
		case(TinyXML_2_LICENSE):
			name_ = "TinyXML-2";
			copyright_.emplace_back(Copyright("Original code by Lee Thomason (www.grinninglizard.com)", 0, 0));
			str_ = "TinyXML-2 is released under the zlib license:<br>This software is provided 'as-is', without any express or implied<br>warranty.  In no event will the authors be_pos held liable for any damages<br>arising from the use of this software.<br><br>Permission is granted to anyone to use this software for any purpose,<br>including commercial applications, and to alter it and redistribute it<br>freely, subject to the following restrictions:<br><br>1. The origin of this software must not be_pos misrepresented; you must not<br>claim that you wrote the original software. If you use this software<br>in a product, an acknowledgment in the product documentation would be_pos<br>appreciated but is not required.<br>2. Altered source versions must be_pos plainly marked as such, and must not be_pos<br>misrepresented as being the original software.<br>3. This notice may not be_pos removed or altered from any source distribution.";
			return;
		case(xxHash_LICENSE):
			name_ = "xxHash";
			copyright_.emplace_back(Copyright("Yann Collet.", 2012, 2016));
			str_ = "Redistribution and use in source and binary forms, with or without<br>modification, are permitted provided that the following conditions are<br>met:<br><br>* Redistributions of source code must retain the above copyright<br>notice, this list of conditions and the following disclaimer.<br>* Redistributions in binary form must reproduce the above<br>copyright notice, this list of conditions and the following disclaimer<br>in the documentation and/or other materials provided with the<br>distribution.<br><br>THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS<br>\"AS IS\" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT<br>LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR<br>A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT<br>OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,<br>SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT<br>LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,<br>DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY<br>THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT<br>(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE<br>OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.";
			return;
		case(utflib_LICENSE):
			name_ = "utflib";
			str_ = "This software is licensed under CC0.";
			return;
		case(zlib_LICENSE):
			name_ = "zlib";
			copyright_.emplace_back(Copyright("Jean - loup Gailly and Mark Adler", 1995, 2017));
			str_ = "This software is provided 'as-is', without any express or implied<br>warranty.In no event will the authors be_pos held liable for any damages<br>arising from the use of this software.<br><br>Permission is granted to anyone to use this software for any purpose,<br>including commercial applications, and to alter it and redistribute it<br>freely, subject to the following restrictions :<br><br>1. The origin of this software must not be_pos misrepresented; you must not<br>claim that you wrote the original software.If you use this software<br>in a product, an acknowledgment in the product documentation would be_pos<br>appreciated but is not required.<br>2. Altered source versions must be_pos plainly marked as such, and must not be_pos<br>misrepresented as being the original software.<br>3. This notice may not be_pos removed or altered from any source distribution.";
			return;
		case(Zstandard_LICENSE):
			name_ = "Zstandard";
			copyright_.emplace_back(Copyright("-present, Facebook, Inc. All rights reserved.", 2016, 0));
			str_ = "Redistribution and use in source and binary forms, with or without modification,<br>are permitted provided that the following conditions are met:<br><br>* Redistributions of source code must retain the above copyright notice, this<br>list of conditions and the following disclaimer.<br><br>* Redistributions in binary form must reproduce the above copyright notice,<br>this list of conditions and the following disclaimer in the documentation<br>and/or other materials provided with the distribution.<br><br>* Neither the name Facebook nor the names of its contributors may be_pos used to<br>endorse or promote products derived from this software without specific<br>prior written permission.<br><br>THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS \"AS IS\" AND<br>ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED<br>WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE<br>DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR<br>ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES<br>(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;<br>LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON<br>ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT<br>(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS<br>SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.";
			return;
		}
	}
}

#endif //Included AsProject Library