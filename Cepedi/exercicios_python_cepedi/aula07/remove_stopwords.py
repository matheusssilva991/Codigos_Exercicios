def remove_stopwords(string):
    pontuacoes = ".,!?;:"
    stopwords = ['de', 'da', 'do', 'dos', 'das', 'uma', 'umas', 'uns', 'a', 'o', 'as', 'um']
    for pontuacao in pontuacoes:
        string = string.replace(pontuacao, ' uma ')

    string = string.split(" ")

    for i, word in enumerate(string):
        if word in stopwords:
            del string[i]

    return " ".join(string)


if __name__ == "__main__":
    texto = "testre uma oi"
    print(remove_stopwords(texto))
