//
// Created by haibo on 10/23/21.
//

#ifndef JIUZHAI_VECTORSERVICE_H
#define JIUZHAI_VECTORSERVICE_H

#include <faiss/MetaIndexes.h>
#include <faiss/IndexFlat.h>
#include <faiss/Index.h>
#include <unordered_map>
#include <vector>
#include <tuple>

using namespace std;
using idx_t = faiss::Index::idx_t;
using Index = faiss::Index;
using IndexFlatIP = faiss::IndexFlatIP;
using IndexIDMap2 = faiss::IndexIDMap2Template<Index>;

class VectorService {
public:
    VectorService(int d) : _d(d) {}

    void rebuild_index_by_category(string&, int, const float **, vector<int64_t>&);

    tuple<int64_t *, float *> search(vector<string>, const float *, int, float);
private:
    int _d;

    unordered_map<string, IndexIDMap2*> indices;
};
#endif //JIUZHAI_VECTORSERVICE_H
