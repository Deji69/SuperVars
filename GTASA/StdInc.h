#pragma once
#pragma message ("Compiling SA headers...")
#pragma warning(disable:4244)
#pragma warning(disable:4305)

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#undef UNICODE

#include <new>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <math.h>

#define jmpTo(a, v) _jmpTo((BYTE*)(a), (DWORD)(v))
#define nop(a,b) _nop((void*)(a),b)
#define patch(a, v, s) _patch((void*)(a), (DWORD)(v), (s))
#define patchf(a, v) _patch((void*)(a), (float)(v))
#define read(a, s) _read((void*)(a), s)
#define read_jmp(a) (_read((void*)(a), 4) + (a+4))
#define charptr(a, v) _charptr((void*)(a), (const char*)(v))
#define changeCall(a, v) _changeCall((DWORD)(a), (DWORD)(v))
#define _x(a) (long double)VAR_MaxWidth - 0.001562500023283064 * (long double)VAR_MaxWidth * (640.0 - a)
#define _y(a) (long double)VAR_MaxHeight * 0.002232142956927419 * a
#define _width(a) VAR_MaxWidth * 0.001562500023283064 * a
#define _height(a) VAR_MaxHeight * 0.002232142956927419 * a

#include "crc32.h"
#include "Common.h"
#include "CGame.h"
#include "CTheScripts.h"