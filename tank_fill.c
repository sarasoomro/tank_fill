
#include <stdio.h>

int main(){
    //initialize variables
    int capacity, seed_rate, implement_width, feild_size;

    //get necessary inputs
    printf("\nTank Capacity (lbs): ");
    scanf("%d", &capacity);

    printf("Seed Rate: (lbs): ");
    scanf("%d", &seed_rate);

    printf("Implement width (ft): ");
    scanf("%d", &implement_width);

    printf("Feild Size (achers): ");
    scanf("%d", &feild_size);

    //calculate how many achers one fill covers 
    double achers = capacity / seed_rate;
    printf("\nAmount of achers one fill covers: %.2f \n", achers);

    //calculate how far you travel before refilling
    double distance = achers*(4046.86/implement_width);
    printf("How far you travel before needing to refill (ft): %.2f \n", distance);

    //calculate how many fills a feild needs
    double fills = feild_size/achers;
    printf("The amount of fills the feild needs: %.2f \n", fills);

    return(0);
}
