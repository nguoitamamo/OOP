#include <iostream>
#include <cstring>

struct SV
{
    char ma[3];
    char ht[50];
    int hl;
    std::string xl;
};

struct Sinhvien
{
    SV data;
    Sinhvien *left;
    Sinhvien *right;
};

Sinhvien *makenode(SV &a)
{
    Sinhvien *newNode = new Sinhvien();
    newNode->data = a;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(Sinhvien *root, SV &x)
{
    if (root == NULL)
    {
        return makenode(x);
    }
    int result = strcmp(root->data.ma, x.ma);
    if (strcmp > 0)
    {
        root->left = insert(root->left, x)
    }
    else
    {
        root->right = insert(root->right, x)
    }
    return root;
}

int main()
{
    Sinhvien *head = NULL;

    return 0;
}