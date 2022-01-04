#include <iostream>
#include"dilated_conv.cc"

int main(){

    int array[9][9]={{1,2,3,4,5,6,7,8,9},
                     {1,2,3,4,5,6,7,8,9},
                     {1,2,3,4,5,6,7,8,9},    
                     {1,2,3,4,5,6,7,8,9},
                     {1,2,3,4,5,6,7,8,9},
                     {1,2,3,4,5,6,7,8,9},
                     {1,2,3,4,5,6,7,8,9},
                     {1,2,3,4,5,6,7,8,9},
                     {1,2,3,4,5,6,7,8,9}};

    int filter[3][3]={{1,1,1 },
                      {1,-2,1},
                      {1,1,1 }};

    int new_filter[5][5];

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            std::cout<<new_filter[i][j]<< " ";
        }
        std::cout<<std::endl;
    }

    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            std::cout<<array[i][j]<< " ";
        }
        std::cout<<std::endl;
    }

    dilate(filter,new_filter);
    d_conv(array,new_filter);

    std::cout<<"THE NEW ARRAY: \n";
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            std::cout<<array[i][j]<< " ";
        }
        std::cout<<std::endl;
    }


    return 0;
}