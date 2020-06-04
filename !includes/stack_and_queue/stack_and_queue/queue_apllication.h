#ifndef QUEUE_APLLICATION_H
#define QUEUE_APLLICATION_H

#include "queue.h"

void menu(char command, Queue<int>& l,
          typename Simple_List<int>::Iterator &head);

void test_queue();
void test2_queue();

#endif // QUEUE_APLLICATION_H
