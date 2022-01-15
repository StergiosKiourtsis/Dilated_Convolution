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
    int *result;
    int *p;
    std::cout<<"\n3x3 Filter dilate 2 degrees:";
    p = dilate(filter[0],3,3,2);
    for(int i=0;i<25;i++){
            if(i%5==0){ std::cout<<"\n";}
            else{std::cout<<" ";}
            std::cout<<p[i];
    }
    result=conv(array[0],p,10,10);
    std::cout<<"\n............."<<p[-1]<<"\n............";
 std::cout<<"\n3x3 Filter dilate 3 degrees:";
  p = dilate(filter[0],3,3,3);
   result=conv(array[0],p,10,10);
  for(int i=0;i<49;i++){
          if(i%7==0){ std::cout<<"\n";}
          else{std::cout<<" ";}
          std::cout<<p[i];
  }
  std::cout<<"\n"<<p[-1]<<" : "<<p[-2];
   for(int i=0;i<100;i++){
       if(i%10==0){ std::cout<<"\n";}
       else{std::cout<<" ";}
       std::cout<<result[i];
   }   
  
  int filter1[5][5]={{1,1,1 ,1,1},
                    {1,1,1 ,1,1},
                    {1,1,-2,1,1},
                    {1,1,1 ,1,1},
                    {1,1,1 ,1,1}};
 std::cout<<"\n5x5 Filter dilate 2 degrees:";
  p = dilate(filter1[0],5,5,2);
   result=conv(array[0],p,10,10);
  for(int i=0;i<81;i++){
          if(i%9==0){ std::cout<<"\n";}
          else{std::cout<<" ";}
          std::cout<<p[i];
  }
 std::cout<<"\n"<<p[-1]<<" : "<<p[-2];
    for(int i=0;i<100;i++){
        if(i%10==0){ std::cout<<"\n";}
        else{std::cout<<" ";}
        std::cout<<result[i];
    }   
    return 0;
}

