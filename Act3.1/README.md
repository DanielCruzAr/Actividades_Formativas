# Análisis de complejidad
## Función visit()
Esta función manda llamar otras funciones que implican recursión, esto quiere decir que en el peor de los casos se repiten el mismo número de veces que los elementos en el árbol, por lo cual su complejidad es de O(n).
## Función height()
En esta función se utiliza recursión al comparar valores del árbol, en el peor de los casos se van a recorrer todos los elementos del mismo por lo que su complejidad es de O(n).
## Función ancestors()
Esta función recibe un valor y lo compara con los elementos del árbol. La función utiliza recursión e igual se repite la mitad de las veces que el número de elementos del árbol en el peor de los casos. Su complejidad es de O(log(n)).
## Función whatlevelamI()
Esta función recive un valor y lo compara con los elementos del árbol de izquierda o derecha, por lo cual la función se repite la mitad de las veces, entonces es de complejidad O(log(n)).
