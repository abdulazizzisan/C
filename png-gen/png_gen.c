#include <stdio.h>
#include <stdint.h>
#include "libs/TinyPngOut.h"

#define WIDTH 400
#define HEIGHT 400

int main(){

    FILE* img = fopen("img.png", "w");
    struct TinyPngOut pngWritter;
    TinyPngOut_init(&pngWritter, WIDTH, HEIGHT, img);

    uint8_t orange[] = {255, 120, 0};
    uint8_t blue[] = {66, 135, 245};

    for(int y = 1; y <= HEIGHT; y++){
        for(int x = 1; x <= WIDTH; x++){
            if(x % 2 == 0 && y % 2 != 0){
                TinyPngOut_write(&pngWritter, orange, 1);
            }else{
                TinyPngOut_write(&pngWritter, blue, 1);
            }
            printf("x: %d, y: %d\n", x, y);
        }
    }
}
