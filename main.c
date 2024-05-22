#include <stdio.h>
#include "student.h"
#include "node.h"

void save_students_to_file(struct Node* head, const char* filename);
struct Node* load_students_from_file(const char* filename);

int main() {
    struct Node* head = NULL;
		
    // Загрузка студентов из файла
    head = load_students_from_file("students.txt"); 

		if (head == NULL) {
			struct Student student1 = {"Pushkin", "Alex", 'M', 20, "Group 1", 4, 3, 5};
			struct Student student2 = {"Mushkina", "Olga", 'F', 19, "Group 2", 5, 5, 3};
		
			append(&head, &student1);
			append(&head, &student2);
		}
    printf("Исходная информация о студентах:\n");
    print_list(head);

    printf("\nСнижение оценки по химии всем студентам на 1 балл...\n");

    struct Node* current = head;
    while (current != NULL) {
				increase_chemistry_grade(&(current->data));
        current = current->next;
    }

    printf("\nОбновленная информация о студентах:\n");
    print_list(head);
    
    //сохраняем
		save_students_to_file(head, "students.txt");

		free_list(head);

    return 0;
}
