#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "queue.h"
#include "expr_assert.h"

void test_create_an_empty_Queue_structure(){
	Queue result ;
	result = createQueue();
	assertEqual(result.list->count,0);

};

void test_create_an_empty_Queue_structure_with_Front_NULL(){
	Queue result ;
	result = createQueue();
	assert(*(result.Front)==NULL);
};

void test_create_an_empty_Queue_structure_with_Rear_NULL(){
	Queue result ;
	result = createQueue();
	assert(*(result.Rear)==NULL);
};

void test_Given_a_Queue_and_a_reference_to_some_data_this_reference_will_be_pushed_on_the_queue(){
	Queue new_queue = createQueue();
	int data= 10,count;
	count = push(new_queue,&data);
	assertEqual(count, 1);
	assertEqual(*(int*)((*new_queue.Front)->data),data);
};

void test_Given_a_Queue_and_a_reference_to_some_data_this_reference_will_be_pushed_on_the_queue_front_and_Rear(){
	Queue new_queue = createQueue();
	int data= 10,count;
	count = push(new_queue,&data);
	assertEqual(count, 1);
	assertEqual(*(int*)((*new_queue.Rear)->data),data);
};

void test_push_puts_the_data_at_Rear(){
	int data= 1,data1=10,count;
	Queue new_queue = createQueue();
	count = push(new_queue,&data);
	count = push(new_queue,&data1);
	assertEqual(count, 2);
	assert((*new_queue.Front)->data==&data);
	assert((*new_queue.Rear)->data==&data1);
}

void test_queue_first_pushed_value_always_will_be_front(){
	int data= 1,data1=10,data2=30,count;
	Queue new_queue = createQueue();
	count = push(new_queue,&data);
	count = push(new_queue,&data1);
	count = push(new_queue,&data2);
	assertEqual(count, 3);
	assert((*new_queue.Front)->data==&data);
	assert((*new_queue.Rear)->data==&data2);
}
///

void test_pop_remove_the_data_from_the_front_of_queue(){
	int data= 1,data1=10,count;
	Queue new_queue = createQueue();
	push(new_queue,&data);
	push(new_queue,&data1);
	pop(new_queue);

	assertEqual(new_queue.list->count, 1);
	assertEqual(*(int*)((*new_queue.Front)->data),data1);
};

void test_pop_remove_the_data_from_Front_of_queue_and_gives_count_1(){
	int data= 1,data1=10;
	Queue new_queue = createQueue();
	push(new_queue,&data);
	push(new_queue,&data1);
	pop(new_queue);
	assertEqual(new_queue.list->count, 1);
}

void test_queue_first_pushed_value_always_will_be_front_and_next_element_will_be_front_now(){
	int data= 1,data1=10,data2=30,count;
	Queue new_queue = createQueue();
	count = push(new_queue,&data);
	count = push(new_queue,&data1);
	count = push(new_queue,&data2);
	pop(new_queue);
	pop(new_queue);
	assertEqual(count, 3);
	assertEqual(new_queue.list->count, 1);
	assert((*new_queue.Front)->data==&data2);
	assert((*new_queue.Rear)->data==&data2);
}

void test_queue_gives_data_15_at_index_2(){
	Queue queue = createQueue();
	int data[] = {12,13,15,16},count,index,i;

	for(i=0;i<4;i++){
		count = push(queue,&data[i]);
	}
	
	index = indexOf(*queue.list,&data[2]);

	assertEqual(count,4);
	assertEqual(index,2);
	assertEqual(*(int*)(*queue.Rear)->data,data[3]);
};