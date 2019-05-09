// BSD-2 part Licensed (full license and info at end of file)
#pragma once
#ifndef AL2O3_LZ4_COMPAT_H
#define AL2O3_LZ4_COMPAT_H

#include "al2o3_platform/platform.h"

// these doesn't follow al2o3 naming conventions because its for anything that
// wants the original lz4 api definations

#define LZ4_VERSION_MAJOR    1    /* for breaking interface changes  */
#define LZ4_VERSION_MINOR    9    /* for new (non-breaking) interface capabilities */
#define LZ4_VERSION_RELEASE  1    /* for tweaks, bug-fixes, or development */
#define LZ4_VERSION_NUMBER (LZ4_VERSION_MAJOR *100*100 + LZ4_VERSION_MINOR *100 + LZ4_VERSION_RELEASE)
#define LZ4_LIB_VERSION LZ4_VERSION_MAJOR.LZ4_VERSION_MINOR.LZ4_VERSION_RELEASE
#define LZ4_MAX_INPUT_SIZE        0x7E000000   /* 2 113 929 216 bytes */
#define LZ4_COMPRESSBOUND(isize)  ((unsigned)(isize) > (unsigned)LZ4_MAX_INPUT_SIZE ? 0 : (isize) + ((isize)/255) + 16)

AL2O3_EXTERN_C int LZ4_versionNumber (void);
AL2O3_EXTERN_C const char* LZ4_versionString (void);

AL2O3_EXTERN_C int LZ4_compress_default(char const* src, char* dst, int srcSize, int dstCapacity);
AL2O3_EXTERN_C int LZ4_decompress_safe(char const* src, char* dst, int compressedSize, int dstCapacity);
AL2O3_EXTERN_C size_t LZ4_compressBound(int inputSize);
AL2O3_EXTERN_C int LZ4_compress_fast(char const* src, char* dst, int srcSize, int dstCapacity, int acceleration);
AL2O3_EXTERN_C int LZ4_sizeofState(void);
AL2O3_EXTERN_C int LZ4_compress_fast_extState (void* state, const char* src, char* dst, int srcSize, int dstCapacity, int acceleration);
AL2O3_EXTERN_C int LZ4_decompress_safe_partial (const char* src, char* dst, int srcSize, int targetOutputSize, int dstCapacity);

#endif // end AL2O3_LZ4_COMPAT_H
/*
 Copyright (C) 2019-present, Dean Calver.
 Includes lz4 by Yann Collet - LZ4 source repository : https://github.com/lz4/lz4

   BSD 2-Clause License (http://www.opensource.org/licenses/bsd-license.php)

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:

       * Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
       * Redistributions in binary form must reproduce the above
   copyright notice, this list of conditions and the following disclaimer
   in the documentation and/or other materials provided with the
   distribution.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
