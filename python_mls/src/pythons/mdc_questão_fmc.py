def mdc_euclides(a: int, b: int) -> int:
    maior_menor = lambda a, b: (a, b) if a > b else (b, a)
    a, b = maior_menor(a, b)

    if (b == 0): return a

    r, q = a % b, a // b
    
    print(f"{a} = {b}*{q} + {r}")
    print(f"mdc({b}, {r})\n")

    return mdc_euclides(b, r)

if (__name__ == "__main__"):
    a = int(input())
    b = int(input())
    print(f"\nCalular mdc de {a} e {b}\n")
    mdc = mdc_euclides(a, b)
    print(f"O mdc de {a} e {b} é {mdc}")