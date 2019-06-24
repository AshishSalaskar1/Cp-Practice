openB = ['(' , '{' , '[']
closeB = [')' , '}', ']']

def checkStr(myStr):
    stk = []
    for i in myStr:
        if i in openB:
            stk.append(i)
        #check top of stack
        elif i in closeB:
            index = closeB.index(i)
            if (len(stk) > 0) and (openB[index] == stk[len(stk)-1]):
                stk.pop()
            else:
                return "Unbalanced Expression"
    
    #all brackets are balanced
    if len(stk) == 0:
        return "Balanced Expression"


str1 = '[()]{}{[()()]()}'
str2 = '[(])'

print(str1 + " : "+ checkStr(str1))
print(str2 + " : "+ checkStr(str2))
