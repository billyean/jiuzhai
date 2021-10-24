//
// Created by haibo on 10/23/21.
//
#include "VectorService.h"
#include <algorithm>
#include <iterator>
#include <string.h>

void VectorService::rebuild_index_by_category(string& category, int n, const float** d2, vector<int64_t>& ids) {
    Index *index = new IndexFlatIP(_d);
    IndexIDMap2* pIdMap2Template = new IndexIDMap2(index);
    // from two-dimensional float array to one-dimensional float array
    float *d1 = new float(_d * n);
    for (int i = 0; i < n; i++) {
        int loc = i * _d;
        memcpy(d1 + loc, d2[i], sizeof(float) * _d);
    }
    int64_t* pids = ids.data();
    pIdMap2Template->add_with_ids(n, d1, pids);

    auto map_it = indices.find(category);
    IndexIDMap2 *old;
    if (map_it != indices.end()) {
        old = indices[category];
    }
    indices[category] = pIdMap2Template;
    if (old != NULL) {
        delete(old);
    }
}

tuple<int64_t *, float *> VectorService::search(vector<string> categories, const float *q, int k, float min_score) {
    idx_t* I = new idx_t[k * categories.size()];
    for (auto it = categories.begin(); it != categories.end(); it++) {
        string category = *it;
        if (indices.find(category) != indices.end()) {
            IndexIDMap2 *index = indices[category];
            index->search(_d, q, k, &min_score, NULL);
        }
    }
    tuple<int64_t *, float *> result;
    return std::move(result);
}
