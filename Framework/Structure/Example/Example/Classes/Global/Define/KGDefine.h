#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define INVALID_IDX			(-1)

// 메모리 관리
#define SAFE_FREE(TARGET)			if((TARGET) != NULL) { free((TARGET)); (TARGET) = NULL; }
