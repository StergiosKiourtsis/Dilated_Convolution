#include "ac_channel.h"

template<typename T,int N,int M,int R,int C>
void dilate(T in_filter[N][M],T out_filter[R][C],T degree,ac_channel<T> &line_in,ac_channel<T> &line_out){
    int count=0;
    for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			if(i%degree==0 && j%degree==0){
				
				line_in.write(in_filter[count/M][count%M]);
				line_out.read(out_filter[i][j]);
				//out_filter[i][j]=in_filter[count/M][count%M];
				count++;
			}else{
				line_in.write(0);
				line_out.read(out_filter[i][j]);
				//out_filter[i][j]=0;
			}
		}
	}
}

template<typename T,int N,int M,int R,int C>
void convBuf(T image[N][M],T filter[R][C],T result[N][M],ac_channel<T> &line_in,ac_channel<T> &line_out,ac_channel<T> &line_buff_in,ac_channel<T> &line_buff_out){ 
	T line_buffer[R][M];
    T pixel;
    T kx=R/2;
    T i,j,ii,jj,k,l,r; 
	T tmp;
    for(i=0;i<N;i++){
		if(i==0){
			for(r=0; r<=kx; r++){
				for(j=0; j<M; j++){
					line_in.write(image[kx-r][j]);
					line_out.read(tmp);
					line_buff_in.write(tmp);
					line_buff_out.read(line_buffer[R-1-r][j]);
					//line_buffer[R-1-r][j] = image[kx-r][j];
				}
			}
		}else if(i<N-kx && i>0){
			for(r=0; r<R; r++){
				for(j=0; j<M; j++){
						if(r==R-1){
							
							line_in.write(image[i+kx][j]);
							line_out.read(tmp);
							line_buff_in.write(tmp);
							line_buff_out.read(line_buffer[r][j]);							
							//line_buffer[r][j] = image[i+kx][j];
							
						}else{
							line_buffer[r][j] = line_buffer[r+1][j];
						}
				}
			}
		}else{
			for(r=0; r<R; r++){
				for(j=0; j<M; j++){
						line_buffer[r][j] = line_buffer[r+1][j];
			    }
			}
		}
		for(j=0;j<M;j++){
			pixel=0;
			for(k=0;k<R;k++){
				for(l=0;l<C;l++){
					ii=i-kx+k;
					jj=j-kx+l;
					if(ii>=0 && ii<N && jj>=0 && jj<M){
						line_buff_in.write(line_buffer[k][jj]);
						line_in.write(filter[k][l]);
						pixel+=line_buff_out.read()*line_out.read(); 
					}else{ 
					pixel +=0; 
					} 
				} 
			}
		line_in.write(pixel);
		line_out.read(result[i][j]);
		}
	}
 }

