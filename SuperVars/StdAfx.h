#pragma message ("Compiling precompiled header...")
#pragma warning(disable:4244)
#pragma warning(disable:4305)
#pragma warning(disable:4333)
#pragma warning(disable:4733)
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#define WINVER 0x0500					// Oldest supported windows (2000)
#define _WIN32_WINNT 0x0500
#define WIN32_LEAN_AND_MEAN
#undef UNICODE
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>

// Load SA Library
#include "../GTASA/StdInc.h"

#define check(a, v, s) _check((void*)(a), (DWORD)(v), (s))
#define jmp(a, v) _jmp((DWORD)(a), (DWORD)(v))