#include <stdio.h>
#include <math.h>

int main() {
    int times;
    scanf("%d", &times);

    for(int i = 0; i < times; i++) {
        int totalCard, needCard;
        int flag = 0, answer = 0;

        scanf("%d %d", &totalCard, &needCard);

        while(needCard > (totalCard + 1) / 2) {
            needCard = needCard - ((totalCard + 1) / 2);
            totalCard = totalCard - ((totalCard + 1) / 2);
            flag++;
        }

        // 2*(n-1)+1 -> calculate odd number
        answer = pow(2, flag) * (2 * (needCard - 1) + 1);

        printf("%d\n", answer);
    }

    return 0;
}
