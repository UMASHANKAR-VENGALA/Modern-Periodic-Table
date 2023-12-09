#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Search(FILE *file, char SK[])
{
    char buff[200], buff2[100], *t1, *t2;
    int flag = 0;
    const char delim[2] = "$";
    printf("\nSearch Results:- \n");
    while (fgets(buff, 100, file) != 0)
    {
        strcpy(buff2, buff);
        t1 = strtok(buff, delim);
        while (t1 != NULL)
        {
            if (!strcmp(SK, t1))
            {
                flag++;
                printf("\n---%d---\n", flag);
                t2 = strtok(buff2, "$");
                while (t2 != NULL)
                {
                    printf(" %s ", t2);

                    t2 = strtok(NULL, delim);
                }
                printf("\n");
            }
            t1 = strtok(NULL, delim);
        }
    }
    if (flag == 0)
    {
        printf("\nElements not found\n");
    }
}

void Add()
{
    char buffer[100];
    FILE *file = fopen("Database.txt", "a");

    if (file == NULL)
    {
        printf("\nError Opening File.");
        exit(0);
    }
    else
    {
        printf("\nName:- ");
        scanf("%s", buffer);
        fprintf(file, "%s$", buffer);
        printf("Symbol:- ");
        scanf("%s", buffer);
        fprintf(file, "%s$", buffer);
        printf("Atomic No:- ");
        scanf("%s", buffer);
        fprintf(file, "%s$", buffer);
        printf("Atomic Wt:- ");
        scanf("%s", buffer);
        fprintf(file, "%s\n", buffer);
    }
    fclose(file);
}

void Explore()
{
    char SK[100];
    int c, flag = 1;
    FILE *file = fopen("Database.txt", "r");
    if (file == NULL)
    {
        printf("\nError Opening File...");
        exit(0);
    }
    else
    {
        while (flag)
        {
            printf("\n1.Search by Name\n2.Search by Symbol.\n3.Search by Atomic No.\n4.Search by Atomic Wt.\n5.Exit\n");
            printf("\nEnter your choice:-");
            scanf("%d", &c);
            switch (c)
            {
            case 1:
                printf("\nEnter Search Key [Name]:-");
                scanf("%s", SK);
                break;
            case 2:
                printf("\nEnter Search Key [Symbol]:-");
                scanf("%s", SK);
                break;
            case 3:
                printf("\nEnter Search Key [Atomic No]:-");
                scanf("%s", SK);
                break;
            case 4:
                printf("\nEnter Search Key [Atomic Wt]:-");
                scanf("%s", SK);
                break;
            case 5:
                printf("\nExited Explore Console...\n");
                flag = 0;
                break;
            default:
                printf("\nInvalid Choice...\n");
                break;
            }
            Search(file, SK);
        }
    }
    fclose(file);
}

int main()
{
    int c, flag = 1;
    while (flag)
    {
        printf("\n1.Add New Element Info\n2.Explore\n3.exit\n");
        printf("\nEnter your choice:-");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            Add();
            break;
        case 2:
            Explore();
            break;
        case 3:
            flag = 0;
            printf("\nProgram Terminated...\n");
            break;
        default:
            printf("\nInvalid Choice...\n");
        }
    }
}
