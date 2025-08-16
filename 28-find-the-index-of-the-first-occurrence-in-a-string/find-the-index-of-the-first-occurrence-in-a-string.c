int strStr(char* haystack, char* needle) {
    int n = strlen(haystack);
    int m = strlen(needle);

    if (m == 0) {
        // empty string for needle
        return 0;
    }

    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && haystack[i + j] == needle[j]) {
            // laymans: while the value of J is less than the max length of string `needle`,
            // AND the i'th (fixed technically when we're in here) + j'th element is equal to the j'th element of needle
            // we will continue and iterate on j. Once j == m, or we don't match, we will break out 
            // and check if we're a match. If not, we'll just iterate to the next i'th element.
            j++;
        }

        if (j == m) {
            // full match
            return i;
        }
    }

    return -1;
}