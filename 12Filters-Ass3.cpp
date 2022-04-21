// FCI – Programming 1 – 2022 - Assignment 3
// Program Name: 12Filters.cpp
// Last Modification Date: 21/4/2022
// Author1 and ID and Group: shahd khaled , ID:20210182 , Group A
// Author2 and ID and Group: youssef alaa , ID:20210476 , Group:A
// Author3 and ID and Group: Marya zoher , ID:20210785 , Group: A
// Teaching Assistant: Afaf Abdelmonem
// Purpose:Task 2 assignment3
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.h"


using namespace std;
unsigned char image[SIZE][SIZE];

void ReadImage();
void saveImage();
void BlackAndWhite();
void Flip();
void HorizontalFlip();
void VerticalFlip();
void again();

int main() {
    cout << "Ahlan ya user ya habibi :)" << endl;
    ReadImage();
    int num;   //to make user choose any filter as he likes
    cout<<"1.Black and White" << endl <<"2.Flip" << endl << "0.Exit" << endl;
    cin >> num;
    if(num == 1){
        BlackAndWhite();
    } else if(num == 2){
        Flip();
    }
    if(num == 0){
        return 0;
    }
    saveImage();
    again();

}
void again(){
    string again;  //to make user do more than one filter
    cout<<"you want another filter? "<<endl;
    cin>>again;
    if (again == "yes") {
        main();
    }
}
void ReadImage() {
    char imageFileName[100];
    cout << "enter the source image file name: ";    // Get gray scale image target file name
    cin >> imageFileName;
    strcat (imageFileName, ".bmp");      // Add to it .bmp extension and load image
    readGSBMP(imageFileName,image);
}
void saveImage(){
    char imageFileName[100];
    cout<<"enter the target file name";     // Get gray scale image target file name
    cin>> imageFileName;
    strcat(imageFileName,".bmp");       // Add to it .bmp extension and load image
    writeGSBMP(imageFileName,image);
}
void BlackAndWhite(){
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            if(image[i][j]>127)
                image[i][j]=255;  //255>>White
            else
                image[i][j]=0; //0>>Black

        }
    }
}

void Flip(){
    cout<<"1.Horizontal"<<endl<<"2.Vertical"<<endl;
    int num;  //choosing between Horizontal Flip or Vertical flip
    cin>>num;
    if(num==1){
        HorizontalFlip();
    }
    else if(num==2){
        VerticalFlip();
    }

}
void HorizontalFlip(){
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE/2;j++){
            swap(image[i][j],image[i][SIZE-j-1]);
        }
    }
}
void VerticalFlip(){
    for(int i=0;i<SIZE/2;i++){
        for(int j=0;j<SIZE;j++){
            swap(image[i][j],image[SIZE-i-1][j]);
        }
    }
}