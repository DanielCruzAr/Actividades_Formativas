# Análisis de complejidad
## Create
### Función add_first(T val)
Esta función es de complejidad O(1) ya que no utiliza ciclos ni condicionales, solo agrega el elemento que recibe al inicio de la lista por lo que solo se repite una vez.
### Función add(T val)
## Read
### Función find(T val)
Esta función es de complejidad O(n) en el peor de los casos porque contiene un ciclo while que se repite el mismo número de veces que el número de elementos que hay en la lista.
## Update
### Función update(T pos, T val)
El ciclo while se repetirá el mismo número de veces que el número de elementos que hay en la lista en el peor de los casos, por eso la complejidad es de O(n).
## Delete
### Función remove(T pos)
