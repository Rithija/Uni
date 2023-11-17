6_latest.py uses ply tool's lex and yacc with python to mimic 5 constructs of java language, namely if_else conditional statement, for loop, while loop, switch case,
and function declaration. The code only follows basic functionalities of the said constructs. 
PLY tool's lexer is used to tokenize the input string(piece of code of java) and yacc is used to parse through the tokens created. A parse tree is generated and the
parser checks if the input code provided follows the production rules of the grammar defined in the python-ply code. It's simply to check if the user input code is 
syntactically matching with the predefined rules. If not error is raised. A deeper study on this lexer and yacc can help the programmer learn how a program gets compiled.
Further, one can develop their own programming language if they intend to.
Moving on..
In the program,
The reserved words act like keywords so that while execution the interpreter doesnt confuse the ID tokens with the while,for,switch like keywords.
All the rest symbols, variables, numbers etc are mentioned in the tokens list. They are then defined.
r represents the raw strings that occur before the character you want to define. It so happens that in regular expression, few characters have special meanings.
to escape that we preceed the character by a backslash.
If you notice, in java + is used as a concatenation symbol in the print statements and as an arithmetic operator. So for the interpreter to not confuse with it twice,
it is mentioned separately in the lexer token rules. 

For documentation of python ply tool follow the link. [https://www.dabeaz.com/ply/ply.html]
P.S disable pylint if you have the extension on your platform, else follow the method described in the documentation. 
P.P.S you can't input a multi line code... you can make necessary changes if you wish to.



