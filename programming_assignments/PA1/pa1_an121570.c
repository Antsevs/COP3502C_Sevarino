#include <stdio.h>
#include <stdlib.h>

struct present {
char *present_name;
float price;
};

struct present* delete_present_list(struct present* present_list, int num){
    int i = 0;
    //note: ok fine
    if(present_list == NULL){
        return 0;
    }
    while(i < num){
        free(present_list[i].present_name);
        i++;
    }
    free(present_list);

    return NULL;
}

int main(){
    //this assignment does not have a main function
}