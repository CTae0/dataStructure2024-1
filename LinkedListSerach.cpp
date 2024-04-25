//202114292 컴퓨터공학과 최태영
//search_list 추가한 버젼
#include <iostream>

using namespace std;

typedef int element;
typedef struct ListNode { // 노드 타입을 구조체로 정의한다.
    element data;
    struct ListNode* link;
} ListNode;

ListNode* insert_first(ListNode* head, element value){
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    p->data = value;
    p->link = head;
    head = p;
    return head;
}

// 노드 pre 뒤에 새로운 노드 삽입
ListNode* insert(ListNode* head, ListNode* pre, element value){
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    p->data = value;
    p->link = pre->link;
    pre->link = p;
    return head;
}

ListNode* remove_first(ListNode* head){
    ListNode* removed;
    if (head == NULL)
        return NULL;
    removed = head;
    head = removed->link;
    free(removed);
    return head;
}

ListNode* remove(ListNode* head, ListNode* pre){
    ListNode* removed;
    removed = pre->link;
    pre->link = removed->link;
    free(removed);
    return head;
}

void print_list(ListNode* head){
    for (ListNode* p = head; p != NULL; p = p->link)
        cout << p->data << "->";
    printf("NULL \n");
}

ListNode* search_list(ListNode* head, element findx) {
    
    for (ListNode* p = head; p != NULL; p = p->link) {
        if (p->data == findx)
            return p;
        }
    return NULL;
}

int main(){
    ListNode* head = NULL;
    string str;
    for (int i = 0; i < 5; i++) {
        head = insert_first(head, i*10);
        print_list(head);
    }
    if(search_list(head, 30) != NULL) {
        cout << "리스트에서 30을 찾았습니다.\n";
    }
    for (int i = 0; i < 5; i++) {
        head = remove_first(head);
        print_list(head);
    }
    return 0;
}

