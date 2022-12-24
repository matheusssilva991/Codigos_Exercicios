if __name__ == '__main__':
    def formata_hora(valor):
        return f"0{valor}" if valor < 10 else valor


    segundos_entrada = int(input())
    horas = segundos_entrada // 3600
    minutos = (segundos_entrada % 3600) // 60
    segundos = (segundos_entrada % 3600) % 60

    hora = [horas, minutos, segundos]
    hora = list(map(formata_hora, hora))
    hora = ":".join(hora)

    print(f"{segundos_entrada} equivale a {hora}")
