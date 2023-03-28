![push_swap](https://github.com/glutack/glutack/blob/master/42img/push_swap_banner.png?raw=true)

`push_swap` is an algorithm project whose objective is to sort x amount of int elements with the minimun possible number of operations. The program is only allowed to work with two stacks (stack A and stack B) and use the following actions:

`pa` (push A): Take the first element at the top of B and put it at the top of A. Do nothing if B is empty.

`pb` (push B): Take the first element at the top of A and put it at the top of B. Do nothing if A is empty.

`sa` (swap A): Swap the first 2 elements at the top of stack A. Do nothing if there is only one or no elements.

`sb` (swap B): Swap the first 2 elements at the top of stack B. Do nothing if there is only one or no elements.

`ss`: sa and sb at the same time.

`ra` (rotate A): Shift all elements of stack A up by 1. The first element becomes the last one.

`rb` (rotate B): Shift all elements of stack B up by 1. The first element becomes the last one.

`rr`: ra and rb at the same time.

`rra` (reverse rotate A): Shift all elements of stack A down by 1. The last element becomes the first one.

`rrb` (reverse rotate B): Shift all elements of stack b down by 1. The last element becomes the first one.

`rrr` : rra and rrb at the same time.

---

## to improve
- [ ] Sorting 100 values has an average of 600+ movements, sometimes it makes a few movements above 700

- [ ] Sorting 500 values has an average of 5500 movements, it makes around 5600 movements sometimes

## to fix

---
banner by me