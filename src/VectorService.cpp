//
// Created by haibo on 10/23/21.
//
#include "VectorService.h"
#include <algorithm>
#include <iterator>

void VectorService::rebuild_index_by_category(string& category, int n, const float** d2, vector<int64_t>& ids) {
    IndexFlatIP *index = new IndexFlatIP(_d);
    IndexFlatIPMap indexMap(index);
    float *d1 = new float(_d * n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < _d; j++) {
            int loc = i * _d + j;
            d1[loc] = d2[i][j];
        }
    }
    int64_t* pids = ids.data();
    indexMap.add_with_ids(n, d1, pids);

    auto map_it = indices.find(category);
}

tuple<int64_t *, float *> VectorService::search(vector<string> categories, float *q, int k, float min_score) {

}
