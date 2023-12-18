#include <stdio.h>

int main(){
    char lover[20], his_love[20];

    printf("Enter the name of the lover :");
    fgets(lover, sizeof(lover), stdin);

    printf("Enter his love name :");
    fgets(his_love, sizeof(his_love), stdin);

    int i;
    for (i = 0; i < 50; i++) {
        printf(" %s loves %s",lover,his_love);
        // printf("%s loves %s \n",his_love ,lover);
    }
    return 0;
}