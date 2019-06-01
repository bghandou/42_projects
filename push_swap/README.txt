These programs sort stack_A through a radix-sort type of algorithm and then check whether the stack is sorted.
./push_swap will take in integers and send out the instructions needed to sort the stack.
./checker will take instructions and check whether stack a (made of integers) is sorted and whether stack b is empty.
example of usage : ./push_swap $ARG | ./checker $ARG
Can use the the SDL visualizer : ./push_swap $ARG | ./checker -v $ARG

NOTE : If you don't have SDL, comment out the lines that compile with SDL and the visualizer files in the Makefile. Also comment out the "include SDL" in the push_swap.h file.
