#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.h"

using namespace std;
unsigned char colored_image[SIZE][SIZE][RGB];
unsigned char image[SIZE][SIZE];
unsigned char grey_image[SIZE][SIZE];
void loadImage ();

void BlackAndWhite ();
int main(){
    loadImage();
    BlackAndWhite();
    return 0;
}
void loadImage () {
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readRGBBMP(imageFileName, colored_image);
}

void BlackAndWhite(){
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            grey_image[i][j]=(colored_image[i][j][0]* 0.299) + (colored_image[i][j][1]* 0.587) + (colored_image[i][j][2]*0.114);
            image[i][j]+=grey_image[i][j];
        }
    }
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            if(image[i][j]>127){
                image[i][j]=255;
            }else{
                image[i][j]=0;
            }
        }
    }
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeGSBMP(imageFileName, image);

}