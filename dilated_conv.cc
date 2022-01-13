#include <iostream>

int *dilate(int *kernel,int rows,int collumns,int degree){
    int N=(rows-1)*(degree-1)+rows;
    int M=(collumns-1)*(degree-1)+collumns;
    int *filter = new int[N*M];
    filter[-1]=N;
    filter[-2]=M;
    int count=0;
    for(int i=0;i<N*M;i++){
        if((i/M)%degree==0 && (i%M)%degree==0){
            filter[i]=kernel[count];
            count++;
        }else{
            filter[i]=0;
        }
    }
    return filter;
}

int *conv(int *picture,int rows,int collums,int *kernel){
    int *x=new int[rows*collums];
    int filter_size=kernel[-1];
    int pixel;
    int kx=filter_size/2;
    int ii;

    for(int i=0;i<rows*collums;i++){
        pixel=0;

        for(int j=0;j<filter_size*filter_size;j++){
            if(((j/filter_size)*collums)+(j%filter_size)+i-((filter_size/2)*collums)-(filter_size/2)<0 || ((j/filter_size)*collums)+(j%filter_size)+i-((filter_size/2)*collums)-(filter_size/2)>rows*collums){
                pixel+=0;
            }else{    
                pixel+=picture[((j/filter_size)*collums)+(j%filter_size)+i-((filter_size/2)*collums)-(filter_size/2)]*kernel[j];    
            }
        }
        x[i]=pixel;
    }
    return x;
}
