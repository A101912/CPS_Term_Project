
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*----------------------------------------*/
/*   THE CODE TO SOLVE FOR QUESTION 1.    */
/*----------------------------------------*/

typedef struct {
    char refDate[500];
    char geo[500];
    char groupAge[500];
    char sexGender[500];
    char val[500];
    double doubleVal;
} Data;

double CalculateProvinceAvg(Data data[], char *filter);
double CalculateProvinceAndYearAvg(Data data[], char *filter, char *filter2);
double CalculateProvinceWithAgeAvg(Data data[], char *filter, char *filter2);

int main(void) {


    FILE *fp;
    char line[1000];
    char *token;
    int i = 0;
    Data dataArray[1000];


    fp = fopen("statscan_diabetes.csv", "r");

    if (fp == NULL) {
        printf("The file is unknown, please fix the file");
        return 1; 
    }

    fseek(fp, 0, SEEK_SET); 

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
        char* quoteToken = strtok(token, "\"");

        // Removes excess quotations
        if (quoteToken != NULL) {
            strncpy(dataArray[i].val, quoteToken, sizeof(dataArray[i].val) - 1);
        } 
        else {
            strncpy(dataArray[i].val, token, sizeof(dataArray[i].val) - 1);
        }

        // Convert the string array to double array
        dataArray[i].doubleVal = atof(dataArray[i].val);

        // Count increases to i
        i++;
    }
    fclose(fp);

    /*------------------------------------------------*/
    /*   THE CODE TO SOLVE FOR QUESTION 1a) and 1b)   */
    /*------------------------------------------------*/
    char ontario[] = "\"Ontario\"";
    char quebec[] = "\"Quebec\"";
    char columbia[] = "\"British Columbia\"";
    char alberta[] = "\"Alberta\"";
    char canada[] = "\"Canada (excluding territories)\"";

    double avgOntario = CalculateProvinceAvg(dataArray, ontario);
    double avgQuebec = CalculateProvinceAvg(dataArray, quebec);
    double avgColumbia = CalculateProvinceAvg(dataArray, columbia);
    double avgAlberta = CalculateProvinceAvg(dataArray, alberta);
    double avgCanada = CalculateProvinceAvg(dataArray, canada);

    printf("\n");
    printf("QUESTION 1a) & 1b)\n");
    printf("\n");
    printf("/-----------------------------------------------------------------/\n"); 
    printf("Average value for Ontario for all years/ageGroup: %0.2f percent! \n", avgOntario);
    printf("\n");
    printf("Average value for Quebec for all years/ageGroup: %0.2lf percent! \n", avgQuebec);
    printf("\n");
    printf("Average value for British Columbia for all years/ageGroup: %0.2lf percent! \n", avgColumbia);
    printf("\n");
    printf("Average value for Alberta for all years/ageGroup: %0.2lf percent! \n", avgAlberta);
    printf("\n");
    printf("Average value for Canada excluding territories for all years/ageGroup: %0.2lf percent! \n", avgCanada);
    printf("/-----------------------------------------------------------------/\n"); 

    /*------------------------------------------------*/
    /*      THE CODE TO SOLVE FOR QUESTION 1c)        */
    /*------------------------------------------------*/
    char years[][8]= { "\"2015\"", "\"2016\"", "\"2017\"", "\"2018\"", "\"2019\"", "\"2020\"", "\"2021\"" };

    double avgOntario2015 = CalculateProvinceAndYearAvg(dataArray, ontario, years[0]);
    double avgQuebec2015 = CalculateProvinceAndYearAvg(dataArray, quebec, years[0]);
    double avgColumbia2015 = CalculateProvinceAndYearAvg(dataArray, columbia, years[0]);
    double avgAlberta2015 = CalculateProvinceAndYearAvg(dataArray, alberta, years[0]);
    double avgCanada2015 = CalculateProvinceAndYearAvg(dataArray, canada, years[0]);

    double avgOntario2016 = CalculateProvinceAndYearAvg(dataArray, ontario, years[1]);
    double avgQuebec2016 = CalculateProvinceAndYearAvg(dataArray, quebec, years[1]);
    double avgColumbia2016 = CalculateProvinceAndYearAvg(dataArray, columbia, years[1]);
    double avgAlberta2016 = CalculateProvinceAndYearAvg(dataArray, alberta, years[1]);
    double avgCanada2016 = CalculateProvinceAndYearAvg(dataArray, canada, years[1]);

    double avgOntario2017 = CalculateProvinceAndYearAvg(dataArray, ontario, years[2]);
    double avgQuebec2017 = CalculateProvinceAndYearAvg(dataArray, quebec, years[2]);
    double avgColumbia2017 = CalculateProvinceAndYearAvg(dataArray, columbia, years[2]);
    double avgAlberta2017 = CalculateProvinceAndYearAvg(dataArray, alberta, years[2]);
    double avgCanada2017 = CalculateProvinceAndYearAvg(dataArray, canada, years[2]);

    double avgOntario2018 = CalculateProvinceAndYearAvg(dataArray, ontario, years[3]);
    double avgQuebec2018 = CalculateProvinceAndYearAvg(dataArray, quebec, years[3]);
    double avgColumbia2018 = CalculateProvinceAndYearAvg(dataArray, columbia, years[3]);
    double avgAlberta2018 = CalculateProvinceAndYearAvg(dataArray, alberta, years[3]);
    double avgCanada2018 = CalculateProvinceAndYearAvg(dataArray, canada, years[3]);

    double avgOntario2019 = CalculateProvinceAndYearAvg(dataArray, ontario, years[4]);
    double avgQuebec2019 = CalculateProvinceAndYearAvg(dataArray, quebec, years[4]);
    double avgColumbia2019 = CalculateProvinceAndYearAvg(dataArray, columbia, years[4]);
    double avgAlberta2019 = CalculateProvinceAndYearAvg(dataArray, alberta, years[4]);
    double avgCanada2019 = CalculateProvinceAndYearAvg(dataArray, canada, years[4]);

    double avgOntario2020 = CalculateProvinceAndYearAvg(dataArray, ontario, years[5]);
    double avgQuebec2020 = CalculateProvinceAndYearAvg(dataArray, quebec, years[5]);
    double avgColumbia2020 = CalculateProvinceAndYearAvg(dataArray, columbia, years[5]);
    double avgAlberta2020 = CalculateProvinceAndYearAvg(dataArray, alberta, years[5]);
    double avgCanada2020 = CalculateProvinceAndYearAvg(dataArray, canada, years[5]);

    double avgOntario2021 = CalculateProvinceAndYearAvg(dataArray, ontario, years[6]);
    double avgQuebec2021 = CalculateProvinceAndYearAvg(dataArray, quebec, years[6]);
    double avgColumbia2021 = CalculateProvinceAndYearAvg(dataArray, columbia, years[6]);
    double avgAlberta2021 = CalculateProvinceAndYearAvg(dataArray, alberta, years[6]);
    double avgCanada2021 = CalculateProvinceAndYearAvg(dataArray, canada, years[6]);

    printf("\n");
    printf("QUESTION 1c)\n");
    printf("\n");
    printf("%-15s %-15s %-15s %-15s %-18s %-15s\n", "Year (20XX)", "Canada", "Ontario", "Quebec", "British Columbia", "Alberta");
    printf("%-15s %-15s %-15s %-15s %-18s %-15s\n", "---------------", "--------------", "--------------", "--------------", "------------------", "--------------");
    printf("%-15s %-15.2f %-15.2f %-15.2f %-18.2f %-15.2f\n", "2015", avgCanada2015, avgOntario2015, avgQuebec2015, avgColumbia2015, avgAlberta2015);
    printf("%-15s %-15.2f %-15.2f %-15.2f %-18.2f %-15.2f\n", "2016", avgCanada2016, avgOntario2016, avgQuebec2016, avgColumbia2016, avgAlberta2016);
    printf("%-15s %-15.2f %-15.2f %-15.2f %-18.2f %-15.2f\n", "2017", avgCanada2017, avgOntario2017, avgQuebec2017, avgColumbia2017, avgAlberta2017);
    printf("%-15s %-15.2f %-15.2f %-15.2f %-18.2f %-15.2f\n", "2018", avgCanada2018, avgOntario2018, avgQuebec2018, avgColumbia2018, avgAlberta2018);
    printf("%-15s %-15.2f %-15.2f %-15.2f %-18.2f %-15.2f\n", "2019", avgCanada2019, avgOntario2019, avgQuebec2019, avgColumbia2019, avgAlberta2019);
    printf("%-15s %-15.2f %-15.2f %-15.2f %-18.2f %-15.2f\n", "2020", avgCanada2020, avgOntario2020, avgQuebec2020, avgColumbia2020, avgAlberta2020);
    printf("%-15s %-15.2f %-15.2f %-15.2f %-18.2f %-15.2f\n", "2021", avgCanada2021, avgOntario2021, avgQuebec2021, avgColumbia2021, avgAlberta2021);

    /*------------------------------------------------*/
    /*      THE CODE TO SOLVE FOR QUESTION 1d)        */
    /*------------------------------------------------*/
    char age[][25] = {"\"35 to 49 years\"", "\"50 to 64 years\"", "\"65 years and over\""};

    double avgOntarioAgrGrp1 = CalculateProvinceWithAgeAvg(dataArray, ontario, age[0]);
    double avgQuebecAgrGrp1 = CalculateProvinceWithAgeAvg(dataArray, quebec, age[0]);
    double avgColumbiaAgrGrp1 = CalculateProvinceWithAgeAvg(dataArray, columbia, age[0]);
    double avgAlbertaAgrGrp1 = CalculateProvinceWithAgeAvg(dataArray, alberta, age[0]);
    double avgCanadaAgrGrp1 = CalculateProvinceWithAgeAvg(dataArray, canada, age[0]);

    double avgOntarioAgrGrp2 = CalculateProvinceWithAgeAvg(dataArray, ontario, age[1]);
    double avgQuebecAgrGrp2 = CalculateProvinceWithAgeAvg(dataArray, quebec, age[1]);
    double avgColumbiaAgrGrp2 = CalculateProvinceWithAgeAvg(dataArray, columbia, age[1]);
    double avgAlbertaAgrGrp2 = CalculateProvinceWithAgeAvg(dataArray, alberta, age[1]);
    double avgCanadaAgrGrp2 = CalculateProvinceWithAgeAvg(dataArray, canada, age[1]);

    double avgOntarioAgrGrp3 = CalculateProvinceWithAgeAvg(dataArray, ontario, age[2]);
    double avgQuebecAgrGrp3 = CalculateProvinceWithAgeAvg(dataArray, quebec, age[2]);
    double avgColumbiaAgrGrp3 = CalculateProvinceWithAgeAvg(dataArray, columbia, age[2]);
    double avgAlbertaAgrGrp3 = CalculateProvinceWithAgeAvg(dataArray, alberta, age[2]);
    double avgCanadaAgrGrp3 = CalculateProvinceWithAgeAvg(dataArray, canada, age[2]);

    printf("\n");
    printf("QUESTION 1d)\n");
    printf("\n");
    printf("%-15s %-15s %-15s %-15s %-18s %-15s\n", "Age Group", "Canada", "Ontario", "Quebec", "British Columbia", "Alberta");
    printf("%-15s %-15s %-15s %-15s %-18s %-15s\n", "---------------", "--------------", "--------------", "--------------", "------------------", "--------------");
    printf("%-15s %-15.2f %-15.2f %-15.2f %-18.2f %-15.2f\n", "35-49", avgCanadaAgrGrp1, avgOntarioAgrGrp1, avgQuebecAgrGrp1, avgColumbiaAgrGrp1, avgAlbertaAgrGrp1);
    printf("%-15s %-15.2f %-15.2f %-15.2f %-18.2f %-15.2f\n", "50-64", avgCanadaAgrGrp2, avgOntarioAgrGrp2, avgQuebecAgrGrp2, avgColumbiaAgrGrp2, avgAlbertaAgrGrp2);
    printf("%-15s %-15.2f %-15.2f %-15.2f %-18.2f %-15.2f\n", "64+", avgCanadaAgrGrp3, avgOntarioAgrGrp3, avgQuebecAgrGrp3, avgColumbiaAgrGrp3, avgAlbertaAgrGrp3);
    
    /*------------------------------------------------*/
    /*      THE CODE TO SOLVE FOR QUESTION 2          */
    /*------------------------------------------------*/
    double ProvinceAvg[] = {avgOntario, avgQuebec, avgColumbia, avgAlberta};
    double highest = 0;
    double lowest = ProvinceAvg[0];
    char ProvinceName[5][20] = {"Ontario", "Quebec", "British Columbia" , "Alberta"};

    for (int i = 0; i < 4; i++){
        if(highest < ProvinceAvg[i]){
            highest = ProvinceAvg[i];
        }

        if(lowest > ProvinceAvg[i]){
            lowest = ProvinceAvg[i];
        }

    }
    printf("\n");
    printf("-----------------------------------------------\n");
    printf("QUESTION 2\n");
    printf("\n");

    printf("The province with the highest average is:");
    for(int i=0; i<4; i++){
        if(ProvinceAvg[i] == highest) {
            printf(" %s\n", ProvinceName[i]);
        }
    }
    printf("The province with the lowest average is:");
    for(int i=0; i<4; i++){
        if(ProvinceAvg[i] == lowest) {
            printf(" %s\n", ProvinceName[i]);
        }
    }

    /*------------------------------------------------*/
    /*      THE CODE TO SOLVE FOR QUESTION 3          */
    /*------------------------------------------------*/

    double aboveAvg[4] = {0};
    double belowAvg[4] = {0};
    char aboveProv[][20]={"","","",""};
    char belowProv[][20] = {" ", " ", " ", " "};

    for(int i=0; i<4; i++){
        if(ProvinceAvg[i] > avgCanada){
            aboveAvg[i] = ProvinceAvg[i];
            strcpy(aboveProv[i], ProvinceName[i]);
        }
        if(ProvinceAvg[i] < avgCanada){
            belowAvg[i] = ProvinceAvg[i];
            strcpy(belowProv[i], ProvinceName[i]);
        }
    }
    printf("\n");
    printf("-----------------------------------------------\n");
    printf("QUESTION 3\n");
    printf("\n");

    printf("The provinces that are above the national average are:\n");
    for(int i=0; i<4; i++){
        if(aboveAvg[i] > 0) {
            printf("%s: with %0.2lf percent!\n", aboveProv[i], aboveAvg[i]);
        }
    }
    printf("\n");

    printf("The provinces that are below the national average are:\n");
    for(int i=0; i<4; i++){
    if(ProvinceAvg[i] < avgCanada){
        belowAvg[i] = ProvinceAvg[i];
        printf("%s: with %0.2lf percent!\n", belowProv[i], belowAvg[i]);
    }
}
    printf("\n");

    /*------------------------------------------------*/
    /*      THE CODE TO SOLVE FOR QUESTION 4          */
    /*------------------------------------------------*/
    char yearName[][20] = {"2015", "2016", "2017" , "2018", "2019", "2020", "2021"};
    double allTimeHigh = 0;
    double allTimeLow = avgOntario2015;
    char highestProvince[][20] = {""};
    char lowestProvince[][20] = {""};
    int yearDetHigh = 0;
    int yearDetLow = 0;

    double province2015[] = {avgOntario2015, avgQuebec2015, avgColumbia2015, avgAlberta2015};
    double province2016[] = {avgOntario2016, avgQuebec2016, avgColumbia2016, avgAlberta2016};
    double province2017[] = {avgOntario2017, avgQuebec2017, avgColumbia2017, avgAlberta2017};
    double province2018[] = {avgOntario2018, avgQuebec2018, avgColumbia2018, avgAlberta2018};
    double province2019[] = {avgOntario2019, avgQuebec2019, avgColumbia2019, avgAlberta2019};
    double province2020[] = {avgOntario2020, avgQuebec2020, avgColumbia2020, avgAlberta2020};
    double province2021[] = {avgOntario2021, avgQuebec2021, avgColumbia2021, avgAlberta2021};

    for(int i =0; i < 4; i++){
        if(province2015[i] > allTimeHigh){
            allTimeHigh = province2015[i];
            yearDetHigh = 0;
            strcpy(highestProvince[0], ProvinceName[i]);

            }
        if(province2015[i] < allTimeLow){
            allTimeLow = province2015[i];
            yearDetLow = 0;
            strcpy(lowestProvince[0], ProvinceName[i]);
            }
        }

    for(int i =0; i < 4; i++){
        if(province2016[i] > allTimeHigh){
            allTimeHigh = province2016[i];
            yearDetHigh = 1;
            strcpy(highestProvince[0], ProvinceName[i]);
            
        }
        if(province2016[i] < allTimeLow){
            allTimeLow = province2016[i];
            yearDetLow = 1;
            strcpy(lowestProvince[0], ProvinceName[i]);
            
        }
    }
    for(int i =0; i < 4; i++){
        if(province2017[i] > allTimeHigh){
            allTimeHigh = province2017[i];
            yearDetHigh = 2;
            strcpy(highestProvince[0], ProvinceName[i]);
        }
        if(province2017[i] < allTimeLow){
            allTimeLow = province2017[i];
            yearDetLow = 2;
            strcpy(lowestProvince[0], ProvinceName[i]);
        }
    }
    for(int i =0; i < 4; i++){
        if(province2018[i] > allTimeHigh){
            allTimeHigh = province2018[i];
            yearDetHigh = 3;
            strcpy(highestProvince[0], ProvinceName[i]);
        }
        if(province2018[i] < allTimeLow){
            allTimeLow = province2018[i];
            yearDetLow = 3;
            strcpy(lowestProvince[0], ProvinceName[i]);
        }
    }
    for(int i =0; i < 4; i++){
        if(province2019[i] > allTimeHigh){
            allTimeHigh = province2019[i];
            yearDetHigh = 4;
            strcpy(highestProvince[0], ProvinceName[i]);
        }
        if(province2019[i] < allTimeLow){
            allTimeLow = province2019[i];
            yearDetLow = 4;
            strcpy(lowestProvince[0], ProvinceName[i]);
        }
    }
    for(int i =0; i < 4; i++){
        if(province2020[i] > allTimeHigh){
            allTimeHigh = province2020[i];
            yearDetHigh = 5;
            strcpy(highestProvince[0], ProvinceName[i]);
        }
        if(province2020[i] < allTimeLow){
            allTimeLow = province2020[i];
            yearDetLow = 5;
            strcpy(lowestProvince[0], ProvinceName[i]);
        }
    }
    for(int i =0; i < 4; i++){
        if(province2021[i] > allTimeHigh){
            allTimeHigh = province2021[i];
            yearDetHigh = 6;
            strcpy(highestProvince[0], ProvinceName[i]);
        }
        if(province2021[i] < allTimeLow){
            allTimeLow = province2021[i];
            yearDetLow = 6;
            strcpy(lowestProvince[0], ProvinceName[i]);
        }
    }
    printf("\n");
    printf("-----------------------------------------------\n");
    printf("QUESTION 4\n");
    printf("\n");
    printf("The all time highest diabetes average is %s, in %s\n",highestProvince[0], yearName[yearDetHigh]);
    printf("\n");
    printf("The all time lowest diabetes average is %s, in %s\n",lowestProvince[0], yearName[yearDetLow]);
    printf("\n");


    /*------------------------------------------------*/
    /*   CODE TO PRINT THE DATA TO FILES FOR GRAPH    */
    /*------------------------------------------------*/
    FILE *newFILE;
    newFILE = fopen("yearGraphData.txt","w");

    if (newFILE == NULL) {
        printf("Error opening file\n");
    return 1;
    }

    fprintf(newFILE,"%-15s %-15s %-15s %-15s %-18s %-15s\n", "Year (20XX)", "Canada", "Ontario", "Quebec", "British Columbia", "Alberta");
    fprintf(newFILE,"%-15d %-15.2f %-15.2f %-15.2f %-18.2f %-15.2f\n", 2015, avgCanada2015, avgOntario2015, avgQuebec2015, avgColumbia2015, avgAlberta2015);
    fprintf(newFILE,"%-15d %-15.2f %-15.2f %-15.2f %-18.2f %-15.2f\n", 2016, avgCanada2016, avgOntario2016, avgQuebec2016, avgColumbia2016, avgAlberta2016);
    fprintf(newFILE,"%-15d %-15.2f %-15.2f %-15.2f %-18.2f %-15.2f\n", 2017, avgCanada2017, avgOntario2017, avgQuebec2017, avgColumbia2017, avgAlberta2017);
    fprintf(newFILE,"%-15d %-15.2f %-15.2f %-15.2f %-18.2f %-15.2f\n", 2018, avgCanada2018, avgOntario2018, avgQuebec2018, avgColumbia2018, avgAlberta2018);
    fprintf(newFILE,"%-15d %-15.2f %-15.2f %-15.2f %-18.2f %-15.2f\n", 2019, avgCanada2019, avgOntario2019, avgQuebec2019, avgColumbia2019, avgAlberta2019);
    fprintf(newFILE,"%-15d %-15.2f %-15.2f %-15.2f %-18.2f %-15.2f\n", 2020, avgCanada2020, avgOntario2020, avgQuebec2020, avgColumbia2020, avgAlberta2020);
    fprintf(newFILE,"%-15d %-15.2f %-15.2f %-15.2f %-18.2f %-15.2f\n", 2021, avgCanada2021, avgOntario2021, avgQuebec2021, avgColumbia2021, avgAlberta2021);
    fprintf(newFILE,"\n");

    FILE *aFILE;
    aFILE = fopen("ageGraphData.txt","w");

    if (aFILE == NULL) {
        printf("Error opening file\n");
    return 1;
    }

    fprintf(aFILE,"%-15s %-15s %-15s %-15s %-18s %-15s\n", "Age Group", "Canada", "Ontario", "Quebec", "British Columbia", "Alberta");
    fprintf(aFILE,"%-15s %-15.2f %-15.2f %-15.2f %-18.2f %-15.2f\n", "35-49", avgCanadaAgrGrp1, avgOntarioAgrGrp1, avgQuebecAgrGrp1, avgColumbiaAgrGrp1, avgAlbertaAgrGrp1);
    fprintf(aFILE,"%-15s %-15.2f %-15.2f %-15.2f %-18.2f %-15.2f\n", "50-64", avgCanadaAgrGrp2, avgOntarioAgrGrp2, avgQuebecAgrGrp2, avgColumbiaAgrGrp2, avgAlbertaAgrGrp2);
    fprintf(aFILE,"%-15s %-15.2f %-15.2f %-15.2f %-18.2f %-15.2f\n", "64+", avgCanadaAgrGrp3, avgOntarioAgrGrp3, avgQuebecAgrGrp3, avgColumbiaAgrGrp3, avgAlbertaAgrGrp3);

    return 0;
}

/*------------------------------------------------*/
/*      FUNCTIONS THAT HELPED SOLVED Q1 HERE      */
/*------------------------------------------------*/

double CalculateProvinceAvg(Data data[], char *filter) {
    double numVal = 0;
    int count = 0;

    for (int j = 0; j < 211; j++) {
        if (strcmp(data[j].geo, filter) == 0) {
            numVal += data[j].doubleVal;
            if(data[j].doubleVal != 0){
                count++;
            }
        }
    }
    double avg = numVal/count;

    return avg; 

}

double CalculateProvinceAndYearAvg(Data data[], char *filter, char *filter2) {
    double numVal = 0;
    int count = 0;

    for (int j = 0; j < 211; j++) {
        if (strcmp(data[j].geo, filter) == 0 && strcmp(data[j].refDate, filter2) == 0) {
            numVal = numVal + data[j].doubleVal;
            if(data[j].doubleVal != 0){
                count++;
            }
        }
    }
    double avg = numVal/count;
    return avg; 
}

double CalculateProvinceWithAgeAvg(Data data[], char *filter, char *filter2) {
    double numVal = 0;
    int count = 0;

    for (int j = 0; j < 211; j++) {
        if (strcmp(data[j].geo, filter) == 0 && strcmp(data[j].groupAge, filter2) == 0) {
            numVal = numVal + data[j].doubleVal;
            if(data[j].doubleVal != 0){
                count++;
            }
        }
    }
    double avg = numVal/count;

    return avg; 
}
