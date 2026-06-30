#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "raylib.h"

#define WIDTH 900
#define HEIGHT 600
#define FPS 120
#define BOX_SIZE 50
#define MAX_COLORS_COUNT 21

int main(void)
{
    Color colors[MAX_COLORS_COUNT] = {
        DARKGRAY, MAROON, ORANGE, 
        DARKGREEN, DARKBLUE, DARKPURPLE, 
        DARKBROWN, GRAY, RED, 
        GOLD, LIME, BLUE, 
        VIOLET, BROWN, LIGHTGRAY, 
        PINK, YELLOW,GREEN, 
        SKYBLUE, PURPLE, BEIGE 
    };

    Color current_color = DARKGRAY;

    InitWindow(WIDTH, HEIGHT, "Bouncing Box");

    SetTargetFPS(FPS);

    bool x_rev = false;
    bool y_rev = false;

    double x = GetRandomValue(10, WIDTH / 2);
    double y = GetRandomValue(10, HEIGHT / 2);


    // ClearBackground(BLACK);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);


        DrawRectangle(x, y, BOX_SIZE, BOX_SIZE, current_color);

        EndDrawing();

        if(x == (WIDTH - BOX_SIZE) || x == 0) {
            current_color = colors[GetRandomValue(0, MAX_COLORS_COUNT - 1)];
            x_rev = !x_rev;
        }
        if(y == (HEIGHT - BOX_SIZE) || y == 0){
            current_color = colors[GetRandomValue(0, MAX_COLORS_COUNT - 1)];
            y_rev = !y_rev;
        }

        x_rev ? x-- : x++;
        y_rev ? y-- : y++;
    }

    CloseWindow();

    return 0;
}
