# UltimaOnline
Esperimenti per comandare Ultima Online mediante un programma esterno scritto in C++

## NB.
Se ci sono problemi di inizializzazione della uo.dll bisogna aprire e
chiudere EasyUO.

## RabaEUOdotNET0.5_Dll
- Contiene la DLL che permette di connettersi al client.
- Dipende a sua volta da uo.dll

## SSRabaWrapper
Wrapper C++ per poter utilizzare in maniera comoda la DLL RabaEUOdotNET, si tratta di una libreria statica. 
La compilazione dipende da RabaEUOdotNET.lib e per defaul il file di property punta a LibsDeploy

## Scripts
Script è la collezione di scripts che utilizzano il Wrapper.
Per compilare, il progetto deve avere incluso il file ScriptsProps.props
per essere sicuri che tutti i path siano corretti e bisogna importarlo come dipendente del progetto SSRabaWrapper.
Nella output dir dove viene generato l'eseguibile devono essere copiati i files:
- RabaEUOdotNET.dll
- uo.dll

## La catena globale di dipendenze è la seguente
    RabaEUOdotNET.dll
        RabaEUOdotNET.lib
            SSRabaWrapper.lib	
                Script
