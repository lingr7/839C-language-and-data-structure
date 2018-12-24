#include <stdio.h>  
#include <stdlib.h>  
struct record {  
    char name[10];  
    int age;  
};  
int main(void)  
{  
    struct record array[2] = {{"Ken", 24}, {"Knuth", 28}};  
    FILE *fp = fopen("recfile", "w");  
    if (fp == NULL) {  
        perror("Open file recfile");  
        exit(1);  
    }  
    fwrite(array, sizeof(struct record), 2, fp);  
    fclose(fp);  
    return 0;  
}  
  
/* гнгнгнгнгнгнгнгнгнгнгнгнгнгнгнгнгнгнгнreadrec.cгнгнгнгнгнгнгнгнгнгнгнгнгнгнгнгнгн */  
#include <stdio.h>  
#include <stdlib.h>  
struct record {  
    char name[10];  
    int age;  
};  
int main(void)  
{  
    struct record array[2];  
    FILE *fp = fopen("recfile", "r");  
    if (fp == NULL) {  
        perror("Open file recfile");  
        exit(1);  
    }  
    fread(array, sizeof(struct record), 2, fp);  
    printf("Name1: %s\tAge1: %d\n", array[0].name, array[0].age);  
    printf("Name2: %s\tAge2: %d\n", array[1].name, array[1].age);  
    fclose(fp);  
    return 0;  
} 
