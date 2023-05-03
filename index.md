<!-- - Ver si es posible independizarse del todo de la representacion en binario

    - Ver si el move es posible realizarlo usando solo numeros decimales, por ejemplo ver si restar dos decimales corresponde al equivalente de restar dos numeros en binario -->

- RiverCrossing:
    - Atributos
        - Archive: fileReader
        - LeftRestriction: Restriction -> Así es posible el realizar mas rapido la busqueda entre restricciones
        - RightRestriction: Restriction
        -  
    - Metodos
        - Assign Restrictions
        - Assign Operations
        - Successors
        - Solve

- 1111 - 0000 id = 0
    - 1111 
    - 1010
    - 1100
    - 1000


- realizar el makefile para realizar comandos mas rapidamente
   -  g++ -g -o testRiver RiverCrossing/RiverCrossing.cpp RiverCrossing/testRiver.cpp State/State.cpp Operation/Operation.cpp Restriction/Restriction.cpp LinkedList/LinkedList.cpp Hash/hashTable.cpp FileReader/fileReader.cpp bitService/bitService.cpp

- comando para realizar el main.cpp

    - g++ -g -o main RiverCrossing/RiverCrossing.cpp State/State.cpp Operation/Operation.cpp Restriction/Restriction.cpp LinkedList/LinkedList.cpp Hashtable/Hashtable.cpp FileReader/fileReader.cpp bitService/bitService.cpp Node/Node.cpp ./main.cpp

- 21/04
    - Implementar linkedList desde cero
        - Utilizar distintos tipos de nodo
        - En la linkedlist se utilizara insertbegin para insertar nodos en la tabla de hash, en caso de que hayan muchas colisiones entre sí
        - Se utilizara a modo de pila en el caso de los abierto
        - testear
    - reimplementar tabla de hash
        - ajustar a la nueva representacion de nodo
        - testear
    - Reimplementacion del nodo
        - Revisar que la implementacion del nodo no genere conflictos con otras clases





