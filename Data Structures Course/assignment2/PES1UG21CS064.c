#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#define MAX 100

typedef struct node
{
    int id;             // ID of user
    int numfren;        // number of friends of user
    char name[MAX];     // name of user
    int *friends;       // friends of user as an array
    struct node *right; // user to the right
    struct node *left;  // user to the left
} node;

struct node *retUser(char str[MAX])
{
    char name[MAX];
    char ID[MAX];
    char strfriends[MAX];

    // copied ID
    char *token = strtok(str, ",");
    strcpy(ID, token);

    // copied Name
    token = strtok(NULL, ",");
    strcpy(name, token);

    // copied friends' ID
    token = strtok(NULL, ",");
    strcpy(strfriends, token);
    // printf("%s\n",(strfriends));

    // creating user nodes
    int id = atoi(ID);
    struct node *user = malloc(sizeof(struct node));
    user->id = id;
    user->friends = (int *)malloc(MAX * sizeof(int));
    strcpy(user->name, name);

    // adding user's friend's IDs
    token = strtok(strfriends, "|");
    int i = 0;
    while (token != NULL)
    {

        int temp = atoi(token);
        user->friends[i] = temp;
        i++;
        token = strtok(NULL, "|");
    }
    user->numfren = i;
    if (i == 0)
    {
        user->friends[i] = -1;
    }
    return user;
}

// search for user with id=key
struct node *search(int key, struct node *users)
{
    struct node *pres = users;
    while (pres != NULL && pres->id != key)
    {
        if (key > pres->id)
        {
            pres = pres->right;
        }
        else
        {
            pres = pres->left;
        }
    }
    return pres;
}

// see document for explanattion
struct node *refineUser(struct node *user, struct node *users)
{
    user->left = NULL;
    user->right = NULL;
    
    struct node *repeat = search(user->id, users);
    while (repeat != NULL)
    {
        (user->id)++;
        repeat = search(user->id, users);
    }

    for (int i = 0; i < (user->numfren); i++)
    {
        int fren = user->friends[i];
        struct node *present = search(fren, users);
        if (present == NULL)
        {
            for (int j = i; j < user->numfren; j++)
            {
                user->friends[j] = user->friends[j + 1];
            }
            i--;
            user->numfren--;
        }
        else
        {
            present->friends[present->numfren] = user->id;
            present->numfren++;
        }
    }

    if (user->numfren == 0)
    {
        user->friends[0] = -1;
    }
    return user;
}

// insert user with id
struct node *insertUser(struct node *root, int id, struct node *user)
{
    if (root == NULL)
    {
        root = user;
    }
    else
    {
        struct node *pres = root;
        struct node *prev = NULL;

        while (pres != NULL)
        {
            if (id > pres->id)
            {
                prev = pres;
                pres = pres->right;
            }
            else
            {
                prev = pres;
                pres = pres->left;
            }
        }
        if (id > prev->id)
        {
            prev->right = user;
        }
        else
        {
            prev->left = user;
        }
    }
    return root;
}

// prints friends list
void friends(int id, struct node *users)
{
    struct node *user = search(id, users);

    if (user != NULL)
    {
        if (user->numfren == 0)
        {
            printf("-1\n");
        }
        else
        {
            for (int i = 0; i < user->numfren; i++)
            {
                printf("%d\n", user->friends[i]);
            }
        }
    }
}

// find child node with minimum value (inorder successor) - helper to delete node
struct node *minValueNode(struct node *node)
{
    struct node *pres = node->right;
    struct node *prev = NULL;

    while (pres != NULL)
    {
        prev = pres;
        pres = pres->left;
    }
    return prev;
}

// deletes itself from its friend's nodes
struct node *deleteFriends(int key, struct node *users)
{
    struct node *user = search(key, users);
    if (user != NULL)
    {
        for (int i = 0; i < user->numfren; i++)
        {
            int fren = user->friends[i];
            struct node *friend = search(fren, users);
            if (friend != NULL)
            {
                int j = 0;
                while (friend->friends[j] != key)
                    j++;
                for (; j < friend->numfren; j++)
                {
                    friend->friends[j] = friend->friends[j + 1];
                }
                friend->numfren--;

                if (friend->numfren == 0)
                {
                    friend->friends[0] = -1;
                }
            }
        }
    }
    return users;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key)
{

    if (root == NULL)
        return root;
    else if (key > root->id)
    {
        root->right = deleteNode(root->right, key);
    }
    else if (key < root->id)
    {
        root->left = deleteNode(root->left, key);
    }
    else
    {
        if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        else if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else
        {
            struct node *temp = minValueNode(root);
            root->id = temp->id;
            strcpy(root->name, temp->name);
            root->friends = temp->friends;
            root->numfren = temp->numfren;
            root->right = deleteNode(root->right, temp->id);
        }
    }
    return root;
}

// Print USER's IDs in ascending order
void printInOrder(node *myusers)
{
    if (myusers != NULL)
    {
        printInOrder(myusers->left);
        printf("%d %s\n", myusers->id, myusers->name);
        printInOrder(myusers->right);
    }
}

int main(int argc, char **argv)
{
    node *users = NULL;
    while (1)
    {

        int opt, id;
        fflush(stdin);
        scanf("%d", &opt);
        char str[MAX];
        switch (opt)
        {
        case 1:

            scanf("%s", str);
            struct node *tbins = retUser(str);
            tbins = refineUser(tbins, users);
            users = insertUser(users, tbins->id, tbins);
            break;

        case 2:

            scanf("%d", &id);
            deleteFriends(id, users);
            users = deleteNode(users, id);
            break;

        case 3:

            scanf("%d", &id);
            node *result = search(id, users);
            if (result == NULL)
                printf("USER NOT IN TREE.\n");
            else
            {
                printf("%d\n", result->id);
            }
            break;

        case 4:
            scanf("%d", &id);
            friends(id, users);
            break;

        case 5:
            printInOrder(users);
            break;

        case 6:
            exit(0);
            break;

        default:
            printf("Wrong input! \n");
            break;
        }
    }
    return 0;
}