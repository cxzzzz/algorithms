import sys

def main():
    n = int(input())
    a = [ int(x) for x in sys.stdin.readline().split(" ") ]
    b = [ int(x) for x in sys.stdin.readline().split(" ") ]
    a = sorted(a)
    b = sorted(b)

    pos = 0
    cnt = 0

    for num in a:
        if num > b[pos] :
            pos += 1
            cnt += 1
    
    print(cnt)

main()