#include <stdio.h>
#include <stdlib.h>
#define MAX_LIST_SIZE 100

typedef int element;
typedef struct ArrayListType {
	element list[MAX_LIST_SIZE]; // 배열 정의
	element length; 
	// 현재 배열에 저장된 항목들의 개수
}ArrayListType;
// 리스트 초기화

void init(ArrayListType *L);
element is_empty(ArrayListType *L);
element is_full(ArrayListType *L);
void add(ArrayListType *L, element position, element item);
element deleteF(ArrayListType *L, element position);
void display(ArrayListType *L);

element main() {
	ArrayListType list1;
	init(&list1);
	add(&list1, 0, 10);
	add(&list1, 0, 20);
	add(&list1, 0, 30);
	display(&list1);
	printf("\n");
	deleteF(&list1, 2);
	display(&list1);
	return 0;
}

void init(ArrayListType *L)
{
	L->length = 0;
}

// 리스트가 비어 있으면 1을 반환
// 그렇지 않으면 0을 반환
element is_empty(ArrayListType *L)
{
	return L->length == 0;
}
// 리스트가 가득 차 있으면 1을 반환
// 그렇지 많으면 0 을 반환
element is_full(ArrayListType *L)
{
	return L->length == MAX_LIST_SIZE;
}

// position： 삽입하고자 하는 위치
// item： 삽입하고자 하는 자료
void add(ArrayListType *L, element position, element item)
{
	element i;
	
	if (!is_full(L) && (position >= 0) && (position <= L->length)) {
	for (i = (L->length - 1); i >= position; i--)
		L->list[i+1] = L->list[i];
		L->list[position] = item;
		L->length++;
	}
}
// position: 삭제하고자 하는 위치
// 반환값: 삭제되는 자료
element deleteF(ArrayListType *L, element position)
{
	element i;
	element item;
	if (position < 0 || position >= L->length)
		printf("위치 오류\n");

	item = L->list[position];
	for (i=position; i<=(L->length-1); i++)
		L->list[i] = L->list[i+1];
	L->length--;
	return item;
}

void	display(ArrayListType *L)
{
	element	i;

	i = 0;
	while (i < L->length)
	{
		printf("%d ", L->list[i]);
		i++;
	}
}