#include <iostream>
#include <chrono>
#include <cmath>
#if _WIN32
#include <windows.h>
#endif


using namespace std;


class Screen
{
public:
    Screen()
    {
#ifdef _WIN32
        _hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
#endif
        hideCursor();
        saveCursorPosition();
    }


    void clear()
    {
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                _screen[i][j] = 'x';
            }
        }
    }


    void draw(char value, float x, float y)
    {
        int xPos = lround(x);
        int yPos = lround(y);
        if (xPos < width && yPos < height)
        {
            _screen[yPos][xPos] = value;
        }
    }


    void flush()
    {
        restoreCursorPosition();


        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (_screen[i][j] != 'x')
                {
                    setRedFont();
                }
                else
                {
                    setWhiteFont();
                }
                cout << _screen[i][j];
            }
            cout << "\n";
        }
    }


private:
    void hideCursor()
    {
#ifdef _WIN32
        CONSOLE_CURSOR_INFO cursorInfo;
        GetConsoleCursorInfo(_hConsole, &cursorInfo);
        cursorInfo.dwSize = 1;
        cursorInfo.bVisible = FALSE;
        SetConsoleCursorInfo(_hConsole, &cursorInfo);
#else
        cout << "\33[?25l";//disable cursor
#endif


    }


    void saveCursorPosition()
    {
#ifdef _WIN32
        CONSOLE_SCREEN_BUFFER_INFO coninfo;
        GetConsoleScreenBufferInfo(_hConsole, &coninfo);
        _prevPos = coninfo.dwCursorPosition;
#else
        cout << "\33[s";
#endif

    }


    void restoreCursorPosition()
    {
#ifdef _WIN32
        SetConsoleCursorPosition(_hConsole, _prevPos);
#else
        cout << "\338";
#endif
    }


    void setRedFont()
    {
#ifdef _WIN32
        WORD attributes = FOREGROUND_RED;
        SetConsoleTextAttribute(_hConsole, attributes);
#else
        cout << "\33[31m";//red color
#endif
    }


    void setWhiteFont()
    {
#ifdef _WIN32
        WORD attributes = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
        SetConsoleTextAttribute(_hConsole, attributes);
#else
        cout << "\33[37m";//white color
#endif
    }


    static constexpr int width{ 60 };
    static constexpr int height{ 20 };
    char _screen[height][width];
#ifdef _WIN32
    HANDLE _hConsole;
    COORD _prevPos;
#endif
};


struct Position
{
    float x;
    float y;

    Position operator+(const Position& other) const
    {
        return Position{ x + other.x, y + other.y };
    }

    Position operator-(const Position& other) const
    {
        return Position{ x - other.x, y - other.y };
    }

    Position operator*(float f) const
    {
        return { x * f, y * f };
    }

    Position& operator=(const Position& other)
    {
        x = other.x;
        y = other.y;
        return *this;
    }
};


using Pixel = char;


class Engine
{
public:
    Engine(int rep = 5) : rep(rep) {}

    void update(chrono::milliseconds deltaTime)
    {
        if (rep > 0)
        {
            if (time < pathTimes[0])
                calcPosition(positions[0], positions[1], 0ms, time, pathTimes[0]);
            else if (time < (pathTimes[0] + pathTimes[1]))
                calcPosition(positions[1], positions[2], pathTimes[0], time, pathTimes[1]);
            else if (time < (pathTimes[0] + pathTimes[1] + pathTimes[2]))
                calcPosition(positions[2], positions[0], pathTimes[0] + pathTimes[1], time, pathTimes[2]);
            else
            {
                rep--;
                time = 0ms;
            }

            time += deltaTime;
        }
    }

    void render(Screen& screen)
    {
        screen.draw(pixel, position.x, position.y);
    }
private:
    void calcPosition(Position p0, Position p1, chrono::milliseconds time0, chrono::milliseconds time, chrono::milliseconds pathTime)
    {
        float percent = calcPercentOfPath(pathTime, time0, time);
        position = p0 + (p1 - p0) * percent;
    }

    float calcPercentOfPath(const chrono::milliseconds& pathTime, const chrono::milliseconds& time0, const chrono::milliseconds& time)
    {
        return static_cast<float>((time - time0).count()) / static_cast<float>(pathTime.count());
    }

    Pixel pixel{ 1 };
    Position position{ 0.0f, 0.0f };
    const Position positions[3]{ { 0.0f, 0.0f }, { 40.0f, 0.0f }, { 40.0f, 10.0f } }; //A, B, C
    const chrono::milliseconds pathTimes[3]{ std::chrono::milliseconds(2000), std::chrono::milliseconds(3000), std::chrono::milliseconds(1000) }; // A->B, B->C, C->A
    int rep;
    chrono::milliseconds time = 0ms;
};


int main()
{
    Engine engine;
    Screen screen;


    auto startTime = chrono::high_resolution_clock::now();
    while (1)
    {
        auto now = chrono::high_resolution_clock::now();
        auto deltaTime = chrono::duration_cast<chrono::milliseconds>(now - startTime);
        if (deltaTime >= 20ms)
        {
            screen.clear();
            engine.update(deltaTime);
            engine.render(screen);
            screen.flush();
            startTime = now;
        }
    }


    return 0;
}