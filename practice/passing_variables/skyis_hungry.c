//skylar morris is hungry
#include <stdio.h>
#include <stdlib.h>

void hasskyeaten(int x){
    if(x == 1){
        printf("sky is no longer hungry");
    }else{
        printf("sky is hungry");
    }
}

void skyishungry(int y){
    printf("Enter 1 if sky has eaten, otherwise enter any number");
    scanf("%d", &y);
    hasskyeaten(y);
}


int main(){
    int g;
    skyishungry(g);
    return 0;
}
