template<int N,int M,int R,int C>
void dilate(int in_filter[N][M],int out_filter[R][C],int degree){
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

template<int N,int M,int R,int C>
void convBuf(int image[N][M],int filter[R][C],int result[N][M]){ 
	int line_buffer[R][M];
    int pixel;
    int kx=R/2;
    int i,j,ii,jj,k,l,r; 
    int dim = N*M; 	
	int count=kx+1;
    for(i=0;i<N;i++){
		if(i==0){
			for(r=0; r<count; r++){
				for(j=0; j<M; j++){
					line_buffer[r][j] = image[i+r][j];
				}
			}
		}
		else if(i<N-R){
			for(j=0; j<M; j++){
				line_buffer[0][j] = image[count][j];
			}
			for(r=1; r<R; r++){
				for(j=0; j<M; j++){
						line_buffer[r][j] = line_buffer[r-1][j];
				}
			}
		}
		for(j=0;j<M;j++){
			pixel=0;
			for(k=0;k<R;k++){
				for(l=0;l<C;l++){
					ii=i+kx-k;
					jj=j+kx-l;
					if(ii>=0 && ii<N && jj>=0 && jj<M){
						pixel+=line_buffer[k][jj]*filter[k][l]; 
					}else{ 
					pixel +=0; 
					} 
				} 
			}
		result[i][j]=pixel;
		}
		count++;
	}
 }
