def func():
    A, B = map(int, input().split())
    return f"YES\n{A} {(2*A*B)- A} {2*A*B}"

for _ in range(int(input())):
    print(func())