/**************************************************************
 *  Fast Union-Find Algorithm
 *
 *  The amortized time complexity for building a union-find
 *  structure is O(E * a(E))
 *      where   E   = number of edges,
 *              a() = Inverse of Ackerman's function
 *
 *  The space complexity is O(V) for storing the equivalence
 *  class of each vertex.
 *
 *  Implementation borrowed from:
 *      http://www.yendor.com/programming/minauto/ufind.c
 **************************************************************/

/**
 *  The array `class_of` represents a partition of the elements
 *  into equivalence classes. Elements are indexed 1 through N
 *  (0 is unused). class_of[i] can be:
 *
 *      A]   == 0 : The element i is singleton in its own class.
 *      B]  j > 0 : The element i belongs to the same class as
 *                  j, who is its parent.
 *      C]  N < 0 : The element i is the root of its equivalence
 *                  class containing -N elements.
 **/
int class_of[VCOUNT];

/**
 *  Returns the index of the root element of the equivalence
 *  class of `elem`.
 **/
int find_node(int elem) {
    register int i, j;

    /* Find the root of the equivalence class                 */
    for(i = elem; class_of[i] > 0; i = class_of[i]);

    /* Path compression for all points from `elem` to root    */
    while(class_of[elem] > 0) {
        j = elem;
        elem = class_of[elem];
        class_of[j] = i;
    }

    return i;
}

/**
 *  Unify the equivalence classes of `elem1` and `elem2` to
 *  belong to the same class.
 **/
void union_nodes(int elem1, int elem2) {
    register int i = find_node(elem1), j = find_node(elem2);

    if(i != j) {
        /* Weight balancing union: Make the shallower tree, a
         * subtree of the deeper tree                         */
        if(class_of[i] > class_of[j]) {
            class_of[j] += (class_of[i] - 1);
            class_of[i] = class_of[j];
        } else {
            class_of[i] += (class_of[j] - 1);
            class_of[j] = class_of[i];
        }
    }
}
