def check_distance(position_rafael, current_apple):
    distance_x = abs(position_rafael[0] - current_apple[0])
    distance_y = abs(position_rafael[1] - current_apple[1])
    distance = max(distance_y, distance_x)
    time_to_move = current_apple[2] - position_rafael[2]

    if distance > time_to_move:
        return False
    else:
        return True

def create_graph(apples_position):
    graph = {}

    for i in range(len(apples_position) - 1, -1, -1):
        graph[i] = 0
        for j in range(i + 1, len(apples_position)):
            if check_distance(apples_position[i], apples_position[j]):
                if 1 + graph[j] > graph[i]:
                    graph[i] = 1 + graph[j]
    return graph

def main():
    while True:
        qtd_rows, qtd_columns, qtd_apples = list(map(int, input().split(" ")))
        apples_position = []

        if qtd_rows == 0 & qtd_columns == 0 & qtd_apples == 0:
            break

        # Pega as posições das maças nos instantes de tempo
        for i in range(qtd_apples):
            apples_position.append(list(map(int, input().split(" "))))

        # Pega a posição inicial do Rafael
        position_rafael = list(map(int, input().split(" ")))
        position_rafael.append(0)

        # Junta a posição de rafael com a das maçãs
        position_merge = [position_rafael] + apples_position

        # Cria o grafo
        graph = create_graph(position_merge)

        #print(graph[0])
        print(graph)


main()
