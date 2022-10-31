/*
Author: Shahzaib Fareed
Course: CSCI-135
Instructor: Zamansky
Assignment: Lab 8

Lab changes images after reading them.
Inverts colors, adds a white box, scales, etc.
*/
#include <iostream>
#include "imageio.h"
#include "funcs.h"

int main(){
    int image[MAX_H][MAX_W];
    std::string img = "inImage.pgm";
    invert(img, image);
    invert_half(img, image);
    box(img, image);
    frame(img, image);
    scale(img, image);
    pixelate(img, image);

    return 0;
}