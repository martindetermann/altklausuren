#include <stdio.h>
#include <stdlib.h>

#include "BigDecimal.h"

LNode* create_lnode(void){
    LNode* lNode;

    lNode = malloc(sizeof(LNode));

    lNode->value = 255;
    lNode->next = NULL;
    lNode->prev = NULL;

    return lNode;
}

void delete_list(LNode* node){
    while (node->prev != NULL){
        node = node->prev;
    }

    LNode* lNodeNext;

    while(node != NULL){
        lNodeNext = node->next;

        free(node);

        node = lNodeNext;
    }

    //free(node);
   
}

void print(LNode* node){
    while (node->prev != NULL){
        node = node->prev;
    }

    while(node != NULL){
        LNode* lNodeNext = node->next;

        printf("%u", node->value);

        node = lNodeNext;
    }
}

void print_reverse(LNode* node){
    while (node->next != NULL){
        node = node->next;
    }

    while(node != NULL){
        LNode* lNodePrev = node->prev;

        printf("%u", node->value);

        node = lNodePrev;
    }
}

LNode* prepend_val(LNode* node, unsigned char val){
    LNode* current = create_lnode();

    current->value = val;

    if(node == NULL){
        return current;
    }

    while(node->prev != NULL){
        node = node->prev;
    }

    current->next = node;
    node->prev = current;
    return current;
}

LNode* append_val(LNode* node, unsigned char val){
    LNode* current = create_lnode();

    current->value = val;

    if(node == NULL){
        return current;
    }

    while(node->next != NULL){
        node = node->next;
    }

    current->prev = node;
    node->next = current;
    return current;
}

LNode* get_at_LSD(LNode* node, unsigned int ind){
    while(ind > 0){
        ind--;
        node = node->next;

        if(node == NULL){
            return node;
        }
    }

    return node;
}

unsigned int set_at_LSD(LNode* node, unsigned int ind, unsigned char val){
     while(ind > 0){
        ind--;
        node = node->next;

        if(node == NULL){
            return 1;
        }
    }

    LNode* nodeBefore = node->prev;
    LNode* current = create_lnode();
    current->value = val;
    current->next = node;
    current->prev = nodeBefore;

    node->prev = current;
    nodeBefore->next = current;

    return 0;
}

unsigned int len_list(LNode* node){
    int i = 0;
    while(node != NULL){
        node = node->next;
        i++;
    }

    return i;
}

LNode* add_list(LNode* node1, LNode* node2){
    int carry = 0;
    LNode* ziffgMSD = NULL;
    LNode* ziffgLSD = NULL;

    int maxLen = len_list(node1);
    if(maxLen < len_list(node2)){
        maxLen = len_list(node2);
    }
    
    for (int k = 0; k < maxLen; k++){
        LNode* ziff1 = get_at_LSD(node1, k);
        LNode* ziff2 = get_at_LSD(node2, k);

        int i1 = 0;
        if(ziff1 != NULL){
            i1 = ziff1->value;
        }
        int i2 = 0;
        if(ziff2 != NULL){
            i2 = ziff2->value;
        }

        //printf("%d %d\n", i1, i2);

        int res = i1 + i2 + carry;
        carry = res / 10;
        res = res % 10;

        ziffgMSD = append_val(ziffgMSD, res);
        if(k == 0){
            ziffgLSD = ziffgMSD;
        }
    }

    return ziffgLSD;
}

LNode* get_LSD(LNode* node){
    if(node == NULL){
        return NULL;
    }

    while(node->prev != NULL){
        node = node->prev;
    }

    return node;
}

unsigned int len_list_from_LSD(LNode* node){
    LNode* LSD = get_LSD(node);

    return len_list(LSD);
}

LNode* get_MSD(LNode* node){
    if(node == NULL){
        return NULL;
    }

    while(node->next != NULL){
        node = node->next;
    }

    return node;
}