#include "../lib/graph.h"

int compareDistanceSamples(const void* a, const void* b) {
    if (((distanceSample_t*)a)->distance < ((distanceSample_t*)b)->distance) return -1;
    if (((distanceSample_t*)a)->distance > ((distanceSample_t*)b)->distance) return 1;
    return 0;
}

union_t* kruskal(distanceDataSet_t* distanceDataSet, size_t groupsNumber) {
    // Qsorting dataSet, Kruskal needs a sorted set
    qsort(distanceDataSet->samples, distanceDataSet->nElements, sizeof(distanceSample_t), &compareDistanceSamples);

    union_t* un = UF_init(distanceDataSet->depth, distanceDataSet->samples);
    size_t currentGroups = distanceDataSet->depth;

    // Not executing K times, don't even need to remove later
    // Sice it's sorted, it's on the 3 largest distances
    for (size_t i = 0; currentGroups != groupsNumber; i++) {
        size_t p = un->samples[i].from->index, q = un->samples[i].to->index;
        if (UF_union(un, p, q) == 1) {
            currentGroups--;
        }
    }

    puts("Final");
    for (size_t i = 0; i < distanceDataSet->depth - groupsNumber; i++) {
        printf("[%ld] %s--%s dist: %Lf cluster: %ld\n", i, un->samples[i].from->id, un->samples[i].to->id, distanceDataSet->samples[i].distance, UF_find(un, i));
    }

    return un;
}

sample_t** sortMST(union_t* MST) {
    return NULL;
}
