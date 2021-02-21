// #################################
// #    Created By JakeQusha!!!    #
// #################################
#include <windows.h>
#include <time.h>
enum _RainbowPrintMode
{
    DEFAULT,
    RANDOM,
    RAINBOW
};
enum _colour : int16_t
{
    BLACK,
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    GOLD,
    LIGHTGRAY,
    DARKGRAY,
    LIGHTBLUE,
    LIGHTGREEN,
    LIGHTCYAN,
    LIGHTRED,
    LIGHTMAGENTA,
    YELLOW,
    WHITE
};

bool _init = false;
const int16_t rainbowcolors[] = {5, 13, 1, 9, 3, 10, 2, 14, 6, 12, 4, 5};
CONSOLE_SCREEN_BUFFER_INFO info;
CONSOLE_SCREEN_BUFFER_INFO info2;
HANDLE hConsole;
void init()
{
    _init = true;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    srand(time(NULL));
}

int16_t GetColourNumber(_colour Colour, _colour BackGroundColour)
{
    if (!_init)
        init();
    return Colour + BackGroundColour * 16;
}
int16_t GetCurrentColourNumber()
{
    if (!_init)
        init();
    if (!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info))
    {
        return 0;
    }
    else
    {
        return info.wAttributes;
    }
}
void SetColourByNumber(int16_t colour)
{
    if (!_init)
        init();
    SetConsoleTextAttribute(hConsole, colour);
}
void SetColour(_colour Colour, _colour BackGroundColour)
{
    if (!_init)
        init();
    SetConsoleTextAttribute(hConsole, Colour + BackGroundColour * 16);
}
void SetDefaultColour()
{
    if (!_init)
        init();
    SetConsoleTextAttribute(hConsole, 15);
}
void SetTextColour(_colour Colour)
{
    if (!_init)
        init();
    int16_t ret;

    if (!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info))
    {
        ret = 0;
    }
    else
    {
        ret = info.wAttributes;
        ret /= 16;
    }
    ret *= 16;
    ret += Colour;
    SetConsoleTextAttribute(hConsole, ret);
}
void SetBackgroundColour(_colour BackgroundColour)
{
    if (!_init)
        init();
    int16_t ret;
    if (!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info))
    {
        ret = 0;
    }
    else
    {
        ret = info.wAttributes;
        ret %= 16;
    }
    ret += BackgroundColour * 16;
    SetConsoleTextAttribute(hConsole, ret);
}
void RainbowPrint(std::string Text, _colour BackgroundColor, _RainbowPrintMode PrintMode)
{
    if (!_init)
        init();
    int16_t k;
    int16_t ret;
    if (!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info))
    {
        ret = 0;
    }
    else
    {
        ret = info.wAttributes;
    }
    for (int16_t i = 0; i < Text.size(); ++i)
    {
        switch (PrintMode)
        {
        case DEFAULT:
            k = i;
            if (k % 16 >= BackgroundColor)
            {
                k++;
            }
            break;
        case RANDOM:
            k = rand() % 16;
            if (k == BackgroundColor)
            {
                k++;
            }
            break;
        case RAINBOW:
            k = rainbowcolors[i % 11];
            if (k >= BackgroundColor)
            {
                if (i % 10 == 0)
                    k = rainbowcolors[0];
                else
                {
                    k = rainbowcolors[i % 11 + 1];
                }
            }
            break;
        }
        SetConsoleTextAttribute(hConsole, k % 16 + BackgroundColor * 16);
        putc(Text[i], stdout);
    }
    SetConsoleTextAttribute(hConsole, ret);
}

//ColourPrint:
//&<number> for colour change
//&&<number> for background colour change
//-& for write '&'
void ColourPrint(std::string Text)
{
    if (!_init)
        init();
    int16_t ret;
    if (!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info))
    {
        ret = 0;
    }
    else
    {
        ret = info.wAttributes;
    }
    int16_t k;
    int16_t tmp;
    for (int32_t i = 0; i < Text.size(); ++i)
    {
        if (!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info2))
        {
            k = 0;
        }
        else
        {
            k = info2.wAttributes;
        }
        if (Text[i] == '-' && Text[i + 1] == '&')
        {
            putc('&', stdout);
            i++;
            continue;
        }
        if (Text[i] == '&' && Text[i + 1] == '&')
        {
            i += 2;
            if (((int)Text[i + 1] - 48) <= 9 && ((int)Text[i + 1] - 48) >= 0)
            {
                tmp = ((int)Text[i] - 48) * 10 + ((int)Text[i + 1] - 48);
                i++;
            }
            else
            {
                tmp = ((int)Text[i] - 48);
            }
            k %= 16;
            k += tmp * 16;

            SetConsoleTextAttribute(hConsole, k);
        }
        else if (Text[i] == '&')
        {
            i++;
            if (((int)Text[i + 1] - 48) <= 9 && ((int)Text[i + 1] - 48) >= 0)
            {
                tmp = ((int)Text[i] - 48) * 10 + ((int)Text[i + 1] - 48);
                i++;
            }
            else
            {
                tmp = ((int)Text[i] - 48);
            }
            k /= 16;
            k *= 16;
            k += tmp;
            SetConsoleTextAttribute(hConsole, k);
        }
        else
        {
            putc(Text[i], stdout);
        }
    }
    SetConsoleTextAttribute(hConsole, ret);
}
