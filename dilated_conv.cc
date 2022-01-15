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

int *conv(int *image,int *filter, int rows, int columns){ // DEN EINAI TELEIVMENH
    int nd=filter[-1];
    int pixel; 
    int kx=nd/2;
    int ky=nd/2;
    int ii;
    int jj;
    int dim = rows*columns;
    int *new_image = new int[dim];
    //Οι δύο επόμενες for διατρέχουν την εικόνα
	for(int i=0;i<rows;i++){
		for(int j=0;j<columns;j++){
            pixel = 0;
            //Αυτές διατρέχουν το φίλτρο
			for(int k=0;k<nd;k++){
                for(int l=0;l<nd;l++){

                    ii = i + kx-k;
                    jj = j + ky-l;
                    if (ii>=0 && ii<columns && jj>=0 && jj<columns){
                        pixel +=image[ii*columns+jj] * filter[k*nd+l];
                    }
					
				}	
			}
            new_image[i*rows+j] = pixel ;
		}
	}	
    return new_image;
}
