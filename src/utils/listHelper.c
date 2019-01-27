#include "listHelper.h"

void addItem(ItemComponent** start, Component component){
    ItemComponent * item;
    Component * ptrComponent;
    item = malloc(sizeof(ItemComponent));
    ptrComponent = malloc(sizeof(Component));
    *ptrComponent = (Component) component;
    item->component = ptrComponent;
    item->next = *start;
    *start = item;
}

ItemComponent* removeItem(ItemComponent * start)
{
    ItemComponent * inter;
    if(start == NULL) return NULL;
    inter = start->next;
    free(start->component);
    free(start);
    return inter;
}
ItemComponent *removeAll(ItemComponent *start){
    ItemComponent * inter = start;
    while(inter != NULL){
        inter = removeItem(inter);
    }
    return inter;
}
ItemComponent *removeItemAt(ItemComponent *start, int id){
    ItemComponent* inter;
    if(start == NULL){
        return NULL;
    }
    if(id == start->component->id){
        inter = start->next;
        free(start->component);
        free(start);

        inter = removeItemAt(inter, id);
        return inter;
    }else{
        start->next = removeItemAt(start->next, id);
        return start;
    }
}

ItemComponent* getComponentById(ItemComponent* start, int id){
    ItemComponent* item = start;
    int i;
    for(i = 0; item != NULL; i++){
        if(item->component->id == id){
            return item;
        }
        item = item->next;
    }
    return NULL;
}

ItemComponent* getComponentByPos(ItemComponent* start, int x, int y){
    ItemComponent* item = start;
    int i;
    for(i = 0; item != NULL; i++){
        if(item->component->posX == x && item->component->posY == y){
            return item;
        }
        item = item->next;
    }
    return NULL;
}
void reverseComponent(Datas *datas,int id){
    ItemComponent* item = getComponentById(datas->grid->components, id);
    if(item != NULL)
        item->component->isReversed = item->component->isReversed ? 0 : 1;
}
void setSpecificDataComponent(Datas *datas, int id, double value){
    ItemComponent* item = getComponentById(datas->grid->components, id);
    if(item != NULL)
        item->component->specificData = value;
}
