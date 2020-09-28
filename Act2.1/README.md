# Análisis de complejidad
## Create
### Función add_first(T val)
Esta función es de complejidad O(1) ya que no utiliza ciclos ni condicionales, solo agrega el elemento que recibe al inicio de la lista por lo que solo se repite una vez.
### Función add(T val)
Esta función condiene un condicional if que manda llamar la función add_first() en caso de que se cumpla, esta función es O(1) por lo que el condicional tendrá la misma complejidad. También hay un ciclo while, el cual se repite n número de veces y va incrementando de uno en uno. En resumen, la función tiene complejidad O(n) en el peor de los casos.
## Read
### Función find(T val)
Esta función es de complejidad O(n) en el peor de los casos porque contiene un ciclo while que se repite el mismo número de veces que el número de elementos que hay en la lista.
## Update
### Función update(T pos, T val)
El ciclo while se repetirá el mismo número de veces que el número de elementos que hay en la lista en el peor de los casos, por eso la complejidad es de O(n).
## Delete
### Función remove_first()
Esta función no tienen ciclos ni condicionales, esto quiere decir que las operaciones solo se realizan una vez por lo que su complejidad es O(1).
### Función remove(T pos)
Esta función tiene un condicional if, el cual de cumplirse manda a llamar a la función remove_first() que tiene complejidad O(1), entonces el condicional tendrá la misma complejidad. La función remove() también tienen un ciclo while que se repite n número de veces con incrementos de uno en uno. La función tiene complejidad O(n) en el peor de los casos.
