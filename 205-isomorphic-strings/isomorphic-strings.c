bool isIsomorphic(char* s, char* t) {
    size_t lenS = strlen(s);
    size_t lenT = strlen(t);

    // learned about this methodology, not my favorite, but I'm coming from C++
    // maps for s->t and t->s
    int mapST[256];
    int mapTS[256];

    // Initialize to -1 (no mapping occurring yet)
    for (int i = 0; i < 256; i++) {
        mapST[i] = -1;
        mapTS[i] = -1;
    }

    for (int i = 0; i < lenS; i++) {
        unsigned char c1 = s[i];
        unsigned char c2 = t[i];

        if (mapST[c1] == -1 && mapTS[c2] == -1) {
            // establish mapping
            mapST[c1] = c2;
            mapTS[c2] = c1;
        } else {
            if (mapST[c1] != c2 || mapTS[c2] != c1) {
                // check if we're getting a different key-value pair for either letter
                return false;
            }
        }
    }

    return true;
}