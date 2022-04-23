#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.h"

using namespace std;
unsigned char colored_image[SIZE][SIZE][RGB];
unsigned char image[SIZE][SIZE];
unsigned char grey_image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE][RGB];
void loadImage ();
void BlackAndWhite ();
void readnewimage();
void Merge_Images();
void Flip();
void HorizontalFlip();
void VerticalFlip();
void again();
int main(){
    cout << "Ahlan ya user ya habibi :)" << endl;
    loadImage();
    string f;   //to make user choose any filter as he likes
    cout<<"Please select a filter to apply or 0 to exit: "<< endl <<"1- Black & White Filter" << endl << "3- Merge Filter"<< endl <<"4- Flip Image" << endl;
    cin>>f;
    if(f == "1"){
        BlackAndWhite();
    }else if(f == "3"){
        Merge_Images();
    }else if(f == "4"){
        Flip();
    }
    again();
    return 0;
}
void again() {
    string again;  //to make user do more than one filter
    cout << "you want another filter? " << endl;
    cin >> again;
    while (again == "yes") {
        main();
        break;

    }
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
void readnewimage(){
    char imageFileName[100];
    cout << "Enter the other image file name: ";       // Get gray scale image file name
    cin >> imageFileName;
    strcat (imageFileName, ".bmp");     // Add to it .bmp extension and load image
    readRGBBMP(imageFileName, image2);

}
void Merge_Images(){
    readnewimage();
    for (int i = 0; i < 256; i ++) {
        for (int j = 0;j < 256; j ++) {
            for(int y = 0;y< RGB; y ++){
                colored_image[i][j][y]+=(image2[i][j][y])/2;
            }

        }
    }
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeRGBBMP(imageFileName, colored_image);

}
void Flip(){
    cout<<"1.Horizontal"<<endl<<"2.Vertical"<<endl;
    int num;  //choosing between Horizontal Flip or Vertical flip
    cin>>num;
    for(int i=0;i<3;i++){
        if(num==1){
            HorizontalFlip();
            break;
        }
        else if(num==2){
            VerticalFlip();
            break;
        }
        else{
            cout<<"please try again and enter 1 for Horizontal Flip or 2 for Vertical Flip"<<endl;
            main();
            break;
        }
    }

}
void HorizontalFlip(){
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE/2;j++){
            for(int k=0;k<3;k++){
                swap(colored_image[i][j][k],colored_image[i][SIZE-j-1][k]);
            }
        }
    }
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeRGBBMP(imageFileName, colored_image);
}
void VerticalFlip(){
    for(int i=0;i<SIZE/2;i++){
        for(int j=0;j<SIZE;j++){
            for(int k=0;k<3;k++){
                swap(colored_image[i][j][k],colored_image[SIZE-i-1][j][k]);
            }

        }
    }
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeRGBBMP(imageFileName, colored_image);
}
