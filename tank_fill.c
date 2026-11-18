
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
given a csv of information containing field size, seed rate, tank capacity, andimplement width, \
the program calculates how many achers one fill covers, how far one travels before refilling, and \
how many fills a field needs
*/
int main(){
    char buffer[1000];

    FILE *sask_fields = fopen("sask_fields.csv", "r");
    FILE *out = fopen("out.csv", "w");
    fprintf(out, "field_id, achers_per_fill, distance_per_fill, fills_per_field \n");

    // parse the first line and do not do any calculations on it (its the title line)
    fgets(buffer, sizeof(buffer), sask_fields);

    // go through the rest of the file until the file cannot read any more lines
    while (fgets(buffer, sizeof(buffer), sask_fields)){
        //get field id from csv
        char id[7];
        char *field_id = strtok(buffer, ",");
        strncpy(id, field_id, sizeof(id) -1);
        id[sizeof(id) -1] = '\0';
        strtok(NULL, ",");
        strtok(NULL, ",");
        //get field size (achers)
        int *field_size = (int *)strtok(NULL, ",");
        //get seed_rate (lbs)
        int *seed_rate = (int *)strtok(NULL, ",");
        strtok(NULL, ",");
        //gat capacity (lbs)
        int *capacity = (int *)strtok(NULL, ",");
        // get implement_width (ft)
        int *implement_width = (int *)strtok(NULL, ",");


        //calculate how many achers one fill covers 
        double achers = *capacity / *seed_rate;
        //calculate how far you travel before refilling
        double distance = achers*(4046.86/(*implement_width));
        //calculate how many fills a field needs
        double fills = *field_size/achers;

        fprintf(out, "%s,%.2f,%.2f,%.2f \n", field_id, achers, distance, fills);
    };

    return(0);
}