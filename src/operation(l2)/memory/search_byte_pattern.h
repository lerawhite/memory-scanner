#pragma once
#include <string>
#include <windows.h>
#include <iostream>
#include <vector>

std::vector<SIZE_T> search_byte_pattern(const BYTE* data, SIZE_T data_size, const BYTE* pattern, SIZE_T pattern_size);