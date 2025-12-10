#include "raylib.h"

#define MAP_W 12
#define MAP_H 20

int map[MAP_H][MAP_W] =
{
    {1,1,1,0,0,0,0,0,0,1,1,1},
    {1,1,0,0,0,0,0,0,0,0,1,1},
    {1,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,5,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,4,0,0,0,4,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,3,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,5,0,0,0,0,1},

    {1,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,4,0,0,0,0,4,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,5,0,0,0,0,0,0,1},
    {1,1,0,0,0,0,0,0,0,0,1,1},
    {1,1,1,0,0,0,0,0,0,1,1,1},
    {1,1,1,1,0,0,0,0,1,1,1,1},
    {1,1,1,1,1,0,0,1,1,1,1,1},
    {1,1,1,1,1,1,0,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1}
};

void draw()
{
    for (int y = 0; y < MAP_H; y++)
    {
        for (int x = 0; x < MAP_W; x++)
        {
            int tile = map[y][x];

            Color c = BLUE;

            if (tile == 1) c = DARKBROWN;
            else if (tile == 3) c = YELLOW;
            else if (tile == 4) c = RED;
            else if (tile == 5) c = GREEN;

            DrawRectangle(x * 40, y * 40, 40, 40, c);
        }
    }
}

int main(void)
{
    InitWindow(480, 800, "River Raid");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
