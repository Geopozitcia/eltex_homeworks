#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "data_base.txt"

struct abonent {
    char name[50];
    char second_name[50];
    char tel[20];
    struct abonent *next;
    struct abonent *prev;
};

struct abonent *create_abonent(const char *name, const char *second_name,
                               const char *tel) {
    struct abonent *new_abonent =
        (struct abonent *)malloc(sizeof(struct abonent));
    if (new_abonent == NULL) {
        printf("Ошибка выделения памяти.\n");
        return NULL;
    }
    strcpy(new_abonent->name, name);
    strcpy(new_abonent->second_name, second_name);
    strcpy(new_abonent->tel, tel);
    new_abonent->next = NULL;
    new_abonent->prev = NULL;
    return new_abonent;
}

void delete_abonent(struct abonent **head, struct abonent *ab) {
    if (ab == NULL)
        return;
    if (*head == ab) {
        *head = ab->next;
    }
    if (ab->next != NULL) {
        ab->next->prev = ab->prev;
    }
    if (ab->prev != NULL) {
        ab->prev->next = ab->next;
    }
    free(ab);
}

void print_abonents(struct abonent *head) {
    int index = 1;
    struct abonent *current = head;
    while (current != NULL) {
        printf("%d. Имя: %s, Фамилия: %s, Телефон: %s\n", index++,
               current->name, current->second_name, current->tel);
        current = current->next;
    }
}

void save_to_file(struct abonent *head) {
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("Не удалось открыть файл для записи.\n");
        return;
    }

    struct abonent *current = head;
    while (current != NULL) {
        fprintf(file, "%s %s %s\n", current->name, current->second_name,
                current->tel);
        current = current->next;
    }

    fclose(file);
    printf("Информация об абонентах сохранена: \"%s\".\n", FILENAME);
}

void search_abonent(struct abonent *head, const char *search_name) {
    struct abonent *current = head;
    int found = 0;
    while (current != NULL) {
        if (strcmp(current->name, search_name) == 0) {
            printf("Найден абонент: Имя: %s, Фамилия: %s, Телефон: %s\n",
                   current->name, current->second_name, current->tel);
            found = 1;
        }
        current = current->next;
    }
    if (!found) {
        printf("Абонента с именем '%s' нет в контактах.\n", search_name);
    }
}

void clear_input_buffer() {
    while (getchar() != '\n')
        ;
}

int main() {
    struct abonent *head = NULL;
    struct abonent *tail = NULL;
    int choice;

    while (1) {
        printf("\nМеню:\n");
        printf("1) Добавить абонента\n");
        printf("2) Удалить абонента\n");
        printf("3) Поиск абонентов по имени\n");
        printf("4) Вывод всех записей\n");
        printf("5) Выход\n");
        printf("Выберите пункт: ");

        if (scanf("%d", &choice) != 1) {
            printf("Неверный ввод! Пожалуйста, введите число от 1 до 5.\n");
            clear_input_buffer();
            continue;
        }

        if (choice == 5) {
            save_to_file(head);
            struct abonent *current = head;
            while (current != NULL) {
                struct abonent *next = current->next;
                free(current);
                current = next;
            }
            break;
        }

        switch (choice) {
        case 1: {
            char name[50], second_name[50], tel[20];
            printf("Введите имя: ");
            scanf("%s", name);
            printf("Введите фамилию: ");
            scanf("%s", second_name);
            printf("Введите телефон: ");
            scanf("%s", tel);

            struct abonent *new_abonent =
                create_abonent(name, second_name, tel);
            if (new_abonent == NULL)
                break;

            if (head == NULL) {
                head = new_abonent;
                tail = new_abonent;
            } else {
                tail->next = new_abonent;
                new_abonent->prev = tail;
                tail = new_abonent;
            }

            printf("Абонент добавлен.\n");
            break;
        }

        case 2: {
            int index;
            printf("Номер абонента для удаления: ");
            scanf("%d", &index);

            struct abonent *current = head;
            int i = 1;
            while (current != NULL && i < index) {
                current = current->next;
                i++;
            }
            if (current != NULL) {
                delete_abonent(&head, current);
                printf("Абонент удалён.\n");
            } else {
                printf("Некорректный номер абонента.\n");
            }
            break;
        }

        case 3: {
            char search_name[50];
            printf("Введите имя для поиска: ");
            scanf("%s", search_name);
            search_abonent(head, search_name);
            break;
        }

        case 4:
            printf("Список всех абонентов:\n");
            print_abonents(head);
            break;

        default:
            printf("Попробуйте снова.\n");
        }
    }

    return 0;
}