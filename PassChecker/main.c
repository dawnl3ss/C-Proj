#include <stdio.h>
#include <stdlib.h>

void* my_strlen(char *str, int *count){
    for (int i = 0; *(str + i) != '\0'; i++){ (*count)++; }
}

void* main(int argc, char **argv){

    if (argc < 2){
        printf("[-] No password detected. Quitting...");
        return NULL;
    } else if (argc > 2){
        printf("[-] Too many arguments provided. Quitting...");
        return NULL;
   }

    char *passwd = argv[1];
    char *s_len;
    int s_num = 0;

    // - Check for length
    int len = 0;
    my_strlen(passwd, &len);

    int weak[2] = {1, 6};
    int medium[2] = {7, 12};
    int strong[2] = {13, 20};
    int verystrong = 21;

    if (len >= weak[0] && len <= weak[1])
        s_len = "Weak";
    else if (len >= medium[0] && len <= medium[1])
        s_len = "Medium";
    else if (len >= strong[0] && len <= strong[1])
        s_len = "Strong";
    else
        s_len = "Very strong";


    // - Check for numbers
    int count = 0;
    int ascii_num[2] = {48, 57};

    for (int i = 0; *(passwd + i) != '\0'; i++){
        char ptr = *(passwd + i);

        if ((int)ptr >= ascii_num[0] && (int)ptr <= ascii_num[1]){
            s_num = 1;

            count++;
        }
    }

    printf("╔═══════════════════════════════\n");
    printf("║\n");
    printf("╟──╼ Password : %s\n", passwd);
    printf("║\n");
    printf("╟ Length : %d ─╼ %s\n", len, s_len);
    printf("║\n");
    if (s_num == 1)
      printf("╟ Number(s) : %d ─╼ ✓\n", count);
    else
      printf("╟ Number(s) : %d ─╼ ✗\n", count);
    printf("║\n");
    printf("╚═══════════════════════════════\n");
}
