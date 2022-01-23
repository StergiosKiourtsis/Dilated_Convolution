#include <iostream>
#include "dv.cc"

int main(){

    int filter[3][3]={{1,1,1 },
                      {1,-2,1},
                      {1,1,1 }};
    int array[10][10]={{1,2,3,4,5,6,7,8,9,10},
                       {1,2,3,4,5,6,7,8,9,10},
                       {1,2,3,4,5,6,7,8,9,10},
                       {1,2,3,4,5,6,7,8,9,10},    
                       {1,2,3,4,5,6,7,8,9,10},
                       {1,2,3,4,5,6,7,8,9,10},
                       {1,2,3,4,5,6,7,8,9,10},
                       {1,2,3,4,5,6,7,8,9,10},
                       {1,2,3,4,5,6,7,8,9,10},
                       {1,2,3,4,5,6,7,8,9,10}};
    int result[10][10];
    //new_rows = (rows-1)*(degree-1)+rows
    //(3-1)*(2-1)+3 = 5
    int dil_filter[5][5];

//TEST 2 WITH A 3*3 FILTER AND 2 DEGREES OF DILATION  
    std::cout<<"\n3x3 Filter dilate 2 degrees: \n";                                                    
    dilate<3,3,5,5>(filter,dil_filter,2);         
    for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
				std::cout<<dil_filter[i][j]<<" ";
		}
		std::cout<<"\n";
	}
    
    std::cout<<"\n BUFFER TIME! \n";
    convBuf<10,10,5,5>(array,dil_filter,result);
   for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
				std::cout<<result[i][j]<<" ";
		}
		std::cout<<"\n";
	}
	return 0;
}
