s=input().strip()
stk=[]
stopped=False

for c in s:
    if(c=='(' or c=='['):
        stk.append(c)
    else:
        check=False
        temp=1
        while(len(stk)): # stk는 (  [  정수 올 수 있다
            if(stk[-1]==('[' if c==')' else '(')):
                stopped=True
                break
            elif(stk[-1]==('(' if c==')' else '[')):
                stk.pop()
                check=True
                temp*=2 if c==')' else 3
                break
            else: 
                temp*=stk.pop()

        eval_plus=True if(len(stk) and stk[-1]!='(' and stk[-1]!='[') else False # 남아있는 괄호를 plus해준다
        if check and stopped==False:
            stk.append(temp)
        else:
            break

        if eval_plus:
            temp=stk.pop()
            while(len(stk) and (stk[-1]!='(' and stk[-1]!='[')):
                temp+=stk.pop()

            stk.append(temp)
        

if stopped or len(stk)!=1 or stk[0]=='(' or stk[0]=='[':
    print(0)
else:
    print(stk.pop())
