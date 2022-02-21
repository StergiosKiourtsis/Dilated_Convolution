template<class T,int N,int M , int R,int C,int K ,int L >
class dilated_conv{

public:

void dilate(T in_filter[N][M],T out_filter[R][C],T degree);
void convBuf(T image[K][L],T filter[N][M],T result[K][L],T degree);
void shift(T linebuffer[R][L],T pixel);
void conv(T kx,T i,T j,T line_buffer[R][L],T result[K][L],T filter[R][C]);
};




template<class T,int N,int M , int R,int C,int K ,int L >
void dilated_conv<T,N,M,R,C,K,L>::dilate(T in_filter[N][M],T out_filter[R][C],T degree){
    for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			if(i%degree==0 && j%degree==0){
				out_filter[i][j]=in_filter[i/degree][j/degree];
			}else{
				out_filter[i][j]=0;
			}
		}
	}
}

template<class T,int N,int M , int R,int C,int K ,int L >
void dilated_conv<T,N,M,R,C,K,L>::convBuf(T image[K][L],T filter[N][M],T result[K][L],T degree){ 
	T line_buffer[R][L];
    T kx=R/2;
    T i,j,ii,jj,k,l,c; 
    T new_filter[R][C];
    dilate(filter,new_filter,degree);
    for(i=0;i<K;i++){
		for(j=0;j<L;j++){
			conv(kx,i,j,line_buffer,result,new_filter);
			//else{
			//	result[K-1-i][j]=0;
		    //}
			shift(line_buffer,image[i][j]);
		}
	}

 }

template<class T,int N,int M , int R,int C,int K ,int L >
void dilated_conv<T,N,M,R,C,K,L>::shift(T line_buffer[R][L],T pixel){
	for(int a=0;a<R*L;a++){
	    T *p = &line_buffer[0][0];
		if(a!=R*L-1){
		    p[a]=p[a+1];
		}else{
		    p[a]=pixel;
	    }
	}
}

template<class T,int N,int M , int R,int C,int K ,int L >
void dilated_conv<T,N,M,R,C,K,L>::conv(T kx,T i,T j,T line_buffer[R][L],T result[K][L],T filter[R][C]){
	if(i*L+j>=(kx+1)*L){
		for(T k=0;k<R;k++){
			for(T l=0;l<C;l++){
				T ii=(i-kx-1)-kx+k;
				T jj= j-kx+l;
				T c= 0-kx+l;						
				if(ii>=0 && ii<K && jj>=0 && jj<L){
					result[i-(kx+1)][j]+=line_buffer[k][c]*filter[k][l]; 
				}else{ 
					result[i-(kx+1)][j]+=0; 
				} 
			} 
		}
	}  
}
