#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define MAX_LINE 200

void greetBasedOnTime() {
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    int hour = tm_info->tm_hour;

    if (hour < 12)
        printf("Good Morning!\n");
    else if (hour < 18)
        printf("Good Afternoon!\n");
    else
        printf("Good Evening!\n");
}

char *getAnswer(char *question) {
    static char answer[200];
    FILE *file = fopen("knowledge.txt", "r");
    if (!file) return NULL;

    char line[MAX_LINE];
    while (fgets(line, sizeof(line), file)) {
        char *q = strtok(line, "=");
        char *a = strtok(NULL, "=");

        if (q && a && strcmp(q, question) == 0) {
            a[strcspn(a, "\n")] = 0;
            strcpy(answer, a);
            fclose(file);
            return answer;
        }
    }
    fclose(file);
    return NULL;
}

void saveAnswer(char *question, char *answer) {
    FILE *file = fopen("knowledge.txt", "a");
    if (!file) {
        printf("Error opening file!\n");
        return;
    }
    fprintf(file, "%s=%s\n", question, answer);
    fclose(file);
}

void cleanInput(char *str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;
    }
    str[strcspn(str, "\n")] = 0;
}

void randomReply() {
    char *replies[] = {
        "That's interesting!",
        "Hmm, tell me more...",
        "I enjoy chatting with you.",
        "Wow, really?",
        "Great! What next?"
    };
    int n = sizeof(replies) / sizeof(replies[0]);
    printf("%s\n", replies[rand() % n]);
}

void startChat() {
    char question[200], answer[200];

    greetBasedOnTime();
    printf("I am your C Chatbot! Type 'exit' to quit.\n\n");

    fflush(stdin);

    while (1) {
        printf("You: ");
        fgets(question, sizeof(question), stdin);
        cleanInput(question);

        if (strcmp(question, "exit") == 0) {
            printf("Bot: Bye! Have a nice day!\n");
            break;
        }

        char *savedAns = getAnswer(question);
        if (savedAns) {
            printf("Bot: %s\n", savedAns);
            randomReply();
        } else {
            printf("Bot: I don't know that yet. Can you teach me? (yes/no)\n");

            char choice[10];
            fgets(choice, sizeof(choice), stdin);
            cleanInput(choice);

            if (strcmp(choice, "yes") == 0) {
                printf("Teach me the answer: ");
                fgets(answer, sizeof(answer), stdin);
                cleanInput(answer);

                saveAnswer(question, answer);
                printf("Bot: Got it! I will remember this.\n");
            } else {
                printf("Bot: Okay! Ask me something else.\n");
            }
        }
    }
}

int main() {
    srand(time(NULL));
    startChat();
    return 0;
}
