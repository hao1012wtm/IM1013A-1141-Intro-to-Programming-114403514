#include <stdio.h>

int main(void){
    int input, password, guess;
    int has_duplication = 1;
    int attempts = 1;
    int A, B;
    int result;

    printf("Enter a 4-digit number to generate a password:\n");
    result = scanf("%d", &input);

    // 檢查輸入是否為4位數數字
    while (result != 1 || input < 1000 || input > 9999){
        printf("Invalid input! Please enter a 4-digit number.\n");
        while (getchar() != '\n');
        result = scanf("%d", &input);
    }

    // 產生密碼
    password = ((input * 3) + 1357) % 10000;
    has_duplication = 1;

    // 檢查密碼是否有重複數字
    while (has_duplication == 1){
        int digits[10] = {0};
        int temp = password;
        has_duplication = 0;
        while (temp > 0){
            int d = temp % 10;
            digits[d]++;
            if (digits[d] > 1){
                has_duplication = 1;
                break;
            }
            temp /= 10;
        }
        if (has_duplication == 1){
            input = password;
            password = ((input * 3) + 1357) % 10000;
        }
    }

    printf("\nA secret password has been generated.\n\n");

    // ===== 猜密碼遊戲開始 =====
    while (attempts <= 10){
        printf("--- ROUND %d ---\n", attempts);
        printf("Enter a 4-digit number: ");

        result = scanf("%d", &guess);
        if (result != 1){
            printf("Invalid input! Please enter a 4-digit number.\n\n");
            while (getchar() != '\n');
            continue;
        }

        if (guess < 1000 || guess > 9999){
            printf("Invalid input! Please enter a 4-digit number.\n\n");
            continue;
        }

        // ===== 計算幾A幾B =====
        int pwDigits[4], gsDigits[4];
        int tempP = password;
        int tempG = guess;
        for (int i = 3; i >= 0; i--){
            pwDigits[i] = tempP % 10;
            gsDigits[i] = tempG % 10;
            tempP /= 10;
            tempG /= 10;
        }

        A = 0;
        B = 0;
        for (int i = 0; i < 4; i++){
            if (gsDigits[i] == pwDigits[i]){
                A++;
            } else {
                for (int j = 0; j < 4; j++){
                    if (i != j && gsDigits[i] == pwDigits[j]){
                        B++;
                    }
                }
            }
        }

        printf("feedback: %dA%dB\n\n", A, B);

        if (A == 4){
            printf("GAME ENDS. YOU WIN THE GAME!!\n");
            return 0;
        }

        attempts++;
    }

    printf("The correct password is %04d.\n\n", password);
    printf("GAME OVER.\nYOU LOSE THE GAME.\n");

    return 0;
}
