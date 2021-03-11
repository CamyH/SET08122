#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int count(struct node *list);
void display(struct node *list);
void append(struct node **list, int num);
void prepend(struct node **list, int num);
void insert_after(struct node *list, int location, int num);
void delete (struct node **list, int num);
void insert_before(struct node *list, int location, int num);

int main()
{
    struct node *list;
    list = NULL;

    printf("Number of elements in linked list = %d\n", count(list));

    append(&list, 14);
    append(&list, 30);
    append(&list, 25);
    append(&list, 42);
    append(&list, 17);
    printf("Number of elements in linked list = %d\n", count(list));
    display(list);

    prepend(&list, 999);
    prepend(&list, 888);
    prepend(&list, 777);
    printf("No of elements in linked list = %d\n", count(list));
    display(list);

    insert_after(list, 1, 0);
    insert_after(list, 2, 1);
    insert_after(list, 5, 99);
    printf("No of elements in linked list = %d\n", count(list));
    display(list);

    insert_after(list, 99, 10);
    printf("No of elements in linked list = %d\n", count(list));
    display(list);

    delete (&list, 99);
    delete (&list, 1);
    printf("No of elements in linked list = %d\n", count(list));
    display(list);

    delete (&list, 10);
    printf("No of elements in linked list = %d\n", count(list));
    display(list);

    return 0;
}

int count(struct node *list)
{
    // Function to count linked list
    int count = 0;
    while (list != NULL)
    {
        list = list->next;
        count++;
    }
    return count;
}

void display(struct node *list)
{
    while (list != NULL)
    {
        printf("%d ", list->data);
        list = list->next;
    }
    printf("\n");
}

void append(struct node **list, int num)
{
    struct node *temp, *r;
    if (*list == NULL)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = num;
        temp->next = NULL;
        *list = temp;
    }
    else
    {
        temp = *list;
        while (temp->next != NULL)
            temp = temp->next;

        r = (struct node *)malloc(sizeof(struct node));
        r->data = num;
        r->next = NULL;
        temp->next = r;
    }
}

void prepend(struct node **list, int num)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    // add data
    temp->data = num;
    // make the new node the head of the linked list
    temp->next = *list;
    // set the head to point to the new node
    *list = temp;
}

void insert_before(struct node *list, int location, int num)
{
    struct node *new_node, *r;
    int i;
    new_node = list;
    for (i = 0; i < location; i++)
    {
        new_node = new_node->next;
        if (new_node == NULL)
        {
            printf("Length of list is %d but supplied location is %d\n", i, location);
            return;
        }
    }
    r = (struct node *)malloc(sizeof(struct node));
    r->data = num;
    r->next = new_node->next;
    new_node->next = r;
}

void insert_after(struct node *list, int location, int num)
{
    struct node *temp, *r;
    int i;
    temp = list;
    for (i = 0; i < location; i++)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            printf("Length of list is %d but supplied location is %d\n", i, location);
            return;
        }
    }
    r = (struct node *)malloc(sizeof(struct node));
    r->data = num;
    r->next = temp->next;
    temp->next = r;
}

void delete (struct node **list, int num)
{
    struct node *old, *temp;
    temp = *list;

    while (temp != NULL)
    {
        if (temp->data == num)
        {
            if (temp == *list)
            {
                *list = temp->next;
            }
            else
            {
                old->next = temp->next;
                free(temp);
                return;
            }
        }
        else
        {
            old = temp;
            temp = temp->next;
        }
    }
    printf("Element %d not found in the supplied list\n", num);
}