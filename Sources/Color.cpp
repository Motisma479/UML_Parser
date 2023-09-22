#include "Color.hpp"

#include <memory>
#include <algorithm>
#include <cmath>

std::array<u32, 3> Color::HSV()
{
    std::array<u32, 3> hsv{ 0 };

    u32 maxVal = std::max({ r, g, b });
    if (maxVal == 0)
        return hsv;

    u32 minVal = std::min({ r, g, b });
    u32 delta = maxVal - minVal;

    hsv[2] = lroundf((maxVal * 100.f) / 255);

    hsv[1] = lroundf((delta * 100.f) / maxVal);

    if (maxVal == r)
    {
        hsv[0] = lround(60 * std::fmod((g - b) / (float)delta, 6.0));
    }
    else if (maxVal == g)
    {
        hsv[0] = lroundf(60 * (2 + (b - r) / (float)delta));
    }
    else if (maxVal == b)
    {
        hsv[0] = lroundf(60 * (4 + (r - g) / (float)delta));
    }

    if (hsv[0] < 0)
    {
        hsv[0] += 360;
    }
    return hsv;
}

void Color::RGB(u32 h, u32 s, u32 v)
{

    if (s == 0) {
        r = g = b = static_cast<u8>(lround((v * 255) * 0.01f));
        return;
    }

    f32 f, p, q, t, _h;
    s32 i;

    _h = h / 60.f;            // sector 0 to 5
    i = static_cast<s32>(floor(_h));
    f = _h - i;          // fractional part of h
    p = (v * 0.01f) * (1 - (s * 0.01f));
    q = (v * 0.01f) * (1 - (s * 0.01f) * f);
    t = (v * 0.01f) * (1 - (s * 0.01f) * (1 - f));

    switch (i) {
    case 0:
        r = static_cast<u8>(lround((v * 255) * 0.01f));
        g = static_cast<u8>(lround(t * 255));
        b = static_cast<u8>(lround(p * 255));
        break;
    case 1:
        r = static_cast<u8>(lround(q * 255));
        g = static_cast<u8>(lround((v * 255) * 0.01f));
        b = static_cast<u8>(lround(p * 255));
        break;
    case 2:
        r = static_cast<u8>(lround(p * 255));
        g = static_cast<u8>(lround((v * 255) * 0.01f));
        b = static_cast<u8>(lround(t * 255));
        break;
    case 3:
        r = static_cast<u8>(lround(p * 255));
        g = static_cast<u8>(lround(q * 255));
        b = static_cast<u8>(lround((v * 255) * 0.01f));
        break;
    case 4:
        r = static_cast<u8>(lround(t * 255));
        g = static_cast<u8>(lround(p * 255));
        b = static_cast<u8>(lround((v * 255) * 0.01f));
        break;
    default:        // case 5:
        r = static_cast<u8>(lround((v * 255) * 0.01f));
        g = static_cast<u8>(lround(p * 255));
        b = static_cast<u8>(lround(q * 255));
        break;
    }
}

std::string SetTerminalColor(const char* text, Color color)
{
    std::string colorToString = "\033[38;2;" + std::to_string(color.r) + ";" + std::to_string(color.g) + ";" + std::to_string(color.b) + "m";
    std::string toDefaultColor = "\033[0m";
    std::string resultString = colorToString + text + toDefaultColor;

    return resultString;
}