//
// Created by haibo on 10/23/21.
//

#ifndef JIUZHAI_VECTORSERVICE_H
#define JIUZHAI_VECTORSERVICE_H

#include <faiss/MetaIndexes.h>
#include <faiss/IndexFlat.h>
#include <unordered_map>
#include <vector>
#include <tuple>

using namespace std;
using IndexFlatIP = faiss::IndexFlatIP;
using IndexFlatIPMap = faiss::IndexIDMap2Template<IndexFlatIP>;

class VectorService {
public:
    VectorService(int d) : _d(d) {}

    void rebuild_index_by_category(string&, int, const float **, vector<int64_t>&);

    tuple<int64_t *, float *> search(vector<string>, float *, int, float);
private:
    int _d;

    unordered_map<string, IndexFlatIPMap> indices;
};
#endif //JIUZHAI_VECTORSERVICE_H
