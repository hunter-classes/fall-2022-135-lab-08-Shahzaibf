/*
Author: Shahzaib Fareed
Course: CSCI-135
Instructor: Zamansky
Assignment: Lab 8

funcs for the lab.
*/
#include <iostream>
#include "imageio.h"

void invert(std::string fileimg, int image[MAX_H][MAX_W]){
    int h;
    int w;
    readImage(fileimg, image, h, w);

    for (int i = 0; i < h; i++)
        for(int j = 0; j < w;j++)
            image[i][j] = 255 - image[i][j];

    writeImage("taskA.pgm", image, h, w);

}

void invert_half(std::string fileimg, int image[MAX_H][MAX_W]){
    int h;
    int w;
    readImage(fileimg, image, h, w);

    for (int i = 0; i < h; i++)
        for (int j = w/2; j < w; j++)
            image[i][j] = 255 - image[i][j];
    
    writeImage("taskB.pgm", image, h, w);
}

void box(std::string fileimg, int image[MAX_H][MAX_W]){
    int h;
    int w;
    readImage(fileimg, image, h, w);
    
    for(int i = 0;i < h;i++){
        for(int j = 0;j < w;j++){//i is row j is col
            if(i >= h/4 && i <= h*3/4 && j >= w/4 && j <= w*3/4){
                image[i][j] = 255;
            }
        }
    }
    writeImage("taskC.pgm", image, h, w);
}

void frame(std::string fileimg, int image[MAX_H][MAX_W]){
    int h;
    int w;
    readImage(fileimg, image, h, w);

    for (int i = 0;i < h;i++){
        for(int j = 0; j < w;j++){
            if(i == h/4 && j >= w/4 && j <= w*3/4){
                image[i][j] = 255;
            }
            else if(i == h*3/4 && j >= w/4 && j <= w*3/4){
                image[i][j] = 255;
            }
            else if(j == w/4 && i >= h/4 && i <= h*3/4){
                image[i][j] = 255;
            }
            else if(j == w*3/4 && i >= h/4 && i <= h*3/4){
                image[i][j] = 255;
            }
        }
    }

    writeImage("taskD.pgm", image, h, w);
}

void scale(std::string fileimg, int image[MAX_H][MAX_W]){
    int h;
    int w;
    readImage(fileimg, image, h, w);

    int result[MAX_H][MAX_W];
    int x;
    int y;
    for(int i = 0; i <= h;i++){
        x = 0;
        for (int j = 0; j <= w;j++){
            x = 2 * i;
            y = 2 * j;
            result[x][y] = image[i][j];
            result[x + 1][y] = image[i][j];
            result[x][y + 1] = image[i][j];
            result[x + 1][y + 1] = image[i][j];
        }
        y += 2;
    }
    writeImage("taskE.pgm", result, h * 2, w * 2);
}

void pixelate(std::string fileimg, int image[MAX_H][MAX_W]){
    int h;
    int w;
    int average;
    readImage(fileimg, image, h, w);

    for(int i = 0;i < h; i+=2){
        for(int j = 0;j < w;j+=2){
            average = (image[i][j] + image[i+1][j] + image[i][j+1] + image[i+1][j+1]) / 4;
            image[i][j] = average;
            image[i + 1][j] = average;
            image[i][j + 1] = average;
            image[i + 1][j + 1] = average;
        }
    }
    writeImage("taskF.pgm", image, h, w);
}