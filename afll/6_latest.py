#this code accepts an input code for 5 constructs of java language - for loop, while loop, if-else statement,switch-case and function declaration
#(note: program executes well when the pylint is disabled)
import ply.lex as lex
import ply.yacc as yacc
#defining the reserved words
reserved={'while':'WHILE','for':'FOR','switch':'SWITCH','case':'CASE','default':'DEFAULT','break':'BREAK','if':'IF','else':'ELSE',
          'int':'INT','float' :'FLOAT','char':'CHAR',
          'double':'DOUBLE','boolean':'BOOLEAN','byte':'BYTE','short':'SHORT','long':'LONG',
          'String':'String','public':'PUBLIC','private':'PRIVATE','protected':'PROTECTED','void':'VOID',
          'System':'SYSTEM','out':'OUT','println':'PRINT','true':'TRUE','false':'FALSE',}
#declaring and defining the tokens 
tokens=[
    'LPAREN',
    'RPAREN',
    'LCURL',
    'RCURL',
    'LBIG',
    'RBIG',
    'COMMA',
    'SEMICOLON',
    'OPERATOR',
    'ID',
    'NUMBER',
    'COMPARE',
    'STRING',
    'DOT',
    'PLUS',
    'ASSIGN',
    'NEWLINE',
    'NOT',
    'INCR',
    'DECR',
    'SINGLE_CHARACTER',
    'COLON',
]+list(reserved.values())

#Define the lexer rules
t_LPAREN= r'\('
t_RPAREN= r'\)'
t_RCURL= r'\}'
t_LCURL= r'\{'
t_RBIG= r'\]'
t_LBIG= r'\['
t_COMMA=r','
t_ASSIGN= r'='
t_PLUS=r'\+'
t_SEMICOLON = r';'
t_COLON = r':'
t_DOT=r'\.'
t_NOT=r'!'
#defining the increment operator
def t_INCR(t):
    r'\+\+'
    return t

#defining the decrement operator
def t_DECR(t):
    r'--'
    return t

#defining the arithmetic operators
def t_OPERATOR(t):
    r'-|\*|/|%'
    return t

#defining the relational operators
def t_COMPARE(t):
    r'[<>]=?|!=|=='
    return t

#defining the id
def t_ID(t):
    r'[a-zA-Z_][a-zA-Z0-9_]*'
    t.type = reserved.get(t.value,'ID') 
    return t

def t_NUMBER(t):
    r'\d+'
    t.value = int(t.value)
    return t

def t_STRING(t):
    r'"[^"]*"'
    t.value = t.value[1:-1]  # remove the double quotes
    return t

def t_SINGLE_CHARACTER(t):
    r"'.'"
    t.value = t.value[1:-1]  # remove the single quotes
    return t

t_ignore = ' \t'

def t_NEWLINE(t):
    r'\n+'
    t.lexer.lineno += len(t.value)

def t_error(t):
    print("Illegal character '%s'" % t.value[0])
    t.lexer.skip(1)

# Build the lexer
lexer = lex.lex()

#the start symbol S can take you to the 5 constructs
def p_p0(p):
    '''S : for_loop
         | if_else
         | while
         | switch_case
         | func_decl'''
#defining the basic structure for for loop in java
def p_p1(p):
    '''for_loop : FOR LPAREN A SEMICOLON B SEMICOLON D RPAREN LCURL statements RCURL
                | FOR LPAREN A SEMICOLON B SEMICOLON D RPAREN SEMICOLON'''

#defining the basic structure for if-else conditional statement in java 
def p_p2(p):
    'if_else : IF LPAREN condition RPAREN LCURL statements RCURL ELSE LCURL statements RCURL'

#defining the basic structure for while loop in java
def p_p3(p):
    'while : WHILE LPAREN condition RPAREN LCURL statements RCURL'

#defining the basic structure for switch case statement in java
def p_p4(p):
    '''switch_case : SWITCH LPAREN P RPAREN LCURL cases RCURL'''

#defining the basic structure for function declaration in java
def p_p5(p):
    '''func_decl : access_specifier return_type ID LPAREN parameters RPAREN SEMICOLON
                 | access_specifier return_type ID LPAREN RPAREN SEMICOLON'''

def p_p6(p):
    '''access_specifier : PUBLIC 
                        | PRIVATE
                        | PROTECTED'''

def p_p7(p):
    '''return_type : INT
                   | FLOAT 
                   | DOUBLE 
                   | String
                   | CHAR 
                   | BYTE 
                   | BOOLEAN 
                   | SHORT 
                   | LONG 
                   | VOID'''

def p_p8(p):
    '''parameters : parameter_type ID 
                  | parameter_type ID COMMA parameters'''
    
def p_p9(p):
    '''parameter_type : INT
                      | FLOAT 
                      | DOUBLE 
                      | String
                      | CHAR 
                      | BYTE 
                      | BOOLEAN 
                      | SHORT 
                      | LONG 
                      | INT LBIG RBIG 
                      | String LBIG RBIG'''
    
def p_p10(p):
    '''P : ID
         | NUMBER
         | STRING
         | SINGLE_CHARACTER'''

def p_p11(p):
    '''cases : CASE Q COLON statements BREAK SEMICOLON cases
             | CASE Q COLON statements BREAK SEMICOLON
             | CASE Q COLON statements BREAK SEMICOLON default'''

def p_p12(p): 
    '''default : DEFAULT COLON statements BREAK SEMICOLON
               | DEFAULT COLON statements '''
    
def p_p13(p):
    '''Q : SINGLE_CHARACTER 
         | NUMBER
         | STRING'''

def p_p14(p):
    '''condition : ID COMPARE ID
                 | ID COMPARE NUMBER
                 | NUMBER COMPARE ID
                 | NUMBER COMPARE NUMBER
                 | TRUE
                 | FALSE
                 | NOT TRUE
                 | NOT FALSE 
                 | NOT ID
                 | NOT NUMBER
                 | ID
                 | NUMBER'''
    
def p_p15(p):
    '''A : ID ASSIGN ID
         | ID ASSIGN NUMBER
         | INT ID ASSIGN NUMBER
         | empty'''
    
def p_p16(p):
    '''B : ID COMPARE ID
         | ID COMPARE NUMBER
         | NUMBER COMPARE ID
         | NUMBER COMPARE NUMBER
         | empty'''
    
def p_p17(p):
    '''C : ID INCR
         | INCR ID
         | ID DECR
         | DECR ID
         | NUMBER INCR
         | INCR NUMBER
         | NUMBER DECR
         | DECR NUMBER
         | ID ASSIGN ID OPERATOR ID
         | ID ASSIGN ID OPERATOR NUMBER
         | ID ASSIGN NUMBER OPERATOR ID
         | ID ASSIGN NUMBER OPERATOR NUMBER
         | ID ASSIGN ID PLUS ID
         | ID ASSIGN ID PLUS NUMBER
         | ID ASSIGN NUMBER PLUS ID
         | ID ASSIGN NUMBER PLUS NUMBER'''
    
def p_p19(p):
    '''D : C
         | empty'''
# defining the statements block
def p_p20(p):
    '''statements : C SEMICOLON statements
                  | print statements
                  | statements print
                  | print
                  | C SEMICOLON
                  | empty'''
    
# defining the outer structure of print statement
def p_p21(p):
    '''print : SYSTEM DOT OUT DOT PRINT LPAREN X RPAREN SEMICOLON'''

def p_p22(p):
    '''X : ID
         | NUMBER
         | STRING PLUS X
         | STRING
         | X PLUS STRING'''

def p_empty(p):
    'empty :'
    pass

def p_error(p):
    print("Syntax error at '%s'" % p.value)

# Build the parser
parser = yacc.yacc()
input_code= input("enter the input code : ")

lexer.input(input_code)
while True:
    tok = lexer.token()
    if not tok:
        break
    print(tok)

# # Provide input to the parser
result = parser.parse(input_code)
