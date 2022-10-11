def dfs_recursiva(grafo, vertice, visitados, count):
    visitados.add(vertice)

    for vizinho in grafo[vertice]:
        if vizinho not in visitados:
            count[0] += 1
            dfs_recursiva(grafo, vizinho, visitados, count)

def create_graph(vertices, arestas):
    graph = {}

    for vertice in range(vertices):
        graph[vertice] = []

        for i in range(len(arestas)):
            if arestas[i][0] == vertice:
                graph[vertice].append(arestas[i][1])
            elif arestas[i][1] == vertice:
                graph[vertice].append(arestas[i][0])

        graph[vertice] = list(set(graph[vertice]))
        if not graph[vertice]:
            del graph[vertice]

    return graph

def main():
    numero_casos = int(input())

    for caso_atual in range(numero_casos):
        initial_position = int(input())
        qtd_vertices, qtd_arestas = list(map(int, input().split(" ")))
        count = [0]
        arestas = []

        for i in range(qtd_arestas):
            arestas.append(list(map(int, input().split(" "))))

        graph = create_graph(qtd_vertices, arestas)
        visitados = set()
        dfs_recursiva(graph, initial_position, visitados, count)
        print(count[0] * 2)


main()
