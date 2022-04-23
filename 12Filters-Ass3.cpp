// FCI – Programming 1 – 2022 - Assignment 3
// Program Name: 12Filters.cpp
// Last Modification Date: 4/23/2022
// Author1 and ID and Group: shahd khaled , ID:20210182 , Group A
// Author2 and ID and Group: youssef alaa , ID:20210476 , Group:A
// Author3 and ID and Group: Marya zoher , ID:20210785 , Group: A
// Teaching Assistant: Afaf Abdelmonem
// Purpose:Task 2 assignment3
#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <fstream>
#include <cstring>
#include "bmplib.h"



using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
unsigned char newimage[SIZE][SIZE];
unsigned char new_image[SIZE][SIZE];
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
void Darken_Lighten();
void Darken();
void Lighten();
void Merge_Images();
void readnewimage();
void shrink();
void blur();
void invert();
void Rotate();
void Rotate90();
void Rotate180();
void Rotate270();
void enlarge();
void shuffle();
void saveImage();


int main() {
    cout << "Ahlan ya user ya habibi :)" << endl;
    LoadImage();
    string f;   //to make user choose any filter as he likes
    cout<<"Please select a filter to apply or 0 to exit: "<< endl <<"1- Black & White Filter" << endl <<"2- Invert Filter"<< endl <<"3- Merge Filter"<< endl <<"4- Flip Image" << endl
    <<"5- Darken and Lighten Image"<< endl <<"6- Rotate Image"<< endl <<"7- Detect Image Edges" << endl <<"8- Enlarge Image"<<
    endl <<"9- Shrink Image" << endl <<"a- Mirror 1/2 Image" << endl <<"b- Shuffle Image"<< endl <<"c- Blur Image" << endl
    <<"s- Save the image to a file"<< endl<< "0.Exit" << endl;
    cin >> f;
    if(f == "1"){
        BlackAndWhite();
    }else if(f == "2"){
        invert();
    }else if(f == "3"){
        Merge_Images();
    }else if(f == "4"){
        Flip();
    }else if(f == "5"){
        Darken_Lighten();
    }else if(f == "6"){
        Rotate();
    }else if(f == "7"){
        DetectEdges();
    }else if(f == "8"){
        enlarge();
    }else if(f == "9"){
        shrink();
    }else if(f == "a"){    
        Mirror();
    }else if(f == "b"){    
        shuffle();
    }else if(f == "c"){    
        blur();
    }else if(f == "s"){    
        saveImage();
    }else if(f == "0"){
        return 0;
    }
    again();

}
void again(){
    string again;  //to make user do more than one filter
    cout<<"you want another filter? "<<endl;
    cin>>again;
    while(again == "yes"){
        main();
        break;
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


void Darken_Lighten(){
    string text;
    cout<<"Darken or Lighten: ";
    cin>>text;
    if (text=="Darken") {
        Darken();
    }
    else if(text=="Lighten") {
        Lighten();
    }
}

void Darken() {
    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < 256; j++) {
            if (image[i][j] >= 127) {
                image[i][j] -= 63;
            }
        }
    }
    char imageFileName[100];
    cout<<"enter the target file name";     // Get gray scale image target file name
    cin>> imageFileName;
    strcat(imageFileName,".bmp");       // Add to it .bmp extension and load image
    writeGSBMP(imageFileName,image);
}
void Lighten(){
    for (int i = 0; i < 256; i ++) {
        for (int j = 0; j < 256; j ++) {
            if(image[i][j]<=127){
                image[i][j]+=63;
            }
        }
    }
    char imageFileName[100];
    cout<<"enter the target file name";     // Get gray scale image target file name
    cin>> imageFileName;
    strcat(imageFileName,".bmp");       // Add to it .bmp extension and load image
    writeGSBMP(imageFileName,image);
}

void readnewimage(){
    char imageFileName[100];
    cout << "Please enter name of image file to merge with: ";       // Get gray scale image file name
    cin >> imageFileName;
    strcat (imageFileName, ".bmp");     // Add to it .bmp extension and load image
    readGSBMP(imageFileName, newimage);
}

void Merge_Images(){
    readnewimage();
    for (int i = 0; i < 256; i ++) {
        for (int j = 0;j < 256; j ++) {
            image[i][j]=(image[i][j]+newimage[i][j])/2;
        }
    }
    char imageFileName[100];
    cout<<"enter the target file name: ";     // Get gray scale image target file name
    cin>> imageFileName;
    strcat(imageFileName,".bmp");       // Add to it .bmp extension and load image
    writeGSBMP(imageFileName,image);
}

void shrink()
{
    int shr;
    cout<<"2.Shrink 1/2"<<endl<<
          "3.Shrink 1/3"<<endl<<
          "4.Shrink 1/4"<<endl<<"enter: ";
    cin>>shr;
    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < 256; j++) {
            if (i != 0) {
                for (int z = i; z <= 256 - i; z++) {
                    if (z == 256 - i) {
                        image[z][j] = 255;
                    }
                    else {
                        image[z][j] = image[z + shr][j];
                    }
                }
            }

        }
    }
    for (int i = 0; i < 256 / 2; i++) {
        for (int j = 0; j < 256; j++) {
            if (j != 0) {
                for (int z = j; z <= 256 - j; z++) {
                    if (z == 256 - j) {
                        image[i][z] = 255;
                    }
                    else {
                        image[i][z] = image[i][z + shr];
                    }
                }
            }
        }
    }
    char imageFileName[100];
    cout<<"enter the target file name: ";
    cin>> imageFileName;
    strcat(imageFileName,".bmp");
    writeGSBMP(imageFileName,image);
}

void blur()
{
    int sum=0;
    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < 256; j++) {
        if((i!=0||i!=255)&&(j!=0||j!=255)){
            sum=(image[i][j]+image[i+1][j]+image[i-1][j]+image[i][j+1]+image[i][j-1]+image[i+1][j+1]+image[i-1][j-1]+image[i+1][j-1]+image[i-1][j+1])/9;
            new_image[i][j]=sum;
        }
        }
    }
    char imageFileName[100];
    cout<<"enter the target file name: ";
    cin>> imageFileName;
    strcat(imageFileName,".bmp");
    writeGSBMP(imageFileName,new_image);
}

void invert()
{
    for(int i = 0 ; i < SIZE ; i ++)
    {
        for(int j = 0;j<SIZE;j++)
        {
            image[i][j]=255-image[i][j];
        }
    }
    char imageFileName[100];
    cout<<"enter the target file name";     // Get gray scale image target file name
    cin>> imageFileName;
    strcat(imageFileName,".bmp");       // Add to it .bmp extension and load image
    writeGSBMP(imageFileName,image);
}


void Rotate()
{
    int rotate;
    cout<<"Rotate (90) or (180) or (270): ";
    cin>>rotate;
    if(rotate==90)
    {
        Rotate90();
    }
    else if(rotate==180)
    {
        Rotate180();
    }
    else if(rotate == 270)
    {
        Rotate270();
    }
}
void Rotate90()
{
    for (int i = 0; i < 256; i++) {
        for (int j = 0, m = 256 - 1; j < m; j++, m--) {

            swap(image[j][i], image[m][i]);
        }
    }
    for (int i = 0; i < 256; i++) {
        for (int j = i; j < 256; j++) {
            swap(image[i][j], image[j][i]);
        }
    }
    char imageFileName[100];
    cout<<"enter the target file name";     // Get gray scale image target file name
    cin>> imageFileName;
    strcat(imageFileName,".bmp");       // Add to it .bmp extension and load image
    writeGSBMP(imageFileName,image);
}
void Rotate180()
{

    for(int i=0;i<256;i++){
        for(int j=i;j<256;j++){
            swap(image[i][j],image[j][i]);
        }
    }
    for(int i=0;i<256;i++){
        for(int j=0;j<256-i;j++){
            swap(image[i][j],image[256-1-j][256-1-i]);
        }
    }
    char imageFileName[100];
    cout<<"enter the target file name";     // Get gray scale image target file name
    cin>> imageFileName;
    strcat(imageFileName,".bmp");       // Add to it .bmp extension and load image
    writeGSBMP(imageFileName,image);
}
void Rotate270() {
    for (int i = 0; i < 256; i++) {
        for (int j = i + 1; j < 256; j++) {
            swap(image[i][j], image[j][i]);
        }
    }
    {
        for (int i = 0; i < 256; i++) {
            for (int j = i + 1; j < 256; j++) {
                swap(image[j][i], image[i][j]);
            }
        }
    }
    char imageFileName[100];
    cout<<"enter the target file name";     // Get gray scale image target file name
    cin>> imageFileName;
    strcat(imageFileName,".bmp");       // Add to it .bmp extension and load image
    writeGSBMP(imageFileName,image);
}

void enlarge(){
    int q;
    cout<<"Enter the quarter num: ";
    cin>>q;
    cout<<endl;
    if(q==1) {
        for (int i = 0, R = 0; i < 128; i++) {          //R is a counter for new_image rows
            for (int j = 0, C = 0; j < 128; j++) {      //C is a counter for new_image columns
                new_image[R][C] = image[i][j];
                new_image[R + 1][C] = image[i][j];
                new_image[R][C + 1] = image[i][j];
                new_image[R + 1][C + 1] = image[i][j];
                C += 2;
            }
            R += 2;
        }
    }
    else if(q==2){
        for (int i = 0, R = 0; i < 128; i++) {
            for (int j = 128, C = 0; j < 256; j++) {
                new_image[R][C] = image[i][j];
                new_image[R + 1][C] = image[i][j];
                new_image[R][C + 1] = image[i][j];
                new_image[R + 1][C + 1] = image[i][j];
                C += 2;
            }
            R += 2;
        }
    }
    else if(q==3){
        for (int i = 128, R = 0; i < 256; i++) {
            for (int j = 0, C = 0; j < 128; j++) {
                new_image[R][C] = image[i][j];
                new_image[R + 1][C] = image[i][j];
                new_image[R][C + 1] = image[i][j];
                new_image[R + 1][C + 1] = image[i][j];
                C += 2;
            }
            R += 2;
        }
    }
    else if(q==4){
        for (int i = 128, R = 0; i < 256; i++) {
            for (int j = 128, C = 0; j < 256; j++) {
                new_image[R][C] = image[i][j];
                new_image[R + 1][C] = image[i][j];
                new_image[R][C + 1] = image[i][j];
                new_image[R + 1][C + 1] = image[i][j];
                C += 2;
            }
            R += 2;
        }
    }
    char imageFileName[100];
    cout<<"enter the target file name: ";
    cin>> imageFileName;
    strcat(imageFileName,".bmp");
    writeGSBMP(imageFileName,new_image);
}


void MoveQ(int m, int i, int j ) {
    int t = j;
    if (m == 1) {
        for (int x = 0; x < 128; i++, x++) {
            j = t;
            for (int z = 0; z < 128; j++, z++)
                new_image[i][j] = image[x][z];
        }
    }
    else if (m == 2){
        for (int x = 0; x < 128; i++, x++) {
            j = t;
            for (int z = 128; z < 256; j++, z++)
                new_image[i][j] = image[x][z];
        }
    }else if (m ==3) {
        for (int x = 128; x < 256; i++, x++) {
            j = t;
            for (int z = 0; z < 128; j++, z++)
                new_image[i][j] = image[x][z];
        }
    }else if (m ==4) {
        for (int x = 128; x < 256; i++, x++) {
            j = t;
            for (int z = 128; z < 256; j++, z++)
                new_image[i][j] = image[x][z];
        }
    }
}
void shuffle() {
    int n;
    cout << "Enter the order of quadrants: ";
    for (int i = 0; i < 4; i++) {
        cin >> n;
        if (i == 0) MoveQ(n, 0, 0);
        else if (i == 1) MoveQ(n, 0, 128);
        else if (i == 2) MoveQ(n, 128, 0);
        else if (i == 3) MoveQ(n, 128, 128);
    }
    char imageFileName[100];
    cout<<"enter the target file name";
    cin>> imageFileName;
    strcat(imageFileName,".bmp");
    writeGSBMP(imageFileName,new_image);
}

void saveImage(){
    char imageFileName[100];
    cout<<"enter the target file name";     // Get gray scale image target file name
    cin>> imageFileName;
    strcat(imageFileName,".bmp");       // Add to it .bmp extension and load image
    writeGSBMP(imageFileName,image);
}
