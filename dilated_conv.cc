#include <iostream>

int *dilate(int *kernel,int rows,int columns,int degree){
    int N=(rows-1)*(degree-1)+rows;
    int M=(columns-1)*(degree-1)+columns;
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

int *conv(int *image,int *filter, int rows, int columns){ 
    int filter_size=filter[-1];
    int pixel; 
    int kx=filter_size/2;
    int ky=filter_size/2;
    int i,j,ii,jj,k,l;
    int dim = rows*columns;
    int *new_image = new int[dim];
    for(int pixel_number=0;pixel_number<dim;pixel_number++){
        i = pixel_number/columns;
        j = pixel_number%columns;
        pixel =0;
        for(int filter_pixel=0;filter_pixel<filter_size*filter_size;filter_pixel++){
            k = filter_pixel/filter_size;
            l = filter_pixel%filter_size;
            ii=i+kx-k;
            jj=j+kx-l;
            if(ii>=0 && ii<rows && jj>=0 && jj<columns){
                pixel+=image[ii*columns+jj]*filter[k*filter_size+l];
            }else{
                pixel +=0;
            }
        }
        new_image[i*columns+j]=pixel;
    }
	
    return new_image;
}
