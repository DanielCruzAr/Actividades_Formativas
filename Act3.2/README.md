# Análisis de complejidad
## Push()
Esta función agrega datos en el árbol a la izquierda o a la derecha de la raíz. Es de complejidad O(log(n)) ya que el árbol se va dividiendo y los pasos se repiten solo si el dato agregado es mayor que el primer dato del árbol.
## Pop()
Pop llama a la función heapify() la cual es recursiva si se cumple con la condición. En el peor de los casos se repite el mismo número de veces que los datos de la fila de prioridad, por lo que es de complejidad O(log(n)).
## Top()
Top solo regresa el primer dato del árbol. O(1)
## Empty()
Empty es una función de consulta que regresa true o false dependiendo si la fila priorizada esta vacía o no. O(1)
## Size()
Size es una función de consulta que regresa la cantidad de datos que tiene la fila priorizada. O(1)
