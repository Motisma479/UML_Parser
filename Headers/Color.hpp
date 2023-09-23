#pragma once

#include "stdafx.hpp"

#include <array>

struct Color
{
	u8 r, g, b, a;

	std::array<u32, 3> HSV();
	void RGB(u32 h, u32 s, u32 v);
};

constexpr Color ENGINE_PURPLE = { 170, 142, 214, 255 };

constexpr Color WHITE = { 255, 255, 255, 255 };
constexpr Color BLACK = { 0,   0,   0,   255 };
constexpr Color RED = { 255, 0,   0,   255 };
constexpr Color GREEN = { 0,   255, 0,   255 };
constexpr Color BLUE = { 0,   0,   255, 255 };
constexpr Color ORANGE = { 255, 106, 0,   255 };
constexpr Color YELLOW = { 255, 216, 0,   255 };
constexpr Color LIGHT_BLUE = { 100, 184, 254, 255 };
constexpr Color BROWN = { 137, 72,  54,  255 };
constexpr Color LIGHT_GRAY = { 195, 195, 195, 255 };
constexpr Color GRAY = { 140, 140, 140, 255 };

std::string SetTerminalColor(const char* text, Color color);