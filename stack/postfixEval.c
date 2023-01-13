// posfix expression evaluation
/*
Algorithm:
    1. Scan the postfix string from left to right
    2. Initialize an empty stack.
    3. Repeat steps 4 and 5 till all the characters are scanned.
    4. If scanned character is an operand, push it onto the stack.
    5. If the scanned character is an operator, and if the operator is an unary operator, then pop an element from the stack.
       If operator is a binary operator, them pop two elements from the stack.
       After popping the elements, apply the operator to those popped elements.
       (first popped element is the second operand for the operation and so on)
       Let the result of this operation be retVal onto the stack.
    6. After all the characters are scanned, we will have only one element in the stack.
    7. Return top of the stack as result.
*/