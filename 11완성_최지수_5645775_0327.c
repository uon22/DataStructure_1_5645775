/*
FUNCTION StudentManagement()
    //���� ����Ʈ�� �л� ���� ���� �� �˻�

    //�л� ����ü ����
    STRUCT Student
        name AS char[20]
        id AS int
        score AS int
        next AS Student*

    DECLARE head AS Student* = NULL //ù ��° �л� ���

    FUNCTION addStudent(name, id, score)
        ALLOCATE new Student
        IF allocation fails THEN
            PRINT "�޸� �Ҵ� ����"
            RETURN
        COPY name TO newStudent.name
        SET newStudent.id = id
        SET newStudent.score = score
        SET newStudent.next = head
        SET head = newStudent

    FUNCTION findStudent(id)
        SET current = head
        WHILE current IS NOT NULL DO
            IF current.id == id THEN
                PRINT "�̸�:", current.name, " �й�:", current.id, " ����:", current.score
                RETURN
            SET current = current.next
        PRINT "�ش� �й��� �л��� �����ϴ�."

    FUNCTION freeStudents()
        SET current = head
        WHILE current IS NOT NULL DO
            SET temp = current
            SET current = current.next
            FREE temp

    FUNCTION main()
        PRINT "�� ���� �л� ������ �Է��Ͻó���? "
        INPUT n
        IF n <= 0 THEN
            PRINT "�߸��� �Է�"
            RETURN ERROR

        FOR i FROM 1 TO n DO
            PRINT "�л� ���� �Է� (�̸� �й� ����): "
            INPUT name, id, score
            CALL addStudent(name, id, score)

        WHILE TRUE DO
            PRINT "�й��� �Է��ϼ��� (0�̸� ����): "
            INPUT id
            IF id == 0 THEN BREAK
            CALL findStudent(id)

        CALL freeStudents()
END FUNCTION
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char name[20];
    int id;
    int score;
    struct Student* next;
} Student;

Student* head = NULL;

void addStudent(char* name, int id, int score) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    if (newStudent == NULL) {
        printf("�޸� �Ҵ� ����\n");
        return;
    }
    strcpy_s(newStudent->name, sizeof(newStudent->name), name);
    newStudent->id = id;
    newStudent->score = score;
    newStudent->next = head;
    head = newStudent;
}

void findStudent(int id) {
    Student* current = head;
    while (current != NULL) {
        if (current->id == id) {
            printf("�̸�: %s, �й�: %d, ����: %d\n", current->name, current->id, current->score);
            return;
        }
        current = current->next;
    }
    printf("�ش� �й��� �л��� �����ϴ�.\n");
}

void freeStudents() {
    Student* current = head;
    while (current != NULL) {
        Student* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    int n, id, score;
    char name[20];

    printf("�� ���� �л� ������ �Է��Ͻó���? ");
    if (scanf_s("%d", &n) != 1 || n <= 0) {
        printf("�߸��� �Է��Դϴ�. ���α׷��� �����մϴ�.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("[%d] �л� ���� �Է� (�̸� �й� ����): ", i + 1);
        if (scanf_s("%19s", name, (unsigned)_countof(name)) != 1 ||
            scanf_s("%d", &id) != 1 || scanf_s("%d", &score) != 1) {
            printf("�Է� ������ �߸��Ǿ����ϴ�. ���α׷��� �����մϴ�.\n");
            freeStudents();
            return 1;
        }
        addStudent(name, id, score);
    }

    while (1) {
        printf("�й��� �Է��ϼ���(0�̸� ����): ");
        if (scanf_s("%d", &id) != 1) {
            printf("�߸��� �Է��Դϴ�. ���α׷��� �����մϴ�.\n");
            freeStudents();
            return 1;
        }
        if (id == 0) break;
        findStudent(id);
    }

    freeStudents();
    return 0;
}
