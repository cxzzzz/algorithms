
result=1
table=set()
while result <= 10**9:
    tmp=result
    reg=0
    while(tmp != 0):
        t = tmp%10
        reg += 10**t
        tmp = tmp // 10  
    table.add(reg)

    result *= 2


print( table )

        
    