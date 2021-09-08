T=int(input())
  
a=T//300
b=(T-300*a)//60
c=(T-(300*a+60*b))//10

if (T-(300*a+60*b))%10 :  
    print(-1)
else:
    print(a,b,c)

