vector <int> countOperationsToK(vector <long> kValues) {

    vector<int> ret(kValues.size());

    for(int i = 0; i < kValues.size(); i++) {
        int n = 0;
        long l = kValues[i];
        n += l & 1;
        l >>= 1;
        while (l != 0) {
            n++;
            n += l & 1;
            l >>= 1;
        }
        ret[i] = n;
    }

    return ret;

}
