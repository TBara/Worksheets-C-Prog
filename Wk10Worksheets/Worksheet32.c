

void treeSort(TYPE *data, int n)
{ /* sort values in array data */
    AVLtree tree;
    AVLIterator itr;
    int i = 0, count = 0;
    AVLtreeInit(&tree);
    for (i = 0; i < n; i++)
        AVLAddTree(&tree, data[i]);
    /* assuming you have an iterator */
    AVLIteratorInit(&tree, &itr);
    while (AVLIteratorHasNext(&itr))
    {
        data[count] = AVLIteratorNext(&itr);
        count = count + 1;
    }
}