#include<bits/stdc++.h>
using namespace std;

vector<int> processMemoryEvents(int N, string events) {
    // Free intervals: [start, end], kept in two structures:
    map<int, int> freeByStart;               // start -> end
    set<pair<int, int>> freeBySize;          // (length, start)

    auto insertFree = [&](int l,int r) {
        if (l > r) return;
        int len = r - l + 1;
        freeByStart[l] = r;
        freeBySize.insert({len, l});
    };
    auto eraseFree = [&](int l,int r) {
        if (l > r) return;
        int len = r - l + 1;
        freeByStart.erase(l);
        freeBySize.erase({len, l});
    };

    if (N > 0) insertFree(0, N - 1);

    unordered_map<int, int> alloc; // start -> size
    int allocatedBlocks = 0;
    long long allocatedUnits = 0;

    int i = 0, L = (int)events.size();
    while (i < L) {
        char op = events[i++];
        long long num = 0;
        bool hasDigit = false;
        while (i < L && isdigit((unsigned char)events[i])) {
            hasDigit = true;
            num = num * 10 + (events[i] - '0');
            ++i;
        }
        if (!hasDigit) continue;
        int x = (int)num;

        if (op == 'A') {
            if (x <= 0) continue;
            auto it = freeBySize.lower_bound({x, -1}); // best-fit
            if (it == freeBySize.end()) continue;       // no block fits

            int len = it->first;
            int st = it->second;
            int en = freeByStart[st];

            eraseFree(st, en);            // consume chosen free block

            if (len > x) {                // leftover free part
                int nst = st + x;
                int nen = en;
                insertFree(nst, nen);
            }

            alloc[st] = x;
            ++allocatedBlocks;
            allocatedUnits += x;
        } else if (op == 'F') {
            auto itA = alloc.find(x);
            if (itA == alloc.end()) continue; // nothing to free

            int sz = itA->second;
            alloc.erase(itA);
            --allocatedBlocks;
            allocatedUnits -= sz;

            int l = x, r = x + sz - 1;

            // merge with left neighbor if adjacent
            auto itRight = freeByStart.upper_bound(l);
            if (itRight != freeByStart.begin()) {
                auto itLeft = prev(itRight);
                if (itLeft->second + 1 == l) {
                    int ll = itLeft->first, rr = itLeft->second;
                    eraseFree(ll, rr);
                    l = ll;
                }
            }
            // merge with right neighbor if adjacent
            auto itNext = freeByStart.lower_bound(r + 1);
            if (itNext != freeByStart.end() && itNext->first == r + 1) {
                int ll = itNext->first, rr = itNext->second;
                eraseFree(ll, rr);
                r = rr;
            }

            insertFree(l, r);
        }
    }

    return {allocatedBlocks, (int)allocatedUnits};
}