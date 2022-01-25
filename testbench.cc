#include <iostream>
#include "dilated_conv.cc"

int main(){

    int filter[3][3]={{1,1,1 },
                      {1,-2,1},
                      {1,1,1 }};
    int array[10][10]={{1,1,1,1,1,14,1,51,1,1},
                       {2,15,2,1,2,14,2,2,2,8},
                       {3,2,3,1,23,14,3,3,6,3},
                       {4,4,74,1,4,14,4,4,1,4},    
                       {5,5,5,1,5,14,5,5,55,5},
                       {1,1,1,1,1,14,1,1,41,1},
                       {2,32,2,1,2,14,2,2,2,2},
                       {3,3,3,1,3,14,3,3,33,3},
                       {4,4,7,1,4,14,4,20,9,4},
                       {21,5,5,1,5,14,5,5,5,5}};

    int result1[10][10]; 
    int result2[10][10];
    //new_rows = (rows-1)*(degree-1)+rows
    //int size = (3-1)*(2-1)+3;
    int dil_filter[7][7];

//TEST 2 WITH A 3*3 FILTER AND 3 DEGREES OF DILATION  
    std::cout<<"\n3x3 Filter dilate 2 degrees: \n";                                                    
    dilate<3,3,7,7>(filter,dil_filter,3);         
    for(int i=0;i<7;i++){
		for(int j=0;j<7;j++){
				std::cout<<dil_filter[i][j]<<" ";
		}
		std::cout<<"\n";
	}
    std::cout<<"\n BUFFER TIME! \n";
    convBuf<10,10,7,7>(array,dil_filter,result2);
   for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
				std::cout<<result2[i][j]<<" ";
		}
		std::cout<<"\n";
	}
return 0;
}
