#include <iostream>
#include "dv.cc"

int main(){

    int filter[3][3]={{1,1,1 },
                      {1,-2,1},
                      {1,1,1 }};
    int array[9][9]={{1,2,3,4,5,6,7,8,9},
                     {1,2,3,4,5,6,7,8,9},
                     {1,2,3,4,5,6,7,8,9},    
                     {1,2,3,4,5,6,7,8,9},
                     {1,2,3,4,5,6,7,8,9},
                     {1,2,3,4,5,6,7,8,9},
                     {1,2,3,4,5,6,7,8,9},
                     {1,2,3,4,5,6,7,8,9},
                     {1,2,3,4,5,6,7,8,9}};
    int *result;
    int *p;
    std::cout<<"\n3x3 Filter dilate 2 degrees:";
    p = dilate(filter[0],3,3,2);
    for(int i=0;i<25;i++){
            if(i%5==0){ std::cout<<"\n";}
            else{std::cout<<" ";}
            std::cout<<p[i];
    }
    result=conv(array[0],9,9,p);
 // std::cout<<"\n3x3 Filter dilate 3 degrees:";
 //  p = dilate(filter[0],3,3,3);
 //  for(int i=0;i<49;i++){
 //          if(i%7==0){ std::cout<<"\n";}
 //          else{std::cout<<" ";}
 //          std::cout<<p[i];
 //  }
 //  
 //  int filter1[5][5]={{1,1,1 ,1,1},
 //                    {1,1,1 ,1,1},
 //                    {1,1,-2,1,1},
 //                    {1,1,1 ,1,1},
 //                    {1,1,1 ,1,1}};
 // std::cout<<"\n5x5 Filter dilate 2 degrees:";
 //  p = dilate(filter1[0],5,5,2);
 //  for(int i=0;i<81;i++){
 //          if(i%9==0){ std::cout<<"\n";}
 //          else{std::cout<<" ";}
 //          std::cout<<p[i];
 //  }
 // std::cout<<"\n"<<p[-1]<<" : "<<p[-2];
    for(int i=0;i<81;i++){
        if(i%9==0){ std::cout<<"\n";}
        else{std::cout<<" ";}
        std::cout<<result[i];
    }   
    return 0;
}

