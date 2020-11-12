# Análisis de complejidad
## loadGraphMat() y loadGraphList()
Recorre todos los elementos del archivo de texto y los almacena en una matriz. Ambas funciones son de complejidad O(n) si tomamos en cuenta unicamente los nodos que son almacenados en la matriz. A los arcos le correspendería cada nodo teniendo entonces una complejidad O(m).
## DFS() y BFS()
Contiene ciclos for anidados los cuales se incrementan de uno en uno recorriendo todo el grafo, ya que los nodos ya visitados no serán repetidos. Si nos guiamos por esta lógica, ambas funciones son de complejidad O(n), recordemos que BFS busca el elemento por el camino más óptimo a diferencia de DFS. 
