//202114292 최태영 컴퓨터공학과 
//plus_list , reverse() 함수 추가 버젼

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

ListNode* plus_list(ListNode* head, ListNode* head2) {
    if (head == NULL) return head2;
    else if(head ==NULL) return head2;
    else {
        ListNode* p = head;
        while (p-> link != NULL)
            p = p->link;
        p->link = head2;
        return head;
        
    }
    
}

ListNode* reverse(ListNode* head) {
    ListNode* p = head;
    ListNode* n = NULL;
    ListNode* revP;
    
    while (p != NULL) {
        revP = n;
        n = p;
        p = p->link;
        n->link = revP;
    }
    
    return n;
    
}

int main(){
    ListNode* head = NULL;
    ListNode* head2 = NULL;
    string str;
    for (int i = 0; i < 5; i++) {
        head = insert_first(head, i*10);
        print_list(head);
    }
    
    for (int i = 0; i < 3; i++) {
        head2 = insert_first(head2, i*10);
        print_list(head2);
    }
    plus_list(head,head2);
    head2 = reverse(head);
    print_list(head2);
    for (int i = 0; i < 5; i++) {
        head = remove_first(head);
    }
    return 0;
}
