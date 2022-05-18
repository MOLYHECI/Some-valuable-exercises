### Boolean Expressions

For us, infix expressions are very easy and familiar to us 'cause we've got acquainted with the priority of operators.

But for the computer, it is very hard to compute the infix expressions. The best way to let it know is that don't let it know. We just feed the expression to the computer------we can sort the single operation and let the computer compute it in order.

For example, if we want to compute the expression:

4.99 * 1.06 + 5.99 + 6.99 * 1.06

We can convert it to a "postfix expression":

4.99 1.06 * 5.99 + 6.99 1.06 * +

Now, the computer can compute it easily.

So first, we need to know how to convert an infix expression to a postfix expression

We can start with a simple expression:

F & (V & V |F)  --> F V V & F | &

And construct a queue and stack. the queue is a postfix expression, the stack is a tool.

queue:

stack: 



We can traverse the string in order. Firstly we meet 'F', we push it into the queue:

queue: 'F'

stack:

> **Rule 1**: if meet a boolean, just push it into the queue



meet '&', and then push it into the stack:

queue: 'F'

stack: '&'

> **Rule 2**: if meet an operator (not '(')and the stack is empty, just push it into the stack.



meet '(', and push it into the stack:

queue: 'F'

stack: '&', '('

> **Rule 3**: if meet '(', push it into the stack.



meet 'V', and push it into the queue:

queue: 'F', 'V'

stack: '&', '('



meet '|', push it into the stack:

queue: 'F', 'V'

stack: '&', '(', '|'



meet 'V', push it into the queue:

queue: 'F', 'V', 'V'

stack: '&', '(', '&'



meet '|',  and throw '&', then push it into the stack:

queue: 'F', 'V', 'V', '&'

stack: '&', '(', '|'

> **Rule 4**: if meet an operator (not '(' or ')'), throw operators whose priority is **less than or equal to** it until the operator's priority is more than it, then push it into the stack.



meet 'F', push it into the queue:

queue: 'F', 'V', 'V', '&', 'F'

stack: '&', '(', '|'



meet ')', throw '&', '(' ,push '&' into the queue:

queue: 'F', 'V', 'V', '&', 'F', '|'

stack: '&'

> **Rule 5**: if meet ')', throw the operator upon the first '(' and push it into the queue until the first '(', and this '(' just throw away.



Finally, throw '&' and push it into the queue:

queue: 'F', 'V', 'V', '&', 'F', '|', '&'

stack:



Now the postfix expression we want is in the queue.

So how can we compute the postfix expression? We also use the example above to explain it:

F V V & F | &

construct a stack:

stack:



Firstly we meet 'F', and push it into the stack:

stack: 'F'

> **Rule 1**: if meet a boolean, push it into the stack.

......

stack: 'F', 'V', 'V'

we meet '&', it's a binary operator. So we take the first two booleans of the stack, compute them and push the result back.

stack: 'F', 'V'

> **Rule 2**: if meet an operator, take arguments from the top of the stack, compute them and push the result back.

......

stack: 'F'

when we meet the end, the last boolean in the stack is the result we desire.

