#include <stdio.h>
#include <string.h>

#define MAX_ABONENTS 100
#define FILENAME "data_base.txt"

struct abonent {
    char name[50];
    char second_name[50];
    char tel[20];
};

void kill_abonent(struct abonent *a) {
    strcpy(a->name, "");
    strcpy(a->second_name, "");
    strcpy(a->tel, "");
}

void print_abonent(const struct abonent *a, int index) {
    printf("%d. Имя: %s, Фамилия: %s, Телефон: %s\n", index + 1, a->name,
           a->second_name, a->tel);
}

void save_to_file(struct abonent *book, int count) {
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("не удалось открыть файл для записи.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        if (strlen(book[i].name) > 0) {
            fprintf(file, "%s %s %s\n", book[i].name, book[i].second_name,
                    book[i].tel);
        }
    }

    fclose(file);
    printf("Информация об абоненах сохранена: \"%s\".\n", FILENAME);
}

int main() {
    struct abonent book[MAX_ABONENTS] = {0};
    int choice;
    int count = 0;

    while (1) {
        printf("\nМеню:\n");
        printf("1) Добавить абонента\n");
        printf("2) Удалить абонента\n");
        printf("3) Поиск абонентов по имени\n");
        printf("4) Вывод всех записей\n");
        printf("5) Выход\n");
        printf("Выберите пункт: ");
        scanf("%d", &choice);

        if (choice == 5) {
            save_to_file(book, count);
            break;
        }

        switch (choice) {
        case 1:
            if (count >= MAX_ABONENTS) {
                printf("Абонентов в базе слишком много. Избавьтесь от "
                       "кого-нибудь\n");
                break;
            }
            printf("Введите имя: ");
            scanf("%s", book[count].name);
            printf("Введите фамилию: ");
            scanf("%s", book[count].second_name);
            printf("Введите телефон: ");
            scanf("%s", book[count].tel);
            count++;
            printf("Абонент добавлен.\n");
            break;

        case 2: {
            int index;
            printf("Номер абонента: (1-%d): ", count);
            scanf("%d", &index);
            if (index < 1 || index > count) {
                printf("Некорректный номер абонента.\n");
            } else {
                kill_abonent(&book[index - 1]);
                printf("Абонент удалён.\n");
            }
            break;
        }

        case 3: {
            char search_name[50];
            printf("Введите имя для поиска: ");
            scanf("%s", search_name);
            int found = 0;
            for (int i = 0; i < count; i++) {
                if (strcmp(book[i].name, search_name) == 0) {
                    print_abonent(&book[i], i);
                    found = 1;
                }
            }
            if (!found) {
                printf("Абонента с именем '%s' нет в контактах.\n",
                       search_name);
            }
            break;
        }

        case 4:
            printf("Список всех абонентов:\n");
            for (int i = 0; i < count; i++) {
                if (strlen(book[i].name) > 0) {
                    print_abonent(&book[i], i);
                }
            }
            break;

        default:
            printf("Попробуйте снова.\n");
        }
    }

    return 0;
}