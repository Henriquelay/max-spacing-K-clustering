#include "../lib/data.h"

int main(int argc, char** argv) {
    char* filename = argv[1];
    FILE* file = openFile(filename);
    // size_t tokenAmount = getLineSize(file, ",", buffer, &bufferSize);
    // char** tokens = readLine(file, ",", buffer, &bufferSize, &tokenAmount);

    // for (int i = 0; i < tokenAmount; i++) {
    //     printf("%s ", tokens[i]);
    // }
    // puts("");

    data_t* data = loadData(file, ",");

    printData(data);

    // unsigned int k = atoi(argv[2]);
    // char* outputFile = argv[3];
    closeFile(file);
    // free(tokens);
}
