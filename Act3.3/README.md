# Análisis de complejidad
## Add()
Add llama a la función splay(), la cual recorre el árbol por la izquierda o la derecha, dependiendo el valor que reciba. Complejidad O(log n) aunque en el primer caso llega a ser O(n) porque solo en ese caso se recorre todo el árbol.
## Remove()
Remove llama la función succesor() si se cumple una condición y si no se cumple ninguna condición establecida se llama a la función splay(). Tanto splay() como succesor() recorren un lado del árbol, por lo que ambas son O(log n), entonces Remove() también es O(log n).
## Find()
Find también manda llamar la función splay() de cumplirse una condición, por lo que es O(log n).
## Inorder()
Inorder utiliza una función recursiva y recorre todo el árbol para regresarlo ordenado en un string, por eso es O(n).
## Size ()
Size solo regresa un valor, por lo que es constante O(1).
