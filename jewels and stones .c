#include <stdio.h>
int numJewelsInStones(char *J, char *S) {
    int count = 0;
    while (*S != '\0') {
        char *ptr = J;
        while (*ptr != '\0') {
            if (*ptr == *S) {
                count++;
                break;
            }
            ptr++;
        }
        S++;
    }
    
    return count;
}
int main() {
    char J[] = "aA";
    char S[] = "aAAbbbb";
    int result = numJewelsInStones(J, S);
    printf("Number of jewels: %d\n", result);
    return 0;
}
