#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char refDate[500];
    char geo[500];
    char groupAge[500];
    char sexGender[500];
    char val[500];
} Data;

int main(void) {
    FILE *fp;
    char line[1000];
    char *token;
    int i = 0;
    Data dataArray[1000];

    fp = fopen("statscan_diabetes.csv", "r");

    if (fp == NULL) {
        printf("The file is unknown, please fix the file");
        return 1; // Exit program with error code
    }

    fseek(fp, 0, SEEK_SET); // Points to the beginning of the file

    while (fgets(line, sizeof(line), fp)) {

        // Extracts reference date
        token = strtok(line, ",");
        if (token == NULL) continue;
        strncpy(dataArray[i].refDate, token, sizeof(dataArray[i].refDate) - 1);

        // Extracts province
        token = strtok(NULL, ",");
        if (token == NULL) continue;
        strncpy(dataArray[i].geo, token, sizeof(dataArray[i].geo) - 1);

        token = strtok(NULL, ",");

        // Extract group age
        token = strtok(NULL, ",");
        if (token == NULL) continue;
        strncpy(dataArray[i].groupAge, token, sizeof(dataArray[i].groupAge) - 1);

        // Extract gender
        token = strtok(NULL, ",");
        if (token == NULL) continue;
        strncpy(dataArray[i].sexGender, token, sizeof(dataArray[i].sexGender) - 1);

        // Skip 7 columns
        int j;
        for (j = 0; j < 8; j++) {
            token = strtok(NULL, ",");
            if (token == NULL) continue;
        }

        // Extracts Value
        token = strtok(NULL, ",");
        if (token == NULL) continue;
        strncpy(dataArray[i].val, token, sizeof(dataArray[i].val) - 1);

        i++;
    }

    for (int j = 0; j < i; j++) {
    if (strcmp(dataArray[j].sexGender, "\"Males\"") == 0) {
    printf("REF date: %s\n", dataArray[j].refDate);
    printf("Geo: %s\n", dataArray[j].geo);
    printf("Group Age: %s\n", dataArray[j].groupAge);
    printf("Sex/Gender: %s\n", dataArray[j].sexGender);
    printf("Value: %s\n", dataArray[j].val);
    printf("\n");
    }
    }

    fclose(fp);
    return 0;

}
