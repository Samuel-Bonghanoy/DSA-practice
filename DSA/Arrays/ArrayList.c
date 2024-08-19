#define SIZE 10

#include <stdio.h>
#include <string.h>

typedef struct
{
    char ID[10];
    char course[8];
} studrec;

typedef struct
{
    studrec Elem[SIZE];
    int count;
} ArrayList;

ArrayList removeList(ArrayList *A, char *course);

int main()
{
    studrec p1 = {"1", "CS"};
    studrec p2 = {"4", "IT"};
    studrec p3 = {"6", "CS"};
    studrec p4 = {"3", "CS"};
    studrec p5 = {"2", "IT"};

    ArrayList A = {{p1, p2, p3, p4, p5}, 5};

    ArrayList B = removeList(&A, "CS");
    int x;
    for (x = 0; x < B.count; x++)
    {
        printf("%s %s\n", B.Elem[x].ID, B.Elem[x].course);
    }
}

ArrayList removeList(ArrayList *A, char *course)
{
    ArrayList B;
    int x = 0, y;
    B.count = 0;
    while (x < A->count)
    {
        if (strcmp(A->Elem[x].course, course) == 0)
        {
            // insert to new list
            for (y = B.count - 1; y >= 0 && strcmp(B.Elem[y].ID, A->Elem[x].ID) > 0; --y)
            {
                B.Elem[y + 1] = B.Elem[y];
            }
            
            B.Elem[y + 1] = A->Elem[x];
            B.count++;
            
            // remove from old list
            for (y = x; y < A->count - 1; ++y)
            {
                A->Elem[y] = A->Elem[y + 1];
            }
            A->count--;
        }
        else {
            ++x;
        }
    }
    return B;
}