#include <stdio.h>
#include <stdbool.h>
#include "libs/TinyPngOut.h"

#define WIDTH 1000
#define HEIGHT 1000
#define BOX_SIZE 167

int main(){
    FILE* imgFile = fopen("checkered.png", "w");
    struct TinyPngOut pngWriter;

    TinyPngOut_init(&pngWriter, WIDTH, HEIGHT, imgFile);
    
    bool printRed = false;

    uint8_t red[] = {158, 0, 48};
    uint8_t yellow[] = {255, 215, 3};

    for(int y = 0; y < HEIGHT; y++){
        if(y % BOX_SIZE == 0) printRed = !printRed;
        for(int x = 0; x < WIDTH; x++){

            if(x % BOX_SIZE == 0) printRed = !printRed;

            if(printRed){
                TinyPngOut_write(&pngWriter, red, 1);
            }else{
                TinyPngOut_write(&pngWriter, yellow, 1);
            }
        }
    }
}
