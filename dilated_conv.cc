template<typename T,int N,int M,int R,int C>
void dilate(T in_filter[N][M],T out_filter[R][C],T degree){
    int count=0;
    for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			if(i%degree==0 && j%degree==0){
				out_filter[i][j]=in_filter[count/M][count%M];
				count++;
			}else{
				out_filter[i][j]=0;
			}
		}
	}
}

template<typename T,int N,int M,int R,int C>
void convBuf(T image[N][M],T filter[R][C],T result[N][M]){ 
	T line_buffer[R][M];
	T *p = &line_buffer[0][0];
    T pixel;
    T kx=R/2;
    T i,j,ii,jj,k,l,r; 
    T dim = N*M; 	
	T count=kx+1;
    for(i=0;i<N;i++){
		for(j=0;j<M;j++){

			if(i*M+j>=(kx+1)*M){
				pixel=0;
				for(k=0;k<R;k++){
					for(l=0;l<C;l++){
						ii=(i-kx-1)-kx+k;
						jj= j-kx+l;
						int  r=k;
						int  c= 0-kx+l;						
						if(ii>=0 && ii<N && jj>=0 && jj<M){
							pixel+=line_buffer[r][c]*filter[k][l]; 
						}else{ 
							pixel +=0; 
						} 
					} 
				}
				result[i-(kx+1)][j]=pixel;
			}else{
				result[N-1-i][j]=0;
			}
			for(int a=0;a<R*M-1;a++){
				p[a]=p[a+1];
			}
			line_buffer[R-1][M-1]=image[i][j];
		}
	}
 }
