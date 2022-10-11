if __name__ == '__main__':
    salario_bruto = float(input("Digite o salario bruto: "))

    if salario_bruto <= 1903.98:
        imposto = 0
    elif 1903.98 < salario_bruto < 2826.65:
        imposto = salario_bruto * 0.075
    elif 2826.65 < salario_bruto < 3751.06:
        imposto = salario_bruto * 0.15
    elif 3751.06 < salario_bruto < 4664.68:
        imposto = salario_bruto * 0.225
    else:
        imposto = salario_bruto * 0.275

    print(f"salário líquido: {salario_bruto - imposto}")
