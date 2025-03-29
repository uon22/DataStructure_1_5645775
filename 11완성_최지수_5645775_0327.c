/*
FUNCTION StudentManagement()
    //연결 리스트로 학생 정보 저장 및 검색

    //학생 구조체 정의
    STRUCT Student
        name AS char[20]
        id AS int
        score AS int
        next AS Student*

    DECLARE head AS Student* = NULL //첫 번째 학생 노드

    FUNCTION addStudent(name, id, score)
        ALLOCATE new Student
        IF allocation fails THEN
            PRINT "메모리 할당 실패"
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
                PRINT "이름:", current.name, " 학번:", current.id, " 점수:", current.score
                RETURN
            SET current = current.next
        PRINT "해당 학번의 학생이 없습니다."

    FUNCTION freeStudents()
        SET current = head
        WHILE current IS NOT NULL DO
            SET temp = current
            SET current = current.next
            FREE temp

    FUNCTION main()
        PRINT "몇 명의 학생 정보를 입력하시나요? "
        INPUT n
        IF n <= 0 THEN
            PRINT "잘못된 입력"
            RETURN ERROR

        FOR i FROM 1 TO n DO
            PRINT "학생 정보 입력 (이름 학번 점수): "
            INPUT name, id, score
            CALL addStudent(name, id, score)

        WHILE TRUE DO
            PRINT "학번을 입력하세요 (0이면 종료): "
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
        printf("메모리 할당 실패\n");
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
            printf("이름: %s, 학번: %d, 점수: %d\n", current->name, current->id, current->score);
            return;
        }
        current = current->next;
    }
    printf("해당 학번의 학생이 없습니다.\n");
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

    printf("몇 명의 학생 정보를 입력하시나요? ");
    if (scanf_s("%d", &n) != 1 || n <= 0) {
        printf("잘못된 입력입니다. 프로그램을 종료합니다.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("[%d] 학생 정보 입력 (이름 학번 점수): ", i + 1);
        if (scanf_s("%19s", name, (unsigned)_countof(name)) != 1 ||
            scanf_s("%d", &id) != 1 || scanf_s("%d", &score) != 1) {
            printf("입력 형식이 잘못되었습니다. 프로그램을 종료합니다.\n");
            freeStudents();
            return 1;
        }
        addStudent(name, id, score);
    }

    while (1) {
        printf("학번을 입력하세요(0이면 종료): ");
        if (scanf_s("%d", &id) != 1) {
            printf("잘못된 입력입니다. 프로그램을 종료합니다.\n");
            freeStudents();
            return 1;
        }
        if (id == 0) break;
        findStudent(id);
    }

    freeStudents();
    return 0;
}
