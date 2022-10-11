import datetime as dt

if __name__ == '__main__':
    date = input("digita a data: ")
    date = dt.datetime.strptime(date, "%d-%m-%Y").date()

    inicio_outono = dt.date(date.year, 3, 20)
    inicio_inverno = dt.date(date.year, 6, 21)
    inicio_primavera = dt.date(date.year, 9, 22)
    inicio_verao = dt.date(date.year, 12, 21)

    if date <= inicio_outono:
        print("Verão")
    elif inicio_outono < date <= inicio_inverno:
        print("Outono")
    elif inicio_inverno < date <= inicio_verao:
        print("Inverno")
    else:
        print("Verão")


