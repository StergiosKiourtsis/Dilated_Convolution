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
////////////////////////////////////////////////////////////////////////////////////////////
//TEST 2 WITH A 3*3 FILTER AND 2 DEGREES OF DILATION 
////////////////////////////////////////////////////////////////////////////////////////////// 
    std::cout<<"\n3x3 Filter dilate 2 degrees:";                                                    
    p = dilate(filter[0],3,3,2);         
    result=conv(array[0],p,10,10);                                  
    for(int i=0;i<p[-1]*p[-2];i++){               //                
            if(i%p[-1]==0){ std::cout<<"\n";}     //     print out the new filter                 
            else{std::cout<<" ";}                 //                             
            std::cout<<p[i];                      //                
    }
  std::cout<<"\n3x3 Filter Dilation Degree:2 Result:";
   for(int i=0;i<sizeof(array)/sizeof(int);i++){ //                      
       if(i%10==0){ std::cout<<"\n";}            //   print out the results of convlution                              
       else{std::cout<<" ";}                     //                        
       std::cout<<result[i];                     //                        
   }                                     
/////////////////////////////////////////////////////////////////////////////////////////////
//TEST 2 WITH A 3*3 FILTER AND 3 DEGREES OF DILATION 
////////////////////////////////////////////////////////////////////////////////////////////// 
 std::cout<<"\n3x3 Filter dilate 3 degrees:";                              
  p = dilate(filter[0],3,3,3);                              
 result=conv(array[0],p,10,10);                              
  for(int i=0;i<p[-1]*p[-2];i++){               //    
          if(i%p[-1]==0){ std::cout<<"\n";}     //     print out the new filter                  
          else{std::cout<<" ";}                 //             
          std::cout<<p[i];                      //        
  }
  std::cout<<"\n3x3 Filter Dilation Degree:3 Result:";                                                                                                         
   for(int i=0;i<sizeof(array)/sizeof(int);i++){         // 
       if(i%10==0){ std::cout<<"\n";}                    // print out the results of convlution                          
       else{std::cout<<" ";}                             //       
       std::cout<<result[i];                             //       
   }   
////////////////////////////////////////////////////////////////////////////////////////////// 
//TEST 3 WITH A 5*5 FILTER AND 2 DEGREES OF DILATION 
////////////////////////////////////////////////////////////////////////////////////////////// 
  int filter1[5][5]={{1,1,1 ,1,1},
                    {1,1,1 ,1,1},
                    {1,1,-2,1,1},
                    {1,1,1 ,1,1},
                    {1,1,1 ,1,1}};
 std::cout<<"\n5x5 Filter dilate 2 degrees:";                        
  p = dilate(filter1[0],5,5,2);                        
  result=conv(array[0],p,10,10);                        
  for(int i=0;i<p[-1]*p[-2];i++){             //  
          if(i%p[-1]==0){ std::cout<<"\n";}   //    print out the new filter             
          else{std::cout<<" ";}               //         
          std::cout<<p[i];                    //    
  }
   std::cout<<"\n5x5 Filter Dilation Degree:2 Result:";                                                            
    for(int i=0;i<sizeof(array)/sizeof(int);i++){        // 
        if(i%10==0){ std::cout<<"\n";}                   //  print out the results of convlution          
        else{std::cout<<" ";}                            //   
        std::cout<<result[i];                            //   
    }   

    return 0;
}

