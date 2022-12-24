def conta_vogal(text):
    vogais = ['a', 'e', 'i', 'o', 'u']
    count = 0

    for vogal in vogais:
        count += text.count(vogal)
    return count


if __name__ == "__main__":
    texto = input("digite o texto: ")

    print(conta_vogal(texto))
