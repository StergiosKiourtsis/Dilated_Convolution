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
    dilate(filter,new_filter);
    std::cout<<"THE NEW FILTER: \n";
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            std::cout<<new_filter[i][j]<< " ";
        }
        std::cout<<std::endl;
    }
    std::cout<<"THE OLD ARRAY: \n";
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            std::cout<<array[i][j]<< " ";
        }
        std::cout<<std::endl;
    }

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