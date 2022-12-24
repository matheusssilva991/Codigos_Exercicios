if __name__ == '__main__':
    notas = list(map(float, input("Digite as notas: ").split()))
    media = 0

    for nota in notas:
        media += nota
    media /= len(notas)

    print(f"Media: {media:.2f}")
