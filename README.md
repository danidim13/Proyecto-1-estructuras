# Proyecto-1-estructuras
Método de integración de Euler

Se incluye un Makefile con tres targets: all, clean y run.
Además se incluye documentación de Doxygen. Para más información ver archivo INSTALL

El proyecto incluye dos pruebas que se pueden correr, ya sea manualmente o automáticamente mediante el Makefile.
Para correr las pruebas manualmente se debe compilar el target all, la pruebas se generan en el directorio "pruebas". El ejecutable recibe dos parametros por línea de comandos:

```
$ pruebas/Prueba1.out <num_pruebas> <tipo_prueba>
```

El valor de `<num_pruebas>` indica la cantidad de puntos a generar, y `<tipo_prueba` indica el LinealSolver a usar, debe ser un número del 1 al 4. La prueba genera un archivo de texto con los resultados. El mismo tiene 3 columnas:

Tiempo, variable de la prueba (x_f o step), cantidad de datos generados por `solve()` (efectivamente n).

Si se corren las pruebas automáticamente usando el Makefile se generan resultados para las 4 ecuaciones y ambas pruebas. En este caso los archivos de texto resultantes se guardan en la carpeta "Resultados".
