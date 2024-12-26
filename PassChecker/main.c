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
    int s_min = 0;
    int s_up = 0;

    // - Check for length
    int len = 0;
    my_strlen(passwd, &len);

    int weak[2] = {1, 6};
    int medium[2] = {7, 12};
    int strong[2] = {13, 20};
    int verystrong = 21;

    if (len >= weak[0] && len <= weak[1])
        s_len = "\033[31mWeak\033[0m";
    else if (len >= medium[0] && len <= medium[1])
        s_len = "\033[33mMedium\033[0m";
    else if (len >= strong[0] && len <= strong[1])
        s_len = "\033[32mStrong\033[0m";
    else
        s_len = "\033[34mVery strong\033[0m";


    // - Check for numbers
    int num_count = 0;
    int ascii_num[2] = {48, 57};

    for (int i = 0; *(passwd + i) != '\0'; i++){
        char ptr = *(passwd + i);

        if ((int)ptr >= ascii_num[0] && (int)ptr <= ascii_num[1]){
            s_num = 1;
            num_count++;
        }
    }

    // - Check for min letters
    int min_count = 0;
    int ascii_min[2] = {97, 122};

    for (int i = 0; *(passwd + i) != '\0'; i++){
        char ptr = *(passwd + i);

        if ((int)ptr >= ascii_min[0] && (int)ptr <= ascii_min[1]){
            s_min = 1;
            min_count++;
        }
    }


    // - Check for upper letters
    int up_count = 0;
    int ascii_up[2] = {65, 90};

    for (int i = 0; *(passwd + i) != '\0'; i++){
        char ptr = *(passwd + i);

        if ((int)ptr >= ascii_up[0] && (int)ptr <= ascii_up[1]){
            s_up = 1;
            up_count++;
        }
    }


    // --- Final Check ---
    int score = 0;
    char *score_str;

    if (len >= weak[0] && len <= weak[1])
        score += 0;
    else if (len >= medium[0] && len <= medium[1])
        score += 2;
    else if (len >= strong[0] && len <= strong[1])
        score += 4;
    else
        score += 6;

    if (s_num == 1)
        score += 1;
    if (s_min == 1)
        score += 1;
    if (s_up == 1)
        score += 1;

    if (score >= 0 && score <= 4)
        score_str = "\033[31mWeak\033[0m";
    else if (score >= 5 && score <= 7)
        score_str = "\033[33mMedium\033[0m";
    else
        score_str = "\033[34mStrong\033[0m";

    printf("╔═══════════════════════════════\n");
    printf("║\n");
    printf("╟──╼ Password : %s\n", passwd);
    printf("║\n");
    printf("╟ Length : %d ─╼ %s\n", len, s_len);
    printf("║\n");
    if (s_num == 1)
        printf("╟ Number(s) : %d ─╼ \033[32m✓\033[0m\n", num_count);
    else
        printf("╟ Number(s) : %d ─╼ \033[31m✗\033[0m\n", num_count);

    printf("║\n");
    
    if (s_min == 1)
        printf("╟ Lower(s) : %d ─╼ \033[32m✓\033[0m\n", min_count);
    else
        printf("╟ Lower(s) : %d ─╼ \033[31m✗\033[0m\n", min_count);

    printf("║\n");

    if (s_up == 1)
        printf("╟ Upper(s) : %d ─╼ \033[32m✓\033[0m\n", up_count);
    else
        printf("╟ Upper(s) : %d ─╼ \033[31m✗\033[0m\n", up_count);

    printf("║\n");
    printf("╟──╼ Result : %s\n", score_str);
    printf("║\n");
    printf("╚═══════════════════════════════\n");
}
