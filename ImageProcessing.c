#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

static FILE *inputFile;
static FILE *outputFile;

int redChannel() {
    inputFile = fopen("Cat.bmp", "rb");
    if (inputFile == NULL) {
        printf("The file cannot be found\n");
    }
    
    outputFile = fopen("Red.bmp", "wb");
    if (inputFile == NULL) {
        printf("The file cannot be found\n");
    }
    char header[122];
    fread(&header, sizeof(char), 122, inputFile); /*extract header from the input file*/
    fwrite(&header, sizeof(char), 122, outputFile);
    
    int width = *(int*)&header[18]; //get width information
    int height = abs(*(int*)&header[22]); //get height information*/
    int stride = ((4 * ((8 * 3)*width) + 31) / 32); //calculate row size
    int paddingCheck = (stride % 4);
    int padding;
    if (paddingCheck != 0) { //if stride is not divisible by
        int padCalc = 0;
        for (int i = 1;padCalc < stride;i++) {
            padCalc = i * 4;
        }
        padding = padCalc - stride;
    }
    else
        padding = 0;
    
    char pad;
    char pixel[3];
    for (int j = 0;j < height;j++) {
        for (int k = 0;k < width;k++) {
            fread(pixel, sizeof(char), 3, inputFile); //read rbg info and store in pixel buffer
            /*GET THE RED ONLY*/
            pixel[0] = 0;
            pixel[1] = 0;
            fwrite(&pixel, (sizeof(char)), 3, outputFile);//*use pixel buffer's info to write back to my output file
        }
        for (int l = 0;l < padding; l++) { //read the padding at the end
            fread(&pad, 1, 1, inputFile); //read padding info from the file
            fwrite(&pad, 1, 1, outputFile); //write padding info to the file
        }
    }
    int elms_read; /*make sure no empty pixels are being read */
    while (1) {
        elms_read = fread(&pad, 1, 1, inputFile);
        if (elms_read == 0) {
            break;
        }
        else {
            fwrite(&pad, 1, 1, outputFile);
        }
    }
    fclose(inputFile);
    fclose(outputFile);
    return 1;
}

int greenChannel() {
    inputFile = fopen("Cat.bmp", "rb");
    if (inputFile == NULL) {
        printf("The file cannot be found\n");
    }
    
    outputFile = fopen("Sample_0_Green.bmp", "wb");
    if (inputFile == NULL) {
        printf("The file cannot be found\n");
    }
    char header[54];
    fread(&header, sizeof(char), 54, inputFile); /*extract header from the input file*/
    fwrite(&header, sizeof(char), 54, outputFile);
    
    int width = *(int*)&header[18]; //get width information
    int height = abs(*(int*)&header[22]); //get height information*/
    int stride = (4 * ((8 * 3)*width) / 32); //calculate row size
    int paddingCheck = (stride % 4);
    int padding;
    if (paddingCheck != 0) { //if stride is not divisible by
        int padCalc = 0;
        for (int i = 1;padCalc < stride;i++) {
            padCalc = i * 4;
        }
        padding = padCalc - stride;
    }
    else
        padding = 0;
    
    char pad;
    char pixel[3];
    for (int j = 0;j < height;j++) {
        for (int k = 0;k < width;k++) {
            fread(pixel, sizeof(char), 3, inputFile); //read rbg info and store in pixel buffer
            /*GET THE GREEN ONLY*/
            //pixel[0] = 0;
            pixel[1] = 0;
            pixel[2] = 0;
            fwrite(&pixel, (sizeof(char)), 3, outputFile);//*use pixel buffer's info to write back to my output file
        }
        for (int l = 0;l < padding; l++) { //read the padding at the end
            fread(&pad, 1, 1, inputFile); //read padding info from the file
            fwrite(&pad, 1, 1, outputFile); //write padding info to the file
        }
    }
    int elms_read; /*make sure no empty pixels are being read */
    while (1) {
        elms_read = fread(&pad, 1, 1, inputFile);
        if (elms_read == 0) {
            break;
        }
        else {
            fwrite(&pad, 1, 1, outputFile);
        }
    }
    fclose(inputFile);
    fclose(outputFile);
    return 1;
}

int blueChannel() {
    inputFile = fopen("Cat.bmp", "rb");
    if (inputFile == NULL) {
        printf("The file cannot be found\n");
    }
    
    outputFile = fopen("Sample_0_Blue.bmp", "wb");
    if (inputFile == NULL) {
        printf("The file cannot be found\n");
    }
    char header[54];
    fread(&header, sizeof(char), 54, inputFile); /*extract header from the input file*/
    fwrite(&header, sizeof(char), 54, outputFile);
    
    int width = *(int*)&header[18]; //get width information
    int height = abs(*(int*)&header[22]); //get height information*/
    int stride = (4 * ((8 * 3)*width) / 32); //calculate row size
    int paddingCheck = (stride % 4);
    int padding;
    if (paddingCheck != 0) { //if stride is not divisible by
        int padCalc = 0;
        for (int i = 1;padCalc < stride;i++) {
            padCalc = i * 4;
        }
        padding = padCalc - stride;
    }
    else
        padding = 0;
    
    char pad;
    char pixel[3];
    for (int j = 0;j < height;j++) {
        for (int k = 0;k < width;k++) {
            fread(pixel, sizeof(char), 3, inputFile); //read rbg info and store in pixel buffer
            /*GET THE GREEN ONLY*/
            pixel[0] = 0;
            pixel[1] = 0;
            //pixel[2] = 0;
            fwrite(&pixel, (sizeof(char)), 3, outputFile);//*use pixel buffer's info to write back to my output file
        }
        for (int l = 0;l < padding; l++) { //read the padding at the end
            fread(&pad, 1, 1, inputFile); //read padding info from the file
            fwrite(&pad, 1, 1, outputFile); //write padding info to the file
        }
    }
    int elms_read; /*make sure no empty pixels are being read */
    while (1) {
        elms_read = fread(&pad, 1, 1, inputFile);
        if (elms_read == 0) {
            break;
        }
        else {
            fwrite(&pad, 1, 1, outputFile);
        }
    }
    fclose(inputFile);
    fclose(outputFile);
    return 1;
}

int greyScale() {
    inputFile = fopen("Cat.bmp", "rb");
    if (inputFile == NULL) {
        printf("The file cannot be found\n");
    }
    
    outputFile = fopen("REEE.bmp", "wb");
    if (inputFile == NULL) {
        printf("The file cannot be found\n");
    }
    
    char header[54];
    fread(&header, sizeof(char), 54, inputFile); /*extract header from the input file*/
    fwrite(&header, sizeof(char), 54, outputFile);
    
    int width = *(int*)&header[18]; //get width information
    int height = abs(*(int*)&header[22]); //get height information*/
    int stride = (4 * ((8 * 3)*width + 31) / 32); //calculate row size
    int paddingCheck = (stride % 4);
    int padding;
    if (paddingCheck != 0) { //if stride is not divisible by
        int padCalc = 0;
        for (int i = 1;padCalc < stride;i++) {
            padCalc = i * 4;
        }
        padding = padCalc - stride;
    }
    else
        padding = 0;
    
    char pad;
    unsigned char pixel[3];
    unsigned char pixelEdit[3];
    for (int j = 0;j < height;j++) {
        for (int k = 0;k < width;k++) {
            fread(pixel, sizeof(unsigned char), 3, inputFile); //read rbg info and store in pixel buffer
            /*GET THE GREYSCALE ONLY*/
            unsigned char avg = (pixel[0] + pixel[1] + pixel[2]) / (unsigned char)3;
            pixelEdit[0] = pixelEdit[1] = pixelEdit[2] = avg;
            
            fwrite(&pixelEdit, (sizeof(unsigned char)), 3, outputFile);//*use pixel buffer's info to write back to my output file
        }
        for (int l = 0;l < padding; l++) { //read the padding at the end
            fread(&pad, 1, 1, inputFile); //read padding info from the file
            fwrite(&pad, 1, 1, outputFile); //write padding info to the file
        }
    }
    int elms_read; /*make sure no empty pixels are being read */
    while (1) {
        elms_read = fread(&pad, 1, 1, inputFile);
        if (elms_read == 0) {
            break;
        }
        else {
            fwrite(&pad, 1, 1, outputFile);
        }
    }
    fclose(inputFile);
    fclose(outputFile);
    return 1;
}

int blackWhite() {
    inputFile = fopen("Cat.bmp", "rb");
    if (inputFile == NULL) {
        printf("the file cannot be found\n");
    }
    
    outputFile = fopen("black and white.bmp", "wb");
    if (inputFile == NULL) {
        printf("the file cannot be found\n");
    }
    
    char header[122];
    fread(header, sizeof(char), 122, inputFile); /*extract header from the input file*/
    fwrite(header, sizeof(char), 122, outputFile);
    
    int width = *(int*)&header[18]; //get width information
    int height = abs(*(int*)&header[22]); //get height information*/
    int stride = (4 * ((8 * 3)*width) / 32); //calculate row size
    int paddingcheck = (stride % 4);
    int padding;
    if (paddingcheck != 0) { //if stride is not divisible by 4
        int padcalc = 0;
        for (int i = 1;padcalc < stride;i++) {
            padcalc = i * 4;
        }
        padding = padcalc - stride;
    }
    else
        padding = 0;
    
    char pad;
    unsigned char pixel[3];
    unsigned char pixeledit[3];
    for (int j = 0;j < height;j++) {
        for (int k = 0;k < width;k++) {
            fread(pixel, sizeof(unsigned char), 3, inputFile); //read rbg info and store in pixel buffer
            /*get the black and white only*/
            unsigned char avg = (pixel[0] + pixel[1] + pixel[2]) / 3;
            if (avg > (unsigned char)127) {
                pixeledit[0] = pixeledit[1] = pixeledit[2] = 255;
            }
            else {
                pixeledit[0] = pixeledit[1] = pixeledit[2] = 0;
            }
            fwrite(&pixeledit, (sizeof(char)), 3, outputFile);//*use pixel buffer's info to write back to my output file
        }
        for (int l = 0;l < padding; l++) { //read the padding at the end
            fread(&pad, 1, 1, inputFile); //read padding info from the file
            fwrite(&pad, 1, 1, outputFile); //write padding info to the file
        }
    }
    int elms_read; /*make sure no empty pixels are being read */
    while (1) {
        elms_read = fread(&pad, 1, 1, inputFile);
        if (elms_read == 0) {
            break;
        }
        else {
            fwrite(&pad, 1, 1, outputFile);
        }
    }
    fclose(inputFile);
    fclose(outputFile);
    return 1;
}

int map(int r, int c, int width) {
    return r * width + c;
}

int blurChannel() {
    inputFile = fopen("Cat.bmp", "rb");
    if (inputFile == NULL) {
        printf("The file cannot be found\n");
    }
    outputFile = fopen("BLUR BOI.bmp", "wb"); /*this is to check if I read the image correctly*/
    if (outputFile == NULL) {
        printf("The file cannot be found\n");
    }
    
    char header[122];
    fread(&header, sizeof(char), 122, inputFile); /*extract header from the input file*/
    fwrite(&header, sizeof(char), 122, outputFile);
    
    int width = *(int*)&header[18]; //get width information
    int height = abs(*(int*)&header[22]); //get height information*/
    int stride = (4 * ((8 * 3)*width) / 32); //calculate row size
    int paddingCheck = stride % 4;
    int padding;
    if (paddingCheck != 0) { //if stride is not divisible by
        int padCalc = 0;
        for (int i = 1;padCalc < stride;i++) {
            padCalc = i * 4;
        }
        padding = padCalc - stride;
    }
    else
        padding = 0;
    
    int width_two = (width * 3) + padding;
    //printf("%d", width_two);
    
    
    
    //unsigned char onePixel[3];
    
    unsigned char *image = malloc(width_two*height * sizeof(unsigned char));
    unsigned char *writeBlur = malloc(width_two*height * sizeof(unsigned char));
    fread(image, sizeof(unsigned char), width_two*height, inputFile);
    //struct Pixel **image;
    //image = (struct Pixel**) malloc(height * width_two *sizeof(struct Pixel*));
    
    //for (int i = 0; i < height * width_two; i+=3) {
    //		fread(onePixel, 3, 1, inputFile);
    /*	image[i] = (struct Pixel*) malloc(sizeof(struct Pixel));
     image[i]->blue = onePixel[0];
     printf("%d", image[i]->blue);
     image[i]->green = onePixel[1];
     printf("%d", image[i]->green);
     image[i]->red = onePixel[2];
     printf("%d", image[i]->red)*/;
    //}
    //char buffer = 0;
    int count = 0;
    unsigned int total_red = 0, total_green = 0, total_blue = 0;
    for (int i = 0; i < height; i++) { // i is storing the row
        for (int j = 0; j < width_two; j += 3) { // j is storing the colums
            
            int count = 0;
            unsigned int total_red = 0;
            unsigned int total_green = 0;
            unsigned int total_blue = 0;
            
            for (int k = i - 3; k < i + 4; k++) { // k is the row of the subarray
                for (int l = j - 9; l < j + 10; l += 3) { // l is the column of the subarray
                    //printf("%d %d\n", k, l);
                    if (k >= 0 && k < height && l >= 0 && l < width_two) { /*check if row and column index is greater than 0 less than the max height/width (not out of bounds)*/
                        
                        int index = map(k, l, width_two);
                        
                        total_red += image[index + 1];
                        total_green += image[index + 2];
                        total_blue += image[index];
                        count++;
                        
                    }
                }
                
            }
            
            //printf("%d", count);
            //struct Pixel point;
            int index = map(i, j, width_two);
            writeBlur[index] = (unsigned char)(total_blue / count);
            writeBlur[index + 1] = (unsigned char)(total_red / count);
            writeBlur[index + 2] = (unsigned char)(total_green / count);
            /*fwrite(&point.blue, (sizeof(unsigned char)), 1, outputFile);
             fwrite(&point.green, (sizeof(unsigned char)), 1, outputFile);
             fwrite(&point.red, (sizeof(unsigned char)), 1, outputFile);*/
            
            
            /*}
             for (int z = 0; z < padding;z++) {
             fwrite(&buffer, (sizeof(unsigned char)), 1, outputFile);*/
        }
        /*for (int i = 0; i < padding;i++) {
         fprintf(outputFile, "0");}*/
    }
    fwrite(writeBlur, sizeof(char), width_two*height, outputFile);
    
    fclose(inputFile);
    fclose(outputFile);
    return 1;
}

int main(void) {
    if (redChannel() == 0) {
        return 0;
    }
    if (greenChannel() == 0) {
        return 0;
    }
    if (blueChannel() == 0) {
        return 0;
    }
    if (greyScale() == 0) {
        return 0;
    }
    if (blackWhite() == 0) {
        return 0;
    }
    if (blurChannel() == 0) {
        return 0;
    }
    return 0;	
}
