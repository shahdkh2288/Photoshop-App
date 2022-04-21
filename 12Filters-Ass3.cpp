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
unsigned char image2[SIZE][SIZE];
void LoadImage();
void BlackAndWhite();
void Flip();
void HorizontalFlip();
void VerticalFlip();
void DetectEdges();
void Mirror();
void LeftMirror();
void RightMirror();
void UpperMirror();
void DownMirror();
void again();

int main() {
    cout << "Ahlan ya user ya habibi :)" << endl;
    LoadImage();
    int num;   //to make user choose any filter as he likes
    cout<<"1- Black & White Filter" << endl <<"4- Flip Image" << endl <<"7- Detect Image Edges" << endl <<"a- Mirror 1/2 Image" << endl << "0.Exit" << endl;
    cin >> num;
    if(num == 1){
        BlackAndWhite();
    } else if(num == 4){
        Flip();
    }else if(num == 7){
        DetectEdges();
    }else if(num == int('a')){    //user must inter 97 ('a' in ascii =97)
        Mirror();
    }
    if(num == 0){
        return 0;
    }
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
void LoadImage() {
    char imageFileName[100];
    cout << "enter the source image file name: ";    // Get gray scale image target file name
    cin >> imageFileName;
    strcat (imageFileName, ".bmp");      // Add to it .bmp extension and load image
    readGSBMP(imageFileName,image);
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
    char imageFileName[100];
    cout<<"enter the target file name: ";     // Get gray scale image target file name
    cin>> imageFileName;
    strcat(imageFileName,".bmp");       // Add to it .bmp extension and load image
    writeGSBMP(imageFileName,image);
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
            swap(image[i][j],image[i][SIZE-j-1]);
        }
    }
    char imageFileName[100];
    cout<<"enter the target file name: ";     // Get gray scale image target file name
    cin>> imageFileName;
    strcat(imageFileName,".bmp");       // Add to it .bmp extension and load image
    writeGSBMP(imageFileName,image);
}
void VerticalFlip(){
    for(int i=0;i<SIZE/2;i++){
        for(int j=0;j<SIZE;j++){
            swap(image[i][j],image[SIZE-i-1][j]);
        }
    }
    char imageFileName[100];
    cout<<"enter the target file name: ";     // Get gray scale image target file name
    cin>> imageFileName;
    strcat(imageFileName,".bmp");       // Add to it .bmp extension and load image
    writeGSBMP(imageFileName,image);
}

void DetectEdges(){
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            if(image[i][j]>127){
                image[i][j]=255;
            }else{
                image[i][j]=0;
            }
        }
    }

    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            if(image[i][j]-image[i][j+1] !=0){
                image2[i][j]=0;
            }else if(image[i][j]-image[i-1][j] !=0){
                image2[i][j]=0;
            }else if(image[i][j]-image[i+1][j] !=0) {
                image2[i][j] = 0;
            }else{
                image2[i][j]=255;

            }
        }
    }
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeGSBMP(imageFileName, image2);
}
void Mirror(){
    char letter;
    cout<<"(l)eft" << endl << "(r)ight" << endl << "(u)pper" << endl << "(d)own side" <<endl;
    cin>>letter;  //user must enter one of these letters "l">>leftmirror","r">>rightmirror","u">>uppermirror","d">>downmirror
    for(int i=0;i<5;i++) {
        if (letter == 'l') {
            LeftMirror();
            break;
        } else if (letter == 'r') {
            RightMirror();
            break;
        } else if (letter == 'u') {
            UpperMirror();
            break;
        } else if (letter == 'd') {
            DownMirror();
            break;
        } else {
            cout << "please try again and enter one of this letters" << endl;
            main();
            break;
        }
    }

}
void LeftMirror(){
    for(int i=0; i<SIZE; i++){
        for(int j=SIZE/2; j<SIZE; j++){
            image[i][j]=image[i][SIZE-1-j];
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
void RightMirror(){
    for(int i=0; i<SIZE; i++ ){
        for(int j=0; j<SIZE/2; j++){
            image[i][j]=image[i][SIZE-j-1];
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
void UpperMirror(){
    for(int i=SIZE/2; i<SIZE; i++){
        for(int j=0;j<SIZE;j++){
            image[i][j]=image[SIZE-1-i][j];
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
void DownMirror() {
    for (int i = 0; i < SIZE/2; i++) {
        for (int j =0; j < SIZE; j++) {
            image[i][j]=image[SIZE-i-1][j];

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