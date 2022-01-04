#include <iostream>
#define N 9 //the number of rows of the main array
#define M 9 //the number of columns of the main array
#define R 5 //the number of rows of the dilated filter
#define C 5 //the number of columns of the dilated filter
void assign(int a[N][M],int b[N][M]){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            a[i][j] = b[i][j];
        }
    }
}


void d_conv(int array[N][M],int kernel[R][C]){
    int row_1,row_2,row_3,row_4;
    int col_1,col_2,col_3,col_4;
    int temp_array[N][M];
    for(int i=0;i<N;i++){
        row_1=(i==0||i==1)?0:1;
        row_2=(i==0)?0:1;
        row_3=(i==N-1)?0:1;
        row_4=(i==N-2 || i==N-1)?0:1;
        for(int j=0;j<M;j++){
            col_1=(j==0||j==1)?0:1;
            col_2=(j==0)?0:1;
            col_3=(j==M-1)?0:1;
            col_4=(j==M-2||j==M-1)?0:1;
            temp_array[i][j]=  col_1*row_1*array[i-2][j-2]*kernel[0][0] + col_2*row_1*array[i-2][j-1]*kernel[0][1] + row_1*array[i-2][j]*kernel[0][2] + col_3*row_1*array[i-2][j+1]*kernel[0][3] + col_4*row_1*array[i-2][j+2]*kernel[0][4] +
                               col_1*row_2*array[i-1][j-2]*kernel[1][0] + col_2*row_2*array[i-1][j-1]*kernel[1][1] + row_2*array[i-1][j]*kernel[1][2] + col_3*row_2*array[i-1][j+1]*kernel[1][3] + col_4*row_2*array[i-1][j+2]*kernel[1][4] + 
                               col_1*  array[i][j-2]*kernel[2][0]       + col_2*  array[i][j-1]*kernel[2][1]       +   array[i][j]*kernel[2][2]       + col_3*  array[i][j+1]*kernel[2][3]       + col_4*  array[i][j+2]*kernel[2][4]       + 
                               col_1*row_3*array[i+1][j-2]*kernel[3][0] + col_2*row_3*array[i+1][j-1]*kernel[3][1] + row_3*array[i+1][j]*kernel[3][2] + col_3*row_3*array[i+1][j+1]*kernel[3][3] + col_4*row_3*array[i+1][j+2]*kernel[3][4] +
                               col_1*row_4*array[i+2][j-2]*kernel[4][0] + col_2*row_4*array[i+2][j-1]*kernel[4][1] + row_4*array[i+2][j]*kernel[4][2] + col_3*row_4*array[i+2][j+1]*kernel[4][3] + col_4*row_4*array[i+2][j+2]*kernel[4][4] ;
            
        }
    }
   assign(array,temp_array);

}

//dilate the kernel by 2 degrees
void dilate(int array[3][3],int result[(3-1)*(2-1)+3][(3-1)*(2-1)+3]){  
    int ROWS=(3-1)*(2-1)+3;
    int COLUMNS=(3-1)*(2-1)+3;
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLUMNS;j++){
            result[i][j]=(i%2==0 && j%2==0)?array[i/2][j/2]:0;
        }
    }

}
