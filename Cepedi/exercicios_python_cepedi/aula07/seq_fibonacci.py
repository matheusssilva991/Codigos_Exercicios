fib_save = {}

def fibonacci(n: int):
    if n == 1 or n == 0:
        return 1
    else:
        fib_save[n] = fibonacci(n - 2) + fibonacci(n - 1)
        return fib_save[n]


if __name__ == "__main__":
    number = int(input("digite o numero: "))

    for i in range(number + 1):
        print(f"{fibonacci(i)} ")
