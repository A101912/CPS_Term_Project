#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    FILE *fp;
    char line[1000];
    char *token;
    char refDate [10];
    char geo[50], sexGender[20], groupAge[50];
    char val [10];

    fp = fopen("statscan_diabetes.csv", "r");

    if (fp == NULL) {
        printf("The file is unknown, please fix the file");
        return 1; // Exit program with error code
    }

    fseek(fp, 0, SEEK_SET);
    
    fgets(line, sizeof(line), fp); // Read the first line (header) and discard it

    while (fgets(line, sizeof(line), fp)) {

        // Extracts reference date
        token = strtok(line, ",");
        if (token == NULL) continue;
        strncpy(refDate, token, sizeof(refDate) - 1);

        // Extracts province
        token = strtok(NULL, ",");
        if (token == NULL) continue;
        strncpy(geo, token, sizeof(geo) - 1);

        token = strtok(NULL, ",");

        // Extract group age
        token = strtok(NULL, ",");
        if (token == NULL) continue;
        strncpy(groupAge, token, sizeof(groupAge) - 1);

        // Extract gender
        token = strtok(NULL, ",");
        if (token == NULL) continue;
        strncpy(sexGender, token, sizeof(sexGender) - 1);

        // Skip 7 columns
        int i;
        for (i = 0; i < 8; i++) {
            token = strtok(NULL, ",");
            if (token == NULL) continue;
        }

        // Extracts Value
        token = strtok(NULL, ",");
        if (token == NULL) continue;
        strncpy(val, token, sizeof(val) - 1);

        printf("REF date: %s\n", refDate);
        printf("Geo: %s\n", geo);
        printf("Group Age: %s\n", groupAge);
        printf("Sex/Gender: %s\n", sexGender);
        printf("Value: %s\n", val);
        printf("\n");
    }
    fclose(fp);
    return 0;
}

