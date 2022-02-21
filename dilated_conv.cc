template<class T,int N,int M , int R,int C,int K ,int L >
class dilated_conv{

public:

void dilate(T in_filter[N][M],T out_filter[R][C],T degree);
void convBuf(T image[K][L],T filter[R][C],T result[K][L]);
};




template<class T,int N,int M , int R,int C,int K ,int L >
void dilated_conv<T,N,M,R,C,K,L>::dilate(T in_filter[N][M],T out_filter[R][C],T degree){
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

template<class T,int N,int M , int R,int C,int K ,int L >
void dilated_conv<T,N,M,R,C,K,L>::convBuf(T image[K][L],T filter[R][C],T result[K][L]){ 
	T line_buffer[R][L];
	T *p = &line_buffer[0][0];
    T kx=R/2;
    T i,j,ii,jj,k,l,c; 
    for(i=0;i<K;i++){
		for(j=0;j<L;j++){
			if(i*L+j>=(kx+1)*L){
				for(k=0;k<R;k++){
					for(l=0;l<C;l++){
						ii=(i-kx-1)-kx+k;
						jj= j-kx+l;
						c= 0-kx+l;						
						if(ii>=0 && ii<K && jj>=0 && jj<L){
							result[i-(kx+1)][j]+=line_buffer[k][c]*filter[k][l]; 
						}else{ 
					        result[i-(kx+1)][j]+=0; 
						} 
					} 
				}
			}//else{
			//	result[K-1-i][j]=0;
			//}
			for(int a=0;a<R*L;a++){
				if(a!=R*L-1){
				    p[a]=p[a+1];
				}else{
				    p[a]= image[i][j];
			    }
			}
		}
	}
 }
