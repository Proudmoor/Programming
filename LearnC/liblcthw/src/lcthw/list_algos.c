#include <lcthw/list_algos.h>
#include "dbg.h"

inline void ListNode_swap(ListNode *a, ListNode *b){
	void *tmp = a -> value;
	a -> value = b -> value;
	b -> value = tmp;
}


inline List* List_merge(List *left, List *right, List_compare cmp){
	List *result = List_create();
	void *val = NULL;
	while(List_count(left) > 0 || List_count(right) > 0){
		if(List_count(left) > 0 && List_count(right) > 0){
			if (cmp(List_first(left), List_first(right)) >= 0){
				val = List_shift(right);
			}else {
				val = List_shift(left);
			}

			List_push(result, val);
		} else if(List_count(left) > 0) {
			val = List_shift(left);
			List_push(result, val);
		} else if(List_count(right) > 0){
			val = List_shift(right);
			List_push(result, val);
		}
	}

	return result;
}

List *List_merge_sort(List *list, List_compare cmp) {
	if(List_count(list) <= 1) {
		return list;
	}

	List *left = List_create();
	List *right = List_create();
	int middle = List_count(list) / 2;

	LIST_FOREACH(list, first, next, cur){
		if(middle > 0){
			List_push(left, cur->value);
		} else{
			List_push(right, cur->value);
		}
		middle --;
	}
	List *sort_left = List_merge_sort(left, cmp);
	List *sort_right = List_merge_sort(right, cmp);

	if(sort_left != left) List_destroy(left);
	if(sort_right != right) List_destroy(right);

	return List_merge(sort_left, sort_right, cmp);
}

int List_bubble_sort(List *list, List_compare cmp){
	bool swapped = false;
	if(List_count(list) <=1){
		return 0;
	}

	do{
		swapped = false; 
		LIST_FOREACH(list, first, next, cur){
			if(cur->next){
				if(cmp(cur->value, cur->next->value) > 0){
					ListNode_swap(cur, cur->next);
					swapped = true;
				}
			}
		}
	}while(swapped);

	return 0;
}























