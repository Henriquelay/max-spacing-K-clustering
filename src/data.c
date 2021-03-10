#include "../lib/data.h"

data_t* loadData(FILE* file, const char* separator) {
    char buffer[5000];
    size_t bufferSize = 0;

    data_t* dataStruct = (data_t*)malloc(sizeof(data_t));
    if (dataStruct == NULL) {
        perror("Error allocating new dataStructure. Exiting");
        exit(1);
    };

    dataStruct->i = countLines(file);
    dataStruct->j = getLineSize(file, separator, buffer, &bufferSize);


    // 0 will always be id, read as `char*`.
    dataStruct->dataMatrix = (void***)malloc(sizeof(void**) * dataStruct->i);
    if (dataStruct->dataMatrix == NULL) {
        perror("Error allocating new dataString lines. Exiting");
        exit(1);
    }

    // void** line = NULL;
    for (int i = 0; i < dataStruct->i; i++) {
        dataStruct->dataMatrix[i] = readLine(file, separator, buffer, &bufferSize, &dataStruct->j);
    }

    return dataStruct;
}

void printData(const data_t *dataStruct) {
    for (int i = 0; i < dataStruct->i; i++) {
        printf("%s", (char*)dataStruct->dataMatrix[i][0]);
        for (int j = 1; j < dataStruct->j; j++) {
            printf(",%.15Lf", *((long double*)dataStruct->dataMatrix[i][j]));
        }
        puts("");
    }
}

