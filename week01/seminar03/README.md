## Given an expression in postfix format, we want to evaluate it.
Usefull link: https://www.techiedelight.com/evaluate-given-postfix-expression/

Example: 5 6 * 2 + -> 5 * 6+2, if we see an operatop -> convert it to expression.

Example: 5 6 2 3 * * + 2 + -> 5 + 6 * 2 * 3 + 2, firstly 2*3, then 6*6, then 36 + 5, then 41 + 2

Code: https://github.com/alexvishnevskiy/CSCI_61/tree/master/week01/seminar03