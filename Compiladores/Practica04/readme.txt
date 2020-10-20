Para correrlo primero hay que:
$flex practica04.l
luego 
$gcc lex.yy.c -o ejecutable -lfl
y por ultimo para ejecutarlo es con
$./ejecutable < prueba.txt
o en lugar de "prueba.txt" se pone un <archivo> con ejemplos dentro a probar.
ya que si no se quiere correr algun archivo, unicamente se ejecuta con 
$./ejecutable
>
>
>
